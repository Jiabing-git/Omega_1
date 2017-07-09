/*
 * control.c
 *
 *  Created on: Jan 20, 2017
 *      Author: dell-pc
 */

#include "all.h"
int currentspeed=0,currentx=0,ud,ud_old=0;
int error[10]={0};
unsigned int udd=0;
int SpeedSet=0;										//设定速度值
int DirectionControl=0,Last_DirControl=0;
float SpeedControl=0;
float Dir_Ratio=0.8;
float K=1;                //动态pd角度控制
//int SpeedControl_old=0;
unsigned char mark=0;
float K_S=1000,I_S=1000,D_S=500;//speed1000 400 500
float d_a = 0.8;
float A_P_DIRECTION,A_D_DIRECTION;
        //27c8//30 7.6//27d7.8V//27 7.4V

//7.92V 650 690 700 730 pwm=27
//7.88V 660 710 720 760 pwm=25 
//7.80V 660 700 710 750  760 860 960 960 pwm=28
//7.77V 660 690 700 750 800 900 1000 pwm=28
//7.60V 660 700 710 750 70 70 70 70 pwm=27
//7.19V 660 700 710 750 90 90 90 90 pwm=32 略切内

/*
 电压     满   怠	p_5 _10 _15 _20 d_5 _10 _15 _20 s  
7.85V 32 13 660 700 710 750 760 860 960 960 80  
7.76V 35 12 640 700 710 750 700 860 960 960 85
7.59V 37 13 680 720 725 740 780 860 980 980 91
*/

float p_5=270;//125//270
float p_10=505;//210//505
float p_15=510;//250//510
float p_20=530;//500//530
float d_5=1200;
float d_10=1400;
float d_15=1400;
float d_20=900;       

unsigned int s=95;
/*
v_1 v_2 v_3 v_4 s  P   I   p_5 _10 _15 _20 U(V) d_all
350 300 280 275 92 200 100 470 655 660 700
350 300 280 275 94 200 100 390 610 660 700
350 300 280 275 95 200 100 380 560 645 730 7.78 1000
370 340 320 290 95 700 220 245 500 520 730 7.78 1000
370 340 310 290 95 700 220 300 450 560 730 7.78 900 1200 1200 900
450             94         380 585 645 730
400 350 325 300 95 200 100 380 585 660 780
400 350 320 280 95 700 300 270 450 560 680 7.78 1000 1200 1300 900
425 380 320 280 95 700 220 270 450 560 680 7.60 1000 1200 1300 900 gut
425 380 340 320 95 700 220 270 450 505 665 7.85 1000 1200 1300 900 gut
425 390 370 320 95 700 220 270 450 560 665 7.89 1000 1200 1300 900 gut

450 400 350 280 95 700 220 300 450 560 720 7.56	1600 2200 2600 900
500 450 400 350 95 700 220 300 450 560 730 7.77 900 1200 1200 1200
						       400 470
						   280 400 450 730
						                   7.34 900 1400 1400 900
500 470 425 370 95 700 220 300 			   8.10 900 1400 1400 900	
430 380 350 320		                       7.78                    gut
闭环：
380 360 350 320 95 700 220 270 505 510 550 8.70 1000 1200 1300 900 gut
									   530
无蓝牙：
130 130 120 90 90 700 220 270 505 515 535 7.72  1000 1200 1300 900 gut	
140 130 120 100 90                        less  							
 */

unsigned int PWM_Set=120;	//满载控制
unsigned int PWM_10=120;
unsigned int PWM_15=120;
unsigned int PWM_20=120;
unsigned int PWM_Idle=85;	//怠速控制

unsigned int EventCount=1; 
unsigned int time=0;
unsigned int stop_time=200;
unsigned int auto_restart_time=0; 
unsigned char Adjust_circle=0;
int Set_Steer_Dead=-300; //-300右拐    300左拐

unsigned int steer_mid=1830;


void DirectionController()
{   x_bekommen();
if(aus_flag)
{ 
	if(Ausflag)
	{
	if(DirectionControl>0)
		DirectionControl+=7;//DirectionControl=300;
	else 
		DirectionControl-=7;//DirectionControl=-300; 
	
	}
	else if((l[5]-l[6])<60&&(l[5]-l[6])>-60&&l[5]>50&&l[6]>50)
		circle_flag=1;
	else
	{
    if(l[5]>l[6])
    	DirectionControl+=7;//DirectionControl=300;
	else 
		DirectionControl-=7;//DirectionControl=-300;
	}
	
	SpeedSet=PWM_Idle;
}

else 
{  
	//SpeedSet=PWM_Set;
	get_kp(X);
    ud=(A_D_DIRECTION *(x_save[99] - x_save[s])*d_a+(1-d_a)*ud_old);

	DirectionControl=K*(A_P_DIRECTION * (x-2500)+ud)/10000;
	if(DirectionControl>0)		//偏右	左转
		DirectionControl*=0.80;//0.80
	else						//偏左 	右转
		DirectionControl*=0.90;
	ud_old=ud;
}
	//环形参数修正
	if(!auscircle_flag)
	{
		if(aus_flag)
		{
			if(Set_Steer_Dead<0)
				DirectionControl=-Set_Steer_Dead*0.74;//0.64//0.68-130//0.73
			else
				DirectionControl=-Set_Steer_Dead*1;
		}
		DirectionControl*=0.8;
	}
	

	if(DirectionControl>300)DirectionControl=300;//
	if(DirectionControl<-300)DirectionControl=-300;//
 
 
	//归一化！！！！
 }
void SpeedController()
{   int i;

	if(!start)
		SpeedSet=0;
	if(Slowdown)
		SpeedSet=100; //80
	
	if(Adjust_circle)
		SpeedSet=50; //80*/
	
	if(time_delta<1200&&Slowdown)
		SpeedSet=85;//50
	if(time_delta<600&&Slowdown)
		SpeedSet=0;
	
	currentspeed=SpeedBekommen();
	if(DirBekommen())										//根据实际确定方向正负
		currentspeed*=-1;
	for(i=0;i<9;i++)
		error[i]=error[i+1];
	error[9]=SpeedSet-currentspeed;	
	
    SpeedControl+=K_S/1000*(error[9]-error[8])+I_S/1000*error[9]+D_S/1000*(error[9]-2*error[8]+error[7]);
    if(SpeedControl>60)
    	SpeedControl=60;
    if(SpeedControl<-60)
    	SpeedControl=-60;
    	
}
void SetSteer()
{ 
	 if(Set_Steer_Dead>0)
	 {
		 if(stop&&time<90)//50//80//110halt
		 {
		 	 DirectionControl=Set_Steer_Dead;
		 }
		 else
		 {
		 	 stop=0;
		 	 time=0;
		 	 if(!start)
		 		 DirectionControl*=0.55;//环形修正//0.55
		 }
	 }
	 else
	 {
		 if(stop&&time<90)//50//80//90halt
		 {
			 DirectionControl=Set_Steer_Dead;
		 }
		 else
		 {
			 stop=0;
			 time=0;
			 if(!start)
			 	 DirectionControl*=0.55;//环形修正
		 }
	 }
	 EMIOS_0.CH[4].CBDR.R=steer_mid-DirectionControl;//1830 15//30
	if(EMIOS_0.CH[4].CBDR.R>2145)//2130
		EMIOS_0.CH[4].CBDR.R=2145;//右打死
	if(EMIOS_0.CH[4].CBDR.R<1545)//1530
		EMIOS_0.CH[4].CBDR.R=1545;//左打死
}


void SetMotor()
{
	int out=SpeedControl;
	/*
	if(!start)
		out=0;
	*/
	if(out>60)
  		out=60;
	if(out<-60)
		out=-60;
	
	
	if(out>=0) 
	{
		EMIOS_0.CH[21].CBDR.R = out;
		EMIOS_0.CH[19].CBDR.R = 0;
	}
	else 
	{
		EMIOS_0.CH[21].CBDR.R = 0;
		EMIOS_0.CH[19].CBDR.R =-out;
	}
}

void Check()
{   	/*if(BT_active)
     { EMIOS_0.CH[21].CBDR.R = 0;
		EMIOS_0.CH[19].CBDR.R = 0;
	while(1)
	{   state=LINFlex_RX();
		if(state>85&&state<95)
	{
		start=1;
		BT_active=0;
		break;
	}
      }
     }*/
	if(Press_Flag)
	{
		SpeedControl_Flag=0;
		DirectionControl_Flag=0;
		EMIOS_0.CH[4].CBDR.R=1838;
		BlueTooth_Flag=0;
	}
	else
	{
		//OLED_Clear();
		SpeedControl_Flag=1;
		DirectionControl_Flag=1;
		ADC_Flag=1;
		BlueTooth_Flag=1;
	}
	if(ADC_Flag)
	{ 
		AD_Read();
		if(Press_Flag&&EventCount%10==0)
			x_bekommen();
	}
	if(EventCount%10==0&&DirectionControl_Flag==1)
	{  
		if(stop)
			time++;
		if(!start)
			auto_restart_time++;
		
		if(!start&&auto_restart_time>100&&auto_restart_time<200)//250 750环形位置二次调整
			Adjust_circle=1;
		else
			Adjust_circle=0; 
		
		/*if(!start&&auto_restart_time>1000)
			BT_active=1;
			*/
		
		if(auto_restart_time>stop_time)//300环岛停车时间 10000=20s//2500=5s
		{
			auto_restart_time=0;
			start=1;
			BT_active=0;
		}
		DirectionController();
	    SetSteer();
	}
	
	if(EventCount%25==0&&SpeedControl_Flag==1)
	{
		SpeedController();
		SetMotor();
	}

	if(EventCount%25==0&&BlueTooth_Flag==1)
	{
		/*
		if(BT_active)
		{
			state=LINFlex_RX();
			if(state>80&&state<100)
			{
				start=1;
			}
		}*/
		//SendFloat_3(currentspeed,'A');
		//SendFloat_3(SpeedSet,'B');
		//SendFloat_3(currentspeed,'C');
		//SendFloat_3(currentspeed,'D');
		//SendFloat_3(currentspeed,'E');
		//SendFloat_3(currentspeed,'F');	
	}
	if(EventCount%100==0)
	{
		SSW_Dis();
	}
	if(EventCount%1000==0&&Press_Flag==1)
	{
		HCI();	
	}
	
	if(EventCount>=1000)
		EventCount=0;
	EventCount++;
    PIT.CH[0].TFLG.B.TIF = 1;
}
