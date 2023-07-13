#ifndef _IMGFX_H_
#define _IMGFX_H_

#include "PR/gbi.h"

// 'compressed' vertex data for animated image fx keyframes
typedef struct ImgFXVtx {
    /* 0x00 */ s16 ob[3];
    /* 0x06 */ u8 tc[2];
    /* 0x08 */ s8 cn[3];
    /* 0x0B */ char unk_0B;
} ImgFXVtx; // size = 0x0C

typedef struct ImgFXAnimHeader {
    /* 0x00 */ ImgFXVtx* keyframesOffset;
    /* 0x04 */ Gfx* gfxOffset; // Gfx for creating mesh from vertices
    /* 0x08 */ u16 vtxCount; // conserved across keyframes
    /* 0x0A */ u16 gfxCount;
    /* 0x0C */ u16 keyframesCount;
    /* 0x0E */ u16 flags;
} ImgFXAnimHeader; // size = 0x10

#endif /* _IMGFX_H_ */
