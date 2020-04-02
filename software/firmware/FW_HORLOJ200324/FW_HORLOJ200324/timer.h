//TIMER LIBRARY
//Using RTC Library
//Author: Marcus V M Oliveira	01-APR-2020

#ifndef TIMER_H_
#define TIMER_H_

#include "rtc.h"

enum timerstatus{
	STOPPED,
	RUNNING,
	PAUSE,
	RESUME,
	TIMED
	};

class timer
{
	public:
	void setTime(timeformat_t time_set);
	void setCallback(void (*callBackFunction)());
	
	void reset();
	void start();
	void stop();
	void pause();
	void resume();
	
	void ticker();
	
	inline bool isRunning();
		
	private:
	static timeformat_t _last_update_time;
	static timeformat_t _now_time;
	
	timeformat_t _time_set;
	timeformat_t _time_buffer;
	timerstatus _timer_status;
	
	void *_callBackFunction;
	
	void checkIfIsTimeToCallbackFunction();	
	inline void decrementTime();
	inline void decrementSeconds();
	inline void decrementMinutes();
	inline void decrementHours();
};



#endif /* TIMER_H_ */