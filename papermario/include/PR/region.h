
/**************************************************************************
 *									  *
 *		 Copyright (C) 1994, Silicon Graphics, Inc.		  *
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
 *  Module: region.h
 *
 *  $Revision: 1.8 $
 *  $Date: 1997/11/26 00:30:56 $
 *  $Author: mitu $
 *  $Source: /hosts/gate3/exdisk2/cvs/N64OS/Master/cvsmdev2/PR/include/region.h,v $
 *
 *  Description:
 *      This file contains macros and structure definitions for the region
 *	library.
 *
 **************************************************************************/


#ifndef _REGION_H_
#define _REGION_H_


#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>


/***************************************
 *
 * Global defines 
 *
 */
					/* Alignment sizes */
#define	ALIGNSZ			(sizeof(long long))	/* 8 bytes */
#define	ALIGNOFFST		(ALIGNSZ-1)	

				/* size for storing index to free buffer */
#define	BUF_CTRL_SIZE		ALIGNSZ		

				/* Max bufcount = 32K */
#define	MAX_BUFCOUNT		0x8000	
				/* code for last free buffer */
#define	BUF_FREE_WO_NEXT	0x8000	

/*
 * Global defines for alignment size (default is 8-byte alignment)
 */
#define OS_RG_ALIGN_2B		2	/*  2 bytes =  16-bit alignment */
#define OS_RG_ALIGN_4B		4	/*  4 bytes =  32-bit alignment */
#define OS_RG_ALIGN_8B		8	/*  8 bytes =  64-bit alignment */
#define OS_RG_ALIGN_16B		16	/* 16 bytes = 128-bit alignment */

#define OS_RG_ALIGN_DEFAULT	OS_RG_ALIGN_8B


/***************************************
 *
 * Macro definitions
 *
 */

/* Perform alignment on input 's' */
#define	ALIGN(s, align)	(((u32)(s) + ((align)-1)) & ~((align)-1))


/***************************************
 *
 * Typedefs & structure definitions
 *
 */
/*
 * Structure for region header/control area 
 */
typedef struct _Region_s {
	u8	*r_startBufferAddress;	/* start address to data buffer */
	u8	*r_endAddress;		/* end address of region */
	s32	r_bufferSize;		/* size of buffers for this region */
	s32	r_bufferCount;		/* up to 32K entries; MSB is used for 
					   setting end-of-list/used */
	u16 	r_freeList;		/* point to array index of first 
					   available memory buffer */
	u16 	r_alignSize;		/* alignment size (# of bytes) */
} OSRegion;

/*
 * Macro to simplify accessing region header structure
 */
#define	RP(x)		rp->r_##x


/***************************************
 *
 * Function prototypes
 *
 */
extern void	*osCreateRegion(void *, u32, u32, u32);
extern void 	*osMalloc(void *); 
extern void	osFree(void *, void *); 
extern s32	osGetRegionBufCount(void *); 
extern s32	osGetRegionBufSize(void *); 


#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif


#endif  /* _REGION_H_ */


