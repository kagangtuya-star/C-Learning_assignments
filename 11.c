#include "reg52.h"

#include<stdio.h>
#include <intrins.h>//使用延时函数需要加这个头文件
typedef unsigned int u16;
	
void Delay1000ms()		//@12.000MHz
{
	unsigned char i, j, k;

	_nop_();
	_nop_();
	i = 61;
	j = 225;
	k = 62;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void UsartInit()
{
	SCON=0X50;			//设置为工作方式1
	TMOD=0X20;			//设置计数器工作方式2
	PCON=0X80;			//波特率加倍
	TH1=0XF3;				//计数器初始值设置，注意波特率是4800的
	TL1=0XF3;
	ES=1;						//打开接收中断
	EA=1;						//打开总中断
	TR1=1;					//打开计数器
}

/*******************************************************************************
* 函 数 名       : main
* 函数功能		 : 主函数
* 输    入       : 无
* 输    出    	 : 无
*******************************************************************************/
void main()
{	
	u16 i;
	i = 0;
	
	UsartInit();
	while(1){
	i++;
	TI=1;                              //printf将T1置为1
  	printf("%d Hello Worid!\n", i);
	Delay1000ms();
	while(!TI);
  TI=0;}
}