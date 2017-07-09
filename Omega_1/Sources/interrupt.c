/*
 * interrupt.c
 *
 *  Created on: Jan 21, 2017
 *      Author: dell-pc
 */

#include "all.h"
void enableIrq(void) 
{
	  INTC.CPR.B.PRI = 0;          /* Single Core: Lower INTC's current priority */
	  asm(" wrteei 1");	    	   /* Enable external interrupts */
}
void initPIT(void) 
	{                                 //PIT02msec�ж���controlflag  PIT1�ٶȷ���2msһ����������
	                           	       // NOTE:  DIVIDER FROM SYSCLK TO PIT ASSUMES DEFAULT DIVIDE BY 1 
	  PIT.PITMCR.R = 0x00000001;       // Enable PIT and configure timers to stop in debug mode 
	  PIT.CH[0].LDVAL.R = 12800;        //0.2ms
	  PIT.CH[0].TCTRL.R = 0X00000003;    //Enable PIT0 interrupt and make PIT active to count 
	  
	  //PIT.CH[1].LDVAL.R = 800000;      // PIT1 timeout = 800000 sysclks x 1sec/80M sysclks = 10msec 
	  //PIT.CH[1].TCTRL.R = 0x00000003; // Enable PIT1 interrupt and make PIT active to count 
	  
	 // PIT.CH[2].LDVAL.R =320000000;    //���ü���ֵΪ32000000
	 // PIT.CH[2].TCTRL.R = 0x000000003; //ʹ��PIT2��������ʹ���ж�
	  
	  INTC_InstallINTCInterruptHandler(Check,59,1); //��һ�����֪�����������һ���жϣ�
	 // INTC_InstallINTCInterruptHandler(Pit1ISR,60,2);
	}
