#include "main.h"
void delay(uint32_t itime);
GPIO_InitTypeDef GPIO_InitStructure;
uint8_t  button;
int main()
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC , ENABLE);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA , ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_40MHz;
	GPIO_Init(GPIOC,&GPIO_InitStructure);
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	while(1)
	{
		button = GPIO_ReadInputDataBit(GPIOA ,GPIO_Pin_0);
		if(button == 1)
		{
		GPIO_SetBits(GPIOC,GPIO_Pin_8 | GPIO_Pin_9);
		delay(100000);
		GPIO_ResetBits(GPIOC,GPIO_Pin_8 | GPIO_Pin_9);
		delay(100000);
		}
	}
}
void delay(uint32_t itime)
{
	uint32_t i;
	for(i=0;i<itime;i++);
}