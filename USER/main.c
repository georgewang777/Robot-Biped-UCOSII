#include "george_system.h"

extern u8 RxCount;    //Index
u8 Mk_UsartAll=0;	   //接收一组数据完成标志
u8 led_flag = 0;         //灯光开关标志位 1 开 0 关
/**************UCOSII任务设置************************/

//START 任务
#define START_TASK_PRIO      			10   //设置任务优先级 开始任务的优先级设置为最低
#define START_STK_SIZE  				64     //设置任务堆栈大小
OS_STK START_TASK_STK[START_STK_SIZE]; //任务堆栈	
void start_task(void *pdata);       	 //任务函数

//Robot任务
#define ROBOT_TASK_PRIO       		7    //设置任务优先级
#define ROBOT_STK_SIZE  		    	64   //设置任务堆栈大小
OS_STK ROBOT_TASK_STK[ROBOT_STK_SIZE]; //任务堆栈	
void robot_task(void *pdata);          //任务函数

//LED任务
#define LED_TASK_PRIO       			6     //设置任务优先级
#define LED_STK_SIZE  					64      //设置任务堆栈大小
OS_STK LED_TASK_STK[LED_STK_SIZE];      //任务堆栈
void led_task(void *pdata);             //任务函数

//OS_EVENT *msg_action;                   //行动邮件事件块指针
/*******************************************************/
int main(void)
{	
	Init();
	OSTaskCreate(start_task,(void *)0,(OS_STK *)&START_TASK_STK[START_STK_SIZE-1],START_TASK_PRIO );//创建起始任务
	OSStart();	  	 
}
 
//开始任务
void start_task(void *pdata)
{
	OS_CPU_SR cpu_sr=0;
	pdata = pdata; 
//	msg_action = OSMboxCreate((void*)0); //创建消息邮箱
	
	OS_ENTER_CRITICAL();			           //进入临界区(无法被中断打断)    
	OSTaskCreate(robot_task,(void *)0,(OS_STK*)&ROBOT_TASK_STK[ROBOT_STK_SIZE-1],ROBOT_TASK_PRIO);						   
	OSTaskCreate(led_task,(void *)0,(OS_STK*)&LED_TASK_STK[LED_STK_SIZE-1],LED_TASK_PRIO);	 				   
	OSTaskSuspend(START_TASK_PRIO);	    //挂起起始任务.
	OS_EXIT_CRITICAL();				          //退出临界区(可以被中断打断)
}

//robot任务
void robot_task(void *pdata)
{	 	
	while(1)
	{
		if(Mk_UsartAll==1)              //接收到数据
		{
			Mk_UsartAll=0;
			RxCount=0;
			UsartRace_Data();             //处理接收到的数据
			OSTaskResume(LED_TASK_PRIO);	//恢复LED任务，LED恢复闪烁
			//process();                    //机器人进程
			ClearUart2();
			//Clear_TM1624();
		}
		OSTaskSuspend(LED_TASK_PRIO);   //挂起LED任务，LED停止闪烁
		//delay_ms(10);
	};
}

//LED任务
void led_task(void *pdata)
{	  
	while(1)
	{
		Tm1624_Display2();
	}
//	u8 led_enable;
//	u8 err;
//	while(1)
//	{
//		led_enable = (u8)OSMboxPend(msg_action,10,&err); //接收消息
//		if(led_enable)
//		{
//			Tm1624_Display1();  //灯光效果
//		}
//	};
}







