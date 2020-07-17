
/*====================================================================
 * os_host.h
 *
 * Copyright 1995, Silicon Graphics, Inc.
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Silicon Graphics,
 * Inc.; the contents of this file may not be disclosed to third
 * parties, copied or duplicated in any form, in whole or in part,
 * without the prior written permission of Silicon Graphics, Inc.
 *
 * RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to
 * restrictions as set forth in subdivision (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS
 * 252.227-7013, and/or in similar or successor clauses in the FAR,
 * DOD or NASA FAR Supplement. Unpublished - rights reserved under the
 * Copyright Laws of the United States.
 *====================================================================*/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: os_host.h,v $
        $Revision: 1.3 $
        $Date: 1999/06/24 09:23:06 $
 *---------------------------------------------------------------------*/

#ifndef _OS_HOST_H_
#define	_OS_HOST_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */

extern void __osInitialize_common(void);

#if defined(_FINALROM)

#define osInitialize() __osInitialize_common()

#else

/* PARTNER-N64 */
#if defined(PTN64)
extern void __osInitialize_kmc(void);
#define osReadHost osReadHost_pt
#define osWriteHost osWriteHost_pt
#define osInitialize()       \
{                            \
    __osInitialize_common();  \
    __osInitialize_kmc();    \
}

/* MONEGI SMART PACK A */
#elif defined(MWN64)
extern void __osInitialize_msp(void);
#define osReadHost osReadHost_pt
#define osWriteHost osWriteHost_pt
#define osInitialize()       \
{                            \
    __osInitialize_common(); \
    __osInitialize_msp();    \
}

/* IS-Viewer(for Debugger) */
#elif defined(ISV64)
extern void __osInitialize_isv(void);
#define osInitialize()       \
{                            \
    __osInitialize_common(); \
    __osInitialize_isv();    \
}

/* Emulation board for INDY */
#elif defined(EMU64)
extern void __osInitialize_emu(void);
#define osInitialize()       \
{                            \
    __osInitialize_common(); \
    __osInitialize_emu();    \
}

#else
/* Default (auto detect) */
extern void __osInitialize_autodetect(void);
extern void __osInitialize_msp(void);
extern void __osInitialize_kmc(void);
extern void __osInitialize_isv(void);
extern void __osInitialize_emu(void);
#define osInitialize()           \
{                                \
    __osInitialize_common();     \
    __osInitialize_autodetect(); \
}
#endif

#endif  /* _FINAL_ROM */

/**************************************************************************
 *
 * Extern variables
 *
 */


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Game <> Host data transfer functions */

extern s32		osTestHost(void);
extern void		osReadHost(void *, u32);
extern void		osWriteHost(void *, u32);
extern void		osAckRamromRead(void);
extern void		osAckRamromWrite(void);

/* RDB port operations */

extern void             osInitRdb(u8 *sendBuf, u32 sendSize);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_HOST_H_ */
