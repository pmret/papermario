#include "common.h"
#include "filemenu.h"
#include "hud_element.h"

void filemenu_draw_contents_title(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    s32 msgIdx;
    s32 xOffset;
    s32 yOffset;

    switch (menu->page) {
        case 0:
            msgIdx = 1;
            xOffset = 9;
            yOffset = 4;
            break;
        case 1:
            msgIdx = 2;
            xOffset = 8;
            yOffset = 4;
            break;
        case 3:
            msgIdx = 4;
            xOffset = 25;
            yOffset = 4;
            break;
        case 4:
            msgIdx = 5;
            xOffset = 16;
            yOffset = 4;
            break;
        case 2:
        default:
            msgIdx = 3;
            xOffset = 10;
            yOffset = 4;
            break;
    }

    filemenu_draw_message(filemenu_get_menu_message(msgIdx), baseX + xOffset, baseY + yOffset, 255, 0, 0);
}

void filemenu_draw_contents_stereo(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    if (gGameStatusPtr->unk_AB == 1) {
        set_hud_element_render_pos(filemenu_hudElemIDs[18], baseX + 34, baseY + 10);
        draw_hud_element_3(filemenu_hudElemIDs[18]);
    } else {
        set_hud_element_render_pos(filemenu_hudElemIDs[19], baseX + 34, baseY + 10);
        draw_hud_element_3(filemenu_hudElemIDs[19]);
    }
}

void filemenu_draw_contents_mono(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    if (gGameStatusPtr->unk_AB == 0) {
        set_hud_element_render_pos(filemenu_hudElemIDs[16], baseX + 34, baseY + 10);
        draw_hud_element_3(filemenu_hudElemIDs[16]);
    } else {
        set_hud_element_render_pos(filemenu_hudElemIDs[17], baseX + 34, baseY + 10);
        draw_hud_element_3(filemenu_hudElemIDs[17]);
    }
}

void filemenu_draw_contents_option_left(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    if (menu->page != 2) {
        if ((menu->unk_00.s & 0x00FFFF00) == 0x200) {
            filemenu_set_cursor_goal_pos(53, baseX, baseY + 8);
        }
        filemenu_draw_message(filemenu_get_menu_message(9), baseX + 8, baseY + 2, 255, 0, 1);
    }
}

void filemenu_draw_contents_option_center(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
);
INCLUDE_ASM(s32, "165490", filemenu_draw_contents_option_center);

void filemenu_draw_contents_option_right(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    if (menu->page != 2) {
        if ((menu->unk_00.s & 0xFFFF00) == 0x020200) {
            filemenu_set_cursor_goal_pos(55, baseX + 8, baseY + 8);
        }
        filemenu_draw_message(filemenu_get_menu_message(10), baseX + 20, baseY + 2, 255, 0, 1);
    }
}

INCLUDE_ASM(s32, "165490", filemenu_draw_contents_file_info);

INCLUDE_ASM(s32, "165490", filemenu_draw_contents_file_title);

void filemenu_draw_contents_file_0_info(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_info(0, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_1_info(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_info(1, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_2_info(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_info(2, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_3_info(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_info(3, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_0_title(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_title(0, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_1_title(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_title(1, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_2_title(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_title(2, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_contents_file_3_title(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    filemenu_draw_contents_file_title(3, menu, baseX, baseY, width, height, opacity, darkening);
}

INCLUDE_ASM(s32, "165490", filemenu_main_init);

static const f32 padding[] = { 0.0f }; // TODO remove when the following func is matched

void filemenu_main_handle_input(MenuPanel* menu);
INCLUDE_ASM(s32, "165490", filemenu_main_handle_input);

INCLUDE_ASM(s32, "165490", filemenu_main_update);

void filemenu_main_cleanup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(filemenu_hudElemIDs); i++) {
        free_hud_element(filemenu_hudElemIDs[i]);
    }
}
