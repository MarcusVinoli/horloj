EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 10
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
L MCU_Microchip_ATmega:ATmega328P-MMH U1
U 1 1 5E769B19
P 3500 3900
F 0 "U1" H 2856 3946 50  0000 R CNN
F 1 "ATmega328P-MMH" H 2856 3855 50  0000 R CNN
F 2 "Package_DFN_QFN:QFN-28-1EP_4x4mm_P0.45mm_EP2.4x2.4mm" H 3500 3900 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 3500 3900 50  0001 C CNN
	1    3500 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 3300 5400 3200
Wire Wire Line
	4100 3400 5400 3400
Wire Wire Line
	5550 3200 5400 3200
Wire Wire Line
	5400 3500 5550 3500
Wire Wire Line
	5400 3400 5400 3500
Wire Wire Line
	4100 4200 5050 4200
Wire Wire Line
	4700 4500 4100 4500
Wire Wire Line
	4100 4400 4700 4400
Text GLabel 4350 4100 2    50   Output ~ 0
I2C_SCL
Wire Wire Line
	4350 4100 4100 4100
Text GLabel 4350 4000 2    50   BiDi ~ 0
I2C_SDA
Wire Wire Line
	4350 4000 4100 4000
$Comp
L power:GND #PWR01
U 1 1 5E76F1F0
P 3500 5500
F 0 "#PWR01" H 3500 5250 50  0001 C CNN
F 1 "GND" H 3505 5327 50  0000 C CNN
F 2 "" H 3500 5500 50  0001 C CNN
F 3 "" H 3500 5500 50  0001 C CNN
	1    3500 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3500 5500 3500 5400
Text GLabel 5050 4200 2    50   Input ~ 0
~RESET
Wire Wire Line
	4650 3200 4100 3200
Wire Wire Line
	4100 3100 4650 3100
Wire Wire Line
	4650 3000 4100 3000
Wire Wire Line
	4650 2900 4100 2900
Text Label 4150 3000 0    50   ~ 0
SPI_MOSI
Text Label 4150 3100 0    50   ~ 0
SPI_MISO
Text Label 4150 3200 0    50   ~ 0
SPI_SCK
Text HLabel 4700 4400 2    50   Output ~ 0
PORTD_0
Text HLabel 4700 4500 2    50   Output ~ 0
PORTD_1
Text HLabel 4650 2900 2    50   Output ~ 0
PORTB_2
Text HLabel 4650 3000 2    50   Output ~ 0
PORTB_3
Text HLabel 4650 3100 2    50   Output ~ 0
PORTB_4
Text HLabel 4650 3200 2    50   Output ~ 0
PORTB_5
Wire Wire Line
	4100 3300 5400 3300
Wire Wire Line
	5550 3500 5550 3450
Wire Wire Line
	5550 3250 5550 3200
$Comp
L Device:Crystal_Small Y1
U 1 1 5E76C625
P 5550 3350
F 0 "Y1" V 5504 3438 50  0000 L CNN
F 1 "32.768kHz" V 5595 3438 50  0000 L CNN
F 2 "Crystal:Crystal_C26-LF_D2.1mm_L6.5mm_Horizontal" H 5550 3350 50  0001 C CNN
F 3 "~" H 5550 3350 50  0001 C CNN
	1    5550 3350
	0    1    1    0   
$EndComp
Text HLabel 4700 4600 2    50   Output ~ 0
PORTD_2
Text HLabel 4700 4700 2    50   Output ~ 0
PORTD_3
Text HLabel 4700 4800 2    50   Output ~ 0
PORTD_4
Text HLabel 4700 4900 2    50   Output ~ 0
PORTD_5
Text HLabel 4700 5000 2    50   Output ~ 0
PORTD_6
Text HLabel 4700 5100 2    50   Output ~ 0
PORTD_7
Wire Wire Line
	4700 5100 4100 5100
Wire Wire Line
	4100 5000 4700 5000
Wire Wire Line
	4700 4900 4100 4900
Wire Wire Line
	4100 4800 4700 4800
Wire Wire Line
	4700 4700 4100 4700
Wire Wire Line
	4100 4600 4700 4600
$EndSCHEMATC
