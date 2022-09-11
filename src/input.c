#include "common.h"
#include "nu/nusys.h"

extern OSContPad D_8009A5B8;

void func_800287F0(void) {
    gGameStatusPtr->currentButtons[0] = 0;
    gGameStatusPtr->pressedButtons[0] = 0;
    gGameStatusPtr->heldButtons[0] = 0;
    gGameStatusPtr->stickX[0] = 0;
    gGameStatusPtr->stickY[0] = 0;
    gGameStatusPtr->prevButtons[0] = 0;
    gGameStatusPtr->unk_50[0] = 4;
    gGameStatusPtr->unk_48[0] = 15;
    gGameStatusPtr->unk_60 = 0;
    gGameStatusPtr->unk_58 = 0;
}

void func_80028838(void) {
    func_800287F0();
    D_8009A6A0 = 0;
    D_8009A6A2 = 0;
    D_8009A6A4 = 0;
    D_8009A6A6 = 0;
}

// Backwards jump hall of shame
#ifdef NON_MATCHING
void update_input(void) {
    OSContPad* cont = &D_8009A5B8;
    s8 update;
    s8 cond;
    s16 stickX;
    s16 stickY;
    s32 buttons;

    update = FALSE;
    if (gGameStatusPtr->contBitPattern & 1) {
        update = TRUE;
        nuContDataGet(cont, 0);
    }

    if (gGameStatusPtr->demoState != 0) {
        if (gGameStatusPtr->demoState < 2 &&
            (cont->button & (BUTTON_A | BUTTON_B | BUTTON_Z | BUTTON_START)) &&
            update)
        {
            gGameStatusPtr->demoState = 2;
        }
        cont->button = gGameStatusPtr->demoButtonInput;
        cont->stick_x = gGameStatusPtr->demoStickX;
        cont->stick_y = gGameStatusPtr->demoStickY;
        update = TRUE;
    }

    if (update) {
        stickX = cont->stick_x;
        stickY = cont->stick_y;
        if (stickX > 0) {
            stickX -= 4;
            if (stickX < 0) {
                stickX = 0;
            }
        }
        if (stickX < 0) {
            stickX += 4;
            if (stickX > 0) {
                stickX = 0;
            }
        }

        if (stickY > 0) {
            stickY -= 4;
            if (stickY < 0) {
                stickY = 0;
            }
        }
        if (stickY < 0) {
            stickY += 4;
            if (stickY > 0) {
                stickY = 0;
            }
        }

        gGameStatusPtr->stickX[0] = stickX;
        gGameStatusPtr->stickY[0] = stickY;
        buttons = cont->button;

        cond = FALSE;
        if (stickX > 0x20) {
            cond = TRUE;
            buttons |= BUTTON_STICK_RIGHT;
            if (!(gGameStatusPtr->prevButtons[0] & BUTTON_STICK_RIGHT)) {
                D_8009A6A0 = stickX;
            } else {
                if (D_8009A6A4 == 0) {
                    if (D_8009A6A0 < stickX) {
                        D_8009A6A0 = stickX;
                    }
                } else {
                    if (D_8009A6A0 > stickX) {
                        D_8009A6A0 = stickX;
                    }
                }

            }
        }
        if (stickX < -0x20) {
            cond = TRUE;
            buttons |= BUTTON_STICK_LEFT;
            if (!(gGameStatusPtr->prevButtons[0] & BUTTON_STICK_LEFT)) {
                D_8009A6A0 = stickX;
            } else {
                if (D_8009A6A4 == 0) {
                    if (D_8009A6A0 > stickX) {
                        D_8009A6A0 = stickX;
                    }
                } else {
                    if (D_8009A6A0 < stickX) {
                        D_8009A6A0 = stickX;
                    }
                }
            }
        }
        if (!cond) {
            D_8009A6A4 = 0;
            D_8009A6A0 = stickX;
        }

        cond = FALSE;
        if (stickY > 0x20) {
            cond = TRUE;
            buttons |= BUTTON_STICK_UP;
            if (!(gGameStatusPtr->prevButtons[0] & BUTTON_STICK_UP)) {
                D_8009A6A2 = stickY;
            } else {
                if (!D_8009A6A6) {
                    if (D_8009A6A2 < stickY) {
                        D_8009A6A2 = stickY;
                    }
                } else {
                    if (D_8009A6A2 > stickY) {
                        D_8009A6A2 = stickY;
                    }
                }
            }
        }
        if (stickY < -0x20) {
            cond = TRUE;
            buttons |= BUTTON_STICK_DOWN;
            if (!(gGameStatusPtr->prevButtons[0] & BUTTON_STICK_DOWN)) {
                D_8009A6A2 = stickY;
            } else {
                if (!D_8009A6A6) {
                    if (D_8009A6A2 > stickY) {
                        D_8009A6A2 = stickY;
                    }
                } else {
                    if (D_8009A6A2 < stickY) {
                        D_8009A6A2 = stickY;
                    }
                }
            }
        }
        if (!cond) {
            D_8009A6A6 = FALSE;
            D_8009A6A2 = stickY;
        }

        if (stickX > 0x20) {
            if (D_8009A6A4 == TRUE && (stickX - D_8009A6A0 > 0x10)) {
                buttons &= ~BUTTON_STICK_RIGHT;
                D_8009A6A4 = FALSE;
            }
            if (D_8009A6A0 - stickX > 0x10) {
                D_8009A6A4 = TRUE;
            }
        }
        if (stickX < -0x20) {
            if (D_8009A6A4 == TRUE) {
                if (D_8009A6A0 - stickX > 0x10) {
                    buttons &= ~BUTTON_STICK_LEFT;
                    D_8009A6A4 = FALSE;
                }
            }
            if (stickX - D_8009A6A0 > 0x10) {
                D_8009A6A4 = TRUE;
            }
        }

        if (stickY > 0x20) {
            if (D_8009A6A6 == TRUE && (stickY - D_8009A6A2 > 0x10)) {
                buttons &= ~BUTTON_STICK_UP;
                D_8009A6A6 = FALSE;
            }
            if (D_8009A6A2 - stickY > 0x10) {
                D_8009A6A6 = TRUE;
            }
        }
        if (stickY < -0x20) {
            if (D_8009A6A6 == TRUE) {
                if (D_8009A6A2 - stickY > 0x10) {
                    buttons &= ~BUTTON_STICK_DOWN;
                    D_8009A6A6 = FALSE;
                }
            }
            if (stickY - D_8009A6A2 > 0x10) {
                D_8009A6A6 = TRUE;
            }
        }

        gGameStatusPtr->currentButtons[0] = buttons;
        gGameStatusPtr->pressedButtons[0] = gGameStatusPtr->currentButtons[0] ^ gGameStatusPtr->prevButtons[0];
        gGameStatusPtr->pressedButtons[0] &= gGameStatusPtr->currentButtons[0];

        if (buttons != 0) {
            if (gGameStatusPtr->prevButtons[0] != buttons) {
                gGameStatusPtr->heldButtons[0] = buttons;
                gGameStatusPtr->unk_60 = -1;
                gGameStatusPtr->heldButtons[0] = gGameStatusPtr->currentButtons[0] ^ gGameStatusPtr->prevButtons[0];
                gGameStatusPtr->heldButtons[0] &= gGameStatusPtr->currentButtons[0];
                gGameStatusPtr->unk_58 = gGameStatusPtr->unk_48[0];
            } else {
                if (gGameStatusPtr->unk_60 >= 0) {
                    gGameStatusPtr->unk_60--;
                    if (gGameStatusPtr->unk_60 == 0) {
                        gGameStatusPtr->heldButtons[0] = gGameStatusPtr->currentButtons[0];
                        gGameStatusPtr->unk_60 = gGameStatusPtr->unk_50[0];
                    } else {
                        gGameStatusPtr->heldButtons[0] = 0;
                    }
                } else {
                    gGameStatusPtr->unk_58--;
                    if (gGameStatusPtr->unk_58 == 0) {
                        gGameStatusPtr->heldButtons[0] = gGameStatusPtr->currentButtons[0];
                        gGameStatusPtr->unk_60 = gGameStatusPtr->unk_50[0];
                    } else {
                        gGameStatusPtr->heldButtons[0] = 0;
                    }
                }
            }
        } else {
            gGameStatusPtr->heldButtons[0] = 0;
        }

        gGameStatusPtr->prevButtons[0] = gGameStatusPtr->currentButtons[0];
    }
}
#else
INCLUDE_ASM(s32, "input", update_input);
#endif
