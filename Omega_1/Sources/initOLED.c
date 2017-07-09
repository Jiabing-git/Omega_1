/*
 * initOLED.c
 *
 *  Created on: Aug 25, 2016
 *      Author: dell-pc
 */
#include "all.h"


void initOLED(void)
{
	SIU.PCR[5].R = 0x0203;  
	SIU.PCR[66].R = 0x0203;  
	SIU.PCR[35].R = 0x0203;  
	SIU.PCR[68].R = 0x0203;  
	SIU.PCR[37].R = 0x0203;  
}
