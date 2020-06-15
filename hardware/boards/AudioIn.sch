EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 7 8
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Device:R R?
U 1 1 5F63C4CD
P 5550 5650
AR Path="/5F0BA363/5F63C4CD" Ref="R?"  Part="1" 
AR Path="/5F0DFE5E/5F63C4CD" Ref="R?"  Part="1" 
AR Path="/5F0E4EB0/5F63C4CD" Ref="R?"  Part="1" 
AR Path="/5F0EA26D/5F63C4CD" Ref="R?"  Part="1" 
AR Path="/5F635A1F/5F63C4CD" Ref="R28"  Part="1" 
AR Path="/5F6F72DC/5F63C4CD" Ref="R20"  Part="1" 
AR Path="/5F6FD5AE/5F63C4CD" Ref="R24"  Part="1" 
F 0 "R28" H 5620 5696 50  0000 L CNN
F 1 "100k" H 5620 5605 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5480 5650 50  0001 C CNN
F 3 "~" H 5550 5650 50  0001 C CNN
	1    5550 5650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F63C4DF
P 5700 5500
AR Path="/5F0BA363/5F63C4DF" Ref="R?"  Part="1" 
AR Path="/5F0DFE5E/5F63C4DF" Ref="R?"  Part="1" 
AR Path="/5F0E4EB0/5F63C4DF" Ref="R?"  Part="1" 
AR Path="/5F0EA26D/5F63C4DF" Ref="R?"  Part="1" 
AR Path="/5F635A1F/5F63C4DF" Ref="R30"  Part="1" 
AR Path="/5F6F72DC/5F63C4DF" Ref="R22"  Part="1" 
AR Path="/5F6FD5AE/5F63C4DF" Ref="R26"  Part="1" 
F 0 "R30" V 5493 5500 50  0000 C CNN
F 1 "150" V 5584 5500 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5630 5500 50  0001 C CNN
F 3 "~" H 5700 5500 50  0001 C CNN
	1    5700 5500
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5F63C4F5
P 6150 5650
AR Path="/5F63C4F5" Ref="C?"  Part="1" 
AR Path="/5F0BA363/5F63C4F5" Ref="C?"  Part="1" 
AR Path="/5F0DFE5E/5F63C4F5" Ref="C?"  Part="1" 
AR Path="/5F0E4EB0/5F63C4F5" Ref="C?"  Part="1" 
AR Path="/5F0EA26D/5F63C4F5" Ref="C?"  Part="1" 
AR Path="/5F635A1F/5F63C4F5" Ref="C67"  Part="1" 
AR Path="/5F6F72DC/5F63C4F5" Ref="C59"  Part="1" 
AR Path="/5F6FD5AE/5F63C4F5" Ref="C63"  Part="1" 
F 0 "C67" H 6265 5696 50  0000 L CNN
F 1 "2700p" H 6265 5605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6188 5500 50  0001 C CNN
F 3 "~" H 6150 5650 50  0001 C CNN
	1    6150 5650
	1    0    0    -1  
$EndComp
$Comp
L Connector:AudioJack3_SwitchTR J?
U 1 1 5F63C502
P 4300 5400
AR Path="/5F0BA363/5F63C502" Ref="J?"  Part="1" 
AR Path="/5F0DFE5E/5F63C502" Ref="J?"  Part="1" 
AR Path="/5F0E4EB0/5F63C502" Ref="J?"  Part="1" 
AR Path="/5F0EA26D/5F63C502" Ref="J?"  Part="1" 
AR Path="/5F635A1F/5F63C502" Ref="J9"  Part="1" 
AR Path="/5F6F72DC/5F63C502" Ref="J7"  Part="1" 
AR Path="/5F6FD5AE/5F63C502" Ref="J8"  Part="1" 
F 0 "J9" H 4020 5325 50  0000 R CNN
F 1 "AudioJack3_SwitchTR" H 4020 5234 50  0000 R CNN
F 2 "footprints:ACJS-MV5" H 4300 5400 50  0001 C CNN
F 3 "~" H 4300 5400 50  0001 C CNN
	1    4300 5400
	1    0    0    1   
$EndComp
Wire Wire Line
	4500 5400 5200 5400
Wire Wire Line
	4500 5300 4850 5300
Wire Wire Line
	4850 5300 4850 5200
Wire Wire Line
	4850 5100 4500 5100
Wire Wire Line
	4500 5200 4850 5200
Connection ~ 4850 5200
Wire Wire Line
	4850 5200 4850 5100
Text HLabel 6650 5500 2    50   Input ~ 0
LEFT
Text HLabel 6700 4650 2    50   Input ~ 0
RIGHT
Text HLabel 7500 5050 2    50   Input ~ 0
AGND
Text Label 4850 5100 0    50   ~ 0
AGND
Text Label 6150 5800 0    50   ~ 0
AGND
Wire Wire Line
	4500 5500 5550 5500
Connection ~ 5550 5500
$Comp
L Device:C C?
U 1 1 5F64573C
P 6000 5500
AR Path="/5F64573C" Ref="C?"  Part="1" 
AR Path="/5F0BA363/5F64573C" Ref="C?"  Part="1" 
AR Path="/5F0DFE5E/5F64573C" Ref="C?"  Part="1" 
AR Path="/5F0E4EB0/5F64573C" Ref="C?"  Part="1" 
AR Path="/5F0EA26D/5F64573C" Ref="C?"  Part="1" 
AR Path="/5F635A1F/5F64573C" Ref="C65"  Part="1" 
AR Path="/5F6F72DC/5F64573C" Ref="C57"  Part="1" 
AR Path="/5F6FD5AE/5F64573C" Ref="C61"  Part="1" 
F 0 "C65" H 6115 5546 50  0000 L CNN
F 1 "10u" H 6115 5455 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6038 5350 50  0001 C CNN
F 3 "~" H 6000 5500 50  0001 C CNN
	1    6000 5500
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6150 5500 6650 5500
Connection ~ 6150 5500
$Comp
L Device:R R?
U 1 1 5F65493E
P 5600 4800
AR Path="/5F0BA363/5F65493E" Ref="R?"  Part="1" 
AR Path="/5F0DFE5E/5F65493E" Ref="R?"  Part="1" 
AR Path="/5F0E4EB0/5F65493E" Ref="R?"  Part="1" 
AR Path="/5F0EA26D/5F65493E" Ref="R?"  Part="1" 
AR Path="/5F635A1F/5F65493E" Ref="R29"  Part="1" 
AR Path="/5F6F72DC/5F65493E" Ref="R21"  Part="1" 
AR Path="/5F6FD5AE/5F65493E" Ref="R25"  Part="1" 
F 0 "R29" H 5670 4846 50  0000 L CNN
F 1 "100k" H 5670 4755 50  0000 L CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5530 4800 50  0001 C CNN
F 3 "~" H 5600 4800 50  0001 C CNN
	1    5600 4800
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5F654944
P 5750 4650
AR Path="/5F0BA363/5F654944" Ref="R?"  Part="1" 
AR Path="/5F0DFE5E/5F654944" Ref="R?"  Part="1" 
AR Path="/5F0E4EB0/5F654944" Ref="R?"  Part="1" 
AR Path="/5F0EA26D/5F654944" Ref="R?"  Part="1" 
AR Path="/5F635A1F/5F654944" Ref="R31"  Part="1" 
AR Path="/5F6F72DC/5F654944" Ref="R23"  Part="1" 
AR Path="/5F6FD5AE/5F654944" Ref="R27"  Part="1" 
F 0 "R31" V 5543 4650 50  0000 C CNN
F 1 "150" V 5634 4650 50  0000 C CNN
F 2 "Resistor_SMD:R_0805_2012Metric" V 5680 4650 50  0001 C CNN
F 3 "~" H 5750 4650 50  0001 C CNN
	1    5750 4650
	0    1    1    0   
$EndComp
$Comp
L Device:C C?
U 1 1 5F65494A
P 6200 4800
AR Path="/5F65494A" Ref="C?"  Part="1" 
AR Path="/5F0BA363/5F65494A" Ref="C?"  Part="1" 
AR Path="/5F0DFE5E/5F65494A" Ref="C?"  Part="1" 
AR Path="/5F0E4EB0/5F65494A" Ref="C?"  Part="1" 
AR Path="/5F0EA26D/5F65494A" Ref="C?"  Part="1" 
AR Path="/5F635A1F/5F65494A" Ref="C68"  Part="1" 
AR Path="/5F6F72DC/5F65494A" Ref="C60"  Part="1" 
AR Path="/5F6FD5AE/5F65494A" Ref="C64"  Part="1" 
F 0 "C68" H 6315 4846 50  0000 L CNN
F 1 "2700p" H 6315 4755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6238 4650 50  0001 C CNN
F 3 "~" H 6200 4800 50  0001 C CNN
	1    6200 4800
	1    0    0    -1  
$EndComp
Text Label 6200 4950 0    50   ~ 0
AGND
$Comp
L Device:C C?
U 1 1 5F654953
P 6050 4650
AR Path="/5F654953" Ref="C?"  Part="1" 
AR Path="/5F0BA363/5F654953" Ref="C?"  Part="1" 
AR Path="/5F0DFE5E/5F654953" Ref="C?"  Part="1" 
AR Path="/5F0E4EB0/5F654953" Ref="C?"  Part="1" 
AR Path="/5F0EA26D/5F654953" Ref="C?"  Part="1" 
AR Path="/5F635A1F/5F654953" Ref="C66"  Part="1" 
AR Path="/5F6F72DC/5F654953" Ref="C58"  Part="1" 
AR Path="/5F6FD5AE/5F654953" Ref="C62"  Part="1" 
F 0 "C66" H 6165 4696 50  0000 L CNN
F 1 "10u" H 6165 4605 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 6088 4500 50  0001 C CNN
F 3 "~" H 6050 4650 50  0001 C CNN
	1    6050 4650
	0    -1   -1   0   
$EndComp
Connection ~ 6200 4650
Wire Wire Line
	5200 5400 5200 4650
Wire Wire Line
	5200 4650 5600 4650
Connection ~ 5600 4650
Wire Wire Line
	6200 4650 6700 4650
Wire Wire Line
	5550 5800 5550 5900
Wire Wire Line
	5550 5900 6150 5900
Wire Wire Line
	6150 5900 6150 5800
Wire Wire Line
	5600 4950 5600 5050
Wire Wire Line
	5600 5050 6200 5050
Wire Wire Line
	6200 4950 6200 5050
Connection ~ 6200 5050
Wire Wire Line
	6200 5050 7250 5050
Wire Wire Line
	6150 5900 7250 5900
Wire Wire Line
	7250 5900 7250 5050
Connection ~ 6150 5900
Connection ~ 7250 5050
Wire Wire Line
	7250 5050 7500 5050
$EndSCHEMATC
