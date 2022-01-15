#include "common.h"
#include "hud_element.h"

BSS s32 gPauseMenuHeldButtons;
BSS s32 gPauseMenuPressedButtons;
BSS s32 gPauseMenuCurrentDescMsg;
BSS s32* gPauseMenuCurrentDescIconScript;
BSS s32 D_802700D0;
BSS s8 gPauseMenuCurrentTab;
BSS char D_802700D[8];
BSS s32 D_802700E0;
#define BSS_END 0x802700E4

// TODO this is the bss for the whole segment - break it up
static char bss[0x80278640 - BSS_END];

//data
extern EvtSource HudScript_AnimatedCursorHand;
extern EvtSource HudScript_DescMsgPrev;
extern EvtSource HudScript_DescMsgNext;
extern EvtSource HudScript_UnusedBadge;
extern EvtSource HudScript_StickTapRight;
extern EvtSource HudScript_PressAButton;
extern EvtSource HudScript_PressStartButton;
extern EvtSource HudScript_StartButtonText;

u32 gPauseMenuIconScripts[] = {HudScript_AnimatedCursorHand, HudScript_DescMsgPrev, HudScript_DescMsgNext,
                               HudScript_UnusedBadge, HudScript_StickTapRight, HudScript_PressAButton,
                               HudScript_PressStartButton, HudScript_StartButtonText};
MenuPanel* gPauseMenuPanels[] = { 0x8024F314, 0x8024F4AC, 0x8024F54C, 0x8024F5E4, 0x8024F88C, 0x8024FA10 };
u32 D_8024EF98 = 0x8025068C;
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
    window->flags &= 0xF3;
}

void func_80242FBC(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB) {
    Window* window = &gWindows[windowID];

    *argA = 0xA0;
    *argB = 0x50;
    window->flags &= 0xF3;
}

void func_80242FF4(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB) {
    Window* window = &gWindows[windowID];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= 0xFB;
    }

    if (updateCounter == 5) {
        update_window_hierarchy(windowID, window->unk_02);
    }

    if (updateCounter < 10) {
        *argA = (updateCounter + 1) * 0x10;
    } else {
        *argA = 0xA0;
        window->flags &= 0xF7;
    }
}

void func_80243090(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB) {
    Window* window = &gWindows[windowID];

    if (window->updateCounter == 0) {
        update_window_hierarchy(windowID, window->unk_02);
        *argA = 0;
        window->flags &= 0xF7;
    }
}

void func_802430E4(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB) {
    Window* window = &gWindows[windowID];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= 0xFB;
    }

    if (updateCounter < 16) {
        *argB = updateCounter * 0x10;
    } else {
        *argB = 255;
        window->flags &= 0xF7;
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
        window->flags = (window->flags & 0xF7) | 4;
    }
}

void func_80243188(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB) {
    Window* window = &gWindows[windowID];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= 0xFB;
    }
    if (updateCounter < 7) {
        *arg1 = D_8024EFC4[updateCounter];
        *arg7 += D_8024EFCC[updateCounter]; // BUG!  length of array is only 6
    } else {
        *arg1 = D_8024EFC4[5];
        *arg7 += D_8024EFCC[6]; // BUG!  length of array is only 6
        window->flags &= 0xF7;
    }
}

void func_80243238(s32 windowID, s32* arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32* arg7, s32 arg8, s32 arg9,
                    s32* argA, s32* argB) {
    Window* window = &gWindows[windowID];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= 0xFB;
    }
    if (updateCounter < 7) {
        *arg1 = D_8024EFC4[updateCounter];
        *arg7 += D_8024EFD8[updateCounter];
    } else {
        *arg1 = D_8024EFC4[5];
        *arg7 += D_8024EFD8[6]; // BUG!  length of array is only 6
        window->flags &= 0xF7;
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
        window->flags = (window->flags & 0xF7) | 4;
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
        window->flags = (window->flags & 0xF7) | 4;
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

INCLUDE_ASM(s32, "pause/135EE0", pause_textbox_draw_contents);

INCLUDE_ASM(s32, "pause/135EE0", pause_tutorial_draw_contents);

INCLUDE_ASM(s32, "pause/135EE0", pause_init);

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
