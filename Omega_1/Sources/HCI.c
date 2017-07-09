/*
 * HCI.c
 *
 *  Created on: Aug 28, 2016
 *      Author: dell-pc
 */

#include "all.h"

void Dis_Page1(char j,int f);
void Dis_Page2(char j,int f);
void Dis_Page3(char j,int f);
void Dis_Page4(char j,int f);
char Page=1;
char Itm=0;

void HCI(void)
{
	OLED_Clear();
	
	if(!PgUp)
		Page++;
	if(!ItmDn)
		Itm++;
	if(!ItmUp)
	{
		if(Itm==0)
			Itm=3;
		else
			Itm--;
	}
		

	if(Page>4)
		Page=1;
	if(Itm>3)
		Itm=0;


	
	if(!ValUp)
	{
		if(Page==1)
		{
			if(Itm==0)
				eins+=10;
			if(Itm==1)
				zwei+=10;
			if(Itm==2)
				drei+=10;
			if(Itm==3)
				vier*=-1;
		}
		if(Page==2)
		{
			if(Itm==0)
				einss+=5;
			if(Itm==1)
				zweii+=5;
			if(Itm==2)
				dreii+=5;
			if(Itm==3)
				vierr+=5;
				//vierr;
		}
		if(Page==3)
		{
		  if(Itm==0)
			 einsss*=-1;
		  if(Itm==1)
			 zweiii+=20;
		  if(Itm==2)
			 dreiii+=20;
		  if(Itm==3)
			 vierrr+=20;
		}
		if(Page==4)
		{
		  if(Itm==0)
			 einssss+=1;
		  if(Itm==1)
			 zweiiii+=5;
		  if(Itm==2)
			 dreiiii+=5;
		  if(Itm==3);
			 vierrrr+=5;
		}
	}
	if(!ValDn)
	{
		if(Page==1)
		{
			if(Itm==0)
				eins-=10;
		    if(Itm==1)
				zwei-=10;
			if(Itm==2)
				drei-=10;
			if(Itm==3)
				vier-=10;
		}
		if(Page==2)
		{
			if(Itm==0)
				einss-=5;
			if(Itm==1)
				zweii-=5;
			if(Itm==2)
				dreii-=5;
			if(Itm==3)
				vierr-=5;
		}
		if(Page==3)
		{
		  if(Itm==0)
			 einsss-=20;
		  if(Itm==1)
			 zweiii-=20;
		  if(Itm==2)
			 dreiii-=1;
		  if(Itm==3)
			 vierrr-=20;
		}
		if(Page==4)
		{
		  if(Itm==0)
			 einssss-=1;
		  if(Itm==1)
			 zweiiii-=5;
		  if(Itm==2)
			 dreiiii-=5;
		  if(Itm==3);
			 vierrrr-=5;
		}
	}
	if(Page==1)
		Dis_Page1(Itm,1);
	if(Page==2)
		Dis_Page2(Itm,1);
    if(Page==3)
	    Dis_Page3(Itm,1);
    if(Page==4)
	    Dis_Page4(Itm,1);
	
}
void Dis_Page1(char j,int f)
{
	OLED_ShowChar(0,0,P1I1);dis_num(1,0,eins);//OLED_ShowChar(60,0,eins);//dis_num(1,0,eins);
	OLED_ShowChar(0,2,P1I2);dis_num(1,2,zwei);
	OLED_ShowChar(0,4,P1I3);dis_num(1,4,drei);
	OLED_ShowChar(0,6,P1I4);dis_num(1,6,vier);
	if(f)
		OLED_ShowChar(115,2*j,'*');
	if(aus_flag)
		OLED_ShowChar(100,0,'!');
}
void Dis_Page2(char j,int f)
{
	OLED_ShowChar(0,0,P2I1);dis_num(1,0,einss);
	OLED_ShowChar(0,2,P2I2);dis_num(1,2,zweii);
	OLED_ShowChar(0,4,P2I3);dis_num(1,4,dreii);
	OLED_ShowChar(0,6,P2I4);dis_num(1,6,vierr);
	if(f)
		OLED_ShowChar(115,2*j,'*');
	if(aus_flag)
	    OLED_ShowChar(100,0,'!');
}
void Dis_Page3(char j,int f)
{
	OLED_ShowChar(0,0,P3I1);dis_num(1,0,einsss);
	OLED_ShowChar(0,2,P3I2);dis_num(1,2,zweiii);
	OLED_ShowChar(0,4,P3I3);dis_num(1,4,dreiii);
	OLED_ShowChar(0,6,P3I4);dis_num(1,6,vierrr);
	if(f)
		OLED_ShowChar(115,2*j,'*');
	if(aus_flag)
		OLED_ShowChar(100,0,'!');
}
void Dis_Page4(char j,int f)
{
	OLED_ShowChar(0,0,P4I1);dis_num(1,0,einssss);
	OLED_ShowChar(0,2,P4I2);dis_num(1,2,zweiiii);
	OLED_ShowChar(0,4,P4I3);dis_num(1,4,dreiiii);
	OLED_ShowChar(0,6,P4I4);dis_num(1,6,vierrrr);
	if(f)
		OLED_ShowChar(115,2*j,'*');
	if(aus_flag)
		OLED_ShowChar(100,0,'!');
}
