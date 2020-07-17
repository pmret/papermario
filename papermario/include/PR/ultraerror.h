/*====================================================================
 * ultraerror.h
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

/**************************************************************************
 *
 *  $Revision: 1.27 $
 *  $Date: 1999/07/14 02:44:00 $
 *  $Source: /hosts/gate3/exdisk2/cvs/N64OS/Master/cvsmdev2/PR/include/ultraerror.h,v $
 *
 **************************************************************************/

#ifndef __ULTRAERROR_H__
#define __ULTRAERROR_H__

#ifdef _LANGUAGE_C_PLUS_PLUS
extern "C" {
#endif

#include <PR/ultratypes.h>

#define	OS_ERROR_FMT	"/usr/lib/PR/error.fmt"
#define OS_ERROR_MAGIC	0x6b617479

/* OS error codes */

#define	ERR_OSCREATETHREAD_SP		1
#define	ERR_OSCREATETHREAD_PRI		2
#define	ERR_OSSTARTTHREAD		3
#define	ERR_OSSETTHREADPRI		4
#define	ERR_OSCREATEMESGQUEUE		5
#define	ERR_OSSENDMESG			6
#define	ERR_OSJAMMESG			7
#define	ERR_OSRECVMESG			8
#define	ERR_OSSETEVENTMESG		9
#define	ERR_OSMAPTLB_INDEX		10
#define	ERR_OSMAPTLB_ASID		11
#define	ERR_OSUNMAPTLB			12
#define	ERR_OSSETTLBASID		13
#define	ERR_OSAISETFREQUENCY		14
#define	ERR_OSAISETNEXTBUFFER_ADDR	15
#define	ERR_OSAISETNEXTBUFFER_SIZE	16
#define	ERR_OSDPSETNEXTBUFFER_ADDR	17
#define	ERR_OSDPSETNEXTBUFFER_SIZE	18
#define	ERR_OSPIRAWREADIO		19
#define	ERR_OSPIRAWWRITEIO		20
#define	ERR_OSPIRAWSTARTDMA_DIR		21
#define	ERR_OSPIRAWSTARTDMA_DEVADDR	22
#define	ERR_OSPIRAWSTARTDMA_ADDR	23
#define	ERR_OSPIRAWSTARTDMA_SIZE	24
#define	ERR_OSPIRAWSTARTDMA_RANGE	25
#define	ERR_OSPIREADIO			26
#define	ERR_OSPIWRITEIO			27
#define	ERR_OSPISTARTDMA_PIMGR		28
#define	ERR_OSPISTARTDMA_PRI		29
#define	ERR_OSPISTARTDMA_DIR		30
#define	ERR_OSPISTARTDMA_DEVADDR	31
#define	ERR_OSPISTARTDMA_ADDR		32
#define	ERR_OSPISTARTDMA_SIZE		33
#define	ERR_OSPISTARTDMA_RANGE		34
#define	ERR_OSCREATEPIMANAGER		35
#define	ERR_OSVIGETCURRENTMODE		36
#define	ERR_OSVIGETCURRENTFRAMEBUFFER	37
#define	ERR_OSVIGETNEXTFRAMEBUFFER	38
#define	ERR_OSVISETXSCALE_VALUE		39
#define	ERR_OSVISETXSCALE_VIMGR		40
#define	ERR_OSVISETYSCALE_VALUE		41
#define	ERR_OSVISETYSCALE_VIMGR		42
#define	ERR_OSVISETSPECIAL_VALUE	43
#define	ERR_OSVISETSPECIAL_VIMGR	44
#define	ERR_OSVISETMODE			45
#define	ERR_OSVISETEVENT		46
#define	ERR_OSVISWAPBUFFER_ADDR		47
#define	ERR_OSVISWAPBUFFER_VIMGR	48
#define	ERR_OSCREATEVIMANAGER		49
#define	ERR_OSCREATEREGION_ALIGN	50
#define	ERR_OSCREATEREGION_SIZE		51
#define	ERR_OSMALLOC			52
#define	ERR_OSFREE_REGION		53
#define	ERR_OSFREE_ADDR			54
#define	ERR_OSGETREGIONBUFCOUNT		55
#define	ERR_OSGETREGIONBUFSIZE		56
#define	ERR_OSSPTASKLOAD_DRAM		57
#define	ERR_OSSPTASKLOAD_OUT		58
#define	ERR_OSSPTASKLOAD_OUTSIZE	59
#define	ERR_OSSPTASKLOAD_YIELD		60
#define ERR_OSPROFILEINIT_STR		61
#define ERR_OSPROFILEINIT_CNT		62
#define ERR_OSPROFILEINIT_ALN		63
#define ERR_OSPROFILEINIT_ORD		64
#define	ERR_OSPROFILEINIT_SIZ		65
#define ERR_OSPROFILESTART_TIME		66
#define ERR_OSPROFILESTART_FLAG		67
#define	ERR_OSPROFILESTOP_FLAG		68
#define ERR_OSPROFILESTOP_TIMER		69
#define	ERR_OSREADHOST_ADDR		70
#define	ERR_OSREADHOST_SIZE		71
#define	ERR_OSWRITEHOST_ADDR		72
#define	ERR_OSWRITEHOST_SIZE		73
#define	ERR_OSGETTIME			74
#define	ERR_OSSETTIME			75
#define	ERR_OSSETTIMER			76
#define	ERR_OSSTOPTIMER			77
#define	ERR_ALSEQP_NO_SOUND		100
#define	ERR_ALSEQP_NO_VOICE		101
#define	ERR_ALSEQP_MAP_VOICE		102
#define	ERR_ALSEQP_OFF_VOICE		103
#define	ERR_ALSEQP_POLY_VOICE		104
#define	ERR_ALSNDP_NO_VOICE		105
#define	ERR_ALSYN_NO_UPDATE		106
#define	ERR_ALSNDPDEALLOCATE		107
#define	ERR_ALSNDPDELETE		108
#define	ERR_ALSNDPPLAY			109
#define	ERR_ALSNDPSETSOUND		110
#define ERR_ALSNDPSETPRIORITY           111
#define ERR_ALSNDPSETPAR                112
#define	ERR_ALBNKFNEW			113
#define ERR_ALSEQNOTMIDI                114
#define ERR_ALSEQNOTMIDI0               115
#define ERR_ALSEQNUMTRACKS              116
#define ERR_ALSEQTIME                   117
#define ERR_ALSEQTRACKHDR               118
#define ERR_ALSEQSYSEX                  119
#define ERR_ALSEQMETA                   120
#define ERR_ALSEQPINVALIDPROG           121
#define ERR_ALSEQPUNKNOWNMIDI           122
#define ERR_ALSEQPUNMAP                 123
#define ERR_ALEVENTNOFREE               124
#define ERR_ALHEAPNOFREE                125
#define ERR_ALHEAPCORRUPT               126
#define ERR_ALHEAPFIRSTBLOCK            127
#define ERR_ALCSEQZEROSTATUS		128
#define ERR_ALCSEQZEROVEL		129
#define ERR_ALCSPVNOTFREE		130
#define ERR_ALSEQOVERRUN		131
#define ERR_OSAISETNEXTBUFFER_ENDADDR	132
#define ERR_ALMODDELAYOVERFLOW		133
#define ERR_OSVIEXTENDVSTART_VIMGR	134
#define ERR_OSVIEXTENDVSTART_VALUE	135
#define ERR_OSTHPROFILESTART_FLAG       136
#define ERR_OSTHPROFILESTART_START      137
#define ERR_OSTHPROFILESTOP_FLAG        138
#define ERR_OSTHPROFILEREADCOUNT_FLAG   139
#define ERR_OSTHPROFILEREADTIME_FLAG    140
#define ERR_OSTHPROFILEREADCOUNTTH_FLAG 141
#define ERR_OSTHPROFILEREADTIMETH_FLAG  142
#define ERR_OSTHPROFILEREADCOUNT_LAR    143
#define ERR_OSTHPROFILEREADTIME_LAR     144
#define ERR_OSTHPROFILEREADCOUNTTH_LAR  145
#define ERR_OSTHPROFILEREADTIMETH_LAR   146
#define ERR_OSTHPROFILESTOP_LAR         147

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)
typedef	void (*OSErrorHandler)(s16, s16, ...);

OSErrorHandler	osSetErrorHandler(OSErrorHandler);
#endif

#ifdef _LANGUAGE_C_PLUS_PLUS
}
#endif

#endif	/* __ULTRAERROR_H__ */
