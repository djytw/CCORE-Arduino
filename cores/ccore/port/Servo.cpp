#include "Servo.h"
#include "Arduino.h"
Servo* servo_list[SERVO_COUNT_MAX];
u8 servo_count=0;
u8 servo_init=0;
int servo_tick=0;

void Servo::init(){
	if(servo_init)return;
	servo_init=1;

}

u8 Servo::attach(int pi, int mi, int ma){
	init();
	pin=pi&0xff;
	min=mi;
	max=ma;
	isActive=1;
	if(servo_count>SERVO_COUNT_MAX)return -1;
	servo_list[servo_count]=this;
	servo_count++;
	writeMicroseconds(DEFAULT_PULSE_WIDTH);
	return 0;
}
void Servo::writeMicroseconds(int value){
	if(value<min)value=min;
	if(value>max)value=max;
	ticks=value;
}
void Servo::detach(){
	u8 i;
	isActive=0;
	for (i=0;i<servo_count;i++)
		if(servo_list[i]==this)break;
	if(i==servo_count)return;
	for (;i<servo_count-1;i++)
		servo_list[i]=servo_list[i+1];
	servo_list[i]=0;
	servo_count--;
	digitalWrite(pin,LOW);
}
extern "C" void servo_isr(){
	u8 i;
	for(i=0;i<servo_count;i++){
		if(servo_tick==0)
			digitalWrite(servo_list[servo_count]->pin,HIGH);
		if(servo_tick>=servo_list[servo_count]->ticks)
			digitalWrite(servo_list[servo_count]->pin,LOW);
	}
	servo_tick++;
	if(servo_tick>REFRESH_INTERVAL)servo_tick=0;
}