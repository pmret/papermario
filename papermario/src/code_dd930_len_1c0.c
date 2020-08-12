#include "common.h"

typedef struct {
        s16 unk0;
        s16 unk2;
        s32 unk4;
        s32 unk8;
        s32 unkC;
} struct_80147230;

extern struct_80147230 D_8014F140;
extern struct_80147230 D_8015C7C0;

void func_80147230(void) {
        D_8015C7C0 = D_8014F140;
}

void UpdateMusicPlayers(void) {
    struct_80147230* temp = &D_8015C7C0;

    switch (temp->unk2) {
        case 0:
            break;
        case 1:
            if (temp->unk0 & 1) {
                s32 phi_v0;
                if (temp->unk4 < 0xFA) {
                    phi_v0 = func_800554A4(0, temp->unk4);
                } else {
                    phi_v0 = func_800554E8(0, temp->unk4);
                }
                if (phi_v0 != 0) {
                    return;
                }
            }
            temp->unk2 = 2;
            break;
        case 2:
            if (temp->unk0 & 1) {
                if (func_800555E4(0) != 0) {
                    return;
                }
                temp->unk0 &= ~1;
            }
            if (temp->unk8 < 0) {
                temp->unk2 = 0;
            } else if (func_80055448(temp->unk8) == 0) {
                if (func_80055464(0, 0) == 0) {
                    temp->unk2 = 0;
                    temp->unk0 |= 1;
                }
            }
            break;
    }
}

s32 play_ambient_sounds(s32 arg0, s32 arg1) {
    struct_80147230* temp1 = &D_8015C7C0;
    struct_80147230* temp2 = &D_8015C7C0;

    if ((*gGameStatusPtr)->musicEnabled == 0) {
        func_800554A4(temp1->unk8, arg1);
        temp1->unk0 &= ~1;
        return 1;
    }

    if (temp1->unk8 == arg0) {
        return 2;
    }

    temp2->unk8 = arg0;
    temp2->unk4 = arg1;
    temp2->unk2 = 1;
    return 1;
}