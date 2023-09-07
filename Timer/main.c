#include"Timer_Register.h"
#include"stdio.h"

void Gpio_SetPinValue(volatile unsigned int* PORT, unsigned int pin, unsigned int Value);
void Gpio_ClearPinValue(volatile unsigned int* PORT, unsigned int pin);
void LEDS_init(void);
void LPIT0_Ch2_IRQHandler(void);
void LPIT0_Ch3_IRQHandler(void);
void Turn_on_led(int a);
void init_channel_2(void);
void init_channel_0(void);
void init_channel_3(void);
//static volatile unsigned int stop;
//static volatile unsigned int start;
//static volatile unsigned int result;

static volatile unsigned int ss=56;
static volatile unsigned int mm=0;
static volatile unsigned int hh=0;
static unsigned int check = 0;
static unsigned int check_channel_3=0;
int main(void){


	/* Assignment 1 */	
	/* Get timer counter value */
//	start = LPIT_0->CVAL0;
//	for(int i=0;i<100000;i++);
//	stop = LPIT_0->CVAL0;
//	if(stop < start){
//	result = start - stop;
//	}
//	else {
//	result = 0xffffffff - stop + start;
//	}
	
//	/* Assignment 2 */
//	init_channel_2();
//	LEDS_init();
//	/* turn off all led (logic 1 led off)*/
//	Gpio_SetPinValue(&(GPIO_D->PDOR_D),0,1);
//	Gpio_SetPinValue(&(GPIO_D->PDOR_D),15,1);
//	Gpio_SetPinValue(&(GPIO_D->PDOR_D),16,1);

	/* Assignment 3 */

init_channel_3();
	while(1){
//		if(check == 1){
//		check =0;
//		GPIO_D->PDOR_D ^= (1u<<15);
//		}
		
		/* Assignment 3 */
	if(check_channel_3 == 1){
	check_channel_3 = 0;
		if(ss>59){
			ss=0;
			mm+=1;
			if(mm>59){
			mm=0;
			hh+=1;
			}
				if(hh>23){
				hh=0;
				}
		}
		else{
		ss+=1;
		}
	}
		
		
	}



}

void init_channel_0(void){
	//	/* Setting clocking */
	PCC->LPIT |= (7<<24);
	PCC->LPIT |= (1<<30);
	/* LPIT Initialization */
	LPIT_0->MCR |= 1;
	LPIT_0->MCR |= (1u<<3); /* 0b - Stop timer channels in Debug mode */
	/* Configure for channel */
	LPIT_0->TCTRL0 &= ~(1u<<2);
	LPIT_0->TCTRL0 &= ~(1u<<3);
	/* Enable */
	LPIT_0->TCTRL0 |= (1);
	/* Set timer value start */
	LPIT_0->TVAL0 = 0xffffffff;
	
}

void init_channel_2(void){
	/* Setting NVIC */
	NVIC->ISER1 |= (1<<18); /* 50 */
	/* Setting clocking */
	PCC->LPIT |= (7<<24);
	PCC->LPIT |= (1<<30);
	/* LPIT Initialization */
	LPIT_0->MCR |= 1;
	LPIT_0->MCR |= (1u<<3); /* 0b - Stop timer channels in Debug mode */

	/* Enable channel 2 timer interrupt */
	LPIT_0->MIER |= (1<<2);
	/* Channel 2 Timer Interrupt Flag */
	LPIT_0->MSR = 0x04;
	/* Set timer value start */
	LPIT_0->TVAL2 = 64000-1;
	/* Configure for channel */
	LPIT_0->TCTRL2 &= ~(1u<<2);
	LPIT_0->TCTRL2 &= ~(1u<<3);
		/* Enable */
	LPIT_0->TCTRL2 |= (1);
}

void init_channel_3(void){
	/* Setting NVIC */
	NVIC->ISER1 |= (1<<19); /* 51 */
	/* Setting clocking */
	PCC->LPIT |= (7<<24);
	PCC->LPIT |= (1<<30);
	/* LPIT Initialization */
	LPIT_0->MCR |= 1;
	LPIT_0->MCR |= (1u<<3); /* 0b - Stop timer channels in Debug mode */

	/* Enable channel 3 timer interrupt */
	LPIT_0->MIER |= (1<<3);
	/* Channel 3 Timer Interrupt Flag */
	LPIT_0->MSR = 0x8;
	/* Set timer value start */
	LPIT_0->TVAL3 = 128000-1;
	/* Configure for channel */
	LPIT_0->TCTRL3 &= ~(1u<<2);
	LPIT_0->TCTRL3 &= ~(1u<<3);
		/* Enable */
	LPIT_0->TCTRL3 |= (1);
}

/* Bitwise operators */
void Gpio_SetPinValue(volatile unsigned int* PORT, unsigned int pin, unsigned int Value){
	(*PORT) |= (Value<<pin);
}

void Gpio_ClearPinValue(volatile unsigned int* PORT, unsigned int pin){
	(*PORT) &= ~(1<<pin);
}

/* GPIO PORT D */
void LEDS_init(void){
	/* Enable clock for Port D */
	Gpio_SetPinValue(&(PCC->PORTD),30,1);
	/* Set pin as GPIO */
	Gpio_SetPinValue(&(PCR_D->PORTD_PCR0),8,1);
	Gpio_ClearPinValue(&(PCR_D->PORTD_PCR0),9);
	Gpio_ClearPinValue(&(PCR_D->PORTD_PCR0),10);

	Gpio_SetPinValue(&(PCR_D->PORTD_PCR15),8,1);
	Gpio_ClearPinValue(&(PCR_D->PORTD_PCR15),9);
	Gpio_ClearPinValue(&(PCR_D->PORTD_PCR15),10);	

	Gpio_SetPinValue(&(PCR_D->PORTD_PCR16),8,1);
	Gpio_ClearPinValue(&(PCR_D->PORTD_PCR16),9);
	Gpio_ClearPinValue(&(PCR_D->PORTD_PCR16),10);	
	
	/* Disabled pull-up/pull-down */
	Gpio_ClearPinValue(&(PCR_D->PORTD_PCR0),1);
	Gpio_ClearPinValue(&(PCR_D->PORTD_PCR15),1);
	Gpio_ClearPinValue(&(PCR_D->PORTD_PCR16),1);

	/* Set pin as output */
	Gpio_SetPinValue(&(GPIO_D->PDDR_D),0,1);
	Gpio_SetPinValue(&(GPIO_D->PDDR_D),15,1);
	Gpio_SetPinValue(&(GPIO_D->PDDR_D),16,1);
}

void LPIT0_Ch2_IRQHandler(void){
	if(	LPIT_0->MSR & (1<<2) ){
	LPIT_0->MSR = 0x04;
	check = 1;
	}
} 

void LPIT0_Ch3_IRQHandler(void){
	if(	LPIT_0->MSR & (1<<3) ){
	LPIT_0->MSR = 0x08;
	check_channel_3 = 1;
	}
} 

void Turn_on_led(int a){
	/* turn off all led (logic 1 led off)*/
	Gpio_SetPinValue(&(GPIO_D->PDOR_D),0,1);
	Gpio_SetPinValue(&(GPIO_D->PDOR_D),15,1);
	Gpio_SetPinValue(&(GPIO_D->PDOR_D),16,1);
	/* turn on led */
	GPIO_D->PDOR_D &= ~(1u<<a);
}
