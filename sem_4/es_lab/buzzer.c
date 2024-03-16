#include <LPC17xx.h>
int i;
int main(void)
{
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 &= ~(3 << 22); // P0.11
	LPC_GPIO0->FIODIR |= 0x00000800;

		LPC_GPIO0->FIOSET = 0x00000800;
		for(i=0;i<500;i++);
		LPC_GPIO0->FIOSET = 0 << 24;
}
