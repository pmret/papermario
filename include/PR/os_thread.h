
/*====================================================================
 * os_thread.h
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

        $RCSfile: os_thread.h,v $
        $Revision: 1.3 $
        $Date: 1999/06/15 12:39:40 $
 *---------------------------------------------------------------------*/

#ifndef _OS_THREAD_H_
#define	_OS_THREAD_H_

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

typedef s32	OSPri;
typedef s32	OSId;
typedef union	{ struct { f32 f_odd; f32 f_even; } f; f64 d; }	__OSfp; // size = 0x8

typedef struct {
	/* 0x000 */ u64	at, v0, v1, a0, a1, a2, a3;
	/* 0x038 */ u64	t0, t1, t2, t3, t4, t5, t6, t7;
	/* 0x078 */ u64	s0, s1, s2, s3, s4, s5, s6, s7;
	/* 0x0B8 */ u64	t8, t9,         gp, sp, s8, ra;
	/* 0x0E8 */ u64	lo, hi;
	/* 0x0F8 */ u32	sr, pc, cause, badvaddr, rcp;
	/* 0x10C */ u32	fpcsr;
	/* 0x110 */ __OSfp	 fp0,  fp2,  fp4,  fp6,  fp8, fp10, fp12, fp14;
	/* 0x150 */ __OSfp	fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} __OSThreadContext; // size = 0x190

typedef struct {
    u32 flag;
    u32 count;
    u64 time;
} __OSThreadprofile_s;

typedef struct OSThread_s {
	/* 0x000 */ struct OSThread_s	*next;		/* run/mesg queue link */
	/* 0x004 */ OSPri			priority;	/* run/mesg queue priority */
	/* 0x008 */ struct OSThread_s	**queue;	/* queue thread is on */
	/* 0x00C */ struct OSThread_s	*tlnext;	/* all threads queue link */
	/* 0x010 */ u16			state;		/* OS_STATE_* */
	/* 0x012 */ u16			flags;		/* flags for rmon */
	/* 0x014 */ OSId			id;		/* id for debugging */
	/* 0x018 */ int			fp;		/* thread has used fp unit */
	/* 0x01C */ __OSThreadprofile_s     *thprof;        /* workarea for thread profiler */
	/* 0x020 */ __OSThreadContext	context;	/* register/interrupt mask */
} OSThread; // size = 0x1B0


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/* Thread states */

#define OS_STATE_STOPPED	1
#define OS_STATE_RUNNABLE	2
#define OS_STATE_RUNNING	4
#define OS_STATE_WAITING	8

/* Recommended thread priorities for the system threads */

#define OS_PRIORITY_MAX		255
#define OS_PRIORITY_VIMGR	254
#define OS_PRIORITY_RMON	250
#define OS_PRIORITY_RMONSPIN	200
#define OS_PRIORITY_PIMGR	150
#define OS_PRIORITY_SIMGR	140
#define	OS_PRIORITY_APPMAX	127
#define OS_PRIORITY_IDLE	  0	/* Must be 0 */

/* for thread profiler */
#define THPROF_IDMAX            64
#define THPROF_STACKSIZE        256

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

/* Thread operations */

extern void		osCreateThread(OSThread *, OSId, void (*)(void *),
				       void *, void *, OSPri);
extern void		osDestroyThread(OSThread *);
extern void		osYieldThread(void);
extern void		osStartThread(OSThread *);
extern void		osStopThread(OSThread *);
extern OSId		osGetThreadId(OSThread *);
extern void		osSetThreadPri(OSThread *, OSPri);
extern OSPri		osGetThreadPri(OSThread *);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_THREAD_H_ */
