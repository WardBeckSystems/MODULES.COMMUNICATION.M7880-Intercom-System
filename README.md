# M7880 Intercom System · Communication

Ward-Beck Systems M7880, 1989|22. Wiki page: [M7880 on WBSps.ca](https://wardbecksystems.github.io/WBSps.ca/PAGES/M7880.html)

| Folder | What is in it | Files |
|---|---|---|
| [SCHEMATICS/](SCHEMATICS/) | electrical drawings: schematics, functional diagrams, component layouts, wiring | 20 |
| [MECHANICAL/](MECHANICAL/) | front panels, cover plates, metalwork, assemblies; the front panel as vectors | 20 |
| [MANUALS/](MANUALS/) | manuals, manual pages, price lists, brochures, documents | 6 |
| [PHOTOS/](PHOTOS/) | photographs of the module | 13 |
| [SOFTWARE/](SOFTWARE/) | program listings, firmware, the plugin | 1 |
| [KICAD/](KICAD/) | KiCad schematics traced from the drawings, the symbol, PCB projects | 6 |
| [OCR/](OCR/) | the note of every file: date, origin, title block, OCR text | 33 |

<!-- module data: tools/module_specs.py, tools/forum_quotes.py -->

## Circuit description

From [19xx - M7880 - DOC - M7880 - 14-172-02-004 - COMPONENT LAYOUT.wp](MANUALS/19xx%20-%20M7880%20-%20DOC%20-%20M7880%20-%2014-172-02-004%20-%20COMPONENT%20LAYOUT.wp) page 1 (read by OCR; check against the pages). As data: [`CircuitDescription.json`](CircuitDescription.json).

<details><summary>Read it</summary>

2 Parts List 2-1 to 2-73 Drawings:

Schematic B 14-270-02-001 Schematic B 14-270-02-002 Schematic B 14-270-02-003 Component Layout B 14-270-06-001

B SA14-271B Audio Assembly

1 Circuit Description 1-1 to 1-32 Parts List 2-1 to 2-10 3 Drawings:

Schematic B 14-271-02-003 Component Layout B 14-271-06-003

C SA14-172C Key Display Assembly

1 Circuit Description 1-12 Parts List 2-1 to 2-23 Drawings:

Schematic B 14-172-02-004 Component Layout B 14-172-06-004

D SA14-173/SA14-173D Logic Assembly

1 Circuit Description 1-1 to 1-22 Parts List 2-1 to 2-53 Drawings:

Schematic B 14-173-02-001 Component Layout B 14-173-06-001

E Lambda Power Supply

1 General (LVT-39E Series) 1-1 to 1-22 Parts List 2-1 A. Preamplifier Section:

Gain:

Dynamic Mic Input: 78 dB to 48 dB +/-1 dB (Transducer Gain +8 dBm operation). Headset Mic Input: 48 dB to 18 dB +/-1 dB (Transducer Gain +8 dBm operation). External Line Input: 18 dB to -2 dB +/-1 dB (Bridging Gain +8 dBm operation).

Frequency Response: +/-1 dB 100 Hz to 5 kHz

Noise: (measured over a 20 Hz to 20 kHz band­width).

Dynamic Mic Input: -118 dBm EIN at maximum sensitivity. -120 dBm typical.

Headset Mic Input: 50 to 65 dB below +8 dBm over the 30 dB sensitivity range. External Line Input: 65 to 75 dB below +8 dBm over the 30 dB sen­sitivity range.

Harmonic Distortion:

Less than 0.25% 100 Hz to 5 kHz at limiting threshold (+12 dBm output +8 dBm operation).

Less than 0.25% 100 Hz to 5 kHz at +22 dBm output level with limiter off. Less than 1% 100 Hz to 5 kHz with 20 dB of limiting and &quot;normal&quot; release time.

Input Levels:

Dynamic Mic: -70 dBm to -40 dBm nominal.

Headset Mic: -40 dBm to -10 dBm nominal.

External Line: -10 dBm to +10 dBm nominal.

Input Impedances:

Dynamic Mic: 600 ohms or greater unbalanced.

Headset Mic: 600 ohm or greater unbalanced.

External Line: 10000 ohms or greater balanced.

Source Impedance:

Dynamic and Headset Mics: 150 ohms balanced/unbalanced. External Line: 600 ohms or less balanced.

Output Level: +8 dBm nominal (+4 dBm optional).

+24 dBu maximum 5K ohm load.

+22 dBm maximum 600 ohm load.

Output Impedance: 60 ohms, actively balanced.

Load Impedance: 600 ohms, or greater balanced.

Limiter:

Range: 30 dB.

Slope: 3:1 nominal at threshold, approaching 10:1 at 20 dB of limiting. Threshold: Set 4 to 5 dB above nominal operating level.(results ina constant output of +4 or +8 VU under dynamic con­ditions). Attack Time: 10 milliseconds nominal.

Release Time: 3 seconds &quot;normal&quot;.

1.5 seconds &quot;fast&quot;.

B. Speaker/Headset Amplifier:

Gain:

to Speaker Output: +25 dB +/-1 dB (bridging gain).

to Headset Output: +10 dB +/-1 dB (bridging gain).

Frequency Response: +/-1 dB 50 Hz to 8 kHz.

+/-0.5 dB 100 Hz to 5 kHz.

Noise: (measured over a 20 Hz to 20 kHz band­width).

Speaker Output: 80 dB below 3 watts.

Headset Output: 70 dB below +8 dBm.

Harmonic Distortion: Less than 0.25% 100 Hz to 5 kHz at 3 watts output for the speaker amplifier into an 8 ohm load and to +22 dBm output into 600 ohms for the headset amplifier.

Input Level: +8 dBu nominal (+4 dBu optional), +24 dBu maximum. (from matrix).

Input Impedance: 10,000 ohms or greater balanced.

Source Impedance: 600 ohms or less balanced.

Output Levels:

Speaker Output: 200 mW nominal 3 watts maximum.

Headset Output: +8 dBm nominal (+4 dBm optional) +22 dBm maximum.

Output Impedances:

Speaker Output: Less than 1 ohm unbalanced.

Headset Output: 60 ohms actively balanced.

Load Impedances:

Speaker Output: 8 ohms unbalanced.

Headset Output: 600 ohms balanced or greater.

C. Control Functions:

Programmable External Inputs:

Standard TTL Logic Levels: +5 volts max.

+0.5 volts min.

Programmable External Outputs:

Open Collector Drive: Source voltage 25 volts max.

Sink current 25 mA max.

External Data and Address Lines:

Standard TTL Logic Levels: +5 volts max.

+0.5 volts min.

Power Requirements: 115/230V AC 50 to 60 Hz 50 VA.

Ambient Temperature: 0 to 50 degrees Celsius.

M7882 Dimensions: 19.00&quot; wide x 3.46&quot; high x 9.00&quot; deep. (482 mm x 88 mm x 229 mm)

M7882 Mounting Depth: 9.75&quot; (248 mm) approximately.

M7882 Weight: 9 lbs (4.1 kg).

M7883 Dimensions: 19.00&quot; wide x 3.46&quot; high x 3.00&quot; deep. (482 mm x 88 mm x 76 mm)

M7883 Mounting Depth: 5.00&quot; (127 mm) approximately.

M7883 Weight: 4 lbs (1.8 kg).

The M7882/M7883 Remote Communicat­ions Package has been designed to ope­rate as an active intercom terminal in conjunc­tion with the WBS MicroCOM ll Commu­nicat­ions System.

The M7883 Remote Communications Panel has the added advantage of being able to be remotely mounted when space limitat­ions are at a premium. Connections to the main M7882 terminal are made via inter­connecting cables.

The self powered M7882 contains the required audio amplifiers and microprocessor con­trol system to handle all control and communication paths to and from the central switching matrix.

The M7883 provides an integral dynamic gooseneck microphone, loudspeaker and headset select facilities. Ten programmable talk keys, ten listen select pushbuttons, four character alphanumeric displays and an assignment keypad are included.

The control assignment,and programming data is transferred to and from the matrix on a balanced serial data line which oper­ates on a RS422 format. The audio input and the audio output of the M7882 are balanced +8 dBm (+4 dBm optional) 600 ohm lines. The above three balanced lines allow full communi­cation between the terminal and the cen­tral matrix. Additional inputs, outputs and control functions are made available on con­nectors at the rear of the M7882.

Audio from the remote dynamic or exter­nal headset microphone is amplified to a nominal +8 dBm (+4 dBm optional) line level output by a preamplifier. A front panel sens­itivity con­trol (SENS) is provided on the M7882 to makeup for operating technique variat­ions. Input levels over a sensitivity range of 30 dB maybe accommodated.

An auto levelling type limiter stabilizes the audio output from the microphone pre­amplifier, assuring constant system levels over a large range of voice vari­ations. Two level indicators on the M7882, located above the sensitivity control, are provided. One, labelled NORM (normal) flashes when the preamplifier output is a nominal +8 VU (+4 VU optional). The other, labelled OVLD (over­load), flashes when the limiting action becomes excessive (greater than 20 dB).

A third indicator, labelled XMIT illumi­nates when a talk keyswitch is operated, serving as a transmit tally.

The front panel &quot;Enable&quot; keyswitch is programmable to provide a &quot;Lock Key Enable&quot; or &quot;Hot Mic&quot; operation.

The external footswitch is paralleled to the &quot;Enable&quot; switch in the &quot;Lock Key Enable&quot; mode so that either switch enables the lock keys.

In the &quot;Hot Mic&quot; mode the external footswitch function is in series with the lock talk keyswitch functions. If an ex­ternal footswitch is not used with a com­munications terminal, an external jumper must be added across the external footswitch connection.

A power amplifier boosts the incoming audio signal from the matrix and drives an integral speaker through the front panel speaker level control. This ampli­fier is capable of delivering up to 3 watts into an 8 ohm load.

The M7882 is powered from a modular power supply integral to the terminal and operates from either 115/230V AC 45 to 400 Hz. The integral power supply may have to be strapped for the specific source voltage being applied.

The M7882 and M7883 are individually housed ina 3 1/2 inch high, (two rack unit), aluminum chassis and designed for standard nineteen inch rack mounting. The M7883's shallow depth (approximately 3 in­ches), permits the remote panel to be easily mounted inmost television plant operating areas. It is constructed on a modular philosophy. All active circuit modules interconnect through ribbon cables and chassis con­nectors allowing easy re­moval of all com­pon­ents from within the terminal as required for ser­vice. Front Panel Control Functions Refer to drawing B 7882-04-002

**1) SENS**

The sensitivity trim control is provided to makeup for operat­ing technique variat­ions. The sensitivity control maybe operationally set by spea­king into the micro­phone ina normal voice at the correct oper­ating dis­tance. Advance the control clock­wise until the green NORM indicator begins flashing inter­mittently. DO NOT advance any fur­ther: Under no circumstances should this control beset so that the red OVLD indi­cator will flash.

**2) NORM**

The green Normal indicator flashes when the output from the micro­phone preamplifier is a nominal +8 VU (+4 VU optional).

**3) OVLD**

The red Overload indicator flashes when the limiting action becomes exces­sive (approximately 20 dB).

**4) XMIT**

The transmit indicator illuminates when any one of the momentary talk key switches are activated, or when a lock keyswitch has been assigned, locked on and then acti­vated by the Group select keys. It indicates that an audio signal is leaving the ter­minal from the micro­phone preampli­fier.

Rear Panel Control Functions Refer to drawing B 7882-04-003

**5) CONNECTOR P1**

Connector P1 contains the audio in­put, audio output and serial data line which connect the terminal to the intercom matrix. See page 8-1 for P1 con­nector layout details.

**6) CONNECTOR P2**

Connector P2 contains the prog­rammable external inputs and pro­gramm­able external outputs. See page 8-2 for P2 connector layout details.

**7) CONNECTOR P7**

Connector P7 contains the key add­ress, key data and display drives to the remote front panel assembly. See page 8-3 for P7 conn­ector layout details.

If option 1 is to be installed for the implementation of M7881 expander, P7 must be moved up to provide space for connector P3, This should be treated as a special case, with additional customization.

**8) EXTERNAL MIC**

A rear panel micro­phone connector provides the external connect­ion of a re­motely mounted dynamic micro­phone.

**9) CONNECTOR P6**

Connector P6 contains the audio in­puts, audio outputs and dc control funct­ions of the audio section of the term­inal. See page 8-5 for P6 con­nector layout details.

**10) EXT PRE SENS**

The external preamplifier input sens­itivity control is an adjust­ment for the pre­ampli­fier line level input func­t­ion. This control is primarily used for the slave operation and any exter­nal line inputs. Installed as required on a custom basis. Refer to specific system requirements.

**11) SIDETONE**

The sidetone control provides a means of adjusting the level of the sidetone audio. It is activated as an integral part of the front panel head­set select­ion.

**12) EXT 1**

The optional external 1 control provi­des for separate adjustment of one of the speaker amplifier external inputs. The control maybe preset on the rear of the unit optionally supplied. Installed as required on a custom basis. Refer to specific system requirements.

**13) PART MUTE**

This control provides a speaker part mute level adjustment. Part muting is prog­rammed to activate with the oper­ation of any talk key funct­ion. This part mute level range is approx­i­ma­tely from -4 to -25 dB.

**14) HDST CONTROL**

The headset level control provides preset headset level adjustments for the rem­ote front panel assembly.

**15) SPKR CONTROL**

The speaker level con­trol provides preset speaker level ad­justments for the rem­ote front panel assembly.

**16) CONNECTOR P5**

Normally not supplied. Maybe installed as a custom basis for slave operation.

**17) CONNECTOR J4**

Connector J4 contains the +5V and control common interconnects to the remote front panel assembly. See page 8-4 J4 connector layout details.

**18) ACCORD**

AC power cord.

**19) AC FUSE**

AC fuse for primary AC power. Fuse rating is 1.5 ampere slow blow 115 or 230 volt. Front Panel Control Functions Refer to drawings B 7883-04-002

This manual describes features incorporated in the communications terminal operating system software &quot;MTFB&quot; rel. 1.12 or greater. The software release maybe observed at startup or via a reset (PD99). The installed software version maybe established by check­ing the label on EPROM U3 on the SA14-270 controller assembly.

**1) TALK KEYSWITCHES**

Ten programmable talk key functions are provided, each with a momentary and a lock keyswitch. The locking talk keys are tal­lied with an in­teg­ral LED indicator. The locking keyswitch funct­ions loop thr­ough the white ENABLE keyswitches and/or an exter­nal footswitch when the ENABLE keyswitch is not programmed to the HOT MIC Mode (see assign code PD37). This allows a preset group of latching talk keyswitches to be operated as a single function, either by operating the Enable momentary key or the external footswitch. Selecting the Lock Enable Key permits the Lock Talk Key­switches to operate their assigned Talk functions.

Alternatively when the ENABLE keyswitches are placed in the HOT MIC Mode (see assign code PD37) the lock­ing talk keyswitch functions loop through the external footswitch con­nection (see page 8-2). From the crosspoint control point of view the locking talk keyswitches are in series with the external footswitch control. Selection of the Enable/Hot Mic switch parallels the footswitch function.

In the HOT MIC Mode of the Enable keyswitches, the latching or momentary Enable keyswitch function must be selected before audio will be fed to the matrix from the communications ter­minal.

A privacy override feature of the momentary talk keyswitches maybe ac­tivated (see assign code PD33) by depressing a momentary talk keyswitch. This releases any lock talk keyswitch function for the duration of the momen­tary keyswitch opera­tion.

TheA, B, C and D keyswit­ches have direct access prog­ramming capabilities through the keypad push­buttons. The 1 to 6 keys have indirect ac­cess prog­ramming capa­bilities thr­ough the front panel keypad P push­button (see Keypad). Any time a keys­witch is acti­vated and audio from the micro­phone pre­amplifier is transmitted the speaker out­put is part muted. The degree of part muting is set via a rear panel trim con­trol (see item 13 on the M7882 rear panel).

**2) DESIGNATION STRIP**

The designation strip maybe lab­elled as per cus­tomers specific requirements.

**3) MICROPHONE**

The front panel mounted mic­ro­phone is a dynamic, unidirectional type with a car­dioid pickup pattern. The micro­phone offers high speech intelligibility and excellent feedback sup­pression.

**4) DISPLAY WINDOW**

The display window contains ten four-digit dot matrix alpha­numeric displays, one above each talk keyswitch. The dis­played code indicates the station sele­ction for each talk keyswitch.

**5) LISTEN PUSHBUTTONS**

Ten programmable listen push­buttons are provided. Each button has an integral two col­our LED indicator. When the control attributes are prog­rammed to give a listen funct­ion for the selected assignment, the listen pushbutton when selected will illumi­nate green.

Calling Tallies:

The M7883 terminal features exten­sive call indicating cap­abilities.

These maybe grouped into calling tallies, automatic call assignment for keys A toD and a call waiting fea­ture.

When an incoming call is rece­ived from a station, which is currently assigned to any one of the intercom keyswitches, the associated calling tally will blink. The calling tally indi­cators are located in the cap of the listen push­buttons above the alpha­numeric display.

Two colour LED's are used. They illuminate green to indi­cate that the listen function is selected, or red as a calling tally indicator. The calling tally has priority over the lis­ten indi­cator. Therefore if the listen push­button is on (green LED), the red blinking tally will over­ride the listen tally for the duration of the call.

The call is answered by pressing the respective momentary talk keyswitch. A call will also be answered by turn­ing on its locked keyswitch, (if the Enable key is on). Upon reply­ing to the call the tally chan­ges from blink­ing to a solid red indi­cator.

If a call is received from a station which is not currently assigned to any intercom keyswitch, the calling station code is displayed, flashing in the first empty window from D to A. By answ­er­ing the call (pressing the approp­riate intercom key) the stat­ion code stops flashing and is auto­mat­ically assigned to this key. During the assignment update, the display shows &quot;****&quot;, when the station code returns the connection path is established. Up to four calls maybe received at the same time in this man­ner, pro­viding that keys A toD are pres­ently not as­signed.

If theA toD intercom keys are occupi­ed with as­signments, add­itional incom­ing calls are cap­tured by the &quot;call wait­ing&quot; fea­ture. This feature is enabled or disabled by assign code PD31.

With the call waiting feature enabled, an unassigned incoming call is indicated by the flashing &quot;????&quot; in the D key display win­dow. This is just a prompt to let the operator know that an unassigned station is calling. The audio of the calling station will always be heard.

The call waiting buffer holds only the last call made.

to select the call waiting code press the &quot;D&quot; keypad pushbutton. The D display will now change to the flashing call waiting code. Pushing the &quot;D&quot; pushbutton a second time results in the D display returning to the current assignment alter­nating with question marks.

With the flashing call waiting code selected in the D window and operating the D talk keys­witch results in the D key taking on the call waiting assignment. This is as previously described for unas­signed A-D displays.

to recover the original D key assignment press the &quot;D&quot; keypad pushbut­ton again. The display blanks off momen­tarily and returns to the original D key assignment.

**6) INTENSITY SET**

The intensity set control allows the adjustment of the alpha­numeric dis­plays illumi­nation level. The control is located on the Logic Assembly board and is adjustable via the screwdriver access hole in the front panel.

**7) LINE**

The yellow LINE LED indi­cates that the terminal is online with the cen­tral matrix.

**8) RUN**

The green flashing RUN LED indi­cates that the integral micro­pro­cessor is accessing data. This maybe enabled or disabled with PD code #98.

**9) KEYPAD**

The sixteen button keypad selector allows direct prog­ramm­ing access of any valid station in the intercom matrix to keyswitches A, B, C and D and indirect programming ac­cess to keyswitches 1 through 6. The keypad is also used for switching between assignment pages or levels and main­t­enance related functions.

The keypad consists of sixteen push­buttons, which are orga­nized as follows: Buttons label­led A toD on the right hand side of the key­pad. These are used to change or make assign­ments to the correspon­ding inter­com keyswitches. Pressing one of these buttons will cause the display of the correspond­ing inter­com key to change to four dashes. This indicates that the terminal is ready to accept anew assignment for that key. If no other key is pressed within 15 seconds, the display will return to the prev­ious assign­ment.

The lower left button of the keypad is the Clear key (labell­ed 'CLR'). Press­ing this key during an entry clears the assignment of the respe­ctive inter­com key.

The button labelled 'P' on the lower right next to the 'D' button is used for several programming type funct­ions.

The remaining keypad push­buttons are or­ganized similar to that on a telephone. The numeric buttons are labelled as fol­lows: But­ton numbers are printed in black in the center. Above it in red let­tering are the pri­mary key codes (the alpha-portion of the alpha­numeric station code). These are accessed dir­ectly after selecting an inter­com key. Below the numbers in blue letter­ing are the secon­dary key codes. The secondary key codes are accessed by pres­sing the 'P' push­button after the initial assign selec­t­ions. The 'P' pushbutton will tog­gle between primary (indicated by upper dashes in the ­display window) and secon­dary (indicated by lower or underline dashes in the display win­dow) codes.

Keyswitches A toD Assignment

Press pushbutton A, B, CorDon the key­pad. The display above the select­ed keys­witch will change to four dashes, prompting for code input. If no other button is pressed within approximately 15 seconds, the display will revert back to the old assign­ment. If the 'CLR' button is pressed, the current ass­ign­ment is erased and the display cleared.

to enter anew assignment, press the numeric keypad pushbutton cor­respond­ing to the alpha-portion of the station's ID. If this is desig­nated in blue below the key number, press the 'P' key first to toggle to the secon­dary function. Note the dashes in the dis­play change to underline dashes.

After entering the alpha-portion of the code the following keypad push­button entries are the numeric digits. There maybe either 1 or 2 digits or none if the mne­monic code already consists of four charac­ters.

Keyswitches 1 to 6 Assignment

The assignments to keyswit­ches 1 to 6 maybe changed via the keypad for assignment pages or levels 1 to 3. In page or level 4 only assign­ments for keys A toD maybe altered from the keypad. Normally, page or level 4 assignments are made from the central PC computer and uploaded to the res­pective terminals.

New key assignments to keyswit­ches 1 to 6 are made in the follow­ing manner:

Press the 'P' key. The 'A' dis­play window will change from showing its assignment to four dots. Don't worry about loosing the 'A' assign­ment. The assign­ment is unchanged and the display will be restored upon complet­ion of the data entry. The control system merely borrows the 'A' display as a prompt and a data entry area. Press '0' followed by the num­ber of the key you wish to re-assign. Valid entries are 01 to 06.

After completing the second key stroke, the 'A' display cha­nges back to show the assig­nment of theA key, while the display above the selected key now shows four dashes, promp­t­ing for an assignment entry.

Proceed to enter anew assign­ment as described above (keyswitches A toD Assignment).

Numeric Entries

A keyswitch assignment maybe made by bus number instead of the mnemo­nic code. Select the desired keyswitch to which the assignment is to be made, then press '0', the symbol # will be displayed as the first charac­ter in the assignment window. Then complete the entry of the 3 digit bus number to be assigned (e.g. #007, #023, etc).

Code Overlay

The electronic legending displays either the generic (or mnemonic) bus code, the bus number (prefixed by a # symbol) or code overlays. The code overlay is an alias of the generic bus code, per­sonalizing the coding for specific operational re­quirements. The overlay is selected by pressing the &quot;P&quot; button fol­lowed by &quot;C&quot; on the keypad. Repeating the above will toggle the displays back to their generic codes.

Station Identification

Pressing the &quot;P&quot; button followed by &quot;9&quot; on the keypad displays the bus number and the generic code (or its alias if in overlay mode) that the terminal is connected to on the displays above keyswitches A toD.

Pressing &quot;P&quot; &quot;9&quot; and viewing the stations ID will allow one to quickly determine whether the terminal is in its mnemonic bus code mode or the overlay mode.

Change, Copy or Delete Assignment Pages Up to four different sets of station as­signments maybe stored in the M7882/M7883. These are known as pages or levels 1 to 4. By switching be­tween these pages, we can effect­ively change the key assignments to diff­erent preset con­figurations.

Pages or levels 1 to 3 are assigned via the keypad, while page or level 4 is assigned from the central assignment computer. It may also be sub­liminally re­assigned to different stations from the assignment computer while the ter­minal is operated from one of the other pages or levels. In page or level 4 only keys A toD maybe reassigned from the terminal key­pad.

to change from the current assign­ment page or level, press 'P', fol­low­ed by the 'A' button on the keypad. The display above intercom keyswitch A will change to 'PG#X', where X is the cur­rently selected page (1, 2, 3 or 4). to select anew page or level, simply press a num­bered pushbutton from 1 to 4 to select the respective page or press 'CLR' to cancel the operat­ion. After selecting anew page or level, the displays above the inter­com keyswitc­hes change to reflect their new as­signments.

to copy the assignments of the current page to another, press &quot;P&quot; followed by &quot;A&quot; and &quot;C&quot; on the keypad. The displays above keyswitches A toD will change to &quot;COPY PGX to PG _&quot;, where X is the currently selected page (1, 2, 3 or 4). The flashing underline symbol prompts for the page number to copy to (Pages 1, 2 or 3).

to delete the assignment of the current page, press &quot;P&quot; followed by &quot;A&quot; and then &quot;D&quot; on the keypad. The displays above keyswitches A toD will change to &quot;** DELETING **&quot; and then blank off.

Editing of Group (GRP) Assignments

Multiple crosspoint assignments maybe made to a single talk key or listen push­button. These multiple assignments are known as groups and maybe as­signed to any key, with the phantom mnemo­nic code of &quot;GRP1&quot; to &quot;GRP4&quot;.

Each group (GRP) may consist of up to six codes each. The following outlines the selection or editing procedure.

a) Press the &quot;P&quot; pushbutton, followed by the &quot;B&quot; (GRP) pushbutton. Display window &quot;A&quot; will show &quot;GRP_&quot;, promp­ting fora group num­ber entry. Press a number push­button from 1 to 4, for Group 1 to 4.

b) At this point the display windows 1 to 6 will show any previously defined as­signments, whereas displays B toD will display the talk, listen and listen/­mute crosspoint control attri­butes. Note: &quot;1&quot; means the attribute is select­ed, &quot;0&quot; means the attribute is not select­ed.

The talk attribute is always set to &quot;1&quot;, while the listen and the listen/mute at­tributes maybe changed as desired. The listen/mute at­tribute will be &quot;0&quot; if the listen at­tribute is set to &quot;0&quot;.

c) to change the listen attribute, press the &quot;C&quot; pushbutton, followed by &quot;1&quot; or &quot;0&quot;. Like­wise, to change the listen/­mute attri­bute, press the &quot;D&quot; push­button, followed by &quot;1&quot; or &quot;0&quot; (provi­ding the listen attri­bute is a &quot;1&quot;). It is necessary to always press &quot;C&quot; or &quot;D&quot; before pressing &quot;1&quot; or &quot;0&quot; to set or clear the attribute. When the group (GRP) edit and or attribute definition is complete press the &quot;A&quot; keypad pushbutton (SAVE) to save the entries and store them in memory.

d) to editor enter an assignment press the keypad's numeric entry buttons 1 to 6 for accessing display windows 1 to 6. A set of four dashes in the select­ed win­dow will prompt for an assign­ment selection in the same manner as a regular key assignment as described previously. Press the mne­monic code entry pushbutton first, then com­plete the entry with a one or two digit numeric entry, depen­dent on the code. Of course if the mnemo­nic code is a complete ass­ign­ment (such as MTCE, etc), no further key presses are re­quired.

e) to clear selected assignments, press &quot;0&quot; to clear the four dashes and blank the display.

f) Define or redefine the assignments and control attributes as desired. When com­plete, press the &quot;A&quot; keypad push­button (SAVE) to save the group (GRP) definition.

to exit the Group edit mode press the &quot;CLR&quot; pushbut­ton. The new defi­nition is not effec­tive until saved by pressing the &quot;A&quot; keypad push­button (SAVE). The Group edit mode automatically times out and ter­minates after approximately 20 to 30 seconds of ina­ctivity (no pushbuttons pressed).

It should be noted that after saving and returning to a group edit that the mnemonic codes maybe shifted to their original entry position. This occurs if a blank (no edit) existed between previous­ly made entries.

Pressing the &quot;CLR&quot; keypad pushbutton at any time will exit the group (GRP) edit mode leaving the GRP as previously defined. It is necessary to press the &quot;A&quot; keypad pushbutton to save the group (GRP) edit entries. The group edit mode will time out in approximately 20 seconds after the last entry.

Phantom Code Selections

A number of select codes are available known as phan­tom codes. These codes do not directly pertain to individual crosspoints, but instead to tabled groupings of crosspoints. These tabled groupings of crosspoint control are known as:

Groups GRP1 to GRP4 Call Arrays CA01 to CA12 Camera Arrays CMA1 to CMA8 ISO Select IS01 to IS24 Event Control EV01 to EV24

a) Groups (GRP):

Four group assignments each consisting of six matrix bus codes maybe defined within each communications terminal. The defining of these groups maybe setup in the assignment computer and then fed to the appropriate com­munications ter­minal.

As described above the groups maybe defined and edited at the terminal. The last activity of the terminal groups determines the current as­signment.

If a download from the central as­signment computer is made for groups, then that is the bus codes assigned to the groups. If a local keypad edit is made of the group assignments then the last chan­ges made will prevail as the group as­signment.

These group assignment setups are unique to each communications terminal.

b) Call Arrays (CA):

Twelve Call Arrays (CA01 to CA12) each with a capacity of sixteen matrix bus codes maybe defined and stored in the central matrix control system. The definition of these arrays is established in the central assignment computer and subsequently loaded into the system.

The arrays are global in nature, that is selection and operation of a Call Array code by any communications terminal results in the operation of the appropriate talk and listen crosspoint for the matrix bus codes entered in the table.

c) Camera Arrays (CMA):

Eight camera arrays maybe defined (CMA1 to CMA8). This array definition as outlined in b) above for call arrays per­mits defined keyswitch functions on a com­munication terminal to com­municate with a defined group of four wire camera circuits as if they were one.

Associated with this function are intercamera party line, sidetone and isolate functions. Refer to the as­signment com­puter documentation for setup details.

As many as twenty-four cameras maybe defined, with up to twelve cameras as­signed to any of the eight possible arrays. d) ISO Select (ISO):

This phantom code permits a selected camera to be removed from a defined camera array (camera isolate). Usually ina system only one or two communications stations have the camera ISO function enabled. This is determined by assign code PD32.

Refer to the MicroCOM II Com­munications System Handbook for il­lustrations and detail of the camera as­signment and isolate operation.

e) Event Control (EV):

The MicroCOM II communications system contains what is referred to as Electronic Pegboard Control (EPC). This feature permits the selection and operation of matrix crosspoints on a co-ordinate basis and without as­sociation to a particular communications terminal.

Associated with the EPC is the Event Control. This is where a defined com­munications terminal keyswitch function (known as EV01 to EV24) maybe desig­nated to operate numerous matrix crosspoints.

A more detailed description of the EPC function is outlined in the MicroCOM II Communications Systems Handbook.

Terminal Configuration Mode:

The following functions are configur­able at a communications terminal by entering a setup code from the keypad:

Code Functions

PD21 Terminal Type PD29 Define Passcode PD31 Enable/disable Call Waiting PD32 Camera ISO Enable PD33 Enable/disable Privacy Override PD34 Select Calling Tally timeout delay PD37 Hot Mic Select PD38 IFB/ISO Lock Key PD46 Enable/disable keypad PD47 Enable/disable M7881 Expander Panel (not applicable to M7882/M7883).

PD48 Select matrix size PD50 Reinitialize terminal PD71 Configure Software for Terminal Revision PD91 RAM test PD98 Run Tally PD99 Reset terminal

The access to most of the above functions except the Reset (PD99) maybe restricted by defining a Passcode. Once a passcode is defined, this code must be entered in order to change any configuration parameter.

to access any of the above programming modes, enter the following key sequence from the keypad:

**&quot;P D X X&quot;**

where x x is the code for the desired mode. (e.g. &quot;PD48&quot; to select matrix size). If a passcode was defined, the A-D display window changes to

**&quot;ACCESS CODE _ _ _ _&quot;,**

promp­ting fora valid pass­code entry with the first blinking underline. As each digit is entere­d, the blinking underline moves to the right by one digit, being replaced by an asterisk. After the full 4-digit code is entered, it is validated. If it matches the previously defined pass­code, the display changes to the selected prog­ramming mode. Windows 1-6 also display the allowable key entries as fol­lows:

&quot;A = SAVE P = ADV. CLR = EXIT&quot;

Press the &quot;P&quot; key to toggle between select­ions. The unselected choice is displayed blinking, while the current selection is not blinking.

to save the displayed selection, press the &quot;A&quot; key. The selection will then stop blink­ing. to exit the programming mode, press the &quot;CLR&quot; key.

While the terminal is in the programming mode, the keyswitches are still fully operational and terminal com­munications are not interrupted.

The following sections explain the indi­vidual programming mode functions in more detail.

Terminal Type (PD21)

Enter &quot;PD21&quot; to access this function. If a passcode was defined, enter the correct code to the

**&quot;ACCESS CODE _ _ _ _&quot;**

prompt in the A-D display window. The A-D window then changes to:

pressing the &quot;P&quot; key (ADV.) selects the next terminal type (i.e M7880). The unselected choices are blinking in the display window.

Pressing the &quot;A&quot; (SAVE) selects the con­figuration of the currently displayed terminal type.

Exit this mode by pressing the &quot;CLR&quot; key.

Upon initialization the default terminal definition is a M7880. If the terminal is reinitialized the previous definition is retained.

Three terminal types are available M7880, M7880B and M7880D. For M7882/M7883 operation set to M7880.

Define Passcode (PD29)

Enter &quot;PD29&quot; to access this function.

If a passcode was defined previously, enter the valid code. Entering an invalid code causes the terminal to reject the operation.

If a correct code was entered, displays 1-6 change to

**&quot; * ENTER NEW PASS­CODE * &quot;**

and display window D changes back to under­lines with the left most digit blink­ing.

to disable the passcode functions, enter &quot;0000&quot;. This will turn off the passcode and allows unrestricted access to all program­m­ing modes. Otherwise, enter a four digit code of your choice. Be sure to remember this code, because it will subsequently be required to access most program­ming mode functions.

Upon initialization the passcode access feature is disabled. If a terminal has a previously defined passcode it is lost with reinitialization (PD50).

As shipped the passcode feature is at the customers discretion.

If the defined passcode is lost the Master Access code maybe used to override the defined passcode. The Master Access Code should be kept ina safe place.

Master Access Code

Call Waiting (PD31)

Enter &quot;PD31&quot; to access this function. The A-D displays then chan­ges to

**&quot;CALL WAITING&quot;**

and either &quot;YES&quot; or &quot;NO&quot; depending on the current setup. Pressing the &quot;P&quot; key (ADV.) toggles the D display between &quot;YES&quot; and &quot;NO&quot;. The unselected choice is displayed blinking. to select, press the &quot;A&quot; key (SAVE). The &quot;YES&quot; or &quot;NO&quot; in the D display window will then stop blinking, indicating that it is now selected.

Exit this mode by pressing the &quot;CLR&quot; key.

The call waiting feature is enabled by default at initialization. Reinitializing the terminal will place it in the enabled con­dition.

Camera Isolation Mode (PD32)

Enter &quot;PD32&quot; to access this function. The A-D display window then changes to

**&quot;CAMERA ISO&quot;**

an­d either &quot;YES&quot; or &quot;NO&quot;, depending on the current setup. Pressing the &quot;P&quot; key (ADV.) toggles the D display between &quot;YES&quot; or &quot;NO&quot;. *The unselected choice is displayed blinking. to select, press the &quot;A&quot; key (SAVE). The &quot;YES&quot; or &quot;NO&quot; in the D display window will then stop blink­ing, indicating that it is now selected.

The default condition upon initialization is that the camera isolate feature is disabled. Reinitializing the terminal will place this function in the disabled state.

Exit this mode by pressing the &quot;CLR&quot; key.

Privacy Override (PD33)

Enter &quot;PD33&quot; to access this function. The A-D display window then changes to

**&quot;PRIV. OVRD&quot;**

an­d either &quot;YES&quot; or &quot;NO&quot;, depending on the current setup. Pressing the &quot;P&quot; key (ADV.) toggles the D display between &quot;YES&quot; or &quot;NO&quot;. The unselected choice is displayed blinking. to select, press the &quot;A&quot; key (SAVE). The &quot;YES&quot; or &quot;NO&quot; in the D display window will then stop blink­ing, indicating that it is now selected.

Exit this mode by pressing the &quot;CLR&quot; key.

The privacy override feature is disabled or turned off by default at initialization.

Tally Timeout Delay (PD34)

The Calling Tally timeout delay is selec­table from ap­proximately 2 sec­onds to 15 seconds by choosing a delay factor from 1 to 8 as outlined below.

Enter &quot;PD34&quot; to access this function. If a passcode was defined, enter the correct code to the

**&quot;ACCESS CODE _ _ _ _&quot;**

prompt in the A-D display window. The A-D display windows changes to &quot;TLY DELAY FACT: x&quot;, where &quot;x&quot; means the currently selected delay factor, a number from 1-8.

Pressing the &quot;P&quot; key (ADV.) increases the delay factor up to a maximum of 8 (approximately 15 seconds) and then folds back to 1. The delay factor is displayed blinking when unselected. to select the displayed delay factor, press the &quot;A&quot; key (SAVE). The number in the display will then stop blinking, indicating the selected delay factor.

Exit this mode by pressing the &quot;CLR&quot; key.

The call tally time-out delay defaults to a setting of 2 (approx 4 secs) at initialization. After reinitialization (PD50) the default setting will also be 2.

Hot Mic Select (PD37)

Enter &quot;PD37&quot; to access this function. The A-D display window then changes to

**&quot;HOT MIC MODE&quot;**

and either &quot;YES&quot; or &quot;NO&quot; depending on the current setup. Pressing the &quot;P&quot; key (ADV.) toggles the display between &quot;YES&quot; and &quot;NO&quot;. The unselected choice is displayed blinking. to select, press the &quot;A&quot; key (SAVE). The &quot;YES&quot; or &quot;NO&quot; in the D display window will then stop blinking, indicating that it is now selected.

Exit this mode by pressing the &quot;CLR&quot; key.

When the terminal is initialized the default setting is the &quot;Enable Key&quot; function. Reinitialization of the terminal will not change the definition of this function.

IFB/ISO Lock Key (PD38)

Enter &quot;PD38&quot; to access this function. The A-D display window then changes to

**&quot;IFB/ISO LOCK&quot;**

and either &quot;YES&quot; or &quot;NO&quot;, depending on the current setup. Pressing the &quot;P&quot; key (ADV.) toggles the D display between &quot;YES&quot; or &quot;NO&quot;. The un­selected choice is displayed blinking. to select, press the &quot;A&quot; key (SAVE). The &quot;YES&quot; or &quot;NO&quot; in the D display window will then stop blink­ing, indicating that it is now selected.

Exit this mode by pressing the &quot;CLR&quot; key.

The default condition upon initialization is that the Lock Talk keyswitch associated with an IFB assignment is enabled (Yes) as per other talk keyswitch functions.

When placed in the &quot;NO&quot; state the Lock Talk Keyswitch associated with an IFB assignment is only a momentary function.

Reinitializing the terminal places this function in the enabled (Yes) state.

Keypad Disable (PD46)

Enter &quot;PD46&quot; to access this function. The A-D display window then changes to

**&quot;KEYPAD EDIT&quot;**

an­d either &quot;YES&quot; or &quot;NO&quot;, depending on the current setup. Pressing the &quot;P&quot; key (ADV.) toggles the D display between &quot;YES&quot; or &quot;NO&quot;. The un­selected choice is displayed blinking. to select, press the &quot;A&quot; key (SAVE). The &quot;YES&quot; or &quot;NO&quot; in the D display window will then stop blink­ing, indicating that it is now selected.

Exit this mode by pressing the &quot;CLR&quot; key.

Disabling the keypad when the terminal is selected to a particular page (1 to 3) will retain the keyswitch assignments as defin­ed.

to realize assignments from the central as­signment computer only, ensure the ter­minal is selected to page #4 prior to disabling the keypad.

The keypad disable feature defaults to an enabled condition at initialization. Similarly if the terminal is reinitialized (selection of PD50) the keypad is placed in the &quot;Yes&quot; or enabled con­dition.

Expander Panel (PD47)

Enter &quot;PD47&quot; to access this function. The A-D display window then changes to

**&quot;E­XPAND­ER PNL&quot;**

an­d either &quot;YES&quot; or &quot;NO&quot;, depending on the current setup. Pressing the &quot;P&quot; key (ADV.) toggles the D display between &quot;YES&quot; or &quot;NO&quot;. The un­selected choice is displayed blinking. to select, press the &quot;A&quot; key (SAVE). The &quot;YES&quot; or &quot;NO&quot; in the D display window will then stop blink­ing, indicating that it is now selected.

Exit this mode by pressing the &quot;CLR&quot; key.

The expander panel should only be selected when the terminal is used with the M7881. The M7880/M7880B Com­munications Terminal must also be built with Option 1 to accept the expander panel.

With the M7882/M7883 terminal, extensive modification must be made to incorporate the M7881 expander, consult with the factory for details.

The default at initialization is &quot;No&quot; condition where an expander panel is not accessible. Reinitializing the terminal does not alter this definition.

Matrix Size (PD48)

Enter &quot;PD48&quot; to access this function. The A-D display window then changes to

**&quot;MATRIX SIZE&quot;**

an­d the currently selected size is displayed.

The following matrix sizes are currently supported:

48, 96,144,192,240

Ina MiniCOM system the matrix size should beset to 48.

Pressing the &quot;P&quot; key (ADV.) selects the next higher matrix size in the D display window up to the maximum size of 240, after which it rolls over to 48. The unselected sizes are blinking in the D display widow. Pressing the &quot;A&quot; key (SAVE) stores the displayed matrix size in the configuration table. The display will then stop blinking, indicating that it is now selected.

Exit this mode by pressing the &quot;CLR&quot; key.

The matrix size is set to 48 at initialization. Reinitializing the terminal does not alter a previously set size definition.

Reinitialize Terminal (PD50)

Enter &quot;PD50&quot; to access this function. The A-D display then chan­ges to

**&quot;FORMATTING SYS­TEM PLEASE WAIT&quot;**

and the terminal will reinitialize to a de­fault configuration. Caution: All assign­ments contained in the terminal index table will be lost.

If the terminal is on-line with the intercom matrix, the index table and mnemonic code table will be updated within a few min­utes.

Terminal Revision Select (PD71)

Enter &quot;PD71&quot; to access this function. The A-D display then changes to

**&quot;TERMINAL REV.&quot;**

and the currently selected Revision (&quot;A&quot; or &quot;B&quot;).­ Pressing the &quot;P&quot; key (ADV.) toggles the D display between &quot;A&quot;, &quot;B&quot; and &quot;C&quot;. The un­selected choice is displayed blinking. to select, press the &quot;A&quot; key (SAVE). The &quot;A&quot;, &quot;B&quot; or &quot;C&quot; in the D display window will then stop blink­ing, in­dicating that it is now selected.

Exit this mode by pressing the &quot;CLR&quot; key.

At reinitialization the terminal will be con­figured as per Rev. &quot;A&quot;. Refer to the &quot;con­figuration&quot; detail supplied in the systems manual for your particular system.

RAM Test (PD91)

Enter &quot;PD91&quot; to access this function. The A-D display window changes to &quot;RAM X TEST ERR. #00&quot;.

The &quot;00&quot; part of the display will indicate the error count of the RAM test.

Exit this mode by pressing the &quot;CLR&quot; key.

Run Tally (PD98)

The front panel &quot;Run&quot; tally maybe enabled or disabled with the setting of this PD code.

Reset Terminal (PD99)

Enter &quot;PD99&quot; to reset the terminal. This function does not require a passcode to be entered. After entering &quot;PD99&quot;, the ter­minal resets to a power-up condition. All as­signments remain as previously defined. However all listen pushbuttons and locking talk buttons will be turned off.

**10) SPEAKER AND LEVEL CON­TROL**

The level control provides for adjust­ments of the audio level leaving the terminal via the speaker.

**11) HDST LEVEL CONTROL**

The headset level control/­sw­itch is a dual function control. First it pro­vides for adjust­ments to the headset level and second, when the switch is acti­vated, the sidetone cross­point is turned on, the front panel micro­phone is turned off and the terminal spea­ker is muted.

When the headset jack is insert­ed the incoming audio signal is heard in the headset and the level is contro­lled by the head­set level control. Pulling on the headset level control knob will activate the HDST MIC LED and turn on the headset micro­phone. The head­set switch is a momentary type with locking action circuitry under soft­ware control.

Pulling on the headset switch again will deactivate the HDST MIC LED, turn off the headset microphone, the sidetone cross­point and will turn on the terminal speak­er and the front panel microphone.

Rear Panel Control Functions Refer to drawing B 7883-04-003

**12) CONNECTOR P4**

Connector P4 contains the +5V and control common interconnects from the M7882 Remote Communications Terminal. See page 9-2 P4 connector layout details.

**13) CONNECTOR J7**

Connector J7 contains the key data and display drives entering from the M7882 Remote Communications Ter­minal. See page 9-1 J7 connector lay­out details.

**14) CONNECTOR J6**

Connector J6 contains the audio in­puts, audio outputs and dc control funct­ions of the audio section interconnecting from the M7882 Rem­ote Communications Terminal. See page 9-3 J6 connector layout details.

**15) MIC CONNECTOR**

Rear panel micro­phone connector XLR-3-32 provides the external con­nect­ion for the dyna­mic microphone feed to the M7882 Remote Communi­cations Terminal. Initial Inspection:

After removal of all packing material, inspect the Com­munications Terminal for any loose components or for any physical damage that may have occurred in transit. If the unit was damaged, contact the carrier and file a claim immediately. Do not dis­card the carton or any packing material until the carrier's represen­tative has noted the damage.

The Communications Ter­minal may have its microphone capsule and the mat­ing 9 pin D data connector for P1 pack­aged separately within the shipp­ing carton. Ensure that these items are located and installed on the terminal before discar­ding the shipping material.

Mating connectors for P2 and P6 are supplied as required.

Determine the following:

1) The keypad and designation strips are labelled according to the appropriate systems definition. 2) The correct software version and or revisions are installed. 3) The correct options if required are installed. The con­figuration modes are setup as per the particular system re­quirements. Refer to the Operational Description area of this manual for details and any overall systems def­init­ion documentation (for example the correct matrix size).

4) Request mating connectors for P2 and P6 as required for particular systems con­figurations. 5) The four interconnecting cables are included and are the required length (15 feet/4.6 meters maximum).

Power Requirements:

The communications ter­minal is designed to operate directly from an AC power source with its integral modular power supply. The power supply is access­ible by removing the top and bottom covers of the terminal.

Note: Service and adjustment of the power supply unit should only be per­formed by personnel knowledgeable with the tech­nology employed and with the correct isolated power sources and test equipment. High voltages are present and extreme caution must betaken.

The power supply may have to be internally strapped for 115V or 230V AC operation. The power con­sumpt­ion is nomi­nally 50 VA.

to gain access to the 115V/230 voltage strap refer to section E of this manual:

Note: the power supply will be damaged if jum­pered or strapped for 115 volts and oper­at­ed on 230V. Mounting

The M7882 and M7883 are designed for stan­dard nine­teen inch rack mounting. They each require only two rack units (2RU) of vertical space. The mounting depth of the M7882 is 9.75 inches (248 mm) and that of the M7883 is 5 inches (127 mm). The M7882 weighs 9 lbs (4.1 kg) and the M7883 weighs 4 lbs (1.8 kg). Matrix Connections:

The M7882 connects to the inter­com matrix via three audio pairs such as Bel­den 8777 or 8451 cable, which extends from data connector P1 at the rear of the unit. Page 8-1 of this manual shows the layout for this connector. Insure that the phase of the serial data pair is correct when wiring this connec­tor (P1 pin 4 corresponds to the low numbered terminal on the matrix termi­nal block).

The typical ground and shielding connections between a communication terminal and the central matrix areas follows:

a) The shield of the data line must be car­ried through between the com­munications ter­minal ground and that of the central matrix (P1 pin 9), see page 8-1). b) The preamplifier output from the com­munications terminal (P1 pin 6) connects to the matrix ground at the matrix ter­minating connector.

c) The speaker amplifier input or audio in from the matrix has its shield connected to the communications terminal ground at P1 pin 3.

All shields should be wired through all connectors to ensure proper and correct shielding, particularly when extension cables are employed.

Configuration:

The following summarizes the typical settings of terminal PD codes. Refer to the systems manual and documentation for the settings that maybe required for the communications system supplied.

**PD CODE FUNCTION DEFINITION COMMENT**

PD21 Terminal Type set to &quot;M7880&quot; required setting for M7882/M7883 operation

PD29 Define Access Code &quot;disabled&quot; activate at customers discretion.

PD31 Call Waiting set to &quot;No&quot; &quot;Yes&quot; at customers discretion.

PD32 Camera ISO set to &quot;No&quot; &quot;Yes&quot; at VO or ISO director station.

PD33 Privacy Override set to &quot;No&quot; &quot;Yes&quot; at customer discretion.

PD34 Call Tally Timeout set to &quot;4&quot; 1-8 at customers discretion.

PD37 Hot Mic Mode set to &quot;No&quot; &quot;Enable&quot; key active as described in oper­ational description

PD38 IFB/ISO Lock set to &quot;Yes&quot; &quot;Yes&quot; will set locking talk key-switch to a Lock function.

PD46 Keypad Edit set to &quot;Yes&quot; &quot;No&quot; will disable keypad, as­signment will be fixed as to page setting when the keypad is disabled.

PD47 Expander Panel set to &quot;No&quot;

PD48 Matrix Size set to system size For MiniCOM set to 48. with which the terminals were shipped.

PD50 reinitializes the M7882/M7883 communications terminal to a default condition. All entered assignments will be lost, and the majority of PD configuration codes revert to their default condition. They will have to be re-established to the settings required for the communications system.

PD71 Revision set to &quot;A&quot; for System II-A operation (IFB priority) set to &quot;B&quot; for System II-B operation (for M7880F expander terminals) set to &quot;C&quot; for System I operation (no IFB priority) Audio Connections

The M7883 maybe operated with a remote speaker and dynamic microphone or with a headset. An external speaker maybe connected at P6-13 and 12 after dis­con­necting the term­inal speaker by cutting the link LK5 on the SA14-271B Audio Assembly. The speaker inter­connect at P6-25 maybe used to reconnect the terminal speaker.

Headset operation is available via the 1/4 inch tip, ring, sleeve receptacle at the lower right corner of the terminal front panel. This receptacle is compat­ible with the Switchcraft #267 jackplug. The tip wires to the microphone, the ring to the headset and the sleeve is the common.

A headset such as the Beyer DT108/­DT109 series with a 400 ohm or higher headset impedance and an amplified dynamic microphone capsule is recom­mended.The phantom power required to operate the preamplifier circuit integral to the headset is supplied from the terminal via the headset receptacle.

When the headset function is selected, the front panel dynamic microphone is switch­ed off, the preamplifier input is trans­ferred to the headset receptacle and the front panel speaker is muted.

Connector P6 on the M7882 provides a means of connect­ing an external headset from a secondary receptacle into the communi­cation term­inal. By grounding headset control terminal P6-22 a solid-state selector switches the pre­amplifier to the headset micro­phone input. This control also activates a relay at the speaker output and mutes the ter­minal's speaker with­out affecting the head­set output at P6-10, 11 (9).

The phantom power on the headset input allows the use of a variety of balanced or unbalanced amplified dynamic micro­phones. See pages 5-6 and 5-7 for sug­gested wiring diagrams for balanced and unbalanced headsets to the terminal. Note In the unbalanced configuration the cable length should be limited to twenty-five feet or less.

An external preamplifier input is pro­vided at P2-15 &amp; 16. This sound feed is sep­arate from the microphone input itself. Connect­ing P2-17 to control common at P2-12 acti­vates the required solid-state switching to make the select­ion. Two switchable inputs are provided to the speaker amplifier. They appear at P6-5 &amp; 6 and P6-7 &amp; 8. Control of these inputs is via P6-18 &amp; 19 to control common (P2-12).

Control Connections:

A footswitch maybe paralleled with the momentary group select function keyswitch on the terminal front panel by a connection at P2-1 and 7. The footswitch uses one of the six prog­rammable external inputs on connector P2.

Cable Connection:

The four interconnecting cables required are restricted to a maximum length of 15 feet (4.6 meters). Shorter cables, maybe specified at the time of ordering. Headset Connections and Wiring

FIG. 1 An amplified dynamic microphone headset with dual and separate earpieces (balanced).

FIG. 2 A dynamic microphone headset with an unbalanced microphone and unbalanced dual earpieces. XLR connector termination.

**FIG. 3**

A dynamic microphone headset with an unbalanced microphone and an unbalanced earpiece, tip, ring, sleeve termination.

Note: The front panel headset receptacle is wired for an amplified dynamic type headset with an nominal output level of -40 dBu.

Headset Wiring (Beyer DT108/DT109)

The Beyer DT109 dynamic studio headphone is a standard for most intercom systems and broadcast two-way communications today.

The DT109 provides a wide frequency response dynamic headset with the inclus­ion of an integral dynamic boom microphone. The DT108 headset may also be used. It is a single-muff version of the DT109.

Illustrated below is the wiring for the Beyer DT109 or DT108 headphones to a Cannon XLR-5-12C connector.

</details>

<!-- /module data -->

## Photos

_Photographs of the module itself: front, back, inside, racked._

<table>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKdFAwSzVKYlN4Uk0/view?resourcekey=0-ca7gLown007jiQYK7yRi0g" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKdFAwSzVKYlN4Uk0&resourcekey=0-ca7gLown007jiQYK7yRi0g" width="240" alt="1994 - M7880 - Screen Shot 2013-03-10 at 10.52.45 PM.png"></a><br><sub>1994|27 · Screen Shot 2013-03-10 at 10.52.45 PM</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKX3pSMXRyb3Jtelk/view?resourcekey=0-GYO4wa75Ol6FhOZVDVAh-Q" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKX3pSMXRyb3Jtelk&resourcekey=0-GYO4wa75Ol6FhOZVDVAh-Q" width="240" alt="1994 - M7880 - Screen Shot 2013-03-10 at 10.52.51 PM.png"></a><br><sub>1994|27 · Screen Shot 2013-03-10 at 10.52.51 PM</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKMnZvUmVPZUNKTjA/view?resourcekey=0-iiG75tp6gnStQ5LyEB8zrQ" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKMnZvUmVPZUNKTjA&resourcekey=0-iiG75tp6gnStQ5LyEB8zrQ" width="240" alt="1994 - M7880 - Screen Shot 2013-03-10 at 10.52.58 PM.png"></a><br><sub>1994|27 · Screen Shot 2013-03-10 at 10.52.58 PM</sub></td></tr>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKRFVTaXI4amVlblU/view?resourcekey=0-4AN4pGusq7oosJABvt__7g" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKRFVTaXI4amVlblU&resourcekey=0-4AN4pGusq7oosJABvt__7g" width="240" alt="1994 - M7880 - Screen Shot 2013-03-10 at 10.53.06 PM.png"></a><br><sub>1994|27 · Screen Shot 2013-03-10 at 10.53.06 PM</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKUVd2OC04Wk5iYXM/view?resourcekey=0-0_mafKDHrYqCF4Yl9G250Q" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKUVd2OC04Wk5iYXM&resourcekey=0-0_mafKDHrYqCF4Yl9G250Q" width="240" alt="1994 - M7880 - Screen Shot 2013-03-10 at 10.53.14 PM.png"></a><br><sub>1994|27 · Screen Shot 2013-03-10 at 10.53.14 PM</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKbmRfZlJEOEtsMW8/view?resourcekey=0-77v7mnJr-b8uXjk65DF2Ow" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKbmRfZlJEOEtsMW8&resourcekey=0-77v7mnJr-b8uXjk65DF2Ow" width="240" alt="1994 - M7880 - Screen Shot 2013-03-10 at 10.53.20 PM.png"></a><br><sub>1994|27 · Screen Shot 2013-03-10 at 10.53.20 PM</sub></td></tr>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKYTFhV3FjZHh5Rmc/view?resourcekey=0-5bJFhdDgObFOTCwXxBNI5Q" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKYTFhV3FjZHh5Rmc&resourcekey=0-5bJFhdDgObFOTCwXxBNI5Q" width="240" alt="1994 - M7880 - TV-BROADCAST-INTERCOM 001.jpg"></a><br><sub>1994|27 · TV-BROADCAST-INTERCOM 001</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKcVBiY2NxbGFGNDQ/view?resourcekey=0-13k3Qb8RsnOrxlR87XNsaw" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKcVBiY2NxbGFGNDQ&resourcekey=0-13k3Qb8RsnOrxlR87XNsaw" width="240" alt="1994 - M7880 - TV-BROADCAST-INTERCOM 002.jpg"></a><br><sub>1994|27 · TV-BROADCAST-INTERCOM 002</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKS0ZnSFFCZU1rbkk/view?resourcekey=0-7v0D-NX-DSI54IZVpqpYRA" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKS0ZnSFFCZU1rbkk&resourcekey=0-7v0D-NX-DSI54IZVpqpYRA" width="240" alt="1994 - M7880 - TV-BROADCAST-INTERCOM 003.jpg"></a><br><sub>1994|27 · TV-BROADCAST-INTERCOM 003</sub></td></tr>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKenUyekZUWnlHVUE/view?resourcekey=0-Q-tNrsZkF2PTtRfwAyZi-w" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKenUyekZUWnlHVUE&resourcekey=0-Q-tNrsZkF2PTtRfwAyZi-w" width="240" alt="1994 - M7880 - TV-BROADCAST-INTERCOM 004.jpg"></a><br><sub>1994|27 · TV-BROADCAST-INTERCOM 004</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKUTNZR3pfc1hYdm8/view?resourcekey=0-XQ3NFHeJOZ3ObML9rUQdLw" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKUTNZR3pfc1hYdm8&resourcekey=0-XQ3NFHeJOZ3ObML9rUQdLw" width="240" alt="1994 - M7880 - TV-BROADCAST-INTERCOM 005.jpg"></a><br><sub>1994|27 · TV-BROADCAST-INTERCOM 005</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKektrVVE2MHAwVjg/view?resourcekey=0-J1UGADUgIbo2qvqcv4wBkQ" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKektrVVE2MHAwVjg&resourcekey=0-J1UGADUgIbo2qvqcv4wBkQ" width="240" alt="1994 - M7880 - TV-BROADCAST-INTERCOM 006.jpg"></a><br><sub>1994|27 · TV-BROADCAST-INTERCOM 006</sub></td></tr>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKNWxNUXM0b2xyNDg/view?resourcekey=0-NtaVFwGBA134UcltygQ7RQ" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKNWxNUXM0b2xyNDg&resourcekey=0-NtaVFwGBA134UcltygQ7RQ" width="240" alt="1994 - M7880 - TV-BROADCAST-INTERCOM 007.jpg"></a><br><sub>1994|27 · TV-BROADCAST-INTERCOM 007</sub></td></tr>
</table>

## Mechanical

_Mechanical drawings: front panels, cover plates, metalwork and hardware (-03- drawings), AutoCAD files, each with its `(EXTRACTED).svg` vectors; `<module> - front panel.svg` is the front panel as vectors._

<table>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/1hdFE6B2-hT-fXAUQkF3og65VXiOwJ65N/view" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=1hdFE6B2-hT-fXAUQkF3og65VXiOwJ65N" width="240" alt="1989 - M7880 - DOC - 093047-04-001 - NOTE NOTE NORMALLED JACK PAIR NOTE CAMERA PRUGRAN.jpg"></a><br><sub>1989|22 · DOC - 093047-04-001 - NOTE NOTE NORMALLED JACK PAIR NOTE CAMERA PRUGRAN · <a href="MECHANICAL/1989%20-%20M7880%20-%20DOC%20-%20093047-04-001%20-%20NOTE%20NOTE%20NORMALLED%20JACK%20PAIR%20NOTE%20CAMERA%20PRUGRAN%20(EXTRACTED).svg">vectors</a></sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/1ZGr_ikfoF2Jgc5_zfbp96kto5yM1dhJL/view" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=1ZGr_ikfoF2Jgc5_zfbp96kto5yM1dhJL" width="240" alt="1996 - M7880 - DOC - 960163-04-002 - KEYPAD LAYOUI IISSUE REVSION.jpg"></a><br><sub>1996|29 · DOC - 960163-04-002 - KEYPAD LAYOUI IISSUE REVSION · <a href="MECHANICAL/1996%20-%20M7880%20-%20DOC%20-%20960163-04-002%20-%20KEYPAD%20LAYOUI%20IISSUE%20REVSION%20(EXTRACTED).svg">vectors</a></sub></td></tr>
</table>

## 3-D model

[`MECHANICAL/M7880.stl`](MECHANICAL/M7880.stl) (GitHub turns it in 3-D) · [view, change and generate it on WBSps.ca](https://wardbecksystems.github.io/WBSps.ca/2026/stl.html?m=M7880)

- **Size:** 41 × 178 mm panel, 165 mm deep, 3.2 mm plate (assumed: 1.6" x 7" x 6.5", the common module)
- **From the drawing:** 0 holes and cut-outs, 0 knobs (front panel: `MECHANICAL/M7880 - front panel.svg`)
- no drawing of the front panel: the panel is blank
- Made by `tools/module_models.py` (→ `MECHANICAL/M7880.model.json`) and `tools/stl/make_stl.mjs` in [WBSps.ca](https://github.com/WardBeckSystems/WBSps.ca); the site makes the same STL from the same JSON.

## Schematics

_Electrical drawings: schematics (-02-), functional diagrams (-01-), component layouts (-06-), wiring (-09-), PCB files (.pcb .dsn), and beside each scan its `(EXTRACTED).svg`: the vectors traced from it._

<table>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/1cm__TLpjcW-Ato0a0XZM4k2U9jJacZBE/view" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=1cm__TLpjcW-Ato0a0XZM4k2U9jJacZBE" width="240" alt="1994 - M7880 - DOC - 940145-01-001 - PROGRAM SOUND PROGRAM SOUND PROGRAM SOUND.jpg"></a><br><sub>1994|27 · DOC - 940145-01-001 - PROGRAM SOUND PROGRAM SOUND PROGRAM SOUND · <a href="SCHEMATICS/1994%20-%20M7880%20-%20DOC%20-%20940145-01-001%20-%20PROGRAM%20SOUND%20PROGRAM%20SOUND%20PROGRAM%20SOUND%20(EXTRACTED).svg">vectors</a></sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/15SPsqhzm9IVmE25FmRXd5lfm78a_o7Rj/view" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=15SPsqhzm9IVmE25FmRXd5lfm78a_o7Rj" width="240" alt="1994 - M7880 - DOC - 94055-01-003 - IRS JACKS FOR ILLUSTRATIVE PURPOSES MAXIMUM DISTANCE FROM.jpg"></a><br><sub>1994|27 · DOC - 94055-01-003 - IRS JACKS FOR ILLUSTRATIVE PURPOSES MAXIMUM DISTANCE FROM · <a href="SCHEMATICS/1994%20-%20M7880%20-%20DOC%20-%2094055-01-003%20-%20IRS%20JACKS%20FOR%20ILLUSTRATIVE%20PURPOSES%20MAXIMUM%20DISTANCE%20FROM%20(EXTRACTED).svg">vectors</a></sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/1cBkMVlYVhwj_w7PbS5VbWUTogJBj8LD1/view" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=1cBkMVlYVhwj_w7PbS5VbWUTogJBj8LD1" width="240" alt="1995 - M7880 - DOC - 95014-01-002 - FUTURC IFB OUTPUTS.jpg"></a><br><sub>1995|28 · DOC - 95014-01-002 - FUTURC IFB OUTPUTS · <a href="SCHEMATICS/1995%20-%20M7880%20-%20DOC%20-%2095014-01-002%20-%20FUTURC%20IFB%20OUTPUTS%20(EXTRACTED).svg">vectors</a></sub></td></tr>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/1Kot4DKkIUC0aNGBNSIvITrlfI_2PD8uJ/view" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=1Kot4DKkIUC0aNGBNSIvITrlfI_2PD8uJ" width="240" alt="1995 - M7880 - DOC - 950271-01-002 - GER ENGR TRKI.jpg"></a><br><sub>1995|28 · DOC - 950271-01-002 - GER ENGR TRKI · <a href="SCHEMATICS/1995%20-%20M7880%20-%20DOC%20-%20950271-01-002%20-%20GER%20ENGR%20TRKI%20(EXTRACTED).svg">vectors</a></sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/1epEfFzCCyPharZz_vYkyVKj0uGhmD35S/view" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=1epEfFzCCyPharZz_vYkyVKj0uGhmD35S" width="240" alt="1996 - M7880 - DOC - 96010-01-001 - AND MONITOR CARDS SHOWN ARE CPTCNAL MODULES REUSED.jpg"></a><br><sub>1996|29 · DOC - 96010-01-001 - AND MONITOR CARDS SHOWN ARE CPTCNAL MODULES REUSED · <a href="SCHEMATICS/1996%20-%20M7880%20-%20DOC%20-%2096010-01-001%20-%20AND%20MONITOR%20CARDS%20SHOWN%20ARE%20CPTCNAL%20MODULES%20REUSED%20(EXTRACTED).svg">vectors</a></sub></td></tr>
</table>

## Manuals and documents

_Manuals and manual pages, price lists, RTO-144 connection sheets, brochures, ads and other document scans._

<table>
<tr><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/1PPJ8e75VldSnwdvX3vCeN_OU3qsCBfpL/view" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=1PPJ8e75VldSnwdvX3vCeN_OU3qsCBfpL" width="240" alt="1998 - M7880 - DOC - Scan_20210323.jpg"></a><br><sub>1998|31 · DOC - Scan_20210323</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/0B0yR0b5T78SKaXhhUHpCbWpwS28/view?resourcekey=0-b7yuPtAlLRppFNXq7C-NCQ" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=0B0yR0b5T78SKaXhhUHpCbWpwS28&resourcekey=0-b7yuPtAlLRppFNXq7C-NCQ" width="240" alt="19xx - M7880 - AD - WBSPS - AD - Microcom II 0012.jpg"></a><br><sub>19xx - M7880 - AD - WBSPS - AD - Microcom II 0012</sub></td><td align="center" valign="top" width="33%"><a href="https://drive.google.com/file/d/1radseki5OUFko-6P7hJONYD5aIhC2YBH/view" title="Open on Google Drive"><img src="https://drive.google.com/thumbnail?sz=w480&id=1radseki5OUFko-6P7hJONYD5aIhC2YBH" width="240" alt="19xx - M7880 - DOC - SECTIONS CROSSPOINT CROSSPOINT NORVALLY OFF SWITCHED.jpg"></a><br><sub>19xx - M7880 - DOC - SECTIONS CROSSPOINT CROSSPOINT NORVALLY OFF SWITCHED</sub></td></tr>
</table>

## KiCad

_KiCad: a schematic (`.kicad_sch`) traced from each electrical drawing, the module symbol (`.kicad_sym`) and its PCB projects. Traced schematics are the line work only: redraw with symbols over them._

- [1994 - M7880 - DOC - 940145-01-001 - PROGRAM SOUND PROGRAM SOUND PROGRAM SOUND.kicad_sch](KICAD/1994%20-%20M7880%20-%20DOC%20-%20940145-01-001%20-%20PROGRAM%20SOUND%20PROGRAM%20SOUND%20PROGRAM%20SOUND.kicad_sch)
- [1994 - M7880 - DOC - 94055-01-003 - IRS JACKS FOR ILLUSTRATIVE PURPOSES MAXIMUM DISTANCE FROM.kicad_sch](KICAD/1994%20-%20M7880%20-%20DOC%20-%2094055-01-003%20-%20IRS%20JACKS%20FOR%20ILLUSTRATIVE%20PURPOSES%20MAXIMUM%20DISTANCE%20FROM.kicad_sch)
- [1995 - M7880 - DOC - 95014-01-002 - FUTURC IFB OUTPUTS.kicad_sch](KICAD/1995%20-%20M7880%20-%20DOC%20-%2095014-01-002%20-%20FUTURC%20IFB%20OUTPUTS.kicad_sch)
- [1995 - M7880 - DOC - 950271-01-002 - GER ENGR TRKI.kicad_sch](KICAD/1995%20-%20M7880%20-%20DOC%20-%20950271-01-002%20-%20GER%20ENGR%20TRKI.kicad_sch)
- [1996 - M7880 - DOC - 96010-01-001 - AND MONITOR CARDS SHOWN ARE CPTCNAL MODULES REUSED.kicad_sch](KICAD/1996%20-%20M7880%20-%20DOC%20-%2096010-01-001%20-%20AND%20MONITOR%20CARDS%20SHOWN%20ARE%20CPTCNAL%20MODULES%20REUSED.kicad_sch)
- [M7880.kicad_sym](KICAD/M7880.kicad_sym)

## Software

- [cpp](SOFTWARE/cpp)

---
Archive: Anthony Peter Kuzub · [WBSps.ca](https://WBSps.ca) · [WBSps.Kuzub.com](https://WBSps.Kuzub.com)
