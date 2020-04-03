//DISPLAY DATA STRUCTURE 
//Author: Marcus V M Oliveira		Creation: 03/APR/2020

#ifndef DISPLAY_DATA_H_
#define DISPLAY_DATA_H_

#define MAX_NUMBER_OF_SEGMENTS 60 
#define BI_CHROMATIC 

#ifdef BI_CHROMATIC

typedef unsigned char pixel_t;
typedef unsigned char red_t;
typedef unsigned char green_t; 

class display_data
{
	public:
	//Class Constructor
	display_data() {allocateNewIndex();}
	
	//Pixel Brightness Setting and Getting
	void setPixelValue(pixel_t pixel_value);
	void setRedValue(red_t value);
	void setGreenValue(green_t value);
	pixel_t getPixelValue();
	red_t getRedValue();
	green_t getGreenValue();
	
	//Concatenation of Values
	pixel_t concatPixelValue(red_t red, green_t gree);
	void splitPixelValue(pixel_t pixel, red_t *red, green_t *green);
	
	private:
	static pixel_t displayVector[60]
	static int indexCounter;
	int index;
	
	void allocateNewIndex();
	void zeroDisplayVector();
	
};
#endif





#endif /* DISPLAY_DATA_H_ */