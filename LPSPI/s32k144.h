#ifndef S32K144_H_
#define S32K144_H_

/** PORT - Size of Registers Arrays */
#define PORT_PCR_COUNT                           32u

/** PORT - Register Layout Typedef */
typedef struct {
  volatile unsigned int PCR[PORT_PCR_COUNT];              /**< Pin Control Register n, array offset: 0x0, array step: 0x4 */
} PORT_Type;
/** Peripheral PORTB base address */
#define PORTB_BASE                               (0x4004A000u)
/** Peripheral PORTB base pointer */
#define PORTB                                    ((PORT_Type *)PORTB_BASE)
/** Peripheral PORTC base address */
#define PORTC_BASE                               (0x4004B000u)
/** Peripheral PORTC base pointer */
#define PORTC                                    ((PORT_Type *)PORTC_BASE)
/** Peripheral PORTD base address */
#define PORTD_BASE                               (0x4004C000u)
/** Peripheral PORTD base pointer */
#define PORTD 									 ((PORT_Type *)PORTD_BASE)

typedef struct {
  volatile unsigned int PDOR;                              /**< Port Data Output Register, offset: 0x0 */
  volatile  unsigned int PSOR;                             /**< Port Set Output Register, offset: 0x4 */
  volatile  unsigned int PCOR;                             /**< Port Clear Output Register, offset: 0x8 */
  volatile  unsigned int PTOR;                             /**< Port Toggle Output Register, offset: 0xC */
  volatile const  unsigned int PDIR;                       /**< Port Data Input Register, offset: 0x10 */
  volatile unsigned int PDDR;                              /**< Port Data Direction Register, offset: 0x14 */
  volatile unsigned int PIDR;                              /**< Port Input Disable Register, offset: 0x18 */
} GPIO_Type;

#define GPIOB_base_address   (0x400FF040u)

#define GPIOB   ((GPIO_Type*)(GPIOB_base_address))

#define GPIOD_base_address   (0x400FF0C0u)

#define GPIOD   ((GPIO_Type*)(GPIOD_base_address))

#define GPIOC_base_address   (0x400FF080u)

#define GPIOC   ((GPIO_Type*)(GPIOC_base_address))

typedef struct{
    volatile unsigned int VERID;
    volatile unsigned int PARAM;
    volatile unsigned int MCR;
    volatile unsigned int MSR;
    volatile unsigned int MIER;
    volatile unsigned int SETTEN;
    volatile unsigned int CLRTEN;
    volatile unsigned int Reserved0;
    volatile unsigned int TVAL0;
    volatile unsigned int CVAL0;
    volatile unsigned int TCTRL0;
    volatile unsigned int Reserved1;
    volatile unsigned int TVAL1;
    volatile unsigned int CVAL1;
    volatile unsigned int TCTRL1;
    volatile unsigned int Reserved2;
    volatile unsigned int TVAL2;
    volatile unsigned int CVAL2;
    volatile unsigned int TCTRL2;
    volatile unsigned int Reserved3;
	  volatile unsigned int TVAL3;
    volatile unsigned int CVAL3;
    volatile unsigned int TCTRL3;
} LPIT_Type;

#define LPIT_base_address  (0x40037000u)

#define LPIT  ((LPIT_Type*)(LPIT_base_address))

/** PCC - Size of Registers Arrays */
#define PCC_PCCn_COUNT                           122u

/** PCC - Register Layout Typedef */
typedef struct {
  volatile unsigned int PCCn[PCC_PCCn_COUNT];              /**< PCC Reserved Register 0..PCC CMP0 Register, array offset: 0x0, array step: 0x4 */
} PCC_Type;


/** Peripheral PCC base address */
#define PCC_base_address                                 (0x40065000u)
/** Peripheral PCC base pointer */
#define PCC                                      ((PCC_Type *)PCC_base_address)


#define PCC_LPSPI0_INDEX                         44
#define PCC_LPSPI1_INDEX                         45
#define PCC_LPSPI2_INDEX                         46
#define PCC_LPIT_INDEX                           55
#define PCC_PORTA_INDEX                          73
#define PCC_PORTB_INDEX                          74
#define PCC_PORTC_INDEX                          75
#define PCC_PORTD_INDEX                          76
#define PCC_PORTE_INDEX                          77
#define PCC_LPUART1_INDEX                        107




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

/** SCG - Register Layout Typedef */
typedef struct {
  volatile const unsigned int VERID;                             /**< Version ID Register, offset: 0x0 */
  volatile const unsigned int PARAM;                             /**< Parameter Register, offset: 0x4 */
                 unsigned int RESERVED_0[2];
  volatile const unsigned int CSR;                               /**< Clock Status Register, offset: 0x10 */
  volatile unsigned int RCCR;                              /**< Run Clock Control Register, offset: 0x14 */
  volatile unsigned int VCCR;                              /**< VLPR Clock Control Register, offset: 0x18 */
  volatile unsigned int HCCR;                              /**< HSRUN Clock Control Register, offset: 0x1C */
  volatile unsigned int CLKOUTCNFG;                        /**< SCG CLKOUT Configuration Register, offset: 0x20 */
       unsigned int RESERVED_1[55];
  volatile unsigned int SOSCCSR;                           /**< System OSC Control Status Register, offset: 0x100 */
  volatile unsigned int SOSCDIV;                           /**< System OSC Divide Register, offset: 0x104 */
  volatile unsigned int SOSCCFG;                           /**< System Oscillator Configuration Register, offset: 0x108 */
       unsigned int RESERVED_2[61];
  volatile unsigned int SIRCCSR;                           /**< Slow IRC Control Status Register, offset: 0x200 */
  volatile unsigned int SIRCDIV;                           /**< Slow IRC Divide Register, offset: 0x204 */
  volatile unsigned int SIRCCFG;                           /**< Slow IRC Configuration Register, offset: 0x208 */
       unsigned int RESERVED_3[61];
  volatile unsigned int FIRCCSR;                           /**< Fast IRC Control Status Register, offset: 0x300 */
  volatile unsigned int FIRCDIV;                           /**< Fast IRC Divide Register, offset: 0x304 */
  volatile unsigned int FIRCCFG;                           /**< Fast IRC Configuration Register, offset: 0x308 */
       unsigned int RESERVED_4[189];
  volatile unsigned int SPLLCSR;                           /**< System PLL Control Status Register, offset: 0x600 */
  volatile unsigned int SPLLDIV;                           /**< System PLL Divide Register, offset: 0x604 */
  volatile unsigned int SPLLCFG;                           /**< System PLL Configuration Register, offset: 0x608 */
} SCG_Type;
  
  /** Peripheral SCG base address */
#define SCG_BASE                                 (0x40064000u)
/** Peripheral SCG base pointer */
#define SCG                                      ((SCG_Type *)SCG_BASE)

/** LPUART - Register Layout Typedef */
typedef struct {
  volatile const  unsigned int VERID;                             /**< Version ID Register, offset: 0x0 */
  volatile const  unsigned int PARAM;                             /**< Parameter Register, offset: 0x4 */
  volatile unsigned int GLOBAL;                            /**< LPUART Global Register, offset: 0x8 */
  volatile unsigned int PINCFG;                            /**< LPUART Pin Configuration Register, offset: 0xC */
  volatile unsigned int BAUD;                              /**< LPUART Baud Rate Register, offset: 0x10 */
  volatile unsigned int STAT;                              /**< LPUART Status Register, offset: 0x14 */
  volatile unsigned int CTRL;                              /**< LPUART Control Register, offset: 0x18 */
  volatile unsigned int DATA;                              /**< LPUART Data Register, offset: 0x1C */
  volatile unsigned int MATCH;                             /**< LPUART Match Address Register, offset: 0x20 */
  volatile unsigned int MODIR;                             /**< LPUART Modem IrDA Register, offset: 0x24 */
  volatile unsigned int FIFO;                              /**< LPUART FIFO Register, offset: 0x28 */
  volatile unsigned int WATER;                             /**< LPUART Watermark Register, offset: 0x2C */
} LPUART_Type;

/** Peripheral LPUART1 base address */
#define LPUART1_BASE                             (0x4006B000u)
/** Peripheral LPUART1 base pointer */
#define LPUART1                                  ((LPUART_Type *)LPUART1_BASE)


/** LPSPI - Register Layout Typedef */
typedef struct {
  volatile const  unsigned int VERID;                             /**< Version ID Register, offset: 0x0 */
  volatile const  unsigned int PARAM;                             /**< Parameter Register, offset: 0x4 */
       unsigned char RESERVED_0[8];
  volatile unsigned int CR;                                /**< Control Register, offset: 0x10 */
  volatile unsigned int SR;                                /**< Status Register, offset: 0x14 */
  volatile unsigned int IER;                               /**< Interrupt Enable Register, offset: 0x18 */
  volatile unsigned int DER;                               /**< DMA Enable Register, offset: 0x1C */
  volatile unsigned int CFGR0;                             /**< Configuration Register 0, offset: 0x20 */
  volatile unsigned int CFGR1;                             /**< Configuration Register 1, offset: 0x24 */
       unsigned char RESERVED_1[8];
  volatile unsigned int DMR0;                              /**< Data Match Register 0, offset: 0x30 */
  volatile unsigned int DMR1;                              /**< Data Match Register 1, offset: 0x34 */
       unsigned char RESERVED_2[8];
  volatile unsigned int CCR;                               /**< Clock Configuration Register, offset: 0x40 */
       unsigned char RESERVED_3[20];
  volatile unsigned int FCR;                               /**< FIFO Control Register, offset: 0x58 */
  volatile const  unsigned int FSR;                               /**< FIFO Status Register, offset: 0x5C */
  volatile unsigned int TCR;                               /**< Transmit Command Register, offset: 0x60 */
  volatile  unsigned int TDR;                               /**< Transmit Data Register, offset: 0x64 */
       unsigned char RESERVED_4[8];
  volatile const  unsigned int RSR;                               /**< Receive Status Register, offset: 0x70 */
  volatile const  unsigned int RDR;                               /**< Receive Data Register, offset: 0x74 */
} LPSPI_Type;
/** Peripheral LPSPI base address */
#define LPSPI0_base_address  (0x4002C000u)
#define LPSPI1_base_address  (0x4002D000u)
#define LPSPI2_base_address  (0x4002E000u)

#define LPSPI0                                   ((LPSPI_Type *)LPSPI0_base_address)
#define LPSPI1                                   ((LPSPI_Type *)LPSPI1_base_address)
#define LPSPI2                                   ((LPSPI_Type *)LPSPI2_base_address)



#endif

