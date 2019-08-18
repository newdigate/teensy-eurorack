# Knobs Controller

An independent rotary encoder and potentiometer breakout board based on Arduino MKR Zero, SAMD21G18A-MU. 
* 4 x 12bit rotary potentiometers
* 3 x RGB Illuminated rotary encoder w/ switch
* Communicates with mainboard via serial.

In this experiment I want to reduce the number of pins used on my teensy micro-controller which are used by my rotaries and pots.

By introducing an intermediate micro-controller (ARM cortex M0 / SAMD21G) and writing some firmware to relay input info via and receive commands via serial, I can reduce the number of connections to just 4: +5V, ,TX,RX;  

I started with the schematic of aduino mkr zero and removed components which I don't need. 

## Images

![top view](images/Knob_controller_top_view.png)

![bottom view](images/Knob_controller_bottom_view.png)

## BOM
| Qty | Parts                                       | Value                               | MPN                   | Package                       | Description                                                                  |
|-----|---------------------------------------------|-------------------------------------|-----------------------|-------------------------------|------------------------------------------------------------------------------|
| 4   | VR1, VR2, VR3, VR4                          |                                     |                       | 9MM_SNAP-IN_POT               | 9mm vertical snap-in pot, Alpha / Panasonic style                            |
| 1   | J1                                          | ZX62-AB-5PA(31)                     | ZX62-AB-5PA(31)       | USBMICRO-ZX62-AB-5PA          |                                                                              |
| 9   | ENC*:R12, ENC*:R13, ENC*:R14                | 10                                  | RL1220S-100-F         | R0805                         | RESISTOR, European symbol                                                    |
| 4   | C19, C28, C29, C30                          | 100nF                               | 08055C104KAT2A        | C0805                         | CAPACITOR, European symbol                                                   |
| 16  | R16, ENC*:R1, ENC*:R4, ENC*:R5, ENC*:R7, ENC*:R9 | 10k                                 | RNCP0805FTD10K0       | R0805                         | RESISTOR, European symbol                                                    |
| 6   | ENC*:C1, ENC*:C3                            | 10nF                                | CL21B103KBANNNC       | C0805                         | CAPACITOR, European symbol                                                   |
| 1   | R2                                          | 1M                                  | CR0805-JW-105ELF      | R0805                         | RESISTOR, European symbol                                                    |
| 1   | C4                                          | 1nF                                 | C0805C102KARACAUTO    | C0805                         | CAPACITOR, European symbol                                                   |
| 1   | C5                                          | 1nF                                 | C1206C102J3REC7800    | C1206                         | CAPACITOR, European symbol                                                   |
| 3   | C8, C10 , C32                              | 1uF                                 | CL21B105KAFNNNE      | C0805                         | CAPACITOR, European symbol                                                   |
| 2   | C9, C11                                     | 20pF                                | CL21C200JBANNNC       | C0805                         | CAPACITOR, European symbol                                                   |
| 1   | Y1                                          | 32.768KHz                           | ABS07-32.768KHZ-T     | QUARZO-ABS07                  | CRYSTAL 32.768KHZ 12.5PF SMD 3.2x1.5mm                                       |
| 1   | R18                                         | 330R                                | RMCF0805JT330R        | R0805                         | RESISTOR, European symbol                                                    |
| 1   | C6                                          | 4.7nF                               | C0805C472K5GECAUTO    | R0805                         | CAPACITOR, European symbol                                                   |
| 1   | C27                                         | 4.7uF                               | CL21A475KOFNNNG       | R0805                         | CAPACITOR, European symbol                                                   |
| 1   | J4                                          | JST---S4B-PH-SM4-TB(LF)(SN)         | S4B-PH-SM4-TB(LF)(SN) | JST_S4B-PH-SM4-TB_LF_SN_0     | 4 Positions Header Connector 0.079 (2.00mm) Surface Mount, Right Angle Tin"" |
| 1   | D2                                          | LED_LTL-1CHG                        | LTL-1CHG              | RADIAL 3MM                    | LED RED DIFFUSED T/H                                                         |
| 1   | U2                                          | AP7215-33YG-13                      | AP7215-33YG-13        | SOT150P400X160-3N             | IC REG LDO 3.3V 0.6A SOT89-3                                                 |
| 1   | U3                                          | ATSAMD21G18A-MU                     | ATSAMD21E18A-MU       | QFN50P700X700X90-49XN-EPSQ515 | IC MCU 32BIT 256KB FLASH 48QFN                                               |
| 2   | L2, L6                                      | BLM18PG471SN1D                      | BLM18PG471SN1D        | 0603-1608X90N                 | FERRITE CHIP 470 OHM 1000MA 0603                                             |
| 1   | F2                                          | MF-FSMF050X-2                       | MF-FSMF050X-2         | 0603-F1608X100N               | FUSE PTC RESET 500MA SMD 0603                                                |
| 1   | D3                                          | PMEG2005EL                          | PMEG2005EL,315        | SODFL1008X40N-882D            | DIODE SCHOTTKY 20V 500MA SOD882                                              |
| 1   | D1                                          | PRTR5V0U2X,215                      | PRTR5V0U2X,215        | SOT190P230X110-4N             | TVS DIODE 5.5VWM SOT143B                                                     |
| 3   | ENC*:SW1                                    | Rotary Encoder w/RGB led and switch |                       | ENCODER_LED_3_KIT             | Illuminated Rotary Encoder w/ RGB LED and select switch                      |
| 1   | J8                                          | 3x2 SMD 0.1” header - SWD           | M20-8760342           |                               |                                                                              |
