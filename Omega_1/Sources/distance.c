/*
 * distance.c
 *
 *  Created on: Feb 22, 2017
 *      Author: apple
 */
#include "all.h"
unsigned char aus_flag=0,Ausflag=0,circle_flag=0,auscircle_flag=1;
float L[7][10];
float l[7]={0,0,0,0,0,0,0};
int x_save[100]={2500};
int x=0,X,max=0,min=0;
float fir[10] = {0.6,0.1,0.08,0.05,0.05,0.03,0.03,0.03,0.02,0.01};

float Circle_L_Set_Up=200;
float Circle_L_Set_Down=50;

unsigned char stop=0;
unsigned char start=1;
unsigned char stop_active=1;

void AD_Read(void)
{  int i;
   AD_Bekommen();
   //operationL();
	for(i=9;i>0;i--)
	{
	L[0][i]=L[0][i-1];
	L[1][i]=L[1][i-1];
	L[2][i]=L[2][i-1];
	L[3][i]=L[3][i-1];
	L[4][i]=L[4][i-1];
	L[5][i]=L[5][i-1];
	L[6][i]=L[6][i-1];
	}
	L[0][0]=L1;
	L[1][0]=L2;
	L[2][0]=L3;
	L[3][0]=L4;
	L[4][0]=L5;
	L[5][0]=L6;
	L[6][0]=L7;
	
}
void x_bekommen(void)
{ 
	int i=0;
	l[0]=0;l[1]=0;l[2]=0;l[3]=0;l[4]=0;l[5]=0;l[6]=0;
	for(i=0;i<10;i++)
   {
		l[0]+=fir[i]*L[0][i];
		l[1]+=fir[i]*L[1][i];
		l[2]+=fir[i]*L[2][i];
		l[3]+=fir[i]*L[3][i];
		l[4]+=fir[i]*L[4][i];
		l[5]+=fir[i]*L[5][i];
		l[6]+=fir[i]*L[6][i];
	}
	if(l[0]<50&&l[1]<50&&l[2]<50&&l[3]<50&&l[4]<50)
	{   
		//if((l[5]-l[6])<50&&(l[5]-l[6])>-50&&l[5]>50&&l[6]>50)
		//circle_flag=1;
		aus_flag=1;
		if(l[5]<80&l[6]<80)
			Ausflag=1;
		else 
			Ausflag=0;
	}
	else
	{
		for(i=0;i<5;i++)
			if(l[i]>l[max])
				max=i; 
		/*for(i=0;i<5;i++)
			if(l[i]<l[min])
				min=i; */
		if(max == 0) 
			x = 1000 - (10000*(float)(l[0] - l[1])/(l[0] + l[1]+(l[0]/2000)*(l[1]/3000)));   
		else if(max == 4) 
			x = 4000 + (10000*(float)(l[4] - l[3])/(l[3] + l[4]+(l[3]/3000)*(l[4]/2000)));   
		else 
		{
			if(l[max-1] > l[max+1])				
				x = max*1000 + 500.0*((l[max]-l[max-1]))/((l[max]-l[max+1]));				  
			else 
				x = (max+1)*1000 - 500.0*((l[max]-l[max+1]))/((l[max]-l[max-1]));	
		}
  
   //x-=400;//修正坐标位置
	
		if (x < -2000 )  x = -2000;   
		if (x >  7000 )  x = 7000;
	
	
		i=0;
		while(i<99)
		{
			x_save[i] = x_save[i+1];	
			i++;		
		}
		if(x>2500) 
			X=x-2500;
		else 
			X=2500-x;
		x_save[99]=x;
		
		aus_flag=0;
		circle_flag=1;
		//if(max==2&&l[max]<250&&l[min]>35&&l[5]>200&&l[6]>200&&l[max]*0.45<l[min])
			//circle_flag=1;
		for(i=0;i<5;i++)
		{
			if(l[i]<Circle_L_Set_Down||l[i]>Circle_L_Set_Up||l[5]<150||l[6]<150)
			{
				circle_flag=0;
				break;
			}
		}
		if(circle_flag&&stop_active)
				{
					stop_active=0;//只识别一次环岛
					//BT_active=1;
					auscircle_flag=0;
					stop=1;
					start=0;
				}
				if(l[max]>250)//250
					auscircle_flag=1;
		/*
		if(l[max]<Circle_L_Set_Up&&X<2000)
			circle_flag=1;
		 */
	}

 }

float get_kp(int X)	  			
{
	float kp_l;
 
	if(X<500)
	 {
		A_P_DIRECTION=p_5;			 
		A_D_DIRECTION=d_5;
		SpeedSet=PWM_Set;
	 }
	 else if(X<1000)
	 {
		 A_P_DIRECTION=p_5+0.002*(X-500)*(p_10-p_5);
		 A_D_DIRECTION=d_10;
		 SpeedSet=PWM_10;
		 //SpeedSet=PWM_Set+((float)X-500)/500*(PWM_10-PWM_Set);//速度平滑处理
	 }
	 else if(X<1500)
	 {
		 A_P_DIRECTION=p_10+0.002*(X-1000)*(p_15-p_10);
		 A_D_DIRECTION=d_15;
		 SpeedSet=PWM_15;
		 //SpeedSet=PWM_Set+((float)X-1000)/500*(PWM_15-PWM_10);//速度平滑处理
	 }
	 else if(X<2000)
	 {
		 A_P_DIRECTION=p_15+0.002*(X-1500)*(p_20-p_15);
		 A_D_DIRECTION=d_20;
		 SpeedSet=PWM_20;
		 //SpeedSet=PWM_15+((float)X-1500)/500*(PWM_20-PWM_15);//速度平滑处理
	 }
	 else
	 {
		 A_P_DIRECTION=p_20;
		 A_D_DIRECTION=d_20;
		 SpeedSet=PWM_Idle;
		 //SpeedSet=PWM_20+((float)X-2000)/2500*(PWM_Idle-PWM_20);//速度平滑处理
	  }
	if(circle_flag==1)
		SpeedSet=PWM_Idle;
	
}
