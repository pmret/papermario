#include "common.h"

void intro_logos_set_fade_alpha(s16 new_alpha) {
    GameStatus* gameStatus = GAME_STATUS;

    gameStatus->bootAlpha = new_alpha;
}

void intro_logos_set_fade_color(s16 arg0) {
    GameStatus* gameStatus = GAME_STATUS;

    gameStatus->bootRed = arg0;
    gameStatus->bootGreen = arg0;
    gameStatus->bootBlue = arg0;
}

s16 intro_logos_fade_in(subtract_val) {
    GameStatus* gameStatus = GAME_STATUS;

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

s16 intro_logos_fade_out(add_val) {
    GameStatus* gameStatus = GAME_STATUS;

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

void intro_logos_update_fade(void) {
    func_80137D88(0, GAME_STATUS->bootAlpha);
    func_80137E10(0, GAME_STATUS->bootBlue, GAME_STATUS->bootGreen, GAME_STATUS->bootRed);
}

void begin_state_battle(void) {
    D_800A0900 = 5;
}

INCLUDE_ASM(s32, "code_ebd0_len_6a0", step_battle);

void func_80033B54(void) {
    func_8003E5B0();
    if (D_800A0900 < 0) {
        draw_main_battle_ui();
    }
}

void func_80033B88(void) {
    D_8009A650[0] |= 0x08;
    nuContRmbForceStop();
    D_800A0900 = 5;
}

INCLUDE_ASM(s32, "code_ebd0_len_6a0", func_80033BC0);

void func_80033E64(void) {
}
