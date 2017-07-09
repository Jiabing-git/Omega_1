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
	EMIOS_0.CH[16].CCR.B.MODE = 0x13;	/* Mode is MCB *///����������pwm
	EMIOS_0.CH[16].CCR.B.BSL = 0x3;	/* Use internal counter �����ʱ��*/
	EMIOS_0.CH[16].CCR.B.UCPRE=0;	/* Set channel prescaler to divide by 1 */
	EMIOS_0.CH[16].CCR.B.UCPEN = 1;	/* Enable prescaler; uses default divide by 1 */
	//EMIOS_0.CH[16].CCR.B.FREN = 0;	/* Freeze channel counting when in debug mode */
	EMIOS_0.CH[16].CCR.B.EDPOL=1;	/* Edge Select rising edge */
	EMIOS_0.CH[16].CADR.R=0xffff; 
				/* (WORD)EMIOS_0.CH[24].CCNTR.R ���ݼĴ��� ���Ǹ�����������  ���ڲ�ͣ���ۼ�*/
	SIU.PCR[64].R = 0x0102; //������� lsb  �������裬�����ɣ�io�ڶ�һ������
	SIU.PCR[65].R=0x0102;	//�����λ dir   io�ڶ�һ���ߵ͵�ƽ
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

