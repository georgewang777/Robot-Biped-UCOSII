#include "robot.h"

void  Dance(void)
{
	u8 j;
	for(j=0;j<5;j++)
	{
		Servo3_pos(1,30);
		Servo4_pos(0,30);
		delay_ms(50);
		Servo3_pos(0,30);
		Servo4_pos(1,30);
	}
}

void Forward(void)
{
	int k = 0;
	Servo4_pos(0,30);
	delay_ms(n);
	Servo3_pos(0,30);
	delay_ms(n);
	Servo2_pos(1,20);
	delay_ms(n);
	Servo1_pos(1,20);
	delay_ms(n);
	Servo3_pos(1,30);
	delay_ms(n);
	Servo4_pos(1,30);
	
	for(k=0;k<5;k++)
	{
		Servo3_pos(1,30);
		delay_ms(n);
		Servo4_pos(1,30);
		delay_ms(n);
		Servo1_pos(0,30);
		delay_ms(n);
		Servo2_pos(0,30);
		delay_ms(n);
		Servo4_pos(0,30);
		delay_ms(n);
		Servo3_pos(0,30);
		delay_ms(n);
		
		Servo4_pos(0,30);
		delay_ms(n);
		Servo3_pos(0,30);
		delay_ms(n);
		Servo2_pos(1,30);
		delay_ms(n);
		Servo1_pos(1,30);
		delay_ms(n);
		Servo3_pos(1,30);
		delay_ms(n);
		Servo4_pos(1,30);
		delay_ms(n);
	}
	Servo2_pos(0,20);
	delay_ms(n);
	Servo1_pos(0,20);
	delay_ms(n);
}
void Backward(void)
{
	int k = 0;
	Servo3_pos(1,30);
	delay_ms(n);
	Servo4_pos(1,30);
	delay_ms(n);
	Servo1_pos(1,20);
	delay_ms(n);
	Servo2_pos(1,20);
	delay_ms(n);
	Servo4_pos(0,30);
	delay_ms(n);
	Servo3_pos(0,30);
	
	for(k=0;k<5;k++)
	{
		Servo4_pos(0,30);
		delay_ms(n);
		Servo3_pos(0,30);
		delay_ms(n);
		Servo2_pos(0,30);
		delay_ms(n);
		Servo1_pos(0,30);
		delay_ms(n);
		Servo3_pos(1,30);
		delay_ms(n);
		Servo4_pos(1,30);
		delay_ms(n);
		
		Servo3_pos(1,30);
		delay_ms(n);
		Servo4_pos(1,30);
		delay_ms(n);
		Servo1_pos(1,30);
		delay_ms(n);
		Servo2_pos(1,30);
		delay_ms(n);
		Servo4_pos(0,30);
		delay_ms(n);
		Servo3_pos(0,30);
		delay_ms(n);
	}
	Servo1_pos(0,20);
	delay_ms(n);
	Servo2_pos(0,20);
	delay_ms(n);
}
void Shake(void)
{
	u8 k=0;
	Servo4_pos(0,20);
	delay_ms(n);
	Servo3_pos(0,20);
	delay_ms(n);
	Servo1_pos(0,20);
	delay_ms(n);
	for(k=0;k<10;k++)
	{
		Servo1_pos(1,40);
		delay_ms(n);
		Servo1_pos(0,40);
		delay_ms(n);
	}
	Servo1_pos(1,20);
	delay_ms(n);
	Servo4_pos(1,20);
	delay_ms(n);
	Servo3_pos(1,20);
	delay_ms(2000);
	
	Servo3_pos(1,20);
	delay_ms(n);
	Servo4_pos(1,20);
	delay_ms(n);
	Servo2_pos(0,20);
	delay_ms(n);
	for(k=0;k<10;k++)
	{
		Servo2_pos(1,40);
		delay_ms(n);
		Servo2_pos(0,40);
		delay_ms(n);
	}
	Servo2_pos(1,20);
	delay_ms(n);
	Servo4_pos(0,20);
	delay_ms(n);
	Servo3_pos(0,20);
	delay_ms(n);
}

void Turn_Right(void)
{
	u8 i =0;
	for(i=0;i<3;i++)
	{
		Servo3_pos(1,30);
		delay_ms(n);
		Servo4_pos(1,30);
		delay_ms(n);
		Servo2_pos(1,20);
		delay_ms(n);
		Servo4_pos(0,30);
		delay_ms(n);
		Servo3_pos(0,30);
		
		Servo4_pos(0,30);
		delay_ms(n);
		Servo3_pos(0,30);
		delay_ms(n);
		Servo2_pos(0,20);
		delay_ms(n);
		Servo3_pos(1,30);
		delay_ms(n);
		Servo4_pos(1,30);
		delay_ms(n);
	 }
	
}

void Turn_Left(void)
{
	u8 i =0;
	for(i=0;i<3;i++)
	{
		Servo4_pos(0,30);
		delay_ms(n);
		Servo3_pos(0,30);
		delay_ms(n);
		Servo1_pos(0,20);
		delay_ms(n);
		Servo3_pos(1,30);
		delay_ms(n);
		Servo4_pos(1,30);
		
		Servo3_pos(1,30);
		delay_ms(n);
		Servo4_pos(1,30);
		delay_ms(n);
		Servo1_pos(1,20);
		delay_ms(n);
		Servo4_pos(0,30);
		delay_ms(n);
		Servo3_pos(0,30);
		delay_ms(n);
	}
	
}

//机器人头部运动
void Head_Action(void)
{
	u8 i;
	motorNcircle(2,1);
	delay_ms(500);
	for(i=0;i<10;i++)
	{
		motorNcircle(4,0);
		delay_ms(100);
		motorNcircle(4,1);
		delay_ms(100);
	}
	motorNcircle(2,0);
}
