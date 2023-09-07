#include"GPIO.h"
#include"Softtimer.h"

#define GPIO_START_SECT_DATA_UNINIT
#include"Gpio_Memmap.h"
volatile unsigned int Check=0;
#define GPIO_STOP_SECT_DATA_UNINIT
#include"Gpio_Memmap.h"

int main(void){
	Softtimer_Init();
	INTERRUPT_BTN_init();
	LEDS_init();
	Turn_off_allled();
	
	Softtimer_StartTimer(1, 50, 1 , &Event_1);
	Softtimer_StartTimer(2, 10, 2 , &Event_2);
//	Softtimer_StartTimer(3, 60, 1, &Event_3);
	while(1){
		Softtimer_MainFunction();
		if(Check == 1){
		Softtimer_StopTimer(1);
		Turn_off_Led(GREEN);
		Check = 0;
		}
		else if(Check == 2){
		Softtimer_StopTimer(2);
		Check = 0;
		}

	}
}
