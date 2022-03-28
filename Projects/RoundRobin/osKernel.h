#ifndef _OS_KERNEL_H
#define _OS_KERNEL_H
#include <stdint.h>
#include "tm4c123gh6pm.h"


void osKernelLaunch(uint32_t quanta);

void osKernelInit(void);

uint8_t osKernelAddThreads(void(*task0)(void),void(*task1)(void),void(*task2)(void));



#endif