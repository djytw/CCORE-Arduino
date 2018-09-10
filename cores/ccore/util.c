#include "includes.h"
void delay_tick(volatile UINT32 val)
{
	//TODO: need to repair
	while(val--);
}
void delayMicroseconds(unsigned int ms){
	while(ms--)
	delay_tick(1200);
}

void delaySeconds(unsigned long s){
	while(s--)
		delay_tick(1200000);
}
