#include "common.h"
#include "hud_element.h"

extern HudScript HudScript_HeaderStats;
extern HudScript HudScript_HeaderBadges;
extern HudScript HudScript_HeaderItems;
extern HudScript HudScript_HeaderParty;
extern HudScript HudScript_HeaderSpirits;
extern HudScript HudScript_HeaderMap;
extern MenuPanel* gPauseMenuPanels[];
extern s32 D_80270148;
extern s32 D_8027014C;

void pause_tabs_init(MenuPanel* tab);
void pause_tabs_handle_input(MenuPanel* tab);
void pause_tabs_update(MenuPanel* tab);
void pause_tabs_cleanup(MenuPanel* tab);
void pause_tabs_draw_stats(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void pause_tabs_draw_badges(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void pause_tabs_draw_items(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void pause_tabs_draw_party(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void pause_tabs_draw_spirits(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void pause_tabs_draw_map(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void pause_tabs_draw_invis(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
void func_80242F90(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8,
                    s32 arg9, s32* argA, s32* argB);
void func_80243090(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB);
void func_80242FF4(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB);
void func_80243238(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB);
void func_802432E8(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB);
void func_80243188(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB);
void func_80243388(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB);


HudScript* D_8024F1B0[] = { HudScript_HeaderStats, HudScript_HeaderBadges, HudScript_HeaderItems,
                                 HudScript_HeaderParty, HudScript_HeaderSpirits, HudScript_HeaderMap };
s8 D_8024F1C8[] = { 0, 1, 2, 3, 4, 5 };
u8 D_8024F1D0[] = { 1, 2, 3, 4, 5, 6 };
u8 D_8024F1D8[] = { 25, 26, 27, 28, 29, 30 };
u8 D_8024F1E0[] = { 0x1F, 0x20, 0x21, 0x22, 0x27, 0x29, 0x00, 0x00 };
MenuWindowBP D_8024F1E8[] = { { .windowID = 25,
                                .unk_01 = 0,
                                .pos = { .x = 0,
                                         .y = 7 },
                                .height = 43,
                                .width = 15,
                                .unk_0A = { 64, 0},
                                .fpDrawContents = &pause_tabs_draw_stats,
                                .tab = NULL,
                                .parentID = 0x16000000,
                                .fpUpdate = 1,
                                .unk_1C = 0,
                                .style = 0x8026F9A8 },

                            { .windowID = 26,
                                .unk_01 = 0,
                                .pos = { .x = 0,
                                         .y = 7 },
                                .height = 43,
                                .width = 15,
                                .unk_0A = { 0, 0},
                                .fpDrawContents = &pause_tabs_draw_badges,
                                .tab = NULL,
                                .parentID = 0x16000000,
                                .fpUpdate = &func_80242F90,
                                .unk_1C = 0,
                                .style = 0x8026F9E0 },

                            { .windowID = 27,
                                .unk_01 = 0,
                                .pos = { .x = 0,
                                         .y = 7 },
                                .height = 43,
                                .width = 15,
                                .unk_0A = { 0, 0},
                                .fpDrawContents = &pause_tabs_draw_items,
                                .tab = NULL,
                                .parentID = 0x16000000,
                                .fpUpdate = &func_80242F90,
                                .unk_1C = 0,
                                .style = 0x8026FA18 },

                            { .windowID = 28,
                                .unk_01 = 0,
                                .pos = { .x = 0,
                                         .y = 7 },
                                .height = 43,
                                .width = 15,
                                .unk_0A = { 0, 0},
                                .fpDrawContents = &pause_tabs_draw_party,
                                .tab = NULL,
                                .parentID = 0x16000000,
                                .fpUpdate = &func_80242F90,
                                .unk_1C = 0,
                                .style = 0x8026FA50 },

                            { .windowID = 29,
                                .unk_01 = 0,
                                .pos = { .x = 0,
                                         .y = 7 },
                                .height = 43,
                                .width = 15,
                                .unk_0A = { 0, 0},
                                .fpDrawContents = &pause_tabs_draw_spirits,
                                .tab = NULL,
                                .parentID = 0x16000000,
                                .fpUpdate = &func_80242F90,
                                .unk_1C = 0,
                                .style = 0x8026FA88 },

                            { .windowID = 30,
                                .unk_01 = 0,
                                .pos = { .x = 0,
                                         .y = 7 },
                                .height = 43,
                                .width = 15,
                                .unk_0A = { 0, 0},
                                .fpDrawContents = &pause_tabs_draw_map,
                                .tab = NULL,
                                .parentID = 0x16000000,
                                .fpUpdate = &func_80242F90,
                                .unk_1C = 0,
                                .style = 0x8026FAC0 },

                            { .windowID = 43,
                                .unk_01 = 0,
                                .pos = { .x = 8,
                                         .y = 8 },
                                .height = 16,
                                .width = 16,
                                .unk_0A = { 64, 0},
                                .fpDrawContents = &pause_tabs_draw_invis,
                                .tab = NULL,
                                .parentID = 0xFF000000,
                                .fpUpdate = 1,
                                .unk_1C = 0,
                                .style = 0x8026FAF8 } };
s32 D_8024F2E4 = 0;
s32 D_8024F2E8[] = { 27, 28, 29, 30, 31, 32 };
u8 D_8024F300[] = { 0x00, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08 };
s32 D_8024F310 = 1;
MenuPanel gPausePanelTabs = { .unk_00 = {
                            .s = 0 },
                         .page = 0,
                         .numCols = 6,
                         .numRows = 1,
                         .numPages = 0,
                         .gridData = D_8024F1C8,
                         .fpInit = &pause_tabs_init,
                         .fpHandleInput = &pause_tabs_handle_input,
                         .fpUpdate = &pause_tabs_update,
                         .fpCleanup = &pause_tabs_cleanup };

void pause_tabs_draw_invis(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
}

void pause_tabs_draw_stats(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    if (arg6 != 0) {
        set_hud_element_flags(gPauseMenuTabIconIDs[0], 0x20);
        set_hud_element_alpha(gPauseMenuTabIconIDs[0], 255.0 - arg6 * 0.5);
    } else {
        clear_hud_element_flags(gPauseMenuTabIconIDs[0], 0x20);
        set_hud_element_alpha(gPauseMenuTabIconIDs[0], 255);
    }

    set_hud_element_render_pos(gPauseMenuTabIconIDs[0], arg1 + 22, arg2 + 7);
    draw_hud_element_3(gPauseMenuTabIconIDs[0]);
    if (gPauseMenuCurrentTab == 0) {
        if (D_8024F1D8[arg0[1]] == 25) {
            func_80242D04(D_8024F1D8[arg0[1]], arg1, arg2 + 6);
        }
    }
}

void pause_tabs_draw_badges(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    if (arg6 != 0) {
        set_hud_element_flags(gPauseMenuTabIconIDs[1], 0x20);
        set_hud_element_alpha(gPauseMenuTabIconIDs[1], 255.0 - arg6 * 0.5);
    } else {
        clear_hud_element_flags(gPauseMenuTabIconIDs[1], 0x20);
        set_hud_element_alpha(gPauseMenuTabIconIDs[1], 255);
    }

    set_hud_element_render_pos(gPauseMenuTabIconIDs[1], arg1 + 22, arg2 + 7);
    draw_hud_element_3(gPauseMenuTabIconIDs[1]);
    if (gPauseMenuCurrentTab == 0) {
        if (D_8024F1D8[arg0[1]] == 26) {
            func_80242D04(D_8024F1D8[arg0[1]], arg1, arg2 + 6);
        }
    }
}

void pause_tabs_draw_items(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    if (arg6 != 0) {
        set_hud_element_flags(gPauseMenuTabIconIDs[2], 0x20);
        set_hud_element_alpha(gPauseMenuTabIconIDs[2], 255.0 - arg6 * 0.5);
    } else {
        clear_hud_element_flags(gPauseMenuTabIconIDs[2], 0x20);
        set_hud_element_alpha(gPauseMenuTabIconIDs[2], 255);
    }

    set_hud_element_render_pos(gPauseMenuTabIconIDs[2], arg1 + 22, arg2 + 7);
    draw_hud_element_3(gPauseMenuTabIconIDs[2]);
    if (gPauseMenuCurrentTab == 0) {
        if (D_8024F1D8[arg0[1]] == 27) {
            func_80242D04(D_8024F1D8[arg0[1]], arg1, arg2 + 6);
        }
    }
}

void pause_tabs_draw_party(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    if (arg6 != 0) {
        set_hud_element_flags(gPauseMenuTabIconIDs[3], 0x20);
        set_hud_element_alpha(gPauseMenuTabIconIDs[3], 255.0 - arg6 * 0.5);
    } else {
        clear_hud_element_flags(gPauseMenuTabIconIDs[3], 0x20);
        set_hud_element_alpha(gPauseMenuTabIconIDs[3], 255);
    }

    set_hud_element_render_pos(gPauseMenuTabIconIDs[3], arg1 + 22, arg2 + 7);
    draw_hud_element_3(gPauseMenuTabIconIDs[3]);
    if (gPauseMenuCurrentTab == 0) {
        if (D_8024F1D8[arg0[1]] == 28) {
            func_80242D04(D_8024F1D8[arg0[1]], arg1, arg2 + 6);
        }
    }
}

void pause_tabs_draw_spirits(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    if (arg6 != 0) {
        set_hud_element_flags(gPauseMenuTabIconIDs[4], 0x20);
        set_hud_element_alpha(gPauseMenuTabIconIDs[4], 255.0 - arg6 * 0.5);
    } else {
        clear_hud_element_flags(gPauseMenuTabIconIDs[4], 0x20);
        set_hud_element_alpha(gPauseMenuTabIconIDs[4], 255);
    }

    set_hud_element_render_pos(gPauseMenuTabIconIDs[4], arg1 + 22, arg2 + 7);
    draw_hud_element_3(gPauseMenuTabIconIDs[4]);
    if (gPauseMenuCurrentTab == 0) {
        if (D_8024F1D8[arg0[1]] == 29) {
            func_80242D04(D_8024F1D8[arg0[1]], arg1, arg2 + 6);
        }
    }
}

void pause_tabs_draw_map(s8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    if (arg6 != 0) {
        set_hud_element_flags(gPauseMenuTabIconIDs[5], 0x20);
        set_hud_element_alpha(gPauseMenuTabIconIDs[5], 255.0 - arg6 * 0.5);
    } else {
        clear_hud_element_flags(gPauseMenuTabIconIDs[5], 0x20);
        set_hud_element_alpha(gPauseMenuTabIconIDs[5], 255);
    }

    set_hud_element_render_pos(gPauseMenuTabIconIDs[5], arg1 + 23, arg2 + 7);
    draw_hud_element_3(gPauseMenuTabIconIDs[5]);
    if (gPauseMenuCurrentTab == 0) {
        if (D_8024F1D8[arg0[1]] == 30) {
            func_80242D04(D_8024F1D8[arg0[1]], arg1, arg2 + 6);
        }
    }
}

void pause_tabs_init(MenuPanel* tab) {
    s32 i;

    for (i = 0; i < 6; i++) {
        gPauseMenuTabIconIDs[i] = create_hud_element(D_8024F1B0[i]);
        set_hud_element_flags(gPauseMenuTabIconIDs[i], 0x80);
    }

    for (i = 6; i >= 0; i--) {
        D_8024F1E8[i].tab = tab;
    }

    setup_pause_menu_tab(D_8024F1E8, 7);
    gWindows[43].pos.y = 25;
    D_8027014C = 0;
    tab->unk_00.c.initialized = TRUE;
    D_80270148 = 5;
}

void pause_tabs_handle_input(MenuPanel* tab) {
    Window* pauseWindows;
    s32 x;

    if (gPauseMenuHeldButtons & (BUTTON_STICK_LEFT | BUTTON_Z)) {
        do {
            if (--tab->unk_00.c.col < 0) {
                tab->unk_00.c.col = 5;
                if (D_8027014C < 1800) {
                    D_8027014C += 1800;
                }
            }
        } while (gPauseMenuPanels[D_8024F1D0[tab->unk_00.c.col]]->unk_00.c.initialized == FALSE);
    }

    if (gPauseMenuHeldButtons & (BUTTON_STICK_RIGHT | BUTTON_R)) {
        do {
            if (++tab->unk_00.c.col >= 6) {
                tab->unk_00.c.col = 0;
                if (D_8027014C > 0) {
                    D_8027014C -= 1800;
                }
            }
        } while (gPauseMenuPanels[D_8024F1D0[tab->unk_00.c.col]]->unk_00.c.initialized == FALSE);
    }

    if (tab->unk_00.c.col != D_8024F2E4) {
        replace_window_update(D_8024F1D8[tab->unk_00.c.col], 0x40, &func_80243090);
        replace_window_update(D_8024F1D8[D_8024F2E4], 0x40, &func_80242FF4);

        pauseWindows = &gWindows[25];
        x = pauseWindows[tab->unk_00.c.col].pos.x;
        gWindows[43].pos.x = x + 6;
        gWindows[43].pos.y = 25;
        D_80270148 = D_8024F2E4;
        D_8024F2E4 = tab->unk_00.c.col;
        sfx_play_sound(200);
    }

    if ((gPauseMenuPressedButtons & BUTTON_A) && gPauseMenuPanels[D_8024F1D0[tab->unk_00.c.col]]->unk_00.c.initialized == TRUE) {
        sfx_play_sound(201);
        gPauseMenuCurrentTab = D_8024F1D0[tab->unk_00.c.col];
    }

    gPauseMenuCurrentDescMsg = pause_get_menu_msg(D_8024F2E8[tab->unk_00.c.col]);
    gPauseMenuCurrentDescIconScript = NULL;
}

void pause_tabs_update(MenuPanel* tab) {
    s32 s0;
    f32 f2;
    f32 delta;
    f32 f7;
    void* phi_s2;
    void* phi_s4;
    void* fpUpdate;
    s32 i;
    s32 flag;
    s32 sgn;

    delta = tab->unk_00.c.col * 300 - D_8027014C;
    s0 = abs(delta);
    sgn = sign(delta);

    if (s0 >= 16) {
        f2 = s0 * 0.5;
        if (f2 > 32.0f) {
            f2 = 32.0f;
        }
    } else {
        f2 = D_8024F300[s0];
    }
    f2 = f2 * sgn;

    D_8027014C += f2;

    if ((D_80270148 != 0 || tab->unk_00.c.col != 5) && (D_80270148 < tab->unk_00.c.col || D_80270148 == 5 && tab->unk_00.c.col == 0)) {
        phi_s4 = &func_80243238;
        phi_s2 = &func_802432E8;
    } else {
        phi_s4 = &func_80243188;
        phi_s2 = &func_80243388;
    }

    flag = FALSE;
    for (i = 0; i < 6; i++) {
        if (gPauseMenuPanels[D_8024F1D0[i]]->unk_00.c.initialized && (gWindows[D_8024F1E0[i]].flags & 8)) {
            flag = TRUE;
            break;
        }
    }

    if (!flag) {
        for (i = 0; i < 6; i++) {
            if (gPauseMenuPanels[D_8024F1D0[i]]->unk_00.c.initialized) {
                fpUpdate = gWindows[D_8024F1E0[i]].fpUpdate;
                if (i != tab->unk_00.c.col && (fpUpdate == &func_80243238 ||
                                               fpUpdate == &func_80243188 ||
                                               fpUpdate == &basic_window_update ||
                                               fpUpdate == 1)) {
                    set_window_update(D_8024F1E0[i], phi_s2);
                    flag = TRUE;
                }
            }
        }

        if (!flag) {
            if (gWindows[D_8024F1E0[tab->unk_00.c.col]].fpUpdate == &func_802432E8 ||
                gWindows[D_8024F1E0[tab->unk_00.c.col]].fpUpdate == &func_80243388 ||
                gWindows[D_8024F1E0[tab->unk_00.c.col]].fpUpdate == 2) {
                if (D_8024F310 != 0) {
                    phi_s4 = &basic_window_update;
                    D_8024F310 = 0;
                }

                set_window_update(D_8024F1E0[tab->unk_00.c.col], phi_s4);
            }
        }
    }
}

void pause_tabs_cleanup(MenuPanel* tab) {
    s32* iconIDs = gPauseMenuTabIconIDs;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPauseMenuTabIconIDs); i++) {
        free_hud_element(iconIDs[i]);
    }
}
