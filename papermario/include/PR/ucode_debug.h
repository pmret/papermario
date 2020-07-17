/*---------------------------------------------------------------------*
	Copyright (C) 1998, Nintendo.
	
	File		ucode_debug.h
	Coded    by	Yoshitaka Yasumoto.	Nov 15, 1998.
	
	$Id: ucode_debug.h,v 1.1 1998/12/25 01:06:21 has Exp $
 *---------------------------------------------------------------------*/
#ifndef _UCODE_DEBUG_H_
#define	_UCODE_DEBUG_H_

#define	DEBUG_DL_PTR()		IO_READ(SP_DMEM_START+0xfc0)

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)
/*========== F3DEX2/F3DLX2/L3DEX2/S2DEX2 ==========*/
/* FIFO version */
extern long long int gspF3DEX2d_fifoTextStart[],    gspF3DEX2d_fifoTextEnd[];
extern long long int gspF3DEX2d_fifoDataStart[],    gspF3DEX2d_fifoDataEnd[];
extern long long int gspF3DEX2d_NoN_fifoTextStart[],gspF3DEX2d_NoN_fifoTextEnd[];
extern long long int gspF3DEX2d_NoN_fifoDataStart[],gspF3DEX2d_NoN_fifoDataEnd[];
extern long long int gspF3DEX2d_Rej_fifoTextStart[],gspF3DEX2d_Rej_fifoTextEnd[];
extern long long int gspF3DEX2d_Rej_fifoDataStart[],gspF3DEX2d_Rej_fifoDataEnd[];
extern long long int gspF3DLX2d_Rej_fifoTextStart[],gspF3DLX2d_Rej_fifoTextEnd[];
extern long long int gspF3DLX2d_Rej_fifoDataStart[],gspF3DLX2d_Rej_fifoDataEnd[];
extern long long int gspL3DEX2d_fifoTextStart[],    gspL3DEX2d_fifoTextEnd[];
extern long long int gspL3DEX2d_fifoDataStart[],    gspL3DEX2d_fifoDataEnd[];
extern long long int gspS2DEX2d_fifoTextStart[],    gspS2DEX2d_fifoTextEnd[];
extern long long int gspS2DEX2d_fifoDataStart[],    gspS2DEX2d_fifoDataEnd[];

/* XBUS version */
extern long long int gspF3DEX2d_xbusTextStart[],    gspF3DEX2d_xbusTextEnd[];
extern long long int gspF3DEX2d_xbusDataStart[],    gspF3DEX2d_xbusDataEnd[];
extern long long int gspF3DEX2d_NoN_xbusTextStart[],gspF3DEX2d_NoN_xbusTextEnd[];
extern long long int gspF3DEX2d_NoN_xbusDataStart[],gspF3DEX2d_NoN_xbusDataEnd[];
extern long long int gspF3DEX2d_Rej_xbusTextStart[],gspF3DEX2d_Rej_xbusTextEnd[];
extern long long int gspF3DEX2d_Rej_xbusDataStart[],gspF3DEX2d_Rej_xbusDataEnd[];
extern long long int gspF3DLX2d_Rej_xbusTextStart[],gspF3DLX2d_Rej_xbusTextEnd[];
extern long long int gspF3DLX2d_Rej_xbusDataStart[],gspF3DLX2d_Rej_xbusDataEnd[];
extern long long int gspL3DEX2d_xbusTextStart[],    gspL3DEX2d_xbusTextEnd[];
extern long long int gspL3DEX2d_xbusDataStart[],    gspL3DEX2d_xbusDataEnd[];
extern long long int gspS2DEX2d_xbusTextStart[],    gspS2DEX2d_xbusTextEnd[];
extern long long int gspS2DEX2d_xbusDataStart[],    gspS2DEX2d_xbusDataEnd[];

#endif /* _LANGUAGE_C */
#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif
#endif /* !_UCODE_DEBUG_H */

/*======== End of ucode_debug.h ========*/
