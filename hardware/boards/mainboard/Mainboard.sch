EESchema Schematic File Version 4
LIBS:Mainboard-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 12
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 1000 1000 500  150 
U 5D772FD9
F0 "Teensy" 50
F1 "kryon-ver2.1-final_1.sch" 50
$EndSheet
$Sheet
S 3000 1000 500  150 
U 5D772FF8
F0 "Power and bypass caps" 50
F1 "kryon-ver2.1-final_2.sch" 50
$EndSheet
$Sheet
S 5000 1000 500  150 
U 5D7730F8
F0 "daughter board connectors" 50
F1 "kryon-ver2.1-final_3.sch" 50
$EndSheet
$Sheet
S 7000 1000 500  150 
U 5D773153
F0 "codec" 50
F1 "codec.sch" 50
$EndSheet
$Comp
L power:GND #PWR0102
U 1 1 5D8F3899
P 6650 3350
F 0 "#PWR0102" H 6650 3100 50  0001 C CNN
F 1 "GND" H 6655 3177 50  0000 C CNN
F 2 "" H 6650 3350 50  0001 C CNN
F 3 "" H 6650 3350 50  0001 C CNN
	1    6650 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 3350 6650 3350
Text GLabel 6400 3950 2    50   Input ~ 0
VIN
Text GLabel 7500 3550 2    70   Output ~ 0
KC_TEENSY_RX
Wire Wire Line
	6400 3550 7500 3550
Text GLabel 7500 3750 2    70   Input ~ 0
KC_TEENSY_TX
$Comp
L knobs-eagle-import:JST---S4B-PH-SM4-TB(LF)(SN)_JST_S4B-PH-SM4-TB_LF_SNJST_S4B-PH-SM4-TB_LF_SN_0_0 J2
U 1 1 5D8FCBBF
P 5600 2950
F 0 "J2" H 6540 2850 85  0000 C CNN
F 1 "JST---S4B-PH-SM4-TB(LF)(SN)_JST_S4B-PH-SM4-TB_LF_SNJST_S4B-PH-SM4-TB_LF_SN_0_0" H 5600 2950 50  0001 C CNN
F 2 "knobs:JST---S4B-PH-SM4-TB(LF)(SN)_JST_S4B-PH-SM4-TB_LF_SN_0" H 5600 2950 50  0001 C CNN
F 3 "" H 5600 2950 50  0001 C CNN
	1    5600 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 3750 7500 3750
NoConn ~ 6400 4350
NoConn ~ 6400 4150
$EndSCHEMATC
