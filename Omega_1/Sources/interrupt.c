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
	{                                 //PIT02msec中断立controlflag  PIT1速度反馈2ms一个控制周期
	                           	       // NOTE:  DIVIDER FROM SYSCLK TO PIT ASSUMES DEFAULT DIVIDE BY 1 
	  PIT.PITMCR.R = 0x00000001;       // Enable PIT and configure timers to stop in debug mode 
	  PIT.CH[0].LDVAL.R = 12800;        //0.2ms
	  PIT.CH[0].TCTRL.R = 0X00000003;    //Enable PIT0 interrupt and make PIT active to count 
	  
	  //PIT.CH[1].LDVAL.R = 800000;      // PIT1 timeout = 800000 sysclks x 1sec/80M sysclks = 10msec 
	  //PIT.CH[1].TCTRL.R = 0x00000003; // Enable PIT1 interrupt and make PIT active to count 
	  
	 // PIT.CH[2].LDVAL.R =320000000;    //设置计数值为32000000
	 // PIT.CH[2].TCTRL.R = 0x000000003; //使能PIT2计数，并使能中断
	  
	  INTC_InstallINTCInterruptHandler(Check,59,1); //这一句如何知道进入的是哪一个中断？
	 // INTC_InstallINTCInterruptHandler(Pit1ISR,60,2);
	}
