#include "common.h"
#include "filemenu.h"
#include "hud_element.h"
#include "fio.h"
#include "ld_addrs.h"
#include "game_modes.h"

extern HudScript HES_AnimatedCursorHand;

extern MenuPanel filemenu_main_menuBP;
extern MenuPanel filemenu_yesno_menuBP;
extern MenuPanel filemenu_info_menuBP;
extern MenuPanel filemenu_createfile_menuBP;
extern MenuPanel filemenu_selectlanguage_menuBP;

HudScript* filemenu_cursor_hudElemScripts[] = { &HES_AnimatedCursorHand };
MenuPanel* filemenu_menus[] = {
    &filemenu_main_menuBP,
    &filemenu_yesno_menuBP,
    &filemenu_info_menuBP,
    &filemenu_createfile_menuBP,
#if VERSION_PAL
    &filemenu_selectlanguage_menuBP,
#endif
};
s32 filemenu_cursor_posX = SCREEN_WIDTH / 2;
s32 filemenu_cursor_posY = -SCREEN_HEIGHT / 2;
s32 filemenu_cursor_alpha = 0;
s32 filemenu_cursor_targetX = SCREEN_WIDTH / 2;
s32 filemenu_cursor_targetY = -SCREEN_HEIGHT / 2;
s32 filemenu_cursorGoalAlpha = 0;
s32 filemenu_cursorGoalAlpha2 = 0;
s32 D_80249BB0 = TRUE;
#if !VERSION_PAL
s32 D_80249BB4 = 0;
#endif
s32 D_80249BB8 = 0;
s16 D_80249BBC[16] = { 315, 303, 283, 260, 235, 210, 185, 160, 135, 110, 85, 60, 37, 17, 5, 0 };
s16 D_80249BDC[16] = { 315, 303, 283, 260, 235, 210, 185, 160, 135, 110, 85, 60, 37, 17, 5, 0 };
s16 D_80249BFC[16] = { 157, 151, 141, 130, 117, 105, 92, 80, 67, 55, 42, 30, 18, 8, 2, 0 };
s16 D_80249C1C[16] = { 157, 151, 141, 130, 117, 105, 92, 80, 67, 55, 42, 30, 18, 8, 2, 0 };
s16 D_80249C3C[16] = { 63, 60, 56, 52, 47, 42, 37, 32, 27, 22, 17, 12, 7, 3, 1, 0 };
s16 D_80249C5C[16] = { 63, 60, 56, 52, 47, 42, 37, 32, 27, 22, 17, 12, 7, 3, 1, 0 };
s16 D_80249C7C[10] = { -5, -17, -37, -60, -85, -110, -135, -160, -185, -210 };
s16 D_80249C90[10] = { -5, -17, -37, -60, -85, -110, -135, -160, -185, -210 };
s16 D_80249CA4[10] = { -2, -8, -18, -30, -42, -55, -70, -85, -100, -115 };
s16 D_80249CB8[10] = { -2, -8, -18, -30, -42, -55, -70, -85, -100, -115 };
s16 D_80249CCC[10] = { -1, -3, -7, -12, -17, -22, -27, -32, -37, -42 };
s16 D_80249CE0[10] = { -1, -3, -7, -12, -17, -22, -27, -32, -37, -42 };
s16 D_80249CF4[16] = { 180, 173, 161, 148, 134, 120, 105, 91, 77, 62, 48, 34, 21, 9, 2, 0 };
s16 D_80249D14[16] = { 0, 2, 9, 21, 34, 48, 62, 77, 91, 105, 120, 134, 148, 161, 173, 180 };
s16 D_80249D34[10] = { 185, 160, 135, 110, 85, 60, 37, 17, 5, 0 };
s16 D_80249D48[10] = { 0, 5, 17, 37, 60, 85, 110, 135, 160, 185};

#if VERSION_PAL
s16 D_filemenu_8024EB5C[] = {
    210,
    182,
    162,
    145,
    130,
    117,
    105,
    92,
    80,
    67,
    55,
    42,
    30,
    18,
    8,
    2,
    0,
};

s16 D_filemenu_8024EB80[] = {
    -2,
    -8,
    -18,
    -30,
    -42,
    -55,
    -67,
    -80,
    -92,
    -105,
    -117,
    -130,
    -142,
    -155,
    -167,
    -180,
    -192,
    -205,
};
#endif

s32 D_80249D4C = 0; // padding?
Vp D_80249D60 = {
    .vp = {
        .vscale = { 640, 480, 511, 0},
        .vtrans = { 640, 480, 511, 0},
    }
};
f32 D_80249D70[15] = { 7.0f, 12.5f, 13.0f, 14.5f, 14.0f, 13.0f, 11.5f, 9.5f, 7.5f, 5.5f, 3.5f, 2.0f, 1.0f, 0.5f, 0.0f };

MenuWindowBP filemenu_common_windowBPs[3] = {
    {
        .windowID = WINDOW_ID_FILEMENU_MAIN,
        .pos = {
            .x = 16,
            .y = 24,
        },
        .width = 288,
        .height = 192,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = NULL,
        .tab = NULL,
        .parentID = -1,
        .fpUpdate = { WINDOW_UPDATE_SHOW },
        .extraFlags = WINDOW_FLAG_40,
        .style = { .customStyle = &filemenu_windowStyles[0] },
    },
    {
        .windowID = WINDOW_ID_FILEMENU_COPYARROW,
        .pos = {
            .x = 0,
            .y = 0,
        },
        .width = 288,
        .height = 192,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = filemenu_draw_contents_copy_arrow,
        .tab = NULL,
        .parentID = WINDOW_ID_FILEMENU_MAIN,
        .fpUpdate = { WINDOW_UPDATE_SHOW } ,
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[1] },
    },
    {
        .windowID = WINDOW_ID_FILEMENU_CURSOR,
        .pos = {
            .x = 0,
            .y = 0,
        },
        .width = 320,
        .height = 240,
        .priority = WINDOW_PRIORITY_0,
        .fpDrawContents = filemenu_draw_cursor,
        .tab = NULL,
        .parentID = -1,
        .fpUpdate = { WINDOW_UPDATE_SHOW },
        .extraFlags = 0,
        .style = { .customStyle = &filemenu_windowStyles[1] },
    },
};

extern Gfx filemenu_dl_copyarrow[];
extern Gfx D_8024B6F0[];
extern Gfx D_8024B708[];

BSS s32 filemenu_iterFileIdx;
BSS s32 filemenu_pressedButtons;
BSS s32 filemenu_cursorHudElem;
BSS s32 filemenu_heldButtons;
BSS s8 filemenu_filename_pos;
BSS s32 filemenu_loadedFileIdx;
BSS s8 filemenu_currentMenu;
BSS s32 filemenu_8024C09C;
BSS s32 filemenu_cursorHudElemID[1];
BSS s32 filemenu_8024C0A4[3];
BSS s32 filemenu_hudElemIDs[20];
BSS s32 filemenu_createfile_hudElems[4];

#if VERSION_PAL
BSS s32 D_802517D0[1];
BSS s32 D_802517D4[1];
BSS u16 D_802517E0[2][0x400] ALIGNED(16);
#endif

#if VERSION_IQUE
BSS u8 filemenu_glyphBuffer[20][0x80];
#endif

void filemenu_draw_rect(s32 ulx, s32 uly, s32 lrx, s32 lry, s32 tileIdx, s32 uls, s32 ult, s32 dsdx, s32 dtdy) {
    if (ulx <= -2688 || uly <= -2688 || lrx <= 0 || lry <= 0) {
        return;
    }
    if (ulx >= 1280 || uly >= 960 || lrx >= 2688 || lry >= 2688) {
        return;
    }
    gSPScisTextureRectangle(gMainGfxPos++, ulx, uly, lrx, lry, tileIdx, uls, ult, dsdx, dtdy);
}

void filemenu_set_selected(MenuPanel* menu, s32 col, s32 row) {
    menu->col = col;
    menu->row = row;
    menu->selected = menu->gridData[(menu->page * menu->numCols * menu->numRows) +
                                    (menu->numCols * menu->row) + menu->col];
}

void filemenu_set_cursor_alpha(s32 alpha) {
    filemenu_cursorGoalAlpha = alpha;
    filemenu_cursorGoalAlpha2 = alpha;
}

void filemenu_set_cursor_goal_pos(s32 windowID, s32 posX, s32 posY) {
    Window* window = &gWindows[windowID];

    if (D_80249BB0
            || get_game_mode() == GAME_MODE_END_FILE_SELECT
            || get_game_mode() == GAME_MODE_END_LANGUAGE_SELECT) {
        if (D_80249BB0) {
            s32 i;

            for (i = WINDOW_ID_FILEMENU_MAIN; i < ARRAY_COUNT(gWindows); i++) {
                Window* window = &gWindows[i];
                s8 parent = window->parent;

                if ((parent == -1 || parent == WINDOW_ID_FILEMENU_MAIN) && (window->flags & WINDOW_FLAG_INITIAL_ANIMATION)) {
                    break;
                }
            }
            if (i >= ARRAY_COUNT(gWindows)) {
                D_80249BB0 = FALSE;
            }
        }
        filemenu_cursor_targetX = posX;
        filemenu_cursor_posX = posX;
        filemenu_cursor_targetY = posY;
        filemenu_cursor_posY = posY;
    } else if (!(window->flags & WINDOW_FLAG_INITIAL_ANIMATION) &&
                (window->parent == -1 || !(gWindows[window->parent].flags & WINDOW_FLAG_INITIAL_ANIMATION))) {
        filemenu_cursor_targetX = posX;
        filemenu_cursor_targetY = posY;
    }
}

void filemenu_update_cursor(void) {
    s32 targetPosX = filemenu_cursor_targetX;
    s32 targetPosY = filemenu_cursor_targetY;
    s32 xDelta;
    s32 yDelta;
    s32 i;

    xDelta = (targetPosX - filemenu_cursor_posX) * 0.5;
    yDelta = (targetPosY - filemenu_cursor_posY) * 0.5;

    if ((targetPosX != filemenu_cursor_posX) || (targetPosY != filemenu_cursor_posY)) {
        if ((xDelta == 0) && (yDelta == 0)) {
            filemenu_cursor_posX = targetPosX;
            filemenu_cursor_posY = targetPosY;
        }
    }

    filemenu_cursor_posX += xDelta;
    filemenu_cursor_posY += yDelta;

    if (filemenu_cursorGoalAlpha == 0) {
        filemenu_cursor_alpha -= 128;
        if (filemenu_cursor_alpha < 0) {
            filemenu_cursor_alpha = 0;
        }
    } else {
        filemenu_cursor_alpha += 32;
        if (filemenu_cursor_alpha > 255) {
            filemenu_cursor_alpha = 255;
        }
    }

    for (i = WINDOW_ID_FILEMENU_MAIN; i < ARRAY_COUNT(gWindows); i++) {
        Window* window = &gWindows[i];
        s8 parent = window->parent;

        if ((parent == -1 || parent == WINDOW_ID_FILEMENU_MAIN) && (window->flags & WINDOW_FLAG_INITIAL_ANIMATION)) {
            break;
        }
    }

    if (D_80249BB8 == 0) {
        if (filemenu_cursorGoalAlpha == 0) {
            D_80249BB8 = 1;
        }
    }

    if (i >= ARRAY_COUNT(gWindows)) {
        if (filemenu_cursorGoalAlpha2 == 255) {
            if (D_80249BB8 != 0) {
                D_80249BB8--;
                if (D_80249BB8 == 0) {
                    filemenu_cursor_posX = filemenu_cursor_targetX;
                    filemenu_cursor_posY = filemenu_cursor_targetY;
                }
            }
        }
        if (D_80249BB8 == 0) {
            filemenu_cursorGoalAlpha = filemenu_cursorGoalAlpha2;
        }
    } else if (filemenu_cursorGoalAlpha == 0) {
        D_80249BB8 = 1;
    }

    filemenu_cursorGoalAlpha2 = 255;
}

void filemenu_update(void) {
    MenuPanel* menu = filemenu_menus[filemenu_currentMenu];
    MenuPanel** menuIt;
    s32 i;

    for (i = WINDOW_ID_FILEMENU_MAIN; i < ARRAY_COUNT(gWindows); i++) {
        if ((gWindows[i].parent == -1 || gWindows[i].parent == WINDOW_ID_FILEMENU_MAIN) &&
            (gWindows[i].flags & WINDOW_FLAG_INITIAL_ANIMATION))
        {
            break;
        }
    }

    if (i >= ARRAY_COUNT(gWindows)) {
        filemenu_heldButtons = gGameStatusPtr->heldButtons[0];
        filemenu_pressedButtons = gGameStatusPtr->pressedButtons[0];
    } else {
        filemenu_heldButtons = 0;
        filemenu_pressedButtons = 0;
    }

    if (filemenu_pressedButtons & BUTTON_B) {
        filemenu_pressedButtons &= ~BUTTON_A;
    }
    if (filemenu_heldButtons & BUTTON_B) {
        filemenu_heldButtons &= ~BUTTON_A;
    }

    if (menu->initialized) {
        if (menu->fpHandleInput != NULL) {
            menu->fpHandleInput(menu);
        }
    }

    // TODO clean up bad match
    menuIt = filemenu_menus;
    for (i = 0; i < ARRAY_COUNT(filemenu_menus); i++, menuIt++) {
        menu = *menuIt;
        if (menu->initialized && menu->fpUpdate != NULL) {
            menu->fpUpdate(menu);
        }
    }
}

void func_8024330C(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAG_HIDDEN;
    }

    if (updateCounter < ARRAY_COUNT(D_80249BBC)) {
        *posX -= D_80249BBC[updateCounter];
    } else {
        *posX -= D_80249BBC[ARRAY_COUNT(D_80249BBC) - 1];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void filemenu_update_show_name_input(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAG_HIDDEN;
    }

    if (updateCounter < ARRAY_COUNT(D_80249BDC)) {
        *posX += D_80249BDC[updateCounter];
    } else {
        *posX += D_80249BDC[ARRAY_COUNT(D_80249BDC) - 1];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void filemenu_update_show_options_left(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAG_HIDDEN;
    }

    if (updateCounter < ARRAY_COUNT(D_80249BFC)) {
        *posX -= D_80249BFC[updateCounter];
    } else {
        *posX -= D_80249BFC[ARRAY_COUNT(D_80249BFC) - 1];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void filemenu_update_show_options_right(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAG_HIDDEN;
    }

    if (updateCounter < ARRAY_COUNT(D_80249C1C)) {
        *posX += D_80249C1C[updateCounter];
    } else {
        *posX += D_80249C1C[ARRAY_COUNT(D_80249C1C) - 1];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void filemenu_update_show_options_bottom(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAG_HIDDEN;
    }

    if (updateCounter < ARRAY_COUNT(D_80249C3C)) {
        *posY += D_80249C3C[updateCounter];
    } else {
        *posY += D_80249C3C[ARRAY_COUNT(D_80249C3C) - 1];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void filemenu_update_show_title(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAG_HIDDEN;
    }

    if (updateCounter < ARRAY_COUNT(D_80249C5C)) {
        *posY -= D_80249C5C[updateCounter];
    } else {
        *posY -= D_80249C5C[ARRAY_COUNT(D_80249C5C) - 1];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void func_802435C4(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < ARRAY_COUNT(D_80249C7C)) {
        *posX += D_80249C7C[updateCounter];
    } else {
        *posX += D_80249C7C[ARRAY_COUNT(D_80249C7C) - 1];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAG_HIDDEN;
    }
}

void filemenu_update_hidden_name_input(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < ARRAY_COUNT(D_80249C90)) {
        *posX -= D_80249C90[updateCounter];
    } else {
        *posX -= D_80249C90[ARRAY_COUNT(D_80249C90) - 1];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAG_HIDDEN;
    }
}

void filemenu_update_hidden_options_left(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < ARRAY_COUNT(D_80249CA4)) {
        *posX += D_80249CA4[updateCounter];
    } else {
        *posX += D_80249CA4[ARRAY_COUNT(D_80249CA4) - 1];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAG_HIDDEN;
    }
}

void filemenu_update_hidden_options_right(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < ARRAY_COUNT(D_80249CB8)) {
        *posX -= D_80249CB8[updateCounter];
    } else {
        *posX -= D_80249CB8[ARRAY_COUNT(D_80249CB8) - 1];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAG_HIDDEN;
    }
}

void filemenu_update_hidden_title(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < ARRAY_COUNT(D_80249CCC)) {
        *posY += D_80249CCC[updateCounter];
    } else {
        *posY += D_80249CCC[ARRAY_COUNT(D_80249CCC) - 1];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAG_HIDDEN;
    }
}

void filemenu_update_hidden_options_bottom(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < ARRAY_COUNT(D_80249CE0)) {
        *posY -= D_80249CE0[updateCounter];
    } else {
        *posY -= D_80249CE0[ARRAY_COUNT(D_80249CE0) - 1];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAG_HIDDEN;
    }
}

void filemenu_update_show_with_rotation(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;

    if (updateCounter == 0) {
        window->flags &= ~WINDOW_FLAG_HIDDEN;
    }

    if (updateCounter < ARRAY_COUNT(D_80249CF4)) {
        *rotY += D_80249CF4[updateCounter];
        *flags = DRAW_FLAG_CULL_BACK | DRAW_FLAG_ROTSCALE;
    } else {
        *flags = 0;
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void filemenu_update_hidden_with_rotation(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < 10) { // TODO: array count?
        *rotY += -D_80249D14[updateCounter];
        *flags = DRAW_FLAG_CULL_BACK | DRAW_FLAG_ROTSCALE;
    } else {
        *flags = 0;
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAG_HIDDEN;
    }
}

void filemenu_update_select_file(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    Window* parent = &gWindows[window->parent];
    s32 updateCounter = window->updateCounter;
    f32 temp_f4 = updateCounter / 16.0f;
    s32 widthDelta = (parent->width / 2) - (window->width / 2);
    s32 heightDelta = (parent->height / 2) - (window->height / 2) - 34;

    if (updateCounter < 16) {
        *posX += -window->pos.x + (((f32) (widthDelta - window->pos.x) * temp_f4) + window->pos.x);
        *posY += -window->pos.y + (((f32) (heightDelta - window->pos.y) * temp_f4) + window->pos.y);
    } else {
        *posX += -window->pos.x + ((f32) (widthDelta - window->pos.x) + window->pos.x);
        *posY += -window->pos.y + ((f32) (heightDelta - window->pos.y) + window->pos.y);
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void filemenu_update_deselect_file(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;
    f32 temp_f4 = 1.0f - (updateCounter / 16.0f);

    if (updateCounter < 16) {
        *posX += -window->pos.x + (((80 - window->pos.x) * temp_f4) + window->pos.x);
        *posY += -window->pos.y + (((36 - window->pos.y) * temp_f4) + window->pos.y);
    } else {
        *posX += -window->pos.x + ((80 - window->pos.x) * 0.0f + window->pos.x);
        *posY += -window->pos.y + ((36 - window->pos.y) * 0.0f + window->pos.y);
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void filemenu_update_show_name_confirm(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;
    u32 counter;

    gDPPipeSync(gMainGfxPos++);
    gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
    gDPSetCombineMode(gMainGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, 140);

    if (updateCounter < 10) {
        s32 x = updateCounter * 16;
        s32 y = updateCounter * 12;
        filemenu_draw_rect(0, 0, SCREEN_WIDTH * 4, y * 4, 0, 0, 0, 0, 0);
        filemenu_draw_rect(0, (SCREEN_HEIGHT - y) * 4, SCREEN_WIDTH * 4, SCREEN_HEIGHT * 4, 0, 0, 0, 0, 0);
        filemenu_draw_rect(0, y * 4, x * 4, (SCREEN_HEIGHT - y) * 4, 0, 0, 0, 0, 0);
        filemenu_draw_rect((SCREEN_WIDTH - x) * 4, y * 4, SCREEN_WIDTH * 4, (SCREEN_HEIGHT - y) * 4, 0, 0, 0, 0, 0);
    } else {
        filemenu_draw_rect(0, 0, SCREEN_WIDTH * 4, SCREEN_HEIGHT * 4, 0, 0, 0, 0, 0);
    }

    counter = updateCounter - 10;
    if (counter < 10) {
        window->flags &= ~WINDOW_FLAG_HIDDEN;
        *posY -= D_80249D34[counter];
    }
    if (updateCounter >= 20) {
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void filemenu_update_hidden_name_confirm(
    s32 windowIdx,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIdx];
    s32 updateCounter = window->updateCounter;

    if (updateCounter < ARRAY_COUNT(D_80249D48)) {
        gDPPipeSync(gMainGfxPos++);
        gDPSetCycleType(gMainGfxPos++, G_CYC_1CYCLE);
        gDPSetCombineMode(gMainGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gDPSetRenderMode(gMainGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, 140 - updateCounter * 14);
        filemenu_draw_rect(0, 0, 1280, 960, 0, 0, 0, 0, 0);
        *posY -= D_80249D48[updateCounter];
    } else {
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAG_HIDDEN;
    }
}

#if VERSION_PAL
void filemenu_update_pal_80247f40(
    s32 windowIndex,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIndex];
    s32 var_a1 = window->updateCounter;
    s32 var_a3 = 0;
    s32 var_v1;

    switch (windowIndex) {
        case WINDOW_ID_FILEMENU_FILE0_INFO:
            var_a3 = 0;
            break;
        case WINDOW_ID_FILEMENU_FILE1_INFO:
            var_a3 = 1;
            break;
        case WINDOW_ID_FILEMENU_FILE2_INFO:
            var_a3 = 2;
            break;
        case WINDOW_ID_FILEMENU_FILE3_INFO:
            var_a3 = 3;
            break;
    }
    var_v1 = gCurrentLanguage;
    var_v1 -= var_a3;
    var_v1 = abs(var_v1);

    var_a1 -= (var_v1 * 3);
    if (var_a1 < 0) {
        var_a1 = 0;
    }
    if (var_a1 == 0) {
        window->flags &= ~WINDOW_FLAG_HIDDEN;
    }
    if (var_a1 < ARRAY_COUNT(D_filemenu_8024EB5C)) {
        *posX -= D_filemenu_8024EB5C[var_a1];
    } else {
        *posX -= D_filemenu_8024EB5C[ARRAY_COUNT(D_filemenu_8024EB5C) - 1];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
    }
}

void filemenu_selectlanguage_80248018(
    s32 windowIndex,
    s32* flags,
    s32* posX, s32* posY, s32* posZ,
    f32* scaleX, f32* scaleY,
    f32* rotX, f32* rotY, f32* rotZ,
    s32* darkening,
    s32* opacity
) {
    Window* window = &gWindows[windowIndex];
    s32 var_a1 = window->updateCounter;
    s32 var_a3 = 0;
    s32 var_v1;

    switch (windowIndex) {
        case WINDOW_ID_FILEMENU_FILE0_INFO:
            var_a3 = 0;
            break;
        case WINDOW_ID_FILEMENU_FILE1_INFO:
            var_a3 = 1;
            break;
        case WINDOW_ID_FILEMENU_FILE2_INFO:
            var_a3 = 2;
            break;
        case WINDOW_ID_FILEMENU_FILE3_INFO:
            var_a3 = 3;
            break;
    }
    var_v1 = gCurrentLanguage;
    var_v1 -= var_a3;
    if (var_v1 < 0) {
        var_v1 = -var_v1;
    }
    var_a1 -= (var_v1 * 3);
    if (var_a1 < 0) {
        var_a1 = 0;
    }
    if (var_a1 < ARRAY_COUNT(D_filemenu_8024EB80)) {
        *posX -= D_filemenu_8024EB80[var_a1];
    } else {
        *posX -= D_filemenu_8024EB80[ARRAY_COUNT(D_filemenu_8024EB80) - 1];
        window->flags &= ~WINDOW_FLAG_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAG_HIDDEN;
    }

    // TODO: ARRAY_COUNT?
    if (var_a1 >= 0x10) {
        filemenu_cursor_alpha = 0;
    }
}
#endif

void filemenu_draw_cursor(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 temp_a1;

    filemenu_update_cursor();
    temp_a1 = filemenu_cursor_alpha;
    if (temp_a1 > 0) {
        if (temp_a1 > 255) {
            temp_a1 = 255;
        }
        hud_element_set_alpha(filemenu_cursorHudElemID[0], temp_a1);
        hud_element_set_render_pos(filemenu_cursorHudElemID[0], baseX + filemenu_cursor_posX, baseY + filemenu_cursor_posY);
        hud_element_draw_without_clipping(filemenu_cursorHudElemID[0]);
    }
}

#if VERSION_PAL
#define PAGE_4 (3)
#else
#define PAGE_4 (4)
#endif

void filemenu_draw_contents_copy_arrow(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity,
                                       s32 darkening)
{
    Matrix4f sp20, sp60;
    MenuPanel* menu0 = filemenu_menus[0];
    f32 startX, startZ;
    f32 endX, endZ;
    f32 temp_f28;

    if (menu0->page == PAGE_4 && menu0->selected < 4) {
        if (menu0->selected != filemenu_loadedFileIdx && filemenu_currentMenu != 2) {
            switch (filemenu_loadedFileIdx) {
                case 0:
                    startX = 130.0f;
                    startZ = 90.0f;
                    break;
                case 1:
                    startX = 190.0f;
                    startZ = 90.0f;
                    break;
                case 2:
                    startX = 130.0f;
                    startZ = 150.0f;
                    break;
                default:
                    startX = 190.0f;
                    startZ = 150.0f;
                    break;
            }

            switch (filemenu_menus[0]->selected) {
                case 0:
                    endX = 130.0f;
                    endZ = 90.0f;
                    break;
                case 1:
                    endX = 190.0f;
                    endZ = 90.0f;
                    break;
                case 2:
                    endX = 130.0f;
                    endZ = 150.0f;
                    break;
                default:
                    endX = 190.0f;
                    endZ = 150.0f;
                    break;
            }

            temp_f28 = -atan2(startX, startZ, endX, endZ) - 90.0f;

            gSPViewport(gMainGfxPos++, &D_80249D60);

            guOrthoF(sp20, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, -100.0f, 100.0f, 1.0f);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gSPDisplayList(gMainGfxPos++, filemenu_dl_copyarrow);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 0, 0, 0, 128);
            gDPSetEnvColor(gMainGfxPos++, 0, 0, 0, 0);

            guTranslateF(sp20, startX + 4.0f, startZ + 4.0f, 0.0f);
            guScaleF(sp60, -1.0f, 1.0f, 1.0f);
            guMtxCatF(sp60, sp20, sp20);
            guRotateF(sp60, temp_f28, 0.0f, 0.0f, 1.0f);
            guMtxCatF(sp60, sp20, sp20);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_8024B6F0);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

            guTranslateF(sp60, D_80249D70[gGameStatusPtr->frameCounter % ARRAY_COUNT(D_80249D70)], 0.0f, 0.0f);
            guMtxCatF(sp60, sp20, sp20);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPSetTileSize(gMainGfxPos++, 1, (gGameStatusPtr->frameCounter * 8) % 512, 0,
                                               ((gGameStatusPtr->frameCounter * 8) % 512) + 60, 0);
            gSPDisplayList(gMainGfxPos++, D_8024B708);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
            gDPSetPrimColor(gMainGfxPos++, 0, 0, 230, 230, 230, 255);
            gDPSetEnvColor(gMainGfxPos++, 232, 40, 160, 0);

            guTranslateF(sp20, startX, startZ, 0.0f);
            guScaleF(sp60, -1.0f, 1.0f, 1.0f);
            guMtxCatF(sp60, sp20, sp20);
            guRotateF(sp60, temp_f28, 0.0f, 0.0f, 1.0f);
            guMtxCatF(sp60, sp20, sp20);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(gMainGfxPos++, D_8024B6F0);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);

            guTranslateF(sp60, D_80249D70[(gGameStatusPtr->frameCounter % ARRAY_COUNT(D_80249D70))], 0.0f, 0.0f);
            guMtxCatF(sp60, sp20, sp20);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMainGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPSetTileSize(gMainGfxPos++, 1, (gGameStatusPtr->frameCounter * 8) % 512, 0,
                                               ((gGameStatusPtr->frameCounter * 8) % 512) + 60, 0);
            gSPDisplayList(gMainGfxPos++, D_8024B708);
            gSPPopMatrix(gMainGfxPos++, G_MTX_MODELVIEW);
        }
    }
}

void func_PAL_8002B574(void); // TODO identify

// TODO bad match, look into
void filemenu_init(s32 arg0) {
    MenuPanel** panelIt;
    MenuPanel* menu;
    s32 i;

    DMA_COPY_SEGMENT(ui_images_filemenu_pause);

    for (i = 0; i < ARRAY_COUNT(filemenu_cursorHudElemID); i++) {
        filemenu_cursorHudElemID[i] = hud_element_create(filemenu_cursor_hudElemScripts[i]);
        hud_element_set_flags(filemenu_cursorHudElemID[i], HUD_ELEMENT_FLAG_DROP_SHADOW | HUD_ELEMENT_FLAG_80);
    }

    filemenu_cursorHudElem = filemenu_cursorHudElemID[0];
    if (arg0 == 0) {
        filemenu_common_windowBPs[0].style.customStyle->background.imgData = NULL; // ???
    }
    setup_pause_menu_tab(filemenu_common_windowBPs, ARRAY_COUNT(filemenu_common_windowBPs));

#if VERSION_PAL
    if (arg0 != 2) {
        filemenu_currentMenu = 0;
        menu = filemenu_menus[0];
        menu->page = filemenu_currentMenu;
        func_PAL_8002B574();

        if (menu->page == 0) {
            fio_load_globals();
            if (gSaveGlobals.lastFileSelected >= 4) {
                gSaveGlobals.lastFileSelected = 0;
            }
            gGameStatusPtr->saveSlot = gSaveGlobals.lastFileSelected;
        }

        filemenu_set_selected(menu, (gGameStatusPtr->saveSlot & 1) * 2, gGameStatusPtr->saveSlot >> 1);

        panelIt = filemenu_menus;
        for (i = 0; i < ARRAY_COUNT(filemenu_menus) - 1; i++, panelIt++) {
            if ((*panelIt)->fpInit != NULL) {
                (*panelIt)->fpInit((*panelIt));
            }
        }
        update_window_hierarchy(WINDOW_ID_PAUSE_DECRIPTION, 64);
    } else {
        filemenu_currentMenu = 4;
        filemenu_set_selected(filemenu_menus[4], 0, gCurrentLanguage);

        panelIt = filemenu_menus;
        for (i = 0; i < ARRAY_COUNT(filemenu_menus); i++, panelIt++) {
            if (i == 4) {
                if ((*panelIt)->fpInit != NULL) {
                    (*panelIt)->fpInit((*panelIt));
                }
            }
        }
        update_window_hierarchy(WINDOW_ID_PAUSE_DECRIPTION, 64);
    }
#else
    menu = filemenu_menus[0];
    filemenu_currentMenu = 0;

    if (arg0 == 0) {
        menu->page = 0;
    } else {
        menu->page = 2;
    }

    if (menu->page == 0) {
        for (i = 0; i < ARRAY_COUNT(filemenu_menus); i++) {
            if (!fio_load_game(i)) {
                gSaveSlotHasData[i] = FALSE;
            } else {
                gSaveSlotMetadata[i] = gCurrentSaveFile.metadata;
                gSaveSlotHasData[i] = TRUE;
            }
        }

        if (menu->page == 0) {
            fio_load_globals();
            if (gSaveGlobals.lastFileSelected >= 4) {
                gSaveGlobals.lastFileSelected = 0;
            }
            gGameStatusPtr->saveSlot = gSaveGlobals.lastFileSelected;
        }
    }

    filemenu_set_selected(menu, (gGameStatusPtr->saveSlot & 1) * 2, gGameStatusPtr->saveSlot >> 1);

    panelIt = filemenu_menus;
    for (i = 0; i < ARRAY_COUNT(filemenu_menus); i++, panelIt++) {
        if ((*panelIt)->fpInit != NULL) {
            (*panelIt)->fpInit((*panelIt));
        }
    }
    update_window_hierarchy(WINDOW_ID_PAUSE_DECRIPTION, 64);
#endif
}

// TODO bad match, look into
void filemenu_cleanup(void) {
    MenuPanel** panelIt;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(filemenu_cursorHudElemID); i++) {
        hud_element_free(filemenu_cursorHudElemID[i]);
    }

    panelIt = filemenu_menus;
    for (i = 0; i < ARRAY_COUNT(filemenu_menus); i++, panelIt++) {
        if ((*panelIt)->initialized) {
            if ((*panelIt)->fpCleanup != NULL) {
                (*panelIt)->fpCleanup(*panelIt);
            }
        }
    }

    for (i = WINDOW_ID_FILEMENU_MAIN; i < ARRAY_COUNT(gWindows); i++) {
        set_window_update(i, WINDOW_UPDATE_HIDE);
    }

    set_window_update(WINDOW_ID_PAUSE_TUTORIAL, WINDOW_UPDATE_HIDE);
    set_window_update(WINDOW_ID_PAUSE_DECRIPTION, WINDOW_UPDATE_HIDE);
    func_80244BC4();
}

s32 func_80244BC4() {
    if (filemenu_menus[0]->page == 0 && filemenu_currentMenu == 1 && filemenu_menus[1]->selected == 0) {
        return 2;
    } else if (filemenu_menus[0]->page == 0 && filemenu_menus[0]->selected < 4) {
        return 1;
    } else {
        return 0;
    }
}
