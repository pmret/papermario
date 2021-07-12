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
    /* 0x00 */ NpcAnimID idle;
    /* 0x04 */ NpcAnimID unk_04;
    /* 0x08 */ NpcAnimID unk_08;
    /* 0x0C */ NpcAnimID unk_0C;
    /* 0x10 */ NpcAnimID unk_10;
    /* 0x10 */ NpcAnimID unk_14;
} DisguiseAnims; // size = 0x18

extern f32 D_800F7B90;
extern Action D_800F7C8C[39];

extern DisguiseAnims world_actions_peachDisguises[];

#endif
