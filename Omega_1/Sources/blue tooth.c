/*
 * blue tooth.c
 *
 *  Created on: Nov 11, 2016
 *      Author: dell-pc
 */
#include "all.h"

unsigned char state=0;

void initLINFlex_0_UART(void) 
{
	LINFLEX_0.LINCR1.B.INIT=1;  //�����ʼ��ģʽ
	LINFLEX_0.LINCR1.R=0x00000015; 
	LINFLEX_0.LINIER.B.DRIE=0; //��������ж�
	/*�������㷨baud=Fperiph_clk/(16*LFDIV)
	DIV_M=LFDIV��������
	DIV_F=LFDIVС������*16  */ 	
	LINFLEX_0.LINIBRR.B.DIV_M= 69;  	//����������38400:80M-130+3 57600:80M-86+13 115200:80M-43+6  9600:80M-520+83
    LINFLEX_0.LINFBRR.B.DIV_F = 7;		//38400:64M-104+3//???
    LINFLEX_0.UARTCR.B.UART=1;
	LINFLEX_0.UARTCR.R=0x00000033;//8-bit data��UART mode
	LINFLEX_0.LINCR1.B.INIT=0; //�˳���ʼ��ģʽ
	 
	SIU.PCR[18].R = 0x0400;    /* MPC56xxB: Configure port B2 as LIN0TX *///??
    SIU.PCR[19].R = 0x0103;    /* MPC56xxB: Configure port B3 as LIN0RX *///??
  	///INTC_InstallINTCInterruptHandler(LINFlex_RX_Interrupt,79,4); 
}
void LINFlex0_init(void)
{
//����LINFlex
  LINFLEX_0.LINCR1.B.INIT   = 1;   // �����ʼ��
  LINFLEX_0.LINCR1.B.SLEEP  = 0;  // ��ֹ˯��ģʽ
  LINFLEX_0.LINCR1.B.BF     = 0;  // ���ID��ƥ�䲻�����ж�

  LINFLEX_0.UARTCR.B.UART   = 1;        // ����UARTģʽ
  LINFLEX_0.UARTCR.B.RXEN   = 1;  // ��ֹ����0
  LINFLEX_0.UARTCR.B.TXEN   = 1;   // ������
  LINFLEX_0.UARTCR.B.WL     = 1;        // 8λ����λ
//  LINFLEX_0.UARTCR.B.OP     = 1;      // żУ��
  LINFLEX_0.UARTCR.B.PCE    = 0;  // ��ֹ��żУ��
  LINFLEX_0.UARTCR.B.TDFL   = 0;        // ���ͻ�����Ϊ1���ֽ�
  LINFLEX_0.UARTCR.B.RDFL   = 0;        // ���ջ�����Ϊ1���ֽ�

//���ò�����Ϊ9600
//������=����ʱ��1/(16*LFDIV)
//DIV_M����LFDIV���������֡�(DIV_F/16)����LFDIV��С�����֡�
//LINFLEX_0.LINIBRR.B.DIV_M = 1666;     // Baud Rate = 2400, In Case fipg_clock_lin = 64 MHz
//LINFLEX_0.LINFBRR.B.DIV_F = 11;       // Baud Rate = 2400, In Case fipg_clock_lin = 64 MHz
//LINFLEX_0.LINIBRR.B.DIV_M = 833;      // Baud Rate = 4800, In Case fipg_clock_lin = 64 MHz
//LINFLEX_0.LINFBRR.B.DIV_F = 11;       // Baud Rate = 4800, In Case fipg_clock_lin = 64 MHz
LINFLEX_0.LINIBRR.B.DIV_M = 416;     // Baud Rate = 9600, In Case fipg_clock_lin = 64 MHz
LINFLEX_0.LINFBRR.B.DIV_F = 11;     // Baud Rate = 9600, In Case fipg_clock_lin = 64 MHz
//LINFLEX_0.LINIBRR.B.DIV_M = 208;      // Baud Rate = 19200, In Case fipg_clock_lin = 64 MHz
//LINFLEX_0.LINFBRR.B.DIV_F = 5;        // Baud Rate = 19200, On Case fipg_clock_lin = 64 MHz
//LINFLEX_0.LINIBRR.B.DIV_M = 104;      // Baud Rate = 38400, In Case fipg_clock_lin = 64 MHz
//LINFLEX_0.LINFBRR.B.DIV_F = 3;        // Baud Rate = 38400, In Case fipg_clock_lin = 64 MHz
//LINFLEX_0.LINIBRR.B.DIV_M = 69;       // Baud Rate = 57600, In Case fipg_clock_lin = 64 MHz
//LINFLEX_0.LINFBRR.B.DIV_F = 7;        // Baud Rate = 57600, In Case fipg_clock_lin = 64 MHz
//LINFLEX_0.LINIBRR.B.DIV_M = 34;       // Baud Rate = 115200, In Case fipg_clock_lin = 64 MHz
//LINFLEX_0.LINFBRR.B.DIV_F = 12;       // Baud Rate = 115200, In Case fipg_clock_lin = 64 MHz

//�����жϣ�ʹ���жϹ���
//LINFLEX_0.LINIER.B.DRIE   = ENABLE;   // ���ݽ�������ж�
//LINFLEX_0.LINIER.B.DTIE   = ENABLE;   // ���ݷ�������ж�
//LINFLEX_0.LINIER.B.DBFIE  = ENABLE;   // ���ݻ��������ж�
//LINFLEX_0.LINIER.B.DBEIE  = ENABLE;   // ���ݻ��������ж�

//�����жϣ���ֹ�жϹ���
  LINFLEX_0.LINIER.R        = 0;        // ��ֹ�����ж�
//LINFLEX_0.LINIER.B.DRIE   = DISABLE;  // ���ݽ�������ж�
//LINFLEX_0.LINIER.B.DTIE   = DISABLE;  // ���ݷ�������ж�
//LINFLEX_0.LINIER.B.DBFIE  = DISABLE;  // ���ݻ��������ж�
//LINFLEX_0.LINIER.B.DBEIE  = DISABLE;  // ���ݻ��������ж�

  LINFLEX_0.UARTSR.B.DRF    = 1;        // ���������ɱ�־
  LINFLEX_0.UARTSR.B.DTF    = 1;        // ���������ɱ�־

  LINFLEX_0.LINCR1.B.INIT   = 0;  // ��Ϊ����ģʽ
  
  SIU.PCR[18].R = 0x0400;    /* MPC56xxB: Configure port B2 as LIN0TX *///??
  SIU.PCR[19].R = 0x0103;    /* MPC56xxB: Configure port B3 as LIN0RX *///??
}
/*************************�����ӿں���*********************/
void LINFlex_TX(unsigned char data)
{
	LINFLEX_0.UARTSR.B.DTF=1;
	LINFLEX_0.BDRL.B.DATA0=data;       //�������
	while(!LINFLEX_0.UARTSR.B.DTF){}
	//LINFLEX_0.UARTSR.B.DTF=1;
}
unsigned char LINFlex_RX(void)
{
  unsigned char datain;
  datain=LINFLEX_0.BDRM.B.DATA4;        // ��ȡ���յ�������
  LINFLEX_0.UARTSR.B.DRF = 1;           // ���������ɱ�־λ
  return datain;
}
void SendFloat_3(float raw,char flag)
{
	int x;
	int y;
	int i;
	unsigned char r[6];//���������λ��Ҳ��Ӱ�죿�����ȶ������б�������ʹ�ã�
	x=raw;//�����Ͳ�����mod��mod��int�õģ��������ú���
	y=(int)(raw*1000)%1000;
	
	
	//dis_num(4,y);
	
	
	for(i=0;i<3;i++)
	{
		if(y==0)
			r[i]=0;
		else
		{
			r[i]=y%10;
			y=y/10;
		}
	}
	for(i=3;i<6;i++)
	{
		if(x==0)
			r[i]=0;
		else
		{
			r[i]=x%10;
			x=x/10;
		}
	}
	LINFlex_TX(flag);
	//for(i=0;i<6;i++)
	
	LINFlex_TX(r[0]+48);
	LINFlex_TX(r[1]+48);
	LINFlex_TX(r[2]+48);
	LINFlex_TX(r[3]+48);
	LINFlex_TX(r[4]+48);
	LINFlex_TX(r[5]+48);
	
	/*
	delay(200);
	LINFlex_TX('1');
	delay(200);
	LINFlex_TX('2');
	delay(200);
	LINFlex_TX('3');
	delay(200);
	LINFlex_TX('4');
	delay(200);
	LINFlex_TX('5');
	delay(200);
	LINFlex_TX('6');
	delay(200);
	LINFlex_TX('7');
	delay(200);
	LINFlex_TX('8');
	delay(200);
	LINFlex_TX('9');
	delay(200);
	LINFlex_TX(':');
	delay(200);
	*/
}
