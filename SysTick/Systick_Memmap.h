
#ifdef SYSTICK_START_SECT_DATA
	#undef SYSTICK_START_SECT_DATA
	#pragma clang section data = ".systick_driver_data"
#endif

#ifdef SYSTICK_STOP_SECT_DATA
	#undef SYSTICK_STOP_SECT_DATA
	#pragma clang section data = ""
#endif

#ifdef SYSTICK_START_SECT_COSNT
	#undef SYSTICK_START_SECT_CONST
	#pragma clang section rodata = ".systick_driver_rodata"
#endif

#ifdef SYSTICK_STOP_SECT_CONST
	#undef SYSTICK_STOP_SECT_CONST
	#pragma clang section rodata = ""
#endif

#ifdef SYSTICK_START_SECT_DATA_UNINIT
	#undef SYSTICK_START_SECT_DATA_UNINIT
	#pragma clang section bss = ".systick_driver_bss"
#endif

#ifdef SYSTICK_STOP_SECT_DATA_UNINIT
	#undef SYSTICK_STOP_SECT_DATA_UNINIT
	#pragma clang section bss = ""
#endif

	
#ifdef SYSTICK_START_SECT_CODE
	#undef SYSTICK_START_SECT_CODE
	#pragma clang section text = ".systick_driver_code"
#endif

#ifdef SYSTICK_STOP_SECT_CODE
	#undef SYSTICK_STOP_SECT_CODE
	#pragma clang section text = ""
#endif

