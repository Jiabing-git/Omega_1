/*
 * ADC.c
 *
 *  Created on: Jan 22, 2017
 *      Author: apple
 */
#include "all.h"
void initADC(void)
{
	//ADC.MCR.R = 0x00000100;          /* Conversion times for 80MHz ADClock */
	//ADC.NCMR[1].R = 0x0000007f;     /* Select ANS0 inputs for conversion */
	//ADC.CTR[1].R = 0x00008606;      /* Conversion times for 32MHz ADClock */
	//ADC.MCR.B.NSTART=1;             /* Trigger normal conversions for ADC0 */
	//SIU.PCR[24].R = 0x2000;         /* MPC56xxB: Initialize PB[8] as ANS0 */
	//SIU.PCR[25].R = 0x2000;         /* MPC56xxB: Initialize PB[9] as ANS1 */
    //ADC.MCR.B.NSTART=1;             /* Trigger normal conversions for ADC0 */
	         
  	//SIU.PCR[62].R = 0x2000;D14
  	//SIU.PCR[61].R = 0x2000;D13
  	SIU.PCR[27].R = 0x2000;             //B11
  	SIU.PCR[28].R = 0x2000;             //B12
  	SIU.PCR[29].R = 0x2000;             //B13
  	SIU.PCR[30].R = 0x2000;             //B14
  	SIU.PCR[31].R = 0x2000;             //B15
  	SIU.PCR[21].R = 0x2000;             //B5
  	SIU.PCR[23].R = 0x2000;             //B7
  	SIU.PCR[58].R = 0x2000;             //D10
    ADC.MCR.R     = 0x20000000;      //初始化ADC为扫描模式，时钟为32MHz。
    ADC.NCMR[0].R = 0x0000400a;        
    ADC.CTR[0].R  = 0x00008606;
    ADC.NCMR[1].R = 0x0000000f;        
    ADC.CTR[1].R  = 0x00008606;
    ADC.NCMR[2].R = 0x01010101;        
    ADC.CTR[2].R  = 0x00008606;  //P622 ctr
  
    ADC.MCR.B.NSTART = 1;                 //启动AD转换
}//Frage:Was ist d** "preferred Vcc"?5V oder 3.3V?


