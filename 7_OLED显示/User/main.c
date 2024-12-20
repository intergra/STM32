#include <stm32f10x.h>                  // Device header
#include <Delay.h>
#include <OLED.h>

int main()
{
	OLED_Init();
	while(1)
	{
		OLED_ShowChar(1,1,'A');
		OLED_ShowString(1,4,"HelloWorld!");
		OLED_ShowSignedNum(2,1,-6,1);
	}
	
}
