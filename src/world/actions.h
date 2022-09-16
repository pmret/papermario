#ifndef _WORLD_ACTIONS_H_
#define _WORLD_ACTIONS_H_

#include "common.h"

typedef struct Action {
    /* 0x00 */ void (*update)(void);
    /* 0x04 */ void* dmaStart;
    /* 0x08 */ void* dmaEnd;
    /* 0x0C */ s8 flag;
} Action; // size = 0x10

typedef struct DisguiseAnims {
    /* 0x00 */ s32 idle;
    /* 0x04 */ s32 walk;
    /* 0x08 */ s32 run;
    /* 0x0C */ s32 talk;
    /* 0x10 */ s32 still;
    /* 0x14 */ s32 hold;
} DisguiseAnims; // size = 0x18

extern f32 D_800F7B90;
extern Action PlayerActionsTable[39];

extern DisguiseAnims BasicPeachDisguiseAnims[4];
extern AnimID* PeachDisguiseExtraAnims[4];

#endif
