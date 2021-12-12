#include "common.h"
#include "filemenu.h"
#include "hud_element.h"

extern SaveMetadata D_800779C4[4];
extern u8 D_80077A24[4];
extern s8* D_80249E20[14];
extern MenuWindowBP D_80249EA0[14];
extern s8 D_8024C098;

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
) {
    s32 msgIdx;
    s32 xOffset;
    s32 yOffset;

    switch (menu->page) {
        case 1:
        case 2:
        case 3:
        case 4:
            msgIdx = 10;
            xOffset = 18;
            yOffset = 0;
            if ((menu->unk_00.s & 0xFFFF00) == 0x010200) {
                filemenu_set_cursor_goal_pos(54, baseX + 8, baseY + 8);
            }
            break;
        default:
            msgIdx = 11;
            xOffset = 14;
            yOffset = 0;
            if ((menu->unk_00.s & 0xFFFF00) == 0x010200) {
                filemenu_set_cursor_goal_pos(54, baseX + 4, baseY + 8);
            }
            break;
    }

    filemenu_draw_message(filemenu_get_menu_message(msgIdx), baseX + xOffset, baseY + yOffset + 2, 255, 0, 1);
}

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

void filemenu_draw_contents_file_title(
    s32 fileIdx,
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening)
{
    if (D_8024C098 == 0 && menu->unk_00.c.selected == fileIdx) {
        filemenu_set_cursor_goal_pos(fileIdx + 60, baseX - 3, baseY + 8);
    }

    filemenu_draw_message(filemenu_get_menu_message(26), baseX + 5, baseY + 1, 255, 0, 1);

    if (D_80077A24[fileIdx] == 0) {
        draw_number(fileIdx + 1, baseX + 33, baseY + 1, 1, 0, 255, 2);
    } else {
        draw_number(fileIdx + 1, baseX + 33, baseY + 1, 1, 0, 255, 2);
        filemenu_draw_file_name(D_800779C4[fileIdx].unk_07, 8, baseX + 46, baseY + 1, 255, 0, 1, 9);
    }
}

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

void filemenu_main_init(MenuPanel* menu) {
    s32 halfWidth;
    s32 halfWidth2;
    s16* posXPtr;
    s32 x;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(filemenu_hudElemIDs); i++) {
        filemenu_hudElemIDs[i] = create_hud_element(D_80249E20[i]);
        set_hud_element_flags(filemenu_hudElemIDs[i], 0x80);
    }

    for (i = 0; i < ARRAY_COUNT(D_80249EA0); i++) {
        D_80249EA0[i].tab = menu;
    }

    setup_pause_menu_tab(D_80249EA0, ARRAY_COUNT(D_80249EA0));
    menu->unk_00.c.selected = menu->gridData[(menu->page * menu->numCols * menu->numRows) +
                                             (menu->numCols * menu->unk_00.c.row) +
                                             menu->unk_00.c.col];

    if (menu->page == 2) {
        gWindows[45].pos.y = 1;
        gWindows[45].width = 211;
        gWindows[45].height = 25;
    } else {
        gWindows[45].pos.y = 1;
        gWindows[45].width = 162;
        gWindows[45].height = 25;
    }

    halfWidth = gWindows[45].width / 2;
    posXPtr = &gWindows[45].pos.x;
    if (gWindows[45].parent != -1) {
        x = (gWindows[gWindows[45].parent].width / 2) - halfWidth;
    } else {
        x = 160 - halfWidth;
    }
    *posXPtr = x;

    halfWidth2 = gWindows[54].width / 2;
    posXPtr = &gWindows[54].pos.x;
    if (gWindows[54].parent != -1) {
        x = (gWindows[gWindows[54].parent].width / 2) - halfWidth2;
    } else {
        x = 160 - halfWidth2;
    }
    *posXPtr = x;

    if (menu->page != 0) {
        set_window_update(0x35, 2);
        set_window_update(0x37, 2);
        set_window_update(0x33, 2);
        set_window_update(0x34, 2);
    }
    menu->unk_00.c.initialized = 1;
}

static const f32 padding[] = { 0.0f }; // TODO remove when the following func is matched

void filemenu_main_handle_input(MenuPanel* menu);
INCLUDE_ASM(s32, "165490", filemenu_main_handle_input);

extern s32 D_8014F150[];

INCLUDE_ASM(s32, "165490", filemenu_main_update);

void filemenu_main_cleanup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(filemenu_hudElemIDs); i++) {
        free_hud_element(filemenu_hudElemIDs[i]);
    }
}
