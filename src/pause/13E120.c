#include "common.h"

extern s32 D_80270640[];

INCLUDE_ASM(s32, "pause/13E120", pause_partners_load_portrait);

INCLUDE_ASM(s32, "pause/13E120", pause_partners_draw_contents);

INCLUDE_ASM(s32, "pause/13E120", pause_partners_draw_title);

INCLUDE_ASM(s32, "pause/13E120", pause_partners_draw_movelist);

void pause_partners_draw_movelist_title(void* menuTab, s32 x, s32 y) {
    draw_msg(pause_get_menu_msg(0x55), x + 0xC, y + 1, 0xFF, -1, 1);
}

void pause_partners_draw_movelist_flower(void* menuTab, s32 x, s32 y) {
    set_hud_element_render_pos(D_80270640[1], x + 0x11, y + 0x10);
    draw_hud_element_3(D_80270640[1]);
}

INCLUDE_ASM(s32, "pause/13E120", pause_partners_init);

INCLUDE_ASM(s32, "pause/13E120", pause_partners_handle_input);

INCLUDE_ASM(s32, "pause/13E120", pause_partners_update);

INCLUDE_ASM(s32, "pause/13E120", pause_partners_cleanup);
