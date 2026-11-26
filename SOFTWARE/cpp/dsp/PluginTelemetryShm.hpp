#pragma once

#include <cstdint>
#include <atomic>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <chrono>

#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>

namespace wbs::telemetry {

constexpr const char* kShmName = "/wbs_plugins_shm";
constexpr uint32_t kHeaderMagic = 0x57425348; // 'WBSH' (Ward-Beck Systems Header)
constexpr uint32_t kSlotMagic   = 0x57425331; // 'WBS1' (Ward-Beck Systems Slot v1)
constexpr uint32_t kShmVersion  = 1;
constexpr uint32_t kMaxSlots    = 32;
constexpr uint32_t kMaxParams   = 64;
constexpr uint32_t kMaxCmdQueue = 32;

#pragma pack(push, 4)

struct ShmParam {
    uint32_t id;
    char name[32];
    char module[32];
    char unit[16];
    float minVal;
    float maxVal;
    float defVal;
    uint32_t flags;
    float currentValue;
    char formattedValue[32];
};

struct ShmCommandEntry {
    uint32_t paramId;
    float targetValue;
};

struct ShmCommandQueue {
    uint32_t writeSeq; // updated by web server
    uint32_t readSeq;  // updated by plugin processor
    ShmCommandEntry entries[kMaxCmdQueue];
};

struct ShmPluginSlot {
    uint32_t magic;           // kSlotMagic when allocated
    uint32_t active;          // 1 if active, 0 if deactivated/idle
    uint32_t instanceId;      // unique ID
    int32_t pid;              // host process ID
    uint32_t moduleIndex;     // 0..9
    char pluginTitle[64];
    char modelCode[16];
    char hostName[32];
    double sampleRate;
    uint32_t blockSize;
    uint32_t latencySamples;
    uint64_t updateSeq;       // monotonically increasing sequence number
    uint64_t lastTimestampNs; // system monotonic time in ns

    // Real-time audio metering
    float peakInL;
    float peakInR;
    float peakOutL;
    float peakOutR;
    float gainReductionDb;
    float vuL;
    float vuR;
    float ppmL;
    float ppmR;
    float correlation;
    uint32_t isLocked;

    // Parameters
    uint32_t paramCount;
    ShmParam params[kMaxParams];

    // Bi-directional command mailbox
    ShmCommandQueue commands;
};

struct ShmRegistryHeader {
    uint32_t headerMagic;     // kHeaderMagic
    uint32_t version;         // kShmVersion
    uint32_t maxSlots;        // kMaxSlots
    uint32_t slotSize;        // sizeof(ShmPluginSlot)
    uint64_t serverHeartbeat; // updated by web server to signal it is alive
    ShmPluginSlot slots[kMaxSlots];
};

#pragma pack(pop)

/**
 * @brief Singleton Broker managing connection to POSIX shared memory
 */
class PluginTelemetryBroker {
public:
    static PluginTelemetryBroker& getInstance() {
        static PluginTelemetryBroker instance;
        return instance;
    }

    PluginTelemetryBroker(const PluginTelemetryBroker&) = delete;
    PluginTelemetryBroker& operator=(const PluginTelemetryBroker&) = delete;

    ShmPluginSlot* registerPlugin(
        uint32_t instanceId,
        uint32_t moduleIndex,
        const char* title,
        const char* modelCode,
        const char* hostName,
        double sampleRate,
        uint32_t blockSize,
        uint32_t latencySamples)
    {
        if (!ensureMapped()) return nullptr;

        for (uint32_t i = 0; i < kMaxSlots; ++i) {
            ShmPluginSlot& slot = header_->slots[i];

            // Reclaim stale slots from dead processes
            if (slot.active && slot.pid > 0 && kill(slot.pid, 0) != 0) {
                slot.magic = 0;
                slot.active = 0;
            }

            uint32_t expected = 0;
            auto* activePtr = reinterpret_cast<std::atomic<uint32_t>*>(&slot.active);

            if (activePtr->compare_exchange_strong(expected, 1)) {
                // Initialized slot
                slot.magic = kSlotMagic;
                slot.instanceId = instanceId;
                slot.pid = static_cast<int32_t>(getpid());
                slot.moduleIndex = moduleIndex;
                slot.sampleRate = sampleRate;
                slot.blockSize = blockSize;
                slot.latencySamples = latencySamples;
                slot.updateSeq = 1;
                slot.lastTimestampNs = getCurrentTimeNs();

                std::strncpy(slot.pluginTitle, title ? title : "WBS Plugin", sizeof(slot.pluginTitle) - 1);
                slot.pluginTitle[sizeof(slot.pluginTitle) - 1] = '\0';

                std::strncpy(slot.modelCode, modelCode ? modelCode : "", sizeof(slot.modelCode) - 1);
                slot.modelCode[sizeof(slot.modelCode) - 1] = '\0';

                std::strncpy(slot.hostName, hostName ? hostName : "REAPER", sizeof(slot.hostName) - 1);
                slot.hostName[sizeof(slot.hostName) - 1] = '\0';

                // Reset meters
                slot.peakInL = 0.0f;
                slot.peakInR = 0.0f;
                slot.peakOutL = 0.0f;
                slot.peakOutR = 0.0f;
                slot.gainReductionDb = 0.0f;
                slot.vuL = -60.0f;
                slot.vuR = -60.0f;
                slot.ppmL = -60.0f;
                slot.ppmR = -60.0f;
                slot.correlation = 1.0f;
                slot.isLocked = 0;
                slot.paramCount = 0;

                // Reset command mailbox
                slot.commands.writeSeq = 0;
                slot.commands.readSeq = 0;

                return &slot;
            }
        }
        return nullptr;
    }

    void unregisterPlugin(ShmPluginSlot* slot) {
        if (!slot) return;
        slot->active = 0;
        slot->magic = 0;
        slot->instanceId = 0;
    }

    static uint64_t getCurrentTimeNs() {
        auto now = std::chrono::steady_clock::now().time_since_epoch();
        return static_cast<uint64_t>(std::chrono::duration_cast<std::chrono::nanoseconds>(now).count());
    }

private:
    PluginTelemetryBroker() {
        ensureMapped();
    }

    ~PluginTelemetryBroker() {
        if (header_ && header_ != MAP_FAILED) {
            munmap(header_, sizeof(ShmRegistryHeader));
            header_ = nullptr;
        }
        if (shmFd_ >= 0) {
            close(shmFd_);
            shmFd_ = -1;
        }
    }

    bool ensureMapped() {
        if (header_ && header_ != MAP_FAILED) return true;

        shmFd_ = shm_open(kShmName, O_RDWR | O_CREAT, 0666);
        if (shmFd_ < 0) {
            return false;
        }

        struct stat sb{};
        if (fstat(shmFd_, &sb) == 0 && sb.st_size < static_cast<off_t>(sizeof(ShmRegistryHeader))) {
            if (ftruncate(shmFd_, sizeof(ShmRegistryHeader)) != 0) {
                close(shmFd_);
                shmFd_ = -1;
                return false;
            }
        }

        void* ptr = mmap(nullptr, sizeof(ShmRegistryHeader), PROT_READ | PROT_WRITE, MAP_SHARED, shmFd_, 0);
        if (ptr == MAP_FAILED) {
            close(shmFd_);
            shmFd_ = -1;
            return false;
        }

        header_ = static_cast<ShmRegistryHeader*>(ptr);

        // Initialize header if uninitialized
        if (header_->headerMagic != kHeaderMagic) {
            header_->headerMagic = kHeaderMagic;
            header_->version = kShmVersion;
            header_->maxSlots = kMaxSlots;
            header_->slotSize = sizeof(ShmPluginSlot);
            header_->serverHeartbeat = 0;
            for (uint32_t i = 0; i < kMaxSlots; ++i) {
                header_->slots[i].magic = 0;
                header_->slots[i].active = 0;
            }
        }

        return true;
    }

    int shmFd_{ -1 };
    ShmRegistryHeader* header_{ nullptr };
};

} // namespace wbs::telemetry
