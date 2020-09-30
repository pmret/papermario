#include "common.h"

void func_800287F0(void) {
    // TODO: Figure out macros
    GameStatus* gameStatus;
    GameStatus* gameStatus2;

    gameStatus = *gGameStatusPtr;
    gameStatus->stickX = 0;
    gameStatus2 = *gGameStatusPtr;
    gameStatus->currentButtons = 0;
    gameStatus->pressedButtons = 0;
    gameStatus->heldButtons = 0;
    gameStatus2->stickY = 0;

    // TODO: macro
    {
        GameStatus* gameStatus = *gGameStatusPtr;
        gameStatus->prevButtons = 0;
        gameStatus->unk_50 = 4;
        gameStatus->unk_48 = 15;
        gameStatus->unk_60 = 0;
        gameStatus->unk_58 = 0;
    }
}

INCLUDE_ASM(s32, "code_3bf0_len_6f0", func_80028838);

INCLUDE_ASM(s32, "code_3bf0_len_6f0", update_input);
