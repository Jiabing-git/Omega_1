/*
 * initPWM.c
 *
 *  Created on: Feb 21, 2017
 *      Author: apple
 */
#include "all.h"
void initPWM(void)
{EMIOS_0.MCR.B.GPRE= 63;   //GPRE+1=��Ƶϵ����/* Divide 80 MHz sysclk by 79+1 = 80 for 1MHz(0.1us) eMIOS clk*/
 EMIOS_0.MCR.B.GPREN = 1;	/* Enable eMIOS clock */
 EMIOS_0.MCR.B.GTBE = 1;   /* Enable global time base */
 EMIOS_0.MCR.B.FRZ = 1;    /* Enable stopping channels when in debug mode */
 
 EMIOS_0.CH[23].CCR.B.UCPRE=0;	/* Set channel prescaler to divide by 1+1 */
 EMIOS_0.CH[23].CCR.B.UCPEN = 1;	/* Enable prescaler; uses default divide by 1 *//*ucpren��*/
 EMIOS_0.CH[23].CCR.B.FREN = 1;	/* Freeze channel counting when in debug mode */
 EMIOS_0.CH[23].CADR.R = 200;	/* ��������200us 5KHZ *///??
 EMIOS_0.CH[23].CCR.B.MODE = 0x50;	/* Modulus Counter Buffered (MCB) */
 EMIOS_0.CH[23].CCR.B.BSL = 0x3;	/* Use internal counter */
 	
 EMIOS_0.CH[21].CCR.B.BSL = 0x0;	
 EMIOS_0.CH[21].CCR.B.MODE = 0x60;	
 EMIOS_0.CH[21].CCR.B.EDPOL = 1;	
 EMIOS_0.CH[21].CADR.R = 1;	
 EMIOS_0.CH[21].CBDR.R =0;
	
	SIU.PCR[69].R = 0x0600;	
	
 EMIOS_0.CH[19].CCR.B.BSL = 0x0;
 EMIOS_0.CH[19].CCR.B.MODE = 0x60;
 EMIOS_0.CH[19].CCR.B.EDPOL = 1;
 EMIOS_0.CH[19].CADR.R = 1;  
 EMIOS_0.CH[19].CBDR.R = 0;  
		
	SIU.PCR[67].R = 0x0600;
}
//63+1�����Ƶ��ɵ�1Mhz��internal counter�Ĳ���A�ģ�����AB bus����P534ҳ���ͼ�ģ�����
//B busͨ��ch0�ģ�ch0�õ���internal counter��1Mhz����pre����1������B����1Mhz�� Ȼ��ch0��Ҫ
//�ṩһ��20000�Ŀ�ȸ�ch4���һ��pwm����������  ����ch4��bsl����ѡ��bus B��Ϊý����ʱ�����ӡ�
