#ifndef CHARLIEPLEXING_H_
#define CHARLIEPLEXING_H_

#define NUMBER_OF_CHARLIE_PINS 12
#define NUMBER_OF_CHARLIE_LEDS 120

#define DDR_A
#define DDR_B
#define PORT_A
#define PORT_B
#define MASK_DDR_A
#define MASK_DDR_B
#define MASK_PORT_A
#define MASK_PORT_B

#define END_OF_SEQUENCE_FOR_SECOND_PIN (1 << (NUMBER_OF_CHARLIE_PINS-1))

extern volatile unsigned int ledCounter;
extern volatile unsigned int first_pin;
extern volatile unsigned int second_pin;
extern volatile unsigned int data_direction;

void cleanDisplayCode();

inline void	incrementLedCounter();

inline bool isSecondLedOfASegment();

inline bool isFirstLedOfASegment();

inline bool isEven(unsigned int number);

inline bool isTheEndOfSequence();

inline bool isTimeToUpdateSecondPin();

inline void updateFirstPinCode();

inline void computeFirstPinCode();

inline void computeSecondPinCode();

inline void computeDataDirectionCode();

inline char getFirstByteOfUnsignedInt(unsigned int number);

inline char getSecondByteOfUnsignedInt(unsigned int number);

inline void setComputedPinCode();

//Put this function on ISR
void charlieplexDisplay();

#endif /* CHARLIEPLEXING_H_ */