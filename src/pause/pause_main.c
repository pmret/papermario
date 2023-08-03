#include "ld_addrs.h"
#include "message_ids.h"
#include "sprite.h"
#include "pause_common.h"
#include "sprite/npc/Goombaria.h"
#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/Goompa.h"

extern MenuPanel gPausePanelTabs;
extern MenuPanel gPausePanelStats;
extern MenuPanel gPausePanelBadges;
extern MenuPanel gPausePanelItems;
extern MenuPanel gPausePanelPartners;
extern MenuPanel gPausePanelSpirits;
extern MenuPanel gPausePanelMap;

void pause_tutorial_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_main_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_textbox_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void pause_draw_cursor(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);

BSS s32 gPauseHeldButtons;
BSS s32 gPausePressedButtons;
BSS s32 gPauseCurrentDescMsg;
BSS HudScript* gPauseCurrentDescIconScript;
BSS s32 gPauseCursorIconID;
BSS s8 gPauseMenuCurrentTab;
BSS s8 D_802700D[7]; //padding

static s32 gPauseTutorialFrameCounter;
#if !VERSION_IQUE
static s32 D_802700E4;
#endif
static s32 gPauseCommonIconIDs[8];
static s32 gPauseShownDescMsg;
static s32 gPauseDescTextMaxPos;
static s32 gPauseDescTextPos;
static s32 gPauseDescTextOffset;
static HudScript* gPauseShownDescIconScript;
static s32 gPauseTutorialSprites[3];

static HudScript* gPauseIconScripts[] = {
    &HES_AnimatedCursorHand, &HES_DescMsgPrev, &HES_DescMsgNext, &HES_UnusedBadge,
    &HES_StickTapRight, &HES_PressAButton, &HES_PressStartButton, &HES_StartButtonText
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
s16 D_8024EFB8[] = { -10, -25, -42, -60, -80 }; //unused
u8 gPauseWindowFlipUpFlags[] = { DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE, 0, 0};
s16 gPauseWindowFlipUpAngles[] = { -80, -65, -38, -30, -10, 0 };
s16 gPauseWindowFlipUpAngles_2[] = {  80,  65,  38,  30,  10, 0 };
u8 gPauseWindowFlipDownFlags[] = { DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE, DRAW_FLAG_ROTSCALE, 0, 0 };
u8 D_8024EFEC[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x11, 0x00, 0x25, 0x00, 0x3C,
                    0x00, 0x55, 0x00, 0x6E }; //unused
s16 gPauseWindowFlipDownAngles[] = { -10, -25, -42, -60, -80};
s16 gPauseWindowFlipDownAngles_2[] = {  10,  25,  42,  60,  80 };
s32 gPauseTutorialState = -1;
s32 gPauseTutorialInputState = 3;
s32 gPauseTutorialButtons[] = { BUTTON_A, BUTTON_STICK_RIGHT, BUTTON_A, BUTTON_A, BUTTON_A, BUTTON_A, BUTTON_START };

s32 gPauseTutorialDescMessages[] = {
    PAUSE_MSG_TUT_DESC_1,
    PAUSE_MSG_TUT_DESC_2,
    PAUSE_MSG_TUT_DESC_3,
    PAUSE_MSG_TUT_DESC_4,
    PAUSE_MSG_TUT_DESC_5,
    PAUSE_MSG_TUT_DESC_6,
    PAUSE_MSG_TUT_DESC_7,
};

s32 gPauseTutorialCmdMessages[] = {
    PAUSE_MSG_TUT_CMD_1,
    PAUSE_MSG_TUT_CMD_2,
    PAUSE_MSG_TUT_CMD_3,
    PAUSE_MSG_TUT_CMD_4,
    PAUSE_MSG_TUT_CMD_5,
    PAUSE_MSG_TUT_CMD_6,
    PAUSE_MSG_TUT_CMD_7,
};

 // unused
s32 D_8024F074[] = {
    PAUSE_MSG_TUT_UNUSED_1,
    PAUSE_MSG_TUT_UNUSED_2,
    PAUSE_MSG_TUT_UNUSED_3,
    PAUSE_MSG_TUT_UNUSED_4,
    PAUSE_MSG_TUT_UNUSED_5,
    PAUSE_MSG_TUT_UNUSED_6,
    PAUSE_MSG_TUT_UNUSED_7,
};

s32 gPauseTutorialIconIDs[] = { 5, 4, 5, 5, 5, 5, 6 };
u8 gPauseMenuTextScrollInterpEasingLUT[] = { 0, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8};
u8 gPauseMenuPageScrollInterpEasingLUT[] = { 0, 1, 2, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8};

s32 gPauseTutorialSpriteAnims[][4] = {
    {
        ANIM_Goombaria_Still,
        ANIM_Goombaria_Idle,
        ANIM_Goombaria_Talk,
        ANIM_LIST_END
    },
    {
        ANIM_WorldGoombario_Still,
        ANIM_WorldGoombario_Idle,
        ANIM_WorldGoombario_Talk,
        ANIM_LIST_END
    },
    {
        ANIM_Goompa_Still,
        ANIM_Goompa_Idle,
        ANIM_Goompa_Talk,
        ANIM_LIST_END
    }
};
Vp gPauseTutorialViewport = {
    .vp = {
        .vscale = { 640, 480, 511, 0 },
        .vtrans = { 640, 480, 511, 0 },
    }
};
s32 gPauseTutorialScrollPos = 0;
MenuWindowBP gPauseCommonWindowsBPs[] = {
    {
        .windowID = WINDOW_ID_PAUSE_MAIN,
        .unk_01 = 0,
        .pos = { .x = 12, .y = 20 },
        .width = 296,
        .height = 200,
        .priority = 0,
        .fpDrawContents = &pause_main_draw_contents,
        .tab = NULL,
        .parentID = WINDOW_ID_NONE,
        .fpUpdate = { WINDOW_UPDATE_SHOW },
        .extraFlags = WINDOW_FLAG_40,
        .style = { .customStyle = &gPauseWS_0 }
    },
    {
        .windowID = WINDOW_ID_PAUSE_TUTORIAL,
        .unk_01 = 0,
        .pos = { .x = 0, .y = 138 },
        .width = 296,
        .height = 63,
        .priority = 0,
        .fpDrawContents = &pause_tutorial_draw_contents,
        .tab = NULL,
        .parentID = WINDOW_ID_PAUSE_MAIN,
        .fpUpdate = { WINDOW_UPDATE_HIDE },
        .extraFlags = 0,
        .style = { .customStyle = &gPauseWS_2 }
    },
    {
        .windowID = WINDOW_ID_PAUSE_DECRIPTION,
        .unk_01 = 0,
        .pos = { .x = 20, .y = 164 },
        .width = 256,
        .height = 32,
        .priority = 0,
        .fpDrawContents = &pause_textbox_draw_contents,
        .tab = NULL,
        .parentID = WINDOW_ID_PAUSE_MAIN,
        .fpUpdate = { .func = &basic_window_update },
        .extraFlags = 0,
        .style = { .customStyle = &gPauseWS_1 }
    },
    {
        .windowID = WINDOW_ID_PAUSE_CURSOR,
        .unk_01 = 0,
        .pos = { .x = 0, .y = 0 },
        .width = SCREEN_WIDTH,
        .height = SCREEN_HEIGHT,
        .priority = 0,
        .fpDrawContents = &pause_draw_cursor,
        .tab = NULL,
        .parentID = WINDOW_ID_NONE,
        .fpUpdate = { WINDOW_UPDATE_SHOW },
        .extraFlags = 0,
        .style = { .customStyle = &gPauseWS_0 }
    }
};

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

                if ((parent == WINDOW_ID_NONE || parent == WINDOW_ID_PAUSE_MAIN) && (window->flags & WINDOW_FLAG_INITIAL_ANIMATION)) {
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

    } else if ((window->flags & WINDOW_FLAG_INITIAL_ANIMATION) == 0 && (window->parent == -1 || !(gWindows[window->parent].flags & WINDOW_FLAG_INITIAL_ANIMATION))) {
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

                if ((parent == -1 || parent == WINDOW_ID_PAUSE_MAIN) && (window->flags & WINDOW_FLAG_INITIAL_ANIMATION)) {
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
    } else if ((window->flags & WINDOW_FLAG_INITIAL_ANIMATION) == 0 && (window->parent == -1 || !(gWindows[window->parent].flags & WINDOW_FLAG_INITIAL_ANIMATION))) {
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

void pause_update_tab_default(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];

    *darkening = 160;
    window->flags &= ~(WINDOW_FLAG_HIDDEN | WINDOW_FLAG_INITIAL_ANIMATION);
}

void func_80242FBC(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];

    *darkening = 160;
    *opacity = 80;
    window->flags &= ~(WINDOW_FLAG_HIDDEN | WINDOW_FLAG_INITIAL_ANIMATION);
}

void pause_update_tab_inactive(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAG_HIDDEN;
    }

    if (updateCounter == 5) {
        update_window_hierarchy(windowIndex, window->originalPriority);
    }

    if (updateCounter < 10) {
        *darkening = (updateCounter + 1) * 16;
    } else {
        *darkening = 160;
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void pause_update_tab_active(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];

    if (window->updateCounter == 0) {
        update_window_hierarchy(windowIndex, window->originalPriority);
        *darkening = 0;
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void func_802430E4(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAG_HIDDEN;
    }

    if (updateCounter < 16) {
        *opacity = updateCounter * 16;
    } else {
        *opacity = 255;
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void func_8024313C(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < 16) {
        *opacity = 255 - (updateCounter * 16);
    } else {
        *opacity = 0;
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAG_HIDDEN;
    }
}

void pause_update_page_active_2(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAG_HIDDEN;
    }
    if (updateCounter < 7) {
        *flags = gPauseWindowFlipUpFlags[updateCounter];
        *rotX += gPauseWindowFlipUpAngles[updateCounter];
    } else {
        *flags = gPauseWindowFlipUpFlags[5];
        *rotX += gPauseWindowFlipUpAngles[6];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void pause_update_page_active_1(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAG_HIDDEN;
    }
    if (updateCounter < 7) {
        *flags = gPauseWindowFlipUpFlags[updateCounter];
        *rotX += gPauseWindowFlipUpAngles_2[updateCounter];
    } else {
        *flags = gPauseWindowFlipUpFlags[5];
        *rotX += gPauseWindowFlipUpAngles_2[6];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void pause_update_page_inactive_1(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < 5) {
        *flags = gPauseWindowFlipDownFlags[updateCounter];
        *rotX += gPauseWindowFlipDownAngles[updateCounter];
    } else {
        *flags = gPauseWindowFlipDownFlags[4];
        *rotX += gPauseWindowFlipDownAngles[4];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAG_HIDDEN;
    }
}

void pause_update_page_inactive_2(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                   f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity) {
    Window* window = &gWindows[windowIndex];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < 5) {
        *flags = gPauseWindowFlipDownFlags[updateCounter];
        *rotX = gPauseWindowFlipDownAngles_2[updateCounter];
    } else {
        *flags = gPauseWindowFlipDownFlags[4];
        *rotX = gPauseWindowFlipDownAngles_2[4];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAG_HIDDEN;
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

void pause_draw_cursor(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 currentOpacity;

    pause_interp_cursor();
    currentOpacity = gPauseCursorOpacity;
    if (currentOpacity > 0) {
        if (currentOpacity > 255) {
            currentOpacity = 255;
        }
        hud_element_set_alpha(gPauseCommonIconIDs[0], currentOpacity);
        hud_element_set_render_pos(gPauseCommonIconIDs[0], baseX + gPauseCursorPosX, baseY + gPauseCursorPosY);
        hud_element_draw_without_clipping(gPauseCommonIconIDs[0]);
    }
}

void pause_main_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
}

void pause_textbox_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 msgID = gPauseShownDescMsg;

    if (msgID == MSG_NONE) {
        return;
    }

    if (gPauseDescTextPos != 0) {
        hud_element_set_render_pos(gPauseCommonIconIDs[1], baseX + width - 4, baseY + 4);
        hud_element_draw_without_clipping(gPauseCommonIconIDs[1]);
    }

    if (gPauseDescTextPos < gPauseDescTextMaxPos) {
        hud_element_set_render_pos(gPauseCommonIconIDs[2], baseX + width - 4, baseY + height - 4);
        hud_element_draw_without_clipping(gPauseCommonIconIDs[2]);
    }

    gDPPipeSync(gMainGfxPos++);
    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, baseX + 1, baseY + 1, baseX + width - 1, baseY + height - 1);
    draw_msg(msgID, baseX + 10, baseY - gPauseDescTextOffset, 255, MSG_PAL_STANDARD, 0);
    if (gPauseShownDescIconScript != 0) {
        gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        hud_element_set_render_pos(gPauseCommonIconIDs[3], baseX - 4, baseY + 16);
        hud_element_set_script(gPauseCommonIconIDs[3], gPauseShownDescIconScript);
        hud_element_set_flags(gPauseCommonIconIDs[3], HUD_ELEMENT_FLAG_DROP_SHADOW);
        hud_element_clear_flags(gPauseCommonIconIDs[3], HUD_ELEMENT_FLAG_FILTER_TEX);
        hud_element_set_scale(gPauseCommonIconIDs[3], 1.0f);
        hud_element_draw_without_clipping(gPauseCommonIconIDs[3]);
    }
}

void pause_tutorial_draw_contents(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    Matrix4f matrix1;
    Matrix4f matrix2;
    f32 (*matrix2ptr)[4];
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
    s32 state;

    if (evt_get_variable(NULL, GF_Tutorial_Badges) == FALSE) {
        return;
    }

    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gDPSetCombineMode(gMainGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 55, 55, 55, 255);
    pause_draw_rect(baseX * 4, baseY * 4, (baseX + width) * 4, (baseY + 12) * 4, 0, 0, 0, 0, 0);
    gDPPipeSync(gMainGfxPos++);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 185, 185, 185, 255);
    pause_draw_rect(baseX * 4, (baseY + 12) * 4, (baseX + width) * 4, (baseY + height) * 4, 0, 0, 0, 0, 0);
    gDPPipeSync(gMainGfxPos++);
    gSPViewport(gMainGfxPos++, &gPauseTutorialViewport);
    guOrthoF(matrix1, 0.0f, 320.0f, 240.0f, 0.0f, -100.0f, 100.0f, 1.0f);
    guMtxF2L(matrix1, &gDisplayContext->matrixStack[gMatrixListPos]);
    gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);

    for (i = 0; i < 3; i++) {
        //needed to match
        matrix2ptr = matrix2;
        switch (i) {
            case 0:
                guTranslateF(matrix1, 40.0f, 223.0f, 0);
                guScaleF(matrix2ptr, -0.8f, 0.8f, 1.0f);
                break;
            case 1:
                guTranslateF(matrix1, 60.0f, 223.0f, 0);
                guScaleF(matrix2ptr, -0.8f, 0.8f, 1.0f);
                break;
            default:
                guTranslateF(matrix1, 280.0f, 223.0f, 0);
                guScaleF(matrix2ptr, 0.8f, 0.8f, 1.0f);
                break;
        }

        guMtxCatF(matrix2ptr, matrix1, matrix1);
        guRotateF(matrix2ptr, 180.0f, 0.0f, 0.0f, 1.0f);
        guMtxCatF(matrix2ptr, matrix1, matrix1);
        guRotateF(matrix2ptr, 180.0f, 0.0f, 1.0f, 0.0f);
        guMtxCatF(matrix2ptr, matrix1, matrix1);
        guMtxF2L(matrix1, &gDisplayContext->matrixStack[gMatrixListPos]);
        gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++], G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        set_npc_imgfx_all(gPauseTutorialSprites[i], IMGFX_SET_COLOR, 255, 255, 255, 255, 64);
        spr_draw_npc_sprite(gPauseTutorialSprites[i], 0, 0, 0, matrix1);
        gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
    }

    get_msg_properties(pause_get_menu_msg(PAUSE_MSG_TUT_NAME_BADGES), &msgHeight, &msgWidth, &msgMaxLineChars, &msgNumLines, &msgMaxLinesPerPage, NULL, 1);
    margin = (s32)(width - msgWidth) >> 1;
    draw_msg(pause_get_menu_msg(PAUSE_MSG_TUT_NAME_BADGES), baseX + margin, baseY, 255, MSG_PAL_WHITE, DRAW_MSG_STYLE_MENU);
    gPauseTutorialScrollPos += pause_interp_text_scroll(gPauseTutorialState * 140 - gPauseTutorialScrollPos);
    gDPSetScissor(gMainGfxPos++, G_SC_NON_INTERLACE, baseX + 1, baseY + 1, baseX + width - 1, baseY + height - 1);
    state = gPauseTutorialState;
    get_msg_properties(pause_get_menu_msg(gPauseTutorialDescMessages[state]), &msgHeight2, &msgWidth2, &msgMaxLineChars2, &msgNumLines2, &msgMaxLinesPerPage2, NULL, 1);
    margin2 = (s32)(width - msgWidth2) >> 1;
    draw_msg(pause_get_menu_msg(gPauseTutorialDescMessages[state]), baseX + margin2, baseY + 13 + state * 140 - gPauseTutorialScrollPos, 255, MSG_PAL_STANDARD, DRAW_MSG_STYLE_MENU);
    hud_element_set_render_pos(gPauseCommonIconIDs[gPauseTutorialIconIDs[gPauseTutorialState]], baseX + width / 2 - 2, baseY + 52);
    hud_element_set_flags(gPauseCommonIconIDs[gPauseTutorialIconIDs[gPauseTutorialState]], HUD_ELEMENT_FLAG_FILTER_TEX);
    hud_element_set_scale(gPauseCommonIconIDs[gPauseTutorialIconIDs[gPauseTutorialState]], 0.5f);
    hud_element_draw_without_clipping(gPauseCommonIconIDs[gPauseTutorialIconIDs[gPauseTutorialState]]);

    if (gPauseTutorialIconIDs[gPauseTutorialState] == 6) {
        hud_element_set_render_pos(gPauseCommonIconIDs[7], baseX + width / 2 + 1, baseY + 50);
        hud_element_draw_without_clipping(gPauseCommonIconIDs[7]);
    }

    draw_msg(pause_get_menu_msg(gPauseTutorialCmdMessages[gPauseTutorialState]), baseX + width / 2 + 10, baseY + 44, 255, MSG_PAL_STANDARD, 0);
}

void pause_init(void) {
    s32 posX;
    s32 x;
    Window* pauseWindows;
    MenuPanel** menuPanels;
    s32 i;

    DMA_COPY_SEGMENT(ui_images);

    for (i = 0; i < ARRAY_COUNT(gPauseIconScripts); i++) {
        gPauseCommonIconIDs[i] = hud_element_create(gPauseIconScripts[i]);
        if (gPauseIconScripts[i] == &HES_AnimatedCursorHand) {
            hud_element_set_flags(gPauseCommonIconIDs[i], HUD_ELEMENT_FLAG_DROP_SHADOW | HUD_ELEMENT_FLAG_80);
        } else {
            hud_element_set_flags(gPauseCommonIconIDs[i], HUD_ELEMENT_FLAG_80);
        }
    }

    gPauseCursorIconID = gPauseCommonIconIDs[0];
    setup_pause_menu_tab(gPauseCommonWindowsBPs, ARRAY_COUNT(gPauseCommonWindowsBPs));
    gPauseShownDescMsg = 0;
    gPauseDescTextPos = 0;
    gPauseDescTextOffset = 0;
    gPauseDescTextMaxPos = 0;
    gPauseShownDescIconScript = 0;
    gPauseCurrentDescMsg = MSG_NONE;
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
            set_window_update(WINDOW_ID_PAUSE_TUTORIAL + i, WINDOW_UPDATE_HIDE);
        } else {
            gWindows[WINDOW_ID_PAUSE_TUTORIAL + i].pos.x = posX + 14;
            posX -= 45;
        }
    }
    pauseWindows = &gWindows[WINDOW_ID_PAUSE_TAB_STATS];
    x = pauseWindows[gPausePanels[0]->col].pos.x;
    gWindows[WINDOW_ID_PAUSE_TAB_INVIS].pos.x = x + 6;

    if (evt_get_variable(NULL, GF_Tutorial_Badges)) {
        for (i = 0; i < ARRAY_COUNT(gPauseTutorialSpriteAnims); i++) {
            gPauseTutorialSprites[i] = spr_load_npc_sprite(gPauseTutorialSpriteAnims[i][0], gPauseTutorialSpriteAnims[i]);
        }

        set_window_update(WINDOW_ID_PAUSE_TUTORIAL, WINDOW_UPDATE_SHOW);
        sfx_play_sound(SOUND_MENU_SHOW_CHOICE);
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
                sfx_play_sound(SOUND_MENU_ERROR);
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

    if (evt_get_variable(NULL, GF_Tutorial_Badges)) {
        for (i = 0; i < ARRAY_COUNT(gPauseTutorialSprites); i++) {
            spr_update_sprite(gPauseTutorialSprites[i], gPauseTutorialSpriteAnims[i][1], 1.0f);
        }
    }

    gPausePressedButtons = pressed;
    gPauseHeldButtons = held;
    if (evt_get_variable(NULL, GF_Tutorial_Badges)) {
        pause_tutorial_input(&gPausePressedButtons, &gPauseHeldButtons);
    }

    if ((gPausePressedButtons & BUTTON_START) || (gPauseMenuCurrentTab == 0) && (gPausePressedButtons & BUTTON_B)) {
        enforce_hpfp_limits();
        sfx_play_sound(SOUND_MENU_CLOSE);
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
    for (i = 0; i < ARRAY_COUNT(gPausePanels); menuPanels++, i++) {
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

    for (i = 0; i < ARRAY_COUNT(gPauseCommonIconIDs); i++) {
        hud_element_free(gPauseCommonIconIDs[i]);
    }

    if (evt_get_variable(NULL, GF_Tutorial_Badges)) {
        for (i = 0; i < ARRAY_COUNT(gPauseTutorialSprites); i++) {
            spr_free_sprite(gPauseTutorialSprites[i]);
        }
    }

    menuPanels = gPausePanels;
    for (i = 0; i < ARRAY_COUNT(gPausePanels); menuPanels++, i++) {
        if ((*menuPanels)->initialized) {
            if ((*menuPanels)->fpCleanup) {
                (*menuPanels)->fpCleanup(*menuPanels);
            }
        }
    }

    for (i = WINDOW_ID_PAUSE_MAIN; i < WINDOW_ID_PAUSE_CURSOR; i++)
        set_window_update(i, WINDOW_UPDATE_HIDE);

    set_window_update(WINDOW_ID_PAUSE_CURSOR, WINDOW_UPDATE_HIDE);
}

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

void pause_draw_rect(s32 ulx, s32 uly, s32 lrx, s32 lry, s32 tileIdx, s32 uls, s32 ult, s32 dsdx, s32 dtdy) {
    if (ulx <= -2688 || uly <= -2688 || lrx <= 0 || lry <= 0) {
        return;
    }
    if (ulx >= 1280 || uly >= 960 || lrx >= 2688 || lry >= 2688) {
        return;
    }
    gSPScisTextureRectangle(gMainGfxPos++, ulx, uly, lrx, lry, tileIdx, uls, ult, dsdx, dtdy);
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

static const f32 rodata_padding[] = {0.0f, 0.0f, 0.0f};
