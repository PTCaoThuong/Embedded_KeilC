


/* PCC */
typedef struct{
	unsigned int dummy0[75];
	volatile unsigned int PCC_PORTC;
	volatile unsigned int PCC_PORTD;
}PCC_Type;

#define PCC_BASE_ADDRESS (0x40065000)
#define PCC ((PCC_Type*)PCC_BASE_ADDRESS)
/* PCR PORT_D */
typedef struct{
	volatile unsigned int PORTD_PCR0; /* BLUE */
	int dummy1[14];
	volatile unsigned int PORTD_PCR15; /* RED */
	volatile unsigned int PORTD_PCR16; /* GREEN */
}PCR_D_Type;

#define PCR_D_BASE_ADDRESS (0x4004C000)
#define PCR_D ((PCR_D_Type*)PCR_D_BASE_ADDRESS)

/* PCR PORT_C */
typedef struct{
	unsigned int dummy2[12];
	volatile unsigned int PORTC_PCR12; /* BTN0 */
	volatile unsigned int PORTC_PCR13; /* BTN1 */
}PCR_C_Type;

#define PCR_C_BASE_ADDRESS (0x4004B000)
#define PCR_C ((PCR_C_Type*)PCR_C_BASE_ADDRESS)

/* GPIO_D */
typedef struct{
	volatile unsigned int PDOR_D;
	unsigned int dummy3[3];
	volatile const unsigned int PDIR_D;
	volatile unsigned int PDDR_D;
}GPIOD_Type;
#define GPIOD_BASE_ADDRESS (0x400FF0C0)
#define GPIO_D ((GPIOD_Type*)GPIOD_BASE_ADDRESS)

/* GPIO_C */
typedef struct{
	volatile unsigned int PDOR_C;
	unsigned int dummy4[3];
	volatile const unsigned int PDIR_C;
	volatile unsigned int PDDR_C;
}GPIOC_Type;
#define GPIOC_BASE_ADDRESS ( 0x400FF080)
#define GPIO_C ((GPIOC_Type*)GPIOC_BASE_ADDRESS)


/** S32_NVIC - Size of Registers Arrays */
#define S32_NVIC_ISER_COUNT                      8u
#define S32_NVIC_ICER_COUNT                      8u
#define S32_NVIC_ISPR_COUNT                      8u
#define S32_NVIC_ICPR_COUNT                      8u
#define S32_NVIC_IABR_COUNT                      8u
#define S32_NVIC_IP_COUNT                        240u

/** S32_NVIC - Register Layout Typedef */
typedef struct {
  volatile unsigned int ISER[S32_NVIC_ISER_COUNT];         /**< Interrupt Set Enable Register n, array offset: 0x0, array step: 0x4 */
					 unsigned int RESERVED_0[24];
  volatile unsigned int ICER[S32_NVIC_ICER_COUNT];         /**< Interrupt Clear Enable Register n, array offset: 0x80, array step: 0x4 */
           unsigned int RESERVED_1[24];
  volatile unsigned int ISPR[S32_NVIC_ISPR_COUNT];         /**< Interrupt Set Pending Register n, array offset: 0x100, array step: 0x4 */
           unsigned int RESERVED_2[24];
  volatile unsigned int ICPR[S32_NVIC_ICPR_COUNT];         /**< Interrupt Clear Pending Register n, array offset: 0x180, array step: 0x4 */
           unsigned int RESERVED_3[24];
  volatile unsigned int IABR[S32_NVIC_IABR_COUNT];         /**< Interrupt Active bit Register n, array offset: 0x200, array step: 0x4 */
       unsigned char RESERVED_4[224];
  volatile unsigned char IP[S32_NVIC_IP_COUNT];              /**< Interrupt Priority Register n, array offset: 0x300, array step: 0x1 */
       unsigned char RESERVED_5[2576];
  volatile  unsigned int STIR;                              /**< Software Trigger Interrupt Register, offset: 0xE00 */
} NVIC_Type;

/* S32_NVIC - Peripheral instance base addresses */
/** Peripheral S32_NVIC base address */
#define NVIC_BASE                            (0xE000E100u)
/** Peripheral S32_NVIC base pointer */
#define NVIC                                 ((NVIC_Type *)NVIC_BASE)

