#include "HardwareSerial.h"
void HardwareSerial::begin(unsigned long br){
	SCI_REG *sci = (SCI_REG *)0x70040000;
	int baud_rate;
	sci->BRDF = (((g_ips_clk * 8 / br) + 1) / 2) & 0x003f;
	baud_rate = (g_ips_clk * 4 / br) >> 6;
	sci->BDHL.BDH = (UINT8)((baud_rate >> 8) & 0x00ff);
	sci->BDHL.BDL = (UINT8)(baud_rate & 0x00ff);
 	sci->CR1 = 0x00;
 	sci->CR2 = 0x00;
}


void HardwareSerial::write(char c){
	SCI_REG *sci = (SCI_REG *)0x70040000;
	sci->CR2 |= 0x08;
	while(0 == (sci->SR1 & 0x80));
	sci->DRL = c;
	while(0 == (sci->SR1 & 0x40));
	sci->CR2 &= ~0x08;
}

void HardwareSerial::write(const char* s){
	while(*s)write(*s++);
}
void HardwareSerial::stop(){
	
}