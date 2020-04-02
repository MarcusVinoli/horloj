//TIMER LIBRARY
//Using RTC Library
//Author: Marcus V M Oliveira	01-APR-2020

#include "timer.h"

timeformat_t timer::_last_update_time;
timeformat_t timer::_now_time;

void timer::ticker(){
	if (isRunning())
	{
		decrementTime();
	}
}

void timer::setTime(timeformat_t time_set){
	_time_set.sec = time_set.sec;
	_time_set.min = time_set.min;
	_time_set.hour = time_set.hour;
}

void timer::setCallback(void (*callBackFunction)()){
	_callBackFunction = &callBackFunction;
}

void timer::reset(){
	stop();
	timeformat_t _zero_timer;
	_zero_timer.hour = 0;
	_zero_timer.min = 0;
	_zero_timer.sec = 0;
	setTime(_zero_timer);
}

void timer::start(){
	_timer_status = RUNNING;
}

void timer::stop(){
	_timer_status = STOPPED;
}

void timer::pause(){
	_timer_status = PAUSE;
}

void timer::resume(){
	_timer_status = RESUME;
}

inline void timer::checkIfIsTimeToCallbackFunction(){
	
}

inline void timer::decrementSeconds(){
	
}

inline void timer::decrementMinutes(){
	
}
inline void timer::decrementHours(){
	
}

inline void timer::decrementTime(){
	decrementSeconds();
}

inline bool timer::isRunning(){
	if( _timer_status == RUNNING || _timer_status == RESUME ){
		return true;
	} else
	return false;
}