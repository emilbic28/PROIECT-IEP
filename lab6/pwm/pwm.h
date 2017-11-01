#ifndef PWM_H
#define PWM_H


class Pwm
{
public:
    double frecventa;
    int factor_umplere;
    Pwm();
    Pwm(double fr, int fu);
    double get_frecventa();
    double get_factor_umplere();
    void set_frecv(double fr);
    void set_factor_umplere(int fu);
};

#endif // PWM_H
