/* Q3. Write a C program for 4 digit BCD up/down counters on seven segment using a
switch and timer with a delay of 1-second between each count. */

#include <LPC17xx.h>

unsigned char array[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
unsigned int seg_select[4]={0<<23,1<<23,2<<23,3<<23};
int dig[4]={0,0,0,0};
unsigned int i, j;

void initTimer0(void)
{
	LPC_TIM0->CTCR = 0x0;
	LPC_TIM0->TCR = 0x02;
	LPC_TIM0->PR = 2;
	LPC_TIM0->MR0 = 999;
	LPC_TIM0->MCR = 2;
	LPC_TIM0->EMR = 0x20;
	LPC_TIM0->TCR = 0x01;
}

void delay(void)
{
	initTimer0();
		while(!(LPC_TIM0-> EMR & 1));
}

void bcd_down();

void bcd_up()
{
	for(dig[3]=0;dig[3]<=9;dig[3]++)
		{
			for(dig[2]=0;dig[2]<=9;dig[2]++)
		{
			for(dig[1]=0;dig[1]<=9;dig[1]++)
		{
			for(dig[0]=0;dig[0]<=9;dig[0]++)
		{
			for(i=0;i<4;i++)
			{
				LPC_GPIO1->FIOPIN=seg_select[i];
				LPC_GPIO0->FIOPIN=array[dig[i]]<<4;
				if(LPC_GPIO2->FIOPIN&1)
				{
					bcd_down();
				}
				delay();
			}
			delay();
			LPC_GPIO0->FIOCLR |= 0xFF0;
		}
		}
		}
		}
}

void bcd_down()
{
	for(dig[3]=9;dig[3]>=0;dig[3]--)
		{
			for(dig[2]=9;dig[2]>=0;dig[2]--)
		{
			for(dig[1]=9;dig[1]>=0;dig[1]--)
		{
			for(dig[0]=9;dig[0]>=0;dig[0]--)
		{
			for(i=0;i<4;i++)
			{
				LPC_GPIO1->FIOPIN=seg_select[i];
				LPC_GPIO0->FIOPIN=array[dig[i]]<<4;
				if(!(LPC_GPIO2->FIOPIN&1))
				{
					bcd_up();
				}
				
				delay();
			}
			delay();
			LPC_GPIO0->FIOCLR |= 0xFF0;
		}
		}
		}
		}
}

int main() {
    SystemInit();
    SystemCoreClockUpdate();
    LPC_GPIO0->FIODIR |= 0xFF0;
    LPC_GPIO1->FIODIR |= 0xF << 23;
	LPC_GPIO2->FIODIR &= 0xFFFFFFFE;
		
		
		while(1)
		{
			if(LPC_GPIO2->FIOPIN&1)
			{
				bcd_down();
				delay();
			}
			else
			{
				bcd_up();
				delay();
			}
		}
	return 0;
}
