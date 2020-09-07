#include "common.h"

void func_800287F0(void) {
    GameStatus* gameStatus = *gGameStatusPtr;
    GameStatus* gameStatus2;
    GameStatus* gameStatus3;

    gameStatus->stickX = 0;
    gameStatus2 = *gGameStatusPtr;
    gameStatus->currentButtons = 0;
    gameStatus->pressedButtons = 0;
    gameStatus->heldButtons = 0;
    gameStatus2->stickY = 0;

    gameStatus3 = *gGameStatusPtr;
    gameStatus3->unk_50 = 4;
    gameStatus3->prevButtons = 0;
    gameStatus3->unk_48 = 15;
    gameStatus3->unk_60 = 0;
    gameStatus3->unk_58 = 0;
}

INCLUDE_ASM("code_3bf0_len_6f0", func_80028838);

INCLUDE_ASM("code_3bf0_len_6f0", update_input);
