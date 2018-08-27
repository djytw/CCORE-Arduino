

#include "wdt_api.h"
#include "cpm_api.h"
#include "eport_api.h"
void initVariant() { }
void init(){
	cpm_init();
	sci_init(SCI_ID2, g_ips_clk, BAUDRATE_115200);
	wdt_disable();
}
void delayMicroseconds(unsigned int ms){
	while(ms--)
	delay(1200);
}

void delaySeconds(unsigned long s){
	while(s--)
		delay(1200000);
}