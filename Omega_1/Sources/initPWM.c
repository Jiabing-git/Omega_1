/*
 * initPWM.c
 *
 *  Created on: Feb 21, 2017
 *      Author: apple
 */
#include "all.h"
void initPWM(void)
{EMIOS_0.MCR.B.GPRE= 63;   //GPRE+1=分频系数；/* Divide 80 MHz sysclk by 79+1 = 80 for 1MHz(0.1us) eMIOS clk*/
 EMIOS_0.MCR.B.GPREN = 1;	/* Enable eMIOS clock */
 EMIOS_0.MCR.B.GTBE = 1;   /* Enable global time base */
 EMIOS_0.MCR.B.FRZ = 1;    /* Enable stopping channels when in debug mode */
 
 EMIOS_0.CH[23].CCR.B.UCPRE=0;	/* Set channel prescaler to divide by 1+1 */
 EMIOS_0.CH[23].CCR.B.UCPEN = 1;	/* Enable prescaler; uses default divide by 1 *//*ucpren？*/
 EMIOS_0.CH[23].CCR.B.FREN = 1;	/* Freeze channel counting when in debug mode */
 EMIOS_0.CH[23].CADR.R = 200;	/* 设置周期200us 5KHZ *///??
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
//63+1这个分频变成的1Mhz是internal counter的不是A的，至于AB bus根据P534页这个图改，比如
//B bus通过ch0改，ch0用的是internal counter（1Mhz），pre除以1，所以B还是1Mhz。 然后ch0还要
//提供一个20000的宽度给ch4输出一个pwm波做基础。  所以ch4的bsl必须选择bus B作为媒介与时基连接。
