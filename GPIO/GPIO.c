#include"S32K144.h"
#include"GPIO.h"

#define GPIO_START_SECT_CODE
#include"Gpio_Memmap.h"
/* Bitwise operators */
void Gpio_SetPinValue(volatile unsigned int* PORT, unsigned int pin, unsigned int Value){
	(*PORT) |= (Value<<pin);
}

void Gpio_ClearPinValue(volatile unsigned int* PORT, unsigned int pin){
	(*PORT) &= ~(1<<pin);
}

void Gpio_GetPinValue(volatile unsigned int *PORT, unsigned int pin, unsigned int* Value){
	*(Value) = (*(PORT)>>pin) & 1;
}

unsigned int Gpio_GetPinValue_1(volatile unsigned int *PORT, unsigned int pin){
	return ((*(PORT)>>pin) & 1);
}

/* GPIO PORT D */
void LEDS_init(void){
	/* Enable clock for Port D */
	Gpio_SetPinValue(&(PCC->PCC_PORTD),30,1);
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


/* GPIO PORT C */
void INTERRUPT_BTN_init(void){
	/* Enable clock for Port C */
	Gpio_SetPinValue(&(PCC->PCC_PORTC),30,1);
	/* Set pin as GPIO */
	Gpio_SetPinValue(&(PCR_C->PORTC_PCR12),8,1);
	Gpio_ClearPinValue(&(PCR_C->PORTC_PCR12),9);
	Gpio_ClearPinValue(&(PCR_C->PORTC_PCR12),10);
	
	Gpio_SetPinValue(&(PCR_C->PORTC_PCR13),8,1);
	Gpio_ClearPinValue(&(PCR_C->PORTC_PCR13),9);
	Gpio_ClearPinValue(&(PCR_C->PORTC_PCR13),10);
	
	/* Disabled pull-up/pull-down */
	Gpio_ClearPinValue(&(PCR_C->PORTC_PCR12),1);
	Gpio_ClearPinValue(&(PCR_C->PORTC_PCR13),1);
	
	/* Set interrupt type */
	Gpio_SetPinValue(&(PCR_C->PORTC_PCR12),16,9);
	Gpio_SetPinValue(&(PCR_C->PORTC_PCR13),16,9);

	/* Set pin as input */
	Gpio_ClearPinValue(&(GPIO_C->PDDR_C),12);
	Gpio_ClearPinValue(&(GPIO_C->PDDR_C),13);
	
	/* Enable NVIC for Port C */
	Gpio_SetPinValue(&(NVIC->ISER[1]),29,1); /* Port C NVIC interrupt ID is 61 */
}

void Delay_s(float n)
{
	for(float i = 0; i<(1000000*n); i++){}
}

void Turn_on_led(unsigned int a){
	/* turn off all led (logic 1 led off)*/
	Gpio_SetPinValue(&(GPIO_D->PDOR_D),0,1);
	Gpio_SetPinValue(&(GPIO_D->PDOR_D),15,1);
	Gpio_SetPinValue(&(GPIO_D->PDOR_D),16,1);
	/* turn on led */
	Gpio_ClearPinValue(&(GPIO_D->PDOR_D),a);
}

void BLUE_always_on(unsigned int a){
	/* turn off red and green (logic 1 led off)*/
	Gpio_SetPinValue(&(GPIO_D->PDOR_D),15,1);
	Gpio_SetPinValue(&(GPIO_D->PDOR_D),16,1);
	/* turn on led */
	Gpio_ClearPinValue(&(GPIO_D->PDOR_D),a);
}
#define GPIO_STOP_SECT_CODE
#include"Gpio_Memmap.h"


