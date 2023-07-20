#include "common.h"

SHIFT_BSS GameMode gMainGameState[2]; // TODO rename

void state_delegate_NOP(void) {
}

void clear_game_modes(void) {
    GameMode* gameMode;
    s32 i;

    for (gameMode = gMainGameState, i = 0; i < ARRAY_COUNT(gMainGameState); i++, gameMode++) {
        gameMode->flags = 0;
    }
}

GameMode* set_next_game_mode(GameMode* arg0) {
    GameMode* gameMode;
    s32 i;

    for (gameMode = gMainGameState, i = 0; i < ARRAY_COUNT(gMainGameState); i++, gameMode++) {
        if (gameMode->flags == 0) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(gMainGameState));

    gameMode->flags = 1 | 2;
    gameMode->init = arg0->init;
    gameMode->step = arg0->step;
    gameMode->render = arg0->render;
    gameMode->unk_0C = NULL;

    if (gameMode->init == NULL) {
        gameMode->init = state_delegate_NOP;
    }
    if (gameMode->step == NULL) {
        gameMode->step = state_delegate_NOP;
    }
    if (gameMode->unk_0C == NULL) {
        gameMode->unk_0C = state_delegate_NOP;
    }
    if (gameMode->render == NULL) {
        gameMode->render = state_delegate_NOP;
    }

    gameMode->renderAux = state_delegate_NOP;
    gameMode->init();

    return gameMode;
}

GameMode* set_game_mode_slot(s32 i, GameMode* mode) {
    GameMode* gameMode = &gMainGameState[i];

    ASSERT(i < ARRAY_COUNT(gMainGameState));

    gameMode->flags = 2 | 1;
    gameMode->init = mode->init;
    gameMode->step = mode->step;
    gameMode->render = mode->render;
    gameMode->unk_0C = NULL;
    if (gameMode->init == NULL) gameMode->init = state_delegate_NOP;
    if (gameMode->step == NULL) gameMode->step = state_delegate_NOP;
    if (gameMode->unk_0C == NULL) gameMode->unk_0C = state_delegate_NOP;
    if (gameMode->render == NULL) gameMode->render = state_delegate_NOP;

    gameMode->renderAux = state_delegate_NOP;
    gameMode->init();

    return gameMode;
}

void game_mode_set_fpDrawAuxUI(s32 i, void (*fn)(void)) {
    GameMode* gameMode = &gMainGameState[i];

    ASSERT(i < ARRAY_COUNT(gMainGameState));

    gameMode->renderAux = fn;
    gameMode->flags |= 0x20;

    if (fn == NULL) {
        gameMode->renderAux = state_delegate_NOP;
    }
}

void func_80112DD4(s32 i) {
    gMainGameState[i].flags |= 4;
}

void func_80112DFC(s32 i) {
    gMainGameState[i].flags |= 8;
}

void func_80112E24(s32 i) {
    gMainGameState[i].flags &= ~0x1C;
}

void func_80112E4C(s32 i) {
    gMainGameState[i].flags &= ~0x0C;
    gMainGameState[i].flags |= 0x10;
}

void step_current_game_mode(void) {
    GameMode* gameMode = gMainGameState;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMainGameState); i++, gameMode++) {
        if (gameMode->flags != 0) {
            if (!(gameMode->flags & 4)) {
                if (!(gameMode->flags & 8)) {
                    gameMode->flags &= ~2;
                    gameMode->step();
                }
            }
        }
    }
}

void state_do_unk(void) {
    GameMode* gameMode = gMainGameState;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMainGameState); i++, gameMode++) {
        if (gameMode->flags != 0) {
            if (!(gameMode->flags & 4)) {
                if (!(gameMode->flags & 0x10)) {
                    gameMode->unk_0C();
                }
            }
        }
    }
}

void state_render_backUI(void) {
    GameMode* gameMode = gMainGameState;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMainGameState); i++, gameMode++) {
        if (gameMode->flags != 0) {
            if (!(gameMode->flags & 4)) {
                if (!(gameMode->flags & 0x10)) {
                    gameMode->render();
                }
            }
        }
    }
}

void state_render_frontUI(void) {
    GameMode* gameMode = gMainGameState;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMainGameState); i++, gameMode++) {
        if (gameMode->flags != 0) {
            if (!(gameMode->flags & 4)) {
                if (!(gameMode->flags & 2)) {
                    if (gameMode->flags & 0x20) {
                        gameMode->renderAux();
                    }
                }
            }
        }
    }

    // re-initialization needed - evidence of inlining? or just copy/pasting?
    gameMode = &gMainGameState[0];
    for (i = 0; i < ARRAY_COUNT(gMainGameState); i++, gameMode++) {
        if (gameMode->flags != 0) {
            if (!(gameMode->flags & 4)) {
                if (!(gameMode->flags & 2)) {
                    if (gameMode->flags & 0x10) {
                        gameMode->render();
                    }
                }
            }
        }
    }
}
