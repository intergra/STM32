#include <stm32f10x.h>                  // Device header
#include <Delay.h>

int main()
{
	GPIO_InitTypeDef GPIO_InitStructure;//结构体的定义，右边是结构体的名称
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//启用APB2的外设时钟
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//结构体的三种参数
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);//GPIO初始化函数，根据结构体中的参数来初始化
	
	while(1)
	{
		//GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_RESET);
		Delay_ms(200);
		GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_SET);
		Delay_ms(200);
	}
}
