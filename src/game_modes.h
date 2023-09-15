#ifndef _GAME_MODES_H_
#define _GAME_MODES_H_

#include "common.h"

// These flags are mostly unused. Not enough context to discern their original purpose.
enum GameModeFlags {
    MODE_FLAG_NONE           = 0,
    MODE_FLAG_INITIALIZED    = (1 << 0), // Set when the mod is initialized
    MODE_FLAG_STEP_NOT_DONE  = (1 << 1), // Turned off after the first step is done
    MODE_FLAG_4              = (1 << 2),
    MODE_FLAG_8              = (1 << 3),
    MODE_FLAG_10             = (1 << 4),
    MODE_FLAG_RENDER_AUX_SET = (1 << 5), // Set when the renderAux function is set
};

enum GameModeIDs {
    GAME_MODE_STARTUP             = 0,
    GAME_MODE_LOGOS               = 1,
    GAME_MODE_TITLE_SCREEN        = 2,
    GAME_MODE_ENTER_DEMO_WORLD    = 3,
    GAME_MODE_WORLD               = 4,
    GAME_MODE_CHANGE_MAP          = 5,
    GAME_MODE_GAME_OVER           = 6,
    GAME_MODE_ENTER_WORLD         = 7,
    GAME_MODE_BATTLE              = 8,
    GAME_MODE_END_BATTLE          = 9,
    GAME_MODE_PAUSE               = 10,
    GAME_MODE_UNPAUSE             = 11,
    GAME_MODE_LANGUAGE_SELECT     = 12,
    GAME_MODE_END_LANGUAGE_SELECT = 13,
    GAME_MODE_FILE_SELECT         = 14,
    GAME_MODE_END_FILE_SELECT     = 15,
    GAME_MODE_INTRO               = 16,
    GAME_MODE_DEMO                = 17,
};

typedef struct GameMode {
    /* 0x00 */ u16 flags;
    /* 0x04 */ void (*init)(void);
    /* 0x08 */ void (*step)(void);
    /* 0x0C */ UNK_FUN_PTR(unusedFunc);
    /* 0x10 */ void (*render)(void);
    /* 0x14 */ void (*renderAux)(void); ///< @see state_render_frontUI
} GameMode; // size = 0x18

void set_game_mode(s16 mode);
void clear_game_modes(void);
GameMode* set_game_mode_slot(s32 i, GameMode* mode);
void game_mode_set_fpDrawAuxUI(s32 i, void (*fn)(void));
void step_current_game_mode(void);
void state_render_backUI(void);
void state_render_frontUI(void);

#endif
