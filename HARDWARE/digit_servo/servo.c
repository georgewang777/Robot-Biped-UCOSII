/******************************
Author:George Wang
Email: georgewang.7sl@gmail.com
Date:2017/11/07
Device:SR-1501 四路舵机
******************************/
#include "servo.h"
#include "timer.h"
#include "delay.h"
#include "usart.h"

u8 i=0;
u8 zhenzhen = 200;
u8 tim1 =10;
u8 Pulse1,Pulse2,Pulse3,Pulse4;

void Servo_Init(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	TIM_OCInitTypeDef  TIM_OCInitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOB , ENABLE); 
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_7 ; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1 ; 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_OD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period = 2000-1; 
	TIM_TimeBaseStructure.TIM_Prescaler =720-1; //72M/720=100k的计数频率，自动重装载为2000，那么PWM频率为100k/2000=50HZ，周期为20ms
	TIM_TimeBaseStructure.TIM_ClockDivision =0; 
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up; 
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
	
	//TIM3_CH1 PA6
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; 
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = Pulse1; 
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;      //TIM输出极性高
	TIM_OC1Init(TIM3, &TIM_OCInitStructure); 
	
	//TIM3_CH2  PA7
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = Pulse2; 
	TIM_OC2Init(TIM3, &TIM_OCInitStructure); 
	TIM_OC2PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	//TIM3_CH3   PB0
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //比较输出使能
	TIM_OCInitStructure.TIM_Pulse = Pulse3; 
	TIM_OC3Init(TIM3, &TIM_OCInitStructure); 
	TIM_OC3PreloadConfig(TIM3, TIM_OCPreload_Enable);
	
	//TIM3_CH4   PB1
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; 	//比较输出使能
	TIM_OCInitStructure.TIM_Pulse = Pulse4; 
	TIM_OC4Init(TIM3, &TIM_OCInitStructure); 
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);   					 //CH4预装载使能
	
	TIM_CtrlPWMOutputs(TIM3,ENABLE);                                						//MOE 主输出使能
	TIM_ARRPreloadConfig(TIM3, ENABLE); 													//使能TIM3在ARR上的预装载寄存器
	TIM_Cmd(TIM3, ENABLE);                       
}
//1号舵机
//compare: 50- 250  对应0.5ms--2.5ms
void Servo1(u32 compare)
{
	TIM_SetCompare1(TIM3,compare);
}

//2号舵机
void Servo2(u32 compare)
{
	TIM_SetCompare2(TIM3,compare);
}

//3号舵机
void Servo3(u32 compare)
{
	TIM_SetCompare3(TIM3,compare);
}

//4号舵机
void Servo4(u32 compare)
{
	TIM_SetCompare4(TIM3,compare);
}

/*************************************
----dir:0 顺时针-------
----dir:1 逆时针-------
************************************/
void Servo1_pos(u8 dir,u8 angle)
{
	for(i=0;i<angle;i++)
	{
		if(dir==0) {Pulse1 = Pulse1 + 1;}
		else {Pulse1 = Pulse1 -1;}
		Servo1(Pulse1);
		delay_ms(7);
	}
	//printf("beauty:%d",Pulse1);
}

void Servo2_pos(u8 dir,u8 angle)
{
	for(i=0;i<angle;i++)
	{
		if(dir==0) {Pulse2 = Pulse2 + 1;}
		else {Pulse2 = Pulse2 -1;}
		Servo2(Pulse2);
		delay_ms(7);
	}
	//printf("beauty:%d",Pulse2);
}

void Servo3_pos(u8 dir,u8 angle)
{
	for(i=0;i<angle;i++)
	{
		if(dir==0) {Pulse3 = Pulse3 - 1;}
		else {Pulse3 = Pulse3 +1;}
		Servo3(Pulse3);
		delay_ms(tim1);
	}
	printf("beauty:%d",Pulse3);
}

void Servo4_pos(u8 dir,u8 angle)
{
	for(i=0;i<angle;i++)
	{
		if(dir==0) {Pulse4 = Pulse4 -1;}
		else {Pulse4 = Pulse4 +1;}
		Servo4(Pulse4);
		delay_ms(tim1);
	}
}


