/*====================================================================
 *
 * Copyright 1993, Silicon Graphics, Inc.
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

#ifndef __N_ABI__
#define	__N_ABI__

/*
 * BEGIN C-specific section: (typedef's)
 */

#if defined(_LANGUAGE_C) || defined(_LANGUAGE_C_PLUS_PLUS)


/*
 * Macros to assemble the audio command list
 */

#define	n_aADPCMdec(pkt, s, f, c, a, d)					\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_ADPCM, 24, 8) | _SHIFTL(s, 0, 24));   \
	_a->words.w1 = (_SHIFTL(f, 28, 4) | _SHIFTL(c, 16, 12) |        \
			_SHIFTL(a, 12, 4) | _SHIFTL(d, 0, 12));         \
}

#define n_aPoleFilter(pkt, f, g, t, s)					\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_POLEF, 24, 8) | _SHIFTL(f, 16, 8) |	\
			_SHIFTL(g, 0, 16)); 				\
	_a->words.w1 = (_SHIFTL(t, 24, 8) |                             \
			_SHIFTL((unsigned int)(s), 0, 24));		\
}

#define n_aEnvMixer(pkt, f, t, s)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_ENVMIXER, 24, 8) | _SHIFTL(f, 16, 8) |\
			_SHIFTL(t, 0, 16));                     	\
	_a->words.w1 = (unsigned int)(s);				\
}

#define n_aInterleave(pkt)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = _SHIFTL(A_INTERLEAVE, 24, 8);    		\
}

#define n_aLoadBuffer(pkt, c, d, s)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_LOADBUFF, 24, 8) | _SHIFTL(c, 12, 12)|\
			_SHIFTL(d, 0, 12));                             \
	_a->words.w1 = (unsigned int)(s);				\
}

#define n_aResample(pkt, s, f, p, i, o)					\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_RESAMPLE, 24, 8) | _SHIFTL(s, 0, 24));\
	_a->words.w1 = (_SHIFTL(f, 30, 2) | _SHIFTL(p, 14, 16) |        \
			_SHIFTL(i, 2, 12) | _SHIFTL(o, 0, 2));          \
}

#define n_aSaveBuffer(pkt, c, d, s)					\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_SAVEBUFF, 24, 8) | _SHIFTL(c, 12, 12)|\
			_SHIFTL(d, 0, 12));                             \
	_a->words.w1 = (unsigned int)(s);				\
}

#define n_aSetVolume(pkt, f, v, t, r)					\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = (_SHIFTL(A_SETVOL, 24, 8) | _SHIFTL(f, 16, 8) |	\
			_SHIFTL(v, 0, 16)); 				\
	_a->words.w1 = _SHIFTL(t, 16, 16) | _SHIFTL(r, 0, 16);		\
}

#define n_aLoadADPCM(pkt, c, d)						\
{									\
	Acmd *_a = (Acmd *)pkt;						\
									\
	_a->words.w0 = _SHIFTL(A_LOADADPCM, 24, 8) | _SHIFTL(c, 0, 24);	\
        _a->words.w1 = (unsigned int) d;                                \
}

#endif /* _LANGUAGE_C */

#endif /* __N_ABI__ */
