#include "common.h"
#include "filemenu.h"
#include "hud_element.h"

typedef struct UnkStruct8015A370 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ char unk_01[0x3];
    /* 0x04 */ void (*unk_04)(s32);
    /* 0x08 */ char unk_08[0x14];
    /* 0x1C */ u8 unk_1C;
} UnkStruct8015A370;

extern UnkStruct8015A370 D_8015A370;

extern s32 D_8024C108;
extern MenuWindowBP D_8024A190[2];
extern s8 D_8024C090;
extern s32 D_8024C100_C09980[3];
extern u8 D_8024C117;

u8 D_8024A130[] = {
    0, 0, 0, 0 // TODO find it's length
};

MenuWindowBP D_8024A134[] = {
    {
        .windowID = WINDOW_ID_47,
        .unk_01 = 0,
        .pos = { .x = 0, .y = 0 },
        .width = 0,
        .height = 0,
        .priority = 0x40,
        .fpDrawContents = &filemenu_info_draw_message_contents,
        .tab = NULL,
        .parentID = -1,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { .customStyle = &D_8024BEC0 }
    },
};

MenuPanel D_8024A158 = {
    .initialized = FALSE,
    .col = 0,
    .row = 0,
    .selected = 0,
    .page = 0,
    .numCols = 1,
    .numRows = 1,
    .numPages = 0,
    .gridData = D_8024A130,
    .fpInit = &filemenu_info_init,
    .fpHandleInput = &filemenu_info_handle_input,
    .fpUpdate = &filemenu_info_update,
    .fpCleanup = &filemenu_info_cleanup
};

void filemenu_info_draw_message_contents(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    switch (menu->page) {
        case 0:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_26), baseX + 10, baseY + 4, 255, 0, 0);
            draw_number(filemenu_menus[0]->selected + 1, baseX + 48, baseY + 6, 0, 0, 255, 3);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_HAS_BEEN_DELETED), baseX + 49, baseY + 4, 255, 0, 0);
            break;
        case 2:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_COPY_FROM), baseX + 10, baseY + 4, 255, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_26), baseX + 84, baseY + 4, 255, 0, 0);
            draw_number(filemenu_loadedFileIdx + 1, baseX + 122, baseY + 6, 0, 0, 255, 3);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_TO), baseX + 10, baseY + 18, 255, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_26), baseX + 30, baseY + 18, 255, 0, 0);
            draw_number(filemenu_iterFileIdx + 1, baseX + 68, baseY + 20, 0, 0, 255, 3);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_PERIOD_34), baseX + 65, baseY + 18, 255, 0, 0);
            break;
        case 1:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_28), baseX + 10, baseY + 4, 255, 0, 0);
            break;
        case 3:
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_FILE_26), baseX + 10, baseY + 4, 255, 0, 0);
            draw_number(filemenu_menus[0]->selected + 1, baseX + 48, baseY + 6, 0, 0, 255, 3);
            filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_HAS_BEEN_CREATED), baseX + 49, baseY + 4, 255, 0, 0);
            break;
    }
    filemenu_set_cursor_alpha(0);
}

void filemenu_info_init(MenuPanel* tab) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8024A134); i++) {
        D_8024A134[i].tab = tab;
    }

    setup_pause_menu_tab(D_8024A134, ARRAY_COUNT(D_8024A134));
    tab->initialized = TRUE;
}

void filemenu_info_handle_input(MenuPanel* menu) {
    if (filemenu_pressedButtons & (BUTTON_A | BUTTON_B)) {
        MenuPanel* menu = filemenu_menus[0];

        filemenu_8024C098 = 0;

        switch (menu->page) {
            case 1:
                menu->page = 0;
                set_window_update(WINDOW_ID_51, (s32)filemenu_update_show_options_left);
                set_window_update(WINDOW_ID_52, (s32)filemenu_update_show_options_right);
                set_window_update(WINDOW_ID_53, (s32)filemenu_update_show_options_bottom);
                set_window_update(WINDOW_ID_55, (s32)filemenu_update_show_options_bottom);
                filemenu_set_selected(menu, 0, 2);
                break;
            case 4:
                menu->page = 0;
                set_window_update(WINDOW_ID_51, (s32)filemenu_update_show_options_left);
                set_window_update(WINDOW_ID_52, (s32)filemenu_update_show_options_right);
                set_window_update(WINDOW_ID_53, (s32)filemenu_update_show_options_bottom);
                set_window_update(WINDOW_ID_55, (s32)filemenu_update_show_options_bottom);
                filemenu_set_selected(menu, 1, 2);
                break;
            case 2:
                menu->page = 2;
                filemenu_set_selected(menu, 1, 2);
                break;
        }
        set_window_update(WINDOW_ID_47, WINDOW_UPDATE_HIDE);
    }
}

void filemenu_info_update(MenuPanel* menu) {
}

void filemenu_info_cleanup(MenuPanel* menu) {
}

