#include "common.h"
#include "audio.h"

void func_800525A0(UnkAl19E0* arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(arg0->unk_1320); i++) {
        UnkAl48* temp = &arg0->unk_1320[i];

        if (temp->unk_42 != 0) {
            func_80056EE8(i);
            temp->unk_42 = 0;
            temp->unk_1C = NULL;
            temp->unk_45 = 0;
        }
    }
}

void func_80052614(UnkAl19E0* arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(arg0->unk_1320); i++) {
        UnkAl48* temp = &arg0->unk_1320[i];

        temp->unk_1C = 0;
        temp->unk_20 = 0;
        temp->unk_24 = 0;
        temp->unk_28 = 0;
        temp->unk_3B = 0;
        temp->unk_3C = 0;
        temp->unk_3D = 0;
        temp->unk_3E = 0;
        temp->unk_3F = 0x80;
    }
}

INCLUDE_ASM(void, "2d9a0_len_890", func_80052660, UnkAl19E0* arg0);

void func_80052B44(UnkAl48* arg0) {
    s32 temp_lo = ((arg0->unk_3A * arg0->unk_40 * arg0->unk_3F) >> 14) * arg0->unk_30;

    arg0->unk_0C = temp_lo >> 7;
    arg0->unk_08 = func_80052BC0(arg0->unk_28);
    arg0->unk_3D &= ~0x2;
    arg0->unk_43 |= 0x4;
}

s32 func_80052BC0(s32 arg0) {
    return (arg0 / 5750) * 0xB8;
}

INCLUDE_ASM(void, "2d9a0_len_890", func_80052BF8, UnkAl48* arg0, s32* arg1);

INCLUDE_ASM(s32, "2d9a0_len_890", func_80052CFC, UnkAl48* arg0);

void func_80052E18(UnkAl48* arg0) {
    arg0->unk_3D |= 0x20;
}
