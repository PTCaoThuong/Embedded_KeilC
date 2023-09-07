#define BLUE 0
#define RED 15
#define GREEN 16
extern volatile unsigned int TimeCountMs;
void Softtimer_Init(void);
void SysTick_Handler(void);
typedef void ( *CALLBACK )( void );
void Softtimer_StartTimer(unsigned int TimerID, unsigned int TimeoutValue, unsigned char Mode, CALLBACK Event);
void Softtimer_StartTimer1 ( unsigned int TimerID, unsigned int TimeoutValue, unsigned char Mode, CALLBACK Event);
void Softtimer_MainFunction(void);
void Softtimer_MainFunction1(void);
void Event_1(void);
void Event_2(void);
void Event_3(void);
void Even_4(void);
void Softtimer_StopTimer ( unsigned int Timer_ID );
void Delay(unsigned int Cnt_100ms);
