#include "s32k144.h"
#define CS_PIN     (17u)
#define CLK_PIN    (14u)
#define SOUT_PIN   (16u)


#define SET_CS_PIN_HIGH()     (GPIOB ->PDOR |= (1u<<CS_PIN))
#define SET_CLK_PIN_HIGH()    (GPIOB ->PDOR |= (1u<<CLK_PIN))
#define SET_SOUT_PIN_HIGH()   (GPIOB ->PDOR |= (1u<<SOUT_PIN))

#define SET_CS_PIN_LOW()     (GPIOB ->PDOR &=~ (1u<<CS_PIN))
#define SET_CLK_PIN_LOW()    (GPIOB ->PDOR &=~ (1u<<CLK_PIN))
#define SET_SOUT_PIN_LOW()   	 (GPIOB ->PDOR &=~ (1u<<SOUT_PIN))


void SPI_init(void);
void SPI_send_data(unsigned short data);
void SPI_generate_CLK(void);
int main()
	
{
	
	SPI_init();
	
	
	SPI_send_data(0x0A01);
	SPI_send_data(0x0B07);

	
	
	while(1)
	{
		
	}

} 


void SPI_init(void)
{
		/* Pins definitions
	* ===================================================
	* Pin number        | Function
	* ----------------- |------------------
	* PTB17             | CS 
	* PTB14             | CLK
	* PTB16             | SOUT
	*/
	
	/* 1.  Setting Clocking */
	PCC->PCCn[PCC_PORTB_INDEX] |= (1u<<30u);   /* Enable clock for PORTD */
	
	/* 2. Set pins as GPIO function */
	PORTB ->PCR[CS_PIN]   |= (1<<8u);
	PORTB ->PCR[CLK_PIN] 	|= (1<<8u);
	PORTB ->PCR[SOUT_PIN] |= (1<<8u);
	
	/* 3. Set pins as output pin */
	GPIOB ->PDDR |= (1<<CS_PIN);
	GPIOB ->PDDR |= (1<<CLK_PIN);
	GPIOB ->PDDR |= (1<<SOUT_PIN);
	
	
	SET_CS_PIN_HIGH();
	SET_CLK_PIN_LOW();
	SET_SOUT_PIN_LOW();
	
}


void SPI_send_data(unsigned short data)
{

	/* Setp 1: Start transmit SPI: Set Low pin CS */
	SET_CS_PIN_LOW();
	
	/* Step 2: Send data */
	for(int i = 15; i >= 0; i--)
	{
		/* Step 2-1: Create bit data */
		if(data&(1u<<i))
		{
			SET_SOUT_PIN_HIGH();
		} else 
		{
			SET_SOUT_PIN_LOW();
		}
		/* Step 2-2: Generate Clock */
		SPI_generate_CLK();
		
	}
	
	/* Step 3: Stop transmit SPI: Set Hign pin CS*/
	SET_CS_PIN_HIGH();
	
}

void SPI_generate_CLK(void)
{
	SET_CLK_PIN_HIGH();
	for(int i=0;i<100;i++);
	SET_CLK_PIN_LOW();
	for(int i=0;i<100;i++);
}
