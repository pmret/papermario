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

/**************************************************************************
 *
 *  $Revision: 1.9 $
 *  $Date: 1998/03/05 06:40:29 $
 *  $Source: /hosts/gate3/exdisk2/cvs/N64OS/Master/cvsmdev2/PR/include/sptask.h,v $
 *
 **************************************************************************/

#ifndef _SPTASK_H_
#define	_SPTASK_H_

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
 * Task List Structure.
 *
 * Things an app might pass to the SP via the task list.
 * Not every task ucode would need/use every field, but
 *
 *	- type (audio, gfx, video, ...)
 *	- flags
 *		- wait for DP to drain before running new task
 *		- SEE BIT DEFINITIONS UNDER "Task Flags field"
 *	- pointer to boot ucode
 *	- size of boot ucode
 *	- pointer to ucode
 *	- size of ucode
 *	- pointer to initial DMEM data
 *	- size of initial DMEM data 
 *	- pointer to DRAM stack
 *	- size of DRAM stack (max)
 *	- pointer to output buffer
 *	- pointer to store output buffer length
 *	- generic data pointer (for display list, etc.)
 *	- generic data length (for display list, etc.)
 *	- pointer to buffer where to store saved DMEM (in yield case)
 *	- size of buffer to store saved DMEM.
 *
 * IMPORTANT!!! Watch alignment issues.
 *
 * IMPORTANT!!! Watch data cache issues.  The RCP may write data into the
 * dram_stack, output_buff, output_buff_size, and the yield_data_ptr areas.
 * These buffers should be cache aligned and use the entire line (16 bytes) to
 * avoid corruption by writebacks by the CPU (cache tearing).
 *
 * IMPORTANT!!! all addresses are virtual addresses. Library does
 * any necessary translation.
 *
 */
typedef struct {
	u32	type;
	u32	flags;

	u64	*ucode_boot;
	u32	ucode_boot_size;

	u64	*ucode;
	u32	ucode_size;

	u64	*ucode_data;
	u32	ucode_data_size;

	u64	*dram_stack;
	u32	dram_stack_size;

	u64	*output_buff;
	u64	*output_buff_size;

	u64	*data_ptr;
	u32	data_size;

	u64	*yield_data_ptr;
	u32	yield_data_size;

} OSTask_t;

typedef union {
    OSTask_t		t;
    long long int	force_structure_alignment;
} OSTask;

typedef u32 OSYieldResult;

#endif /* _LANGUAGE_C */

#ifdef _LANGUAGE_ASSEMBLY

/*
 * For the RSP ucode:
 *	offsets into the task structure
 */

#include <PR/sptaskoff.h>

#endif

/*
 * Task Flags field
 */
#define OS_TASK_YIELDED			0x0001
#define OS_TASK_DP_WAIT			0x0002
#define	OS_TASK_LOADABLE		0x0004
#define	OS_TASK_SP_ONLY			0x0008
#define OS_TASK_USR0			0x0010
#define OS_TASK_USR1			0x0020
#define OS_TASK_USR2			0x0040
#define OS_TASK_USR3			0x0080

/*
 * Size of Yield buffer.  The taskHdrPtr->t.yield_data_ptr must point to a 
 * buffer of this size.  (The size is in bytes).  ONLY If the task will NEVER
 * yield it may be a null pointer.  The buffer must be aligned to a 64 bit
 * boundary.  The taskHdrPtr->t.yield_data_ptr must be set to point to the
 * buffer BEFORE the task is started.
 */
#if	(defined(F3DEX_GBI)||defined(F3DLP_GBI)||defined(F3DEX_GBI_2))
#define	OS_YIELD_DATA_SIZE		0xc00
#else
#define OS_YIELD_DATA_SIZE		0x900
#endif
#define OS_YIELD_AUDIO_SIZE		0x400

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

/*
 * this macro simulates atomic action.
 */
#define	osSpTaskStart(tp)	\
    {				\
        osSpTaskLoad((tp));	\
        osSpTaskStartGo((tp));	\
    }


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

/*
 * break this up into two steps for debugging.
 */
extern void		osSpTaskLoad(OSTask *tp);
extern void		osSpTaskStartGo(OSTask *tp);

extern void		osSpTaskYield(void);
extern OSYieldResult	osSpTaskYielded(OSTask *tp);

#endif /* _LANGUAGE_C */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_SPTASK_H */
