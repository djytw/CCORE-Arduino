#pragma once
#include "includes.h"
#include <inttypes.h>
#include "regmap/sci_reg.h"
#include "type.h"


class HardwareSerial{
public:
    void begin(unsigned long);
    int read(void);
    void write(char);
    void write(const char*);
    void stop();
};
extern HardwareSerial Serial;