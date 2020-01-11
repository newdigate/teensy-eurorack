EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 12
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 7900 4450 0    70   ~ 0
V_IN
Text Label 7900 4450 0    70   ~ 0
V_IN
Wire Wire Line
	5200 3750 5300 3750
Wire Wire Line
	4050 3750 5200 3750
Connection ~ 5200 3750
Wire Wire Line
	6200 4200 6200 3750
Wire Wire Line
	6200 3750 6100 3750
Wire Wire Line
	6200 3750 8650 3750
Connection ~ 6200 3750
Wire Wire Line
	5700 3750 5800 3750
Wire Wire Line
	8000 4050 7900 4050
Wire Wire Line
	8300 4200 8300 4050
Wire Wire Line
	8300 4050 8200 4050
Wire Wire Line
	8650 4050 8300 4050
Connection ~ 8300 4050
Wire Wire Line
	4950 4350 7500 4050
Wire Wire Line
	7600 4050 7500 4050
Wire Wire Line
	4050 4350 4950 4350
Connection ~ 7500 4050
Wire Wire Line
	4400 3950 4400 4150
Wire Wire Line
	4400 4150 4400 4500
Wire Wire Line
	4400 4500 5200 4500
Wire Wire Line
	5200 4500 6200 4500
Wire Wire Line
	6200 4500 7500 4500
Wire Wire Line
	7500 4500 7500 4450
Wire Wire Line
	7500 4500 8300 4500
Wire Wire Line
	5200 4150 5200 4500
Wire Wire Line
	4050 4550 5200 4550
Wire Wire Line
	5200 4550 5200 4500
Wire Wire Line
	4050 4150 4400 4150
Wire Wire Line
	4050 3950 4400 3950
Connection ~ 4400 4150
Connection ~ 6200 4500
Connection ~ 7500 4500
Connection ~ 5200 4500
$Comp
L Audio-in-eagle-import:R-US_R0805 R5
U 1 1 81A18C18
P 5200 3950
AR Path="/5D773153/5D79EBF1/81A18C18" Ref="R5"  Part="1" 
AR Path="/5D773153/5D7E3898/81A18C18" Ref="R9"  Part="1" 
AR Path="/5D773153/5D7EAAD7/81A18C18" Ref="R13"  Part="1" 
F 0 "R13" H 5050 4009 59  0000 L BNN
F 1 "100K" H 5050 3820 59  0000 L BNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 5200 3950 50  0001 C CNN
F 3 "" H 5200 3950 50  0001 C CNN
	1    5200 3950
	0    -1   -1   0   
$EndComp
$Comp
L Audio-in-eagle-import:R-US_R0805 R6
U 1 1 9C9FFFCA
P 5500 3750
AR Path="/5D773153/5D79EBF1/9C9FFFCA" Ref="R6"  Part="1" 
AR Path="/5D773153/5D7E3898/9C9FFFCA" Ref="R10"  Part="1" 
AR Path="/5D773153/5D7EAAD7/9C9FFFCA" Ref="R14"  Part="1" 
F 0 "R14" H 5350 3809 59  0000 L BNN
F 1 "150" H 5350 3620 59  0000 L BNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 5500 3750 50  0001 C CNN
F 3 "" H 5500 3750 50  0001 C CNN
	1    5500 3750
	1    0    0    -1  
$EndComp
$Comp
L Audio-in-eagle-import:C-EUC0805 C27
U 1 1 4294FF20
P 6000 3750
AR Path="/5D773153/5D79EBF1/4294FF20" Ref="C27"  Part="1" 
AR Path="/5D773153/5D7E3898/4294FF20" Ref="C31"  Part="1" 
AR Path="/5D773153/5D7EAAD7/4294FF20" Ref="C35"  Part="1" 
F 0 "C35" H 6060 3765 59  0000 L BNN
F 1 "10uF" H 6060 3565 59  0000 L BNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6000 3750 50  0001 C CNN
F 3 "" H 6000 3750 50  0001 C CNN
	1    6000 3750
	0    1    1    0   
$EndComp
$Comp
L Audio-in-eagle-import:C-EUC0805 C28
U 1 1 FB49CEF8
P 6200 4300
AR Path="/5D773153/5D79EBF1/FB49CEF8" Ref="C28"  Part="1" 
AR Path="/5D773153/5D7E3898/FB49CEF8" Ref="C32"  Part="1" 
AR Path="/5D773153/5D7EAAD7/FB49CEF8" Ref="C36"  Part="1" 
F 0 "C36" H 6260 4315 59  0000 L BNN
F 1 "2700pF" H 6260 4115 59  0000 L BNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 6200 4300 50  0001 C CNN
F 3 "" H 6200 4300 50  0001 C CNN
	1    6200 4300
	1    0    0    -1  
$EndComp
$Comp
L Audio-in-eagle-import:R-US_R0805 R7
U 1 1 B915E54E
P 7500 4250
AR Path="/5D773153/5D79EBF1/B915E54E" Ref="R7"  Part="1" 
AR Path="/5D773153/5D7E3898/B915E54E" Ref="R11"  Part="1" 
AR Path="/5D773153/5D7EAAD7/B915E54E" Ref="R15"  Part="1" 
F 0 "R15" H 7350 4309 59  0000 L BNN
F 1 "100K" H 7350 4120 59  0000 L BNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 7500 4250 50  0001 C CNN
F 3 "" H 7500 4250 50  0001 C CNN
	1    7500 4250
	0    -1   -1   0   
$EndComp
$Comp
L Audio-in-eagle-import:R-US_R0805 R8
U 1 1 3A24EE69
P 7800 4050
AR Path="/5D773153/5D79EBF1/3A24EE69" Ref="R8"  Part="1" 
AR Path="/5D773153/5D7E3898/3A24EE69" Ref="R12"  Part="1" 
AR Path="/5D773153/5D7EAAD7/3A24EE69" Ref="R16"  Part="1" 
F 0 "R16" H 7650 4109 59  0000 L BNN
F 1 "150" H 7650 3920 59  0000 L BNN
F 2 "Resistors_SMD:R_0805_HandSoldering" H 7800 4050 50  0001 C CNN
F 3 "" H 7800 4050 50  0001 C CNN
	1    7800 4050
	1    0    0    -1  
$EndComp
$Comp
L Audio-in-eagle-import:C-EUC0805 C29
U 1 1 03B11DE5
P 8100 4050
AR Path="/5D773153/5D79EBF1/03B11DE5" Ref="C29"  Part="1" 
AR Path="/5D773153/5D7E3898/03B11DE5" Ref="C33"  Part="1" 
AR Path="/5D773153/5D7EAAD7/03B11DE5" Ref="C37"  Part="1" 
F 0 "C37" H 8160 4065 59  0000 L BNN
F 1 "10uF" H 8160 3865 59  0000 L BNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 8100 4050 50  0001 C CNN
F 3 "" H 8100 4050 50  0001 C CNN
	1    8100 4050
	0    1    1    0   
$EndComp
$Comp
L Audio-in-eagle-import:C-EUC0805 C30
U 1 1 5D940E46
P 8300 4300
AR Path="/5D773153/5D79EBF1/5D940E46" Ref="C30"  Part="1" 
AR Path="/5D773153/5D7E3898/5D940E46" Ref="C34"  Part="1" 
AR Path="/5D773153/5D7EAAD7/5D940E46" Ref="C38"  Part="1" 
F 0 "C38" H 8360 4315 59  0000 L BNN
F 1 "2700pF" H 8360 4115 59  0000 L BNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 8300 4300 50  0001 C CNN
F 3 "" H 8300 4300 50  0001 C CNN
	1    8300 4300
	1    0    0    -1  
$EndComp
$Comp
L Audio-in-eagle-import:ACJS-MV-5 U$2
U 1 1 5D940E45
P 3750 4550
AR Path="/5D773153/5D79EBF1/5D940E45" Ref="U$2"  Part="1" 
AR Path="/5D773153/5D7E3898/5D940E45" Ref="U$3"  Part="1" 
AR Path="/5D773153/5D7EAAD7/5D940E45" Ref="U$4"  Part="1" 
F 0 "U$4" H 3750 4550 50  0001 C CNN
F 1 "ACJS-MV-5" H 3750 4550 50  0001 C CNN
F 2 "Mainboard:ACJS-MV5" H 3750 4550 50  0001 C CNN
F 3 "" H 3750 4550 50  0001 C CNN
	1    3750 4550
	1    0    0    -1  
$EndComp
Text HLabel 8650 3750 2    70   Input ~ 0
LEFT_OUT
Text HLabel 8650 4050 2    70   Input ~ 0
RIGHT_OUT
Text HLabel 8300 4500 3    70   Input ~ 0
AGND
Connection ~ 6200 4200
$EndSCHEMATC
