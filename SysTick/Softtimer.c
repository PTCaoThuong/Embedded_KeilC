#include"Softtimer.h"
#include"Systick_Register.h"
#include"GPIO.h"


typedef struct Softtimer
{
    unsigned int TimerID;
    unsigned int TimeoutValue;
    unsigned int CurrentTime;
		unsigned int ModeTimer;
    CALLBACK Callback;
} Softtimer;

#define SYSTICK_START_SECT_DATA_UNINIT
#include"Systick_Memmap.h"
volatile unsigned int TimeCountMs;
static volatile unsigned int Check_event=0;
static volatile unsigned int Check_event4=0;
static Softtimer Array_Timer[4];
#define SYSTICK_STOP_SECT_DATA_UNINIT
#include"Systick_Memmap.h"

#define SYSTICK_START_SECT_CODE
#include"Systick_Memmap.h"

void Softtimer_Init(void){
	/* Control */
	SYST->SYST_CSR = 0; /* Disable the SysTick */
	/* Reload */
	SYST->SYST_RVR = 4800000-1; /* Write the new reload value (4800000 -> 100ms) */
	/* Current */
	SYST->SYST_CVR = 0; /* Clear value register */
	SYST->SYST_CSR |= (1<<1);/* SysTick exception */
	SYST->SYST_CSR |= (1<<2); /* Processor clock */
	/* Enable */
	SYST->SYST_CSR |= (1);
	/* Create TimeCoutMS */
	TimeCountMs=0;
	for(int i=0 ;i<4;i++){
	Array_Timer[i].TimerID = 0;
	}
	
}


void SysTick_Handler(void){
	TimeCountMs+=1;
}



void Softtimer_StartTimer ( unsigned int TimerID, unsigned int TimeoutValue, unsigned char Mode, CALLBACK Event)
{
	  Array_Timer[TimerID].TimerID = TimerID;
    Array_Timer[TimerID].TimeoutValue = TimeoutValue;
    Array_Timer[TimerID].Callback = Event;
    Array_Timer[TimerID].CurrentTime = TimeCountMs;
		Array_Timer[TimerID].ModeTimer = Mode;
		
}



void Softtimer_MainFunction(void)
{	
	for(int i=1; i<4;i++){
		if(Array_Timer[i].TimerID == 0){ /* Check neu chua nhap ID thi khong thuc hien chuong trinh */
			Array_Timer[i].CurrentTime = 0; 
			Array_Timer[i].TimeoutValue = 0;
		}
		else{
			if ( TimeCountMs >= (Array_Timer[i].CurrentTime + Array_Timer[i].TimeoutValue) )
			{
			Array_Timer[i].Callback();
				if(Array_Timer[i].ModeTimer == 2){
        Array_Timer[i].CurrentTime = TimeCountMs;
				}
				else if(Array_Timer[i].ModeTimer == 1){
				Array_Timer[i].CurrentTime = 0;
				Array_Timer[i].TimeoutValue = 0;
				}
			}
		}
	}
}





void Event_1(void){
	Turn_on_led(GREEN);
	Turn_on_led(BLUE);
}

void Event_2(void){
	Toggle_led(RED);
}
 
void Event_3(void){
	if(Check_event == 0){
	Turn_off_Led(BLUE);
	Turn_on_led(GREEN);
		Check_event+=1;
	}
	else if(Check_event == 1){
		Turn_off_Led(GREEN);
		Turn_on_led(RED);
		Check_event+=1;
	}
	else if(Check_event == 2){
		Turn_off_Led(RED);
		Turn_on_led(BLUE);
		Check_event =0;
	}
}

void Even_4(void){
	if(Check_event4 == 0){
		Turn_off_Led(RED);
		Turn_on_led(GREEN);
		Check_event4+=1;
	}
	else if(Check_event4 == 1){
	Turn_off_Led(GREEN);
	Turn_on_led(RED);
		Check_event4=0;
	}
}

void Softtimer_StopTimer ( unsigned int Timer_ID ){

	Array_Timer[Timer_ID].TimerID = 0;
}



void Delay(unsigned int Cnt_100ms){
	while(Cnt_100ms){
		if((SYST->SYST_CSR>>16)==1){
		Cnt_100ms--;
		}
			
	}
}

#define SYSICK_STOP_SECT_CODE
#include"Systick_Memmap.h"

