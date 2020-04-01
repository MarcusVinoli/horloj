//Real Time Clock (RTC) Library
//Using a 32.768kHz Crystal on OSC1 and OSC2 pins
//Author: Marcus V M Oliveira	30/MAR/2020

#ifndef RTC_M328P_H_
#define RTC_M328P_H_

//Time Format
typedef struct{
	short int hour;
	short int min;
	short int sec;
} timeformat_t;

//RTC Object
class rtc{
	public:
	//Constructor
	rtc(){ }
	
	//Time Increment on ISR
	void Ticker();
	
	//Time Handling
	void getTime(timeformat_t *now_time);
	
	void setTime(timeformat_t new_time);
	void setTime(short int hour, short int minutes, short int seconds);
	
	private:
	static timeformat_t _current_time;

	inline void incrementTime();
	inline void incrementSeconds();
	inline void incrementMinutes();
	inline void incrementHours();
	
};

#endif /* RTC_M328P_H_ */