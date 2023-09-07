#include"uart_register.h"
#include"uart.h"


#define UART_START_SECT_DATA_UNINIT
#include"uart_memmap.h"
static volatile unsigned int index=0;
static volatile unsigned int t_index=0;
static volatile unsigned int r_index=0;
static volatile unsigned int r_index2=0;
static volatile char read[20];
static volatile unsigned int check = 0;
volatile unsigned char TxBuffer[30];
volatile unsigned char RxBuffer[30];
static volatile unsigned int t_length=0;
static volatile unsigned int r_length=0;
extern volatile STATE t_state;
extern volatile STATE r_state;
#define UART_STOP_SECT_DATA_UNINIT
#include"uart_memmap.h"


#define UART_START_SECT_DATA
#include"uart_memmap.h"
static volatile char read_data='0';
#define UART_STOP_SECT_DATA
#include"uart_memmap.h"

#define UART_START_SECT_CODE
#include"uart_memmap.h"
void LPUART_init(void){
	/* Setting Tx/Rx pin */
	PCC->PORTC |= (1<<30);
	PCR_C->PCR6 |= (2<<8);
	PCR_C->PCR7 |= (2<<8);
	
	/* Select source LPUART */
	PCC->LPUART1 |= (3<<24); /* FIRCDIV2_CLK */
	PCC->LPUART1 |= (1<<30); /* Enable Clock */
	/* Set Baud rate: 96000 */
	LPUART->BAUD &= ~(0x1fu<<24u);
	
	LPUART->BAUD &= ~(0x1fffu);
	LPUART->BAUD |= 312u;
	/* Setting Frame: 1 Stop bit, 8 bit format, no parity */
	LPUART->BAUD &= ~(1u<<13);
	LPUART->CTRL &= ~(1u<<4);
	LPUART->CTRL &= ~(1u<<1);
	
	/* Enable Tx & Rx */
	LPUART->CTRL |= (1<<18);
	LPUART->CTRL |= (1<<19);
	
}

void Clock_init(void){
	SCG->FIRCDIV |= (1<<8);

}

void LPUART_Interrupt(void){
	/* Enable NVIC */
	NVIC->ISER1 |= (1<<1);
	/* Setting Tx/Rx pin */
	PCC->PORTC |= (1<<30);
	PCR_C->PCR6 |= (2<<8);
	PCR_C->PCR7 |= (2<<8);
	
	/* Select source LPUART */
	PCC->LPUART1 |= (3<<24); /* FIRCDIV2_CLK */
	PCC->LPUART1 |= (1<<30); /* Enable Clock */
	/* Set Baud rate: 96000 */
	LPUART->BAUD &= ~(0x1fu<<24u);
	
	LPUART->BAUD &= ~(0x1fffu);
	LPUART->BAUD |= 312u;
	/* Setting Frame: 1 Stop bit, 8 bit format, no parity */
	LPUART->BAUD &= ~(1u<<13);
	LPUART->CTRL &= ~(1u<<4);
	LPUART->CTRL &= ~(1u<<1);
	/* Enable receiver interrupt */
	LPUART->CTRL |= (1<<21); /* RIE */
	
	/* Enable Tx & Rx */
	LPUART->CTRL |= (1<<18);
	LPUART->CTRL |= (1<<19);
		/* Variable */
	t_state = IDLE;
	r_state = EMPTY;
}
/* Assignment 5 */
//void LPUART1_RxTx_IRQHandler(void){
//	read_data = (char)(LPUART->DATA);
//		if(read_data == '1'){
//		turn_on_led();
//		}
//		else if(read_data == '0'){
//		turn_off_led();
//		}
//		else{}
//} 

/* Assignment 6 */
void LPUART1_RxTx_IRQHandler(void){
	read_data = (char)(LPUART->DATA);
	check = 1;
}



void received_string(void){
	if(index > 0 && check == 1){
	check = 0;
	read[index] = read_data;
	index++;
	}
	if(read_data == '[' && check == 1){
	check = 0;
	read[0] = read_data;
	index = 1;
	}
	if(read_data == ']'){
		read_data = '0';
		if(read[0]== '['){
			control_led(read);
		}
		index=0;
	}


}

void control_led(char* buffer){
		if(buffer[5] == 'N'){
			turn_on_led();
		}
		else{
			turn_off_led();
		}
}

void Uart_Init(void){
	/* Setting Tx/Rx pin */
	PCC->PORTC |= (1<<30);
	PCR_C->PCR6 |= (2<<8);
	PCR_C->PCR7 |= (2<<8);
	
	/* Select source LPUART */
	PCC->LPUART1 |= (3<<24); /* FIRCDIV2_CLK */
	PCC->LPUART1 |= (1<<30); /* Enable Clock */
	/* Set Baud rate: 96000 */
	LPUART->BAUD &= ~(0x1fu<<24u);
	
	LPUART->BAUD &= ~(0x1fffu);
	LPUART->BAUD |= 312u;
	/* Setting Frame: 1 Stop bit, 8 bit format, no parity */
	LPUART->BAUD &= ~(1u<<13);
	LPUART->CTRL &= ~(1u<<4);
	LPUART->CTRL &= ~(1u<<1);
	
	/* Enable Tx & Rx */
	LPUART->CTRL |= (1<<18);
	LPUART->CTRL |= (1<<19);
	/* Variable */
	t_state = IDLE;
	r_state = EMPTY;
	
}

unsigned char Uart_GetTransmitState(void){
	if(t_length != 0){
		return BUSY;
	}
	else{
		return IDLE;
	}
}

void Uart_Transmit(unsigned char* u8_TxBuffer, unsigned int u4_Length){
	if(t_state == IDLE){
		for(unsigned int i =0;i < u4_Length;i++){
			TxBuffer[i] = u8_TxBuffer[i];
			t_length++;
		}
	}
}


void Uart_TxMainFunction(void){
	if(t_state == BUSY){
	 if(LPUART->STAT & (1<<23u)){
		LPUART->DATA = TxBuffer[t_index];
		t_length--;
		t_index++;
	 }
//	 else{
//		 t_state = IDLE;
//	 }
	}
}

unsigned char Uart_GeReceiveState(void){
	if(LPUART->STAT & (1<<21u)){
		return NOT_EMP;
	}
	else{
		return EMPTY;
	}
}


void Uart_GetReceiveData(void){
	
	if(r_state == NOT_EMP){
			RxBuffer[r_index2] = (unsigned char)(LPUART->DATA);
			r_length++;
			r_index2++;
	}
		else{

		}
	
	
}

void Uart_RxMainFunction(unsigned char* u8_RxBuffer){
//	if(r_length>28){
//		while(r_length !=0){
//			RxBuffer[r_index]=u8_RxBuffer[r_index];
//			r_index++;
//			r_length--;
//		}
//		
//	}
	
	if(r_state == EMPTY && r_length != 0){
			u8_RxBuffer[r_index] = RxBuffer[r_index];
			r_index++;
			r_length--;
	}
	else if(r_state == EMPTY && (LPUART->STAT & (1<<20))){
		 r_index2=0;
		 r_index=0;
		 LPUART->STAT = 0x100000;

	 }
	
}
#define UART_STOP_SECT_CODE
#include"uart_memmap.h"



