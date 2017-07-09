/*
 * initPress.c
 *
 *  Created on: Jan 22, 2017
 *      Author: apple
 */
#include "all.h"
void initPress()
{
	SIU.PCR[2].R = 0x0103;  
	SIU.PCR[1].R = 0x0103;  
	SIU.PCR[72].R = 0x0103;  
	SIU.PCR[74].R = 0x0103;
	SIU.PCR[75].R = 0x0103;
}



