#include <stm32f10x.h>                  // Device header
#include <Delay.h>

int main()
{
	GPIO_InitTypeDef GPIO_InitStructure;//�ṹ��Ķ��壬�ұ��ǽṹ�������
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//����APB2������ʱ��
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//�ṹ������ֲ���
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB,&GPIO_InitStructure);//GPIO��ʼ�����������ݽṹ���еĲ�������ʼ��
	
	while(1)
	{
		//GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_RESET);
		Delay_ms(200);
		GPIO_WriteBit(GPIOB,GPIO_Pin_12,Bit_SET);
		Delay_ms(200);
	}
}
