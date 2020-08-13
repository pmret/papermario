
/*====================================================================
 * os_vi.h
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
        
        $RCSfile: os_vi.h,v $
        $Revision: 1.1 $
        $Date: 1998/10/09 08:01:20 $
 *---------------------------------------------------------------------*/

#ifndef _OS_VI_H_
#define	_OS_VI_H_

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>
#include "os_thread.h"
#include "os_message.h"


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/**************************************************************************
 *
 * Type definitions
 *
 */

/*
 * Structure to store VI register values that remain the same between 2 fields
 */
typedef struct {
    u32	ctrl;
    u32	width;
    u32	burst;
    u32	vSync;
    u32	hSync;
    u32	leap;
    u32	hStart;
    u32	xScale;
    u32	vCurrent;
} OSViCommonRegs;


/*
 * Structure to store VI register values that change between fields
 */
typedef struct {
    u32	origin;
    u32	yScale;
    u32	vStart;	
    u32	vBurst;
    u32	vIntr;
} OSViFieldRegs;


/*
 * Structure for VI mode
 */
typedef struct {
    u8			type;		/* Mode type */
    OSViCommonRegs	comRegs;	/* Common registers for both fields */
    OSViFieldRegs	fldRegs[2];	/* Registers for Field 1  & 2 */
} OSViMode;


#endif /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

/**************************************************************************
 *
 * Global definitions
 *
 */

/*
 * Video Interface (VI) mode type
 */
#define OS_VI_NTSC_LPN1		0	/* NTSC */
#define OS_VI_NTSC_LPF1		1
#define OS_VI_NTSC_LAN1		2
#define OS_VI_NTSC_LAF1		3
#define OS_VI_NTSC_LPN2		4
#define OS_VI_NTSC_LPF2		5
#define OS_VI_NTSC_LAN2		6
#define OS_VI_NTSC_LAF2		7
#define OS_VI_NTSC_HPN1		8
#define OS_VI_NTSC_HPF1		9
#define OS_VI_NTSC_HAN1		10
#define OS_VI_NTSC_HAF1		11
#define OS_VI_NTSC_HPN2		12
#define OS_VI_NTSC_HPF2		13

#define OS_VI_PAL_LPN1		14	/* PAL */
#define OS_VI_PAL_LPF1		15
#define OS_VI_PAL_LAN1		16
#define OS_VI_PAL_LAF1		17
#define OS_VI_PAL_LPN2		18
#define OS_VI_PAL_LPF2		19
#define OS_VI_PAL_LAN2		20
#define OS_VI_PAL_LAF2		21
#define OS_VI_PAL_HPN1		22
#define OS_VI_PAL_HPF1		23
#define OS_VI_PAL_HAN1		24
#define OS_VI_PAL_HAF1		25
#define OS_VI_PAL_HPN2		26
#define OS_VI_PAL_HPF2		27

#define OS_VI_MPAL_LPN1		28	/* MPAL - mainly Brazil */
#define OS_VI_MPAL_LPF1		29
#define OS_VI_MPAL_LAN1		30
#define OS_VI_MPAL_LAF1		31
#define OS_VI_MPAL_LPN2		32
#define OS_VI_MPAL_LPF2		33
#define OS_VI_MPAL_LAN2		34
#define OS_VI_MPAL_LAF2		35
#define OS_VI_MPAL_HPN1		36
#define OS_VI_MPAL_HPF1		37
#define OS_VI_MPAL_HAN1		38
#define OS_VI_MPAL_HAF1		39
#define OS_VI_MPAL_HPN2		40
#define OS_VI_MPAL_HPF2		41

#define OS_VI_FPAL_LPN1         42      /* FPAL - Full screen PAL */
#define OS_VI_FPAL_LPF1         43
#define OS_VI_FPAL_LAN1         44
#define OS_VI_FPAL_LAF1         45
#define OS_VI_FPAL_LPN2         46
#define OS_VI_FPAL_LPF2         47
#define OS_VI_FPAL_LAN2         48
#define OS_VI_FPAL_LAF2         49
#define OS_VI_FPAL_HPN1         50
#define OS_VI_FPAL_HPF1         51
#define OS_VI_FPAL_HAN1         52
#define OS_VI_FPAL_HAF1         53
#define OS_VI_FPAL_HPN2         54
#define OS_VI_FPAL_HPF2         55

/*
 * Video Interface (VI) special features
 */
#define	OS_VI_GAMMA_ON			0x0001
#define	OS_VI_GAMMA_OFF			0x0002
#define	OS_VI_GAMMA_DITHER_ON		0x0004
#define	OS_VI_GAMMA_DITHER_OFF		0x0008
#define	OS_VI_DIVOT_ON			0x0010
#define	OS_VI_DIVOT_OFF			0x0020
#define	OS_VI_DITHER_FILTER_ON		0x0040
#define	OS_VI_DITHER_FILTER_OFF		0x0080

/*
 * Video Interface (VI) mode attribute bit
 */
#define OS_VI_BIT_NONINTERLACE		0x0001          /* lo-res */
#define OS_VI_BIT_INTERLACE		0x0002          /* lo-res */
#define OS_VI_BIT_NORMALINTERLACE	0x0004          /* hi-res */
#define OS_VI_BIT_DEFLICKINTERLACE	0x0008          /* hi-res */
#define OS_VI_BIT_ANTIALIAS		0x0010
#define OS_VI_BIT_POINTSAMPLE		0x0020
#define OS_VI_BIT_16PIXEL		0x0040
#define OS_VI_BIT_32PIXEL		0x0080
#define OS_VI_BIT_LORES			0x0100
#define OS_VI_BIT_HIRES			0x0200
#define OS_VI_BIT_NTSC			0x0400
#define OS_VI_BIT_PAL			0x0800


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

extern OSViMode	osViModeTable[];	/* Global VI mode table */

extern OSViMode	osViModeNtscLpn1;	/* Individual VI NTSC modes */
extern OSViMode	osViModeNtscLpf1;
extern OSViMode	osViModeNtscLan1;
extern OSViMode	osViModeNtscLaf1;
extern OSViMode	osViModeNtscLpn2;
extern OSViMode	osViModeNtscLpf2;
extern OSViMode	osViModeNtscLan2;
extern OSViMode	osViModeNtscLaf2;
extern OSViMode	osViModeNtscHpn1;
extern OSViMode	osViModeNtscHpf1;
extern OSViMode	osViModeNtscHan1;
extern OSViMode	osViModeNtscHaf1;
extern OSViMode	osViModeNtscHpn2;
extern OSViMode	osViModeNtscHpf2;

extern OSViMode	osViModePalLpn1;	/* Individual VI PAL modes */
extern OSViMode	osViModePalLpf1;
extern OSViMode	osViModePalLan1;
extern OSViMode	osViModePalLaf1;
extern OSViMode	osViModePalLpn2;
extern OSViMode	osViModePalLpf2;
extern OSViMode	osViModePalLan2;
extern OSViMode	osViModePalLaf2;
extern OSViMode	osViModePalHpn1;
extern OSViMode	osViModePalHpf1;
extern OSViMode	osViModePalHan1;
extern OSViMode	osViModePalHaf1;
extern OSViMode	osViModePalHpn2;
extern OSViMode	osViModePalHpf2;

extern OSViMode	osViModeMpalLpn1;	/* Individual VI MPAL modes */
extern OSViMode	osViModeMpalLpf1;
extern OSViMode	osViModeMpalLan1;
extern OSViMode	osViModeMpalLaf1;
extern OSViMode	osViModeMpalLpn2;
extern OSViMode	osViModeMpalLpf2;
extern OSViMode	osViModeMpalLan2;
extern OSViMode	osViModeMpalLaf2;
extern OSViMode	osViModeMpalHpn1;
extern OSViMode	osViModeMpalHpf1;
extern OSViMode	osViModeMpalHan1;
extern OSViMode	osViModeMpalHaf1;
extern OSViMode	osViModeMpalHpn2;
extern OSViMode	osViModeMpalHpf2;

extern OSViMode osViModeFpalLpn1;       /* Individual VI FPAL modes */
extern OSViMode osViModeFpalLpf1;
extern OSViMode osViModeFpalLan1;
extern OSViMode osViModeFpalLaf1;
extern OSViMode osViModeFpalLpn2;
extern OSViMode osViModeFpalLpf2;
extern OSViMode osViModeFpalLan2;
extern OSViMode osViModeFpalLaf2;
extern OSViMode osViModeFpalHpn1;
extern OSViMode osViModeFpalHpf1;
extern OSViMode osViModeFpalHan1;
extern OSViMode osViModeFpalHaf1;
extern OSViMode osViModeFpalHpn2;
extern OSViMode osViModeFpalHpf2;


/**************************************************************************
 *
 * Function prototypes
 *
 */

/* Video interface (Vi) */
extern u32		osViGetStatus(void);
extern u32		osViGetCurrentMode(void);
extern u32		osViGetCurrentLine(void);
extern u32		osViGetCurrentField(void);
extern void		*osViGetCurrentFramebuffer(void);
extern void		*osViGetNextFramebuffer(void);
extern void		osViSetXScale(f32);
extern void		osViSetYScale(f32);
extern void		osViExtendVStart(u32);
extern void		osViSetSpecialFeatures(u32);
extern void		osViSetMode(OSViMode *);
extern void		osViSetEvent(OSMesgQueue *, OSMesg, u32);
extern void		osViSwapBuffer(void *);
extern void		osViBlack(u8);
extern void		osViFade(u8, u16);
extern void		osViRepeatLine(u8);
extern void		osCreateViManager(OSPri);


#endif  /* defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS) */

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif /* !_OS_VI_H_ */
