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

// Need data segment and vars declared above
#ifdef NON_MATCHING
void pause_set_cursor_opacity(s32 val) {
    gPauseMenuCursorTargetOpacity = val;
}
#else
INCLUDE_ASM(s32, "pause/135EE0", pause_set_cursor_opacity);
#endif

// Delay slot issue with D_8024EFB4 (needs .data)
#ifdef NON_MATCHING
extern s32 D_8024EFB4;

void func_80242BAC(s32 windowID, s32 posX, s32 posY) {
    Window* window = &gWindows[windowID];

    if (D_8024EFB4 != 0
            || get_game_mode() == GAME_MODE_EXIT_FILE_SELECT
            || get_game_mode() == GAME_MODE_EXIT_LANGUAGE_SELECT) {
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

    } else if ((window->flags & WINDOW_FLAGS_88 == 0 && (window->parent == -1 || !(gWindows[window->parent].flags & 8))) {
        gPauseMenuTargetPosX = posX;
        gPauseMenuCursorPosX = posX;
        gPauseMenuTargetPosY = posY;
        gPauseMenuCursorPosY = posY;
    }
}
#else
INCLUDE_ASM(s32, "pause/135EE0", func_80242BAC);
#endif

// Delay slot issue with gPauseMenuCursorPosY (needs .data)
#ifdef NON_MATCHING
extern s32 D_8024EFB4;

void func_80242D04(s32 windowID, s32 posX, s32 posY) {
    Window* window = &gWindows[windowID];

    if (D_8024EFB4 != 0
            || get_game_mode() == GAME_MODE_EXIT_FILE_SELECT
            || get_game_mode() == GAME_MODE_EXIT_LANGUAGE_SELECT) {
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
#else
INCLUDE_ASM(s32, "pause/135EE0", func_80242D04);
#endif

// Delay slot issue with gPauseMenuCursorTargetOpacity (needs .data)
#ifdef NON_MATCHING
void pause_interp_cursor(void) {
    s32* posX = &gPauseMenuCursorPosX;
    s32* posY = &gPauseMenuCursorPosY;
    s32* targetPosX = &gPauseMenuTargetPosX;
    s32* targetPosY = &gPauseMenuTargetPosY;
    s32 xDelta;
    s32 yDelta;
    s32* opacity;

    xDelta = (*targetPosX - *posX) * 0.5;
    yDelta = (*targetPosY - *posY) * 0.5;

    if ((*targetPosX != *posX) || (*targetPosY != *posY)) {
        if ((xDelta == 0) && (yDelta == 0)) {
            *posX = *targetPosX;
            *posY = *targetPosY;
        }
    }

    // Macros? something strange
    {
        s32* posX = &gPauseMenuCursorPosX;
        *posX += xDelta;
    }

    {
        s32* posY = &gPauseMenuCursorPosY;
        *posY += yDelta;
    }

    if (gPauseMenuCursorTargetOpacity == 0) {
        opacity = &gPauseMenuCursorOpacity;

        *opacity -= 128;
        if (*opacity < 0) {
            *opacity = 0;
        }
    } else {
        opacity = &gPauseMenuCursorOpacity;

        *opacity += 32;
        if (*opacity > 255) {
            *opacity = 255;
        }
    }
    gPauseMenuCursorTargetOpacity = 255;
}
#else
INCLUDE_ASM(s32, "pause/135EE0", pause_interp_cursor);
#endif

INCLUDE_ASM(s32, "pause/135EE0", func_80242F90);

INCLUDE_ASM(s32, "pause/135EE0", func_80242FBC);

INCLUDE_ASM(s32, "pause/135EE0", func_80242FF4);

INCLUDE_ASM(s32, "pause/135EE0", func_80243090);

INCLUDE_ASM(s32, "pause/135EE0", func_802430E4);

INCLUDE_ASM(s32, "pause/135EE0", func_8024313C);

INCLUDE_ASM(s32, "pause/135EE0", func_80243188);

INCLUDE_ASM(s32, "pause/135EE0", func_80243238);

INCLUDE_ASM(s32, "pause/135EE0", func_802432E8);

INCLUDE_ASM(s32, "pause/135EE0", func_80243388);

INCLUDE_ASM(s32, "pause/135EE0", pause_interp_text_scroll);

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
