#include "reg52.h"

#include<stdio.h>
#include <intrins.h>//ʹ����ʱ������Ҫ�����ͷ�ļ�
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
	SCON=0X50;			//����Ϊ������ʽ1
	TMOD=0X20;			//���ü�����������ʽ2
	PCON=0X80;			//�����ʼӱ�
	TH1=0XF3;				//��������ʼֵ���ã�ע�Ⲩ������4800��
	TL1=0XF3;
	ES=1;						//�򿪽����ж�
	EA=1;						//�����ж�
	TR1=1;					//�򿪼�����
}

/*******************************************************************************
* �� �� ��       : main
* ��������		 : ������
* ��    ��       : ��
* ��    ��    	 : ��
*******************************************************************************/
void main()
{	
	u16 i;
	i = 0;
	
	UsartInit();
	while(1){
	i++;
	TI=1;                              //printf��T1��Ϊ1
  	printf("%d Hello Worid!\n", i);
	Delay1000ms();
	while(!TI);
  TI=0;}
}