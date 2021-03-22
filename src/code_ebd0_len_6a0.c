#include "code_ebd0_len_6a0.h"

void intro_logos_set_fade_alpha(s16 alpha) {
    gGameStatusPtr->bootAlpha = alpha;
}

void intro_logos_set_fade_color(s16 color) {
    gGameStatusPtr->bootRed = color;
    gGameStatusPtr->bootGreen = color;
    gGameStatusPtr->bootBlue = color;
}

s16 intro_logos_fade_in(s16 subtractAlpha) {
    if (gGameStatusPtr->bootAlpha != 0) {
        gGameStatusPtr->bootAlpha -= subtractAlpha;
        if (gGameStatusPtr->bootAlpha << 16 < 0) {
            gGameStatusPtr->bootAlpha = 0;
        }
    } else {
        return 1;
    }
    return 0;
}

s16 intro_logos_fade_out(s16 addAlpha) {
    if (gGameStatusPtr->bootAlpha != 0xFF) {
        gGameStatusPtr->bootAlpha += addAlpha;
        if ((gGameStatusPtr->bootAlpha > 0xFF)) {
            gGameStatusPtr->bootAlpha = 0xFF;
        }
    } else {
        return 1;
    }
    return 0;
}

void intro_logos_update_fade(void) {
    GameStatus** gameStatus = &gGameStatusPtr;
    
    set_transition_stencil_zoom_0(0, (*gameStatus)->bootAlpha);
    set_transition_stencil_color(0, (*gameStatus)->bootBlue, (*gameStatus)->bootGreen, (*gameStatus)->bootRed);
}

void begin_state_battle(void) {
    D_800A0900 = 5;
}

INCLUDE_ASM(s32, "code_ebd0_len_6a0", step_battle);

void func_80033B54(void) {
    draw_encounter_ui();
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
