/*
 * counter.c
 *
 *  Created on: Dec 24, 2016
 *      Author: dell-pc
 */
#include "all.h"
unsigned int lastcount=0;
void initCounter(void)
{		
	EMIOS_0.CH[16].CCR.B.MODE = 0x13;	/* Mode is MCB *///？？？输入pwm
	EMIOS_0.CH[16].CCR.B.BSL = 0x3;	/* Use internal counter 这个是时基*/
	EMIOS_0.CH[16].CCR.B.UCPRE=0;	/* Set channel prescaler to divide by 1 */
	EMIOS_0.CH[16].CCR.B.UCPEN = 1;	/* Enable prescaler; uses default divide by 1 */
	//EMIOS_0.CH[16].CCR.B.FREN = 0;	/* Freeze channel counting when in debug mode */
	EMIOS_0.CH[16].CCR.B.EDPOL=1;	/* Edge Select rising edge */
	EMIOS_0.CH[16].CADR.R=0xffff; 
				/* (WORD)EMIOS_0.CH[24].CCNTR.R 数据寄存器 读那个方波的周期  他在不停地累加*/
	SIU.PCR[64].R = 0x0102; //检测脉冲 lsb  下拉电阻，限流吧，io口读一个方波
	SIU.PCR[65].R=0x0102;	//检测相位 dir   io口读一个高低电平
}
unsigned int  SpeedBekommen(void)
{
	unsigned int speed=0;
	if(EMIOS_0.CH[16].CCNTR.R<lastcount)		
	speed=EMIOS_0.CH[16].CCNTR.R-lastcount+65535;
	else speed=EMIOS_0.CH[16].CCNTR.R-lastcount;
	lastcount=EMIOS_0.CH[16].CCNTR.R;
	return(speed);
	if(speed<270) K=0.8;
	
	
}

unsigned char DirBekommen(void)
{
	return(SIU.GPDI[65].R);
}

