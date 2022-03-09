#include "C:\ti\ccs1110\TivaWare_C_Series-2.2.0.295\inc\tm4c123gh6pm.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/*The program below controls a unipolar stepper motor using PB 3,2,1 and 0 */


void delayMs(int n);

 //Delay n miliseconds (16MHz CPU clock)
 void delayMs(int n)
{
   int i;
   int j;
   for(i = 0; i < n; i++)
   {
      for(j = 0; j < 3180; j++)
      {
                //do nothing for 1ms
      }
    }

}


int main(void)
{
    int delay = 5;
    int direction = 0;
    const char steps[] = {0x9, 0x3, 0x6, 0xC};
    int i = 0;

    SYSCTL_RCGCGPIO_R |= 0X02; //enable the clock on GPIOB

    /*PORT B 3,2,1,0 for motor control*/
    GPIO_PORTB_DIR_R |= 0X0F;     //PORTB 3,2,1 and 0 as output
    GPIO_PORTB_DEN_R |= 0X0F;     //PORTB 3,2,1 and 0 as digital pins

    for(;;)
    {
        if(direction)
        {
            GPIO_PORTB_DATA_R = (steps[i++ & 3]);
        }
        else
        {
            GPIO_PORTB_DATA_R = (steps[i-- & 3]);
        }
        delayMs(delay);
    }





    /*This function is called  by the startup assembly code to perform system specific initialization tasks*/

  //  void SystemInit(void)
  //  {
   //     SCB->CPACR |= 0X00f00000;
   // }


    return 0;
}
