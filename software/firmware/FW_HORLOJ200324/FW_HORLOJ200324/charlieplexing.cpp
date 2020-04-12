/*
 * charlieplexing.cpp
 *
 * Created: 10/04/2020 03:49:05
 *  Author: marcu
 */ 

#include <avr/io.h>
#include "charlieplexing.h"
// 
// extern unsigned int ledCounter;
// extern unsigned int first_pin;
// extern unsigned int second_pin;
// extern unsigned int data_direction;

volatile unsigned int ledCounter = 0;
volatile unsigned int first_pin = (1<<0);
volatile unsigned int second_pin = (1<<1);
volatile unsigned int data_direction = (first_pin | second_pin);

/*

SG     ----|||| ||||||||		 ÍMPAR					 PAR
00 - 0b00000000 00000011	(1)	 0b00000000 00000001	(2)  0b00000000 00000010 
01 - 0b00000000 00000101	(3)  0b00000000 00000001	(4)	 0b00000000 00000100 
02 - 0b00000000 00001001	(5)  0b00000000 00000001	(6)  0b00000000 00001000
03 - 0b00000000 00010001	(7)	 0b00000000 00000001	(8)	 0b00000000 00010000
04 - 0b00000000 00100001	(9)	 0b00000000 00000001	(10) 0b00000000 00100000
05 - 0b00000000 01000001	(11) 0b00000000 00000001	(12) 0b00000000 01000000
06 - 0b00000000 10000001	(13) 0b00000000 00000001	(14) 0b00000000 10000000
07 - 0b00000001 00000001	(15) 0b00000000 00000001	(16) 0b00000001 00000000
08 - 0b00000010 00000001	(17) 0b00000000 00000001	(18) 0b00000010 00000000
09 - 0b00000100 00000001	(19) 0b00000000 00000001	(20) 0b00000100 00000000
10 - 0b00001000 00000001	(21) 0b00000000 00000001	(22) 0b00001000 00000000
11 - 0b00000000 00000110	(23) 0b00000000 00000010	(24) 0b00000000 00000100 << 
12 - 0b00000000 00001010
13 - 0b00000000 00010010
14 - 0b00000000 00100010
15 - 0b00000000 01000010
16 - 0b00000000 10000010
17 - 0b00000001 00000010
18 - 0b00000010 00000010
19 - 0b00000100 00000010
20 - 0b00001000 00000010
21 - 0b00000000 00001100
22 - 0b00000000 00010100
23 - 0b00000000 00100100
24 - 0b00000000 01000100
25 - 0b00000000 10000100
26 - 0b00000001 00000100
27 - 0b00000010 00000100
28 - 0b00000100 00000100
29 - 0b00001000 00000100
30 - 0b00000000 00011000
31 - 0b00000000 00101000
32 - 0b00000000 01001000
33 - 0b00000000 10001000
34 - 0b00000001 00001000
35 - 0b00000010 00001000
36 - 0b00000100 00001000
37 - 0b00001000 00001000
38 - 0b00000000 00110000
39 - 0b00000000 01010000
40 - 0b00000000 10010000
41 - 0b00000001 00010000
42 - 0b00000010 00010000
43 - 0b00000100 00010000
44 - 0b00001000 00010000
45 - 0b00000000 01100000
46 - 0b00000000 10100000
47 - 0b00000001 00100000
48 - 0b00000010 00100000
49 - 0b00000100 00100000
50 - 0b00001000 00100000
51 - 0b00000000 11000000
52 - 0b00000001 01000000
53 - 0b00000010 01000000
54 - 0b00000100 01000000
55 - 0b00001000 01000000
56 - 0b00000001 10000000
57 - 0b00000010 10000000
58 - 0b00000100 10000000
59 - 0b00001000 10000000
*/

/*
- Interrupção ocorre;
- O contador que indica o LED é incrementado; 
- Primeiro Pino é calculado; 
- Segundo Pino é calculado; 
- Os pinos de Entrada e Saída são configurados; 
- Os valores nos registradores são atualizados; 
- Verifica-se que foi alcançado o limite de incrementos; 
*/

void cleanDisplayCode(){
	ledCounter = 0;
	first_pin = (1<<0);
	second_pin = (1<<1);
	data_direction = (first_pin | second_pin);
}

inline void	incrementLedCounter(){
	if(ledCounter == NUMBER_OF_CHARLIE_LEDS){
		cleanDisplayCode();
	} else {
		ledCounter++;
	}
}

inline bool isSecondLedOfASegment(){
	return((ledCounter%2) == 0);
}

inline bool isFirstLedOfASegment(){
	return((ledCounter%2) != 0);
}

inline bool isEven(unsigned int number){
	return((number%2) == 0);
}

inline bool isTheEndOfSequence(){
	return((second_pin == END_OF_SEQUENCE_FOR_SECOND_PIN) && (isFirstLedOfASegment()));
	}

inline bool isTimeToUpdateSecondPin(){
	//return(isFirstLedOfASegment());
	return(isFirstLedOfASegment() && ledCounter > 1);
}

inline void updateFirstPinCode(){
	first_pin = (first_pin << 1);
}

inline void computeFirstPinCode(){
	if(isTheEndOfSequence()){
		updateFirstPinCode();
	}
}

inline void computeSecondPinCode(){
	if(isTheEndOfSequence()){
		second_pin = (first_pin << 1);
	} else if(isTimeToUpdateSecondPin()){
		second_pin = (second_pin << 1);
	}
}

inline void computeDataDirectionCode(){
	data_direction = (first_pin | second_pin);
}

inline char getFirstByteOfUnsignedInt(unsigned int number){
	return (char (number & 0x00FF));
}

inline char getSecondByteOfUnsignedInt(unsigned int number){
	return (char ((number & 0xFF00) >> 8));
}

inline void setComputedPinCode(){
	DDRD = getFirstByteOfUnsignedInt(data_direction);
	DDRB = (getSecondByteOfUnsignedInt(data_direction) << 2);
	
	if(isFirstLedOfASegment()){
		PORTD = getFirstByteOfUnsignedInt(first_pin);
		PORTB = (getSecondByteOfUnsignedInt(first_pin) << 2);
	} else {
		PORTD = getFirstByteOfUnsignedInt(second_pin);
		PORTB = (getSecondByteOfUnsignedInt(second_pin) << 2);
	}
	
}

//Put this function on ISR
void charlieplexDisplay(){
	incrementLedCounter();
	computeFirstPinCode();
	computeSecondPinCode();
	computeDataDirectionCode();
	setComputedPinCode();
	
}
