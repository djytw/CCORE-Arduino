#pragma once 
#include "type.h"
#define MIN_PULSE_WIDTH       544     // the shortest pulse sent to a servo  
#define MAX_PULSE_WIDTH      2400     // the longest pulse sent to a servo 
#define DEFAULT_PULSE_WIDTH  1500     // default pulse width when servo is attached
#define REFRESH_INTERVAL    20000     // minumim time to refresh servos in microseconds 

#define SERVO_COUNT_MAX 	64

extern "C" void servo_isr();

class Servo
{
public:
	Servo();
	inline uint8_t attach(int pin){return attach(pin,MIN_PULSE_WIDTH,MAX_PULSE_WIDTH);}          // attach the given pin to the next free channel, sets pinMode, returns channel number or 0 if failure
	uint8_t attach(int pin, int min, int max); // as above but also sets min and max values for writes. 
	void detach();
	inline void write(int value){return writeMicroseconds(min+(max-min)*(value%180)/180);}             // if value is < 200 its treated as an angle, otherwise as pulse width in microseconds 
	void writeMicroseconds(int value); // Write pulse width in microseconds 
	int read(){return 180*(ticks-min)/(max-min);}                      // returns current pulse width as an angle between 0 and 180 degrees
	int readMicroseconds(){return ticks;}             // returns current pulse width in microseconds for this servo (was read_us() in first release)
	bool attached(){return isActive;}                   // return true if this servo is attached, otherwise false 

	void init();
	uint8_t servoIndex;               // index into the channel data for this servo
	int8_t min;                       // minimum is this value times 4 added to MIN_PULSE_WIDTH    
	int8_t max;                       // maximum is this value times 4 added to MAX_PULSE_WIDTH   
	u8 pin;
	u8 isActive;
	int ticks;
};
