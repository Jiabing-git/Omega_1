/*
 * distance.h
 *
 *  Created on: Feb 22, 2017
 *      Author: apple
 */

#ifndef DISTANCE_H_
#define DISTANCE_H_
extern int x,X,max,min;
extern float l[7];
extern int x_save[100];
extern unsigned char aus_flag,Ausflag,auscircle_flag;
extern unsigned char circle_flag;
void initDis();
void x_bekommen();
void AD_Read();
float get_kp(int X);

extern float Circle_L_Set_Up;
extern float Circle_L_Set_Down;
extern unsigned char stop;
extern unsigned char start;
extern unsigned char stop_active;

#endif /* DISTANCE_H_ */
