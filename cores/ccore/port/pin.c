#include "includes.h"
#include "pins_arduino.h"
#include "regmap/eport_reg.h"
void pinMode(uint8_t pin, uint8_t mode){
	mode = mode & 1;
	switch(pin&0xf0){
	case PIN_EPORT_MASK:
		pin=pin&7;
		if (mode)	EPORT_EPDDR |= (1 << pin);
		else 		EPORT_EPDDR &= ~(1 << pin);
		break;
	/*case PIN_SPI_MASK:
		spi_config_gpio(PIN_SPI_PORT(pin), PIN_SPI_PIN(pin), mode);
		break;
	case PIN_USI_MASK:
		usi_config_gpio(PIN_USI_PORT(pin), PIN_USI_PIN(pin), mode);
		break;
	*/
	}
}
void digitalWrite(uint8_t pin, uint8_t value){
	value = value & 1;
	switch(pin & 0xf0){
	case PIN_EPORT_MASK:
		if(value)	EPORT_EPDR |= (1 << pin);
		else 		EPORT_EPDR &= ~(1 << pin);
		break;
	/*case PIN_SPI_MASK:
		spi_write_gpio(PIN_SPI_PORT(pin),PIN_SPI_PIN(pin),value);
		break;
	case PIN_USI_MASK:
		usi_write_gpio(PIN_USI_PORT(pin),PIN_USI_PIN(pin),value);
		break;
	*/
	}
}
int digitalRead(uint8_t pin){
	switch(pin & 0xf0){
		case PIN_EPORT_MASK:
			return (EPORT_EPPDR & (1 << pin)) > 0 ;

		/*case PIN_SPI_MASK:
		return spi_read_gpio(PIN_SPI_PORT(pin),PIN_SPI_PIN(pin));

		case PIN_USI_MASK:
		return usi_read_gpio(PIN_USI_PORT(pin),PIN_USI_PIN(pin));*/
		
	}
	return -1;
}