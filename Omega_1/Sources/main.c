#include "all.h"

unsigned char SpeedControl_Flag=0;
unsigned char DirectionControl_Flag=0; 
unsigned char ADC_Flag=1;
unsigned char BlueTooth_Flag=0;
unsigned char Press_Flag=1;

int main(void) 
      {
    disableWatchdog();
  	initModesAndClock();
  	initPWM();
  	initADC(); 
  	initPress();
  	initLINFlex_0_UART();
  	LINFlex0_init();
    initOLED();
    OLED_Init();			//³õÊ¼»¯OLED  
    OLED_Clear();
    initSteer();
    initCounter();
    initSSW();
    
    initPIT();
    enableIrq();
  /* Loop forever */
  for (;;) 
  {  // MaxBekommen();
	  //state=LINFlex_RX();
	  if(BT_active)
	  {
		  state=LINFlex_RX();
		  if(state>80&&state<100)
		  {
			  start=1;
			  BT_active=0;
		  }
	  }
	  if(!press5&&!press4)
		  {Press_Flag=0;
	      OLED_Clear();}
	  if(!press5&&!press3)
		  Press_Flag=1;
  } 
}



