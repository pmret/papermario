#include "common.h"

void func_800287F0(void) {
    gGameStatusPtr->currentButtons = 0;
    gGameStatusPtr->pressedButtons = 0;
    gGameStatusPtr->heldButtons = 0;
    gGameStatusPtr->stickX = 0;
    gGameStatusPtr->stickY = 0;
    gGameStatusPtr->prevButtons = 0;
    gGameStatusPtr->unk_50[0] = 4;
    gGameStatusPtr->unk_48[0] = 15;
    gGameStatusPtr->unk_60 = 0;
    gGameStatusPtr->unk_58 = 0;
}

void func_80028838(void) {
    func_800287F0();
    D_8009A6A0 = 0;
    D_8009A6A2 = 0;
    D_8009A6A4 = 0;
    D_8009A6A6 = 0;
}

INCLUDE_ASM(s32, "3bf0_len_6f0", update_input);
