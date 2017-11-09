#ifndef __USART3_H
#define __USART3_H
#include "stdio.h"

void    WriteUsartBuff3(char ch);
void uart2_init(u32 bound);
void ClearUart2(void) ;
void USART2_Puts(char * str);
void UsartRace_Data(void);
int strcmp_str(char *str1,char *str2,int count);
#endif

