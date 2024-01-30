#include <stm32f10x.h>
void delay_ms(uint16_t t);
void sys_delay(void);
int main()
{
		RCC->APB2ENR |= 0xFC; //Enable GPIO ports clocks
		GPIOC->CRH = 0x44344444; //PC13 as output
		while(1)
		{
				GPIOC->ODR ^= (1<<13); //toggle PC13
				for(int i=0;i < 1000;i++){
					sys_delay();
				}		
		}
}

void delay_ms(uint16_t t) {
volatile unsigned long l = 0;
for(uint16_t i = 0; i < t; i++)
	{
		for(l = 0; l < 6000; l++);
	}
}
void sys_delay(void)
{
	SysTick->LOAD = 72*1000 -1;
	SysTick->VAL = 0;
	SysTick ->CTRL = 5;
	while(!(SysTick->CTRL & (1<< 16))) {
	}
}

