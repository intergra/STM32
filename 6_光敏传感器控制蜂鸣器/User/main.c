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
		if(LigntSensor_Get()==1)//获取光敏传感器对应引脚的电平,暗时为1，亮为0
		{
			Buzzer_ON();
		}
		else
		{
			Buzzer_OFF();
		}
			
	}
	
}
