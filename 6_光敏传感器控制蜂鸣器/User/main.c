#include <stm32f10x.h>                  // Device header
#include <Delay.h>
#include <Buzzer.h>
#include <LightSensor.h>

int main()
{
	LightSensor_Init();
	Buzzer_Init();
	
	while(1)
	{
		if(LigntSensor_Get()==1)//��ȡ������������Ӧ���ŵĵ�ƽ,��ʱΪ1����Ϊ0
		{
			Buzzer_ON();
		}
		else
		{
			Buzzer_OFF();
		}
			
	}
	
}
