


#ifdef GPIO_START_SECT_DATA
	#undef GPIO_START_SECT_DATA
	#pragma clang section data = ".gpio_driver_data"
#endif

#ifdef GPIO_STOP_SECT_DATA
	#undef GPIO_STOP_SECT_DATA
	#pragma clang section data = ""
#endif

#ifdef GPIO_START_SECT_COSNT
	#undef GPIO_START_SECT_CONST
	#pragma clang section rodata = ".gpio_driver_rodata"
#endif

#ifdef GPIO_STOP_SECT_CONST
	#undef GPIO_STOP_SECT_CONST
	#pragma clang section rodata = ""
#endif

#ifdef GPIO_START_SECT_DATA_UNINIT
	#undef GPIO_START_SECT_DATA_UNINIT
	#pragma clang section bss = ".gpio_driver_bss"
#endif

#ifdef GPIO_STOP_SECT_DATA_UNINIT
	#undef GPIO_STOP_SECT_DATA_UNINIT
	#pragma clang section bss = ""
#endif

	
#ifdef GPIO_START_SECT_CODE
	#undef GPIO_START_SECT_CODE
	#pragma clang section text = ".gpio_driver_code"
#endif

#ifdef GPIO_STOP_SECT_CODE
	#undef GPIO_STOP_SECT_CODE
	#pragma clang section text = ""
#endif

