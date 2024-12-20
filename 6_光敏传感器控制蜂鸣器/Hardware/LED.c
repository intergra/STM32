#include "stm32f10x.h"                  // Device header
void LED_Init()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//����APB2������ʱ��
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//�ṹ������ֲ���
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);//GPIO��ʼ�����������ݽṹ���еĲ�������ʼ��
	
	GPIO_WriteBit(GPIOA,GPIO_Pin_1|GPIO_Pin_2,Bit_SET);//��Ĭ�ϵĵ͵�ƽ����Ϊ�ߵ�ƽ
}

//LED1�ĸ�������A1��LED2�ĸ�������A2

void LED1_ON()//LED1����
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_1);
}

void LED1_OFF()//LED1Ϩ��
{
	GPIO_SetBits(GPIOA,GPIO_Pin_1);
}

void LED1_Turn()//��A1���ŵĸߣ��͵�ƽ��ת
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_1)==1)
		GPIO_ResetBits(GPIOA,GPIO_Pin_1);
	else
		GPIO_SetBits(GPIOA,GPIO_Pin_1);
}

void LED2_ON()//LED2����
{
	GPIO_ResetBits(GPIOA,GPIO_Pin_2);
}

void LED2_OFF()//LED2Ϩ��
{
	GPIO_SetBits(GPIOA,GPIO_Pin_2);
}

void LED2_Turn()//��A2���ŵĸߣ��͵�ƽ��ת
{
	if(GPIO_ReadOutputDataBit(GPIOA,GPIO_Pin_2)==1)
		GPIO_ResetBits(GPIOA,GPIO_Pin_2);
	else
		GPIO_SetBits(GPIOA,GPIO_Pin_2);
}