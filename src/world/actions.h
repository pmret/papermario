#ifndef _WORLD_ACTIONS_H_
#define _WORLD_ACTIONS_H_

#include "common.h"

typedef struct Action {
    /* 0x00 */ void (*update)(void);
    /* 0x04 */ void* dmaStart;
    /* 0x08 */ void* dmaEnd;
    /* 0x0C */ s8 flag;
} Action;

extern f32 D_800F7B90;
extern Action D_800F7C8C[39]; // size = 0x10 * 39

#endif
