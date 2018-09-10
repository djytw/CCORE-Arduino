

#ifndef Pins_Arduino_h
#define Pins_Arduino_h


#define PIN_EPORT_MASK	0x10
#define PIN_EPORT_PIN(pin)	(pin&7)

#define PIN_SPI_MASK	0x20
#define PIN_SPI_PORT(pin) 	(((pin)&0xc)>>2)
#define PIN_SPI_PIN(pin)	((pin)&3)

#define PIN_USI_MASK	0x30
#define PIN_USI_PORT(pin) 	(((pin)&0xc)>>2)
#define PIN_USI_PIN(pin)	((pin)&3)

#define PIN_EPORT_(pin)	(((pin)&7)|0x10)
#define PIN_EPORT_0   	0x10
#define PIN_EPORT_1   	0x11
#define PIN_EPORT_2   	0x12
#define PIN_EPORT_3   	0x13
#define PIN_EPORT_4   	0x14
#define PIN_EPORT_5   	0x15
#define PIN_EPORT_6   	0x16
#define PIN_EPORT_7   	0x17

#define PIN_SPI_(pin)	(((pin)&0xf)|0x20)
#define PIN_SPI_MISO 	0
#define PIN_SPI_MOSI 	1
#define PIN_SPI_SCK 	2
#define PIN_SPI_SS 		3
#define PIN_SPI1		0x20
#define PIN_SPI2		0x24
#define PIN_SPI3		0x28
#define PIN_SPI1_(pin)	(((pin)&3)|PIN_SPI1)
#define PIN_SPI2_(pin)	(((pin)&3)|PIN_SPI2)
#define PIN_SPI3_(pin)	(((pin)&3)|PIN_SPI3)

#define PIN_SPI1_MOSI   (PIN_SPI1|PIN_SPI_MOSI)
#define PIN_SPI1_SS   	(PIN_SPI1|PIN_SPI_SS)
#define PIN_SPI1_MISO  	(PIN_SPI1|PIN_SPI_MISO)
#define PIN_SPI1_SCK   	(PIN_SPI1|PIN_SPI_SCK)
#define PIN_SPI2_MOSI   (PIN_SPI2|PIN_SPI_MOSI)
#define PIN_SPI2_SS   	(PIN_SPI2|PIN_SPI_SS)
#define PIN_SPI2_MISO  	(PIN_SPI2|PIN_SPI_MISO)
#define PIN_SPI2_SCK   	(PIN_SPI2|PIN_SPI_SCK)
#define PIN_SPI3_MOSI   (PIN_SPI3|PIN_SPI_MOSI)
#define PIN_SPI3_SS   	(PIN_SPI3|PIN_SPI_SS)
#define PIN_SPI3_MISO  	(PIN_SPI3|PIN_SPI_MISO)
#define PIN_SPI3_SCK   	(PIN_SPI3|PIN_SPI_SCK)

#define PIN_USI_(pin)	(((pin)&0xf)|0x30)
#define PIN_USI1 		0x30
#define PIN_USI2 		0x34
#define PIN_USI3 		0x38
#define PIN_USI_RST 	0
#define PIN_USI_CLK 	1
#define PIN_USI_DAT 	2
#define PIN_USI1_(pin)	(((pin)&3)|PIN_USI1)
#define PIN_USI2_(pin)	(((pin)&3)|PIN_USI2)
#define PIN_USI3_(pin)	(((pin)&3)|PIN_USI3)

#define PIN_USI1_RST   	(PIN_USI1|PIN_USI_RST)
#define PIN_USI1_DAT   	(PIN_USI1|PIN_USI_DAT)
#define PIN_USI1_CLK  	(PIN_USI1|PIN_USI_CLK)
#define PIN_USI2_RST   	(PIN_USI2|PIN_USI_RST)
#define PIN_USI2_DAT   	(PIN_USI2|PIN_USI_DAT)
#define PIN_USI2_CLK  	(PIN_USI2|PIN_USI_CLK)
#define PIN_USI3_RST   	(PIN_USI3|PIN_USI_RST)
#define PIN_USI3_DAT   	(PIN_USI3|PIN_USI_DAT)
#define PIN_USI3_CLK  	(PIN_USI3|PIN_USI_CLK)
#endif
