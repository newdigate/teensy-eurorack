EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 10 13
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
	5300 3600 6200 3600
Wire Wire Line
	6200 3600 6200 3800
Wire Wire Line
	6200 3800 6800 3800
Wire Wire Line
	5300 4400 6800 4400
Text GLabel 5300 4400 0    70   BiDi ~ 0
TFT_CS
Wire Wire Line
	5300 4300 6800 4300
Text GLabel 5300 4300 0    70   BiDi ~ 0
TFT_DC
Wire Wire Line
	5300 4000 6800 4000
Text GLabel 5300 4000 0    70   BiDi ~ 0
SPI0_SCK
Wire Wire Line
	5300 4100 6800 4100
Text GLabel 5300 4100 0    70   BiDi ~ 0
SPI0_MOSI
Wire Wire Line
	6800 3900 4700 3900
Wire Wire Line
	6800 4500 4700 4500
Text GLabel 4700 3900 0    70   BiDi ~ 0
VIN
$Comp
L TopBreakout-eagle-import:GND #GND?
U 1 1 5E09D776
P 5300 3700
AR Path="/5E09D776" Ref="#GND?"  Part="1" 
AR Path="/5D7F4364/5E09D776" Ref="#GND028"  Part="1" 
F 0 "#GND028" H 5300 3700 50  0001 C CNN
F 1 "GND" H 5200 3600 59  0000 L BNN
F 2 "" H 5300 3700 50  0001 C CNN
F 3 "" H 5300 3700 50  0001 C CNN
	1    5300 3700
	1    0    0    -1  
$EndComp
$Comp
L TopBreakout-eagle-import:ST7735_1.4 J?
U 1 1 5FA14143
P 7000 4100
AR Path="/5FA14143" Ref="J?"  Part="1" 
AR Path="/5D7F4364/5FA14143" Ref="J59"  Part="1" 
F 0 "J59" H 6800 4620 70  0000 L BNN
F 1 "ST7735_1.4" H 7000 4100 50  0001 C CNN
F 2 "topbreakout:ST7735" H 7000 4100 50  0001 C CNN
F 3 "" H 7000 4100 50  0001 C CNN
	1    7000 4100
	-1   0    0    1   
$EndComp
Text Notes 6000 3600 0    59   ~ 0
TFT
Wire Wire Line
	6800 4200 4700 4200
Text GLabel 4700 4200 0    70   BiDi ~ 0
VIN
Text GLabel 4700 4500 0    70   BiDi ~ 0
VIN
$EndSCHEMATC
