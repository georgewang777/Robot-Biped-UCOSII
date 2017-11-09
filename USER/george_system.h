#ifndef __GEORGE_SYSTEM_H
#define __GEORGE_SYSTEM_H

#include "timer.h"
#include "usart.h"
#include "usart2.h"
#include "sys.h"
#include "delay.h"
#include "servo.h"
#include "stepper.h"
#include "tm1624.h"
#include "robot.h"
#include "wkup.h"
#include "led.h"
#include "includes.h"



void Init(void);    //系统初始化函数

void process(void); //Robot进程

#endif
