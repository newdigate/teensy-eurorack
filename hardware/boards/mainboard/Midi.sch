EESchema Schematic File Version 4
LIBS:Mainboard-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 13 13
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	7000 3700 7200 3700
Wire Wire Line
	7200 3700 7200 3900
Text GLabel 7000 3700 0    10   BiDi ~ 0
GND
Wire Wire Line
	5500 4700 5500 4600
Text Label 5500 4700 0    10   ~ 0
VCC
Wire Wire Line
	7000 3300 7100 3300
Wire Wire Line
	7100 3300 7100 2900
Wire Wire Line
	7100 2900 7100 2800
Wire Wire Line
	7300 3000 7300 2900
Wire Wire Line
	7300 2900 7100 2900
Connection ~ 7100 2900
Text Label 7000 3300 0    10   ~ 0
VCC
Wire Wire Line
	6000 3400 6000 3300
Wire Wire Line
	6000 3300 5900 3300
Wire Wire Line
	6000 3300 6100 3300
Connection ~ 6000 3300
Wire Wire Line
	6000 3600 6000 3700
Wire Wire Line
	6100 3700 6000 3700
Wire Wire Line
	6000 3700 4800 3700
Connection ~ 6000 3700
Text GLabel 4800 3700 0    70   BiDi ~ 0
MIDI_IN_PIN4
Wire Wire Line
	6000 5500 6500 5500
Text GLabel 6200 5500 2    70   BiDi ~ 0
TX
Text GLabel 6500 5500 2    70   BiDi ~ 0
TX
Wire Wire Line
	7000 3500 7300 3500
Wire Wire Line
	7300 3500 7700 3500
Wire Wire Line
	7300 3500 7300 3400
Connection ~ 7300 3500
Text GLabel 7700 3500 2    70   BiDi ~ 0
RX
Wire Wire Line
	5500 5300 5500 5100
Wire Wire Line
	5500 5300 4500 5300
Text GLabel 4500 5300 0    70   BiDi ~ 0
MIDI_OUT_PIN5
Wire Wire Line
	5600 5500 4500 5500
Text GLabel 4500 5500 0    70   BiDi ~ 0
MIDI_OUT_PIN4
Wire Wire Line
	5500 3300 4800 3300
Text GLabel 4800 3300 0    70   BiDi ~ 0
MIDI_IN_PIN5
$Comp
L Mainboard-eagle-import:DIODESMA D3
U 1 1 DA5D11AB
P 6000 3500
F 0 "D3" H 6100 3519 59  0000 L BNN
F 1 "DIODESMA" H 6100 3409 59  0000 L BNN
F 2 "Diodes_SMD:D_SMA_Handsoldering" H 6000 3500 50  0001 C CNN
F 3 "" H 6000 3500 50  0001 C CNN
	1    6000 3500
	0    -1   -1   0   
$EndComp
$Comp
L Mainboard-eagle-import:R-US_R0805 R34
U 1 1 35ADC47D
P 5700 3300
F 0 "R34" H 5550 3359 59  0000 L BNN
F 1 "220" H 5550 3170 59  0000 L BNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 5700 3300 50  0001 C CNN
F 3 "" H 5700 3300 50  0001 C CNN
	1    5700 3300
	1    0    0    -1  
$EndComp
$Comp
L Mainboard-eagle-import:GND #GND012
U 1 1 BFE1AC94
P 7200 4000
F 0 "#GND012" H 7200 4000 50  0001 C CNN
F 1 "GND" H 7100 3900 59  0000 L BNN
F 2 "" H 7200 4000 50  0001 C CNN
F 3 "" H 7200 4000 50  0001 C CNN
	1    7200 4000
	1    0    0    -1  
$EndComp
$Comp
L Mainboard-eagle-import:R-US_R0805 R36
U 1 1 E7324063
P 7300 3200
F 0 "R36" H 7150 3259 59  0000 L BNN
F 1 "220" H 7150 3070 59  0000 L BNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 7300 3200 50  0001 C CNN
F 3 "" H 7300 3200 50  0001 C CNN
	1    7300 3200
	0    -1   -1   0   
$EndComp
$Comp
L Mainboard-eagle-import:VCC #P+02
U 1 1 48DD0DF0
P 7100 2800
F 0 "#P+02" H 7100 2800 50  0001 C CNN
F 1 "VCC" H 7060 2940 59  0000 L BNN
F 2 "" H 7100 2800 50  0001 C CNN
F 3 "" H 7100 2800 50  0001 C CNN
	1    7100 2800
	1    0    0    -1  
$EndComp
$Comp
L Mainboard-eagle-import:R-US_R0805 R33
U 1 1 0D065E34
P 5500 4900
F 0 "R33" H 5350 4959 59  0000 L BNN
F 1 "220" H 5350 4770 59  0000 L BNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 5500 4900 50  0001 C CNN
F 3 "" H 5500 4900 50  0001 C CNN
	1    5500 4900
	0    -1   -1   0   
$EndComp
$Comp
L Mainboard-eagle-import:R-US_R0805 R35
U 1 1 87680542
P 5800 5500
F 0 "R35" H 5650 5559 59  0000 L BNN
F 1 "220" H 5650 5370 59  0000 L BNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 5800 5500 50  0001 C CNN
F 3 "" H 5800 5500 50  0001 C CNN
	1    5800 5500
	1    0    0    -1  
$EndComp
$Comp
L Mainboard-eagle-import:VCC #P+01
U 1 1 534F544F
P 5500 4600
F 0 "#P+01" H 5500 4600 50  0001 C CNN
F 1 "VCC" H 5460 4740 59  0000 L BNN
F 2 "" H 5500 4600 50  0001 C CNN
F 3 "" H 5500 4600 50  0001 C CNN
	1    5500 4600
	1    0    0    -1  
$EndComp
$Comp
L Mainboard-eagle-import:OPTO_DARL_6N138S U$5
U 1 1 6197D135
P 6500 3400
F 0 "U$5" H 6500 3400 50  0001 C CNN
F 1 "OPTO_DARL_6N138S" H 6360 2880 59  0000 L BNN
F 2 "Mainboard:8-SMD" H 6500 3400 50  0001 C CNN
F 3 "" H 6500 3400 50  0001 C CNN
	1    6500 3400
	1    0    0    -1  
$EndComp
Text Notes 5200 5500 0    59   ~ 0
PIN4
Text Notes 5200 5600 0    59   ~ 0
PIN5
$EndSCHEMATC
