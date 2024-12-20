#include <stm32f10x.h>                  // Device header
#include <Delay.h>
#include <LED.h>
#include <Key.h>

int main()
{
	uint8_t KeyNum=0;
	LED_Init();
	Key_Init();
	
	
	while(1)
	{
		KeyNum=Key_GetNum();
		if(KeyNum==1)
		{
			LED1_Turn();
		}
		if(KeyNum==2)
		{
			LED2_Turn();
		}
			
	}
}
