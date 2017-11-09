#ifndef __STEPPER_H
#define __STEPPER_H

#include "stm32f10x.h"

void Step_Motor_GPIO_Init(void);
void SetMotor(unsigned char InputData);
void motorNcircle(int n,u8 position);
void Head_Action(void);
#endif
