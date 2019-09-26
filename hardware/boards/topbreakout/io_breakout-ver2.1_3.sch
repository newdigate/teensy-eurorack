EESchema Schematic File Version 4
LIBS:TopBreakout-cache
EELAYER 30 0
EELAYER END
$Descr User 14469 9224
encoding utf-8
Sheet 4 8
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
	6500 3550 5800 3550
Wire Wire Line
	5800 3550 5800 3900
Wire Wire Line
	5800 3900 1400 3900
Text Label 5800 3550 0    70   ~ 0
USB_B_VCC
Text Label 2600 3900 0    70   ~ 0
USB_B_VCC
Text Label 1800 3900 0    70   ~ 0
USB_B_VCC
Wire Wire Line
	6500 3450 5700 3450
Wire Wire Line
	5700 3450 5700 3800
Wire Wire Line
	5700 3800 1400 3800
Text Label 5700 3450 0    70   ~ 0
USB_B_D-
Text Label 1800 3800 0    70   ~ 0
USB_B_D-
Wire Wire Line
	6500 3350 5600 3350
Wire Wire Line
	5600 3350 5600 3700
Wire Wire Line
	5600 3700 1400 3700
Text Label 5600 3350 0    70   ~ 0
USB_B_D+
Text Label 1800 3700 0    70   ~ 0
USB_B_D+
Text GLabel 6100 5600 0    70   BiDi ~ 0
GND
Text GLabel 6500 3250 0    70   BiDi ~ 0
GND
Wire Wire Line
	1400 6000 1800 6000
Text GLabel 1800 6000 2    70   BiDi ~ 0
GND
Wire Wire Line
	4900 5900 4900 4200
Wire Wire Line
	4900 4200 1400 4200
Text Label 4900 5900 0    70   ~ 0
USB_A_VCC
Text Label 1800 4200 0    70   ~ 0
USB_A_VCC
Wire Wire Line
	5100 5700 5100 4000
Wire Wire Line
	5100 4000 1400 4000
Text Label 5100 5700 0    70   ~ 0
USB_A_D+
Text Label 1800 4000 0    70   ~ 0
USB_A_D+
Wire Wire Line
	1400 3500 4750 3500
Text GLabel 4750 3500 2    70   BiDi ~ 0
TFT_CS
Wire Wire Line
	1400 3400 4300 3400
Text GLabel 4300 3400 2    70   BiDi ~ 0
TFT_DC
Wire Wire Line
	1400 3200 3100 3200
Text GLabel 3100 3200 2    70   BiDi ~ 0
SPI0_SCK
Wire Wire Line
	1400 3300 3700 3300
Text GLabel 3700 3300 2    70   BiDi ~ 0
SPI0_MOSI
Wire Wire Line
	1400 3100 2800 3100
Text GLabel 2800 3100 2    70   BiDi ~ 0
VIN
Wire Wire Line
	1400 4100 5000 4100
Wire Wire Line
	5000 4100 5000 5800
Text Label 5000 5800 0    70   ~ 0
USB_A_D-
Text Label 1800 4100 0    70   ~ 0
USB_A_D-
Wire Wire Line
	1700 1200 2700 1200
Text Label 1800 1200 0    70   ~ 0
SD_DAT1
Wire Wire Line
	1700 1300 2700 1300
Text Label 1800 1300 0    70   ~ 0
SD_DATAOUT
Wire Wire Line
	1700 1400 2700 1400
Text Label 1800 1400 0    70   ~ 0
SD_GND
Wire Wire Line
	2700 1500 1700 1500
Text Label 1800 1500 0    70   ~ 0
SD_CLK
Wire Wire Line
	1700 1700 2700 1700
Text Label 1800 1700 0    70   ~ 0
SD_DATAIN
Wire Wire Line
	2700 1600 1700 1600
Text Label 1800 1600 0    70   ~ 0
SD_VCC
Wire Wire Line
	1700 1800 2700 1800
Text Label 1800 1800 0    70   ~ 0
SD_CS
Wire Wire Line
	1700 1900 2700 1900
Text Label 1800 1900 0    70   ~ 0
SD_DAT2
Wire Wire Line
	1400 5900 2250 5900
Text GLabel 2250 5900 2    70   BiDi ~ 0
AD_CS
Wire Wire Line
	1400 5800 1650 5800
Text GLabel 1650 5800 2    70   BiDi ~ 0
AD_RESET
Wire Wire Line
	1400 5700 2250 5700
Text GLabel 2250 5700 2    70   BiDi ~ 0
AD_CONVST
Wire Wire Line
	1400 5600 1650 5600
Text GLabel 1650 5600 2    70   BiDi ~ 0
AD_BUSY
Wire Wire Line
	1400 5500 2200 5500
Text GLabel 2200 5500 2    70   BiDi ~ 0
SPI0_MISO
Wire Wire Line
	1400 5400 1650 5400
Text GLabel 1650 5400 2    70   BiDi ~ 0
DA_SYNC
Wire Wire Line
	1400 3600 2800 3600
Text GLabel 2800 3600 2    70   BiDi ~ 0
3V3
$Comp
L TopBreakout-eagle-import:WURTH_ELECTRONICS_61400413321WURTH_ELECTRONICS_61400413321_0_0 J1
U 1 1 92202B0B
P 7100 3350
AR Path="/92202B0B" Ref="J1"  Part="1" 
AR Path="/5D7F42FA/92202B0B" Ref="J1"  Part="1" 
F 0 "J1" H 7200 3250 85  0000 L TNN
F 1 "WURTH_ELECTRONICS_61400413321WURTH_ELECTRONICS_61400413321_0_0" H 7100 3350 50  0001 C CNN
F 2 "topbreakout:WURTH_ELECTRONICS_61400413321_0" H 7100 3350 50  0001 C CNN
F 3 "" H 7100 3350 50  0001 C CNN
	1    7100 3350
	-1   0    0    1   
$EndComp
$Comp
L TopBreakout-eagle-import:USB-A-S-X-X-VT J3
U 1 1 83A3164B
P 6100 5900
AR Path="/83A3164B" Ref="J3"  Part="1" 
AR Path="/5D7F42FA/83A3164B" Ref="J3"  Part="1" 
F 0 "J3" H 6300 6031 42  0000 L BNN
F 1 "USB-A-S-X-X-VT" H 6300 5120 42  0000 L BNN
F 2 "topbreakout:USB-A-S-X-X-VT" H 6100 5900 50  0001 C CNN
F 3 "" H 6100 5900 50  0001 C CNN
	1    6100 5900
	1    0    0    1   
$EndComp
$Comp
L TopBreakout-eagle-import:YAMAICHI_SD_CARD U$1
U 1 1 4D826FCC
P 1400 1400
AR Path="/4D826FCC" Ref="U$1"  Part="1" 
AR Path="/5D7F42FA/4D826FCC" Ref="U$1"  Part="1" 
F 0 "U$1" H 1300 2020 59  0000 L BNN
F 1 "YAMAICHI_SD_CARD" H 1300 700 59  0000 L BNN
F 2 "topbreakout:YAMAICHI_MICROSD_VERTICAL" H 1400 1400 50  0001 C CNN
F 3 "" H 1400 1400 50  0001 C CNN
	1    1400 1400
	-1   0    0    1   
$EndComp
$Comp
L TopBreakout-eagle-import:1734592-8 U$2
U 1 1 6197D135
P 2200 1800
AR Path="/6197D135" Ref="U$2"  Part="1" 
AR Path="/5D7F42FA/6197D135" Ref="U$2"  Part="1" 
F 0 "U$2" H 2200 1800 50  0001 C CNN
F 1 "1734592-8" H 2200 1800 50  0001 C CNN
F 2 "topbreakout:TE_1-1734592-8" H 2200 1800 50  0001 C CNN
F 3 "" H 2200 1800 50  0001 C CNN
	1    2200 1800
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6100 5900 4900 5900
Wire Wire Line
	5100 5700 6100 5700
Wire Wire Line
	5000 5800 6100 5800
Text GLabel 1800 5100 2    61   Input ~ 0
AVDD
Text GLabel 1800 5200 2    61   Input ~ 0
AVSS
Text GLabel 1400 4300 2    59   Input ~ 0
MIDI_RX
Text GLabel 1400 4400 2    59   Input ~ 0
MIDI_TX
$Comp
L TopBreakout-eagle-import:MOLEX_52892-3033MOLEX_52892-3033_0_0 J2
U 1 1 F1780596
P 800 6100
AR Path="/F1780596" Ref="J2"  Part="1" 
AR Path="/5D7F42FA/F1780596" Ref="J2"  Part="1" 
F 0 "J2" H 800 6000 85  0000 L TNN
F 1 "MOLEX_52892-3033MOLEX_52892-3033_0_0" H 800 6100 50  0001 C CNN
F 2 "topbreakout:MOLEX_52892-3033_0" H 800 6100 50  0001 C CNN
F 3 "" H 800 6100 50  0001 C CNN
	1    800  6100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1400 5300 1400 5200
Connection ~ 1400 5200
Wire Wire Line
	1400 5200 1800 5200
Wire Wire Line
	1800 5100 1400 5100
Wire Wire Line
	1400 5000 1400 5100
Connection ~ 1400 5100
Wire Wire Line
	1400 4900 1600 4900
Wire Wire Line
	1400 4800 1600 4800
Wire Wire Line
	1400 4700 1600 4700
Wire Wire Line
	1400 4600 1600 4600
Text GLabel 1600 4600 2    59   Input ~ 0
GATE_1
Text GLabel 1600 4700 2    59   Input ~ 0
GATE_2
Text GLabel 1600 4800 2    59   Input ~ 0
GATE_3
Text GLabel 1600 4900 2    59   Input ~ 0
GATE_4
$EndSCHEMATC
