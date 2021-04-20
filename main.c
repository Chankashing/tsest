
#include "stm32f10x.h"
#include "stm32f10x_it.h"
#include "led.h"
#include "delay.h"
#include "bsp_key.h"
#include "sys.h"
#include "pwm_pa0.h"
#include "usart.h"	 
#include "remote.h"
#include "iwdg.h" 
#include "i2c_eep.h"
#include "main.h" 
/************************************************
 ALIENTEKս��STM32������ʵ��28
 ����ң���� ʵ��  
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/
/*********************************************/
#define  EEP_Firstpage      0x00   //EEProm��ʼ��ַ
uint8_t I2c_Buf_Write[2];         
uint8_t I2c_Buf_Read[2];
void I2C_Test(void);

/*********************************************/



u8 key = 0;               //��������ֵ
u8 Val;                   //��ǰPWMռ�ձ���ʮ�ж�
u8 Value;
u8 flag=1;
 int main(void)
 {	 
	 
	 GENERAL_TIM_Init();  	     //PWM��ʱ���ӳ�ʼ��

	 Key_GPIO_Config();

	 
	while(1)
	{
		
		if( Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_ON )   //����һ�����B0
		{			
 			pwm_inde1=12600;
			pwm_inde3=12600;
		}
		if(pwm_inde1)
    {
			GPIO_ResetBits(GPIOA,GPIO_Pin_4);
		 }        //ģ����ǹ�ź�
		else GPIO_SetBits(GPIOA,GPIO_Pin_4);  //ģ����ǹ�ź�
		

		if( Key_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN) == KEY_ON )   //�����������B1
		{		
			pwm_inde2=24600;
			pwm_inde4=24600;
		}
		if(pwm_inde2) 
			{
				GPIO_ResetBits(GPIOA,GPIO_Pin_5);
			}  //ģ����ǹ�ź�
		  else GPIO_SetBits(GPIOA,GPIO_Pin_5);  //ģ����ǹ�ź�
		
	}
}




