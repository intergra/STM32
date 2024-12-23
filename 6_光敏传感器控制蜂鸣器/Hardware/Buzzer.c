#include "stm32f10x.h"                  // Device header

void Buzzer_Init()//蜂鸣器模块的IO口插在B12处
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//启用APB2的外设时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//结构体的三种参数
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);//GPIO初始化函数，根据结构体中的参数来初始化
	
	GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_SET);//将默认的低电平设置为高电平
}

void Buzzer_ON()
{
	GPIO_ResetBits(GPIOB,GPIO_Pin_12);
}

void Buzzer_OFF()
{
	GPIO_SetBits(GPIOB,GPIO_Pin_12);
}

void Buzzer_Turn()
{
	if(GPIO_ReadOutputDataBit(GPIOB,GPIO_Pin_12)==1)
		GPIO_ResetBits(GPIOB,GPIO_Pin_12);
	else
		GPIO_SetBits(GPIOB,GPIO_Pin_12);
}