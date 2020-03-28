EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text GLabel 2550 2050 2    50   UnSpc ~ 0
PIN_01
Wire Wire Line
	2550 2050 2250 2050
Text GLabel 2550 2150 2    50   UnSpc ~ 0
PIN_02
Text GLabel 2550 2250 2    50   UnSpc ~ 0
PIN_03
Text GLabel 2550 2600 2    50   UnSpc ~ 0
PIN_04
Text GLabel 2550 2700 2    50   UnSpc ~ 0
PIN_05
Text GLabel 2550 2800 2    50   UnSpc ~ 0
PIN_06
Wire Wire Line
	2250 2150 2550 2150
Wire Wire Line
	2550 2250 2250 2250
Wire Wire Line
	2250 2600 2550 2600
Wire Wire Line
	2550 2700 2250 2700
Wire Wire Line
	2250 2800 2550 2800
Text GLabel 2550 3150 2    50   UnSpc ~ 0
PIN_07
Wire Wire Line
	2550 3150 2250 3150
Text GLabel 2550 3250 2    50   UnSpc ~ 0
PIN_08
Text GLabel 2550 3350 2    50   UnSpc ~ 0
PIN_09
Text GLabel 2550 3700 2    50   UnSpc ~ 0
PIN_10
Text GLabel 2550 3800 2    50   UnSpc ~ 0
PIN_11
Text GLabel 2550 3900 2    50   UnSpc ~ 0
PIN_12
Wire Wire Line
	2550 3900 2250 3900
Wire Wire Line
	2250 3800 2550 3800
Wire Wire Line
	2550 3700 2250 3700
Wire Wire Line
	2250 3350 2550 3350
Wire Wire Line
	2550 3250 2250 3250
$Sheet
S 4500 2000 2000 500 
U 5E7A082E
F0 "SCH001LDDH200324A - Chronograph" 50
F1 "SCH001LDDH200324A.sch" 50
$EndSheet
$Sheet
S 4500 3000 2000 500 
U 5E7A0AC7
F0 "SCH002LDDH200324A - Timer" 50
F1 "SCH002LDDH200324A.sch" 50
$EndSheet
$Sheet
S 4500 4000 2000 500 
U 5E7A0BC1
F0 "SCH003LDDH200324A - Status Bar" 50
F1 "SCH003LDDH200324A.sch" 50
$EndSheet
$Sheet
S 4500 5000 2000 500 
U 5E7A0C9B
F0 "SCH004LDDH200324A - Icon.sch" 50
F1 "SCH004LDDH200324A.sch" 50
$EndSheet
$Comp
L Connector_Generic:Conn_01x03 J1
U 1 1 5E817FA0
P 2050 2150
F 0 "J1" H 1968 2467 50  0000 C CNN
F 1 "Conn_01x03" H 1968 2376 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 2050 2150 50  0001 C CNN
F 3 "~" H 2050 2150 50  0001 C CNN
	1    2050 2150
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 5E819AC3
P 2050 2700
F 0 "J2" H 1968 3017 50  0000 C CNN
F 1 "Conn_01x03" H 1968 2926 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 2050 2700 50  0001 C CNN
F 3 "~" H 2050 2700 50  0001 C CNN
	1    2050 2700
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J3
U 1 1 5E81ADE4
P 2050 3250
F 0 "J3" H 1968 3567 50  0000 C CNN
F 1 "Conn_01x03" H 1968 3476 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 2050 3250 50  0001 C CNN
F 3 "~" H 2050 3250 50  0001 C CNN
	1    2050 3250
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J4
U 1 1 5E81B892
P 2050 3800
F 0 "J4" H 1968 4117 50  0000 C CNN
F 1 "Conn_01x03" H 1968 4026 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 2050 3800 50  0001 C CNN
F 3 "~" H 2050 3800 50  0001 C CNN
	1    2050 3800
	-1   0    0    -1  
$EndComp
$EndSCHEMATC
