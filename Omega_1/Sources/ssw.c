/*
 * ssw.c
 *
 *  Created on: Feb 22, 2017
 *      Author: dell-pc
 */
//This file contributes to distance measurement by super sound wave.
#include "all.h"
unsigned int time1=0,time2=0,time_delta=0,time_delta_old=0;
unsigned char out_of_sight=0;
unsigned char BT_active=0;
unsigned int safe_distance=2500;
unsigned char Slowdown=0;

void initSSW()
{

	  EMIOS_0.CH[3].CCR.B.BSL = 0x1;				/* Use counter bus B,C,D,or E */
	  EMIOS_0.CH[3].CCR.B.EDPOL = 1;			/* Polarity-leading edge sets output/trailing clears*/
	  EMIOS_0.CH[3].CCR.B.EDSEL = 1;				/* Both edges triggering*/
	  EMIOS_0.CH[3].CCR.B.FCK = 1;	    			/* Input filter bit clock reference is the system clock*/
	  EMIOS_0.CH[3].CCR.B.IF = 1;				    /* Input filter bit of 2 clock cycles*/ 
	  EMIOS_0.CH[3].CCR.B.MODE = 0b0000100; 		/* Mode is IPWM Input Pulse Width Measurement */
	  EMIOS_0.CH[3].CCR.B.FREN = 1;	    			/* Freeze channel counting when in debug mode */
	  EMIOS_0.CH[3].CCR.B.DMA = 0;	  				/* Flag/overrun assigned to interrupt request instead of CTU*/
	  EMIOS_0.CH[3].CCR.B.FEN = 0;	    			/* Enables Unified Channel FLAG bit to generate an interrupt signal*/
	 
	  SIU.PCR[3].B.PA = 1;            			    /* Selects eMIOS path as alternative mode 3 for input signal */
	  SIU.PCR[3].B.IBE = 1;    
	  SIU.PCR[8].R = 0x0203;/* Input buffer of the pad is enabled */
	  SIU.GPDO[8].B.PDO=1;
}

void SSW_Dis(void)
{
	unsigned int i;

	if(EMIOS_0.CH[3].CSR.B.FLAG==1)
	{	
		time2=EMIOS_0.CH[3].CBDR.R;
		time1=EMIOS_0.CH[3].CADR.R;    
		
		time_delta =EMIOS_0.CH[3].CADR.R-EMIOS_0.CH[3].CBDR.R;	/*Pulse width by subtracting the value in B1 from A2*/
		
		if(time2>time1)
			time_delta=time1+20000-time2;
		else
			time_delta=time1-time2;
		if(time_delta>5000)
		{ 
			out_of_sight=1;
			time_delta=5000;
		}
		else
		{ 
			out_of_sight=0; 
		}
		if(time_delta<safe_distance&&time_delta!=0)
			Slowdown=1;
		else
			Slowdown=0;
		if(time_delta==time_delta_old)
			Slowdown=0;
		EMIOS_0.CH[3].CSR.B.FLAG = 1;											/*Clear Flag*/
	}

}

