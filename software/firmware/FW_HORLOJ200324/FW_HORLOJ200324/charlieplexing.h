#ifndef CHARLIEPLEXING_H_
#define CHARLIEPLEXING_H_

class display{
	public:
	void displayOff();
	void displayOn();
	
	};

class segment{
	public:
	void setGreenBrightnessValue(unsigned char brightness);
	void setRedBrightnessValue(unsigned char brightness);
	unsigned char getGreenBrightnessValue();
	unsigned char getRedBrightnessValue();
	
	private:
	static unsigned char segmentVector[120];
	static unsigned int segmentVectorIndex;
	
	unsigned char Index;
	
	unsigned char convertBrightnessValueToNibbleValue();
	unsigned char convertNibbleValueToBrightness();
	};


#endif /* CHARLIEPLEXING_H_ */