#include "spi.h"
#include "bcm2835.h"
SPI::SPI(int bitorder,int datamode, int clockdivider, int chipselect, int chipselectpolarity)
{
        bcm2835_spi_setBitOrder(bitorder);      // The default
        bcm2835_spi_setDataMode(datamode);                   // The default
        bcm2835_spi_setClockDivider(clockdivider); // The default
        bcm2835_spi_chipSelect(chipselect);                      // The default
        bcm2835_spi_setChipSelectPolarity(chipselect,chipselectpolarity);
}

uint8_t SPI::transfer(uint8_t data){
    return bcm2835_spi_transfer(data);
   }
