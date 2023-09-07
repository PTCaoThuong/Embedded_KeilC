#include "s32k144.h"

void Clock_init(void);
void LPSPI_init(void);
void LPSPI1_send_char(unsigned short data);
void LPSPI1_send_string(char *data);

int main()
{

	
	/* Initialize clock: Enable FIRC_DIV2 */
	Clock_init();
	
	/* Initialize LPSPI 1 */
	LPSPI_init();
	
	/* intensity*/
	LPSPI1_send_char(0x0A01);
	
	/* scan limit*/
	LPSPI1_send_char(0x0B07);

	/* Normal Operation */
	LPSPI1_send_char(0x0C01);

	 /* Display Test */
//	LPSPI1_send_char(0x0F01);
 
		/* Decode mode */
	LPSPI1_send_char(0x09FF);

	 /* set 1 for led 0 */
	LPSPI1_send_char(0x0100);
	LPSPI1_send_char(0x0200);
	LPSPI1_send_char(0x030A);
	LPSPI1_send_char(0x0408);
	LPSPI1_send_char(0x0500);
	LPSPI1_send_char(0x060A);
	LPSPI1_send_char(0x0703);
	LPSPI1_send_char(0x0800);
	while(1)
	{
//		LPSPI1_send_string("Hello world!");
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
	* PTB15             | LPSPI1_SIN
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
		
	/* 3. Setting clock */
	LPSPI1->CCR |= (4u);      /* SCK Divider: 6-2 = 4 */
	LPSPI1->CCR |= (4u<<24u);
	LPSPI1->CCR |= (4u<<16u);
	
	/* 3.4.5.6 */	
	LPSPI1->TCR = ( (3u<<27u)   					/*3. Set Prescaler Value */  /*4. CPOL =0, CPHA = 0 */ 
								| (15u)        					/*5. Set frame size is 8 bits (FRAMESZ + 1) */
								| (3u<<24u) ); 					/*6. Transfer using PCS3  */
	
	/* 7. Setting Transmit/Receive FIFO */
	LPSPI1->FCR  |= (3u);        				/* Transmit FIFO */
	LPSPI1->CFGR1 |= (1u<<3u);  				/* No Stall if Tx FIFO empty or Rx FIFO full*/
	
	/* 8. Configures LPSPI mode */ 
	LPSPI1->CFGR1 |= (1u) ;       				/* Master mode */
	LPSPI1->CR |= (1u<<3u);      				/* Debug mode */

	/* 9. Enable LPSPI module */
	LPSPI1->CR |= (1u);
	
}

void LPSPI1_send_char(unsigned short data)
{
		while((LPSPI1->SR & (1u)) == 0 ){}
                                   /* Wait for Tx FIFO available 	*/
  LPSPI1->TDR = data;              /* Transmit data 				*/

}

void LPSPI1_send_string(char*  data_string )  
{  /* Function to Transmit whole string */
	while(*data_string != '\0')  {           /* Send chars one at a time */
		LPSPI1_send_char(*data_string);
		data_string++;
	}
}
