#include "common.h"
#include "filemenu.h"
#include "message_ids.h"
#include "hud_element.h"
#include "ld_addrs.h"
#include "game_modes.h"

extern HudScript HES_Spirit1;

HudScript* D_filemenu_8024F120[] = { &HES_Spirit1 };

u32 D_filemenu_8024F124 = 0x00000000;

s32 D_filemenu_8024F128 = 0x00000000;

u8 D_filemenu_8024F12C[] = { 0x00, 0x01, 0x02, 0x03 };

u32 D_filemenu_8024F130[] = {
    MSG_PAL_Menu_0056,
    MSG_PAL_Menu_0057,
    MSG_PAL_Menu_0058,
    MSG_PAL_Menu_0059,
};

Gfx D_filemenu_8024F140[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_CLD_SURF, G_RM_CLD_SURF2),
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPNoOp(),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, 320, 240),
    gsSPEndDisplayList(),
};

u32 D_filemenu_8024F1C8[] = {
    0x00000300,
    0x00000000,
    0x00000200,
    0x00000100,
};

void filemenu_draw_pal_8024d6a0(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void filemenu_draw_pal_8024DAA0(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void filemenu_update_pal_80247f40(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                                  f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
void filemenu_draw_pal_8024DA50(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);

void filemenu_draw_pal_8024DA00(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void filemenu_draw_pal_8024D9B0(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void filemenu_selectlanguage_handle_input(MenuPanel*);
void filemenu_selectlanguage_init(MenuPanel*);
void filemenu_selectlanguage_cleanup(MenuPanel*);
void filemenu_selectlanguage_update(MenuPanel*);

MenuWindowBP D_filemenu_8024F1D8[] = {
    {
        .windowID = WINDOW_ID_FILEMENU_TITLE,
        .unk_01 = 0,
        .pos = { .x = 0, .y = 0 },
        .width = 0,
        .height = 0,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_pal_8024d6a0,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { .func=&filemenu_update_show_title },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[3] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_FILE2_INFO,
        .unk_01 = 0,
        .pos = { .x = 89, .y = 98 },
        .width = 110,
        .height = 20,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_pal_8024DA50,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { .func=&filemenu_update_pal_80247f40 },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[9] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_FILE3_INFO,
        .unk_01 = 0,
        .pos = { .x = 89, .y = 124 },
        .width = 110,
        .height = 20,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_pal_8024DAA0,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { .func=&filemenu_update_pal_80247f40 },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[10] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_FILE0_INFO,
        .unk_01 = 0,
        .pos = { .x = 89, .y = 46 },
        .width = 110,
        .height = 20,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_pal_8024D9B0,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { .func=&filemenu_update_pal_80247f40 },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[7] }
    },
    {
        .windowID = WINDOW_ID_FILEMENU_FILE1_INFO,
        .unk_01 = 0,
        .pos = { .x = 89, .y = 72 },
        .width = 110,
        .height = 20,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = &filemenu_draw_pal_8024DA00,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { .func=&filemenu_update_pal_80247f40 },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[8] }
    },
};

MenuPanel filemenu_selectlanguage_menuBP = {
    .initialized = FALSE,
    .col = 0,
    .row = 0,
    .selected = 0,
    .page = 0,
    .numCols =1,
    .numRows = 4,
    .numPages = 0,
    .gridData = D_filemenu_8024F12C,
    .fpInit = filemenu_selectlanguage_init,
    .fpHandleInput = filemenu_selectlanguage_handle_input,
    .fpUpdate = filemenu_selectlanguage_update,
    .fpCleanup = filemenu_selectlanguage_cleanup
};

void filemenu_draw_pal_8024d6a0(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    draw_msg(MSG_PAL_Menu_0055, baseX + (192 - get_msg_width(MSG_PAL_Menu_0055, 0)) / 2, baseY + 4, 255, 0, 0);
}

void func_filemenu_8024D710(s32 arg0, MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 var_a1;

    if (filemenu_currentMenu == 4 && menu->selected == arg0) {
        filemenu_set_cursor_goal_pos(arg0 + 60, baseX + 4, baseY + 10);
    }

    var_a1 = D_filemenu_8024F130[arg0];
    draw_msg(var_a1, baseX + 36, baseY + 2, 255, 10, 0);

    gSPDisplayList(gMainGfxPos++, D_filemenu_8024F140);

    if (arg0 != gCurrentLanguage) {
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 255, 255, 255, 128);
        gDPSetCombineMode(gMainGfxPos++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    } else {
        gDPSetCombineMode(gMainGfxPos++, G_CC_DECALRGBA, G_CC_DECALRGBA);
    }

    gDPPipeSync(gMainGfxPos++);
    gDPSetTextureImage(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 1, &D_802517E0[D_filemenu_8024F124][D_filemenu_8024F1C8[arg0]]);

    gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 0, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gMainGfxPos++);
    gDPLoadBlock(gMainGfxPos++, G_TX_LOADTILE, 0, 0, 255, 512);
    gDPPipeSync(gMainGfxPos++);
    gDPSetTile(gMainGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 4, 0x0000, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(gMainGfxPos++, G_TX_RENDERTILE, 0, 0, (16 - 1) << 2, (16 - 1) << 2);
    gSPTextureRectangle(gMainGfxPos++, (baseX + 15) << 2, (baseY + 2) << 2, (baseX + 31) << 2, (baseY + 18) << 2, 0, 0, 0, 0x400, 0x400);
}

void filemenu_draw_pal_8024D9B0(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    func_filemenu_8024D710(0, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_pal_8024DA00(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    func_filemenu_8024D710(1, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_pal_8024DA50(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    func_filemenu_8024D710(2, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_draw_pal_8024DAA0(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    func_filemenu_8024D710(3, menu, baseX, baseY, width, height, opacity, darkening);
}

void filemenu_selectlanguage_init(MenuPanel* menu) {
    s16 x;
    s16* posXPtr;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_filemenu_8024F120); i++) {
        D_802517D0[i] = hud_element_create(D_filemenu_8024F120[i]);
        hud_element_set_flags(D_802517D0[i], HUD_ELEMENT_FLAG_80);
    }

    for (i = 0; i < ARRAY_COUNT(D_filemenu_8024F1D8); i++) {
        D_filemenu_8024F1D8[i].tab = menu;
    }

    setup_pause_menu_tab(D_filemenu_8024F1D8, 5);

    menu->selected = MENU_PANEL_SELECTED_GRID_DATA(menu);
    D_802517D4[0] = (s32) menu->row;

    gWindows[WINDOW_ID_FILEMENU_TITLE].pos.y = 1;
    gWindows[WINDOW_ID_FILEMENU_TITLE].width = 192;
    gWindows[WINDOW_ID_FILEMENU_TITLE].height = 25;

    posXPtr = &gWindows[WINDOW_ID_FILEMENU_TITLE].pos.x;
    if (gWindows[WINDOW_ID_FILEMENU_TITLE].parent != -1) {
        x = (gWindows[gWindows[WINDOW_ID_FILEMENU_TITLE].parent].width / 2) - (gWindows[WINDOW_ID_FILEMENU_TITLE].width / 2);
    } else {
        x = 64;
    }
    *posXPtr = x;

    menu->initialized = 1;
    D_filemenu_8024F124 = 0;
    dma_copy(titlemenu_flags_ROM_START, titlemenu_flags_ROM_END, D_802517E0[0]);
    dma_copy(titlemenu_flags_ROM_START + 0x800, titlemenu_flags_ROM_END, D_802517E0[1]);
    D_filemenu_8024F128 = 2;
}

void filemenu_selectlanguage_handle_input(MenuPanel* menu) {
    s32 originalSelected = menu->selected;
    s32 var_s1 = 0;
    s32 var_a1;

    if (filemenu_heldButtons & BUTTON_STICK_LEFT) {
        while (TRUE) {
            menu->col--;
            if (menu->col < 0) {
                menu->col = 0;
                break;
            }
            if (menu->selected != MENU_PANEL_SELECTED_GRID_DATA(menu)) {
                break;
            }
        }
    }

    if (filemenu_heldButtons & BUTTON_STICK_RIGHT) {
        while (TRUE) {
            menu->col++;
            if (menu->col >= menu->numCols) {
                menu->col = menu->numCols - 1;
                break;
            }

            if (menu->selected != MENU_PANEL_SELECTED_GRID_DATA(menu)) {
                break;
            }
        }
    }

    if (filemenu_heldButtons & BUTTON_STICK_UP) {
        menu->row--;
        if (menu->row < 0) {
            menu->row = 0;
        }
    }

    if (filemenu_heldButtons & BUTTON_STICK_DOWN) {
        menu->row++;
        if (menu->row >= menu->numRows) {
            menu->row = menu->numRows - 1;
        }
    }

    var_a1 = 0;
    if (filemenu_pressedButtons & BUTTON_B) {
        if (menu->row != D_802517D4[0]) {
            menu->row = D_802517D4[0];
            sfx_play_sound(SOUND_MENU_BACK);
            var_a1 = 1;
        } else {
            var_s1 = 1;
        }
    }

    menu->selected = MENU_PANEL_SELECTED_GRID_DATA(menu);
    if (originalSelected != menu->selected) {
        if (var_a1 == 0) {
            sfx_play_sound(SOUND_FILE_MENU_MOVE_CURSOR);
        }
        switch (menu->selected) {                          /* irregular */
            case 0:
                gCurrentLanguage = LANGUAGE_EN;
                break;
            case 1:
                gCurrentLanguage = LANGUAGE_DE;
                break;
            case 2:
                gCurrentLanguage = LANGUAGE_FR;
                break;
            case 3:
                gCurrentLanguage = LANGUAGE_ES;
                break;
        }
    }

    if ((filemenu_pressedButtons & (BUTTON_A | BUTTON_START)) || (var_s1 != 0)) {
        set_window_update(WINDOW_ID_FILEMENU_FILE0_INFO, (s32) &filemenu_selectlanguage_80248018);
        set_window_update(WINDOW_ID_FILEMENU_FILE1_INFO, (s32) &filemenu_selectlanguage_80248018);
        set_window_update(WINDOW_ID_FILEMENU_FILE2_INFO, (s32) &filemenu_selectlanguage_80248018);
        set_window_update(WINDOW_ID_FILEMENU_FILE3_INFO, (s32) &filemenu_selectlanguage_80248018);
        set_window_update(WINDOW_ID_FILEMENU_TITLE, (s32) filemenu_update_hidden_title);
        if (var_s1 == 0) {
            sfx_play_sound(SOUND_PLANTS_BELL);
        } else {
            sfx_play_sound(SOUND_FILE_MENU_OUT);
        }
        set_game_mode(GAME_MODE_END_LANGUAGE_SELECT);
    }
}

void filemenu_selectlanguage_update(MenuPanel* menu) {
    gWindowStyles[WINDOW_ID_FILEMENU_FILE0_INFO].customStyle = &filemenu_windowStyles[15];
    gWindowStyles[WINDOW_ID_FILEMENU_FILE1_INFO].customStyle = &filemenu_windowStyles[15];
    gWindowStyles[WINDOW_ID_FILEMENU_FILE2_INFO].customStyle = &filemenu_windowStyles[15];
    gWindowStyles[WINDOW_ID_FILEMENU_FILE3_INFO].customStyle = &filemenu_windowStyles[15];

    switch (menu->selected) {
        case 0:
            gWindowStyles[WINDOW_ID_FILEMENU_FILE0_INFO].customStyle = &filemenu_windowStyles[16];
            break;
        case 1:
            gWindowStyles[WINDOW_ID_FILEMENU_FILE1_INFO].customStyle = &filemenu_windowStyles[16];
            break;
        case 2:
            gWindowStyles[WINDOW_ID_FILEMENU_FILE2_INFO].customStyle = &filemenu_windowStyles[16];
            break;
        case 3:
            gWindowStyles[WINDOW_ID_FILEMENU_FILE3_INFO].customStyle = &filemenu_windowStyles[16];
            break;
    }

    D_filemenu_8024F124 ^= 1;

    D_filemenu_8024F128 = D_filemenu_8024F128 + 1;
    if (D_filemenu_8024F128 > 40) {
        D_filemenu_8024F128 = 0;
    }

    dma_copy(titlemenu_flags_ROM_START + (D_filemenu_8024F128 * 0x800), titlemenu_flags_ROM_END, D_802517E0[D_filemenu_8024F124]);
}

void filemenu_selectlanguage_cleanup(MenuPanel* arg0) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_802517D0); i++) {
        hud_element_free(D_802517D0[i]);
    }
}
