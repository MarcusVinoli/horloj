//Real Time Clock (RTC) Library
//Using a 32.768kHz Crystal on OSC1 and OSC2 pins
//Author: Marcus V M Oliveira	30/MAR/2020

#include "rtc.h"

//Static Variables Definition
timeformat_t rtc::_current_time;

void rtc::ticker(){
	
	incrementTime();
}

inline void rtc::incrementTime(){
	incrementSeconds();
}
	
inline void rtc::incrementSeconds(){
	if(_current_time.sec == 59){
		_current_time.sec = 0;
		incrementMinutes();
	} else {
		_current_time.sec++;
	}
}

inline void rtc::incrementMinutes(){
	if(_current_time.min == 59){
		_current_time.min = 0;
		incrementHours();
		} else {
		_current_time.min++;
	}
}
	
inline void rtc::incrementHours(){
	if(_current_time.hour == 23){
		_current_time.hour = 0;
		} else {
		_current_time.hour++;
	}
}

void rtc::getTime(timeformat_t *now_time){
	*(&now_time->sec) = _current_time.sec;
	*(&now_time->min) = _current_time.min;
	*(&now_time->hour) = _current_time.hour;
}

void rtc::setTime(timeformat_t new_time){
	_current_time.hour = new_time.hour;
	_current_time.min = new_time.min;
	_current_time.sec = new_time.sec;
}
	
void rtc::setTime(short int hour, short int minutes, short int seconds){
	timeformat_t new_time;
	new_time.hour = hour;
	new_time.min = minutes;
	new_time.sec = seconds; 
	setTime(new_time);
}
		 
