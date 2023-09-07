#include "s32k144.h"

void LPUART_init(void);
void Clock_init(void);
void LPUART1_send_char(char data); /* Function to Transmit single Char */

int main(void)
{
    /* Initialize clock: Enable FIRC_DIV2 */
    Clock_init();
    /* Initialize LPUART 1 */
    LPUART_init();

    /* Send char 'h' once time */
    LPUART1_send_char('h');

    while(1)
    {

    }
}
void LPUART_init(void)
{
    /* 1.  Setting Tx/Rx pin */
    PCC->PCCn[PCC_PORTC_INDEX] |= (1u<<30u); /* Enable clock for PORTC */
    PORTC->PCR[6] |= (2<<8u);                   /* Port C6: MUX = ALT2, UART1 RX */
    PORTC->PCR[7] |= (2<<8u);                /* Port C7: MUX = ALT2, UART1 TX */

    /* 2. Select source LPUART  */
    PCC->PCCn[PCC_LPUART1_INDEX] |= (3<<24u);   /* Select source: FIRCDIV2_CLK = 48MHz */
    PCC->PCCn[PCC_LPUART1_INDEX] |= (1<<30u);   /* Enable clock for LPURAT */

    /* 3. Setting baud rate: 9600 */
    LPUART1->BAUD &=(~( 0x1fu<<24u) | (15<<24));    /* Clear */
    //LPUART1->BAUD |=( 15<< 24u);       /* Set oversampling: 16*/

    LPUART1->BAUD &=~(0x1fffu);        /* Clear */
    LPUART1->BAUD |= 312u;             /* Set the modulo divide rate */

    /* 4. Setting Frame : 1 stop bit, 8 bit format, no parity */
    LPUART1->BAUD &=~ (1u<<13u);    /* ont stop bit */
    LPUART1->CTRL &=~ (1u<<4u);     /* 8 bit data */
    LPUART1->CTRL &=~ (1u<<1u);     /* no parity */

    /* 5. Enable transmitter & receiver */
    LPUART1->CTRL |= (1u<<18u);     /* Receiver Enable */
    LPUART1->CTRL |= (1u<<19u);     /* Transmitter Enable */

}
void Clock_init(void)
{
    SCG->FIRCDIV |= (1<<8u);    /* Fast IRC Clock Divide 2 : 1*/
}

void LPUART1_send_char(char data) {
    while((LPUART1->STAT & (1<<23u)) == 0 );
    /* Wait for transmit buffer to be empty */
    LPUART1->DATA = data;              /* Send data */
}
