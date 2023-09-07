void Gpio_SetPinValue(volatile unsigned int* PORT, unsigned int pin, unsigned int Value);
void Gpio_ClearPinValue(volatile unsigned int* PORT, unsigned int pin);
void Turn_on_led(int a);
void LEDS_init(void);
void Turn_off_allled(void);
void Toggle_led(int a);
void INTERRUPT_BTN_init(void);
void PORTC_IRQHandler(void);
extern volatile unsigned int Check;
void GPIO_A_Init(void);

void Turn_off_Led(unsigned int a);

