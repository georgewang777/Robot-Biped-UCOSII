#ifndef   __TM1624_H
#define	__TM1624_H

#include "stm32f10x.h"
void TM1624_Write(u8 wr_data);
void Write_Com(u8 cmd);
void Clear_TM1624(void);
void Tm1624_Init(void);
void Tm1624_Display1(void);
void Tm1624_Display2(void);
#endif

