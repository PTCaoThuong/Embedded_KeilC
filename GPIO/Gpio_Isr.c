#include"S32K144.h"
#include"GPIO.h"

#define BLUE 0
#define RED 15
#define GREEN 16


extern volatile int Check_IRQ;
extern volatile int Count_Second;



#define GPIO_START_SECT_CODE
#include"Gpio_Memmap.h"
void PORTC_IRQHandler(void)
{	
	
	if(Gpio_GetPinValue_1(&(PCR_C-> PORTC_PCR12), 24)){
	Gpio_SetPinValue(&(PCR_C-> PORTC_PCR12),24,1);
	Check_IRQ=1;
	}
	else if(Gpio_GetPinValue_1(&(PCR_C-> PORTC_PCR13), 24)){
	Gpio_SetPinValue(&(PCR_C-> PORTC_PCR13),24,1);
	Check_IRQ=2;
	}
}

/* Program 1 */
void Program_1(void){
	if(Count_Second <5000000 && Check_IRQ==1){ /* Kiem tra delay du 5s chua, neu chua tiep tuc cho blue led on */
		Gpio_ClearPinValue(&(GPIO_D->PDOR_D), BLUE);
		BLUE_always_on(GREEN);
		Delay_s(1);
		Count_Second+=1000000;
	}
	if(Count_Second <5000000 && Check_IRQ==1){ /* Kiem tra delay du 5s chua, neu chua tiep tuc cho blue led on */
		Gpio_ClearPinValue(&(GPIO_D->PDOR_D), BLUE);
		BLUE_always_on(RED);
		Delay_s(1);
		Count_Second+=1000000;
	}
	if(Count_Second <5000000 && Check_IRQ==1){ /* Kiem tra delay du 5s chua, neu chua tiep tuc cho blue led on */
		Gpio_ClearPinValue(&(GPIO_D->PDOR_D), BLUE);
		BLUE_always_on(BLUE);
		Delay_s(1);
		Count_Second+=1000000;
	}
	else if(Count_Second>=5000000){ /* Kiem tra delay du 5s thi chay program 1 binh thuong */
		if(Check_IRQ==1){
		Turn_on_led(GREEN);
		Delay_s(1);
		}
		if(Check_IRQ==1){
		Turn_on_led(RED);	
		Delay_s(1);
		}
		if(Check_IRQ==1){
		Turn_on_led(BLUE);	
		Delay_s(1);
		}
		else if(Check_IRQ==2){
		Program_2();
		}
	}
	else if(Check_IRQ==2){
	Program_2();
	}
}

/* Program 2 */
void Program_2(void){
		if(Count_Second <5000000 && Check_IRQ==2){ /* Kiem tra delay du 5s chua, neu chua tiep tuc cho blue led on */
		Gpio_ClearPinValue(&(GPIO_D->PDOR_D), BLUE);
		BLUE_always_on(GREEN);
		Delay_s(0.5);
		Count_Second+=500000;
	}
		if(Count_Second <5000000 && Check_IRQ==2){ /* Kiem tra delay du 5s chua, neu chua tiep tuc cho blue led on */
		Gpio_ClearPinValue(&(GPIO_D->PDOR_D), BLUE);
		BLUE_always_on(RED);
		Delay_s(0.5);
		Count_Second+=500000;
	}

	else if(Count_Second>=5000000 && Check_IRQ==2){ /* Kiem tra delay du 5s thi chay program 2 binh thuong */
		if(Check_IRQ==2){
		Turn_on_led(GREEN);
		Delay_s(0.5);
		}
		if(Check_IRQ==2){
		Turn_on_led(RED);
		Delay_s(0.5);
		}
		else if(Check_IRQ==1){
		Program_1();
		}	
	}
	else if(Check_IRQ==1){
	Program_1();
	}
}
#define GPIO_STOP_SECT_CODE
#include"Gpio_Memmap.h"
