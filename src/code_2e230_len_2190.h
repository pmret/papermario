#ifndef _CODE_2E230_LEN_2190_H_
#define _CODE_2E230_LEN_2190_H_

#include "common.h"

// Probably some libultra audio thing
typedef struct UnkStructFor80053A18 {
    /* 0x00 */ UNK_TYPE unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ char unk_08[2];
    /* 0x0A */ u16 unk_0A;
    /* 0x0C */ s32 unk_0C;
} UnkStructFor80053A18; // size unknown

typedef struct alUnk1 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s16 unk_08;
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ char unk_0C[4];
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ s16 unk_1A;
} alUnk1;

typedef struct alUnk2 {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ s8 unk_04;
    /* 0x05 */ s8 unk_05;
    /* 0x06 */ s8 unk_06;
} alUnk2;

void func_80053A18(UnkStructFor80053A18* arg0);

#endif
