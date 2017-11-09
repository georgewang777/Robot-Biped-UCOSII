#ifndef __ROBOT_H
#define __ROBOT_H

#include "servo.h"
#include "stepper.h"
#include "delay.h"
#define n 1

void  Dance(void);
void Forward(void);
void Backward(void);
void Shake(void);
void Turn_Right(void);
void Turn_Left(void);
void Head_Action(void);

#endif

