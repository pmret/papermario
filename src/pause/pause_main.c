//#include "common.h"
#include "ld_addrs.h"
#include "sprite.h"
#include "pause_common.h"

#ifndef M2CTX
#define BSS __attribute__ ((section (".bss")))
#else
#define BSS static
#endif

BSS s32 gPauseHeldButtons;
BSS s32 gPausePressedButtons;
BSS s32 gPauseCurrentDescMsg;
BSS HudScript* gPauseCurrentDescIconScript;
BSS s32 gPauseCursorIconID;
BSS s8 gPauseMenuCurrentTab;
BSS s8 D_802700D[7]; //padding

static s32 gPauseTutorialFrameCounter;
static s32 D_802700E4;
static s32 gPauseCommonIconIDs[8];
static s32 gPauseShownDescMsg;
static s32 gPauseDescTextMaxPos;
static s32 gPauseDescTextPos;
static s32 gPauseDescTextOffset;
static HudScript* gPauseShownDescIconScript;
static s32 gPauseTutorialSprites[3];
static s32 D_80270128[2]; // padding

HudScript* gPauseIconScripts[] = {
    HudScript_AnimatedCursorHand, HudScript_DescMsgPrev, HudScript_DescMsgNext, HudScript_UnusedBadge,
    HudScript_StickTapRight, HudScript_PressAButton, HudScript_PressStartButton, HudScript_StartButtonText
};
MenuPanel* gPausePanels[] = {
    &gPausePanelTabs, &gPausePanelStats, &gPausePanelBadges, &gPausePanelItems, &gPausePanelPartners,
    &gPausePanelSpirits, &gPausePanelMap
};
s32 gPauseCursorPosX = 160;
s32 gPauseCursorPosY = -120;
s32 gPauseCursorOpacity = 0;
s32 gPauseCursorTargetPosX = 160;
s32 gPauseCursorTargetPosY = -120;
s32 gPauseCursorTargetOpacity = 0;
u32 D_8024EFB4 = 1;
u32 D_8024EFB8[] = {0xFFF6FFE7, 0xFFD6FFC4, 0xFFB00000 }; //unused
u8 D_8024EFC4[] = { 1, 1, 1, 1, 1, 0, 0};
s16 D_8024EFCC[] = { -80, -65, -38, -30, -10, 0 };
s16 D_8024EFD8[] = {  80,  65,  38,  30,  10, 0 };
u8 D_8024EFE4[] = { 1, 1, 1, 1, 1, 1, 0, 0 };
u8 D_8024EFEC[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x11, 0x00, 0x25, 0x00, 0x3C,
                    0x00, 0x55, 0x00, 0x6E }; //unused
s16 D_8024F000[] = { -10, -25, -42, -60, -80};
s16 D_8024F00C[] = {  10,  25,  42,  60,  80 };
s32 gPauseTutorialState = -1;
s32 gPauseTutorialInputState = 3;
s32 gPauseTutorialButtons[] = { BUTTON_A, BUTTON_STICK_RIGHT, BUTTON_A, BUTTON_A, BUTTON_A, BUTTON_A, BUTTON_START };
s32 gPauseTutorialDescMessages[] = { 9, 10, 11, 12, 13, 14, 15 };
s32 gPauseTutorialCmdMessages[] = { 16, 17, 18, 19, 20, 21, 22 };
s32 D_8024F074[] = { 2, 3, 4, 5, 6, 7, 8 }; // unused
s32 gPauseTutorialIconIDs[] = { 5, 4, 5, 5, 5, 5, 6 };
u8 gPauseMenuTextScrollInterpEasingLUT[] = { 0, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8};
u8 gPauseMenuPageScrollInterpEasingLUT[] = { 0, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8};
s32 gPauseTutorialSpriteAnims[][4] = {
    { 0x009E0000, 0x009E0001, 0x009E000B, 0xFFFFFFFF },
    { 0x00010000, 0x00010001, 0x00010008, 0xFFFFFFFF },
    { 0x009D0000, 0x009D0001, 0x009D0008, 0xFFFFFFFF }
};
Vp gPauseTutorialViewport = {
    .vp = {
        .vscale = { 640, 480, 511, 0 },
        .vtrans = { 640, 480, 511, 0 },
    }
};
s32 D_8024F110 = 0;
MenuWindowBP gPauseCommonWindowsBPs[] = {
  { .windowID = WINDOW_ID_PAUSE_MAIN,
    .unk_01 = 0,
    .pos = { .x = 12, .y = 20 },
    .width = 296,
    .height = 200,
    .unk_0A = { 0, 0 },
    .fpDrawContents = &pause_main_draw_contents,
    .tab = NULL,
    .parentID = WINDOW_ID_NONE,
    .fpUpdate = { 1 },
    .unk_1C = 0x40000000,
    .style = &gPauseWS_0 },

  { .windowID = WINDOW_ID_PAUSE_TUTORIAL,
    .unk_01 = 0,
    .pos = { .x = 0, .y = 138 },
    .width = 296,
    .height = 63,
    .unk_0A = { 0, 0 },
    .fpDrawContents = &pause_tutorial_draw_contents,
    .tab = NULL,
    .parentID = WINDOW_ID_PAUSE_MAIN,
    .fpUpdate = { 2 },
    .unk_1C = 0,
    .style = &gPauseWS_2 },

  { .windowID = WINDOW_ID_PAUSE_DECRIPTION,
    .unk_01 = 0,
    .pos = { .x = 20, .y = 164 },
    .width = 256,
    .height = 32,
    .unk_0A = { 0, 0 },
    .fpDrawContents = &pause_textbox_draw_contents,
    .tab = NULL,
    .parentID = WINDOW_ID_PAUSE_MAIN,
    .fpUpdate = { .func = &basic_window_update },
    .unk_1C = 0,
    .style = &gPauseWS_1 },

  { .windowID = WINDOW_ID_PAUSE_CURSOR,
    .unk_01 = 0,
    .pos = { .x = 0, .y = 0 },
    .width = 320,
    .height = 240,
    .unk_0A = { 0, 0 },
    .fpDrawContents = &pause_cursor_draw_contents,
    .tab = NULL,
    .parentID = WINDOW_ID_NONE,
    .fpUpdate = { 1 },
    .unk_1C = 0,
    .style = &gPauseWS_0 } };

void pause_set_cursor_opacity(s32 val) {
    gPauseCursorTargetOpacity = val;
}

void pause_set_cursor_pos_immediate(s32 windowID, s32 posX, s32 posY) {
    Window* window = &gWindows[windowID];

    if (D_8024EFB4 != 0
            || get_game_mode() == GAME_MODE_END_FILE_SELECT
            || get_game_mode() == GAME_MODE_END_LANGUAGE_SELECT) {
        if (D_8024EFB4 != 0) {
            s32 i;

            for (i = WINDOW_ID_PAUSE_MAIN; i < WINDOW_ID_PAUSE_CURSOR; i++) {
                Window* window = &gWindows[i];
                s8 parent = window->parent;

                if ((parent == WINDOW_ID_NONE || parent == WINDOW_ID_PAUSE_MAIN) && (window->flags & WINDOW_FLAGS_8)) {
                    break;
                }
            }
            if (i >= WINDOW_ID_PAUSE_CURSOR) {
                D_8024EFB4 = 0;
            }
        }
        gPauseCursorTargetPosX = posX;
        gPauseCursorPosX = posX;
        gPauseCursorTargetPosY = posY;
        gPauseCursorPosY = posY;

    } else if ((window->flags & WINDOW_FLAGS_8) == 0 && (window->parent == -1 || !(gWindows[window->parent].flags & WINDOW_FLAGS_8))) {
        gPauseCursorTargetPosX = posX;
        gPauseCursorPosX = posX;
        gPauseCursorTargetPosY = posY;
        gPauseCursorPosY = posY;
    }
}

void pause_set_cursor_pos(s32 windowID, s32 posX, s32 posY) {
    Window* window = &gWindows[windowID];

    if (D_8024EFB4 != 0
            || get_game_mode() == GAME_MODE_END_FILE_SELECT
            || get_game_mode() == GAME_MODE_END_LANGUAGE_SELECT) {
        if (D_8024EFB4 != 0) {
            s32 i;

            for (i = WINDOW_ID_PAUSE_MAIN; i < WINDOW_ID_PAUSE_CURSOR; i++) {
                Window* window = &gWindows[i];
                s8 parent = window->parent;

                if ((parent == -1 || parent == WINDOW_ID_PAUSE_MAIN) && (window->flags & WINDOW_FLAGS_8)) {
                    break;
                }
            }
            if (i >= 44) {
                D_8024EFB4 = 0;
            }
        }
        gPauseCursorTargetPosX = posX;
        gPauseCursorPosX = posX;
        gPauseCursorTargetPosY = posY;
        gPauseCursorPosY = posY;
    } else if ((window->flags & WINDOW_FLAGS_8) == 0 && (window->parent == -1 || !(gWindows[window->parent].flags & WINDOW_FLAGS_8))) {
        gPauseCursorTargetPosX = posX;
        gPauseCursorTargetPosY = posY;
    }
}

void pause_interp_cursor(void) {
    s32 xDelta;
    s32 yDelta;
    s32* opacity;

    xDelta = (gPauseCursorTargetPosX - gPauseCursorPosX) * 0.5;
    yDelta = (gPauseCursorTargetPosY - gPauseCursorPosY) * 0.5;

    if ((gPauseCursorTargetPosX != gPauseCursorPosX) || (gPauseCursorTargetPosY != gPauseCursorPosY)) {
        if ((xDelta == 0) && (yDelta == 0)) {
            gPauseCursorPosX = gPauseCursorTargetPosX;
            gPauseCursorPosY = gPauseCursorTargetPosY;
        }
    }

    gPauseCursorPosX += xDelta;
    gPauseCursorPosY += yDelta;

    if (gPauseCursorTargetOpacity == 0) {
        gPauseCursorOpacity -= 128;
        if (gPauseCursorOpacity < 0) {
            gPauseCursorOpacity = 0;
        }
    } else {
        gPauseCursorOpacity += 32;
        if (gPauseCursorOpacity> 255) {
            gPauseCursorOpacity = 255;
        }
    }
    gPauseCursorTargetOpacity = 255;
}

void pause_update_tab_default(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];

    *darkening = 160;
    window->flags &= ~(WINDOW_FLAGS_4 | WINDOW_FLAGS_8);
}

void func_80242FBC(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];

    *darkening = 160;
    *opacity = 80;
    window->flags &= ~(WINDOW_FLAGS_4 | WINDOW_FLAGS_8);
}

void pause_update_tab_losing_focus(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAGS_4;
    }

    if (updateCounter == 5) {
        update_window_hierarchy(windowIndex, window->unk_02);
    }

    if (updateCounter < 10) {
        *darkening = (updateCounter + 1) * 0x10;
    } else {
        *darkening = 160;
        window->flags &= ~WINDOW_FLAGS_8;
    }
}

void pause_update_tab_getting_focus(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];

    if (window->updateCounter == 0) {
        update_window_hierarchy(windowIndex, window->unk_02);
        *darkening = 0;
        window->flags &= ~WINDOW_FLAGS_8;
    }
}

void func_802430E4(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAGS_4;
    }

    if (updateCounter < 16) {
        *opacity = updateCounter * 0x10;
    } else {
        *opacity = 255;
        window->flags &= ~WINDOW_FLAGS_8;
    }
}

void func_8024313C(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < 16) {
        *opacity = 255 - (updateCounter * 16);
    } else {
        *opacity = 0;
        window->flags = (window->flags & ~WINDOW_FLAGS_8) | WINDOW_FLAGS_4;
    }
}

void func_80243188(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAGS_4;
    }
    if (updateCounter < 7) {
        *flags = D_8024EFC4[updateCounter];
        *rotX += D_8024EFCC[updateCounter]; // BUG!  length of array is only 6
    } else {
        *flags = D_8024EFC4[5];
        *rotX += D_8024EFCC[6]; // BUG!  length of array is only 6
        window->flags &= ~WINDOW_FLAGS_8;
    }
}

void func_80243238(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAGS_4;
    }
    if (updateCounter < 7) {
        *flags = D_8024EFC4[updateCounter];
        *rotX += D_8024EFD8[updateCounter];
    } else {
        *flags = D_8024EFC4[5];
        *rotX += D_8024EFD8[6]; // BUG!  length of array is only 6
        window->flags &= ~WINDOW_FLAGS_8;
    }
}

void func_802432E8(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < 5) {
        *flags = D_8024EFE4[updateCounter];
        *rotX += D_8024F000[updateCounter];
    } else {
        *flags = D_8024EFE4[4];
        *rotX += D_8024F000[4];
        window->flags = (window->flags & ~WINDOW_FLAGS_8) | WINDOW_FLAGS_4;
    }
}

void func_80243388(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, s32* scaleX, s32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < 5) {
        *flags = D_8024EFE4[updateCounter];
        *rotX = D_8024F00C[updateCounter];
    } else {
        *flags = D_8024EFE4[4];
        *rotX = D_8024F00C[4];
        window->flags = (window->flags & ~WINDOW_FLAGS_8) | WINDOW_FLAGS_4;
    }
}

s32 pause_interp_text_scroll(s32 deltaBefore) {
    s32 val;
    s32 db = abs(deltaBefore);
    s32 s = sign(deltaBefore);

    if (db >= 16) {
        val = 8;
    } else {
        val = gPauseMenuTextScrollInterpEasingLUT[db];
    }

    return val * s;
}

s32 pause_interp_vertical_scroll(s32 deltaBefore) {
    s32 val;
    s32 db = abs(deltaBefore);
    s32 s = sign(deltaBefore);

    if (db >= 16) {
        val = db / 2;
        if (val > 20) {
            val = 20;
        }
    } else {
        val = gPauseMenuPageScrollInterpEasingLUT[db];
    }

    return val * s;
}

void pause_cursor_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 currentOpacity;

    pause_interp_cursor();
    currentOpacity = gPauseCursorOpacity;
    if (currentOpacity > 0) {
        if (currentOpacity > 255) {
            currentOpacity = 255;
        }
        set_hud_element_alpha(gPauseCommonIconIDs[0], currentOpacity);
        set_hud_element_render_pos(gPauseCommonIconIDs[0], baseX + gPauseCursorPosX, baseY + gPauseCursorPosY);
        draw_hud_element_3(gPauseCommonIconIDs[0]);
    }
}

void pause_main_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
}

void pause_textbox_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 msgID = gPauseShownDescMsg;

    if (msgID == 0)
        return;

    if (gPauseDescTextPos != 0) {
        set_hud_element_render_pos(gPauseCommonIconIDs[1], baseX + width - 4, baseY + 4);
        draw_hud_element_3(gPauseCommonIconIDs[1]);
    }

    if (gPauseDescTextPos < gPauseDescTextMaxPos) {
        set_hud_element_render_pos(gPauseCommonIconIDs[2], baseX + width - 4, baseY + height - 4);
        draw_hud_element_3(gPauseCommonIconIDs[2]);
    }

    gDPPipeSync(gMasterGfxPos++);
    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, baseX + 1, baseY + 1, baseX + width - 1, baseY + height - 1);
    draw_msg(msgID, baseX + 10, baseY - gPauseDescTextOffset, 255, 10, 0);
    if (gPauseShownDescIconScript != 0) {
        gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        set_hud_element_render_pos(gPauseCommonIconIDs[3], baseX - 4, baseY + 16);
        set_hud_element_anim(gPauseCommonIconIDs[3], gPauseShownDescIconScript);
        set_hud_element_flags(gPauseCommonIconIDs[3], 0x20000000);
        clear_hud_element_flags(gPauseCommonIconIDs[3], 0x8000);
        set_hud_element_scale(gPauseCommonIconIDs[3], 1.0f);
        draw_hud_element_3(gPauseCommonIconIDs[3]);
    }
}

void pause_tutorial_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    Matrix4f sp28;
    Matrix4f sp68;
    f32 (*psp68)[4];
    s32 msgHeight;
    s32 msgWidth;
    s32 msgMaxLineChars;
    s32 msgNumLines;
    s32 msgMaxLinesPerPage;
    s32 msgHeight2;
    u32 msgWidth2;
    s32 msgMaxLineChars2;
    s32 msgNumLines2;
    s32 msgMaxLinesPerPage2;
    s32 i;
    s32 margin, margin2;
    s32 temp_s2;

    if (evt_get_variable(NULL, EVT_SAVE_FLAG(94)) == 0)
        return;

    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gDPSetCombineMode(gMasterGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0x37, 0x37, 0x37, 0xFF);
    pause_draw_rect(baseX * 4, baseY * 4, (baseX + width) * 4, (baseY + 12) * 4, 0, 0, 0, 0, 0);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0xB9, 0xB9, 0xB9, 0xFF);
    pause_draw_rect(baseX * 4, (baseY + 12) * 4, (baseX + width) * 4, (baseY + height) * 4, 0, 0, 0, 0, 0);
    gDPPipeSync(gMasterGfxPos++);
    gSPViewport(gMasterGfxPos++, &gPauseTutorialViewport);
    guOrthoF(sp28, 0.0f, 320.0f, 240.0f, 0.0f, -100.0f, 100.0f, 1.0f);
    guMtxF2L(sp28, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    for (i = 0; i < 3; i++) {
        psp68 = sp68;
        switch (i) {
            case 0:
                guTranslateF(sp28, 40.0f, 223.0f, 0);
                guScaleF(psp68, -0.8f, 0.8f, 1.0f);
                break;
            case 1:
                guTranslateF(sp28, 60.0f, 223.0f, 0);
                guScaleF(psp68, -0.8f, 0.8f, 1.0f);
                break;
            default:
                guTranslateF(sp28, 280.0f, 223.0f, 0);
                guScaleF(psp68, 0.8f, 0.8f, 1.0f);
                break;
        }

        guMtxCatF(psp68, sp28, sp28);
        guRotateF(psp68, 180.0f, 0.0f, 0.0f, 1.0f);
        guMtxCatF(psp68, sp28, sp28);
        guRotateF(psp68, 180.0f, 0.0f, 1.0f, 0.0f);
        guMtxCatF(psp68, sp28, sp28);
        guMtxF2L(sp28, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        func_802DE894(gPauseTutorialSprites[i], 6, 255, 255, 255, 255, 64);
        spr_draw_npc_sprite(gPauseTutorialSprites[i], 0, 0, 0, sp28);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }

    get_msg_properties(pause_get_menu_msg(1), &msgHeight, &msgWidth, &msgMaxLineChars, &msgNumLines, &msgMaxLinesPerPage, NULL, 1);
    margin = (s32)(width - msgWidth) >> 1;
    draw_msg(pause_get_menu_msg(1), baseX + margin, baseY, 0xFF, 0, 1);
    D_8024F110 += pause_interp_text_scroll(gPauseTutorialState * 140 - D_8024F110);
    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, baseX + 1, baseY + 1, baseX + width - 1, baseY + height - 1);
    temp_s2 = gPauseTutorialState;
    get_msg_properties(pause_get_menu_msg(gPauseTutorialDescMessages[temp_s2]), &msgHeight2, &msgWidth2, &msgMaxLineChars2, &msgNumLines2, &msgMaxLinesPerPage2, NULL, 1);
    margin2 = (s32)(width - msgWidth2) >> 1;
    draw_msg(pause_get_menu_msg(gPauseTutorialDescMessages[temp_s2]), baseX + margin2, baseY + 13 + temp_s2 * 140 - D_8024F110, 0xFF, 10, 1);
    set_hud_element_render_pos(gPauseCommonIconIDs[gPauseTutorialIconIDs[gPauseTutorialState]], baseX + width / 2 - 2, baseY + 52);
    set_hud_element_flags(gPauseCommonIconIDs[gPauseTutorialIconIDs[gPauseTutorialState]], 0x8000);
    set_hud_element_scale(gPauseCommonIconIDs[gPauseTutorialIconIDs[gPauseTutorialState]], 0.5f);
    draw_hud_element_3(gPauseCommonIconIDs[gPauseTutorialIconIDs[gPauseTutorialState]]);

    if (gPauseTutorialIconIDs[gPauseTutorialState] == 6) {
        set_hud_element_render_pos(gPauseCommonIconIDs[7], baseX + width / 2 + 1, baseY + 50);
        draw_hud_element_3(gPauseCommonIconIDs[7]);
    }

    draw_msg(pause_get_menu_msg(gPauseTutorialCmdMessages[gPauseTutorialState]), baseX + width / 2 + 10, baseY + 44, 0xFF, 10, 0);
}

void pause_init(void) {
    s32 i;
    s32 posX;
    s32 x;
    Window* pauseWindows;
    MenuPanel** menuPanels;

    dma_copy(_131340_ROM_START, _131340_ROM_END, _131340_VRAM);

    for (i = 0; i < ARRAY_COUNT(gPauseIconScripts); i++) {
        gPauseCommonIconIDs[i] = create_hud_element(gPauseIconScripts[i]);
        if (gPauseIconScripts[i] == HudScript_AnimatedCursorHand) {
            set_hud_element_flags(gPauseCommonIconIDs[i], 0x20000080);
        } else {
            set_hud_element_flags(gPauseCommonIconIDs[i], 0x80);
        }
    }

    gPauseCursorIconID = gPauseCommonIconIDs[0];
    setup_pause_menu_tab(gPauseCommonWindowsBPs, ARRAY_COUNT(gPauseCommonWindowsBPs));
    gPauseShownDescMsg = 0;
    gPauseDescTextPos = 0;
    gPauseDescTextOffset = 0;
    gPauseDescTextMaxPos = 0;
    gPauseShownDescIconScript = 0;
    gPauseCurrentDescMsg = 0;
    gPauseCurrentDescIconScript = 0;
    gPauseMenuCurrentTab = 0;

    menuPanels = gPausePanels;
    for (i = 0; i < ARRAY_COUNT(gPausePanels); menuPanels++, i++) {
        if ((*menuPanels)->fpInit) {
            (*menuPanels)->fpInit(*menuPanels);
        }
    }

    posX = 225;
    for (i = 6; i > 0; i--) {
        if (!gPausePanels[i]->initialized) {
            set_window_update(24 + i, 2);
        } else {
            gWindows[24 + i].pos.x = posX + 14;
            posX -= 45;
        }
    }
    pauseWindows = &gWindows[25];
    x = pauseWindows[gPausePanels[0]->col].pos.x;
    gWindows[43].pos.x = x + 6;

    if (evt_get_variable(NULL, EVT_SAVE_FLAG(94)) != 0) {
        for (i = 0; i < 3; i++) {
            gPauseTutorialSprites[i] = spr_load_npc_sprite(gPauseTutorialSpriteAnims[i][0], gPauseTutorialSpriteAnims[i]);
        }

        set_window_update(24, 1);
        sfx_play_sound(9);
    }

    update_window_hierarchy(WINDOW_ID_PAUSE_CURSOR, 0x40);
}

void pause_tutorial_input(s32 *pressed, s32 *held) {
    s32 pressedOld = *pressed;
    s32 pressedNew = *pressed;
    s32 heldNew = *held;

    switch (gPauseTutorialInputState) {
    case 0:
        heldNew = pressedNew = pressedNew & gPauseTutorialButtons[gPauseTutorialState];
        if (pressedNew) {
            gPauseTutorialInputState = 1;
        }
        if (pressedOld && pressedNew == 0) {
            sfx_play_sound(541);
        }
        if (gPauseTutorialState == 0) {
            pressedNew = 0;
            heldNew = 0;
        }
        break;
    case 1:
        gPauseTutorialFrameCounter = 0;
        gPauseTutorialInputState = 2;
        pressedNew = 0;
        heldNew = 0;
        break;
    case 2:
        if (--gPauseTutorialFrameCounter <= 0) {
            gPauseTutorialInputState = 3;
        }
        pressedNew = 0;
        heldNew = 0;
        break;
    case 3:
        gPauseTutorialFrameCounter = 16;
        gPauseTutorialInputState = 4;
        gPauseTutorialState += 1;
        pressedNew = 0;
        heldNew = 0;
        break;
    case 4:
        if (--gPauseTutorialFrameCounter <= 0) {
            gPauseTutorialInputState = 0;
        }
        pressedNew = 0;
        heldNew = 0;
        break;
    }

    *pressed = pressedNew;
    *held = heldNew;
}



void pause_handle_input(s32 pressed, s32 held) {
    s32 height;
    s32 width;
    s32 maxLineChars;
    s32 numLines;
    s32 i,j;
    MenuPanel** menuPanels;
    s32 currentDescMsg = gPauseCurrentDescMsg;
    MenuPanel* currentPanel = gPausePanels[gPauseMenuCurrentTab];

    if (evt_get_variable(NULL, EVT_SAVE_FLAG(94)) != 0) {
        for (i = 0; i < 3; i++) {
            spr_update_sprite(gPauseTutorialSprites[i], gPauseTutorialSpriteAnims[i][1], 1.0f);
        }
    }

    gPausePressedButtons = pressed;
    gPauseHeldButtons = held;
    if (evt_get_variable(NULL, EVT_SAVE_FLAG(94)) != 0) {
        pause_tutorial_input(&gPausePressedButtons, &gPauseHeldButtons);
    }

    if ((gPausePressedButtons & BUTTON_START) || (gPauseMenuCurrentTab == 0) && (gPausePressedButtons & BUTTON_B)) {
        enforce_hpfp_limits();
        sfx_play_sound(198);
        set_game_mode(GAME_MODE_UNPAUSE);
        return;
    }

    if (gPauseCurrentDescIconScript != gPauseShownDescIconScript) {
        gPauseShownDescIconScript = gPauseCurrentDescIconScript;
    }

    if (currentDescMsg != gPauseShownDescMsg) {
        gPauseShownDescMsg = currentDescMsg;
        gPauseDescTextPos = 0;
        gPauseDescTextOffset = 0;
        if (currentDescMsg != 0) {
            get_msg_properties(currentDescMsg, &height, &width, &maxLineChars, &numLines, NULL, NULL, 0);
            if (numLines % 2) {
                numLines++;
            }
            gPauseDescTextMaxPos = numLines - 2;
            if (gPauseDescTextMaxPos < 0) {
                gPauseDescTextMaxPos = 0;
            }
        } else {
            gPauseDescTextMaxPos = 0;
        }
    }
    if (gPauseHeldButtons & BUTTON_C_UP) {
        gPauseDescTextPos -= 2;
        if (gPauseDescTextPos < 0) {
            gPauseDescTextPos = 0;
        }
    }
    if (gPauseHeldButtons & BUTTON_C_DOWN) {
        gPauseDescTextPos += 2;
        if (gPauseDescTextPos > gPauseDescTextMaxPos) {
            gPauseDescTextPos = gPauseDescTextMaxPos;
        }
    }
    gPauseDescTextOffset += pause_interp_text_scroll(gPauseDescTextPos * 16 - gPauseDescTextOffset);
    if (currentPanel->initialized) {
        if (currentPanel->fpHandleInput) {
            currentPanel->fpHandleInput(currentPanel);
        }
    }
    menuPanels = gPausePanels;
    for (i = 0; i < 7; menuPanels++, i++) {
        if ((*menuPanels)->initialized) {
            if ((*menuPanels)->fpUpdate) {
                (*menuPanels)->fpUpdate(*menuPanels);
            }
        }
    }
}

void pause_cleanup(void) {
    s32 i;
    MenuPanel** menuPanels;

    for (i = 0; i < 8; i++) {
        free_hud_element(gPauseCommonIconIDs[i]);
    }

    if (evt_get_variable(NULL, EVT_SAVE_FLAG(94)) != 0) {
        for (i = 0; i < 3; i++) {
            spr_free_sprite(gPauseTutorialSprites[i]);
        }
    }

    menuPanels = gPausePanels;
    for (i = 0; i < 7; menuPanels++, i++) {
        if ((*menuPanels)->initialized) {
            if ((*menuPanels)->fpCleanup) {
                (*menuPanels)->fpCleanup(*menuPanels);
            }
        }
    }

    for (i = WINDOW_ID_PAUSE_MAIN; i < WINDOW_ID_PAUSE_CURSOR; i++)
        set_window_update(i, 2);

    set_window_update(WINDOW_ID_PAUSE_CURSOR, 2);
}

const f32 rodata_padding[] = {0.0f, 0.0f, 0.0f};

s32 pause_get_total_equipped_bp_cost(void) {
    s32 totalCost = 0;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPlayerData.equippedBadges); i++) {
        s16 itemID = gPlayerData.equippedBadges[i];

        if (itemID != ITEM_NONE) {
            s32 moveID = gItemTable[itemID].moveID;

            totalCost += gMoveTable[moveID].costBP;
        }
    }
    return totalCost;
}

void pause_draw_rect(s32 ulx, s32 uly, s32 lrx, s32 lry, s32 tileDescriptor, s32 uls, s32 ult, s32 dsdx, s32 dtdy) {
    if (ulx <= -2688 || uly <= -2688 || lrx <= 0 || lry <= 0) {
        return;
    }
    if (ulx >= 1280 || uly >= 960 || lrx >= 2688 || lry >= 2688) {
        return;
    }
    gSPScisTextureRectangle(gMasterGfxPos++, ulx, uly, lrx, lry, tileDescriptor, uls, ult, dsdx, dtdy);
}

void pause_sort_item_list(s16* arr, s32 len, s32 (*compare)(s16*, s16 *)) {
    if (len < 2) {
        // Trivially sorted
        return;
    } else if (len == 2) {
        // Trivial 2-element sort
        if (compare(&arr[0], &arr[1]) > 0) {
            s16 temp = arr[0];
            arr[0] = arr[1];
            arr[1] = temp;
        }
        return;
    } else {
        // Nontrivial sort required, use shell sort
        u32 gap = 1;
        s16* end;

        while (gap < len) {
            gap = gap * 2 + 1;
        }

        end = &arr[len];
        while ((gap /= 2) != 0) {
            s16* window_end;

            for (window_end = &arr[gap]; window_end < end; window_end++) {
                s16* cur_elem = window_end - gap;

                // This could be written simpler as a while loop, but the compiler figures out that it only needs to do
                // the "cur_elem < end" check on the first iteration in that case
                if (cur_elem >= arr && cur_elem < end) {
                    do {
                        s16* elem_a = cur_elem;
                        s16* elem_b = cur_elem + gap;

                        if (compare(elem_a, elem_b) > 0) {
                            s16 temp = *elem_a;
                            *elem_a = *elem_b;
                            *elem_b = temp;
                            cur_elem -= gap;
                        } else {
                            break;
                        }
                    } while (cur_elem >= arr && cur_elem < end);
                }
            }
        }
    }
}
