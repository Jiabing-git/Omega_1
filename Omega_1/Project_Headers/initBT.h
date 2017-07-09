/*
 * initBT.h
 *
 *  Created on: Nov 11, 2016
 *      Author: dell-pc
 */

#ifndef INITBT_H_
#define INITBT_H_

extern unsigned char state;

void initLINFlex_0_UART (void);
void LINFlex0_init(void);
void LINFlex_TX(unsigned char data);
unsigned char LINFlex_RX(void);
void SendFloat_3(float raw,char flag);
#endif /* INITBT_H_ */
