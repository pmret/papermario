#ifndef _CODE_28910_LEN_5090_H_
#define _CODE_28910_LEN_5090_H_

#include "common.h"
#include "code_2e230_len_2190.h"

typedef struct {
    /* 0x000 */ char unk_000[8];
    /* 0x008 */ s32 unk_008;
    /* 0x00C */ char unk_00C[4];
    /* 0x010 */ s32 unk_010;
    /* 0x014 */ char unk_014[8];
    /* 0x01C */ UNK_TYPE unk_01C;
    /* 0x020 */ char unk_020[0xC];
    /* 0x02C */ UnkStructFor80053A18 unk_02C;
    /* 0x03C */ char unk_03C[0x1E5];
    /* 0x221 */ u8 unk_221;
} UnkStructFor8004DAA8; // size unknown

void func_8004DAA8(UnkStructFor8004DAA8* arg0);

#endif
