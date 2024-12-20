#include <stm32f10x.h>                  // Device header
#include <Delay.h>

int main()
{
	GPIO_InitTypeDef GPIO_InitStructure;//�ṹ��Ķ��壬�ұ��ǽṹ�������
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//����APB2������ʱ��
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//�ṹ������ֲ���
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOA,&GPIO_InitStructure);//GPIO��ʼ�����������ݽṹ���еĲ�������ʼ��
	
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
		
		GPIO_WriteBit(GPIOA,GPIO_Pin_2,Bit_RESET);
		Delay_ms(50);
		GPIO_WriteBit(GPIOA,GPIO_Pin_2,Bit_SET);
		Delay_ms(50);
		
		GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_RESET);
		Delay_ms(50);
		GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_SET);
		Delay_ms(50);
		
		GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_RESET);
		Delay_ms(50);
		GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_SET);
		Delay_ms(50);
		
		GPIO_WriteBit(GPIOA,GPIO_Pin_5,Bit_RESET);
		Delay_ms(50);
		GPIO_WriteBit(GPIOA,GPIO_Pin_5,Bit_SET);
		Delay_ms(50);
		
		GPIO_WriteBit(GPIOA,GPIO_Pin_6,Bit_RESET);
		Delay_ms(50);
		GPIO_WriteBit(GPIOA,GPIO_Pin_6,Bit_SET);
		Delay_ms(50);
		
		GPIO_WriteBit(GPIOA,GPIO_Pin_7,Bit_RESET);
		Delay_ms(50);
		GPIO_WriteBit(GPIOA,GPIO_Pin_7,Bit_SET);
		Delay_ms(50);
	}
}
