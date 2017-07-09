/*
 * steer.c
 *
 *  Created on: Feb 21, 2017
 *      Author: apple
 */
#include "all.h"

void SET_steer(unsigned int steer)
{EMIOS_0.CH[4].CBDR.R = steer;}// left limit 2500 right limit 2000 middle 2250 

