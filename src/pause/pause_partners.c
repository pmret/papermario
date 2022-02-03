#include "pause_common.h"
#include "sprite.h"

typedef struct PartnerPosition {
    /* 0x00 */ f32 pos;
    /* 0x04 */ s32 index;
} PartnerPosition; // size = 0x8

extern HudScript HudScript_FPCost;
extern HudScript HudScript_PartnerRank;
extern HudScript HudScript_MoveDiamond;
extern HudScript HudScript_MoveBlueOrb;
extern HudScript HudScript_MoveGreenOrb;
extern HudScript HudScript_MoveRedOrb;
extern s32 gPartnerPopupProperties[11][4];

extern s32 D_80270640[];
extern s32 D_80270660[];
extern s32 D_80270680[];
extern s32 D_802706A0;
extern s32 D_802706A4;
extern f32 D_802706A8;
extern s32 D_802706AC;
extern s32 D_802706B0;
extern s32 D_8026FD98;

void pause_partners_draw_contents(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5, u32 arg6);
void pause_partners_draw_title(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void pause_partners_draw_movelist(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void pause_partners_draw_movelist_title(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void pause_partners_draw_movelist_flower(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void pause_partners_init(MenuPanel* panel);
void pause_partners_handle_input(MenuPanel* panel);
void pause_partners_update(MenuPanel* panel);
void pause_partners_cleanup(MenuPanel* panel);

HudScript* D_8024F600[] = { HudScript_FPCost, HudScript_StatFp_1, HudScript_PartnerRank, HudScript_PartnerRank,
                         HudScript_MoveDiamond, HudScript_MoveBlueOrb, HudScript_MoveGreenOrb, HudScript_MoveRedOrb };
Vp D_8024F620 = {
    .vp = {
        .vscale = { 640, 480, 511, 0 },
        .vtrans = { 640, 480, 511, 0 },
    }
};
s32 D_8024F630[][4] = {
    { 0x00010000, 0x00010002, 0x00010008, 0xFFFFFFFF },
    { 0x00020000, 0x00020004, 0x0002000D, 0xFFFFFFFF },
    { 0x00030000, 0x00030005, 0x0003000E, 0xFFFFFFFF },
    { 0x00040000, 0x00040002, 0x00040006, 0xFFFFFFFF },
    { 0x00050000, 0x00050002, 0x00050004, 0xFFFFFFFF },
    { 0x00060000, 0x00060002, 0x00060004, 0xFFFFFFFF },
    { 0x00070000, 0x00070002, 0x00070004, 0xFFFFFFFF },
    { 0x00080000, 0x00080005, 0x00080009, 0xFFFFFFFF }
};
s32 D_8024F6B0[] = { 1, 2, 3, 4, 9, 6, 7, 8};
s32 D_8024F6D0[] = { 0x00280006, 0x00280013, 0x00280020, 0x0028002D, 0x0028003A, 0x00280047, 0x00280054, 0x00280061 };
s32 D_8024F6F0[] = { MOVE_HEADBONK1, MOVE_SHELL_TOSS1, MOVE_BODY_SLAM1, MOVE_SKY_DIVE1,
                     MOVE_SMACK1, MOVE_ELECTRO_DASH1, MOVE_BELLY_FLOP1, MOVE_SPINY_FLIP1 };
s32 D_8024F710[] = { 0x04050607, 0x00010203 };
char* D_8024F718[] = { "party_kurio", "party_kameki", "party_pinki", "party_pareta", "party_resa",  "party_akari", "party_opuku", "party_pokopi", "letter_peach" };
s32 D_8024F73C[] = { 0x80270930, 0x802748B8 };
s32 D_8024F744[] = { 0x80270730, 0x802746B8 };
s32 D_8024F74C = 0;
Gfx D_8024F750[] = {
    gsDPPipeSync(),
    gsSPTexture(0xFFFF, 0xFFFF, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_RGBA16),
    gsDPSetTextureFilter(G_TF_POINT),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetCombineLERP(0, 0, 0, TEXEL0, 0, 0, 0, 1, 0, 0, 0, TEXEL0, 0, 0, 0, 1),
    gsSPClearGeometryMode(G_LIGHTING),
    gsSPSetGeometryMode(G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPEndDisplayList() };
s32 D_8024F7C0 = -1;
s32 D_8024F7C4 = -1;
MenuWindowBP D_8024F7C8[] = { { .windowID = WINDOW_ID_34,
                                         .unk_01 = 0,
                                         .pos = { .x = 3,
                                                  .y = 16 },
                                         .width = 289,
                                         .height = 154,
                                         .unk_0A = { 1, 0},
                                         .fpDrawContents = &pause_partners_draw_contents,
                                         .tab = NULL,
                                         .parentID = WINDOW_ID_PAUSE_MAIN,
                                         .fpUpdate = { 2 },
                                         .unk_1C = 0,
                                         .style = &gPauseWS_20 },

                                       { .windowID = WINDOW_ID_35,
                                         .unk_01 = 0,
                                         .pos = { .x = 8,
                                                  .y = 103 },
                                         .width = 112,
                                         .height = 20,
                                         .unk_0A = { 0, 0},
                                         .fpDrawContents = &pause_partners_draw_title,
                                         .tab = NULL,
                                         .parentID = WINDOW_ID_34,
                                         .fpUpdate = { 1 },
                                         .unk_1C = 0,
                                         .style = &gPauseWS_22 },

                                       { .windowID = WINDOW_ID_36,
                                         .unk_01 = 0,
                                         .pos = { .x = 133,
                                                  .y = 36 },
                                         .width = 140,
                                         .height = 80,
                                         .unk_0A = { 0, 0},
                                         .fpDrawContents = &pause_partners_draw_movelist,
                                         .tab = NULL,
                                         .parentID = WINDOW_ID_34,
                                         .fpUpdate = { 2 },
                                         .unk_1C = 0,
                                         .style = -1 },

                                       { .windowID = WINDOW_ID_37,
                                         .unk_01 = 0,
                                         .pos = { .x = 12,
                                                  .y = -6 },
                                         .width = 80,
                                         .height = 16,
                                         .unk_0A = { 0, 0},
                                         .fpDrawContents = &pause_partners_draw_movelist_title,
                                         .tab = NULL,
                                         .parentID = WINDOW_ID_36,
                                         .fpUpdate = { 1 },
                                         .unk_1C = 0,
                                         .style = -1 },

                                       { .windowID = WINDOW_ID_38,
                                         .unk_01 = 0,
                                         .pos = { .x = 102,
                                                  .y = -12 },
                                         .width = 32,
                                         .height = 32,
                                         .unk_0A = { 0, 0},
                                         .fpDrawContents = &pause_partners_draw_movelist_flower,
                                         .tab = NULL,
                                         .parentID = WINDOW_ID_36,
                                         .fpUpdate = { 1 },
                                         .unk_1C = 0,
                                         .style = -1 } };
u8 D_8024F87C[] = {0x00, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08 };
MenuPanel gPausePanelPartners = { .initialized = FALSE, .col = 0, .row = 1, .selected = 0,
                         .page = 0,
                         .numCols = 4,
                         .numRows = 2,
                         .numPages = 0,
                         .gridData = D_8024F710,
                         .fpInit = &pause_partners_init,
                         .fpHandleInput = &pause_partners_handle_input,
                         .fpUpdate = &pause_partners_update,
                         .fpCleanup = &pause_partners_cleanup };

void pause_partners_load_portrait(s32 arg0) {
    s32 size;
    void* asset;

    if (D_8024F7C0 != D_80270680[arg0]) {
        D_8024F7C0 = D_80270680[arg0];
        asset = load_asset_by_name(D_8024F718[D_8024F7C0], &size);
        decode_yay0(asset, D_8024F744[0]);
        general_heap_free(asset);
    }

    if (D_8024F7C4 != D_80270680[(arg0 + 1) % D_802706B0]) {
        D_8024F7C4 = D_80270680[(arg0 + 1) % D_802706B0];
        asset = load_asset_by_name(D_8024F718[D_8024F7C4], &size);
        decode_yay0(asset, D_8024F744[1]);
        general_heap_free(asset);
    }
}

void pause_partners_draw_contents(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5, u32 arg6) {
    Matrix4f sp50;
    Matrix4f sp90;
    PartnerPosition spD0[8];
    s32 i, j, k, l, m;
    s32 x1, y1, x2, y2;
    s32 x1a, y1a, x2a, y2a;
    f32 f, angle, f24, scale;
    f32 offsetX, offsetY;
    s32 a2;
    s8 currentTab;
    s32 f0;
    s32 ta2;
    s32 t6;
    s32 s7;
    s32 index;
    s32 dd;
    s32 a0, s8;

    gSPViewport(gMasterGfxPos++, &D_8024F620);
    guOrthoF(&sp50, 0.0f, 320.0f, 240.0f, 0.0f, -100.0f, 100.0f, 1.0f);
    guMtxF2L(&sp50, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
    guTranslateF(&sp50, 0.0f, 0.0f, 0.0f);
    guMtxF2L(&sp50, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    for (i = 0; i < D_802706B0; i++) {
        f = cos_deg( i * 360 / D_802706B0 - D_802706A8) * 20.0f + 0.0f;

        for (j = 0; j < i; j++) {
            if (f < spD0[j].pos) {
                break;
            }
        }

        for (k = D_802706B0 - 1; k > j; k--) {
            spD0[k] = spD0[k-1];
        }

        spD0[j].index = i;
        spD0[j].pos = f;
    }

    for (j = 0; j < D_802706B0; j++) {
        s8 = D_802706B0;
        l = spD0[j].index;
        angle = l * 360 / D_802706B0 - D_802706A8;
        //angle += -D_802706A8;
        offsetX = D_802706B0 * 3 + 17;// * sin_deg(angle) + 42.0f;
        offsetX *= sin_deg(angle);
        offsetX += 42.0f;
        f24 = 30.0f  - cos_deg(angle) * 30.0f;
        offsetY = cos_deg(angle) * 20.0f + 0.0f;
        scale = 30.0 / (f24 + 60.0f) + 0.5;

        guTranslateF(sp50, arg1 + 0x16 + offsetX, arg2 + 0x51 + offsetY, -f24);
        guRotateF(sp90, 180.0f, 0.0f, 0.0f, 1.0f);
        guMtxCatF(sp90, sp50, sp50);
        guScaleF(sp90, scale, scale, 1.0f);
        guMtxCatF(sp90, sp50, sp50);

        if (f24 > 8.0f) {
            a2 = 160;
        } else {
            a2 = 255.0f - f24 * 95.0f * 0.125f;
        }
        func_802DE894(D_80270660[D_80270680[l]], 6, a2, a2, a2, 0xFF, 0x40);
        spr_draw_npc_sprite(D_80270660[D_80270680[l]], 0, 0, NULL, sp50);
    }

    gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);

    currentTab = gPauseMenuCurrentTab;
    if (currentTab == 4) {
        if (D_802706AC == 0) {
            pause_set_cursor_pos(0x22, arg1 + 0x2A, arg2 + 0x58);
        }

        if (gPauseMenuCurrentTab == currentTab && D_802706AC == 0) {
            pause_draw_menu_label(8, 0x12, 0x9E);
        }
    }

    x1 = arg1 + 0x82;
    y1 = arg2 + 0x18;
    x2 = arg1 + 0x118;
    y2 = arg2 + 0x81;

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

    f0 = (D_802706A8 + 360.0f) * 15000.0f * D_802706B0 / 360.0f;
    ta2 = f0 / 15000;
    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, x1, y1, x2, y2);
    s7 = (ta2 * 15000 - f0);
    s7 *= 0.01;
    s8 = ta2;
    pause_partners_load_portrait(s8 % D_802706B0);
    for (i = 0; i < 2; s7 += 150, i++) {
        gSPDisplayList(gMasterGfxPos++, &D_8024F750);
        gDPLoadTLUT_pal256(gMasterGfxPos++, D_8024F744[i]);

        for (l = 0; l < 20; l++) {
            //dd = 12 * l;
            if (12 * l + 12 <= 105) {
                t6 = 12;
            } else {
                t6 = 106 - 12 * l;
            }

            gDPLoadTextureTile(gMasterGfxPos++, D_8024F73C[i], G_IM_FMT_CI, G_IM_SIZ_8b, 150, 0,
                                0, 12 * l, 149, 12 * l + t6 - 1, 0,
                                G_TX_CLAMP, G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
            pause_draw_rect((arg1 + 0x82 + s7) * 4, (arg2 + 0x18 + 12 * l) * 4, (arg1 + 0x118 + s7) * 4, (arg2 + 0x18 + 12 * l + t6) * 4, 0, 0,
                            12 * l * 32, 0x400, 0x400);
            gDPPipeSync(gMasterGfxPos++);
            if (12 * l + 12 >= 105) {
                break;
            }
        }
    }

    x1a = arg1 + 0x7A;
    y1a = arg2 + 0x10;
    x2a = arg1 + 0x120;
    y2a = arg2 + 0x89;

    if (x1a <= 0) {
        x1a = 1;
    }
    if (y1a <= 0) {
        y1a = 1;
    }

    if (x2a <= 0 || y2a <= 0 || x1a >= 319 || y1a >= 239) {
        return;
    }

    if (x2a >= 319) {
        x2a = 319;
    }
    if (y2a >= 239) {
        y2a = 239;
    }

    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, x1a, y1a, x2a, y2a);
    draw_box(0, &gPauseWS_21, arg1 + 0x7A, arg2 + 0x10, 0, 166, 121, arg5, arg6, 1.0f, 1.0f, 0, 0, 0, 0, 0, 0, arg3, arg4, 0);
}

void pause_partners_draw_title(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 msgID = gPartnerPopupProperties[D_8024F6B0[D_80270680[D_802706A0]]][0];
    s32 level = get_player_data()->partners[D_8024F6B0[D_80270680[D_802706A0]]].level;
    s32 msgWidth = get_msg_width(msgID, 0);
    s32 offset = 16;

    if (level != 1) {
        offset = 0;
        if (level == 2) {
            offset = 20;
        }
    }

    if (offset != 0) {
        msgWidth += 4;
    }

    draw_msg(msgID, arg1 + ((arg3 - offset - msgWidth) >> 1), arg2 + 1, 0xFF, 0, 0);

    if (level == 1) {
        set_hud_element_render_pos(D_80270640[2], arg1 + 0x5F, arg2 + 0xA);
        draw_hud_element_3(D_80270640[2]);
    } else if (level == 2) {
        set_hud_element_render_pos(D_80270640[2], arg1 + 0x5B, arg2 + 0xA);
        draw_hud_element_3(D_80270640[2]);
        set_hud_element_render_pos(D_80270640[3], arg1 + 0x65, arg2 + 0xA);
        draw_hud_element_3(D_80270640[3]);
    }
}

void pause_partners_draw_movelist(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 i;
    s32 moveNameID;
    s32 costFP;
    s32 msgX, msgY;
    s32 style;
    s32 level = get_player_data()->partners[D_8024F6B0[D_80270680[D_802706A0]]].level;


    if (level == 2) {
        level = 4;
    } else if (level == 1) {
        level = 3;
    } else if (level == 0) {
        level = 2;
    }
    for (i = 0; i < 4; i++) {
        msgX = arg1 + 0x15;
        msgY = arg2 + 0x16 + i * 0xD;

        if (i >= level) {
            continue;
        }

        style = 1;

        if (i == 0) {
            moveNameID = gMoveTable[D_8024F6F0[D_80270680[D_802706A0]]].moveNameID;
        } else {
            moveNameID =  gMoveTable[D_8024F6F0[D_80270680[D_802706A0]] + 2 + i].moveNameID;
        }

        if (i > 0) {
            costFP = gMoveTable[D_8024F6F0[D_80270680[D_802706A0]] + 2 + i].costFP;
        } else {
            costFP = 0;
        }

        draw_msg(moveNameID, msgX, msgY, 255, 10, style);
        set_hud_element_scale(D_80270640[i + 4], 0.5f);
        //TODO find better match
        set_hud_element_render_pos(D_80270640[i + 4], 0xC - (-arg1), arg2 + 0x1C + i * 0xD);
        draw_hud_element_3(D_80270640[i + 4]);

        if (costFP != 0) {
            draw_number(costFP, arg1 + 0x7D, arg2 + 0x16 + i * 0xD, style, 0xA, 0xFF, 3);
            if (costFP > 0) {
                set_hud_element_render_pos(D_80270640[0], arg1 + 0x86, arg2 + 0x1D + i * 0xD);
                draw_hud_element_3(D_80270640[0]);
            }
        }
    }

    if (gPauseMenuCurrentTab == 4 && D_802706AC == 1) {
        pause_set_cursor_pos(0x24, arg1 - 2, arg2 + 0x1C + D_802706A4 * 0xD);
    }
}

void pause_partners_draw_movelist_title(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    draw_msg(pause_get_menu_msg(0x55), arg1 + 12, arg2 + 1, 0xFF, -1, 1);
}

void pause_partners_draw_movelist_flower(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    set_hud_element_render_pos(D_80270640[1], arg1 + 17, arg2 + 16);
    draw_hud_element_3(D_80270640[1]);
}

void pause_partners_init(MenuPanel* panel) {
    s32 i;
    PlayerData* playerData = get_player_data();

    D_802706B0 = 0;
    for (i = 0; i < 8; i++) {
        if (playerData->partners[D_8024F6B0[i]].enabled) {
            D_80270680[D_802706B0] = i;
            D_802706B0++;
        }
    }

    if (D_802706B0 == 0) {
        set_window_update(0x22, 2);
        panel->initialized = FALSE;
        return;
    }

    for (i = 0; i < 8; i++) {
        D_80270660[i] = spr_load_npc_sprite(D_8024F630[i][0], D_8024F630[i]);
    }

    for (i = 0; i < 8; i++) {
        D_80270640[i] = create_hud_element(D_8024F600[i]);
        set_hud_element_flags(D_80270640[i], 0x80);
    }

    for (i = 0; i < 5; i++) {
        D_8024F7C8[i].tab = panel;
    }
    setup_pause_menu_tab(&D_8024F7C8, 5);

    D_802706A0 = 0;
    for (i = 0; i < D_802706B0; i++) {
        if (playerData->currentPartner == D_8024F6B0[D_80270680[i]]) {
            D_802706A0 = i;
            break;
        }
    }

    D_802706A4 = 0;
    D_802706AC = 0;
    D_802706A8 = D_802706A0 * 360 / D_802706B0;
    pause_partners_load_portrait(0);
    panel->initialized = TRUE;
}

void pause_partners_handle_input(MenuPanel* panel) {
    s32 s0;
    s32 level, level2;
    s32 oldPos;

    if (D_802706B0 >= 2 && (D_802706AC == 0 || (gPauseHeldButtons & (BUTTON_Z | BUTTON_R)))) {
        s0 = 0;

        if (gPauseHeldButtons & BUTTON_STICK_LEFT) {
            s0 = -1;
        }

        if (gPauseHeldButtons & BUTTON_STICK_RIGHT) {
            s0++;
        }

        if (gPauseHeldButtons & BUTTON_Z) {
            s0--;
        }

        if (gPauseHeldButtons & BUTTON_R) {
            s0++;
        }

        if (s0) {
            sfx_play_sound(0xC7);
            D_802706A0 += s0;

            if (D_802706A0 < 0) {
                D_802706A0 = D_802706B0 - 1;
                if (D_802706A8 < 360.0f) {
                    D_802706A8 += 360.0f;
                }
            } else if (D_802706A0 >= D_802706B0) {
                D_802706A0 = 0;
                if (D_802706A8 > 0.0f) {
                    D_802706A8 -= 360.0f;
                }
            }

            D_802706A4 = 0;
        }
    }

    level = get_player_data()->partners[D_8024F6B0[D_80270680[D_802706A0]]].level;
    if (level == 2) {
        level = 4;
    } else if (level == 1) {
        level = 3;
    } else if (level == 0) {
        level = 2;
    }

    gWindows[0x24].height = level * 0xD + 0x1E;

    if (D_802706AC == 1) {
        oldPos = D_802706A4;

        level2 = get_player_data()->partners[D_8024F6B0[D_80270680[D_802706A0]]].level;
        if (level2 == 2) {
            level2 = 4;
        } else if (level2 == 1) {
            level2 = 3;
        } else if (level2 == 0) {
            level2 = 2;
        }

        if (gPauseHeldButtons & BUTTON_STICK_UP) {
            D_802706A4--;
        }
        if (gPauseHeldButtons & BUTTON_STICK_DOWN) {
            D_802706A4++;
        }

        if (D_802706A4 < 0) {
            D_802706A4 = level2 - 1;
        } else if (D_802706A4 >= level2) {
            D_802706A4 = 0;
        }

        if (D_802706A4 != oldPos) {
            sfx_play_sound(0xC7);
        }
    }

    if ((gPausePressedButtons & BUTTON_A) && D_802706AC == 0) {
        D_802706AC = 1;
        sfx_play_sound(0xC9);
        set_window_update(0x24, 1);
        return;
    }

    if (gPausePressedButtons & BUTTON_B) {
        if (D_802706AC == 0) {
            gPauseMenuCurrentTab = 0;
            sfx_play_sound(0xCA);
            return;
        } else {
            D_802706AC = 0;
            sfx_play_sound(0xCA);
            set_window_update(0x24, 2);
            return;
        }
    }

    gPauseCurrentDescIconScript = 0;

    if (D_802706AC == 0) {
        gPauseCurrentDescMsg = D_8024F6D0[D_80270680[D_802706A0]];
    } else if (D_802706A4 == 0) {
        gPauseCurrentDescMsg = gMoveTable[D_8024F6F0[D_80270680[D_802706A0]]].menuDescID;
    } else {
        gPauseCurrentDescMsg = gMoveTable[D_8024F6F0[D_80270680[D_802706A0]] + 2 + D_802706A4].menuDescID;
    }
}

void pause_partners_update(MenuPanel* panel) {
    s32 i;
    f32 delta;
    s32 phi_s0;
    f32 f20;
    s32 sgn;

    f20 = D_802706A0 * 360 / D_802706B0 - D_802706A8;
    phi_s0 = abs(f20);
    sgn = sign(f20);

    if (phi_s0 >= 16) {
        delta = f20 * 0.3;
    } else {
        delta = sgn * D_8024F87C[phi_s0];
        D_802706A8 = (int)D_802706A8;
    }
    D_802706A8 += delta;

    for (i = 0; i < D_802706B0; i++) {
        if (i == D_802706A0) {
            spr_update_sprite(D_80270660[D_80270680[i]], D_8024F630[D_80270680[i]][1], 1.0f);
        } else {
            spr_update_sprite(D_80270660[D_80270680[i]], D_8024F630[D_80270680[i]][0], 1.0f);
        }
    }

}

void pause_partners_cleanup(MenuPanel* panel) {
    s32 i;

    for (i = 0; i < 8; i++) {
        free_hud_element(D_80270640[i]);
    }

    for (i = 0; i < 8; i++) {
        spr_free_sprite(D_80270660[i]);
    }
}


