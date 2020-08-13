
/*====================================================================
 * os_debug.h
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
        
        $RCSfile: os_debug.h,v $
        $Revision: 1.4 $
        $Date: 1999/06/30 03:04:08 $
 *---------------------------------------------------------------------*/

#ifndef _OS_DEBUG_H_
#define	_OS_DEBUG_H_

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

/*
 * Structure for Profiler 
 */
typedef struct {
	u16	*histo_base;		/* histogram base */
	u32	histo_size;		/* histogram size */
	u32	*text_start;		/* start of text segment */
	u32	*text_end;		/* end of text segment */
} OSProf;


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/*
 * Profiler constants
 */
#define PROF_MIN_INTERVAL	50	/* microseconds */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Macro definitions
 *
 */


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

/* Profiler Interface */

extern void		osProfileInit(OSProf *, u32 profcnt);
extern void		osProfileStart(u32);
extern void		osProfileFlush(void);
extern void		osProfileStop(void);

/* Thread Profiler Interface */
extern void             osThreadProfileClear(OSId);
extern void             osThreadProfileInit(void);
extern void             osThreadProfileStart(void);
extern void             osThreadProfileStop(void);
extern u32              osThreadProfileReadCount(OSId);
extern u32              osThreadProfileReadCountTh(OSThread*);
extern OSTime           osThreadProfileReadTime(OSId);
extern OSTime           osThreadProfileReadTimeTh(OSThread*);

#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_DEBUG_H_ */
