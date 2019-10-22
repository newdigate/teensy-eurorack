EESchema Schematic File Version 5
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 12
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
Comment5 ""
Comment6 ""
Comment7 ""
Comment8 ""
Comment9 ""
$EndDescr
Wire Wire Line
	2050 5050 2450 5050
Text GLabel 2450 5050 2    70   BiDi ~ 0
GND
Text GLabel 800  2350 2    70   BiDi ~ 0
GND
Wire Wire Line
	5050 2050 5350 2050
Text Label 3150 2350 0    70   ~ 0
USB_B_VCC
Text Label 2450 2250 0    70   ~ 0
USB_B_D-
Text Label 3450 2150 0    70   ~ 0
USB_B_D+
Text Label 1050 2650 0    70   ~ 0
USB_A_VCC
Text Label 1150 2450 0    70   ~ 0
USB_A_D+
Wire Wire Line
	2050 3650 2350 3650
Wire Wire Line
	2050 3550 2450 3550
Wire Wire Line
	2050 3450 2350 3450
Wire Wire Line
	2050 3350 2450 3350
Text Label 1150 2550 0    70   ~ 0
USB_A_D-
$Comp
L Mainboard-eagle-import:MOLEX_52892-3033MOLEX_52892-3033_0_0 J1
U 1 1 F1780596
P 1450 5150
F 0 "J1" H 1450 5050 85  0000 L TNN
F 1 "MOLEX_52892-3033MOLEX_52892-3033_0_0" H 1450 5150 50  0001 C CNN
F 2 "Mainboard:MOLEX_52892-3033_0" H 1450 5150 50  0001 C CNN
F 3 "" H 1450 5150 50  0001 C CNN
	1    1450 5150
	0    -1   -1   0   
$EndComp
$Comp
L Mainboard-eagle-import:PINHD-1X4 JUSB_B1
U 1 1 60AD87F5
P 4950 2150
F 0 "JUSB_B1" H 4700 2475 59  0000 L BNN
F 1 "PINHD-1X4" H 4700 1850 59  0000 L BNN
F 2 "Mainboard:1X04" H 4950 2150 50  0001 C CNN
F 3 "" H 4950 2150 50  0001 C CNN
	1    4950 2150
	-1   0    0    1   
$EndComp
Wire Wire Line
	2050 4950 2850 4950
Wire Wire Line
	2050 4850 2250 4850
Wire Wire Line
	2050 4750 2850 4750
Wire Wire Line
	2050 4650 2250 4650
Wire Wire Line
	2050 4550 2850 4550
Wire Wire Line
	2050 4450 2250 4450
Wire Wire Line
	2050 4250 2200 4250
Wire Wire Line
	2050 4350 2950 4350
Text GLabel 2850 4950 2    50   BiDi ~ 0
AD_CS
Text GLabel 2250 4850 2    50   BiDi ~ 0
AD_RESET
Text GLabel 2850 4750 2    50   BiDi ~ 0
AD_CONVST
Text GLabel 2250 4650 2    50   BiDi ~ 0
AD_BUSY
Text GLabel 2850 4550 2    50   BiDi ~ 0
SPI0_MISO
Text GLabel 2250 4450 2    50   BiDi ~ 0
SPI0_SCK
Text GLabel 2950 4350 2    50   BiDi ~ 0
TFT_CS
Text GLabel 2200 4250 2    50   BiDi ~ 0
TFT_DC
Text GLabel 2050 4150 2    50   BiDi ~ 0
AVSS
Text GLabel 2050 4050 2    50   BiDi ~ 0
AVDD
Text GLabel 2050 3950 2    50   BiDi ~ 0
GATE_4
Text GLabel 2050 3850 2    50   BiDi ~ 0
GATE_3
Text GLabel 2050 3750 2    50   BiDi ~ 0
GATE_2
Text GLabel 2350 3650 2    50   BiDi ~ 0
GATE_1
Text GLabel 2450 3550 2    50   BiDi ~ 0
3V3
Text GLabel 2350 3450 2    50   BiDi ~ 0
+3V3
Text GLabel 2450 3350 2    50   BiDi ~ 0
VIN
Wire Wire Line
	500  2350 800  2350
Wire Wire Line
	500  2450 2050 2450
Wire Wire Line
	500  2550 2050 2550
Wire Wire Line
	500  2650 2050 2650
$Comp
L Mainboard-eagle-import:PINHD-1X4 JUSB_A1
U 1 1 A4FDA5DD
P 400 2450
F 0 "JUSB_A1" H 150 2775 59  0000 L BNN
F 1 "PINHD-1X4" H 150 2150 59  0000 L BNN
F 2 "Mainboard:1X04" H 400 2450 50  0001 C CNN
F 3 "" H 400 2450 50  0001 C CNN
	1    400  2450
	-1   0    0    1   
$EndComp
Wire Wire Line
	2050 2150 5050 2150
Wire Wire Line
	2050 2250 5050 2250
Wire Wire Line
	2050 2350 5050 2350
Text GLabel 2050 2750 2    50   BiDi ~ 0
MIDI_RX
Text GLabel 2050 2850 2    50   BiDi ~ 0
MIDI_TX
Text GLabel 2050 2950 2    50   BiDi ~ 0
SPI0_MOSI
Text GLabel 2050 3050 2    50   BiDi ~ 0
DA_SYNC
$Comp
L power:GND #PWR0101
U 1 1 5D91AC47
P 2150 3150
F 0 "#PWR0101" H 2150 2900 50  0001 C CNN
F 1 "GND" H 2155 2977 50  0000 C CNN
F 2 "" H 2150 3150 50  0001 C CNN
F 3 "" H 2150 3150 50  0001 C CNN
	1    2150 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 3150 2050 3150
Wire Wire Line
	2050 3250 2050 3350
Connection ~ 2050 3350
Wire Wire Line
	2050 3550 2050 3450
Connection ~ 2050 3550
Connection ~ 2050 3450
NoConn ~ 2050 1950
NoConn ~ 2050 1850
Text GLabel 5350 2050 2    70   BiDi ~ 0
GND
$EndSCHEMATC
