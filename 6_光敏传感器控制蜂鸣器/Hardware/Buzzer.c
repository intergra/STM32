#include "stm32f10x.h"                  // Device header

void Buzzer_Init()//������ģ���IO�ڲ���B12��
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//����APB2������ʱ��
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//�ṹ������ֲ���
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);//GPIO��ʼ�����������ݽṹ���еĲ�������ʼ��
	
	GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_SET);//��Ĭ�ϵĵ͵�ƽ����Ϊ�ߵ�ƽ
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