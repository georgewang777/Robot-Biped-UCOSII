#ifndef __SERVO_H
#define	__SERVO_H

#include "stm32f10x.h"

void Servo_Init(void);

void Servo1(u32 compare);
void Servo2(u32 compare);
void Servo3(u32 compare);
void Servo4(u32 compare);

void Servo1_pos(u8 dir,u8 angle);

void Servo2_pos(u8 dir,u8 angle);

void Servo3_pos(u8 dir,u8 angle);

void Servo4_pos(u8 dir,u8 angle);


#endif
