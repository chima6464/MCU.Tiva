

/**
 * main.c
 */

#include "C:\ti\ccs1110\TivaWare_C_Series-2.2.0.295\inc\tm4c123gh6pm.h"

int _svc(0x00) svc_service_add(int x, int y);
int _svc(0x01) svc_service_sub(int x, int y);
int _svc(0x02) svc_service_mul(int x, int y);
int _svc(0x03) svc_service_div(int x, int y);

__asm void SVC_Handler(void)
{
    TST LR, #4  //0b 0100
    ITE EQ
    MRSEQ R0, RSP
    MRSNE R0, PSP
    B       __cpp(SVC_Handler_C)
}

void SVC_Handler_C(unsigned int * svc_args)
{
    unsigned int svc_number;
    svc_number = (char*)svc_args[6][-2]; //get first byte
    switch(svc_number)
    {
        case 0:
            svc_args[0] = svc_args[0] + svc_args[1]; //AAPCS doc
        break;

        case 1:
            svc_args[0] = svc_args[0] - svc_args[1]; //AAPCS doc
        break;

        case 2:
            svc_args[0] = svc_args[0] * svc_args[1]; //AAPCS doc
        break;

        case 3:
            svc_args[0] = svc_args[0] / svc_args[1]; //AAPCS doc
        break;

        default:
            break;


    }


}


int main(void)
{
    int x = 1;
    int y = 5;
    int z = svc_service_add(x,y);
    x = 3;
    y = 2;

    z = svc_service_sub(x,y);

    z = svc_service_mul(x,y);

    x = 4;
    y = 2;

    z = svc_service_div(x,y);
	return 0;
}


