/******************************
Author:George Wang
Email: georgewang.7sl@gmail.com
Date:2017/11/07
Device:28BYJ-48
link: http://blog.csdn.net/qq_17280755/article/details/78459842
******************************/
#include "sys.h"
#include "delay.h"
#include "stepper.h"
//管脚接线
//IN4: PB6  d
//IN3: PB5  c
//IN2: PB4  b
//IN1: PB3   a
u8 phasecw[8] ={0x08,0x0c,0x04,0x06,0x02,0x03,0x01,0x09};// 逆时针
u8 phaseccw[8]={0x09,0x01,0x03,0x02,0x06,0x04,0x0c,0x08};// 顺时针

//引脚初始化
void Step_Motor_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14|GPIO_Pin_13|GPIO_Pin_12|GPIO_Pin_8|GPIO_Pin_7|GPIO_Pin_6|GPIO_Pin_5;
	GPIO_Init(GPIOB,&GPIO_InitStructure);	
}

void SetMotor(unsigned char InputData)
{
	if(InputData&0x01)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
	}
	else
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	}
	if(InputData&0x02)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_6);
	}
	else
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_6);
		
	}
	if(InputData&0x04)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_7);
	}
	else
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_7);
	}
	if(InputData&0x08)
	{
		GPIO_SetBits(GPIOB,GPIO_Pin_8);
	}
	else
	{
		GPIO_ResetBits(GPIOB,GPIO_Pin_8);
	}
}
/**************************************
******步距角5.625 减速比1/64
******360/5.625=64
******64*64个脉冲转一圈
******n:5.625的倍数
******position:方向
*************************************/
void motorNcircle(int n,u8 position)
{
	int i,j,k=0;
	for(j=0;j<n;j++)
	{
		//for(i=0;i<64*8;i++)
		for(i=0;i<8;i++)
		{
			for(k=0;k<8;k++)
			{
				if(1 == position)
				{
					SetMotor(phasecw[k]);
				}
				else
				{
					SetMotor(phaseccw[k]);
				}
				delay_ms(2);
			}
		}
	}
}

