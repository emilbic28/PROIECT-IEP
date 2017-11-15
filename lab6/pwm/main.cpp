// pwm.c
//
// Example program for bcm2835 library
// Shows how to use PWM to control GPIO pins
//
// After installing bcm2835, you can build this
// with something like:
// gcc -o pwm pwm.c -l bcm2835
// sudo ./pwm
//
// Or you can test it before installing with:
// gcc -o pwm -I ../../src ../../src/bcm2835.c pwm.c
// sudo ./pwm
//
// Connect an LED between GPIO18 (pin 12) and GND to observe the LED changing in brightness
//
// Author: Mike McCauley
// Copyright (C) 2013 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $
#include <bcm2835.h>
#include <stdio.h>
#include "pin.h"
#include "pwm.h"
#include "spi.h"
#include "serial.h"
// PWM output on RPi Plug P1 pin 12 (which is GPIO pin 18)
// in alt fun 5.
// Note that this is the _only_ PWM pin available on the RPi IO headers
#define PIN RPI_GPIO_P1_12
// and it is controlled by PWM channel 0
#define PWM_CHANNEL 0
// This controls the max range of the PWM signal
#define RANGE 1024
int main(int argc, char **argv)
{
    SPI *c;
    bcm2835_set_debug(1);
    if (!bcm2835_init())
    {
      printf("bcm2835_init failed. Are you running as root??\n");
      return 1;
    }
    if (!bcm2835_spi_begin())
    {
      printf("bcm2835_spi_begin failed. Are you running as root??\n");
      return 1;
    }
    c=new SPI(BCM2835_SPI_BIT_ORDER_MSBFIRST,BCM2835_SPI_MODE0,BCM2835_SPI_CLOCK_DIVIDER_65536,BCM2835_SPI_CS0,LOW);
    uint8_t send_data = 0x23;
    uint8_t read_data = c->transfer(send_data);
    printf("Sent to SPI: 0x%02X. Read back from SPI: 0x%02X.\n", send_data, read_data);
    return 0;
}
