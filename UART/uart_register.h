#ifndef _UART_H_
#define _UART_H_



/* LPUART01 */
typedef struct{
	volatile unsigned int dummy_0[4];
	volatile unsigned int BAUD;
	volatile unsigned int STAT;
	volatile unsigned int CTRL;
	volatile unsigned int DATA;

}LPUART_Type;

#define LPUART_BASE_ADDRESS (0x4006B000)
#define LPUART ((LPUART_Type*)LPUART_BASE_ADDRESS)

/* PCC */
typedef struct{
	volatile unsigned int dummy_1[55];
	volatile unsigned int LPIT;
	volatile unsigned int dummy_2[19];
	volatile unsigned int PORTC;
	volatile unsigned int PORTD;
	volatile unsigned int dummy_6[29];
	volatile unsigned int LPUART0;
	volatile unsigned int LPUART1;
}PCC_Type;

#define PCC_BASE_ADDRESS (0x40065000)
#define PCC ((PCC_Type*)PCC_BASE_ADDRESS)


/* PCR PORT_C */
typedef struct{
	unsigned int dummy_3[6];
	volatile unsigned int PCR6; 
	volatile unsigned int PCR7;	
	unsigned int dummy_4[4];
	volatile unsigned int PCR12; /* BTN0 */
	volatile unsigned int PCR13; /* BTN1 */
}PCR_C_Type;

#define PCR_C_BASE_ADDRESS (0x4004B000)
#define PCR_C ((PCR_C_Type*)PCR_C_BASE_ADDRESS)

/* SCG */
typedef struct{
	volatile unsigned int dummy_5[193];
	volatile unsigned int FIRCDIV;
}SCG_Type;

#define SCG_BASE_ADDRESS (0x40064000)
#define SCG ((SCG_Type*)SCG_BASE_ADDRESS)


/* PCR PORT_D */
typedef struct{
	volatile unsigned int PORTD_PCR0; /* BLUE */
	int dummy_7[14];
	volatile unsigned int PORTD_PCR15; /* RED */
	volatile unsigned int PORTD_PCR16; /* GREEN */
}PCR_D_Type;

#define PCR_D_BASE_ADDRESS (0x4004C000)
#define PCR_D ((PCR_D_Type*)PCR_D_BASE_ADDRESS)

/* GPIO_D */
typedef struct{
	volatile unsigned int PDOR_D;
	unsigned int dummy_8[3];
	volatile const unsigned int PDIR_D;
	volatile unsigned int PDDR_D;
}GPIOD_Type;
#define GPIOD_BASE_ADDRESS (0x400FF0C0)
#define GPIO_D ((GPIOD_Type*)GPIOD_BASE_ADDRESS)

typedef struct{
	volatile unsigned int ISER0;
	volatile unsigned int ISER1;
}NVIC_Type;

#define NVIC_BASE_ADDRESS (0xE000E100)
#define NVIC ((NVIC_Type*)NVIC_BASE_ADDRESS)

#endif


