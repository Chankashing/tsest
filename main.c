
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
 ALIENTEK战舰STM32开发板实验28
 红外遥控器 实验  
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/
/*********************************************/
#define  EEP_Firstpage      0x00   //EEProm初始地址
uint8_t I2c_Buf_Write[2];         
uint8_t I2c_Buf_Read[2];
void I2C_Test(void);

/*********************************************/



u8 key = 0;               //按键，键值
u8 Val;                   //当前PWM占空比整十判断
u8 Value;
u8 flag=1;
 int main(void)
 {	 
	 
	 GENERAL_TIM_Init();  	     //PWM定时器从初始化

	 Key_GPIO_Config();

	 
	while(1)
	{
		
		if( Key_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_ON )   //按键一，输出B0
		{			
 			pwm_inde1=12600;
			pwm_inde3=12600;
		}
		if(pwm_inde1)
    {
			GPIO_ResetBits(GPIOA,GPIO_Pin_4);
		 }        //模拟提枪信号
		else GPIO_SetBits(GPIOA,GPIO_Pin_4);  //模拟提枪信号
		

		if( Key_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN) == KEY_ON )   //按键二，输出B1
		{		
			pwm_inde2=24600;
			pwm_inde4=24600;
		}
		if(pwm_inde2) 
			{
				GPIO_ResetBits(GPIOA,GPIO_Pin_5);
			}  //模拟提枪信号
		  else GPIO_SetBits(GPIOA,GPIO_Pin_5);  //模拟提枪信号
		
	}
}




