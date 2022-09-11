#include "common.h"
#include "filemenu.h"
#include "hud_element.h"
#include "fio.h"
#include "ld_addrs.h"

void filemenu_draw_cursor(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void filemenu_draw_contents_copy_arrow(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
);

extern HudScript D_80241ECC;
extern MenuPanel D_8024A098;
extern MenuPanel D_8024A114;
extern MenuPanel D_8024A158;
extern MenuPanel D_8024A1D8;
extern WindowStyleCustom D_8024BA60;
extern WindowStyleCustom D_8024BA98;
extern s32 D_8024C088;

HudScript* D_80249B80[] = { &D_80241ECC };
MenuPanel* filemenu_menus[4] = { &D_8024A098, &D_8024A114, &D_8024A158, &D_8024A1D8 };
s32 D_80249B94 = SCREEN_WIDTH / 2;
s32 D_80249B98 = -SCREEN_HEIGHT / 2;
s32 D_80249B9C = 0;
s32 D_80249BA0 = SCREEN_WIDTH / 2;
s32 D_80249BA4 = -SCREEN_HEIGHT / 2;
s32 filemenu_cursorGoalAlpha = 0;
s32 filemenu_cursorGoalAlpha2 = 0;
s32 D_80249BB0[] = { TRUE, FALSE };
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
s32 D_80249D4C = 0; // padding?
Vp D_80249D60 = {
    .vp = {
        .vscale = { 640, 480, 511, 0},
        .vtrans = { 640, 480, 511, 0},
    }
};
f32 D_80249D70[15] = { 7.0f, 12.5f, 13.0f, 14.5f, 14.0f, 13.0f, 11.5f, 9.5f, 7.5f, 5.5f, 3.5f, 2.0f, 1.0f, 0.5f, 0.0f };

MenuWindowBP D_80249DAC[3] = {
    {
        .windowID = 0x2C,
        .pos = {
            .x = 16,
            .y = 24,
        },
        .width = 288,
        .height = 192,
        .priority = 0,
        .fpDrawContents = NULL,
        .tab = NULL,
        .parentID = -1,
        .fpUpdate = { 1 },
        .extraFlags = 0x40,
        .style = { .customStyle = &D_8024BA60 },
    },
    {
        .windowID = 0x18,
        .pos = {
            .x = 0,
            .y = 0,
        },
        .width = 0x120,
        .height = 0xC0,
        .priority = 0,
        .fpDrawContents = filemenu_draw_contents_copy_arrow,
        .tab = NULL,
        .parentID = 0x2C,
        .fpUpdate = { 1} ,
        .extraFlags = 0x00,
        .style = { .customStyle = &D_8024BA98 },
    },
    {
        .windowID = 0x17,
        .pos = {
            .x = 0,
            .y = 0,
        },
        .width = 0x140,
        .height = 0xF0,
        .priority = 0,
        .fpDrawContents = filemenu_draw_cursor,
        .tab = NULL,
        .parentID = -1,
        .fpUpdate = { 1 },
        .extraFlags = 0x00,
        .style = { .customStyle = &D_8024BA98 },
    },
};

extern Gfx D_8024B600[];
extern Gfx D_8024B6F0[];
extern Gfx D_8024B708[];

BSS s32 filemenu_iterFileIdx;
BSS s32 filemenu_pressedButtons;
BSS s32 filemenu_8024C088;
BSS s32 filemenu_heldButtons;
BSS s32 filemenu_8024C090;
BSS s32 filemenu_loadedFileIdx;
BSS s8 filemenu_8024C098;
BSS s32 filemenu_8024C09C;
BSS s32 filemenu_cursorHudElemID[1];
BSS s32 filemenu_8024C0A4[3];
BSS s32 filemenu_hudElemIDs[20];
BSS s32 filemenu_8024C100[4];
BSS u8 filemenu_8024C110[8];

s32 func_80244BC4(void);

void mainmenu_draw_rect(s32 ulx, s32 uly, s32 lrx, s32 lry, s32 tileDescriptor, s32 uls, s32 ult, s32 dsdx, s32 dtdy) {
    if (ulx <= -2688 || uly <= -2688 || lrx <= 0 || lry <= 0) {
        return;
    }
    if (ulx >= 1280 || uly >= 960 || lrx >= 2688 || lry >= 2688) {
        return;
    }
    gSPScisTextureRectangle(gMasterGfxPos++, ulx, uly, lrx, lry, tileDescriptor, uls, ult, dsdx, dtdy);
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

    if (D_80249BB0[0]
            || get_game_mode() == GAME_MODE_END_FILE_SELECT
            || get_game_mode() == GAME_MODE_END_LANGUAGE_SELECT) {
        if (D_80249BB0[0]) {
            s32 i;

            for (i = 0x2C; i < ARRAY_COUNT(gWindows); i++) {
                Window* window = &gWindows[i];
                s8 parent = window->parent;

                if ((parent == -1 || parent == 0x2C) && (window->flags & 8)) {
                    break;
                }
            }
            if (i >= ARRAY_COUNT(gWindows)) {
                D_80249BB0[0] = FALSE;
            }
        }
        D_80249BA0 = posX;
        D_80249B94 = posX;
        D_80249BA4 = posY;
        D_80249B98 = posY;
    } else if (!(window->flags & 0x8) && (window->parent == -1 || !(gWindows[window->parent].flags & 8))) {
        D_80249BA0 = posX;
        D_80249BA4 = posY;
    }
}

void filemenu_update_cursor(void) {
    s32 targetPosX = D_80249BA0;
    s32 targetPosY = D_80249BA4;
    s32 xDelta;
    s32 yDelta;
    s32 i;

    xDelta = (targetPosX - D_80249B94) * 0.5;
    yDelta = (targetPosY - D_80249B98) * 0.5;

    if ((targetPosX != D_80249B94) || (targetPosY != D_80249B98)) {
        if ((xDelta == 0) && (yDelta == 0)) {
            D_80249B94 = targetPosX;
            D_80249B98 = targetPosY;
        }
    }

    D_80249B94 += xDelta;
    D_80249B98 += yDelta;

    if (filemenu_cursorGoalAlpha == 0) {
        D_80249B9C -= 128;
        if (D_80249B9C < 0) {
            D_80249B9C = 0;
        }
    } else {
        D_80249B9C += 32;
        if (D_80249B9C > 255) {
            D_80249B9C = 255;
        }
    }

    for (i = 0x2C; i < ARRAY_COUNT(gWindows); i++) {
        Window* window = &gWindows[i];
        s8 parent = window->parent;

        if ((parent == -1 || parent == 0x2C) && (window->flags & 8)) {
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
                    D_80249B94 = D_80249BA0;
                    D_80249B98 = D_80249BA4;
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
    MenuPanel* menu = filemenu_menus[filemenu_8024C098];
    MenuPanel** menuIt;
    s32 i;

    for (i = 0x2C; i < ARRAY_COUNT(gWindows); i++) {
        if ((gWindows[i].parent == -1 || gWindows[i].parent == 0x2C) &&
            (gWindows[i].flags & WINDOW_FLAGS_INITIAL_ANIMATION))
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
        window->flags &= ~WINDOW_FLAGS_HIDDEN;
    }

    if (updateCounter < ARRAY_COUNT(D_80249BBC)) {
        *posX -= D_80249BBC[updateCounter];
    } else {
        *posX -= D_80249BBC[ARRAY_COUNT(D_80249BBC) - 1];
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
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
        window->flags &= ~WINDOW_FLAGS_HIDDEN;
    }

    if (updateCounter < ARRAY_COUNT(D_80249BDC)) {
        *posX += D_80249BDC[updateCounter];
    } else {
        *posX += D_80249BDC[ARRAY_COUNT(D_80249BDC) - 1];
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
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
        window->flags &= ~WINDOW_FLAGS_HIDDEN;
    }

    if (updateCounter < ARRAY_COUNT(D_80249BFC)) {
        *posX -= D_80249BFC[updateCounter];
    } else {
        *posX -= D_80249BFC[ARRAY_COUNT(D_80249BFC) - 1];
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
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
        window->flags &= ~WINDOW_FLAGS_HIDDEN;
    }

    if (updateCounter < ARRAY_COUNT(D_80249C1C)) {
        *posX += D_80249C1C[updateCounter];
    } else {
        *posX += D_80249C1C[ARRAY_COUNT(D_80249C1C) - 1];
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
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
        window->flags &= ~WINDOW_FLAGS_HIDDEN;
    }

    if (updateCounter < ARRAY_COUNT(D_80249C3C)) {
        *posY += D_80249C3C[updateCounter];
    } else {
        *posY += D_80249C3C[ARRAY_COUNT(D_80249C3C) - 1];
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
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
        window->flags &= ~WINDOW_FLAGS_HIDDEN;
    }

    if (updateCounter < ARRAY_COUNT(D_80249C5C)) {
        *posY -= D_80249C5C[updateCounter];
    } else {
        *posY -= D_80249C5C[ARRAY_COUNT(D_80249C5C) - 1];
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
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
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAGS_HIDDEN;
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
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAGS_HIDDEN;
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
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAGS_HIDDEN;
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
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAGS_HIDDEN;
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
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAGS_HIDDEN;
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
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAGS_HIDDEN;
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
        window->flags &= ~WINDOW_FLAGS_HIDDEN;
    }

    if (updateCounter < ARRAY_COUNT(D_80249CF4)) {
        *rotY += D_80249CF4[updateCounter];
        *flags = DRAW_FLAGS_CULL_BACK | DRAW_FLAGS_ROTSCALE;
    } else {
        *flags = 0;
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
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
        *flags = DRAW_FLAGS_CULL_BACK | DRAW_FLAGS_ROTSCALE;
    } else {
        *flags = 0;
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAGS_HIDDEN;
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
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
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
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
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
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    u32 temp_v1;

    gDPPipeSync(gMasterGfxPos++);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gDPSetCombineMode(gMasterGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, 140);

    if (updateCounter < 10) {
        temp_s2 = updateCounter * 48;
        temp_s3 = updateCounter * 12;
        mainmenu_draw_rect(0, 0, 1280, temp_s2, 0, 0, 0, 0, 0);
        temp_s1 = (SCREEN_HEIGHT - temp_s3) * 4;
        mainmenu_draw_rect(0, temp_s1, 1280, 960, 0, 0, 0, 0, 0);
        mainmenu_draw_rect(0, temp_s2, updateCounter * 64, temp_s1, 0, 0, 0, 0, 0);
        mainmenu_draw_rect((SCREEN_WIDTH - (updateCounter * 16)) * 4, temp_s2, 1280, temp_s1, 0, 0, 0, 0, 0);
    } else {
        mainmenu_draw_rect(0, 0, 1280, 960, 0, 0, 0, 0, 0);
    }

    temp_v1 = updateCounter - 10;
    if (temp_v1 < 10) {
        window->flags &= ~WINDOW_FLAGS_HIDDEN;
        *posY -= D_80249D34[temp_v1];
    }
    if (updateCounter >= 20) {
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
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
        gDPPipeSync(gMasterGfxPos++);
        gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
        gDPSetCombineMode(gMasterGfxPos++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gDPSetRenderMode(gMasterGfxPos++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, 140 - (updateCounter * 14));
        mainmenu_draw_rect(0, 0, 1280, 960, 0, 0, 0, 0, 0);
        *posY -= D_80249D48[updateCounter];
    } else {
        window->flags &= ~WINDOW_FLAGS_INITIAL_ANIMATION;
        window->flags |= WINDOW_FLAGS_HIDDEN;
    }
}

void filemenu_draw_cursor(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening) {
    s32 temp_a1;

    filemenu_update_cursor();
    temp_a1 = D_80249B9C;
    if (temp_a1 > 0) {
        if (temp_a1 > 255) {
            temp_a1 = 255;
        }
        hud_element_set_alpha(filemenu_cursorHudElemID[0], temp_a1);
        hud_element_set_render_pos(filemenu_cursorHudElemID[0], baseX + D_80249B94, baseY + D_80249B98);
        hud_element_draw_without_clipping(filemenu_cursorHudElemID[0]);
    }
}


void filemenu_draw_contents_copy_arrow(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity,
                                       s32 darkening)
{
    Matrix4f sp20, sp60;
    MenuPanel* menu0 = filemenu_menus[0];
    f32 startX, startZ;
    f32 endX, endZ;
    f32 temp_f28;

    if (menu0->page == 4 && menu0->selected < 4) {
        if (menu0->selected != filemenu_loadedFileIdx && filemenu_8024C098 != 2) {
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

            gSPViewport(gMasterGfxPos++, &D_80249D60);

            guOrthoF(sp20, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f, -100.0f, 100.0f, 1.0f);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
            gSPDisplayList(gMasterGfxPos++, D_8024B600);
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, 128);
            gDPSetEnvColor(gMasterGfxPos++, 0, 0, 0, 0);

            guTranslateF(sp20, startX + 4.0f, startZ + 4.0f, 0.0f);
            guScaleF(sp60, -1.0f, 1.0f, 1.0f);
            guMtxCatF(sp60, sp20, sp20);
            guRotateF(sp60, temp_f28, 0.0f, 0.0f, 1.0f);
            guMtxCatF(sp60, sp20, sp20);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, D_8024B6F0);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);

            guTranslateF(sp60, D_80249D70[gGameStatusPtr->frameCounter % ARRAY_COUNT(D_80249D70)], 0.0f, 0.0f);
            guMtxCatF(sp60, sp20, sp20);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPSetTileSize(gMasterGfxPos++, 1, (gGameStatusPtr->frameCounter * 8) % 512, 0,
                                               ((gGameStatusPtr->frameCounter * 8) % 512) + 60, 0);
            gSPDisplayList(gMasterGfxPos++, D_8024B708);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 230, 230, 230, 255);
            gDPSetEnvColor(gMasterGfxPos++, 232, 40, 160, 0);

            guTranslateF(sp20, startX, startZ, 0.0f);
            guScaleF(sp60, -1.0f, 1.0f, 1.0f);
            guMtxCatF(sp60, sp20, sp20);
            guRotateF(sp60, temp_f28, 0.0f, 0.0f, 1.0f);
            guMtxCatF(sp60, sp20, sp20);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gSPDisplayList(gMasterGfxPos++, D_8024B6F0);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);

            guTranslateF(sp60, D_80249D70[(gGameStatusPtr->frameCounter % ARRAY_COUNT(D_80249D70))], 0.0f, 0.0f);
            guMtxCatF(sp60, sp20, sp20);
            guMtxF2L(sp20, &gDisplayContext->matrixStack[gMatrixListPos]);

            gSPMatrix(gMasterGfxPos++, &gDisplayContext->matrixStack[gMatrixListPos++],
                      G_MTX_PUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
            gDPSetTileSize(gMasterGfxPos++, 1, (gGameStatusPtr->frameCounter * 8) % 512, 0,
                                               ((gGameStatusPtr->frameCounter * 8) % 512) + 60, 0);
            gSPDisplayList(gMasterGfxPos++, D_8024B708);
            gSPPopMatrix(gMasterGfxPos++, G_MTX_MODELVIEW);
        }
    }
}

// TODO bad match, look into
void filemenu_init(s32 arg0) {
    MenuPanel** panelIt;
    MenuPanel* menu;
    s32 i;

    dma_copy(ui_images_ROM_START, ui_images_ROM_END, ui_images_VRAM);
    for (i = 0; i < ARRAY_COUNT(filemenu_cursorHudElemID); i++) {
        filemenu_cursorHudElemID[i] = hud_element_create(D_80249B80[i]);
        hud_element_set_flags(filemenu_cursorHudElemID[i], HUD_ELEMENT_FLAGS_DROP_SHADOW | HUD_ELEMENT_FLAGS_80);
    }

    D_8024C088 = filemenu_cursorHudElemID[0];
    if (!arg0) {
        D_80249DAC[0].style.customStyle->background.imgData = NULL; // ???
    }
    setup_pause_menu_tab(D_80249DAC, ARRAY_COUNT(D_80249DAC));
    menu = filemenu_menus[0];
    filemenu_8024C098 = 0;

    if (!arg0) {
        menu->page = 0;
    } else {
        menu->page = 2;
    }

    if (menu->page == 0) {
        for (i = 0; i < ARRAY_COUNT(filemenu_menus); i++) {
            if (!fio_load_game(i)) {
                gSaveSlotHasData[i] = FALSE;
            } else {
                gSaveSlotMetadata[i] = gCurrentSaveFile.unk_12EC;
                gSaveSlotHasData[i] = TRUE;
            }
        }

        if (menu->page == 0) {
            fio_has_valid_backup();
            if (D_800D95E8.saveCount >= 4) {
                D_800D95E8.saveCount = 0;
            }
            gGameStatusPtr->saveSlot = D_800D95E8.saveCount;
        }
    }

    filemenu_set_selected(menu, (gGameStatusPtr->saveSlot & 1) * 2, gGameStatusPtr->saveSlot >> 1);

    panelIt = filemenu_menus;
    for (i = 0; i < ARRAY_COUNT(filemenu_menus); i++, panelIt++) {
        if ((*panelIt)->fpInit != NULL) {
            (*panelIt)->fpInit((*panelIt));
        }
    }
    update_window_hierarchy(0x17, 0x40);
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

    for (i = 0x2C; i < ARRAY_COUNT(gWindows); i++) {
        set_window_update(i, WINDOW_UPDATE_HIDE);
    }

    set_window_update(WINDOW_ID_PAUSE_TUTORIAL, WINDOW_UPDATE_HIDE);
    set_window_update(WINDOW_ID_PAUSE_DECRIPTION, WINDOW_UPDATE_HIDE);
    func_80244BC4();
}

s32 func_80244BC4() {
    if (filemenu_menus[0]->page == 0 && filemenu_8024C098 == 1 && filemenu_menus[1]->selected == 0) {
        return 2;
    } else if (filemenu_menus[0]->page == 0 && filemenu_menus[0]->selected < 4) {
        return 1;
    } else {
        return 0;
    }
}
