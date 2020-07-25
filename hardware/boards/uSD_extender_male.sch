EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 2850 4300 0    59   ~ 0
PCB must be no thicker than 0.75mm
$Comp
L Connector_Generic:Conn_01x10 J1
U 1 1 5F1C893D
P 3300 3700
F 0 "J1" H 3218 2975 50  0000 C CNN
F 1 "Conn_01x10" H 3218 3066 50  0000 C CNN
F 2 "footprints:HFW8R-1STE1LF" H 3300 3700 50  0001 C CNN
F 3 "~" H 3300 3700 50  0001 C CNN
	1    3300 3700
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J2
U 1 1 5F1C13DD
P 4000 3700
F 0 "J2" H 4080 3692 50  0000 L CNN
F 1 "Conn_01x08" H 4080 3601 50  0000 L CNN
F 2 "footprints:MICRO-SDCARD" H 4000 3700 50  0001 C CNN
F 3 "~" H 4000 3700 50  0001 C CNN
	1    4000 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 4100 3800 4100
Wire Wire Line
	3500 4000 3800 4000
Wire Wire Line
	3500 3900 3800 3900
Wire Wire Line
	3500 3800 3800 3800
Wire Wire Line
	3500 3700 3800 3700
Wire Wire Line
	3500 3600 3800 3600
Wire Wire Line
	3500 3500 3800 3500
Wire Wire Line
	3500 3400 3800 3400
Text Label 3500 3400 0    50   ~ 0
DAT1
Text Label 3500 3500 0    50   ~ 0
DAT0
Text Label 3500 3600 0    50   ~ 0
CLK
Text Label 3500 3700 0    50   ~ 0
VCC
Text Label 3500 3800 0    50   ~ 0
GND
Text Label 3500 3900 0    50   ~ 0
CMD
Text Label 3500 4000 0    50   ~ 0
CD_DAT3
Text Label 3500 4100 0    50   ~ 0
DAT2
$Comp
L Connector_Generic:Conn_01x10 J3
U 1 1 5F1E1EB7
P 2550 3800
F 0 "J3" H 2468 3075 50  0000 C CNN
F 1 "Conn_01x10" H 2468 3166 50  0000 C CNN
F 2 "footprints:HFW8R-1STE1LF" H 2550 3800 50  0001 C CNN
F 3 "~" H 2550 3800 50  0001 C CNN
	1    2550 3800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	2750 3400 3500 3400
Connection ~ 3500 3400
Wire Wire Line
	2750 3500 3500 3500
Connection ~ 3500 3500
Wire Wire Line
	2750 3600 3500 3600
Connection ~ 3500 3600
Wire Wire Line
	2750 3700 3500 3700
Connection ~ 3500 3700
Wire Wire Line
	2750 3800 3500 3800
Connection ~ 3500 3800
Wire Wire Line
	2750 3900 3500 3900
Connection ~ 3500 3900
Wire Wire Line
	2750 4000 3500 4000
Connection ~ 3500 4000
Wire Wire Line
	2750 4100 3500 4100
Connection ~ 3500 4100
NoConn ~ 3500 3300
NoConn ~ 3500 3200
NoConn ~ 2750 4300
NoConn ~ 2750 4200
$EndSCHEMATC
