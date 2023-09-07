#include "s32k144.h"

void Clock_init(void);
void LPSPI_init(void);
void LPSPI1_send_char(char data);
void LPSPI1_send_string(char *data);

int main()
{
	/* Initialize clock: Enable FIRC_DIV2 */
	Clock_init();
	
	/* Initialize LPSPI 1 */
	LPSPI_init();
	
	/* Send char */
	LPSPI1_send_char('s');
	while(1)
	{
		
	}
}
void Clock_init(void)
{
	SCG->FIRCDIV |= (1<<8u);    /* Fast IRC Clock Divide 2 : 1*/
}


void LPSPI_init(void)
{
	/* Pin number        | Function
	* ----------------- |------------------
	* PTB14             | LPSPI1_SCK
	* PTB16			        | LPSPI1_SOUT
	* PTB17			        | LPSPI1_PCS3 */
	
	/* 1. Setting SCK/PCS/SOUT/SIN pin */
	PCC->PCCn[PCC_PORTB_INDEX] |= (1u<<30u);  /* Enable clock for PORTB */
	PORTB->PCR[14] |= (3u<<8u); 							/* Port B14: MUX = ALT3, LPSPI1_SCK */
	PORTB->PCR[15] |= (3u<<8u); 							/* Port B15: MUX = ALT3, LPSPI1_SIN */
	PORTB->PCR[16] |= (3u<<8u); 							/* Port B16: MUX = ALT3, LPSPI1_SOUT */
	PORTB->PCR[17] |= (3u<<8u); 							/* Port B17: MUX = ALT3, LPSPI1_PCS3 */

	/* 2. Select source LPUART  */
	PCC->PCCn[PCC_LPSPI1_INDEX] |= (3<<24u);   /* Select source: FIRCDIV2_CLK = 48MHz */
	PCC->PCCn[PCC_LPSPI1_INDEX] |= (1<<30u);   /* Enable clock for LPURAT */
		
	/* 8. Configures LPSPI mode */
	LPSPI1->CFGR1 |= ((1u)|(1u<<3u));    /* No Stall if Tx FIFO empty or Rx FIFO full*/


	/* 3. Setting baud rate */
	/* Configures Clock Phase and Polarity */
	/*  Set frame size is 8 bits*/
	/* Transfer using PCS3  */
	LPSPI1->TCR = ((3u<<27u)|(7u)|(3u<<24u));
	LPSPI1->CCR |= (4u);


	/* 7. Setting Transmit/Receive FIFO */
	LPSPI1->FCR  |= (3u);

	/* 9. Enable LPSPI module */
	LPSPI1->CR |= (1u<<3u);
	LPSPI1->CR |= (1u);
	
}

void LPSPI1_send_char(char data)
{
		while((LPSPI1->SR & (1u)) == 0 ){}
                                   /* Wait for Tx FIFO available 	*/
  LPSPI1->TDR = data;              /* Transmit data 				*/

}

void LPSPI1_send_string(char*  data )  
{  
	(void)data;
}
