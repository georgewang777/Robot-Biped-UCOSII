#include "george_system.h"

extern u8 RxCount;    //Index
u8 Mk_UsartAll=0;	   //����һ��������ɱ�־

/**************UCOSII��������************************/

//START ����
#define START_TASK_PRIO      			10   //�����������ȼ� ��ʼ��������ȼ�����Ϊ���
#define START_STK_SIZE  				64     //���������ջ��С
OS_STK START_TASK_STK[START_STK_SIZE]; //�����ջ	
void start_task(void *pdata);       	 //������

//Robot����
#define ROBOT_TASK_PRIO       		7    //�����������ȼ�
#define ROBOT_STK_SIZE  		    	64   //���������ջ��С
OS_STK ROBOT_TASK_STK[ROBOT_STK_SIZE]; //�����ջ	
void robot_task(void *pdata);          //������

//LED����
#define LED_TASK_PRIO       			6     //�����������ȼ�
#define LED_STK_SIZE  					64      //���������ջ��С
OS_STK LED_TASK_STK[LED_STK_SIZE];      //�����ջ
void led_task(void *pdata);             //������

/*******************************************************/
int main(void)
{	
	Init();
	OSTaskCreate(start_task,(void *)0,(OS_STK *)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO );//������ʼ����
	OSStart();	  	 
}
 
//��ʼ����
void start_task(void *pdata)
{
	OS_CPU_SR cpu_sr=0;
	pdata = pdata; 
	OS_ENTER_CRITICAL();			//�����ٽ���(�޷����жϴ��)    
	OSTaskCreate(robot_task,(void *)0,(OS_STK*)&ROBOT_TASK_STK[ROBOT_STK_SIZE-1],ROBOT_TASK_PRIO);						   
	OSTaskCreate(led_task,(void *)0,(OS_STK*)&LED_TASK_STK[LED_STK_SIZE-1],LED_TASK_PRIO);	 				   
	OSTaskSuspend(START_TASK_PRIO);	//������ʼ����.
	OS_EXIT_CRITICAL();				//�˳��ٽ���(���Ա��жϴ��)
}

//robot����
void robot_task(void *pdata)
{	 	
	while(1)
	{
		if(Mk_UsartAll==1) //���յ�����
		{
			Mk_UsartAll=0;
			RxCount=0;
			UsartRace_Data();//������յ�������
			process();       //�����˽���
			ClearUart2();
		}
	};
}

//LED����
void led_task(void *pdata)
{	  
	while(1)
	{
		Tm1624_Dispaly();  //�ƹ�Ч��
	};
}







