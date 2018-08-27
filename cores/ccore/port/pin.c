
#include "eport_api.h"
#include "pins_arduino.h"

void pinMode(uint8_t pin, uint8_t mode){
	mode = mode & 1;
	u8 pin_num=pin & 7;
	switch(pin&0xf0){
		case PIN_EPORT_MASK:
		eport_config(pin_num, mode, FALSE, FALSE);
		break;
	}
}
void digitalWrite(uint8_t pin, uint8_t value){
	value = value & 1;
	u8 pin_num=pin & 7;
	switch(pin & 0xf0){
		case PIN_EPORT_MASK:
		eport_write_port_data(pin_num, value);
		break;
	}
}
int digitalRead(uint8_t pin){
	u8 pin_num=pin & 7;
	switch(pin & 0xf0){
		case PIN_EPORT_MASK:
		return eport_read_port_data(pin_num);
	}
	return -1;
}