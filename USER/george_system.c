#include "george_system.h"
extern u8 Pulse1,Pulse2,Pulse3,Pulse4;
u8 status;

void Init(void)
{
	SystemInit();          //配置系统时钟为72M
	delay_init();	    	 //延时函数初始化	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置中断优先级分组为组2：2位抢占优先级，2位响应优先级
	uart_init(115200);
	uart2_init(115200);
	Pulse1 = 140;
	Pulse2 = 130;
	Pulse3 = 150;
	Pulse4 = 130;
  TIM2_Int_Init(50-1,7200-1);//定时器时钟72M，分频系数7200，所以72M/7200=10Khz的计数频率，计数50次为5ms  
  Servo_Init();  
	Step_Motor_GPIO_Init();
	Tm1624_Init();
	//WKUP_Init();              //待机唤醒
	OSInit();
}

void process(void)
{
	switch(status)
	{
		case 1: Forward();break;    //前进
		case 2: Backward();break;   //后退
		case 3: Turn_Right();break; //右转
		case 4: Turn_Left();break;  //左转
		case 5: Dance();    break;  //跳舞
		case 6: Shake();    break;  //摇摆
		case 7: Head_Action();break;//头部
		default: status = 0;break;
	}
}
