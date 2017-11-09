#include "tm1624.h"
#include "delay.h"

#define DIO_H   GPIO_SetBits(GPIOB,GPIO_Pin_12)
#define DIO_L    GPIO_ResetBits(GPIOB,GPIO_Pin_12)
#define CLK_H   GPIO_SetBits(GPIOB,GPIO_Pin_13)
#define CLK_L    GPIO_ResetBits(GPIOB,GPIO_Pin_13)
#define STB_H   GPIO_SetBits(GPIOB,GPIO_Pin_14)
#define STB_L    GPIO_ResetBits(GPIOB,GPIO_Pin_14)

void TM1624_Write(u8 wr_data)
{
    u8 i;
    STB_L;                     
    
    for(i=0;i<8;i++)
    {
        CLK_L;
        if(wr_data&0x01)
        {
           DIO_H;
        } else
        {
            DIO_L;
        }
        CLK_H;
        wr_data>>=1;
    }
		CLK_L;
		DIO_L;
}
 //发送命令字        
void Write_Com(u8 cmd)                  
{
    STB_L;
    TM1624_Write(cmd);
    STB_H;
    delay_ms(2);
}

void Clear_TM1624(void)
{
   u8 i;
	 Write_Com(0x40); 
   STB_L;
   TM1624_Write(0xc0);              
   for(i=0;i<16;i++)
   TM1624_Write(0x00);                
   STB_H;
}

void Tm1624_Init(void)
{
	CLK_H;                              
	STB_H;                              
	DIO_H;        
  Write_Com(0x89);    //最亮   10001111 设置消光脉冲14/16 显示开 	
	//Write_Com(0x03);  //设置显示模式：7位11段        
	//Write_Com(0x40);    //设置数据命令，采用地址自动加一模式
	Clear_TM1624();    
//	Write_Com(0x44);    //固定地址
	delay_ms(100);
}

void Tm1624_Dispaly(void)
{
	u8 i,j;
	u16 k= 200;
	Write_Com(0x44);    //固定地址
	for(j=0;j<8;j++)
	{
		STB_L;
		TM1624_Write(0xc0+2*j);              
		for(i=0;i<9;i++)
		{
			TM1624_Write(1<<i);
			delay_ms(k);
		}	
		STB_H;
		delay_ms(20);
	}
}
