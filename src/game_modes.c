#include "game_modes.h"

s32 D_80077420[] = {
    0x000000E4, 0x000000E1, 0x000000EB, 0x000000EF, 0x000000F6, 0x0000010A, 0x0000010C, 0x00000121, 0x00000122,
    0x00000123, 0x00000118, 0x0000010E, 0x00000131, 0x0000012E, 0x0000012F, 0x000000E0, 0x000000EE, 0x000000F0,
    0x00000109, 0x0000010B, 0x00000107, 0x000000E8, 0x00000117, 0x00000108, 0x00000124, 0x00000125, 0x00000126,
    0x0000010F, 0x0000012B, 0x0000012C, 0x000000E9, 0x00000106, 0x00000143, 0x000000ED, 0x00000129, 0x0000012A,
    0x000000E7, 0x000000F8, 0x000000FF, 0x00000140, 0x00000105, 0x00000110, 0x00000119, 0x000000E3, 0x00000116,
    0x00000113, 0x000000F4, 0x000000E2, 0x000000F5, 0x00000115, 0x00000101, 0x00000102, 0x0000012D, 0x00000111,
    0x0000010D, 0x00000112, 0x000000F9, 0x00000130, 0x000000FB, 0x000000FA, 0x000000EC, 0x000000E5, 0x00000150,
    0x000000F2, 0x00000100, 0x000000F1, 0x00000114, 0x000000F7, 0x000000F3, 0x00000145, 0x00000146, 0x00000147,
    0x00000148, 0x00000149, 0x00000104, 0x000000FC, 0x00000103, 0x0000011A, 0x0000011B, 0x000000FD, 0x00000144,
    0x0000011E, 0x000000FE, 0x0000011F, 0x0000011D, 0x0000011C, 0x000000E6, 0x00000120, 0x00000080, 0x00000081,
    0x00000082, 0x00000084, 0x00000083, 0x00000086, 0x00000085, 0x00000088, 0x0000008B, 0x0000008A, 0x0000008C,
    0x0000008E, 0x00000095, 0x0000008D, 0x00000089, 0x0000009B, 0x0000009E, 0x0000009F, 0x000000A0, 0x000000A1,
    0x0000009D, 0x0000009C, 0x000000A4, 0x000000A3, 0x000000A2, 0x00000093, 0x00000094, 0x000000A5, 0x000000A6,
    0x000000A7, 0x000000A8, 0x000000A9, 0x000000AA, 0x000000AB, 0x000000AC, 0x000000AD, 0x000000AE, 0x000000AF,
    0x0000008F, 0x00000090, 0x00000091, 0x00000092, 0x0000009A, 0x00000098, 0x00000096, 0x00000097, 0x00000087,
    0x000000B0, 0x000000B1, 0x000000B2, 0x000000B3, 0x000000B4, 0x000000B5, 0x000000B6, 0x000000B9, 0x000000B8,
    0x000000B7, 0x000000BA, 0x000000BD, 0x000000BB, 0x000000BE, 0x000000BF, 0x000000BC, 0x000000C0, 0x000000C1,
    0x000000C2, 0x000000C3, 0x000000C4, 0x000000C5, 0x000000C6, 0x000000C7, 0x000000C8, 0x000000C9, 0x000000CA,
    0x000000CB, 0x000000CC, 0x000000CD, 0x000000CE, 0x000000CF, 0x000000D0, 0x000000D1, 0x000000D2, 0x000000D3,
    0x000000D4, 0x000000D5, 0x000000D6, 0x000000D7, 0x000000D8, 0x000000D9, 0x000000DA,
};

// These GameModeIncomplete are used as the struct GameMode. As GameModeIncomplete is 0x14 long and GameMode is 0x18 long, the last element
// and first element of the next struct are shared in data.

typedef struct GameModeIncomplete {
    /* 0x00 */ u16 flags;
    /* 0x04 */ void (*init)(void);
    /* 0x08 */ void (*step)(void);
    /* 0x0C */ UNK_FUN_PTR(unusedFunc);
    /* 0x10 */ void (*render)(void);
    #ifdef AVOID_UB
    /* 0x14 */ void (*renderAux)(void); ///< @see state_render_frontUI
    #endif
} GameModeIncomplete; // size = 0x14

GameModeIncomplete GameModeStartup = {
    MODE_FLAG_NONE,
    state_init_startup,
    state_step_startup,
    NULL,
    state_drawUI_startup,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModeLogos = {
    MODE_FLAG_NONE,
    state_init_logos,
    state_step_logos,
    NULL,
    state_drawUI_logos,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModeTitleScreen = {
    MODE_FLAG_NONE,
    state_init_title_screen,
    state_step_title_screen,
    NULL,
    state_drawUI_title_screen,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModeEnterDemoWorld = {
    MODE_FLAG_NONE,
    state_init_enter_demo,
    state_step_enter_world,
    NULL,
    state_drawUI_enter_world,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModeChangeMap = {
    MODE_FLAG_NONE,
    state_init_change_map,
    state_step_change_map,
    NULL,
    state_drawUI_change_map,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModeGameOver = {
    MODE_FLAG_NONE,
    state_init_game_over,
    state_step_game_over,
    NULL,
    state_drawUI_game_over,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModeEnterWorld = {
    MODE_FLAG_NONE,
    state_init_enter_world,
    state_step_enter_world,
    NULL,
    state_drawUI_enter_world,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModeWorld = {
    MODE_FLAG_NONE,
    state_init_world,
    state_step_world,
    NULL,
    state_drawUI_world,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModeBattle = {
    MODE_FLAG_NONE,
    state_init_battle,
    state_step_battle,
    NULL,
    state_drawUI_battle,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModeEndBattle = {
    MODE_FLAG_NONE,
    state_init_end_battle,
    state_step_end_battle,
    NULL,
    state_drawUI_end_battle,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModePause = {
    MODE_FLAG_NONE,
    state_init_pause,
    state_step_pause,
    NULL,
    state_drawUI_pause,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModeUnpause = {
    MODE_FLAG_NONE,
    state_init_unpause,
    state_step_unpause,
    NULL,
    state_drawUI_unpause,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModeLanguageSelect = {
    MODE_FLAG_NONE,
    state_init_language_select,
    state_step_language_select,
    NULL,
    state_drawUI_language_select,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModeEndLanguageSelect = {
    MODE_FLAG_NONE,
    state_init_exit_language_select,
    state_step_exit_language_select,
    NULL,
    state_drawUI_exit_language_select,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModeFileSelect = {
    MODE_FLAG_NONE,
    state_init_file_select,
    state_step_file_select,
    NULL,
    state_drawUI_file_select,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModeEndFileSelect = {
    MODE_FLAG_NONE,
    state_init_exit_file_select,
    state_step_exit_file_select,
    NULL,
    state_drawUI_exit_file_select,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModeIntro = {
    MODE_FLAG_NONE,
    state_init_intro,
    state_step_intro,
    NULL,
    state_drawUI_intro,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameModeIncomplete GameModeDemo = {
    MODE_FLAG_NONE,
    state_init_demo,
    state_step_demo,
    NULL,
    state_drawUI_demo,
    #ifdef AVOID_UB
    NULL,
    #endif
};

GameMode* gameModeMap[] = {
    [GAME_MODE_STARTUP]             (GameMode*) &GameModeStartup,
    [GAME_MODE_LOGOS]               (GameMode*) &GameModeLogos,
    [GAME_MODE_TITLE_SCREEN]        (GameMode*) &GameModeTitleScreen,
    [GAME_MODE_ENTER_DEMO_WORLD]    (GameMode*) &GameModeEnterDemoWorld,
    [GAME_MODE_WORLD]               (GameMode*) &GameModeWorld,
    [GAME_MODE_CHANGE_MAP]          (GameMode*) &GameModeChangeMap,
    [GAME_MODE_GAME_OVER]           (GameMode*) &GameModeGameOver,
    [GAME_MODE_ENTER_WORLD]         (GameMode*) &GameModeEnterWorld,
    [GAME_MODE_BATTLE]              (GameMode*) &GameModeBattle,
    [GAME_MODE_END_BATTLE]          (GameMode*) &GameModeEndBattle,
    [GAME_MODE_PAUSE]               (GameMode*) &GameModePause,
    [GAME_MODE_UNPAUSE]             (GameMode*) &GameModeUnpause,
    [GAME_MODE_LANGUAGE_SELECT]     (GameMode*) &GameModeLanguageSelect,
    [GAME_MODE_END_LANGUAGE_SELECT] (GameMode*) &GameModeEndLanguageSelect,
    [GAME_MODE_FILE_SELECT]         (GameMode*) &GameModeFileSelect,
    [GAME_MODE_END_FILE_SELECT]     (GameMode*) &GameModeEndFileSelect,
    [GAME_MODE_INTRO]               (GameMode*) &GameModeIntro,
    [GAME_MODE_DEMO]                (GameMode*) &GameModeDemo,
};

SHIFT_BSS s16 CurGameMode;

void set_game_mode(s16 mode) {
    CurGameMode = mode;
    set_game_mode_slot(0, gameModeMap[mode]);
}

s16 get_game_mode(void) {
    return CurGameMode;
}
