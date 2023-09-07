/* Function prototype (GPIO.c) */

void PORTC_IRQHandler(void);
void Program_1(void);
void Program_2(void);
void LEDS_init(void);
void INTERRUPT_BTN_init(void);
void Delay_s(float n);
void Turn_on_led(unsigned int a);
void BLUE_always_on(unsigned int a);
extern volatile int Check_IRQ;
extern volatile int Count_Second;
void Gpio_SetPinValue(volatile unsigned int* PORT, unsigned int pin, unsigned int Value);
void Gpio_ClearPinValue(volatile unsigned int* PORT, unsigned int pin);
void Gpio_GetPinValue(volatile unsigned int *PORT, unsigned int pin, unsigned int* Value);
unsigned int Gpio_GetPinValue_1(volatile unsigned int *PORT, unsigned int pin);
