/*
 * ssw.h
 *
 *  Created on: Feb 24, 2017
 *      Author: dell-pc
 */

#ifndef SSW_H_
#define SSW_H_

void initSSW();
void SSW_Dis();

extern unsigned int time1,time2,time_delta;
extern unsigned char out_of_sight;
extern unsigned int safe_distance;
extern unsigned char BT_active;
extern unsigned char Slowdown;
extern unsigned int stop_time;

#endif /* SSW_H_ */
