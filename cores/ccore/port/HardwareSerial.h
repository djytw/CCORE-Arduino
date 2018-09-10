#pragma once

#include <inttypes.h>

#include "type.h"

extern u32 g_ips_clk;

typedef struct
{
	union
	{
		VUINT16 BD;		//0x0000 SCI baud register
		struct		//zfj20171214
		{
			VUINT8  BDL;	//0x0000 SCI baud register low
			VUINT8  BDH;	//0x0001 SCI baud register high
		}BDHL;
	};
	VUINT8 CR2;				//0x0002 SCI control register2
	VUINT8 CR1;				//0x0003 SCI control register1
	VUINT8 SR2;				//0x0004 SCI status register2
	VUINT8 SR1;				//0x0005 SCI status register1
	VUINT8 DRL;				//0x0006 SCI data register low
	VUINT8 DRH;				//0x0007 SCI data register high
	VUINT8 PORT;			//0x0008 SCI port data register
	VUINT8 PURD;			//0x0009 SCI pullup and reduced drive register
	VUINT8 BRDF;			//0x000a SCI fractional baudrate divisor register
	VUINT8 DDR;				//0x000b SCI data direction register
	VUINT8 IRCR;			//0x000c SCI infrared control register
	VUINT8 TR;				//0x000d SCI test register
	VUINT8 FCR;				//0x000e SCI fifo contral register
	VUINT8 IRDR;			//0x000f SCI infrared divisor register
	VUINT8 Reserved_10;;	//0x0010 Reserved at 0x00000010
	VUINT8 FSR;				//0x0011 SCI fifo status register
}SCI_REG;

class HardwareSerial{
public:
    void begin(unsigned long);
    int read(void);
    void write(char);
    void write(const char*);
    void stop();
};
extern HardwareSerial Serial;