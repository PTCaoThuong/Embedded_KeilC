typedef enum{
	UNINIT,
	IDLE,
	BUSY,
	EMPTY,
	NOT_EMP
}STATE;

void LPUART1_send_char(char data);
void LPUART1_send_string(char*  data_string );
void Clock_init(void);
void LPUART_init(void);
void LPUART_Interrupt(void);
void LPUART1_RxTx_IRQHandler(void);
void Led_init(void);
void turn_off_led(void);
void turn_on_led(void);
void received_string(void);
void control_led(char* buffer);
void Uart_Init(void);
extern volatile STATE t_state;
extern volatile STATE r_state;
void Uart_Transmit(unsigned char* u8_TxBuffer, unsigned int u4_Length);
void Uart_TxMainFunction(void);
void	Uart_GetReceiveData(void);
void Uart_RxMainFunction(unsigned char* u8_RxBuffer);
unsigned char Uart_GetTransmitState(void);
unsigned char Uart_GeReceiveState(void);
