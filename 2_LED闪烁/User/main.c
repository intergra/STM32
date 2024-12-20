#include <stm32f10x.h>                  // Device header
#include <Delay.h>

int main()
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//启用APB2的外设时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;//结构体的定义，右边是结构体的名称
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//结构体的三种参数
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);//GPIO初始化函数，根据结构体中的参数来初始化
	
	while(1)
	{
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
		Delay_ms(50);
		GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
		Delay_ms(50);
		
		GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_RESET);
		Delay_ms(50);
		GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_SET);
		Delay_ms(50);
	}
}
