#include "stm32f10x.h"                  // Device header
#include <Delay.h>

uint16_t CountSensor_Count;//��¼�жϴ���

void CountSensor_Init()//��ʼ�����⴫������ͬʱ���������ⲿ�ж�
//�����ⲿ�ж�Ҫ����GPIO��AFIO��ʱ�ӣ�Ҫ��ʼ��GPIO��AFIO(�ж�����ѡ��)��EXTI(��Եѡ�񼰿���)��NVIC(���ȼ�)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;//�������룬��Ϊ���⴫����Ĭ��Ϊ0���Ͽ�Ϊ1
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);//AFIO�����������ⶼ�ж����ŵ�ѡ������
	
	EXTI_InitTypeDef EXTI_InitStruct;
	EXTI_InitStruct.EXTI_Line=EXTI_Line14;//��14����·
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;//�����ж�
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;//�ж�ģʽ
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;//�½��ش���
	//��EXTI�ĵ�14����·����Ϊ�ж�ģʽ���½��ش����������ж�
	EXTI_Init(&EXTI_InitStruct);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�������оƬֻ����һ��
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel=EXTI15_10_IRQn;//ָ���ж�ͨ��
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;//ͨ��ʹ��
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;//��ռ���ȼ�
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;//��Ӧ���ȼ�
	
	NVIC_Init(&NVIC_InitStruct);
}

						   //�����ж�ͨ��ѡ���жϺ���,����Ҫ�������Զ�ִ��
void EXTI15_10_IRQHandler()//�жϺ��������ֶ��ǹ̶��ģ�д���˾ͽ������ж���
{
	if(EXTI_GetITStatus(EXTI_Line14)==SET)
	{
		CountSensor_Count++;
	}
	EXTI_ClearITPendingBit(EXTI_Line14);
	//���жϺ�����ĩβ����жϱ�־λ����ֹһֱ�����жϵ��³�����
}

uint16_t CountSensor_Get()
{
	return CountSensor_Count;
}

