#include "common.h"
#include "nu/nusys.h"

OSContPad ContPadData;
BSS s16 StickExtremeX;
BSS s16 StickExtremeY;
BSS s16 StickRetriggerStateX;
BSS s16 StickRetriggerStateY;
BSS s32 D_8009A6A8; // unused

#define STICK_DEADZONE_THRESHOLD 4
#define STICK_BUTTON_THRESHOLD 32
#define STICK_RELEASE_THRESHOLD 16

/*
 * When converting analog stick input into digital direction buttons (BUTTON_STICK_LEFT/RIGHT/UP/DOWN),
 * small oscillations near the threshold could trigger rapid spurious stick 'button' inputs. This code
 * prevents such inputs by recording the most recent 'extreme' values of StickX/Y along with the direction
 * of motion, inward or outward, and then only counting directional reversals from those extremes.
 *
 * How it works:
 * - When the stick crosses the main threshold (|stick| > 32), the corresponding digital stick 'button' is set.
 * - While held, the code tracks the furthest extreme reached in the 'outward' direction.
 * - If the stick reverses inward by more than 16 units, it enters a release-check state.
 * - If the stick then moves outward again by more than 16 units from the inward extreme, the stick button is cleared.
 *   and a new input may be triggered *without* having to fully return the stick to neutral.
 */
enum {
    DIR_OUTWARD = 0, // track outward extremes while the stick is pressed past the threshold
    DIR_INWARD = 1, // track inward motion and determine when the stick direction should be released
};

void reset_input_state(void) {
    gGameStatusPtr->curButtons[0] = 0;
    gGameStatusPtr->pressedButtons[0] = 0;
    gGameStatusPtr->heldButtons[0] = 0;
    gGameStatusPtr->stickX[0] = 0;
    gGameStatusPtr->stickY[0] = 0;
    gGameStatusPtr->prevButtons[0] = 0;
    gGameStatusPtr->holdRepeatInterval[0] = 4;
    gGameStatusPtr->holdDelayTime[0] = 15;
    gGameStatusPtr->holdRepeatCounter = 0;
    gGameStatusPtr->holdDelayCounter = 0;
}

void clear_input(void) {
    reset_input_state();
    StickExtremeX = 0;
    StickExtremeY = 0;
    StickRetriggerStateX = DIR_OUTWARD;
    StickRetriggerStateY = DIR_OUTWARD;
}

void update_input(void) {
    OSContPad* contData = &ContPadData;
    s16 hasInput = false;
    s16 stickButtonDetected;
    s32 buttons;
    s16 stickX;
    s16 stickY;

    if (gGameStatusPtr->contBitPattern & 1) {
        hasInput = true;
        nuContDataGet(contData, 0);
    }

    if (gGameStatusPtr->demoState != DEMO_STATE_NONE) {
        if (gGameStatusPtr->demoState < DEMO_STATE_CHANGE_MAP
            && (contData->button & (BUTTON_A | BUTTON_B | BUTTON_Z | BUTTON_START))
            && hasInput
        ) {
            gGameStatusPtr->demoState = DEMO_STATE_CHANGE_MAP;
        }
        contData->button = gGameStatusPtr->demoButtonInput;
        contData->stick_x = gGameStatusPtr->demoStickX;
        contData->stick_y = gGameStatusPtr->demoStickY;
        hasInput = true;
    }

    if (!hasInput) {
        return;
    }

    stickX = contData->stick_x;
    stickY = contData->stick_y;
    if (stickX > 0) {
        stickX -= STICK_DEADZONE_THRESHOLD;
        if (stickX < 0) {
            stickX = 0;
        }
    }
    if (stickX < 0) {
        stickX += STICK_DEADZONE_THRESHOLD;
        if (stickX > 0) {
            stickX = 0;
        }
    }

    if (stickY > 0) {
        stickY -= STICK_DEADZONE_THRESHOLD;
        if (stickY < 0) {
            stickY = 0;
        }
    }
    if (stickY < 0) {
        stickY += STICK_DEADZONE_THRESHOLD;
        if (stickY > 0) {
            stickY = 0;
        }
    }

    gGameStatusPtr->stickX[0] = stickX;
    gGameStatusPtr->stickY[0] = stickY;
    buttons = contData->button;

    // check if stickX is over the 'digital' threshold for a right stick 'button' press
    stickButtonDetected = false;
    if (stickX > STICK_BUTTON_THRESHOLD) {
        stickButtonDetected = true;
        buttons |= BUTTON_STICK_RIGHT;
        if (!(gGameStatusPtr->prevButtons[0] & BUTTON_STICK_RIGHT)) {
            StickExtremeX = stickX;
        } else if (StickRetriggerStateX == DIR_OUTWARD) {
            // track largest value during DIR_OUTWARD
            if (StickExtremeX < stickX) {
                StickExtremeX = stickX;
            }
        } else {
            // track smallest value during DIR_INWARD
            if (StickExtremeX > stickX) {
                StickExtremeX = stickX;
            }
        }
    }

    // likewise for left stick 'button' (comparisons reversed since we are working with negative values)
    if (stickX < -STICK_BUTTON_THRESHOLD) {
        stickButtonDetected = true;
        buttons |= BUTTON_STICK_LEFT;
        if (!(gGameStatusPtr->prevButtons[0] & BUTTON_STICK_LEFT)) {
            StickExtremeX = stickX;
        } else if (StickRetriggerStateX == DIR_OUTWARD) {
            if (StickExtremeX > stickX) {
                StickExtremeX = stickX;
            }
        } else {
            if (StickExtremeX < stickX)
            {
                StickExtremeX = stickX;
            }
        }
    }

    if (!stickButtonDetected) {
        StickRetriggerStateX = DIR_OUTWARD;
        StickExtremeX = stickX;
    }

    // likewise for up stick 'button'
    stickButtonDetected = false;
    if (stickY > STICK_BUTTON_THRESHOLD) {
        stickButtonDetected = true;
        buttons |= BUTTON_STICK_UP;
        if (!(gGameStatusPtr->prevButtons[0] & BUTTON_STICK_UP)) {
            StickExtremeY = stickY;
        } else if (StickRetriggerStateY == DIR_OUTWARD) {
            if (StickExtremeY < stickY) {
                StickExtremeY = stickY;
            }
        } else {
            if (StickExtremeY > stickY) {
                StickExtremeY = stickY;
            }
        }
    }

    // likewise for down stick 'button'
    if (stickY < -STICK_BUTTON_THRESHOLD) {
        stickButtonDetected = true;
        buttons |= BUTTON_STICK_DOWN;
        if (!(gGameStatusPtr->prevButtons[0] & BUTTON_STICK_DOWN)) {
            StickExtremeY = stickY;
        } else if (StickRetriggerStateY == DIR_OUTWARD) {
            if (StickExtremeY > stickY) {
                StickExtremeY = stickY;
            }
        } else {
            if (StickExtremeY < stickY) {
                StickExtremeY = stickY;
            }
        }
    }

    if (!stickButtonDetected) {
        StickRetriggerStateY = DIR_OUTWARD;
        StickExtremeY = stickY;
    }

    if (stickX > STICK_BUTTON_THRESHOLD) {
        // if stick changes direction of motion during a release (from inward back to outward),
        // clear the old input and reset to DIR_OUTWARD in preparation for a new input. this allows quick
        // repeated inputs by rocking the stick without having to fully return to neutral between each.
        if (StickRetriggerStateX == DIR_INWARD && stickX - StickExtremeX > STICK_RELEASE_THRESHOLD) {
            buttons &= ~BUTTON_STICK_RIGHT;
            StickRetriggerStateX = DIR_OUTWARD;
        }
        // if we ever fall RELEASE_THRESHOLD units below the maximum value recorded, begin DIR_INWARD reversal checks
        if (StickExtremeX - stickX > STICK_RELEASE_THRESHOLD) {
            StickRetriggerStateX = DIR_INWARD;
        }
    }

    if (stickX < -STICK_BUTTON_THRESHOLD) {
        if (StickRetriggerStateX == DIR_INWARD && StickExtremeX - stickX > STICK_RELEASE_THRESHOLD) {
            buttons &= ~BUTTON_STICK_LEFT;
            StickRetriggerStateX = DIR_OUTWARD;
        }
        if (stickX - StickExtremeX > STICK_RELEASE_THRESHOLD) {
            StickRetriggerStateX = DIR_INWARD;
        }
    }

    if (stickY > STICK_BUTTON_THRESHOLD) {
        if (StickRetriggerStateY == DIR_INWARD && stickY - StickExtremeY > STICK_RELEASE_THRESHOLD) {
            buttons &= ~BUTTON_STICK_UP;
            StickRetriggerStateY = DIR_OUTWARD;
        }
        if (StickExtremeY - stickY > STICK_RELEASE_THRESHOLD) {
            StickRetriggerStateY = DIR_INWARD;
        }
    }

    if (stickY < -STICK_BUTTON_THRESHOLD) {
        if (StickRetriggerStateY == DIR_INWARD && StickExtremeY - stickY > STICK_RELEASE_THRESHOLD) {
            buttons &= ~BUTTON_STICK_DOWN;
            StickRetriggerStateY = DIR_OUTWARD;
        }
        if (stickY - StickExtremeY > STICK_RELEASE_THRESHOLD) {
            StickRetriggerStateY = DIR_INWARD;
        }
    }

    gGameStatusPtr->curButtons[0] = buttons;
    gGameStatusPtr->pressedButtons[0] = gGameStatusPtr->curButtons[0] ^ gGameStatusPtr->prevButtons[0];
    gGameStatusPtr->pressedButtons[0] &= gGameStatusPtr->curButtons[0];
    do {
        if (gGameStatusPtr->curButtons[0] == 0) {
            gGameStatusPtr->heldButtons[0] = 0;
        } else if (gGameStatusPtr->prevButtons[0] != gGameStatusPtr->curButtons[0]) {
            // buttons changed this frame: treat new presses as an immediate "held" pulse
            gGameStatusPtr->heldButtons[0] = gGameStatusPtr->curButtons[0];
            // NOTE: next two lines are just a duplicate calculation for heldButtons = pressedButtons
            gGameStatusPtr->heldButtons[0] = gGameStatusPtr->curButtons[0] ^ gGameStatusPtr->prevButtons[0];
            gGameStatusPtr->heldButtons[0] &= gGameStatusPtr->curButtons[0];
            gGameStatusPtr->holdDelayCounter = gGameStatusPtr->holdDelayTime[0];
            gGameStatusPtr->holdRepeatCounter = -1;
        } else {
            // no change in buttons and at least one button is still held
            if (gGameStatusPtr->holdRepeatCounter >= 0) {
                // repeat "held" input pulses at a regular interval
                gGameStatusPtr->holdRepeatCounter--;
                if (gGameStatusPtr->holdRepeatCounter != 0) {
                    gGameStatusPtr->heldButtons[0] = 0;
                } else {
                    gGameStatusPtr->heldButtons[0] = gGameStatusPtr->curButtons[0];
                    gGameStatusPtr->holdRepeatCounter = gGameStatusPtr->holdRepeatInterval[0];
                }
            } else {
                // initial delay before train of "held" pulses begin
                gGameStatusPtr->holdDelayCounter--;
                if (gGameStatusPtr->holdDelayCounter != 0) {
                    gGameStatusPtr->heldButtons[0] = 0;
                } else {
                    gGameStatusPtr->heldButtons[0] = gGameStatusPtr->curButtons[0];
                    gGameStatusPtr->holdRepeatCounter = gGameStatusPtr->holdRepeatInterval[0];
                }
            }
        }
    } while (0);

    gGameStatusPtr->prevButtons[0] = gGameStatusPtr->curButtons[0];
}
