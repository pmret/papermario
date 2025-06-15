#include "common.h"
#include "game_modes.h"

BSS GameMode gMainGameMode[2];
BSS s32 D_80151730[4]; // unused? or probably a part of GameMode?

void mode_default_nop(void) {
}

void clear_game_modes(void) {
    GameMode* gameMode;
    s32 i;

    for (gameMode = gMainGameMode, i = 0; i < ARRAY_COUNT(gMainGameMode); i++, gameMode++) {
        gameMode->flags = MODE_FLAG_NONE;
    }
}

// Function is unused.
GameMode* set_next_game_mode(GameMode* mode) {
    GameMode* gameMode;
    s32 i;

    for (gameMode = gMainGameMode, i = 0; i < ARRAY_COUNT(gMainGameMode); i++, gameMode++) {
        if (gameMode->flags == MODE_FLAG_NONE) {
            break;
        }
    }

    ASSERT(i < ARRAY_COUNT(gMainGameMode));

    gameMode->flags = MODE_FLAG_INITIALIZED | MODE_FLAG_STEP_NOT_DONE;
    gameMode->init = mode->init;
    gameMode->step = mode->step;
    gameMode->render = mode->render;
    gameMode->unusedFunc = nullptr;

    if (gameMode->init == nullptr) {
        gameMode->init = mode_default_nop;
    }
    if (gameMode->step == nullptr) {
        gameMode->step = mode_default_nop;
    }
    if (gameMode->unusedFunc == nullptr) {
        gameMode->unusedFunc = mode_default_nop;
    }
    if (gameMode->render == nullptr) {
        gameMode->render = mode_default_nop;
    }

    gameMode->renderAux = mode_default_nop;
    gameMode->init();

    return gameMode;
}

GameMode* set_game_mode_slot(s32 i, GameMode* mode) {
    GameMode* gameMode = &gMainGameMode[i];

    ASSERT(i < ARRAY_COUNT(gMainGameMode));

    gameMode->flags = MODE_FLAG_INITIALIZED | MODE_FLAG_STEP_NOT_DONE;
    gameMode->init = mode->init;
    gameMode->step = mode->step;
    gameMode->render = mode->render;
    gameMode->unusedFunc = nullptr;
    if (gameMode->init == nullptr) gameMode->init = mode_default_nop;
    if (gameMode->step == nullptr) gameMode->step = mode_default_nop;
    if (gameMode->unusedFunc == nullptr) gameMode->unusedFunc = mode_default_nop;
    if (gameMode->render == nullptr) gameMode->render = mode_default_nop;

    gameMode->renderAux = mode_default_nop;
    gameMode->init();

    return gameMode;
}

void game_mode_set_fpDrawAuxUI(s32 i, void (*fn)(void)) {
    GameMode* gameMode = &gMainGameMode[i];

    ASSERT(i < ARRAY_COUNT(gMainGameMode));

    gameMode->renderAux = fn;
    gameMode->flags |= MODE_FLAG_RENDER_AUX_SET;

    if (fn == nullptr) {
        gameMode->renderAux = mode_default_nop;
    }
}

// Unused
void set_game_mode_flag_4(s32 i) {
    gMainGameMode[i].flags |= MODE_FLAG_4;
}

// Unused
void set_game_mode_flag_8(s32 i) {
    gMainGameMode[i].flags |= MODE_FLAG_8;
}

// Unused
void clear_game_mode_unk_flags(s32 i) {
    gMainGameMode[i].flags &= ~(MODE_FLAG_4 | MODE_FLAG_8 | MODE_FLAG_10);
}

// Unused
void set_game_mode_flag_10(s32 i) {
    gMainGameMode[i].flags &= ~(MODE_FLAG_4 | MODE_FLAG_8);
    gMainGameMode[i].flags |= MODE_FLAG_10;
}

void step_current_game_mode(void) {
    GameMode* gameMode = gMainGameMode;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMainGameMode); i++, gameMode++) {
        if (gameMode->flags != MODE_FLAG_NONE) {
            if (!(gameMode->flags & MODE_FLAG_4)) {
                if (!(gameMode->flags & MODE_FLAG_8)) {
                    gameMode->flags &= ~MODE_FLAG_STEP_NOT_DONE;
                    gameMode->step();
                }
            }
        }
    }
}

// Unused
void state_do_unk(void) {
    GameMode* gameMode = gMainGameMode;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMainGameMode); i++, gameMode++) {
        if (gameMode->flags != MODE_FLAG_NONE) {
            if (!(gameMode->flags & MODE_FLAG_4)) {
                if (!(gameMode->flags & MODE_FLAG_10)) {
                    gameMode->unusedFunc();
                }
            }
        }
    }
}

void state_render_backUI(void) {
    GameMode* gameMode = gMainGameMode;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMainGameMode); i++, gameMode++) {
        if (gameMode->flags != MODE_FLAG_NONE) {
            if (!(gameMode->flags & MODE_FLAG_4)) {
                if (!(gameMode->flags & MODE_FLAG_10)) {
                    gameMode->render();
                }
            }
        }
    }
}

void state_render_frontUI(void) {
    GameMode* gameMode = gMainGameMode;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gMainGameMode); i++, gameMode++) {
        if (gameMode->flags != MODE_FLAG_NONE) {
            if (!(gameMode->flags & MODE_FLAG_4)) {
                if (!(gameMode->flags & MODE_FLAG_STEP_NOT_DONE)) {
                    if (gameMode->flags & MODE_FLAG_RENDER_AUX_SET) {
                        gameMode->renderAux();
                    }
                }
            }
        }
    }

    // re-initialization needed - evidence of inlining? or just copy/pasting?
    gameMode = &gMainGameMode[0];
    for (i = 0; i < ARRAY_COUNT(gMainGameMode); i++, gameMode++) {
        if (gameMode->flags != MODE_FLAG_NONE) {
            if (!(gameMode->flags & MODE_FLAG_4)) {
                if (!(gameMode->flags & MODE_FLAG_STEP_NOT_DONE)) {
                    if (gameMode->flags & MODE_FLAG_10) {
                        gameMode->render();
                    }
                }
            }
        }
    }
}
