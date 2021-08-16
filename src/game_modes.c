#include "common.h"

// TODO: decide whether to call these 'game modes' or 'states'

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

StateFunc gameModeBlueprints[] = { NULL, state_init_startup, state_step_startup, NULL, state_drawUI_startup };

StateFunc D_800776FC[] = { NULL, state_init_logos, state_step_logos, NULL, state_drawUI_logos };

StateFunc D_80077710[] = { NULL, state_init_title_screen, state_step_title_screen, NULL, state_drawUI_title_screen };

StateFunc D_80077724[] = { NULL, state_init_enter_demo, state_step_enter_world, NULL, state_drawUI_enter_world };

StateFunc D_80077738[] = { NULL, state_init_change_map, state_step_change_map, NULL, state_drawUI_change_map };

StateFunc D_8007774C[] = { NULL, func_80036430, func_8003646C, NULL, func_80036640 };

StateFunc D_80077760[] = { NULL, state_init_enter_world, state_step_enter_world, NULL, state_drawUI_enter_world };

StateFunc D_80077774[] = { NULL, state_init_world, state_step_world, NULL, state_drawUI_world };

StateFunc D_80077788[] = { NULL, state_init_battle, state_step_battle, NULL, state_drawUI_battle };

StateFunc D_8007779C[] = { NULL, state_init_end_battle, state_step_end_battle, NULL, state_drawUI_end_battle };

StateFunc D_800777B0[] = { NULL, state_init_pause, state_step_pause, NULL, state_drawUI_pause };

StateFunc D_800777C4[] = { NULL, state_init_unpause, state_step_unpause, NULL, state_drawUI_unpause };

StateFunc D_800777D8[] = {
    NULL, state_init_language_select, state_step_language_select, NULL, state_drawUI_language_select
};

StateFunc D_800777EC[] = {
    NULL, state_init_exit_language_select, state_step_exit_language_select, NULL, state_drawUI_exit_language_select
};

StateFunc D_80077800[] = { NULL, state_init_file_select, state_step_file_select, NULL, state_drawUI_file_select };

StateFunc D_80077814[] = {
    NULL, state_init_exit_file_select, state_step_exit_file_select, NULL, state_drawUI_exit_file_select
};

StateFunc D_80077828[] = { NULL, state_init_intro, state_step_intro, NULL, state_drawUI_intro };

StateFunc D_8007783C[] = { NULL, state_init_demo, state_step_demo, NULL, state_drawUI_demo };

StateFunc gameModeMap[] = {
    &gameModeBlueprints, &D_800776FC, &D_80077710, &D_80077724, &D_80077774, &D_80077738, &D_8007774C, &D_80077760,
    &D_80077788, &D_8007779C, &D_800777B0, &D_800777C4, &D_800777D8, &D_800777EC, &D_80077800, &D_80077814, &D_80077828,
    &D_8007783C, NULL, NULL,
};

// BSS
extern s16 gameMode;

void set_game_mode(s16 mode) {
    gameMode = mode;
    set_game_mode_slot(0, gameModeMap[mode]);
}

s16 get_game_mode(void) {
    return gameMode;
}
