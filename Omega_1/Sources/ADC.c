/*
 * ADC.c
 *
 *  Created on: Sep 12, 2016
 *      Author: dell-pc
 */

#include "all.h"
//6 5 2 1
float L1=0,L2=0,L3=0,L4=0,L5=0,L6=0,L7=0,L8=0;
//int max1=310,max2=310,max3=310,max4=410,max5=350;
int max1=320,max2=320,max3=320,max4=320,max5=320;
void AD_Bekommen(void)
{
	unsigned int x;
	while(ADC.CDR[88].B.VALID != 1); //这个序号是page592对应的序号，是adc的序号不是pcr
	//while(ADC.CDR[38].B.VALID != 1);          
	x = (unsigned int)ADC.CDR[35].B.CDATA;
	L5=x;
	//while(ADC.CDR[37].B.VALID != 1);    
	x = (unsigned int)ADC.CDR[14].B.CDATA;
	L6=x;
	//while(ADC.CDR[35].B.VALID != 1);    
	x=	(unsigned int)ADC.CDR[88].B.CDATA;
	L1=x;
	//while(ADC.CDR[64].B.VALID != 1);    
	x=	(unsigned int)ADC.CDR[64].B.CDATA;
	L4=x;
	//while(ADC.CDR[72].B.VALID != 1);    
	x=	(unsigned int)ADC.CDR[72].B.CDATA;
    L3=x;
	//while(ADC.CDR[80].B.VALID != 1);    
	x=	(unsigned int)ADC.CDR[80].B.CDATA;
	L2=x;
	//while(ADC.CDR[88].B.VALID != 1);    
	x=	(unsigned int)ADC.CDR[3].B.CDATA;
	L7=x;
	//while(ADC.CDR[1].B.VALID != 1);    
	x=	(unsigned int)ADC.CDR[1].B.CDATA;
	L8=x;
}
void operationL(void)
{ L1=L1/max1*400;
  L2=L2/max2*400;
  L3=L3/max3*400;
  L4=L4/max4*400;
  L5=L5/max5*400;
}
 
void MaxBekommen(void)
 { AD_Bekommen();
   if(L1>max1)
   { max1=L1;
     //dat18=L8;
   }
   if(L3>max3)
 	   {max3=L3;
       //dat34=L4;
  	   //dat38=L8;
 	   }
   if(L4>max4)
 	   {max4=L4;
       //dat43=L3;
 	   }
   if(L2>max2)
   {max2=L2;
         //dat43=L3;
   	   }
   if(L5>max5)
 	   {max5=L5;
       //dat81=L1;
   	   //dat83=L3;
 	   }
 }


