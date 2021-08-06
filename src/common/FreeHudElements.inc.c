#include "common.h"

extern struct D_8029FBE0 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
} D_8029FBE0; // size = 0x10

void N(FreeHudElements)(void) {
    free_hud_element(D_8029FBE0.unk_04);
    free_hud_element(D_8029FBE0.unk_08);
    free_hud_element(D_8029FBE0.unk_0C);
}

