#ifndef SERIAL_H
#define SERIAL_H
#include<bcm2835.h>

class SERIAL
{
public:
    SERIAL();
    virtual uint8_t transfer(uint8_t data)=0;
};

#endif // SERIAL_H
