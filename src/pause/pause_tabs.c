#include "pause_common.h"
static s32 gPauseTabsIconIDs[6];
static s32 gPauseTabsPreviousTab;
static s32 gPauseTabsHorizScrollPos;
HudScript* D_8024F1B0[] = { HudScript_HeaderStats, HudScript_HeaderBadges, HudScript_HeaderItems,
                            HudScript_HeaderParty, HudScript_HeaderSpirits, HudScript_HeaderMap };
s8 D_8024F1C8[] = { 0, 1, 2, 3, 4, 5 };
u8 D_8024F1D0[] = { 1, 2, 3, 4, 5, 6 };
u8 D_8024F1D8[] = { 25, 26, 27, 28, 29, 30 };
u8 D_8024F1E0[] = { 31, 32, 33, 34, 39, 41, 0, 0 };
MenuWindowBP D_8024F1E8[] = {
  { .windowID = WINDOW_ID_25,
    .unk_01 = 0,
    .pos = { .x = 0, .y = 7 },
    .width = 43,
    .height = 15,
    .unk_0A = { 64, 0 },
    .fpDrawContents = &pause_tabs_draw_stats,
    .tab = NULL,
    .parentID = WINDOW_ID_PAUSE_MAIN,
    .fpUpdate = { 1 },
    .unk_1C = 0,
    .style = &gPauseWS_3 },

  { .windowID = WINDOW_ID_26,
    .unk_01 = 0,
    .pos = { .x = 0, .y = 7 },
    .width = 43,
    .height = 15,
    .unk_0A = { 0, 0 },
    .fpDrawContents = &pause_tabs_draw_badges,
    .tab = NULL,
    .parentID = WINDOW_ID_PAUSE_MAIN,
    .fpUpdate = { .func = &pause_update_tab_default },
    .unk_1C = 0,
    .style = &gPauseWS_4 },

  { .windowID = WINDOW_ID_27,
    .unk_01 = 0,
    .pos = { .x = 0, .y = 7 },
    .width = 43,
    .height = 15,
    .unk_0A = { 0, 0 },
    .fpDrawContents = &pause_tabs_draw_items,
    .tab = NULL,
    .parentID = WINDOW_ID_PAUSE_MAIN,
    .fpUpdate = { .func = &pause_update_tab_default },
    .unk_1C = 0,
    .style = &gPauseWS_5 },

  { .windowID = WINDOW_ID_28,
    .unk_01 = 0,
    .pos = { .x = 0, .y = 7 },
    .width = 43,
    .height = 15,
    .unk_0A = { 0, 0 },
    .fpDrawContents = &pause_tabs_draw_party,
    .tab = NULL,
    .parentID = WINDOW_ID_PAUSE_MAIN,
    .fpUpdate = { .func = &pause_update_tab_default },
    .unk_1C = 0,
    .style = &gPauseWS_6 },

  { .windowID = WINDOW_ID_29,
    .unk_01 = 0,
    .pos = { .x = 0, .y = 7 },
    .width = 43,
    .height = 15,
    .unk_0A = { 0, 0 },
    .fpDrawContents = &pause_tabs_draw_spirits,
    .tab = NULL,
    .parentID = WINDOW_ID_PAUSE_MAIN,
    .fpUpdate = { .func = &pause_update_tab_default },
    .unk_1C = 0,
    .style = &gPauseWS_7 },

  { .windowID = WINDOW_ID_30,
    .unk_01 = 0,
    .pos = { .x = 0, .y = 7 },
    .width = 43,
    .height = 15,
    .unk_0A = { 0, 0 },
    .fpDrawContents = &pause_tabs_draw_map,
    .tab = NULL,
    .parentID = WINDOW_ID_PAUSE_MAIN,
    .fpUpdate = { .func = &pause_update_tab_default },
    .unk_1C = 0,
    .style = &gPauseWS_8 },

  { .windowID = WINDOW_ID_43,
    .unk_01 = 0,
    .pos = { .x = 8, .y = 8 },
    .width = 16,
    .height = 16,
    .unk_0A = { 64, 0 },
    .fpDrawContents = &pause_tabs_draw_invis,
    .tab = NULL,
    .parentID = WINDOW_ID_NONE,
    .fpUpdate = { 1 },
    .unk_1C = 0,
    .style = &gPauseWS_9 } };
s32 gPauseTabsCurrentTab = 0;
s32 D_8024F2E8[] = { 27, 28, 29, 30, 31, 32 };
u8 D_8024F300[] = { 0, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8 };
s32 D_8024F310 = 1;
MenuPanel gPausePanelTabs = {
    .initialized = FALSE,
    .col = 0,
    .row = 0,
    .selected = 0,
    .page = 0,
    .numCols = 6,
    .numRows = 1,
    .numPages = 0,
    .gridData = D_8024F1C8,
    .fpInit = &pause_tabs_init,
    .fpHandleInput = &pause_tabs_handle_input,
    .fpUpdate = &pause_tabs_update,
    .fpCleanup = &pause_tabs_cleanup
};

void pause_tabs_draw_invis(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
}

void pause_tabs_draw_stats(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    if (darkening != 0) {
        set_hud_element_flags(gPauseTabsIconIDs[0], 0x20);
        set_hud_element_alpha(gPauseTabsIconIDs[0], 255.0 - darkening * 0.5);
    } else {
        clear_hud_element_flags(gPauseTabsIconIDs[0], 0x20);
        set_hud_element_alpha(gPauseTabsIconIDs[0], 255);
    }

    set_hud_element_render_pos(gPauseTabsIconIDs[0], baseX + 22, baseY + 7);
    draw_hud_element_3(gPauseTabsIconIDs[0]);
    if (gPauseMenuCurrentTab == 0) {
        if (D_8024F1D8[menu->col] == 25) {
            pause_set_cursor_pos(D_8024F1D8[menu->col], baseX, baseY + 6);
        }
    }
}

void pause_tabs_draw_badges(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    if (darkening != 0) {
        set_hud_element_flags(gPauseTabsIconIDs[1], 0x20);
        set_hud_element_alpha(gPauseTabsIconIDs[1], 255.0 - darkening * 0.5);
    } else {
        clear_hud_element_flags(gPauseTabsIconIDs[1], 0x20);
        set_hud_element_alpha(gPauseTabsIconIDs[1], 255);
    }

    set_hud_element_render_pos(gPauseTabsIconIDs[1], baseX + 22, baseY + 7);
    draw_hud_element_3(gPauseTabsIconIDs[1]);
    if (gPauseMenuCurrentTab == 0) {
        if (D_8024F1D8[menu->col] == 26) {
            pause_set_cursor_pos(D_8024F1D8[menu->col], baseX, baseY + 6);
        }
    }
}

void pause_tabs_draw_items(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    if (darkening != 0) {
        set_hud_element_flags(gPauseTabsIconIDs[2], 0x20);
        set_hud_element_alpha(gPauseTabsIconIDs[2], 255.0 - darkening * 0.5);
    } else {
        clear_hud_element_flags(gPauseTabsIconIDs[2], 0x20);
        set_hud_element_alpha(gPauseTabsIconIDs[2], 255);
    }

    set_hud_element_render_pos(gPauseTabsIconIDs[2], baseX + 22, baseY + 7);
    draw_hud_element_3(gPauseTabsIconIDs[2]);
    if (gPauseMenuCurrentTab == 0) {
        if (D_8024F1D8[menu->col] == 27) {
            pause_set_cursor_pos(D_8024F1D8[menu->col], baseX, baseY + 6);
        }
    }
}

void pause_tabs_draw_party(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    if (darkening != 0) {
        set_hud_element_flags(gPauseTabsIconIDs[3], 0x20);
        set_hud_element_alpha(gPauseTabsIconIDs[3], 255.0 - darkening * 0.5);
    } else {
        clear_hud_element_flags(gPauseTabsIconIDs[3], 0x20);
        set_hud_element_alpha(gPauseTabsIconIDs[3], 255);
    }

    set_hud_element_render_pos(gPauseTabsIconIDs[3], baseX + 22, baseY + 7);
    draw_hud_element_3(gPauseTabsIconIDs[3]);
    if (gPauseMenuCurrentTab == 0) {
        if (D_8024F1D8[menu->col] == 28) {
            pause_set_cursor_pos(D_8024F1D8[menu->col], baseX, baseY + 6);
        }
    }
}

void pause_tabs_draw_spirits(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    if (darkening != 0) {
        set_hud_element_flags(gPauseTabsIconIDs[4], 0x20);
        set_hud_element_alpha(gPauseTabsIconIDs[4], 255.0 - darkening * 0.5);
    } else {
        clear_hud_element_flags(gPauseTabsIconIDs[4], 0x20);
        set_hud_element_alpha(gPauseTabsIconIDs[4], 255);
    }

    set_hud_element_render_pos(gPauseTabsIconIDs[4], baseX + 22, baseY + 7);
    draw_hud_element_3(gPauseTabsIconIDs[4]);
    if (gPauseMenuCurrentTab == 0) {
        if (D_8024F1D8[menu->col] == 29) {
            pause_set_cursor_pos(D_8024F1D8[menu->col], baseX, baseY + 6);
        }
    }
}

void pause_tabs_draw_map(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    if (darkening != 0) {
        set_hud_element_flags(gPauseTabsIconIDs[5], 0x20);
        set_hud_element_alpha(gPauseTabsIconIDs[5], 255.0 - darkening * 0.5);
    } else {
        clear_hud_element_flags(gPauseTabsIconIDs[5], 0x20);
        set_hud_element_alpha(gPauseTabsIconIDs[5], 255);
    }

    set_hud_element_render_pos(gPauseTabsIconIDs[5], baseX + 23, baseY + 7);
    draw_hud_element_3(gPauseTabsIconIDs[5]);
    if (gPauseMenuCurrentTab == 0) {
        if (D_8024F1D8[menu->col] == 30) {
            pause_set_cursor_pos(D_8024F1D8[menu->col], baseX, baseY + 6);
        }
    }
}

void pause_tabs_init(MenuPanel* tab) {
    s32 i;

    for (i = 0; i < 6; i++) {
        gPauseTabsIconIDs[i] = create_hud_element(D_8024F1B0[i]);
        set_hud_element_flags(gPauseTabsIconIDs[i], 0x80);
    }

    for (i = 6; i >= 0; i--) {
        D_8024F1E8[i].tab = tab;
    }

    setup_pause_menu_tab(D_8024F1E8, 7);
    gWindows[43].pos.y = 25;
    gPauseTabsHorizScrollPos = 0;
    tab->initialized = TRUE;
    gPauseTabsPreviousTab = 5;
}

void pause_tabs_handle_input(MenuPanel* tab) {
    Window* pauseWindows;
    s32 x;

    if (gPauseHeldButtons & (BUTTON_STICK_LEFT | BUTTON_Z)) {
        do {
            if (--tab->col < 0) {
                tab->col = 5;
                if (gPauseTabsHorizScrollPos < 1800) {
                    gPauseTabsHorizScrollPos += 1800;
                }
            }
        } while (gPausePanels[D_8024F1D0[tab->col]]->initialized == FALSE);
    }

    if (gPauseHeldButtons & (BUTTON_STICK_RIGHT | BUTTON_R)) {
        do {
            if (++tab->col >= 6) {
                tab->col = 0;
                if (gPauseTabsHorizScrollPos > 0) {
                    gPauseTabsHorizScrollPos -= 1800;
                }
            }
        } while (gPausePanels[D_8024F1D0[tab->col]]->initialized == FALSE);
    }

    if (tab->col != gPauseTabsCurrentTab) {
        replace_window_update(D_8024F1D8[tab->col], 0x40, pause_update_tab_getting_focus);
        replace_window_update(D_8024F1D8[gPauseTabsCurrentTab], 0x40, pause_update_tab_losing_focus);

        pauseWindows = &gWindows[25];
        x = pauseWindows[tab->col].pos.x;
        gWindows[43].pos.x = x + 6;
        gWindows[43].pos.y = 25;
        gPauseTabsPreviousTab = gPauseTabsCurrentTab;
        gPauseTabsCurrentTab = tab->col;
        sfx_play_sound(200);
    }

    if ((gPausePressedButtons & BUTTON_A) && gPausePanels[D_8024F1D0[tab->col]]->initialized == TRUE) {
        sfx_play_sound(201);
        gPauseMenuCurrentTab = D_8024F1D0[tab->col];
    }

    gPauseCurrentDescMsg = pause_get_menu_msg(D_8024F2E8[tab->col]);
    gPauseCurrentDescIconScript = NULL;
}

void pause_tabs_update(MenuPanel* tab) {
    s32 s0;
    f32 f2;
    f32 delta;
    f32 f7;
    void (*phi_s2)(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                                 f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
    void (*phi_s4)(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                                 f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
    WindowUpdateFunc fpUpdate;
    s32 i;
    s32 flag;
    s32 sgn;

    delta = tab->col * 300 - gPauseTabsHorizScrollPos;
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

    gPauseTabsHorizScrollPos += f2;

    if ((gPauseTabsPreviousTab != 0 || tab->col != 5) && (gPauseTabsPreviousTab < tab->col || gPauseTabsPreviousTab == 5 && tab->col == 0)) {
        phi_s4 = &func_80243238;
        phi_s2 = &func_802432E8;
    } else {
        phi_s4 = &func_80243188;
        phi_s2 = &func_80243388;
    }

    flag = FALSE;
    for (i = 0; i < 6; i++) {
        if (gPausePanels[D_8024F1D0[i]]->initialized && (gWindows[D_8024F1E0[i]].flags & 8)) {
            flag = TRUE;
            break;
        }
    }

    if (!flag) {
        for (i = 0; i < 6; i++) {
            if (gPausePanels[D_8024F1D0[i]]->initialized) {
                fpUpdate = gWindows[D_8024F1E0[i]].fpUpdate;
                if (i != tab->col && (fpUpdate.func == func_80243238 ||
                                               fpUpdate.func == func_80243188 ||
                                               fpUpdate.func == basic_window_update ||
                                               fpUpdate.i == 1)) {
                    set_window_update(D_8024F1E0[i], phi_s2);
                    flag = TRUE;
                }
            }
        }

        if (!flag) {
            if (gWindows[D_8024F1E0[tab->col]].fpUpdate.func == func_802432E8 ||
                gWindows[D_8024F1E0[tab->col]].fpUpdate.func == func_80243388 ||
                gWindows[D_8024F1E0[tab->col]].fpUpdate.i == 2) {
                if (D_8024F310 != 0) {
                    phi_s4 = &basic_window_update;
                    D_8024F310 = 0;
                }

                set_window_update(D_8024F1E0[tab->col], phi_s4);
            }
        }
    }
}

void pause_tabs_cleanup(MenuPanel* tab) {
    s32* iconIDs = gPauseTabsIconIDs;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPauseTabsIconIDs); i++) {
        free_hud_element(iconIDs[i]);
    }
}
