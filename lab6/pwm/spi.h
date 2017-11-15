#ifndef SPI_H
#define SPI_H
#include"serial.h"

class SPI: public SERIAL
{
public:
    SPI(int bitorder,int datamode, int clockdivider, int chipselect, int chipselectpolarity);
    uint8_t transfer(uint8_t data);
};

#endif // SPI_H
