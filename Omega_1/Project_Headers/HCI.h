/*
  * HCI.h
 *
 *  Created on: Aug 28, 2016
 *      Author: dell-pc
 */

#ifndef HCI_H_
#define HCI_H_

#define PgMax 2

#define PgUp press5
#define PgDn press5
#define ItmUp press1
#define ItmDn press2
#define ValUp press3 
#define ValDn press4

/***************************************************************************************************************
**************************************************Page1(below)**************************************************
***************************************************************************************************************/
#define P1I1 'V'
#define P1I2 's'
#define P1I3 'K'
#define P1I4 'I'



//声明变量寄存器名称(below)
/*
#define eins time_delta//state//Set_Steer_Dead
#define zwei SpeedSet//start
#define drei Slowdown//time_delta
#define vier PWM_20//stop_ac tive
*/

#define eins stop_time//K_S
#define zwei steer_mid//I_S
#define drei L3//stop_time
#define vier Set_Steer_Dead

//声明变量寄存器名称(above)
/***************************************************************************************************************
**************************************************Page1(above)**************************************************
***************************************************************************************************************/

/***************************************************************************************************************
**************************************************Page2(below)**************************************************
***************************************************************************************************************/
#define P2I1 'P'
#define P2I2 'P'
#define P2I3 'P'
#define P2I4 'P'



//声明变量寄存器名称(below)
/*
#define einss PWM_Idle
#define zweii p_10
#define dreii p_15
#define vierr p_20
*/
#define einss L5
#define zweii L6
#define dreii L7
#define vierr x

#define P3I1 'D'
#define P3I2 'D'
#define P3I3 'D'
#define P3I4 'x'



//声明变量寄存器名称(below)
#define einsss Set_Steer_Dead//stop_active
#define zweiii L2
#define dreiii L3
#define vierrr L4

/*#define einss l[4]
#define zweii l[5]
#define dreii l[6]
#define vierr x*/
//声明变量寄存器名称(above)
#define P4I1 'D'
#define P4I2 'L'
#define P4I3 'L'
#define P4I4 'L'



//声明变量寄存器名称(below)
#define einssss L5
#define zweiiii L6
#define dreiiii L7
#define vierrrr x

extern char Page;
extern char Itm;

void HCI(void);
void Dis_Page1(char j,int f);
void Dis_Page2(char j,int f);
void Dis_Page3(char j,int f);
void Dis_Page4(char j,int f);

#endif /* HCI_H_ */
