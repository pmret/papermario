/**************************************************************************
 *									  *
 *		 Copyright (C) 1995, Silicon Graphics, Inc.		  *
 *									  *
 *  These coded instructions, statements, and computer programs  contain  *
 *  unpublished  proprietary  information of Silicon Graphics, Inc., and  *
 *  are protected by Federal copyright law.  They  may  not be disclosed  *
 *  to  third  parties  or copied or duplicated in any form, in whole or  *
 *  in part, without the prior written consent of Silicon Graphics, Inc.  *
 *									  *
 **************************************************************************/

/*---------------------------------------------------------------------*
        Copyright (C) 1998 Nintendo. (Originated by SGI)
        
        $RCSfile: os_internal_reg.h,v $
        $Revision: 1.2 $
        $Date: 1999/03/10 12:19:14 $
 *---------------------------------------------------------------------*/

#ifndef _OS_INTERNAL_REG_H_
#define	_OS_INTERNAL_REG_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/os.h>

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/* Routines to get/fetch coprocessor 0 registers */

extern u32		__osGetCause(void);
extern void		__osSetCause(u32);
extern u32		__osGetCompare(void);
extern void		__osSetCompare(u32);
extern u32		__osGetConfig(void);
extern void		__osSetConfig(u32);
extern void		__osSetCount(u32);
extern u32		__osGetSR(void);
extern void		__osSetSR(u32);
extern u32		____osDisableInt(void);
extern void		____osRestoreInt(u32);
extern u32		__osGetWatchLo(void);
extern void		__osSetWatchLo(u32);

/* Routines to get/set floating-point control and status register */
extern u32              __osSetFpcCsr(u32);
extern u32              __osGetFpcCsr(void);


#endif /* _LANGUAGE_C */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_INTERNAL_REG_H */
