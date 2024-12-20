#include "stm32f10x.h"                  // Device header

void LightSensor_Init()//������������DO�ڲ���B13��
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//����APB2������ʱ��
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//�ṹ������ֲ���
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_13;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);
}

uint8_t LigntSensor_Get()//��ȡ������������Ӧ���ŵĵ�ƽ,��ʱΪ1����Ϊ0
{
	return GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13);
}