#include "stm32f10x.h"                  // Device header

void LightSensor_Init()//光敏传感器的DO口插在B13处
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//启用APB2的外设时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//结构体的三种参数
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}

uint8_t LigntSensor_Get()//获取光敏传感器对应引脚的电平,暗时为1，亮为0
{
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13);
}