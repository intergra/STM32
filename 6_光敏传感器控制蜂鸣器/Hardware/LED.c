#include "stm32f10x.h"                  // Device header
void LED_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//启用APB2的外设时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//结构体的三种参数
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);//GPIO初始化函数，根据结构体中的参数来初始化
	
	GPIO_WriteBit(GPIOA,GPIO_Pin_1|GPIO_Pin_2,Bit_SET);//将默认的低电平设置为高电平
}

//LED1的负极接在A1，LED2的负极接在A2

void LED1_ON()//LED1点亮
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
}

void LED1_OFF()//LED1熄灭
{
	GPIO_SetBits(GPIOA,GPIO_Pin_1);
}

void LED1_Turn()//让A1引脚的高，低电平反转
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)==1)
		GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	else
		GPIO_SetBits(GPIOA,GPIO_Pin_1);
}

void LED2_ON()//LED2点亮
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}

void LED2_OFF()//LED2熄灭
{
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
}

void LED2_Turn()//让A2引脚的高，低电平反转
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2)==1)
		GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	else
		GPIO_SetBits(GPIOA,GPIO_Pin_2);
}