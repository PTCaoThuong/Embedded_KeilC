#ifndef SYSTICK_H_
#define SYSTICK_H_

typedef struct{
	volatile unsigned int SYST_CSR;
	volatile unsigned int SYST_RVR;
	volatile unsigned int SYST_CVR;
	volatile const unsigned int SYST_CALIB;
	
}SYST_Type;

#define SYST_BASE_ADDRESS (0xE000E010)
#define SYST ((SYST_Type*)SYST_BASE_ADDRESS)

#endif


