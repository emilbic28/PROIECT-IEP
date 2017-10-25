#include "pin.h"
#include "bcm2835.h"

Pin::Pin(int numar, int directia, int stare)
{
          this->numar=numar;
          this->directia=directia;
          this->stare=stare;
          bcm2835_gpio_fsel(numar, directia);
}

void Pin::set(int p)
 {
     if(this->directia==0)
      {
          bcm2835_gpio_write(this->numar, p);
     }
}

int Pin::get(int stare)
{
          int res;

          if(this->directia == 0)
          {
              res = this->stare;
          }
          else
          {
              res  = bcm2835_gpio_lev(this->numar);
          }
          return res;
}
void Pin::change()
{
if(this->directia==0)

{

bcm2835_gpio_fsel(this->numar, BCM2835_GPIO_FSEL_INPT);

}
else
{
bcm2835_gpio_fsel(this->numar, BCM2835_GPIO_FSEL_OUTP);

}

}
