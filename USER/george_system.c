#include "george_system.h"
extern u8 Pulse1,Pulse2,Pulse3,Pulse4;
u8 status;

void Init(void)
{
	SystemInit();          //����ϵͳʱ��Ϊ72M
	delay_init();	    	 //��ʱ������ʼ��	  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	uart_init(115200);
	uart2_init(115200);
	Pulse1 = 140;
	Pulse2 = 130;
	Pulse3 = 150;
	Pulse4 = 130;
  TIM2_Int_Init(50-1,7200-1);//��ʱ��ʱ��72M����Ƶϵ��7200������72M/7200=10Khz�ļ���Ƶ�ʣ�����50��Ϊ5ms  
  Servo_Init();  
	Step_Motor_GPIO_Init();
	Tm1624_Init();
	//WKUP_Init();              //��������
	OSInit();
}

void process(void)
{
	switch(status)
	{
		case 1: Forward();break;    //ǰ��
		case 2: Backward();break;   //����
		case 3: Turn_Right();break; //��ת
		case 4: Turn_Left();break;  //��ת
		case 5: Dance();    break;  //����
		case 6: Shake();    break;  //ҡ��
		case 7: Head_Action();break;//ͷ��
		default: status = 0;break;
	}
}
