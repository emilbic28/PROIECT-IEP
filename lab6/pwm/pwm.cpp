#include "pwm.h"
#include "bcm2835.h"

#define PIN RPI_GPIO_P1_12
#define PWM_CHANNEL 0

Pwm::Pwm(){
    frecventa=0;factor_umplere=0;
}
Pwm::Pwm(double fr, int fu){
    frecventa=fr;
    factor_umplere=fu;
    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
    bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);
    bcm2835_pwm_set_range(PWM_CHANNEL, frecventa);

    int data=factor_umplere*frecventa/100;
    bcm2835_pwm_set_data(PWM_CHANNEL,data);
}
double Pwm::get_frecventa(){
    return frecventa;
}
double Pwm::get_factor_umplere(){
    return factor_umplere;
}
void Pwm::set_frecv(double fr){
    frecventa=fr;
    bcm2835_pwm_set_range(PWM_CHANNEL, frecventa);
}
void Pwm::set_factor_umplere(int fu){
    factor_umplere=fu;
    int data=factor_umplere *frecventa/100;
    bcm2835_pwm_set_data(PWM_CHANNEL, data);
}
