#include"S32K144.h"
#include"GPIO.h"

#define BLUE 0
#define RED 15
#define GREEN 16

volatile unsigned check;

#define GPIO_START_SECT_DATA_UNINIT
#include"Gpio_Memmap.h"

 /* Bien de phat hien ngat */
volatile int Count_Second=0;
volatile int Check_IRQ=0;

#define GPIO_STOP_SECT_DATA_UNINIT
#include"Gpio_Memmap.h"

int main(void){
	LEDS_init();
	INTERRUPT_BTN_init();
	
	/* Assignment 3 */
	/* turn on red 5s */
	Turn_on_led(BLUE);
	TEXT:	if(Check_IRQ==0){ /* Check interrput every 0.5s */
		for(int i=0;i<500000;i++){
			Count_Second++;
		}
	if(Count_Second<5000000){
		goto TEXT;
	}
	else{
		Gpio_SetPinValue(&(GPIO_D->PDOR_D), 0,1); /* Turn off Blue after 5s */
	}
	}
	while(1){
		check = GPIO_C->PDIR_C;
		if(Check_IRQ == 1){
			Program_1();
		}
		else if(Check_IRQ == 2){
			Program_2();
		}
	}
}
