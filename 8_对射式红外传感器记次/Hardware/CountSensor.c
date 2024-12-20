#include "stm32f10x.h"                  // Device header
#include <Delay.h>

uint16_t CountSensor_Count;//记录中断次数

void CountSensor_Init()//初始化红外传感器的同时将其配置外部中断
//配置外部中断要开启GPIO和AFIO的时钟，要初始化GPIO，AFIO(中断引脚选择)，EXTI(边缘选择及控制)，NVIC(优先级)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
 	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;//下拉输入，因为红外传感器默认为0，断开为1
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource14);//AFIO函数，进行外都中断引脚的选择配置
	
	EXTI_InitTypeDef EXTI_InitStruct;
	EXTI_InitStruct.EXTI_Line=EXTI_Line14;//第14个线路
	EXTI_InitStruct.EXTI_LineCmd=ENABLE;//开启中断
	EXTI_InitStruct.EXTI_Mode=EXTI_Mode_Interrupt;//中断模式
	EXTI_InitStruct.EXTI_Trigger=EXTI_Trigger_Falling;//下降沿触发
	//将EXTI的第14个线路配置为中断模式，下降沿触发，开启中断
	EXTI_Init(&EXTI_InitStruct);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//配置中断优先级，整个芯片只能用一种
	NVIC_InitTypeDef NVIC_InitStruct;
	NVIC_InitStruct.NVIC_IRQChannel=EXTI15_10_IRQn;//指定中断通道
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;//通道使能
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=1;//抢占优先级
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;//响应优先级
	
	NVIC_Init(&NVIC_InitStruct);
}

						   //根据中断通道选择中断函数,不需要声明，自动执行
void EXTI15_10_IRQHandler()//中断函数的名字都是固定的，写错了就进不了中断了
{
	if(EXTI_GetITStatus(EXTI_Line14)==SET)
	{
		CountSensor_Count++;
	}
	EXTI_ClearITPendingBit(EXTI_Line14);
	//在中断函数的末尾清楚中断标志位，防止一直申请中断导致程序卡死
}

uint16_t CountSensor_Get()
{
	return CountSensor_Count;
}

