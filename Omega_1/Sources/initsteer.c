/*
 * initsteer.c
 *
 *  Created on: Feb 21, 2017
 *      Author: apple
 */
#include "all.h"
void initSteer(void)   
{      	/**********���PWM 50HZ A4�����40000*7.5%=3000��λ**********/
	    //eMIOS0 Bͨ��0����/* EMIOS 0 CH 0: Modulus Counter */
	    EMIOS_0.CH[0].CCR.B.UCPRE=0;	    /* Set channel prescaler to divide by 1 */
		EMIOS_0.CH[0].CCR.B.UCPEN = 1;   /* Enable prescaler; uses default divide by 1 */
		EMIOS_0.CH[0].CCR.B.FREN = 1; 	/* Freeze channel counting when in debug mode */
		EMIOS_0.CH[0].CADR.R =20000;/********��������20ms  50HZ*******/
		EMIOS_0.CH[0].CCR.B.MODE = 0x50; /* Modulus Counter Buffered (MCB) */
		EMIOS_0.CH[0].CCR.B.BSL = 0x3;	/* Use internal counter */
		
		
	    /* EMIOS 0 CH 4: Output Pulse Width Modulation */
		EMIOS_0.CH[4].CCR.B.BSL = 0x1;	/* Use counter bus B (default) */
		EMIOS_0.CH[4].CCR.B.MODE = 0x60; /* Mode is OPWM Buffered */  
	    EMIOS_0.CH[4].CCR.B.EDPOL = 1;	/* Polarity-leading edge sets output/trailing clears*/
		EMIOS_0.CH[4].CADR.R = 1;//��ռ�ձ�/* Leading edge when channel counter bus=250*/
		EMIOS_0.CH[4].CBDR.R = 1815;//1818;//1568;//1585links 2085rechts            /* Trailing edge when channel counter bus=500*/
		SIU.PCR[4].R = 0x0600;    //[11:10]ѡ��AFx �˴�AF1   A4�ڶ�����

		
}


