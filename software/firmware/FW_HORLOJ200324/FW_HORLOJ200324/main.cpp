//H.Orloj Firmware V200324
//Author: Marcus V M Oliveira		30/MARCH/2020

#include <avr/io.h>
#include <avr/interrupt.h>

#define  F_CPU 1000000
#include <util/delay.h>

#include "rtc.h"

rtc sysRTC;

void setupTIMER2(){
	TCCR2A = 0x00; //OC2A and OC2B as normal GPIO pins; Normal Operation Mode.
	TCCR2B = 0x05; //Normal Operation Mode; Prescaler in ClockIO/128
	TIMSK2 = 0x01; //Interruption Mask on Timer2 for Overflow (ocurred at every 1 second);
	ASSR |= (1<<AS2); //Enables 32.768kHz Crystal Oscilattor
}

void holdTime(){
	for (unsigned int i=0; i<50000; i++)
	{
		
	}
}

ISR(TIMER2_OVF_vect){
	//cli();
	sysRTC.Ticker();
	PORTB ^= (1<<2);
	_delay_ms(100);
	PORTB ^= (1<<2);
	//sei();
}

int main(void)
{
	setupTIMER2();
	
	DDRB |= (1<<2);
	PORTB |= (1<<2);
	
	sei();
		
    while (1) 
    {
		
    }
}

