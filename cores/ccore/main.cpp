
#include <Arduino.h>

int main(void)
{
	init();

	initVariant();

	setup();
    
	for (;;) {
		loop();
	}
        
	return 0;
}

asm(".text\n"
	".export __start\n"
	".align 4\n"
	".global __start\n"
	".type __start,@function\n"
	"__start:\n"
	"jsri main\n");