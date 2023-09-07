
#ifdef UART_START_SECT_DATA
	#undef UART_START_SECT_DATA
	#pragma clang section data = ".uart_driver_data"
#endif

#ifdef UART_STOP_SECT_DATA
	#undef UART_STOP_SECT_DATA
	#pragma clang section data = ""
#endif

#ifdef UART_START_SECT_COSNT
	#undef UART_START_SECT_CONST
	#pragma clang section rodata = ".uart_driver_rodata"
#endif

#ifdef UART_STOP_SECT_CONST
	#undef UART_STOP_SECT_CONST
	#pragma clang section rodata = ""
#endif

#ifdef UART_START_SECT_DATA_UNINIT
	#undef UART_START_SECT_DATA_UNINIT
	#pragma clang section bss = ".uart_driver_bss"
#endif

#ifdef UART_STOP_SECT_DATA_UNINIT
	#undef UART_STOP_SECT_DATA_UNINIT
	#pragma clang section bss = ""
#endif

	
#ifdef UART_START_SECT_CODE
	#undef UART_START_SECT_CODE
	#pragma clang section text = ".uart_driver_code"
#endif

#ifdef UART_STOP_SECT_CODE
	#undef UART_STOP_SECT_CODE
	#pragma clang section text = ""
#endif
