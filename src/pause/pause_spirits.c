#include "pause_common.h"
#include "sprite.h"

extern s32 D_802706FC;
extern s32 D_802706E0[];
extern s32 D_802706C0[];
extern Gfx D_8026F5A0[];
extern s32 D_8026A2B0;
extern s32 D_8026FE78[];

void pause_spirits_init(MenuPanel* panel);
void pause_spirits_handle_input(MenuPanel* panel);
void pause_spirits_update(MenuPanel* panel);
void pause_spirits_cleanup(MenuPanel* panel);

s32 D_8024F8B0[] = { 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000 };
s32 D_8024F8C0[][4] = {
    { 0x00120000, 0x00120001, 0x00120002, 0xFFFFFFFF },
    { 0x00130000, 0x00130001, 0x00130002, 0xFFFFFFFF },
    { 0x00140000, 0x00140001, 0x00140002, 0xFFFFFFFF },
    { 0x00150000, 0x00150001, 0x00150002, 0xFFFFFFFF },
    { 0x00160000, 0x00160001, 0x00160002, 0xFFFFFFFF },
    { 0x00170000, 0x00170001, 0x00170003, 0xFFFFFFFF },
    { 0x00180000, 0x00180001, 0x00180002, 0xFFFFFFFF }
};
s8 D_8024F930[] = {
    5, 6, 0, 1, 2,
    5, 4, 4, 3, 2
};
Vec2i D_8024F93C[] = { {.x = 120, .y = -5},
                       {.x = 179, .y = -2},
                       {.x = 222, .y = 28},
                       {.x = 165, .y = 45},
                       {.x = 76, .y = 45},
                       {.x = 17, .y = 28},
                       {.x = 59, .y = -2} };
s32 D_8024F974[] = { 6, 0, 1, 5, 2, 4, 3 };
Vec2i D_8024F990[] = { {.x = 120, .y = 50},
                       {.x = 180, .y = 55},
                       {.x = 220, .y = 90},
                       {.x = 165, .y = 110},
                       {.x = 75, .y = 110},
                       {.x = 20, .y = 90},
                       {.x = 60, .y = 55} };
MenuWindowBP D_8024F9C8[] = { { .windowID = WINDOW_ID_39,
                                .unk_01 = 0,
                                .pos = { .x = 3,
                                         .y = 16 },
                                .width = 289,
                                .height = 154,
                                .unk_0A = { 1, 0},
                                .fpDrawContents = &pause_spirits_draw_contents,
                                .tab = NULL,
                                .parentID = WINDOW_ID_PAUSE_MAIN,
                                .fpUpdate = { 2 },
                                .unk_1C = 0,
                                .style = &gPauseWS_23 },

                            { .windowID = WINDOW_ID_40,
                                .unk_01 = 0,
                                .pos = { .x = 86,
                                         .y = 124 },
                                .width = 120,
                                .height = 20,
                                .unk_0A = { 0, 0},
                                .fpDrawContents = &pause_spirits_draw_title,
                                .tab = NULL,
                                .parentID = WINDOW_ID_39,
                                .fpUpdate = { 1 },
                                .unk_1C = 0,
                                .style = &gPauseWS_24 } };
MenuPanel gPausePanelSpirits = {
                                .initialized = FALSE,
                                .col = 2,
                                .row = 0,
                                .selected = 0,
                         .page = 0,
                         .numCols = 5,
                         .numRows = 2,
                         .numPages = 0,
                         .gridData = D_8024F930,
                         .fpInit = &pause_spirits_init,
                         .fpHandleInput = &pause_spirits_handle_input,
                         .fpUpdate = &pause_spirits_update,
                         .fpCleanup = &pause_spirits_cleanup };

void pause_spirits_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    Matrix4f sp50;
    Matrix4f sp90;
    s32 i, j;
    s32 s0;
    s32 s1;
    s32 s2;
    f32 x, y;
    f32 f20;
    s32 x1, y1, x2, y2;
    f32 frameCounter;
    f32 scale;
    PlayerData* playerData = get_player_data();

    gDPPipeSync(gMasterGfxPos++);
    gSPViewport(gMasterGfxPos++, &D_8024F8B0);
    gSPDisplayList(gMasterGfxPos++, D_8026F5A0);

    for (i = 0; i < 5; i++) {
        gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 64, &D_8026A2B0);
        gDPSetTile(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_8b, 8, 0x0000, G_TX_LOADTILE, 0, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_MIRROR, 7, G_TX_NOLOD);
        gDPLoadSync(gMasterGfxPos++);
        gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, i * 0x58, 254, 0x54 + i * 0x58);
        gDPPipeSync(gMasterGfxPos++);
        gDPSetTile(gMasterGfxPos++, G_IM_FMT_CI, G_IM_SIZ_4b, 8, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_MIRROR | G_TX_WRAP, 7, G_TX_NOLOD);
        gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, i * 0x58, 508, 0x54 + i * 0x58);
        pause_draw_rect((baseX + 0xF) * 4, (baseY + 0x16 + i * 0x16) * 4, (baseX + 0x10F) * 4, (baseY + 0x16 + i * 0x16 + 0x16) * 4, 0, 0x10, 0x10 + i * 0x2C0, 0x400, 0x400);
        gDPPipeSync(gMasterGfxPos++);
    }

    guOrthoF(sp50, 0.0f, 320.0f, 240.0f, 0.0f, -1000.0f, 1000.0f, 1.0f);
    guMtxF2L(sp50, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    guTranslateF(sp50, 0.0f, 0.0f, 0.0f);
    guMtxF2L(sp50, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);


    for (i = 0; i < D_802706FC; i++) {
        s2 = D_8024F974[i];
        frameCounter = gGameStatusPtr->frameCounter * 4;
        x = D_8024F93C[s2].x;
        y = D_8024F93C[s2].y;

        if (playerData->maxStarPower < s2 + 1) {
            s0 = 0;
            s1 = 0x80;
            f20 = 0.0f;
        } else {
            s0 = 0xFF;
            s1 = 0xFF;
            f20 = sin_deg(s2 * s2 * s2 + frameCounter * 0.4321 + frameCounter * (s2 * 0.02 + 0.1324))
                  * 5.0f
                  * sin_deg(s2 * 0.25 + frameCounter + frameCounter * (0.0432 - s2 * 0.01));

        }

        func_802DE894(D_802706C0[D_802706E0[s2]], 8, s0, s0, s0, s1, 0x40);
        guTranslateF(sp50, baseX + 0x16 + x, baseY + 0x4D + y + f20, 0.0f);
        guRotateF(sp90, 180.0f, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp90, sp50, sp50);

        if (s2 == 1 || s2 == 2 || s2 == 3) {
            guRotateF(sp90, 180.0f, 0.0f, 1.0f, 0.0f);
            guMtxCatF(sp90, sp50, sp50);
        }

        guScaleF(sp90, 0.9f, 0.9f, 0.9f);
        guMtxCatF(sp90, sp50, sp50);
        spr_draw_npc_sprite(D_802706C0[D_802706E0[s2]], 0, 0, 0, sp50);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);

    x1 = baseX + 7;
    y1 = baseY + 14;
    x2 = baseX + 0x117;
    y2 = baseY + 0x8C;

    if (x1 <= 0) {
        x1 = 1;
    }
    if (y1 <= 0) {
        y1 = 1;
    }

    if (x2 <= 0 || y2 <= 0 || x1 >= 319 || y1 >= 239) {
        return;
    }

    if (x2 >= 319) {
        x2 = 319;
    }
    if (y2 >= 239) {
        y2 = 239;
    }

    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);
    draw_box(0, &gPauseWS_25, baseX + 7, baseY + 0xE, 0, 0x110, 0x7E, opacity, darkening, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, width, height, 0);

    if (gPauseMenuCurrentTab == 5) {
        pause_set_cursor_pos(0x27, baseX + D_8024F990[menu->selected].x, baseY + D_8024F990[menu->selected].y);
    }
}

void pause_spirits_draw_title(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 msgID;
    PlayerData* playerData = get_player_data();

    if (gPauseMenuCurrentTab == 5) {
        if (playerData->maxStarPower > D_802706E0[menu->selected]) {
            msgID = D_802706E0[menu->selected] + MESSAGE_ID(0x1D, 0x2A);
        } else {
            msgID = pause_get_menu_msg(0x56);
        }
        draw_msg(msgID, baseX + ((width - get_msg_width(msgID, 0)) >> 1), baseY + 1, 0xFF, 0, 0);
    }
}

void pause_spirits_init(MenuPanel* panel) {
    s32 i;

    get_player_data();
    D_802706FC = 0;

    for (i = 0; i < 7; i++) {
        D_802706E0[D_802706FC] = i;
        D_802706FC++;
    }

    for (i = 0; i < 7; i++) {
        D_802706C0[i] = spr_load_npc_sprite(D_8024F8C0[i][0], D_8024F8C0[i]);
    }

    for (i = 0; i < 2; i++) {
        D_8024F9C8[i].tab = panel;
    }
    setup_pause_menu_tab(D_8024F9C8, 2);
    panel->initialized = TRUE;
}

void pause_spirits_handle_input(MenuPanel* panel) {
    s32 oldSelected = panel->selected;

    if (gPauseHeldButtons & BUTTON_STICK_LEFT) {
        while (TRUE) {
            panel->col--;
            if (panel->col < 0) {
                panel->col = 0;
                break;
            }

            if (panel->selected != panel->gridData[
                                            (panel->page * panel->numCols * panel->numRows)
                                          + (panel->numCols * panel->row)
                                          + (panel->col)]) {
                                              break;
                                          }
        }
    }

    if (gPauseHeldButtons & BUTTON_STICK_RIGHT) {
        while (TRUE) {
            panel->col++;
            if (panel->col >= panel->numCols) {
                panel->col = panel->numCols - 1;
                break;
            }

            if (panel->selected != panel->gridData[
                                            (panel->page * panel->numCols * panel->numRows)
                                          + (panel->numCols * panel->row)
                                          + (panel->col)]) {
                                              break;
                                          }
        }
    }

    if (gPauseHeldButtons & BUTTON_STICK_UP) {
        if (panel->selected == 2) {
            panel->col = 3;
            panel->row = 0;
        } else if (panel->selected == 5) {
            panel->col = 1;
            panel->row = 0;
        } else {
            while (TRUE) {
                panel->row--;
                if (panel->row < 0) {
                    panel->row = 0;
                    break;
                }
                if (panel->selected != panel->gridData[
                                                (panel->page * panel->numCols * panel->numRows)
                                              + (panel->numCols * panel->row)
                                              + (panel->col)]) {
                                                  break;
                                              }
            }
        }
    }

    if (gPauseHeldButtons & BUTTON_STICK_DOWN) {
        if (panel->selected == 2) {
            panel->col = 3;
            panel->row = 1;
        } else if (panel->selected == 5) {
            panel->col = 1;
            panel->row = 1;
        } else {
            while (TRUE) {
                panel->row++;
                if (panel->row >= panel->numRows) {
                    panel->row = panel->numRows - 1;
                    break;
                }
                if (panel->selected != panel->gridData[
                                                (panel->page * panel->numCols * panel->numRows)
                                              + (panel->numCols * panel->row)
                                              + (panel->col)]) {
                                                  break;
                                              }
            }
        }
    }

    panel->selected = panel->gridData[
                              (panel->page * panel->numCols * panel->numRows)
                            + (panel->numCols * panel->row)
                            + (panel->col)];

    if (panel->selected == 4) {
        panel->col = 1;
        panel->row = 1;
    }

    if (panel->selected != oldSelected) {
        sfx_play_sound(0xC7);
    }

    if (gPausePressedButtons & BUTTON_B) {
        gPauseMenuCurrentTab = 0;
        sfx_play_sound(0xCA);
        return;
    }

    gPauseCurrentDescIconScript = 0;

    if (get_player_data()->maxStarPower <= D_802706E0[panel->selected]) {
        gPauseCurrentDescMsg = pause_get_menu_msg(0x56);
    } else {
        gPauseCurrentDescMsg = MESSAGE_ID(0x1D, 0x31) + D_802706E0[panel->selected];
    }
}

void pause_spirits_update(MenuPanel* panel) {
    PlayerData* playerData = get_player_data();
    s32 i;

    for (i = 0; i < D_802706FC; i++) {
        if (i < playerData->maxStarPower && gPauseMenuCurrentTab == 5 && i == panel->selected) {
            spr_update_sprite(D_802706C0[i], D_8024F8C0[i][1], 1.0f);
        } else {
            //TODO find better match
            do { spr_update_sprite(D_802706C0[i], D_8024F8C0[i][0], 1.0f); } while (0);
        }
    }
}

void pause_spirits_cleanup(MenuPanel* panel) {
    s32 i;

    for (i = 0; i < 7; i++) {
        spr_free_sprite(D_802706C0[i]);
    }
}
