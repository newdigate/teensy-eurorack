EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 8
Title "Teensy-eurorack V2.0"
Date ""
Rev "v2.0"
Comp "Moolet"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L teensy-eurorack:Teensy4.1_tht U4
U 1 1 5ECE9695
P 9050 3200
F 0 "U4" H 9050 5765 50  0000 C CNN
F 1 "Teensy4.1" H 9050 5674 50  0000 C CNN
F 2 "footprints:Teensy41_tht" H 8650 3600 50  0001 C CNN
F 3 "" H 8650 3600 50  0001 C CNN
	1    9050 3200
	1    0    0    -1  
$EndComp
Text Label 7550 1950 0    50   ~ 0
TDM_IN
Text Label 7550 1850 0    50   ~ 0
TDM_OUT
$Comp
L teensy-eurorack:CS42448 U1
U 1 1 5ED1263F
P 4550 3850
F 0 "U1" H 4500 3950 59  0000 C CNN
F 1 "CS42448" H 4500 3850 59  0000 C CNN
F 2 "Package_QFP:LQFP-64_10x10mm_P0.5mm" H 4550 3850 50  0001 C CNN
F 3 "" H 4550 3850 50  0001 C CNN
	1    4550 3850
	1    0    0    -1  
$EndComp
Text Label 10150 1350 0    50   ~ 0
MCLK
Text Label 10150 1550 0    50   ~ 0
BCLK
Wire Wire Line
	7550 1850 7950 1850
Wire Wire Line
	7550 1950 7950 1950
$Comp
L power:GND #PWR044
U 1 1 5ED8F475
P 7450 1050
F 0 "#PWR044" H 7450 800 50  0001 C CNN
F 1 "GND" V 7455 922 50  0000 R CNN
F 2 "" H 7450 1050 50  0001 C CNN
F 3 "" H 7450 1050 50  0001 C CNN
	1    7450 1050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR069
U 1 1 5ED90814
P 10700 2450
F 0 "#PWR069" H 10700 2200 50  0001 C CNN
F 1 "GND" H 10705 2277 50  0000 C CNN
F 2 "" H 10700 2450 50  0001 C CNN
F 3 "" H 10700 2450 50  0001 C CNN
	1    10700 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 2450 10700 2450
Wire Wire Line
	10150 1050 10150 950 
$Comp
L power:+5V #PWR063
U 1 1 5ED92A93
P 10150 950
F 0 "#PWR063" H 10150 800 50  0001 C CNN
F 1 "+5V" H 10165 1123 50  0000 C CNN
F 2 "" H 10150 950 50  0001 C CNN
F 3 "" H 10150 950 50  0001 C CNN
	1    10150 950 
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 5450 2600 5450
Wire Wire Line
	3050 5550 2600 5550
Text Label 2600 5450 0    50   ~ 0
SCL
Text Label 2600 5550 0    50   ~ 0
SDA
Text Label 10150 1850 0    50   ~ 0
SDA
Text Label 10150 1750 0    50   ~ 0
SCL
$Comp
L power:+3V3 #PWR068
U 1 1 5ED94BD4
P 10650 900
F 0 "#PWR068" H 10650 750 50  0001 C CNN
F 1 "+3V3" H 10665 1073 50  0000 C CNN
F 2 "" H 10650 900 50  0001 C CNN
F 3 "" H 10650 900 50  0001 C CNN
	1    10650 900 
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5ED95E8A
P 10650 1050
F 0 "R3" H 10720 1096 50  0000 L CNN
F 1 "2k" H 10720 1005 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 10580 1050 50  0001 C CNN
F 3 "~" H 10650 1050 50  0001 C CNN
	1    10650 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	10650 1200 10650 1350
Text Label 10650 1350 0    50   ~ 0
SCL
$Comp
L power:+3V3 #PWR072
U 1 1 5ED96E87
P 10950 900
F 0 "#PWR072" H 10950 750 50  0001 C CNN
F 1 "+3V3" H 10965 1073 50  0000 C CNN
F 2 "" H 10950 900 50  0001 C CNN
F 3 "" H 10950 900 50  0001 C CNN
	1    10950 900 
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5ED977DD
P 10950 1050
F 0 "R4" H 11020 1096 50  0000 L CNN
F 1 "2k" H 11020 1005 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 10880 1050 50  0001 C CNN
F 3 "~" H 10950 1050 50  0001 C CNN
	1    10950 1050
	1    0    0    -1  
$EndComp
Wire Wire Line
	10950 1200 10950 1350
$Comp
L power:GND #PWR019
U 1 1 5ED9AC5C
P 4350 6450
F 0 "#PWR019" H 4350 6200 50  0001 C CNN
F 1 "GND" H 4355 6277 50  0000 C CNN
F 2 "" H 4350 6450 50  0001 C CNN
F 3 "" H 4350 6450 50  0001 C CNN
	1    4350 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4250 6450 4350 6450
Connection ~ 4350 6450
Wire Wire Line
	4350 6450 4450 6450
$Comp
L Device:C C16
U 1 1 5ED9E660
P 6400 6550
F 0 "C16" H 6515 6596 50  0000 L CNN
F 1 "100u" H 6515 6505 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 6438 6400 50  0001 C CNN
F 3 "~" H 6400 6550 50  0001 C CNN
	1    6400 6550
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C15
U 1 1 5ED9EB12
P 6400 6100
F 0 "C15" H 6515 6146 50  0000 L CNN
F 1 "0.1u" H 6515 6055 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6438 5950 50  0001 C CNN
F 3 "~" H 6400 6100 50  0001 C CNN
	1    6400 6100
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C14
U 1 1 5ED9EFC4
P 6400 5700
F 0 "C14" H 6515 5746 50  0000 L CNN
F 1 "22u" H 6515 5655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6438 5550 50  0001 C CNN
F 3 "~" H 6400 5700 50  0001 C CNN
	1    6400 5700
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C12
U 1 1 5ED9F6BB
P 6400 4750
F 0 "C12" H 6515 4796 50  0000 L CNN
F 1 "4.7u" H 6515 4705 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6438 4600 50  0001 C CNN
F 3 "~" H 6400 4750 50  0001 C CNN
	1    6400 4750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6250 4750 6250 4950
$Comp
L Device:R R2
U 1 1 5EDB2FCD
P 4600 6450
F 0 "R2" V 4393 6450 50  0000 C CNN
F 1 "0" V 4484 6450 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 4530 6450 50  0001 C CNN
F 3 "~" H 4600 6450 50  0001 C CNN
	1    4600 6450
	0    1    1    0   
$EndComp
NoConn ~ 6050 5350
$Comp
L Device:R R1
U 1 1 5EDBA062
P 2900 5750
F 0 "R1" V 3000 5750 50  0000 C CNN
F 1 "2k" V 2900 5750 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 2830 5750 50  0001 C CNN
F 3 "~" H 2900 5750 50  0001 C CNN
	1    2900 5750
	0    1    1    0   
$EndComp
$Comp
L power:GND #PWR04
U 1 1 5EDBC014
P 2500 5650
F 0 "#PWR04" H 2500 5400 50  0001 C CNN
F 1 "GND" H 2505 5477 50  0000 C CNN
F 2 "" H 2500 5650 50  0001 C CNN
F 3 "" H 2500 5650 50  0001 C CNN
	1    2500 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 5650 3050 5650
$Comp
L power:GND #PWR06
U 1 1 5EDBDED5
P 2650 5750
F 0 "#PWR06" H 2650 5500 50  0001 C CNN
F 1 "GND" H 2655 5577 50  0000 C CNN
F 2 "" H 2650 5750 50  0001 C CNN
F 3 "" H 2650 5750 50  0001 C CNN
	1    2650 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2650 5750 2750 5750
NoConn ~ 3050 5950
$Comp
L power:+3V3 #PWR011
U 1 1 5EDC43A1
P 3050 6150
F 0 "#PWR011" H 3050 6000 50  0001 C CNN
F 1 "+3V3" H 2900 6250 50  0000 C CNN
F 2 "" H 3050 6150 50  0001 C CNN
F 3 "" H 3050 6150 50  0001 C CNN
	1    3050 6150
	1    0    0    -1  
$EndComp
Text Label 3050 5250 2    50   ~ 0
MCLK
Text Label 3050 4850 2    50   ~ 0
TDM_OUT
Text Label 3050 4950 2    50   ~ 0
BCLK
$Comp
L power:GND #PWR09
U 1 1 5EDCA7C8
P 2750 4550
F 0 "#PWR09" H 2750 4300 50  0001 C CNN
F 1 "GND" H 2755 4377 50  0000 C CNN
F 2 "" H 2750 4550 50  0001 C CNN
F 3 "" H 2750 4550 50  0001 C CNN
	1    2750 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 4550 3050 4550
Text Label 3050 4250 2    50   ~ 0
BCLK
Text Label 3050 4150 2    50   ~ 0
TDM_IN
NoConn ~ 3050 4050
NoConn ~ 3050 3950
NoConn ~ 3050 3750
NoConn ~ 3050 3650
$Comp
L power:GND #PWR010
U 1 1 5EDD0E44
P 2950 3550
F 0 "#PWR010" H 2950 3300 50  0001 C CNN
F 1 "GND" H 2955 3377 50  0000 C CNN
F 2 "" H 2950 3550 50  0001 C CNN
F 3 "" H 2950 3550 50  0001 C CNN
	1    2950 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 3550 3050 3550
$Comp
L Device:CP C3
U 1 1 5EDDCA3D
P 2200 3600
F 0 "C3" H 2318 3646 50  0000 L CNN
F 1 "4.7u" H 2318 3555 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 2238 3450 50  0001 C CNN
F 3 "~" H 2200 3600 50  0001 C CNN
	1    2200 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C2
U 1 1 5EDDF5B7
P 1800 3600
F 0 "C2" H 1918 3646 50  0000 L CNN
F 1 "4.7u" H 1918 3555 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 1838 3450 50  0001 C CNN
F 3 "~" H 1800 3600 50  0001 C CNN
	1    1800 3600
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C1
U 1 1 5EDE15CD
P 1400 3600
F 0 "C1" H 1518 3646 50  0000 L CNN
F 1 "4.7u" H 1518 3555 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 1438 3450 50  0001 C CNN
F 3 "~" H 1400 3600 50  0001 C CNN
	1    1400 3600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5EDE36F7
P 2200 3750
F 0 "#PWR03" H 2200 3500 50  0001 C CNN
F 1 "GND" H 2205 3577 50  0000 C CNN
F 2 "" H 2200 3750 50  0001 C CNN
F 3 "" H 2200 3750 50  0001 C CNN
	1    2200 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR02
U 1 1 5EDE3BF9
P 1800 3750
F 0 "#PWR02" H 1800 3500 50  0001 C CNN
F 1 "GND" H 1805 3577 50  0000 C CNN
F 2 "" H 1800 3750 50  0001 C CNN
F 3 "" H 1800 3750 50  0001 C CNN
	1    1800 3750
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR01
U 1 1 5EDE413F
P 1400 3750
F 0 "#PWR01" H 1400 3500 50  0001 C CNN
F 1 "GND" H 1405 3577 50  0000 C CNN
F 2 "" H 1400 3750 50  0001 C CNN
F 3 "" H 1400 3750 50  0001 C CNN
	1    1400 3750
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR016
U 1 1 5EDEF0A8
P 4050 1250
F 0 "#PWR016" H 4050 1100 50  0001 C CNN
F 1 "+3V3" H 4050 1500 50  0000 C CNN
F 2 "" H 4050 1250 50  0001 C CNN
F 3 "" H 4050 1250 50  0001 C CNN
	1    4050 1250
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR017
U 1 1 5EDEFC04
P 4150 1250
F 0 "#PWR017" H 4150 1100 50  0001 C CNN
F 1 "+3V3" H 4165 1423 50  0000 C CNN
F 2 "" H 4150 1250 50  0001 C CNN
F 3 "" H 4150 1250 50  0001 C CNN
	1    4150 1250
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR018
U 1 1 5EDEFED7
P 4350 1250
F 0 "#PWR018" H 4350 1100 50  0001 C CNN
F 1 "+3V3" H 4365 1423 50  0000 C CNN
F 2 "" H 4350 1250 50  0001 C CNN
F 3 "" H 4350 1250 50  0001 C CNN
	1    4350 1250
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR020
U 1 1 5EDF0206
P 4450 1250
F 0 "#PWR020" H 4450 1100 50  0001 C CNN
F 1 "+3V3" H 4450 1500 50  0000 C CNN
F 2 "" H 4450 1250 50  0001 C CNN
F 3 "" H 4450 1250 50  0001 C CNN
	1    4450 1250
	1    0    0    -1  
$EndComp
$Comp
L Device:C C9
U 1 1 5EDF2BAA
P 5400 1050
F 0 "C9" H 5515 1096 50  0000 L CNN
F 1 "0.01u" H 5515 1005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5438 900 50  0001 C CNN
F 3 "~" H 5400 1050 50  0001 C CNN
	1    5400 1050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C10
U 1 1 5EDF312B
P 5850 1050
F 0 "C10" H 5965 1096 50  0000 L CNN
F 1 "0.1u" H 5965 1005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5888 900 50  0001 C CNN
F 3 "~" H 5850 1050 50  0001 C CNN
	1    5850 1050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C11
U 1 1 5EDF346D
P 6250 1050
F 0 "C11" H 6365 1096 50  0000 L CNN
F 1 "0.1u" H 6365 1005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6288 900 50  0001 C CNN
F 3 "~" H 6250 1050 50  0001 C CNN
	1    6250 1050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C18
U 1 1 5EDF3ABD
P 6650 1050
F 0 "C18" H 6765 1096 50  0000 L CNN
F 1 "10u" H 6765 1005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6688 900 50  0001 C CNN
F 3 "~" H 6650 1050 50  0001 C CNN
	1    6650 1050
	1    0    0    -1  
$EndComp
$Comp
L Device:C C8
U 1 1 5EDF3E16
P 5000 1050
F 0 "C8" H 5115 1096 50  0000 L CNN
F 1 "0.01u" H 5115 1005 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 5038 900 50  0001 C CNN
F 3 "~" H 5000 1050 50  0001 C CNN
	1    5000 1050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR022
U 1 1 5EDF4F4B
P 5000 1200
F 0 "#PWR022" H 5000 950 50  0001 C CNN
F 1 "GND" H 5005 1027 50  0000 C CNN
F 2 "" H 5000 1200 50  0001 C CNN
F 3 "" H 5000 1200 50  0001 C CNN
	1    5000 1200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR023
U 1 1 5EDF5416
P 5400 1200
F 0 "#PWR023" H 5400 950 50  0001 C CNN
F 1 "GND" H 5405 1027 50  0000 C CNN
F 2 "" H 5400 1200 50  0001 C CNN
F 3 "" H 5400 1200 50  0001 C CNN
	1    5400 1200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR024
U 1 1 5EDF5727
P 5850 1200
F 0 "#PWR024" H 5850 950 50  0001 C CNN
F 1 "GND" H 5855 1027 50  0000 C CNN
F 2 "" H 5850 1200 50  0001 C CNN
F 3 "" H 5850 1200 50  0001 C CNN
	1    5850 1200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR025
U 1 1 5EDF5A9E
P 6250 1200
F 0 "#PWR025" H 6250 950 50  0001 C CNN
F 1 "GND" H 6255 1027 50  0000 C CNN
F 2 "" H 6250 1200 50  0001 C CNN
F 3 "" H 6250 1200 50  0001 C CNN
	1    6250 1200
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR026
U 1 1 5EDF5D9E
P 6650 1200
F 0 "#PWR026" H 6650 950 50  0001 C CNN
F 1 "GND" H 6655 1027 50  0000 C CNN
F 2 "" H 6650 1200 50  0001 C CNN
F 3 "" H 6650 1200 50  0001 C CNN
	1    6650 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 1250 4850 1250
Wire Wire Line
	4850 1250 4850 900 
Wire Wire Line
	4850 900  5000 900 
Wire Wire Line
	5000 900  5400 900 
Connection ~ 5000 900 
Wire Wire Line
	5850 900  5400 900 
Connection ~ 5400 900 
Connection ~ 5850 900 
Wire Wire Line
	5850 900  6250 900 
Connection ~ 6250 900 
Wire Wire Line
	6250 900  6650 900 
$Comp
L Device:Ferrite_Bead FB1
U 1 1 5EE05C7D
P 4850 750
F 0 "FB1" H 4987 796 50  0000 L CNN
F 1 "Ferrite_Bead" H 4987 705 50  0000 L CNN
F 2 "Inductor_SMD:L_0603_1608Metric" V 4780 750 50  0001 C CNN
F 3 "~" H 4850 750 50  0001 C CNN
	1    4850 750 
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR021
U 1 1 5EE09172
P 4850 600
F 0 "#PWR021" H 4850 450 50  0001 C CNN
F 1 "+5V" H 4865 773 50  0000 C CNN
F 2 "" H 4850 600 50  0001 C CNN
F 3 "" H 4850 600 50  0001 C CNN
	1    4850 600 
	1    0    0    -1  
$EndComp
Connection ~ 4850 900 
NoConn ~ 3050 3150
NoConn ~ 3050 2850
$Comp
L Device:C C5
U 1 1 5EE10715
P 2750 1000
F 0 "C5" H 2865 1046 50  0000 L CNN
F 1 "0.1u" H 2865 955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 2788 850 50  0001 C CNN
F 3 "~" H 2750 1000 50  0001 C CNN
	1    2750 1000
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR07
U 1 1 5EE10D09
P 2750 850
F 0 "#PWR07" H 2750 700 50  0001 C CNN
F 1 "+3V3" H 2750 1100 50  0000 C CNN
F 2 "" H 2750 850 50  0001 C CNN
F 3 "" H 2750 850 50  0001 C CNN
	1    2750 850 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5EE11273
P 2750 1150
F 0 "#PWR08" H 2750 900 50  0001 C CNN
F 1 "GND" H 2755 977 50  0000 C CNN
F 2 "" H 2750 1150 50  0001 C CNN
F 3 "" H 2750 1150 50  0001 C CNN
	1    2750 1150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6550 6100 6550 5700
$Comp
L power:+3V3 #PWR060
U 1 1 5F04E46D
P 10250 1250
F 0 "#PWR060" H 10250 1100 50  0001 C CNN
F 1 "+3V3" H 10400 1300 50  0000 C CNN
F 2 "" H 10250 1250 50  0001 C CNN
F 3 "" H 10250 1250 50  0001 C CNN
	1    10250 1250
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 1250 10250 1250
$Comp
L Device:C C6
U 1 1 5F05CD70
P 3200 1000
F 0 "C6" H 3315 1046 50  0000 L CNN
F 1 "0.01u" H 3315 955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3238 850 50  0001 C CNN
F 3 "~" H 3200 1000 50  0001 C CNN
	1    3200 1000
	1    0    0    -1  
$EndComp
$Comp
L Device:C C7
U 1 1 5F05D62D
P 3650 1000
F 0 "C7" H 3765 1046 50  0000 L CNN
F 1 "10u" H 3765 955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3688 850 50  0001 C CNN
F 3 "~" H 3650 1000 50  0001 C CNN
	1    3650 1000
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR012
U 1 1 5F05DDAA
P 3200 850
F 0 "#PWR012" H 3200 700 50  0001 C CNN
F 1 "+3V3" H 3200 1100 50  0000 C CNN
F 2 "" H 3200 850 50  0001 C CNN
F 3 "" H 3200 850 50  0001 C CNN
	1    3200 850 
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR014
U 1 1 5F05E253
P 3650 850
F 0 "#PWR014" H 3650 700 50  0001 C CNN
F 1 "+3V3" H 3650 1100 50  0000 C CNN
F 2 "" H 3650 850 50  0001 C CNN
F 3 "" H 3650 850 50  0001 C CNN
	1    3650 850 
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR013
U 1 1 5F05E855
P 3200 1150
F 0 "#PWR013" H 3200 900 50  0001 C CNN
F 1 "GND" H 3205 977 50  0000 C CNN
F 2 "" H 3200 1150 50  0001 C CNN
F 3 "" H 3200 1150 50  0001 C CNN
	1    3200 1150
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR015
U 1 1 5F05EB44
P 3650 1150
F 0 "#PWR015" H 3650 900 50  0001 C CNN
F 1 "GND" H 3655 977 50  0000 C CNN
F 2 "" H 3650 1150 50  0001 C CNN
F 3 "" H 3650 1150 50  0001 C CNN
	1    3650 1150
	1    0    0    -1  
$EndComp
$Sheet
S 6250 1500 750  400 
U 5F0BA363
F0 "AudioOut.sch" 50
F1 "AudioOut.sch" 50
F2 "LEFT" I L 6250 1550 49 
F3 "RIGHT" I L 6250 1850 49 
F4 "AGND" I R 7000 1700 49 
$EndSheet
$Sheet
S 6250 2100 750  400 
U 5F0DFE5E
F0 "sheet5F0DFE5C" 50
F1 "AudioOut.sch" 50
F2 "LEFT" I L 6250 2150 49 
F3 "RIGHT" I L 6250 2450 49 
F4 "AGND" I R 7000 2300 49 
$EndSheet
$Sheet
S 6250 3300 750  400 
U 5F0EA26D
F0 "sheet5F0EA26B" 50
F1 "AudioOut.sch" 50
F2 "LEFT" I L 6250 3350 49 
F3 "RIGHT" I L 6250 3650 49 
F4 "AGND" I R 7000 3500 49 
$EndSheet
NoConn ~ 6050 1650
NoConn ~ 6050 1950
NoConn ~ 6050 2250
NoConn ~ 6050 2550
NoConn ~ 6050 2850
NoConn ~ 6050 3150
NoConn ~ 6050 3450
NoConn ~ 6050 3750
Text Label 7000 1700 0    50   ~ 0
AGND
Text Label 7000 2300 0    50   ~ 0
AGND
Text Label 7000 2900 0    50   ~ 0
AGND
Text Label 7000 3500 0    50   ~ 0
AGND
Text Notes 8250 750  2    98   ~ 0
TEENSY 4.1
Wire Wire Line
	6550 5200 6550 4750
Text Label 6550 7000 0    50   ~ 0
AGND
Wire Wire Line
	6050 5650 6150 5650
Wire Wire Line
	6150 4950 6250 4950
$Comp
L Device:C C17
U 1 1 5ED9DFE4
P 6400 7000
F 0 "C17" H 6515 7046 50  0000 L CNN
F 1 "0.1u" H 6515 6955 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6438 6850 50  0001 C CNN
F 3 "~" H 6400 7000 50  0001 C CNN
	1    6400 7000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6150 4950 6150 5650
Wire Wire Line
	6250 5700 6250 5950
Connection ~ 6250 5950
Wire Wire Line
	6250 5950 6250 6100
Wire Wire Line
	6050 5950 6250 5950
Wire Wire Line
	6250 6550 6250 6750
Wire Wire Line
	6550 6550 6550 7000
Wire Wire Line
	6050 6150 6150 6150
Wire Wire Line
	6150 6750 6250 6750
Wire Wire Line
	6150 6150 6150 6750
Connection ~ 6250 6750
Wire Wire Line
	6250 6750 6250 7000
$Comp
L Device:C C13
U 1 1 5ED9F362
P 6400 5200
F 0 "C13" H 6515 5246 50  0000 L CNN
F 1 "0.1u" H 6515 5155 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6438 5050 50  0001 C CNN
F 3 "~" H 6400 5200 50  0001 C CNN
	1    6400 5200
	0    -1   -1   0   
$EndComp
Connection ~ 6250 4950
Wire Wire Line
	6250 4950 6250 5200
Wire Wire Line
	6550 5200 6550 5700
Connection ~ 6550 5200
Connection ~ 6550 5700
Wire Wire Line
	6550 6100 6550 6550
Connection ~ 6550 6100
Connection ~ 6550 6550
Text Label 5200 6450 0    50   ~ 0
AGND
Text Notes 1200 700  2    98   ~ 0
CS42448
$Comp
L power:GND #PWR05
U 1 1 5EDD3D54
P 2600 3750
F 0 "#PWR05" H 2600 3500 50  0001 C CNN
F 1 "GND" H 2605 3577 50  0000 C CNN
F 2 "" H 2600 3750 50  0001 C CNN
F 3 "" H 2600 3750 50  0001 C CNN
	1    2600 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C4
U 1 1 5EDD2C1E
P 2600 3600
F 0 "C4" H 2718 3646 50  0000 L CNN
F 1 "4.7u" H 2718 3555 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D5.0mm_P2.50mm" H 2638 3450 50  0001 C CNN
F 3 "~" H 2600 3600 50  0001 C CNN
	1    2600 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3050 1550 1300 1550
Wire Wire Line
	1400 3450 1400 1650
Wire Wire Line
	1300 1850 3050 1850
Wire Wire Line
	1400 1650 3050 1650
Wire Wire Line
	3050 1950 1800 1950
Wire Wire Line
	1800 1950 1800 3450
Wire Wire Line
	3050 2250 2200 2250
Wire Wire Line
	2200 2250 2200 3450
Wire Wire Line
	3050 2550 2600 2550
Wire Wire Line
	2600 2550 2600 3450
$Sheet
S 700  2100 600  450 
U 5F6F72DC
F0 "sheet5F6F72D7" 49
F1 "AudioIn.sch" 49
F2 "LEFT" I R 1300 2150 49 
F3 "RIGHT" I R 1300 2450 49 
F4 "AGND" I L 700 2350 49 
$EndSheet
Wire Wire Line
	3050 2150 1300 2150
Wire Wire Line
	1300 2450 3050 2450
$Sheet
S 700  2700 600  450 
U 5F6FD5AE
F0 "sheet5F6FD5A9" 49
F1 "AudioIn.sch" 49
F2 "LEFT" I R 1300 2750 49 
F3 "RIGHT" I R 1300 3050 49 
F4 "AGND" I L 700 2950 49 
$EndSheet
Wire Wire Line
	3050 2750 1300 2750
Wire Wire Line
	1300 3050 3050 3050
$Sheet
S 700  1500 600  450 
U 5F635A1F
F0 "AudioIn" 49
F1 "AudioIn.sch" 49
F2 "LEFT" I R 1300 1550 49 
F3 "RIGHT" I R 1300 1850 49 
F4 "AGND" I L 700 1750 49 
$EndSheet
Text Label 700  1750 2    50   ~ 0
AGND
Text Label 700  2350 2    50   ~ 0
AGND
Text Label 700  2950 2    50   ~ 0
AGND
$Sheet
S 6250 2700 750  400 
U 5F0E4EB0
F0 "sheet5F0E4EAE" 50
F1 "AudioOut.sch" 50
F2 "LEFT" I L 6250 2750 49 
F3 "RIGHT" I L 6250 3050 49 
F4 "AGND" I R 7000 2900 49 
$EndSheet
Text Label 7950 2250 2    49   ~ 0
TFT_MOSI
Text Label 10150 2350 0    49   ~ 0
TFT_SCK
Text Label 7950 1350 2    49   ~ 0
TFT_DC
Text Label 7950 1750 2    49   ~ 0
TFT_CS
Wire Wire Line
	4750 6450 4850 6450
Wire Wire Line
	3050 4550 3050 4650
Text Label 7950 2850 2    49   ~ 0
DAC_SCK
Text Label 7950 2750 2    49   ~ 0
DAC_SDIN
Text Label 10150 2750 0    49   ~ 0
ADC_MISO
Text Label 10150 3050 0    49   ~ 0
ADC_CS
Text Label 7950 1150 2    49   ~ 0
MIDI_RX
Text Label 7950 1250 2    49   ~ 0
MIDI_TX
Wire Wire Line
	7450 1050 7950 1050
Text Label 7950 1450 2    49   ~ 0
ADC_BUSY
Text Label 7950 1650 2    49   ~ 0
ADC_CONVST
Text Label 10150 2850 0    49   ~ 0
DAC_SYNC
$Comp
L Connector_Generic:Conn_02x08_Odd_Even J28
U 1 1 5EE93454
P 1350 7150
F 0 "J28" H 1400 7667 50  0000 C CNN
F 1 "Conn_02x08_Odd_Even" H 1400 7576 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x08_P2.54mm_Vertical" H 1350 7150 50  0001 C CNN
F 3 "~" H 1350 7150 50  0001 C CNN
	1    1350 7150
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR0101
U 1 1 5EE9CB27
P 1800 6850
F 0 "#PWR0101" H 1800 6950 50  0001 C CNN
F 1 "-12V" H 1815 7023 50  0000 C CNN
F 2 "" H 1800 6850 50  0001 C CNN
F 3 "" H 1800 6850 50  0001 C CNN
	1    1800 6850
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR0122
U 1 1 5EE9E974
P 900 6850
F 0 "#PWR0122" H 900 6950 50  0001 C CNN
F 1 "-12V" H 915 7023 50  0000 C CNN
F 2 "" H 900 6850 50  0001 C CNN
F 3 "" H 900 6850 50  0001 C CNN
	1    900  6850
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  6850 1150 6850
Wire Wire Line
	1650 6850 1800 6850
Wire Wire Line
	1150 7150 1150 7050
Wire Wire Line
	1150 7050 1150 6950
Connection ~ 1150 7050
Wire Wire Line
	1650 7150 1650 7050
Wire Wire Line
	1650 7050 1650 6950
Connection ~ 1650 7050
$Comp
L power:+12V #PWR0123
U 1 1 5EED4414
P 900 7250
F 0 "#PWR0123" H 900 7100 50  0001 C CNN
F 1 "+12V" H 915 7423 50  0000 C CNN
F 2 "" H 900 7250 50  0001 C CNN
F 3 "" H 900 7250 50  0001 C CNN
	1    900  7250
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR0124
U 1 1 5EED521B
P 1800 7250
F 0 "#PWR0124" H 1800 7100 50  0001 C CNN
F 1 "+12V" H 1815 7423 50  0000 C CNN
F 2 "" H 1800 7250 50  0001 C CNN
F 3 "" H 1800 7250 50  0001 C CNN
	1    1800 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	900  7250 1150 7250
Wire Wire Line
	1650 7250 1800 7250
Wire Wire Line
	1150 7350 1650 7350
$Comp
L Connector_Generic:Conn_01x02 J27
U 1 1 5EEEAE16
P 700 7550
F 0 "J27" V 572 7362 50  0000 R CNN
F 1 "Conn_01x02" V 663 7362 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 700 7550 50  0001 C CNN
F 3 "~" H 700 7550 50  0001 C CNN
	1    700  7550
	0    -1   1    0   
$EndComp
$Comp
L power:+5V #PWR0125
U 1 1 5EEF2D0F
P 700 7350
F 0 "#PWR0125" H 700 7200 50  0001 C CNN
F 1 "+5V" H 715 7523 50  0000 C CNN
F 2 "" H 700 7350 50  0001 C CNN
F 3 "" H 700 7350 50  0001 C CNN
	1    700  7350
	1    0    0    -1  
$EndComp
Wire Wire Line
	800  7350 1150 7350
Connection ~ 1150 7350
Wire Notes Line
	18600 16100 18650 16100
Text Label 10950 1350 0    50   ~ 0
SDA
Wire Wire Line
	7750 5550 8250 5550
Wire Wire Line
	7750 5650 8250 5650
Wire Wire Line
	8250 5750 7750 5750
Wire Wire Line
	7750 5850 8250 5850
Text Label 7750 5650 0    49   ~ 0
GND
Text Label 7750 6050 0    49   ~ 0
P1
Text Label 7750 6150 0    49   ~ 0
P2
Text Label 7750 5550 0    49   ~ 0
P3
$Comp
L Connector_Generic:Conn_01x08 JM3
U 1 1 5EF60DE4
P 7550 5950
F 0 "JM3" H 7468 5325 50  0000 C CNN
F 1 "Conn_01x08" H 7468 5416 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 7550 5950 50  0001 C CNN
F 3 "~" H 7550 5950 50  0001 C CNN
	1    7550 5950
	-1   0    0    1   
$EndComp
Text Label 8850 6150 0    49   ~ 0
P4
Wire Wire Line
	8850 5850 9350 5850
Wire Wire Line
	9350 5750 8850 5750
Wire Wire Line
	8850 5650 9350 5650
Wire Wire Line
	8850 5550 9350 5550
$Comp
L Connector_Generic:Conn_01x08 JM4
U 1 1 5F025765
P 8650 5950
F 0 "JM4" H 8568 5325 50  0000 C CNN
F 1 "Conn_01x08" H 8568 5416 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 8650 5950 50  0001 C CNN
F 3 "~" H 8650 5950 50  0001 C CNN
	1    8650 5950
	-1   0    0    1   
$EndComp
Wire Wire Line
	7750 5950 8250 5950
Wire Wire Line
	7750 6050 8250 6050
Wire Wire Line
	8250 6150 7750 6150
Wire Wire Line
	8850 5950 9350 5950
Wire Wire Line
	8850 6050 9350 6050
Wire Wire Line
	8850 6150 9350 6150
Wire Wire Line
	8850 6250 9350 6250
Text Label 8850 6050 0    49   ~ 0
ES1
Text Label 8850 5750 0    49   ~ 0
ES2
Text Label 7750 5750 0    49   ~ 0
ES3
Text Label 8850 5850 0    49   ~ 0
E1A
Text Label 8850 5950 0    49   ~ 0
E1B
Text Label 8850 5550 0    49   ~ 0
E2A
Text Label 8850 5650 0    49   ~ 0
E2B
Text Label 7750 5850 0    49   ~ 0
E3A
Text Label 7750 5950 0    49   ~ 0
E3B
$Comp
L power:+3V3 #PWR093
U 1 1 5F1055C7
P 8350 6250
F 0 "#PWR093" H 8350 6100 50  0001 C CNN
F 1 "+3V3" H 8365 6423 50  0000 C CNN
F 2 "" H 8350 6250 50  0001 C CNN
F 3 "" H 8350 6250 50  0001 C CNN
	1    8350 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	8350 6250 8850 6250
Connection ~ 8850 6250
Wire Wire Line
	7750 6250 8250 6250
Text Label 10150 2250 0    49   ~ 0
P1
Text Label 10150 2150 0    49   ~ 0
P2
Text Label 10150 2550 0    49   ~ 0
P3
Text Label 10150 1450 0    49   ~ 0
P4
$Comp
L power:GND #PWR0155
U 1 1 5F135286
P 10350 900
F 0 "#PWR0155" H 10350 650 50  0001 C CNN
F 1 "GND" H 10355 727 50  0000 C CNN
F 2 "" H 10350 900 50  0001 C CNN
F 3 "" H 10350 900 50  0001 C CNN
	1    10350 900 
	1    0    0    -1  
$EndComp
Text Label 7950 1550 2    49   ~ 0
ES1
Text Label 7950 2050 2    49   ~ 0
ES2
Text Label 7950 2150 2    49   ~ 0
ES3
Text Label 7950 2350 2    49   ~ 0
E1A
Text Label 7950 2550 2    49   ~ 0
E1B
Text Label 7950 2650 2    49   ~ 0
E2A
Text Label 7950 2950 2    49   ~ 0
E2B
Text Label 7950 3050 2    49   ~ 0
E3A
Text Label 7950 3150 2    49   ~ 0
E3B
Connection ~ 4850 6450
Wire Wire Line
	4850 6450 5200 6450
Wire Wire Line
	6050 1550 6250 1550
Wire Wire Line
	6050 1850 6250 1850
Wire Wire Line
	6050 2150 6250 2150
Wire Wire Line
	6050 2450 6250 2450
Wire Wire Line
	6050 2750 6250 2750
Wire Wire Line
	6050 3050 6250 3050
Wire Wire Line
	6050 3350 6250 3350
Wire Wire Line
	6050 3650 6250 3650
Wire Notes Line
	16050 6400 16050 6550
$Comp
L Connector_Generic:Conn_01x04 JMUSBA1
U 1 1 5F0FE33E
P 10550 5650
F 0 "JMUSBA1" H 10468 5225 50  0000 C CNN
F 1 "Conn_01x04" H 10468 5316 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 10550 5650 50  0001 C CNN
F 3 "~" H 10550 5650 50  0001 C CNN
	1    10550 5650
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x04 JMUSBB1
U 1 1 5F17FFC9
P 10550 6300
F 0 "JMUSBB1" H 10468 5875 50  0000 C CNN
F 1 "Conn_01x04" H 10468 5966 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 10550 6300 50  0001 C CNN
F 3 "~" H 10550 6300 50  0001 C CNN
	1    10550 6300
	-1   0    0    1   
$EndComp
Wire Wire Line
	10750 6400 10950 6400
Wire Wire Line
	10050 5450 10750 5450
Wire Wire Line
	10050 5550 10750 5550
Wire Wire Line
	10050 5650 10750 5650
Wire Wire Line
	10050 5750 10750 5750
Wire Wire Line
	10050 6100 10750 6100
Wire Wire Line
	10050 6200 10750 6200
Wire Wire Line
	10050 6300 10750 6300
Wire Wire Line
	10050 6400 10750 6400
Connection ~ 10750 6400
$Comp
L Connector_Generic:Conn_01x04 JUSBB1
U 1 1 5F22310C
P 9850 6300
F 0 "JUSBB1" H 9768 5875 50  0000 C CNN
F 1 "Conn_01x04" H 9768 5966 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9850 6300 50  0001 C CNN
F 3 "~" H 9850 6300 50  0001 C CNN
	1    9850 6300
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x04 JUSBA1
U 1 1 5F222B18
P 9850 5650
F 0 "JUSBA1" H 9768 5225 50  0000 C CNN
F 1 "Conn_01x04" H 9768 5316 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9850 5650 50  0001 C CNN
F 3 "~" H 9850 5650 50  0001 C CNN
	1    9850 5650
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR0156
U 1 1 5F589967
P 10950 6400
F 0 "#PWR0156" H 10950 6150 50  0001 C CNN
F 1 "GND" H 10955 6227 50  0001 C CNN
F 2 "" H 10950 6400 50  0001 C CNN
F 3 "" H 10950 6400 50  0001 C CNN
	1    10950 6400
	-1   0    0    -1  
$EndComp
NoConn ~ 10150 3350
NoConn ~ 7950 3350
NoConn ~ 7950 2450
Connection ~ 3050 4650
Wire Wire Line
	3050 4650 3050 4750
NoConn ~ 1150 7550
NoConn ~ 1150 7450
NoConn ~ 1650 7450
NoConn ~ 1650 7550
$Comp
L power:GND #PWR0102
U 1 1 5F061C98
P 1050 6950
F 0 "#PWR0102" H 1050 6700 50  0001 C CNN
F 1 "GND" H 1055 6777 50  0000 C CNN
F 2 "" H 1050 6950 50  0001 C CNN
F 3 "" H 1050 6950 50  0001 C CNN
	1    1050 6950
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0103
U 1 1 5F0623CA
P 1800 6950
F 0 "#PWR0103" H 1800 6700 50  0001 C CNN
F 1 "GND" H 1805 6777 50  0000 C CNN
F 2 "" H 1800 6950 50  0001 C CNN
F 3 "" H 1800 6950 50  0001 C CNN
	1    1800 6950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1050 6950 1150 6950
Connection ~ 1150 6950
Wire Wire Line
	1800 6950 1650 6950
Connection ~ 1650 6950
Connection ~ 7750 6250
Wire Wire Line
	7750 4050 8800 4050
Wire Wire Line
	7350 6250 7750 6250
$Comp
L power:+3V3 #PWR092
U 1 1 5F05AB81
P 7350 6250
F 0 "#PWR092" H 7350 6100 50  0001 C CNN
F 1 "+3V3" H 7365 6423 50  0000 C CNN
F 2 "" H 7350 6250 50  0001 C CNN
F 3 "" H 7350 6250 50  0001 C CNN
	1    7350 6250
	1    0    0    -1  
$EndComp
Connection ~ 7750 4850
Wire Wire Line
	7750 4850 8700 4850
Connection ~ 7750 4050
Wire Wire Line
	7400 4050 7750 4050
Wire Wire Line
	8700 4950 7750 4950
Wire Wire Line
	7750 5050 8700 5050
Wire Wire Line
	7750 5150 8700 5150
$Comp
L Connector_Generic:Conn_01x14 JM1
U 1 1 5EF72A68
P 7550 4550
F 0 "JM1" H 7468 3625 50  0000 C CNN
F 1 "Conn_01x14" H 7468 3716 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x14_P2.54mm_Vertical" H 7550 4550 50  0001 C CNN
F 3 "~" H 7550 4550 50  0001 C CNN
	1    7550 4550
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x14 JM2
U 1 1 5EF6CCE4
P 9250 4550
F 0 "JM2" H 9168 3625 50  0000 C CNN
F 1 "CONN_01x14" H 9168 3716 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x14_P2.54mm_Vertical" H 9250 4550 50  0001 C CNN
F 3 "~" H 9250 4550 50  0001 C CNN
	1    9250 4550
	-1   0    0    1   
$EndComp
$Comp
L power:+3V3 #PWR089
U 1 1 5F089EA5
P 8800 4050
F 0 "#PWR089" H 8800 3900 50  0001 C CNN
F 1 "+3V3" H 8815 4223 50  0000 C CNN
F 2 "" H 8800 4050 50  0001 C CNN
F 3 "" H 8800 4050 50  0001 C CNN
	1    8800 4050
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR088
U 1 1 5F089478
P 7400 4050
F 0 "#PWR088" H 7400 3900 50  0001 C CNN
F 1 "+3V3" H 7415 4223 50  0000 C CNN
F 2 "" H 7400 4050 50  0001 C CNN
F 3 "" H 7400 4050 50  0001 C CNN
	1    7400 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 4850 7750 4850
$Comp
L power:+3V3 #PWR083
U 1 1 5F063899
P 7350 4850
F 0 "#PWR083" H 7350 4700 50  0001 C CNN
F 1 "+3V3" H 7365 5023 50  0000 C CNN
F 2 "" H 7350 4850 50  0001 C CNN
F 3 "" H 7350 4850 50  0001 C CNN
	1    7350 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 4450 8700 4450
Connection ~ 8250 4450
$Comp
L power:+5V #PWR0154
U 1 1 5F032E74
P 8250 4450
F 0 "#PWR0154" H 8250 4300 50  0001 C CNN
F 1 "+5V" H 8265 4623 50  0000 C CNN
F 2 "" H 8250 4450 50  0001 C CNN
F 3 "" H 8250 4450 50  0001 C CNN
	1    8250 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	9450 5050 10850 5050
Text Label 9450 4650 0    49   ~ 0
DAC_SYNC
Wire Wire Line
	8400 3950 8700 3950
Connection ~ 8400 3950
Wire Wire Line
	8400 3800 8400 3950
Wire Wire Line
	8100 3850 8700 3850
Connection ~ 8100 3850
Wire Wire Line
	8100 3800 8100 3850
$Comp
L power:+12V #PWR0153
U 1 1 5F0A0CCB
P 8400 3800
F 0 "#PWR0153" H 8400 3650 50  0001 C CNN
F 1 "+12V" H 8415 3973 50  0000 C CNN
F 2 "" H 8400 3800 50  0001 C CNN
F 3 "" H 8400 3800 50  0001 C CNN
	1    8400 3800
	1    0    0    -1  
$EndComp
$Comp
L power:-12V #PWR0150
U 1 1 5F09F1EE
P 8100 3800
F 0 "#PWR0150" H 8100 3900 50  0001 C CNN
F 1 "-12V" H 8115 3973 50  0000 C CNN
F 2 "" H 8100 3800 50  0001 C CNN
F 3 "" H 8100 3800 50  0001 C CNN
	1    8100 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 4350 8700 4350
Wire Wire Line
	7750 4450 8250 4450
Wire Wire Line
	7750 4250 8700 4250
Wire Wire Line
	9450 4250 10850 4250
Wire Wire Line
	9950 4450 10850 4450
Connection ~ 9950 4450
Wire Wire Line
	9450 4850 10850 4850
Text Label 7750 4250 0    49   ~ 0
DAC_SCK
Text Label 7750 4150 0    49   ~ 0
DAC_SDIN
Wire Wire Line
	9450 4750 10850 4750
Text Label 7750 4350 0    49   ~ 0
ADC_MISO
Text Label 9450 4850 0    49   ~ 0
ADC_CS
Text Label 9450 5050 0    49   ~ 0
ADC_CONVST
Text Label 9450 4750 0    49   ~ 0
ADC_BUSY
Text Label 7750 4950 0    49   ~ 0
MIDI_RX
Text Label 7750 5050 0    49   ~ 0
MIDI_TX
Wire Wire Line
	7750 4150 8700 4150
Wire Wire Line
	7750 3950 8400 3950
Wire Wire Line
	10850 4650 9450 4650
Wire Wire Line
	9450 4450 9950 4450
Wire Wire Line
	9450 4350 10850 4350
Wire Wire Line
	9450 4150 10850 4150
Wire Wire Line
	9450 4050 10850 4050
$Comp
L power:+5V #PWR0143
U 1 1 5F2119BB
P 9950 4450
F 0 "#PWR0143" H 9950 4300 50  0001 C CNN
F 1 "+5V" H 9965 4623 50  0000 C CNN
F 2 "" H 9950 4450 50  0001 C CNN
F 3 "" H 9950 4450 50  0001 C CNN
	1    9950 4450
	1    0    0    -1  
$EndComp
Text Label 8700 5150 2    49   ~ 0
GND
Text Label 9450 5150 0    49   ~ 0
GND
Text Label 9450 4250 0    49   ~ 0
TFT_MOSI
Text Label 9450 4350 0    49   ~ 0
TFT_SCK
Text Label 9450 4050 0    49   ~ 0
TFT_CS
Text Label 9450 4150 0    49   ~ 0
TFT_DC
Wire Wire Line
	7750 3850 8100 3850
Connection ~ 3050 4550
Connection ~ 4450 6450
Connection ~ 4750 6450
Connection ~ 4850 1250
Wire Notes Line
	500  6300 2350 6300
Wire Notes Line
	2350 6300 2350 7800
Wire Notes Line
	7250 500  7250 6500
Wire Notes Line
	7250 3500 11200 3500
Text Label 10150 1650 0    49   ~ 0
LRCLK
Text Label 3050 5050 2    49   ~ 0
LRCLK
Text Label 3050 4350 2    49   ~ 0
LRCLK
NoConn ~ 10150 3250
Wire Wire Line
	9450 4950 10900 4950
Wire Wire Line
	9450 5150 10900 5150
Text Label 9450 4950 0    49   ~ 0
ADC_RANGE
Text Label 10150 2950 0    49   ~ 0
ADC_RANGE
$Comp
L power:GND #PWR0104
U 1 1 5FA5C96B
P 10950 4550
F 0 "#PWR0104" H 10950 4300 50  0001 C CNN
F 1 "GND" H 10955 4377 50  0001 C CNN
F 2 "" H 10950 4550 50  0001 C CNN
F 3 "" H 10950 4550 50  0001 C CNN
	1    10950 4550
	-1   0    0    -1  
$EndComp
Wire Wire Line
	9450 4550 10950 4550
$Comp
L power:GND #PWR0105
U 1 1 5FA650F8
P 8800 4750
F 0 "#PWR0105" H 8800 4500 50  0001 C CNN
F 1 "GND" H 8805 4577 50  0001 C CNN
F 2 "" H 8800 4750 50  0001 C CNN
F 3 "" H 8800 4750 50  0001 C CNN
	1    8800 4750
	-1   0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 5FA85CAE
P 8800 4550
F 0 "#PWR0106" H 8800 4300 50  0001 C CNN
F 1 "GND" H 8805 4377 50  0001 C CNN
F 2 "" H 8800 4550 50  0001 C CNN
F 3 "" H 8800 4550 50  0001 C CNN
	1    8800 4550
	-1   0    0    -1  
$EndComp
Text Label 7750 4650 0    49   ~ 0
ADC_RESET
Text Label 10150 3150 0    49   ~ 0
ADC_RESET
Wire Wire Line
	7750 4550 8800 4550
Wire Wire Line
	7750 4750 8800 4750
NoConn ~ 9450 3950
NoConn ~ 9450 3850
NoConn ~ 7950 3250
$Comp
L Connector_Generic:Conn_01x03 JDAISYM1
U 1 1 60113125
P 10700 2050
F 0 "JDAISYM1" H 10600 1750 50  0000 C CNN
F 1 "Conn_01x03" H 10550 1850 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 10700 2050 50  0001 C CNN
F 3 "~" H 10700 2050 50  0001 C CNN
	1    10700 2050
	1    0    0    1   
$EndComp
Wire Wire Line
	10150 1150 10200 1150
Wire Wire Line
	10200 1150 10200 900 
Wire Wire Line
	10200 900  10350 900 
Wire Wire Line
	10150 1950 10500 1950
Wire Wire Line
	10150 2050 10500 2050
Text Label 10200 1950 0    49   ~ 0
D_TX
Text Label 10200 2050 0    49   ~ 0
D_RX
$Comp
L power:GND #PWR0107
U 1 1 6015AF41
P 10500 2150
F 0 "#PWR0107" H 10500 1900 50  0001 C CNN
F 1 "GND" H 10505 1977 50  0000 C CNN
F 2 "" H 10500 2150 50  0001 C CNN
F 3 "" H 10500 2150 50  0001 C CNN
	1    10500 2150
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 JDAISYS1
U 1 1 60162E8E
P 11050 1950
F 0 "JDAISYS1" H 10968 1525 50  0000 C CNN
F 1 "Conn_01x03" H 10968 1616 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 11050 1950 50  0001 C CNN
F 3 "~" H 11050 1950 50  0001 C CNN
	1    11050 1950
	1    0    0    -1  
$EndComp
Connection ~ 10500 1950
Connection ~ 10500 2050
$Comp
L power:GND #PWR0108
U 1 1 60189B9D
P 11150 1850
F 0 "#PWR0108" H 11150 1600 50  0001 C CNN
F 1 "GND" H 11155 1677 50  0000 C CNN
F 2 "" H 11150 1850 50  0001 C CNN
F 3 "" H 11150 1850 50  0001 C CNN
	1    11150 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	10500 1950 10850 1950
Wire Wire Line
	10500 2050 10850 2050
Wire Wire Line
	10850 1850 11150 1850
Text Label 10150 2650 0    49   ~ 0
LRCLK
$EndSCHEMATC
