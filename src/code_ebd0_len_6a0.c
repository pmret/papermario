#include "common.h"

void func_800337D0(s16 new_alpha) {
    GameStatus* gameStatus = *gGameStatusPtr;

    gameStatus->bootAlpha = new_alpha;
}

void func_800337E0(s16 arg0) {
    GameStatus* gameStatus = *gGameStatusPtr;

    gameStatus->bootRed = arg0;
    gameStatus->bootGreen = arg0;
    gameStatus->bootBlue = arg0;
}

s16 func_800337F8(subtract_val) {
    GameStatus* gameStatus = *gGameStatusPtr;

    if (gameStatus->bootAlpha != 0) {
        gameStatus->bootAlpha -= subtract_val;
        if (gameStatus->bootAlpha << 16 < 0) {
            gameStatus->bootAlpha = 0;
        }
    } else {
        return 1;
    }
    return 0;
}

s16 func_80033830(add_val) {
    GameStatus* gameStatus = *gGameStatusPtr;

    if (gameStatus->bootAlpha != 0xFF) {
        gameStatus->bootAlpha += add_val;
        if ((gameStatus->bootAlpha > 0xFF)) {
            gameStatus->bootAlpha = 0xFF;
        }
    } else {
        return 1;
    }
    return 0;
}


void func_80033874(void) {
    func_80137D88(0, (*gGameStatusPtr)->bootAlpha);
    func_80137E10(0, (*gGameStatusPtr)->bootBlue, (*gGameStatusPtr)->bootGreen, (*gGameStatusPtr)->bootRed);
}

void start_battle_countdown(void) {
    D_800A0900 = 5;
}

INCLUDE_ASM("code_ebd0_len_6a0", step_battle);
INCLUDE_ASM("code_ebd0_len_6a0", func_80033B54);
INCLUDE_ASM("code_ebd0_len_6a0", func_80033B88);
INCLUDE_ASM("code_ebd0_len_6a0", func_80033BC0);
INCLUDE_ASM("code_ebd0_len_6a0", func_80033E64);
