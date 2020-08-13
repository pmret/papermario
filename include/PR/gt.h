
/*
 * Copyright 1995, Silicon Graphics, Inc.
 * ALL RIGHTS RESERVED
 *
 * UNPUBLISHED -- Rights reserved under the copyright laws of the United
 * States.   Use of a copyright notice is precautionary only and does not
 * imply publication or disclosure.
 *
 * U.S. GOVERNMENT RESTRICTED RIGHTS LEGEND:
 * Use, duplication or disclosure by the Government is subject to restrictions
 * as set forth in FAR 52.227.19(c)(2) or subparagraph (c)(1)(ii) of the Rights
 * in Technical Data and Computer Software clause at DFARS 252.227-7013 and/or
 * in similar or successor clauses in the FAR, or the DOD or NASA FAR
 * Supplement.  Contractor/manufacturer is Silicon Graphics, Inc.,
 * 2011 N. Shoreline Blvd. Mountain View, CA 94039-7311.
 *
 * THE CONTENT OF THIS WORK CONTAINS CONFIDENTIAL AND PROPRIETARY
 * INFORMATION OF SILICON GRAPHICS, INC. ANY DUPLICATION, MODIFICATION,
 * DISTRIBUTION, OR DISCLOSURE IN ANY FORM, IN WHOLE, OR IN PART, IS STRICTLY
 * PROHIBITED WITHOUT THE PRIOR EXPRESS WRITTEN PERMISSION OF SILICON
 * GRAPHICS, INC.
 *
 */

/*
 * File:	gt.h
 * Creator:	hsa@sgi.com
 * Create Date:	Thu Oct 12 15:48:14 PDT 1995
 *
 * This file defines the GBI for the TURBO 3D graphics microcode.
 * The turbo microcode is a special FEATURE-LIMITED microcode designed
 * for specific applications. It is not for general use.
 *
 * (see XXX for more information)
 *
 */

/**************************************************************************
 *
 *  $Revision: 1.16 $
 *  $Date: 1998/05/28 00:14:50 $
 *  $Source: /hosts/gate3/exdisk2/cvs/N64OS/Master/cvsmdev2/PR/include/gt.h,v $
 *
 **************************************************************************/

#ifndef _GT_H_
#define	_GT_H_

/* this file should be #included AFTER gbi.h */

#include "sptask.h"

#ifdef	_LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif	/* _LANGUAGE_C_PLUS_PLUS */

#include <PR/ultratypes.h>

/* the following #defines seem out of order, but we need them
 * for the microcode.
 */

/* 
 * object state field: rendState
 *
 * This flag word is built up out of the bits from a
 * subset of the G_SETGEOMETRYMODE flags from gbi.h.
 * 
 * When each of these bits is '1', the comments below explain
 * the effect on the triangles.
 */
#define GT_ZBUFFER		G_ZBUFFER
#define GT_TEXTURE		G_TEXTURE_ENABLE	/* texture ON */
#define GT_CULL_BACK		G_CULL_BACK		/* reject backfaces */
#define GT_SHADING_SMOOTH	G_SHADING_SMOOTH	/* smooth shade ON */

/*
 * object state field: textureState
 *
 * The lower 3 bits of this flag word contain the texture tile number
 * to be used. All triangles of an object are rendered with the same
 * texture tile.
 */

/* 
 * object state field: flag
 *
 * This is a group of what would be pad bits. We use them for some
 * flag bits.
 */
#define GT_FLAG_NOMTX		0x01	/* don't load the matrix */
#define GT_FLAG_NO_XFM		0x02	/* load vtx, use verbatim */
#define GT_FLAG_XFM_ONLY	0x04	/* xform vtx, write to *TriN */


#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)

/* turbo 3D ucode: */
extern long long int	gspTurbo3DTextStart[], gspTurbo3DTextEnd[];
extern long long int	gspTurbo3DDataStart[], gspTurbo3DDataEnd[];
extern long long int	gspTurbo3D_dramTextStart[], gspTurbo3D_dramTextEnd[];
extern long long int	gspTurbo3D_dramDataStart[], gspTurbo3D_dramDataEnd[];
extern long long int	gspTurbo3D_fifoTextStart[], gspTurbo3D_fifoTextEnd[];
extern long long int	gspTurbo3D_fifoDataStart[], gspTurbo3D_fifoDataEnd[];

/*
 * This is the global state structure. It's definition carefully 
 * matches the ucode, so if this structure changes, you must also change
 * the ucode.
 */
typedef struct {
    u16		perspNorm;	/* persp normalization */
    u16		pad0;
    u32		flag;
    Gfx		rdpOthermode;
    u32		segBases[16];	/* table of segment base addrs (SEE NOTE!) */
    Vp		viewport;	/* the viewport to use */
    Gfx		*rdpCmds;	/* block of RDP data, process if !NULL
				 * block terminated by gDPEndDisplayList()
				 * (This is a segment address)
				 */
} gtGlobState_t;

/* NOTE:
 * Although there are 16 segment table entries, the first one (segment 0)
 * is reserved for physical memory mapping. You should not segment 0
 * to anything other than 0x0.
 */

typedef union {
    gtGlobState_t	sp;
    long long int	force_structure_alignment;
} gtGlobState;


/*
 * This is the 'state' structure associated with each object
 * to be rendered. It's definition carefully matches the
 * ucode, so if this structure changes, you must also change
 * the gtoff.c tool and the ucode.
 */
typedef struct {
    u32		renderState;	/* render state */
    u32		textureState;	/* texture state */
    u8		vtxCount;	/* how many verts? */
    u8		vtxV0;		/* where to load verts? */
    u8		triCount;	/* how many tris? */
    u8		flag;
    Gfx		*rdpCmds;	/* ptr (segment address) to RDP DL */
    Gfx		rdpOthermode;
    Mtx		transform;	/* the transform matrix to use */
} gtState_t;

typedef union {
    gtState_t		sp;
    long long int	force_structure_alignment;
} gtState;

/* gtStateLite : same as gtState, but no matrix (see flags below) */
/* this structure must be identical to gtState! (bad) */
typedef struct {
    u32		renderState;	/* render state */
    u32		textureState;	/* texture state */
    u8		vtxCount;	/* how many verts? */
    u8		vtxV0;		/* where to load verts? */
    u8		triCount;	/* how many tris? */
    u8		flag;
    Gfx		*rdpCmds;	/* ptr (segment address) to RDP DL */
    Gfx		rdpOthermode;
} gtStateL_t;

typedef union {
    gtStateL_t		sp;
    long long int	force_structure_alignment;
} gtStateL;

/*
 * The vertex list for the turbo display list uses the
 * Vtx struct in gbi.h
 *
 */


/*
 * This structure represents a single triangle, part of the
 * triangle list of the object to be rendered.
 *
 * NOTE: The triangle list MUST be aligned to an 8-byte boundary.
 * Since this structure is only 4 bytes, we are REQUIRING that
 * this structure only be used as an array of triangles, and we 
 * depend on the MIPS C compiler (which always aligns arrays to 
 * 8-byte boundaries). THIS IS DANGEROUS!!!!
 *
 */
typedef struct {
    u8		v0, v1, v2, flag;	/* flag is which one for flat shade */
} gtTriN;


/*
 * This structure represents the transformed points. It is the format
 * of the points written out when GT_FLAG_XFM_ONLY is set, as well as
 * the format expected when GT_FLAG_NO_XFM is used.
 *
 * NOTE: The size and layout of these points is very similar to Vtx,
 * except the screen coordinates overwrite the x,y,z,pad fields.
 * (we could consider adding to the Vtx union, but we want to keep
 * turbo stuff out of gbi.h)
 *
 * NOTE: The z is a special format. It can be used to compare vertices
 * for sorting, but it should not be used for other purposes. If modified,
 * the z-buffer hardware might not understand the data.
 *
 */
typedef struct {
    short int	xscrn;	/* x,y screen coordinates are SSSS10.2	*/
    short int	yscrn;
    int		zscrn;	/* z screen is S15.16			*/

    short int	s;	/* transformed texture coord, S10.5	*/
    short int	t;

    u8		r;	/* color (or normal)			*/
    u8		g;
    u8		b;
    u8		a;
} gtVtxOut_t;

/* see "Data Structure" comment in gbi.h for information about why
 * we use this union.
 */
typedef union {
    gtVtxOut_t		v;
    long long int	force_structure_alignment;
} gtVtxOut;



/*
 * state field: rdpOthermode
 *
 * This is one of the trickier state fields. The turbo interface
 * requires the RDP othermode command to be cached by the host,
 * therefore we provide a different interface in libultra to help cache
 * this in the gt state (this word is just bits, you could pack them
 * on your own). 
 *
 * gtStateSetOthermode() accomplishs this, taking as arguments 
 * the state, one of the following mode enums, and a piece of data 
 * (othermode parameters from gbi.h).
 *
 * By definition, the othermode word from the gt state structure is sent
 * to the RDP *before* any RDP commands from the rdpCmds[] field. The
 * othermode is *always* sent.
 *
 * Stated another way, NONE of the gbi RDP othermode commands equivalent
 * to those listed here are allowed in the rdpCmd[] field of the 
 * gt state structure.
 *
 * Notice also that many of these commands do not make sense for
 * the turbo ucode (they control features not supported, like mip-mapping). 
 * They are only included here for completeness.
 *
 */
typedef enum {
    GT_CLEAR,		/* special gt mode, clears othermode state */
    GT_ALPHACOMPARE,
    GT_ZSRCSEL,
    GT_RENDERMODE,
    GT_ALPHADITHER,
    GT_RGBDITHER,
    GT_COMBKEY,
    GT_TEXTCONV,
    GT_TEXTFILT,
    GT_TEXTLUT,
    GT_TEXTLOD,
    GT_TEXTDETAIL,
    GT_TEXTPERSP,
    GT_CYCLETYPE,
    GT_PIPELINE
} gtStateOthermode_t;

/*
 * This call builds up an othermode command word. The 'mode' is one of
 * the above modes, the 'data' field comes from gbi.h, it is the data
 * field for the equivalent gbi setothermode macro.
 */
extern void gtStateSetOthermode(Gfx *om, gtStateOthermode_t mode, int data);

/* 
 * This call dumps a turbo display list for use with gbi2mem and RSPSIM
 */
#define GT_DUMPTURBO_HANGAFTER           64
#define GT_DUMPTURBO_NOTEXTURES          128
extern void gtDumpTurbo(OSTask *tp,u8 flags);

/*
 * Special macros to init othermode words to all 0's, a good default
 * value.
 */
#define gDPClearOtherMode(pkt)						\
{									\
	Gfx *_g = (Gfx *)(pkt);						\
									\
	_g->words.w0 = _SHIFTL(G_RDPSETOTHERMODE, 24, 8);		\
	_g->words.w1 = 0x0;						\
}

#define gsDPClearOtherMode()						\
{									\
	_SHIFTL(G_RDPSETOTHERMODE, 24, 8), 0x0				\
}

/*
 * Special macros to end DP blocks (see above). These commands
 * generate all 0's, which the turbo ucode looks for. They *aren't*
 * real DP commands!
 */
#define gDPEndDisplayList(pkt)	gSPNoOp(pkt)
#define gsDPEndDisplayList()	gsSPNoOp()

/*
 * This structure is a turbo 'object', the turbo display list is
 * simply a list of these.
 *
 * NOTE: All pointers are segment addresses
 *
 * NOTE: If (statep->flag & GT_FLAG_XFM_ONLY), the trip field is
 * interpreted as a pointer to gtVtxOut[] that can be used to store
 * the transformed points. (statep->triCount should be 0, else bad
 * things could happen...)
 *
 * NOTE: If (statep->flag & GT_FLAG_NO_XFM), the vtxp field is
 * interpreted as a pointer to gtVtxOut[] that can be used to load
 * pre-transformed points.
 *
 */
typedef struct {
    gtGlobState	*gstatep;	/* global state, usually NULL */
    gtState	*statep;	/* if this is NULL, end object processing */
    Vtx		*vtxp;		/* if this is NULL, use points in buffer */
    gtTriN	*trip;		/* if this is NULL, use tris in buffer */
} gtGfx_t;

typedef union {
    gtGfx_t		obj;
    long long int	force_structure_alignment;
} gtGfx;


#endif	/* _LANGUAGE_C */

#ifdef	_LANGUAGE_ASSEMBLY
#include <PR/gtoff.h>
#endif	/* _LANGUAGE_ASSEMBLY */

#ifdef	_LANGUAGE_C_PLUS_PLUS
}
#endif	/* _LANGUAGE_C_PLUS_PLUS */

#ifdef	_LANGUAGE_MAKEROM
#endif	/* _LANGUAGE_MAKEROM */

#endif	/* _GT_H_ */
