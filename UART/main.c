#include"uart_register.h"
#include"uart.h"



#define UART_START_SECT_DATA_UNINIT
#include"uart_memmap.h"
volatile STATE t_state = UNINIT;
volatile STATE r_state = UNINIT;
static volatile unsigned char receive[30];
#define UART_STOP_SECT_DATA_UNINIT
#include"uart_memmap.h"

#define UART_START_SECT_DATA
#include"uart_memmap.h"
static volatile unsigned char trans[30]="Pham Thanh Cao Thuong";
#define UART_STOP_SECT_DATA
#include"uart_memmap.h"


int main(void){

	Clock_init();
//	LPUART_init();
//	LPUART_Interrupt();
//	Led_init();
//	turn_off_led();
	Uart_Init();
//	Uart_Transmit(trans,21);
	while(1){
//		t_state = Uart_GetTransmitState();
//		Uart_TxMainFunction();
		
//	r_state=Uart_GeReceiveState();
//	Uart_GetReceiveData();
//	Uart_RxMainFunction(receive);
		
		


	}
}

#define UART_START_SECT_CODE
#include"uart_memmap.h"
void LPUART1_send_char(char data) {
    while((LPUART->STAT & (1<<23u)) == 0 );
    /* Wait for transmit buffer to be empty */
    LPUART->DATA = data;              /* Send data */
}

void LPUART1_send_string(char*  data_string )
{  /* Function to Transmit whole string */
	while(*data_string != '\0')  {		/* Send chars one at a time */
		LPUART1_send_char(*data_string);
		data_string++;
	}
}

void Led_init(void){
	/* Enable clock */
	PCC->PORTD |= (1<<30);
	/* Set pin GPIO */
	PCR_D->PORTD_PCR0 &= ~(7u<<8);
	PCR_D->PORTD_PCR0 |= (1<<8);
	/* Disable pull up/down */
	PCR_D->PORTD_PCR0 &= ~(1u<<1);
	/* Set pin out put */
	GPIO_D->PDDR_D |= 1;
	
}

void turn_off_led(void){
	GPIO_D->PDOR_D |= 1;
}

void turn_on_led(void){
	GPIO_D->PDOR_D &= ~(1u);
}

		/* Assignment 3 */
//		while((LPUART->STAT & (1<<21u))==0);
//		read_data = (char)(LPUART->DATA);
//	
//		if(read_data == '1'){
//			turn_on_led();
//		}
//		else{
//			turn_off_led();
//		}
#define UART_STOP_SECT_CODE
#include"uart_memmap.h"

