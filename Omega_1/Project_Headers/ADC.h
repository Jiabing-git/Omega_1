/*
 * ADC.h
 *
 *  Created on: Sep 12, 2016
 *      Author: dell-pc
 */

#ifndef ADC_H_
#define ADC_H_




void initADC(void);
void AD_Bekommen(void);
void MaxBekommen(void);
void operationL(void);
void operationDat(void);
extern float L1,L2,L3,L4,L5,L6,L7,L8;
extern int max1,max3,max4,max5,max2;
/*
void Kalman_Filter(float angle_m,float gyro_m);
void Complementary_Filter();

void G_C_A(void);

extern float D_A;
extern float G_X,G_Z;
extern float C_A;
extern float G_X_Mitte;
extern float angle, angle_dot; 
*/

#endif /* ADC_H_ */
