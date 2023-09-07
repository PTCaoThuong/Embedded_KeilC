#ifndef _TIMER_H_
#define _TIMER_H_

typedef struct{
	volatile unsigned int dummy_0[55];
	volatile unsigned int LPIT;
	volatile unsigned int dummy_5[20];
	volatile unsigned int PORTD;
	
}PCC_Type;

#define PCC_BASE_ADDRESS (0x40065000)
#define PCC ((PCC_Type*)PCC_BASE_ADDRESS)

typedef struct{
	unsigned int dummy_1[2];
	volatile unsigned int MCR;
	volatile unsigned int MSR;
	volatile unsigned int MIER;
	unsigned int dummy_2[3];
	volatile unsigned int TVAL0;
	volatile unsigned int CVAL0;
	volatile unsigned int TCTRL0;
	unsigned int dummy_6[5];
	volatile unsigned int TVAL2;
	volatile unsigned int CVAL2;
	volatile unsigned int TCTRL2;
	unsigned int dummy_7[1];
	volatile unsigned int TVAL3;
	volatile unsigned int CVAL3;
	volatile unsigned int TCTRL3;
	
}LPIT_Type;

#define LPIT_BASE_ADDRESS (0x40037000)
#define LPIT_0 ((LPIT_Type*)LPIT_BASE_ADDRESS)

typedef struct{
	volatile unsigned int ISER0;
	volatile unsigned int ISER1;

}NVIC_Type;

#define NVIC_BASE_ADDRESS (0xE000E100)
#define NVIC ((NVIC_Type*)NVIC_BASE_ADDRESS)

/* PCR PORT_D */
typedef struct{
	volatile unsigned int PORTD_PCR0; /* BLUE */
	int dummy_3[14];
	volatile unsigned int PORTD_PCR15; /* RED */
	volatile unsigned int PORTD_PCR16; /* GREEN */
}PCR_D_Type;

#define PCR_D_BASE_ADDRESS (0x4004C000)
#define PCR_D ((PCR_D_Type*)PCR_D_BASE_ADDRESS)

/* GPIO_D */
typedef struct{
	volatile unsigned int PDOR_D;
	unsigned int dummy_4[3];
	volatile const unsigned int PDIR_D;
	volatile unsigned int PDDR_D;
}GPIOD_Type;
#define GPIOD_BASE_ADDRESS (0x400FF0C0)
#define GPIO_D ((GPIOD_Type*)GPIOD_BASE_ADDRESS)

#endif
