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

extern HudScript HES_FilenameCaret;
extern HudScript HES_FilenameSpace;
extern HudScript HES_134F60_135120;

HudScript* D_8024A180[] = {
    &HES_FilenameCaret, &HES_FilenameSpace, &HES_134F60_135120
};

s32 D_8024A18C = -4;

MenuWindowBP D_8024A190[] = {
    {
        .windowID = WINDOW_ID_48,
        .unk_01 = 0,
        .pos = { .x = 68, .y = 10 },
        .width = 164,
        .height = 46,
        .priority = 0x40,
        .fpDrawContents = &filemenu_draw_contents_file_create_header,
        .tab = NULL,
        .parentID = WINDOW_ID_PAUSE_CURSOR,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { .customStyle = &D_8024BEF8 }
    },
    {
        .windowID = WINDOW_ID_49,
        .unk_01 = 0,
        .pos = { .x = 12, .y = 67 },
        .width = 262,
        .height = 113,
        .priority = 0x40,
        .fpDrawContents = &filemenu_draw_contents_choose_name,
        .tab = NULL,
        .parentID = WINDOW_ID_PAUSE_CURSOR,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { .customStyle = &D_8024BF30 }
    },
};

extern u8 D_8024B978[]; // TODO

MenuPanel D_8024A1D8 = {
    .initialized = FALSE,
    .col = 0,
    .row = 0,
    .selected = 0,
    .page = 0,
    .numCols = 13,
    .numRows = 6,
    .numPages = 0,
    .gridData = D_8024B978,
    .fpInit = &filemenu_choose_name_init,
    .fpHandleInput = &filemenu_choose_name_handle_input,
    .fpUpdate = &filemenu_choose_name_update,
    .fpCleanup = &filemenu_choose_name_cleanup
};

void func_80248170(s32 idx) {
    Window* window = &gWindows[idx];

    if (window->updateCounter == 8) {
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
        set_window_update(idx, WINDOW_UPDATE_SHOW);
    }
}

void filemenu_draw_contents_file_create_header(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    s32 xOffset;
    s32 yOffset;
    s32 i;
    s32 tempAmt;

    filemenu_draw_message(filemenu_get_menu_message(FILE_MESSAGE_ENTER_A_FILE_NAME), baseX + 10, baseY + 6, 255, 0, 0);
    filemenu_draw_file_name(filemenu_8024C110, 8, baseX + 36, baseY + 22, 255, 0, 0, 11);
    xOffset = 41;

    for (i = 0; i < 8; i++) {
        hud_element_set_render_pos(D_8024C100_C09980[1], baseX + 42 + (i * 11), baseY + xOffset);
        if (i == 0) {
            hud_element_draw_without_clipping(D_8024C100_C09980[1]);
        } else {
            hud_element_draw_next(D_8024C100_C09980[1]);
        }
    }

    tempAmt = 8;
    if (filemenu_8024C098 == 3) {
        s32 phi_v0 = 122;

        if (D_8024C090 != tempAmt) {
            phi_v0 = (D_8024C090 * 11) + 45;
        }
        hud_element_set_render_pos(D_8024C100_C09980[0], baseX + phi_v0, baseY + 45);
        hud_element_draw_next(D_8024C100_C09980[0]);
    }
}

void filemenu_draw_contents_choose_name(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
) {
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;

    s32 s6;
    s32 s2;
    s32 s4;
    s32 s7;
    s32 s3;
    s32 t0;
    s32 v1;
    s32 s5;
    s32 s0;
    s32 s1;
    Window* window = &gWindows[49];

    if ((window->flags & WINDOW_FLAGS_INITIAL_ANIMATION) && window->fpUpdate.func == func_80248170) {
        sp18 = window->updateCounter * 2;
        sp1C = menu->page;
        sp20 = menu->page != 1;
        if (sp18 > 0x10) {
            sp18 = 0x10;
        }

        for (s6 = 0; s6 < menu->numRows; s6++) {
            for (t0 = 0; t0 < 2; t0++) {
                s2 = 15 * s6 + 4;
                if (t0 == 0) {
                    sp24 = sp1C;
                    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE,
                                  baseX,
                                  baseY + s2,
                                  baseX + width,
                                  baseY + s2 + sp18);
                } else {
                    sp24 = sp20;
                    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE,
                                  baseX,
                                  baseY + s2 + sp18,
                                  baseX + width,
                                  baseY + s2 + 0x10);
                }

                for (s4 = 0; s4 < menu->numCols; s4++) {
                    s3 = menu->gridData[sp24 * menu->numCols * menu->numRows + menu->numCols * s6 + s4];
                    if (s3 != 0xF7) {
                        if (s4 == menu->col && s6 == menu->row) {
                            v1 = 8;
                            s5 = 0;
                        } else {
                            v1 = 0;
                            s5 = 10;
                        }
                        s0 = 19 * s4 + 12;
                        s2 = 17 * s6 + 5;
                        s1 = s3;
                        if (s3 >= 0xA2 && s3 < 0xF0) {
                            if (s3 >= 0xC6) {
                                hud_element_set_render_pos(D_8024C108, baseX + s0 + 22, baseY + s2 + 8);
                                hud_element_draw_without_clipping(D_8024C108);
                                v1 = 0;
                            }
                        }
                        if (s1 == 0xC6) {
                            s0 -= 1;
                        }
                        if (s1 == 0xC9) {
                            s0 += 5;
                        }
                        if (s1 == 0xCA) {
                            s0 += 8;
                        }
                        if (s1 == 0xC6 || s1 == 0xCA || s1 == 0xC9) {
                            s2 -= 1;
                        }
                        filemenu_draw_message(s3, baseX + s0, baseY + s2, 255, s5, v1);
                    }
                }
            }
        }
        gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, baseX, baseY, baseX + width, baseY + height);
    } else {
        for (s4 = 0; s4 < menu->numCols; s4++) {
            for (s6 = 0; s6 < menu->numRows; s6++) {
                s3 = menu->gridData[menu->page * menu->numCols * menu->numRows + menu->numCols * s6 + s4];
                if (s3 != 0xF7) {
                    if (s4 == menu->col && s6 == menu->row) {
                        v1 = 8;
                        s5 = 0;
                    } else {
                        v1 = 0;
                        s5 = 10;
                    }
                    s0 = s4 * 19 + 12;
                    s2 = s6 * 17 + 5;
                    s1 = s3;
                    if (s3 >= 0xA2 && s3 < 0xF0) {
                        if (s3 >= 0xC6) {
                            hud_element_set_render_pos(D_8024C108, baseX + s0 + 22, baseY + s2 + 8);
                            hud_element_draw_without_clipping(D_8024C108);
                            v1 = 0;
                        }
                    }
                    if (s1 == 0xC6) {
                        s0 -= 1;
                    }
                    if (s1 == 0xC9) {
                        s0 += 5;
                    }
                    if (s1 == 0xCA) {
                        s0 += 8;
                    }
                    if (s1 == 0xC6 || s1 == 0xCA || s1 == 0xC9) {
                        s2 -= 1;
                    }
                    filemenu_draw_message(s3, baseX + s0, baseY + s2, 255, s5, v1);
                }
            }
        }
    }

    if (filemenu_8024C098 == 3) {
        if (filemenu_heldButtons & (BUTTON_STICK_RIGHT | BUTTON_STICK_LEFT | BUTTON_STICK_DOWN | BUTTON_STICK_UP)) {
            D_8024A18C = -4;
        }
        D_8024A18C += 1;
        filemenu_set_cursor_goal_pos(49, baseX + 2 + menu->col * 19, baseY + 13 + menu->row * 17);
    }
}

void filemenu_choose_name_init(MenuPanel* menu) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8024A180); i++) {
        D_8024C100_C09980[i] = hud_element_create(D_8024A180[i]);
        hud_element_set_flags(D_8024C100_C09980[i], HUD_ELEMENT_FLAGS_80);
    }

    for (i = 0; i < ARRAY_COUNT(D_8024A190); i++) {
        D_8024A190[i].tab = menu;
    }

    setup_pause_menu_tab(D_8024A190, 2);

    gWindows[48].pos.x = ((gWindows[48].parent != -1)
                        ? (gWindows[gWindows[48].parent].width / 2)
                        : SCREEN_WIDTH / 2) - gWindows[48].width / 2;

    gWindows[49].pos.x = ((gWindows[49].parent != -1)
                        ? (gWindows[gWindows[49].parent].width / 2)
                        : SCREEN_WIDTH / 2) - gWindows[49].width / 2;

    menu->initialized = TRUE;
}

void filemenu_choose_name_handle_input(MenuPanel* menu) {
    s32 oldSelected = menu->selected;
    MenuPanel* newMenu;
    MenuPanel* newMenu2;
    s32 temp;
    s32 i;

    if (filemenu_heldButtons & BUTTON_STICK_LEFT) {
        menu->col--;
        if (menu->col < 0) {
            menu->col = menu->numCols - 1;
        }
    } else if (filemenu_heldButtons & BUTTON_STICK_RIGHT) {
        menu->col++;
        if (menu->col >= menu->numCols) {
            menu->col = 0;
        }
        if (menu->row == menu->numRows - 1) {
            if (menu->col > 10) {
                menu->col = 0;
            } else if (menu->col == 8 || menu->col == 9) {
                menu->col = 10;
            } else if (menu->col == 5 || menu->col == 6) {
                menu->col = 7;
            }
        }
    }

    if (filemenu_heldButtons & BUTTON_STICK_UP) {
        menu->row--;
        if (menu->row < 0) {
            menu->row = menu->numRows - 1;
        }
    } else if (filemenu_heldButtons & BUTTON_STICK_DOWN) {
        menu->row++;
        if (menu->row >= menu->numRows) {
            menu->row = 0;
        }
    }

    if (menu->row == menu->numRows - 1) {
        if (menu->col > 10) {
            menu->col = 10;
        } else if (menu->col == 8 || menu->col == 9) {
            menu->col = 7;
        } else if (menu->col == 5 || menu->col == 6) {
            menu->col = 4;
        }
    }

    menu->selected = MENU_PANEL_SELECTED_GRID_DATA(menu);
    if (oldSelected != menu->selected) {
        sfx_play_sound(SOUND_2102);
    }

    if (filemenu_pressedButtons & BUTTON_A) {
        switch (menu->selected) {
            case 0xC6:
                sfx_play_sound(SOUND_2103);
                if (D_8024C090 == ARRAY_COUNT(filemenu_8024C110)) {
                    D_8024C090 = ARRAY_COUNT(filemenu_8024C110) - 1;
                }
                filemenu_8024C110[D_8024C090] = 0xF7;
                D_8024C090++;
                if (D_8024C090 > ARRAY_COUNT(filemenu_8024C110)) {
                    D_8024C090 = ARRAY_COUNT(filemenu_8024C110);
                }
                break;
            case 0xC9:
                break;
            case 0xC7:
                if (menu->page != 1) {
                    sfx_play_sound(SOUND_2105);
                    menu->page = 1;
                    filemenu_set_selected(menu, menu->col, menu->row);
                    set_window_update(WINDOW_ID_49, (s32)func_80248170);
                }
                break;
            case 0xC8:
                if (menu->page != 0) {
                    sfx_play_sound(SOUND_2105);
                    menu->page = 0;
                    filemenu_set_selected(menu, menu->col, menu->row);
                    set_window_update(WINDOW_ID_49, (s32)func_80248170);
                }
                break;
            case 0xCA:
                for (i = 0; i < ARRAY_COUNT(filemenu_8024C110); i++) {
                    if (filemenu_8024C110[i] != 0xF7) {
                        break;
                    }
                }
                if (i == ARRAY_COUNT(filemenu_8024C110)) {
                    sfx_play_sound(SOUND_MENU_ERROR);
                    break;
                }

                sfx_play_sound(SOUND_MENU_NEXT);
                set_window_update(WINDOW_ID_50, (s32) filemenu_update_show_name_confirm);
                gWindows[50].pos.y = 121;
                gWindows[50].width = 69;
                gWindows[50].height = 44;
                gWindows[50].pos.x = ((gWindows[50].parent != -1)
                                    ? (gWindows[gWindows[50].parent].width / 2)
                                    : SCREEN_WIDTH / 2) - gWindows[50].width / 2;

                gWindows[46].pos.y = -70;
                gWindows[46].width = 164;
                gWindows[46].height = 62;
                gWindows[46].pos.x = ((gWindows[46].parent != -1)
                                    ? (gWindows[gWindows[46].parent].width / 2)
                                    : SCREEN_WIDTH / 2) - gWindows[46].width / 2;

                filemenu_8024C098 = 1;
                newMenu = filemenu_menus[filemenu_8024C098];
                newMenu->page = 2;
                filemenu_set_selected(newMenu, 0, 0);
                return;
            default:
                sfx_play_sound(SOUND_2103);
                if (D_8024C090 == ARRAY_COUNT(filemenu_8024C110)) {
                    D_8024C117 = menu->selected;
                } else {
                    filemenu_8024C110[D_8024C090] = menu->selected;
                    D_8024C090++;
                    if (D_8024C090 > ARRAY_COUNT(filemenu_8024C110)) {
                        D_8024C090 = ARRAY_COUNT(filemenu_8024C110);
                    }
                }
                break;
        }

        if (((u8)(menu->selected + 0x39) >= 3) && (D_8024C090 == ARRAY_COUNT(filemenu_8024C110))) { // todo ???
            filemenu_set_selected(menu, menu->numCols - 3, menu->numRows - 1);
        }
    }


    if ((filemenu_pressedButtons & BUTTON_B) || ((filemenu_pressedButtons & BUTTON_A) && (menu->selected == 0xC9))) {
        sfx_play_sound(SOUND_2104);
        D_8024C090--;
        if (D_8024C090 < 0) {
            D_8024C090 = 0;
            set_window_update(WINDOW_ID_48, (s32) &filemenu_update_hidden_name_input);
            set_window_update(WINDOW_ID_49, (s32) &filemenu_update_hidden_name_input);
            set_window_update(WINDOW_ID_45, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_51, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_52, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_53, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_54, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_55, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_53, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_56, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_57, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_58, (s32) &filemenu_update_show_with_rotation);
            set_window_update(WINDOW_ID_59, (s32) &filemenu_update_show_with_rotation);
            filemenu_8024C098 = 0;
            return;
        }

        for (i = D_8024C090; i < ARRAY_COUNT(filemenu_8024C110); i++) {
            filemenu_8024C110[i] = 0xF7;
        }
    }

    if (filemenu_pressedButtons & BUTTON_START) {
        for (i = 0; i < ARRAY_COUNT(filemenu_8024C110); i++) {
            if (filemenu_8024C110[i] != 0xF7) {
                break;
            }
        }
        if (i == ARRAY_COUNT(filemenu_8024C110)) {
            sfx_play_sound(SOUND_MENU_ERROR);
            return;

        }

        sfx_play_sound(SOUND_MENU_NEXT);
        set_window_update(WINDOW_ID_50, (s32) filemenu_update_show_name_confirm);

        gWindows[50].pos.y = 121;
        gWindows[50].width = 69;
        gWindows[50].height = 44;
        gWindows[50].pos.x = ((gWindows[50].parent != -1)
                            ? (gWindows[gWindows[50].parent].width / 2)
                            : SCREEN_WIDTH / 2) - gWindows[50].width / 2;

        gWindows[46].pos.y = -70;
        gWindows[46].width = 164;
        gWindows[46].height = 62;
        gWindows[46].pos.x = ((gWindows[46].parent != -1)
                            ? (gWindows[gWindows[46].parent].width / 2)
                            : SCREEN_WIDTH / 2) - gWindows[46].width / 2;

        newMenu2 = filemenu_menus[1];
        filemenu_8024C098 = 1;
        newMenu2->page = 2;
        filemenu_set_selected(newMenu2, 0, 0);
    }
}

static const f32 padding[2] = { 0.0f, 0.0f }; // not sure why this is needed

void filemenu_choose_name_update(MenuPanel* menu) {
}

void filemenu_choose_name_cleanup(MenuPanel* menu) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_8024C100_C09980); i++) {
        hud_element_free(D_8024C100_C09980[i]);
    }
}
