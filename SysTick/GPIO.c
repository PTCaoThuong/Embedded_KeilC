#include"Gpio_Register.h"
#include"GPIO.h"
#include"Softtimer.h"
extern volatile unsigned int Check;

#define GPIO_START_SECT_CODE
#include"Gpio_Memmap.h"

void Turn_off_allled(void){
	Gpio_SetPinValue(&(GPIO_D->PDOR_D),0,1);
	Gpio_SetPinValue(&(GPIO_D->PDOR_D),15,1);
	Gpio_SetPinValue(&(GPIO_D->PDOR_D),16,1);
}

void Turn_on_led(int a){
	/* turn on led */
	GPIO_D->PDOR_D &= ~(1u<<a);
}

void Turn_off_Led(unsigned int a){
	Gpio_SetPinValue(&(GPIO_D->PDOR_D),a,1);
}

void Toggle_led(int a){

	GPIO_D->PDOR_D ^= (1u<<a);
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

/* GPIO A */

void GPIO_A_Init(void){
	PCC->PCC_PORTA |= (1<<30);
	/* Set pin as GPIO */
	PCR_A->PCR0 &= ~(4u<<8);
	PCR_A->PCR1 &= ~(4u<<8);
	PCR_A->PCR2 &= ~(4u<<8);
	PCR_A->PCR3 &= ~(4u<<8);
	PCR_A->PCR4 &= ~(4u<<8);
	/* Disabled pull-up/pull-down */
	PCR_A->PCR0 &= ~(1u<<1);
	PCR_A->PCR1 &= ~(1u<<1);
	PCR_A->PCR2 &= ~(1u<<1);
	PCR_A->PCR3 &= ~(1u<<1);
	PCR_A->PCR4 &= ~(1u<<1);
	/* Set pin as output */
	GPIO_A->PDDR_A |= ((1) | (1<<1) | (1<<2) | (1<<3) | (1<<4));
	
}

void PORTC_IRQHandler(void)
{
	if( PCR_C-> PORTC_PCR12 & (1u<<24u) ){
	PCR_C-> PORTC_PCR12 |= (1u<<24u);
	Check = 1;
	}
	else if(PCR_C-> PORTC_PCR13 & (1u<<24u) ){
	PCR_C-> PORTC_PCR13 |= (1u<<24u);
	Check = 2;
	}
}
#define GPIO_STOP_SECT_CODE
#include"Gpio_Memmap.h"
