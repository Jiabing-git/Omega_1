/*
 * control.h
 *
 *  Created on: Jan 20, 2017
 *      Author: dell-pc
 */

#ifndef CONTROL_H_
#define CONTROL_H_

void SpeedController();
void DirectionController();
void SetSteer();
void SetMotor();
void Check();

extern int SpeedSet;												//设定速度值
extern float SpeedControl;

extern unsigned int s;//delta distance 数组
extern unsigned int udd;//ud的绝对值，便于OLED显示

extern unsigned int PWM_Set;
extern unsigned int PWM_10;
extern unsigned int PWM_15;
extern unsigned int PWM_20;
extern unsigned int PWM_Idle;

extern int currentspeed;
extern int ud,ud_old;
extern int DirectionControl;
extern float K_S,I_S,D_S,A_P_DIRECTION,A_D_DIRECTION,K;
extern unsigned int lastcount;
extern unsigned int EventCount;

extern unsigned char SpeedControl_Flag;
extern unsigned char DirectionControl_Flag;
extern unsigned char ADC_Flag;
extern unsigned char BlueTooth_Flag;
extern unsigned char Press_Flag;
extern int Set_Steer_Dead;
extern unsigned char Adjust_circle;
extern unsigned int steer_mid;

extern float d_a;

extern float p_5;
extern float p_10;
extern float p_15;
extern float p_20;
extern float d_5;
extern float d_10;
extern float d_15;
extern float d_20;


#endif /* CONTROL_H_ */
