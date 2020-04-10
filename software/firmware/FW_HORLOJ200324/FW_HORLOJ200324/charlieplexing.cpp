/*
 * charlieplexing.cpp
 *
 * Created: 10/04/2020 03:49:05
 *  Author: marcu
 */ 

#include<avr/io.h>

#define NUMBER_OF_CHARLIE_PINS 12
#define NUMBER_OF_CHARLIE_LEDS 120

unsigned int code = 0; 
unsigned int mask = 0; 
unsigned int counter = 0;


unsigned int first_pin_bit = 1;
unsigned int second_pin_bit = 1;


inline bool isTheLastLed(){
	return (counter == NUMBER_OF_CHARLIE_LEDS)
}

inline bool isTheLastPin(){
	return (counter == NUMBER_OF_CHARLIE_PINS)
}


void incrementCharlieCode(){
	if(!isTheLastLed()){
		_second_pin_bit =(_second_pin_bit<<_charlie_counter);
	}
}

unsigned int getCharlieCode(){
	
}