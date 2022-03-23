#include "common.h"
#include "filemenu.h"
#include "hud_element.h"

void filemenu_draw_cursor(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
void filemenu_draw_contents_copy_arrow(
    MenuPanel* menu,
    s32 baseX, s32 baseY,
    s32 width, s32 height,
    s32 opacity, s32 darkening
);

extern s32 D_80241ECC;
extern MenuPanel D_8024A098;
extern MenuPanel D_8024A114;
extern MenuPanel D_8024A158;
extern MenuPanel D_8024A1D8;
extern s32 D_8024BA60;
extern s32 D_8024BA98;

s32* D_80249B80[] = { &D_80241ECC };
MenuPanel* filemenu_menus[4] = { &D_8024A098, &D_8024A114, &D_8024A158, &D_8024A1D8 };
s32 D_80249B94 = 160;
s32 D_80249B98 = -120;
s32 D_80249B9C = 0;
s32 D_80249BA0 = 160;
s32 D_80249BA4 = -120;
s32 filemenu_cursorGoalAlpha = 0;
s32 filemenu_cursorGoalAlpha2 = 0;
s32 D_80249BB0[] = { 0x00000001, 0x00000000 };
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
s32 D_80249D60[] = { 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000, };
s32 D_80249D70[] = { 0x40E00000, 0x41480000, 0x41500000, 0x41680000, 0x41600000, 0x41500000, 0x41380000, 0x41180000,
                     0x40F00000, 0x40B00000, 0x40600000, 0x40000000, 0x3F800000, 0x3F000000, 0x00000000, };
s32 D_80249DAC[] = { 0x2C000010, 0x00180120, 0x00C00000, 0x00000000, 0x00000000, 0xFF000000, 0x00000001, 0x40000000, };
s32 D_80249DCC[] = { &D_8024BA60, 0x18000000, 0x00000120, 0x00C00000, filemenu_draw_contents_copy_arrow, 0x00000000,
                     0x2C000000, 0x00000001, 0x00000000, &D_8024BA98, 0x17000000, 0x00000140, 0x00F00000,
                     filemenu_draw_cursor, 0x00000000, 0xFF000000, 0x00000001, 0x00000000, &D_8024BA98, 0x00000000,
                     0x00000000, };

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

INCLUDE_ASM(s32, "163400", mainmenu_draw_rect);

void filemenu_set_selected(MenuPanel* menu, s32 col, s32 row) {
    menu->col = col;
    menu->row = row;
    menu->selected = menu->gridData[(menu->page * menu->numCols * menu->numRows) +
                                    (menu->numCols * menu->row) + menu->col];
}

void filemenu_set_cursor_alpha(s32 arg0) {
    filemenu_cursorGoalAlpha = arg0;
    filemenu_cursorGoalAlpha2 = arg0;
}

void filemenu_set_cursor_goal_pos(s32 windowID, s32 posX, s32 posY) {
    Window* window = &gWindows[windowID];

    if (D_80249BB0[0] != 0
            || get_game_mode() == GAME_MODE_END_FILE_SELECT
            || get_game_mode() == GAME_MODE_END_LANGUAGE_SELECT) {
        if (D_80249BB0[0] != 0) {
            s32 i;

            for (i = 0x2C; i < ARRAY_COUNT(gWindows); i++) {
                Window* window = &gWindows[i];
                s8 parent = window->parent;

                if ((parent == -1 || parent == 0x2C) && (window->flags & 8)) {
                    break;
                }
            }
            if (i >= ARRAY_COUNT(gWindows)) {
                D_80249BB0[0] = 0;
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
        if (filemenu_cursorGoalAlpha2 == 0xFF) {
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

    filemenu_cursorGoalAlpha2 = 0xFF;
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
        filemenu_heldButtons = gGameStatusPtr->heldButtons;
        filemenu_pressedButtons = gGameStatusPtr->pressedButtons;
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
    menuIt = &filemenu_menus;
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
        set_hud_element_alpha(filemenu_cursorHudElemID[0], temp_a1);
        set_hud_element_render_pos(filemenu_cursorHudElemID[0], baseX + D_80249B94, baseY + D_80249B98);
        draw_hud_element_3(filemenu_cursorHudElemID[0]);
    }
}

INCLUDE_ASM(s32, "163400", filemenu_draw_contents_copy_arrow);

INCLUDE_ASM(void, "163400", filemenu_init);

// TODO bad match, look into
void filemenu_cleanup(void) {
    MenuPanel** panelIt;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(filemenu_cursorHudElemID); i++) {
        free_hud_element(filemenu_cursorHudElemID[i]);
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

    set_window_update(0x18, WINDOW_UPDATE_HIDE);
    set_window_update(0x17, WINDOW_UPDATE_HIDE);
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
