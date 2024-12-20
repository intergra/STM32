#include "stm32f10x.h"                  // Device header
#include <Delay.h>
void Key_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//启用APB2中GPIOB的外设时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//上拉输入，确保按键未被按下时引脚能准确为高电平。
												//按键另一边为高电平。
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}

uint8_t Key_GetNum()
{
	uint8_t KeyNum=0;//如果Keynum=1表示按键1按下，KeyNum=2就是2按下
	
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
			Delay_ms(20);
		KeyNum=1;
	}
	
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0)
	{
		Delay_ms(20);
		while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0)
			Delay_ms(20);
		KeyNum=2;
	}
	
	return KeyNum;
}