#include "common.h"

void func_800337D0(s16 new_alpha) {
    game_status* gameStatus = *gGameStatusPtr;
    gameStatus->boot_alpha = new_alpha;
    return;
}

void func_800337E0(s16 arg0) {
    game_status* gameStatus = *gGameStatusPtr;
    gameStatus->boot_red = arg0;
    gameStatus->boot_green = arg0;
    gameStatus->boot_blue = arg0;
}

s16 func_800337F8(subtract_val) {
    game_status* gameStatus = *gGameStatusPtr;
    if (gameStatus->boot_alpha != 0) {
        gameStatus->boot_alpha -= subtract_val;
        if (gameStatus->boot_alpha << 0x10 < 0) {
            gameStatus->boot_alpha = 0;
        }
    } else {
        return 1;
    }
    return 0;
}

s16 func_80033830(add_val) {
    game_status* gameStatus = *gGameStatusPtr;
    if (gameStatus->boot_alpha != 0xFF) {
        gameStatus->boot_alpha += add_val;
        if ((gameStatus->boot_alpha >= 0x100)) {
            gameStatus->boot_alpha = 0xFF;
        }
    } else {
        return 1;
    }
    return 0;
}


void func_80033874(void) {
    
    func_80137D88(0, (*gGameStatusPtr)->boot_alpha);
    func_80137E10(0, (*gGameStatusPtr)->boot_blue, (*gGameStatusPtr)->boot_green, (*gGameStatusPtr)->boot_red);
    return 0;
}

s8 start_battle_countdown(void) {
    D_800A0900 = 5;
}


INCLUDE_ASM(code_ebd0_len_6a0, step_battle);
