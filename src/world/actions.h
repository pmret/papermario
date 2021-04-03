#ifndef _WORLD_ACTIONS_H_
#define _WORLD_ACTIONS_H_

#include "common.h"

typedef struct Action {
    /* 0x00 */ void (*init)(void);
    /* 0x04 */ void* dmaStart;
    /* 0x08 */ void* dmaEnd;
    /* 0x0C */ s8 flag;
} Action;

extern f32 D_800F7B90;
extern Action D_800F7C8C[39]; // size = 0x10 * 39

s32 func_802B6000_E24920();
s32 func_802B6288_E23968();
s32 func_802B60B4_E240F4();
s32 func_802B6198_E241D8();
s32 func_802B6294_E242D4();
s32 func_802B6060_E27570();
s32 func_802B6348_E24388();
s32 func_802B61C0_E24AE0();
s32 func_802B6638_E29068();
s32 func_802B66A8_E25578();
s32 func_802B6350_E28D80();
s32 func_802B6508_E28F38();
s32 func_802B6230_E24800();
s32 func_802B6120_E2A7D0();
s32 func_802B63D4_E28E04();
s32 func_802B6478_E28EA8();
s32 func_802B60A4_E29514();
s32 func_802B609C_E28ACC();

#endif
