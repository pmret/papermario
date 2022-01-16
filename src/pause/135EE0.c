#include "common.h"
#include "hud_element.h"
#include "ld_addrs.h"

extern HudElementAnim HudScript_AnimatedCursorHand;
extern HudElementAnim HudScript_DescMsgPrev;
extern HudElementAnim HudScript_DescMsgNext;
extern HudElementAnim HudScript_UnusedBadge;
extern HudElementAnim HudScript_StickTapRight;
extern HudElementAnim HudScript_PressAButton;
extern HudElementAnim HudScript_PressStartButton;
extern HudElementAnim HudScript_StartButtonText;

extern HudElementAnim D_80241ECC;

extern s32 D_80270108;
extern s32 D_8027010C;
extern s32 D_80270110;
extern s32 D_80270114;
extern HudElementAnim* D_80270118;
extern s32 D_8027011C[3];

void pause_tutorial_draw_contents(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void func_80243568(void);
void pause_textbox_draw_contents(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void pause_update_cursor(s32 arg0, s32 offsetX, s32 offsetY);

HudElementAnim* gPauseMenuIconScripts[] = {HudScript_AnimatedCursorHand, HudScript_DescMsgPrev, HudScript_DescMsgNext,
                               HudScript_UnusedBadge, HudScript_StickTapRight, HudScript_PressAButton,
                               HudScript_PressStartButton, HudScript_StartButtonText};
// TODO make pointers,
MenuPanel* gPauseMenuPanels[] = { 0x8024F314, 0x8024F4AC, 0x8024F54C, 0x8024F5E4, 0x8024F88C, 0x8024FA10, 0x8025068C };
s32 gPauseMenuCursorPosX = 160;
s32 gPauseMenuCursorPosY = -120;
s32 gPauseMenuCursorOpacity = 0;
s32 gPauseMenuTargetPosX = 160;
s32 gPauseMenuTargetPosY = -120;
s32 gPauseMenuCursorTargetOpacity = 0;
u32 D_8024EFB4 = 1;
u32 D_8024EFB8[] = {0xFFF6FFE7, 0xFFD6FFC4, 0xFFB00000 }; //unused??
u8 D_8024EFC4[] = { 1, 1, 1, 1, 1, 0, 0};
s16 D_8024EFCC[] = { -80, -65, -38, -30, -10, 0 };
s16 D_8024EFD8[] = {  80,  65,  38,  30,  10, 0 };
u8 D_8024EFE4[] = { 1, 1, 1, 1, 1, 1, 0, 0 };
u8 D_8024EFEC[] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x11, 0x00, 0x25, 0x00, 0x3C,
                    0x00, 0x55, 0x00, 0x6E }; //unused??
s16 D_8024F000[] = { -10, -25, -42, -60, -80};
s16 D_8024F00C[] = {  10,  25,  42,  60,  80 };
s32 D_8024F018 = -1;
s32 D_8024F01C = 3;
s32 D_8024F020[] = { 0x00008000, 0x00080000, 0x00008000, 0x00008000, 0x00008000, 0x00008000, 0x00001000 };
s32 D_8024F03C[] = { 9, 10, 11, 12, 13, 14, 15 };
s32 D_8024F058[] = { 0x00000010, 0x00000011, 0x00000012, 0x00000013, 0x00000014, 0x00000015, 0x00000016,
                     0x00000002, 0x00000003, 0x00000004, 0x00000005, 0x00000006, 0x00000007, 0x00000008};
s32 D_8024F090[] = { 5, 4, 5, 5, 5, 5, 6 };
u8 gPauseMenuTextScrollInterpEasingLUT[] = { 0x00, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08};
u8 gPauseMenuPageScrollInterpEasingLUT[] = { 0x00, 0x01, 0x02, 0x02, 0x02, 0x03, 0x03, 0x04, 0x04, 0x05, 0x05, 0x06, 0x06, 0x07, 0x07, 0x08};
s32 D_8024F0CC[] = { 0x009E0000, 0x009E0001, 0x009E000B, 0xFFFFFFFF, 0x00010000, 0x00010001, 0x00010008, 0xFFFFFFFF, 0x009D0000, 0x009D0001, 0x009D0008, 0xFFFFFFFF, 0x00000000 };
Vp D_8024F100 = {
    .vp = {
        .vscale = { 640, 480, 511, 0 },
        .vtrans = { 640, 480, 511, 0 },
    }
};
s32 D_8024F110 = 0;
MenuWindowBP D_8024F114[] = { { .windowID = 22,
                                .unk_01 = 0,
                                .pos = { .x = 12,
                                         .y = 20 },
                                .height = 296,
                                .width = 200,
                                .unk_0A = { 0, 0},
                                .fpDrawContents = &func_80243568,
                                .tab = NULL,
                                .parentID = 0xFF000000,
                                .fpUpdate = 1,
                                .unk_1C = 0x40000000,
                                .style = 0x8026F900 },

                              { .windowID = 24,
                                .unk_01 = 0,
                                .pos = { .x = 0,
                                         .y = 138 },
                                .height = 296,
                                .width = 63,
                                .unk_0A = { 0, 0},
                                .fpDrawContents = &pause_tutorial_draw_contents,
                                .tab = NULL,
                                .parentID = 0x16000000,
                                .fpUpdate = 2,
                                .unk_1C = 0x00000000,
                                .style = 0x8026F970 },

                              { .windowID = 23,
                                .unk_01 = 0,
                                .pos = { .x = 20,
                                         .y = 164 },
                                .height = 256,
                                .width = 32,
                                .unk_0A = { 0, 0},
                                .fpDrawContents = &pause_textbox_draw_contents,
                                .tab = NULL,
                                .parentID = 0x16000000,
                                .fpUpdate = &basic_window_update,
                                .unk_1C = 0x00000000,
                                .style = 0x8026F938 },

                              { .windowID = 44,
                                .unk_01 = 0,
                                .pos = { .x = 0,
                                         .y = 0 },
                                .height = 320,
                                .width = 240,
                                .unk_0A = { 0, 0},
                                .fpDrawContents = &pause_update_cursor,
                                .tab = NULL,
                                .parentID = 0xFF000000,
                                .fpUpdate = 1,
                                .unk_1C = 0x00000000,
                                .style = 0x8026F900 } };

void pause_set_cursor_opacity(s32 val) {
    gPauseMenuCursorTargetOpacity = val;
}

void func_80242BAC(s32 windowID, s32 posX, s32 posY) {
    Window* window = &gWindows[windowID];

    if (D_8024EFB4 != 0
            || get_game_mode() == GAME_MODE_END_FILE_SELECT
            || get_game_mode() == GAME_MODE_END_LANGUAGE_SELECT) {
        if (D_8024EFB4 != 0) {
            s32 i;

            for (i = 0x16; i < 0x2C; i++) {
                Window* window = &gWindows[i];
                s8 parent = window->parent;

                if ((parent == -1 || parent == 0x16) && (window->flags & WINDOW_FLAGS_8)) {
                    break;
                }
            }
            if (i >= 0x2C) {
                D_8024EFB4 = 0;
            }
        }
        gPauseMenuTargetPosX = posX;
        gPauseMenuCursorPosX = posX;
        gPauseMenuTargetPosY = posY;
        gPauseMenuCursorPosY = posY;

    } else if ((window->flags & WINDOW_FLAGS_8) == 0 && (window->parent == -1 || !(gWindows[window->parent].flags & WINDOW_FLAGS_8))) {
        gPauseMenuTargetPosX = posX;
        gPauseMenuCursorPosX = posX;
        gPauseMenuTargetPosY = posY;
        gPauseMenuCursorPosY = posY;
    }
}

void func_80242D04(s32 windowID, s32 posX, s32 posY) {
    Window* window = &gWindows[windowID];

    if (D_8024EFB4 != 0
            || get_game_mode() == GAME_MODE_END_FILE_SELECT
            || get_game_mode() == GAME_MODE_END_LANGUAGE_SELECT) {
        if (D_8024EFB4 != 0) {
            s32 i;

            for (i = 0x16; i < 0x2C; i++) {
                Window* window = &gWindows[i];
                s8 parent = window->parent;

                if ((parent == -1 || parent == 0x16) && (window->flags & WINDOW_FLAGS_8)) {
                    break;
                }
            }
            if (i >= 0x2C) {
                D_8024EFB4 = 0;
            }
        }
        gPauseMenuTargetPosX = posX;
        gPauseMenuCursorPosX = posX;
        gPauseMenuTargetPosY = posY;
        gPauseMenuCursorPosY = posY;
    } else if ((window->flags & WINDOW_FLAGS_8) == 0 && (window->parent == -1 || !(gWindows[window->parent].flags & 8))) {
        gPauseMenuTargetPosX = posX;
        gPauseMenuTargetPosY = posY;
    }
}

void pause_interp_cursor(void) {
    s32 xDelta;
    s32 yDelta;
    s32* opacity;

    xDelta = (gPauseMenuTargetPosX - gPauseMenuCursorPosX) * 0.5;
    yDelta = (gPauseMenuTargetPosY - gPauseMenuCursorPosY) * 0.5;

    if ((gPauseMenuTargetPosX != gPauseMenuCursorPosX) || (gPauseMenuTargetPosY != gPauseMenuCursorPosY)) {
        if ((xDelta == 0) && (yDelta == 0)) {
            gPauseMenuCursorPosX = gPauseMenuTargetPosX;
            gPauseMenuCursorPosY = gPauseMenuTargetPosY;
        }
    }

    gPauseMenuCursorPosX += xDelta;
    gPauseMenuCursorPosY += yDelta;

    if (gPauseMenuCursorTargetOpacity == 0) {
        gPauseMenuCursorOpacity -= 128;
        if (gPauseMenuCursorOpacity < 0) {
            gPauseMenuCursorOpacity = 0;
        }
    } else {
        gPauseMenuCursorOpacity += 32;
        if (gPauseMenuCursorOpacity> 255) {
            gPauseMenuCursorOpacity = 255;
        }
    }
    gPauseMenuCursorTargetOpacity = 255;
}

// TODO figure out what do arguments mean
void func_80242F90(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB) {
    Window* window = &gWindows[windowID];

    *argA = 0xA0;
    window->flags &= ~(WINDOW_FLAGS_4 | WINDOW_FLAGS_8);
}

void func_80242FBC(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB) {
    Window* window = &gWindows[windowID];

    *argA = 0xA0;
    *argB = 0x50;
    window->flags &= ~(WINDOW_FLAGS_4 | WINDOW_FLAGS_8);
}

void func_80242FF4(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB) {
    Window* window = &gWindows[windowID];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAGS_4;
    }

    if (updateCounter == 5) {
        update_window_hierarchy(windowID, window->unk_02);
    }

    if (updateCounter < 10) {
        *argA = (updateCounter + 1) * 0x10;
    } else {
        *argA = 0xA0;
        window->flags &= ~WINDOW_FLAGS_8;
    }
}

void func_80243090(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB) {
    Window* window = &gWindows[windowID];

    if (window->updateCounter == 0) {
        update_window_hierarchy(windowID, window->unk_02);
        *argA = 0;
        window->flags &= ~WINDOW_FLAGS_8;
    }
}

void func_802430E4(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB) {
    Window* window = &gWindows[windowID];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAGS_4;
    }

    if (updateCounter < 16) {
        *argB = updateCounter * 0x10;
    } else {
        *argB = 255;
        window->flags &= ~WINDOW_FLAGS_8;
    }
}

void func_8024313C(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB) {
    Window* window = &gWindows[windowID];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < 16) {
        *argB = 255 - (updateCounter * 16);
    } else {
        *argB = 0;
        window->flags = (window->flags & ~WINDOW_FLAGS_8) | WINDOW_FLAGS_4;
    }
}

void func_80243188(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB) {
    Window* window = &gWindows[windowID];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAGS_4;
    }
    if (updateCounter < 7) {
        *arg1 = D_8024EFC4[updateCounter];
        *arg7 += D_8024EFCC[updateCounter]; // BUG!  length of array is only 6
    } else {
        *arg1 = D_8024EFC4[5];
        *arg7 += D_8024EFCC[6]; // BUG!  length of array is only 6
        window->flags &= ~WINDOW_FLAGS_8;
    }
}

void func_80243238(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB) {
    Window* window = &gWindows[windowID];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAGS_4;
    }
    if (updateCounter < 7) {
        *arg1 = D_8024EFC4[updateCounter];
        *arg7 += D_8024EFD8[updateCounter];
    } else {
        *arg1 = D_8024EFC4[5];
        *arg7 += D_8024EFD8[6]; // BUG!  length of array is only 6
        window->flags &= ~WINDOW_FLAGS_8;
    }
}

void func_802432E8(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB) {
    Window* window = &gWindows[windowID];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < 5) {
        *arg1 = D_8024EFE4[updateCounter];
        *arg7 += D_8024F000[updateCounter];
    } else {
        *arg1 = D_8024EFE4[4];
        *arg7 += D_8024F000[4];
        window->flags = (window->flags & ~WINDOW_FLAGS_8) | WINDOW_FLAGS_4;
    }
}

void func_80243388(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB) {
    Window* window = &gWindows[windowID];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < 5) {
        *arg1 = D_8024EFE4[updateCounter];
        *arg7 = D_8024F00C[updateCounter];
    } else {
        *arg1 = D_8024EFE4[4];
        *arg7 = D_8024F00C[4];
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

void pause_update_cursor(s32 arg0, s32 offsetX, s32 offsetY) {
    s32 opacity;

    pause_interp_cursor();
    opacity = gPauseMenuCursorOpacity;
    if (opacity > 0) {
        if (opacity > 255) {
            opacity = 255;
        }
        set_hud_element_alpha(gPauseMenuCommonIconIDs[0], opacity);
        set_hud_element_render_pos(gPauseMenuCommonIconIDs[0], offsetX + gPauseMenuCursorPosX, offsetY + gPauseMenuCursorPosY);
        draw_hud_element_3(gPauseMenuCommonIconIDs[0]);
    }
}

void func_80243568(void) {
}

void pause_textbox_draw_contents(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 msgID = D_80270108;

    if (msgID == 0)
        return;

    if (D_80270110 != 0) {
        set_hud_element_render_pos(gPauseMenuCommonIconIDs[1], arg1 + arg3 - 4, arg2 + 4);
        draw_hud_element_3(gPauseMenuCommonIconIDs[1]);
    }

    if (D_80270110 < D_8027010C) {
        set_hud_element_render_pos(gPauseMenuCommonIconIDs[2], arg1 + arg3 - 4, arg2 + arg4 - 4);
        draw_hud_element_3(gPauseMenuCommonIconIDs[2]);
    }

    gDPPipeSync(gMasterGfxPos++);
    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, arg1 + 1, arg2 + 1, arg1 + arg3 - 1, arg2 + arg4 - 1);
    draw_msg(msgID, arg1 + 10, arg2 - D_80270114, 255, 10, 0);
    if (D_80270118 != 0) {
        gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        set_hud_element_render_pos(gPauseMenuCommonIconIDs[3], arg1 - 4, arg2 + 16);
        set_hud_element_anim(gPauseMenuCommonIconIDs[3], D_80270118);
        set_hud_element_flags(gPauseMenuCommonIconIDs[3], 0x20000000);
        clear_hud_element_flags(gPauseMenuCommonIconIDs[3], 0x8000);
        set_hud_element_scale(gPauseMenuCommonIconIDs[3], 1.0f);
        draw_hud_element_3(gPauseMenuCommonIconIDs[3]);
    }
}

void pause_tutorial_draw_contents(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Matrix4f sp28;
    Matrix4f sp68;
    f32** psp68;
    s32 height;
    s32 width;
    s32 maxLineChars;
    s32 numLines;
    s32 maxLinesPerPage;
    s32 height2;
    u32 width2;
    s32 maxLineChars2;
    s32 numLines2;
    s32 maxLinesPerPage2;
    s32 i;
    s32 temp, tempp;
    s32 temp_s2;
    s32 q;

    if (evt_get_variable(NULL, EVT_SAVE_FLAG(94)) == 0)
        return;
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gDPSetCombineMode(gMasterGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0x37, 0x37, 0x37, 0xFF);
    pause_draw_rect(arg1 * 4, arg2 * 4, (arg1 + arg3) * 4, (arg2 + 12) * 4, 0, 0, 0, 0, 0);
    gDPPipeSync(gMasterGfxPos++);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0xB9, 0xB9, 0xB9, 0xFF);
    pause_draw_rect(arg1 * 4, (arg2 + 12) * 4, (arg1 + arg3) * 4, (arg2 + arg4) * 4, 0, 0, 0, 0, 0);
    gDPPipeSync(gMasterGfxPos++);
    gSPViewport(gMasterGfxPos++, &D_8024F100);
    guOrthoF(&sp28, 0.0f, 320.0f, 240.0f, 0.0f, -100.0f, 100.0f, 1.0f);
    guMtxF2L(&sp28, &gDisplayContext->matrixStack[gMatrixListPos]);
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
        func_802DE894(D_8027011C[i], 6, 255, 255, 255, 255, 64);
        spr_draw_npc_sprite(D_8027011C[i], 0, 0, 0, &sp28);
        gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
    }

    get_msg_properties(pause_get_menu_msg(1), &height, &width, &maxLineChars, &numLines, &maxLinesPerPage, NULL, 1);
    temp = (s32)(arg3 - width) >> 1;
    draw_msg(pause_get_menu_msg(1), arg1 + temp, arg2, 0xFF, 0, 1);
    D_8024F110 += pause_interp_text_scroll(D_8024F018 * 140 - D_8024F110);
    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, arg1 + 1, arg2 + 1, arg1 + arg3 - 1, arg2 + arg4 - 1);
    temp_s2 = D_8024F018;
    get_msg_properties(pause_get_menu_msg(D_8024F03C[temp_s2]), &height2, &width2, &maxLineChars2, &numLines2, &maxLinesPerPage2, NULL, 1);
    tempp = (s32)(arg3 - width2) >> 1;
    q = 13;
    draw_msg(pause_get_menu_msg(D_8024F03C[temp_s2]), arg1 + tempp, arg2 + (temp_s2 * 140 + q) - D_8024F110, 0xFF, 10, 1);
    set_hud_element_render_pos(gPauseMenuCommonIconIDs[D_8024F090[D_8024F018]], arg1 + arg3 / 2 - 2, arg2 + 52);
    set_hud_element_flags(gPauseMenuCommonIconIDs[D_8024F090[D_8024F018]], 0x8000);
    set_hud_element_scale(gPauseMenuCommonIconIDs[D_8024F090[D_8024F018]], 0.5f);
    draw_hud_element_3(gPauseMenuCommonIconIDs[D_8024F090[D_8024F018]]);

    if (D_8024F090[D_8024F018] == 6) {
        set_hud_element_render_pos(gPauseMenuCommonIconIDs[7], arg1 + arg3 / 2 + 1, arg2 + 50);
        draw_hud_element_3(gPauseMenuCommonIconIDs[7]);
    }

    draw_msg(pause_get_menu_msg(D_8024F058[D_8024F018]), arg1 + arg3 / 2 + 10, arg2 + 44, 0xFF, 10, 0);
}

void pause_init(void) {
    s32 i;
    s32 posX;
    s32 x;
    Window* pauseWindows;
    MenuPanel** menuPanels;

    dma_copy(_131340_ROM_START, _131340_ROM_END, _131340_VRAM);

    for (i = 0; i < 8; i++) {
        gPauseMenuCommonIconIDs[i] = create_hud_element(gPauseMenuIconScripts[i]);
        if (gPauseMenuIconScripts[i] == D_80241ECC) {
            set_hud_element_flags(gPauseMenuCommonIconIDs[i], 0x20000080);
        } else {
            set_hud_element_flags(gPauseMenuCommonIconIDs[i], 0x80);
        }
    }

    D_802700D0 = gPauseMenuCommonIconIDs[0];
    setup_pause_menu_tab(&D_8024F114, 4);
    D_80270108 = 0;
    D_80270110 = 0;
    D_80270114 = 0;
    D_8027010C = 0;
    D_80270118 = 0;
    gPauseMenuCurrentDescMsg = 0;
    gPauseMenuCurrentDescIconScript = 0;
    gPauseMenuCurrentTab = 0;

    menuPanels = gPauseMenuPanels;
    for (i = 0; i < ARRAY_COUNT(gPauseMenuPanels); menuPanels++, i++) {
        if ((*menuPanels)->fpInit) {
            (*menuPanels)->fpInit(*menuPanels);
        }
    }

    posX = 225;
    for (i = 6; i > 0; i--) {
        if (!gPauseMenuPanels[i]->unk_00.c.initialized) {
            set_window_update(24 + i, 2);
        } else {
            gWindows[24 + i].pos.x = posX + 14;
            posX -= 45;
        }
    }
    pauseWindows = &gWindows[25];
    x = pauseWindows[gPauseMenuPanels[0]->unk_00.c.col].pos.x;
    gWindows[43].pos.x = x + 6;

    if (evt_get_variable(NULL, EVT_SAVE_FLAG(94)) != 0) {
        for (i = 0; i < 3; i++) {
            D_8027011C[i] = spr_load_npc_sprite(D_8024F0CC[4*i], &D_8024F0CC[4*i]);
        }

        set_window_update(24, 1);
        sfx_play_sound(9);
    }

    update_window_hierarchy(44, 0x40);
}

INCLUDE_ASM(s32, "pause/135EE0", pause_tutorial_input);

INCLUDE_ASM(s32, "pause/135EE0", pause_handle_input);

INCLUDE_ASM(s32, "pause/135EE0", pause_cleanup);

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
