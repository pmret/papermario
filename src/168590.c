#include "common.h"
#include "filemenu.h"
#include "hud_element.h"

extern MenuWindowBP D_8024A134[1];

extern s32 filemenu_iterFileIdx;
extern s32 filemenu_pressedButtons;
extern s8 D_8024C090;
extern s32 filemenu_loadedFileIdx;
extern s8 D_8024C098_C09918;
extern s32 D_8024C100_C09980[3];
extern s32 D_8024C110;

s32 filemenu_get_menu_message(s32 index);
void filemenu_update_show_options_left(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX,
                                       s32* scaleY, s32* rotX, s32* rotY, s32* rotZ, s32* darkening, s32* opacity);
void filemenu_update_show_options_right(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX,
                                       s32* scaleY, s32* rotX, s32* rotY, s32* rotZ, s32* darkening, s32* opacity);
void filemenu_update_show_options_bottom(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX,
                                       s32* scaleY, s32* rotX, s32* rotY, s32* rotZ, s32* darkening, s32* opacity);

void filemenu_info_draw_message_contents(MenuPanel* menu, s32 baseX, s32 baseY) {
    s8 page = menu->page;

    switch (page) {
        case 0:
            filemenu_draw_message(filemenu_get_menu_message(0x1A), baseX + 10, baseY + 4, 255, 0, 0);
            draw_number(filemenu_menus[0]->selected + 1, baseX + 48, baseY + 6, 0, 0, 255, 3);
            filemenu_draw_message(filemenu_get_menu_message(0x1B), baseX + 49, baseY + 4, 255, 0, 0);
            break;
        case 2:
            filemenu_draw_message(filemenu_get_menu_message(0x1D), baseX + 10, baseY + 4, 255, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(0x1A), baseX + 84, baseY + 4, 255, 0, 0);
            draw_number(filemenu_loadedFileIdx + 1, baseX + 122, baseY + 6, 0, 0, 255, 3);
            filemenu_draw_message(filemenu_get_menu_message(0x1E), baseX + 10, baseY + 18, 255, 0, 0);
            filemenu_draw_message(filemenu_get_menu_message(0x1A), baseX + 30, baseY + 18, 255, 0, 0);
            draw_number(filemenu_iterFileIdx + 1, baseX + 68, baseY + 20, 0, 0, 255, 3);
            filemenu_draw_message(filemenu_get_menu_message(0x22), baseX + 65, baseY + 18, 255, 0, 0);
            break;
        case 1:
            filemenu_draw_message(filemenu_get_menu_message(0x1C), baseX + 10, baseY + 4, 255, 0, 0);
            break;
        case 3:
            filemenu_draw_message(filemenu_get_menu_message(0x1A), baseX + 10, baseY + 4, 255, 0, 0);
            draw_number(filemenu_menus[0]->selected + 1, baseX + 48, baseY + 6, 0, 0, 255, page);
            filemenu_draw_message(filemenu_get_menu_message(0x1F), baseX + 49, baseY + 4, 255, 0, 0);
            break;
    }
    filemenu_set_cursor_alpha(0);
}

void filemenu_info_init(s8* tab) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8024A134); i++) {
        D_8024A134[i].tab = tab;
    }

    setup_pause_menu_tab(D_8024A134, 1);
    *tab = 1;
}

void filemenu_info_handle_input(void) {
    if (filemenu_pressedButtons & (BUTTON_A | BUTTON_B)) {
        MenuPanel* menu = filemenu_menus[0];
        s32 page;

        D_8024C098_C09918 = 0;
        page = menu->page;

        switch(page) {
            case 1:
                menu->page = 0;
                set_window_update(0x33, filemenu_update_show_options_left);
                set_window_update(0x34, filemenu_update_show_options_right);
                set_window_update(0x35, filemenu_update_show_options_bottom);
                set_window_update(0x37, filemenu_update_show_options_bottom);
                filemenu_set_selected(menu, 0, 2);
                break;
            case 4:
                menu->page = 0;
                set_window_update(0x33, filemenu_update_show_options_left);
                set_window_update(0x34, filemenu_update_show_options_right);
                set_window_update(0x35, filemenu_update_show_options_bottom);
                set_window_update(0x37, filemenu_update_show_options_bottom);
                filemenu_set_selected(menu, 1, 2);
                break;
            case 2:
                menu->page = page;
                filemenu_set_selected(menu, 1, 2);
                break;
        }
        set_window_update(0x2F, 2);
    }
}

void filemenu_info_update(void) {
}

void filemenu_info_cleanup(void) {
}

void func_80248170(s32 idx) {
    Window* window = &gWindows[idx];

    if (window->updateCounter == 8) {
        window->flags &= ~WINDOW_FLAGS_8;
        set_window_update(idx, 1);
    }
}

void filemenu_draw_contents_file_create_header(MenuPanel* menu, s32 baseX, s32 baseY) {
    s32 xOffset;
    s32 yOffset;
    s32 i;
    s32 tempAmt;

    filemenu_draw_message(filemenu_get_menu_message(0x20), baseX + 10, baseY + 6, 255, 0, 0);
    filemenu_draw_file_name(&D_8024C110, 8, baseX + 36, baseY + 22, 255, 0, 0, 0xB);
    xOffset = 41;

    for (i = 0; i < 8; i++) {
        set_hud_element_render_pos(D_8024C100_C09980[1], baseX + 42 + (i * 11), baseY + xOffset);
        if (i == 0) {
            draw_hud_element_3(D_8024C100_C09980[1]);
        } else {
            draw_hud_element_2(D_8024C100_C09980[1]);
        }
    }

    tempAmt = 8;
    if (D_8024C098_C09918 == 3) {
        s32 phi_v0 = 122;

        if (D_8024C090 != tempAmt) {
            phi_v0 = (D_8024C090 * 0xB) + 45;
        }
        set_hud_element_render_pos(D_8024C100_C09980[0], baseX + phi_v0, baseY + 45);
        draw_hud_element_2(D_8024C100_C09980[0]);
    }
}

INCLUDE_ASM(s32, "168590", filemenu_draw_contents_choose_name);

INCLUDE_ASM(s32, "168590", filemenu_choose_name_init);

INCLUDE_ASM(s32, "168590", filemenu_choose_name_handle_input);

void filemenu_choose_name_update(void) {
}

void filemenu_choose_name_cleanup(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8024C100_C09980); i++) {
        free_hud_element(D_8024C100_C09980[i]);
    }
}
