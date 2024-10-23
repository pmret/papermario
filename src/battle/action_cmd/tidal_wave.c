#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_tidal_wave

extern s32 actionCmdTableTidalWave[];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_METER          = 0,
    HIDX_FIRST_BUTTON   = 1,
    // remaining HIDX are for the sequence of buttons
};

// states for this action command
enum {
    TIDAL_WAVE_STATE_INIT           = 0,  // create hud elements
    TIDAL_WAVE_STATE_APPEAR         = 1,  // hud elements move into position
    TIDAL_WAVE_STATE_START          = 10,
    TIDAL_WAVE_STATE_NEXT_BUTTON    = 11, // choose the next required input
    TIDAL_WAVE_STATE_AWAIT_INPUT    = 12, // wait for the player's response
    TIDAL_WAVE_STATE_WRAPUP         = 13, // tally overall success
    TIDAL_WAVE_STATE_DISPOSE        = 14, // delay and disappear
};

enum {
    TIDAL_WAVE_INPUT_A          = 0,
    TIDAL_WAVE_INPUT_B          = 1,
    TIDAL_WAVE_INPUT_C_DOWN     = 2,
    TIDAL_WAVE_INPUT_COUNT,
};

HudScript* HudButtonsUp[TIDAL_WAVE_INPUT_COUNT] = { &HES_PressAButton, &HES_PressBButton, &HES_PressCDownButton };
HudScript* HudButtonsDown[TIDAL_WAVE_INPUT_COUNT] = { &HES_AButtonDown, &HES_BButtonHeld, &HES_CDownButtonHeld };

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElemID hid;
    s32 i;

    battleStatus->maxActionQuality = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTableTidalWave;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->actionCommandID = ACTION_COMMAND_TIDAL_WAVE;
    acs->state = TIDAL_WAVE_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->meterFillLevel = 0;
    acs->meterFillWidth = 0;
    battleStatus->actionProgress = 0;
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_BlueMeter);
    acs->hudElemIDs[HIDX_METER] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    for (i = HIDX_FIRST_BUTTON; i < ARRAY_COUNT(acs->hudElemIDs) - 1; i++) {
        hid = hud_element_create(&HES_AButton);
        acs->hudElemIDs[i] = hid;
        hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
        hud_element_set_render_depth(hid, 0);
        hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->prepareTime = evt_get_variable(script, *args++);
    acs->duration = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);

    acs->wrongButtonPressed = FALSE;
    acs->meterFillLevel = 0;
    acs->meterFillWidth = 0;
    battleStatus->actionQuality = 0;
    battleStatus->actionProgress = 0;
    battleStatus->actionResult = ACTION_RESULT_FAIL;
    acs->state = TIDAL_WAVE_STATE_START;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

    increment_action_command_attempt_count();

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElemID hid;
    s8 oldButton;
    s8 newButton;
    s32 numLookbackFrames;
    s32 bufferPos;
    s32 buttonsPressed;
    s32 success;
    s32 i;

    switch (acs->state) {
        case TIDAL_WAVE_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);
            hid = acs->hudElemIDs[HIDX_METER];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);
            acs->state = TIDAL_WAVE_STATE_APPEAR;
            break;
        case TIDAL_WAVE_STATE_APPEAR:
            btl_set_popup_duration(POPUP_MSG_ON);
            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_METER], acs->hudPosX + 21, acs->hudPosY + 28);
            break;
        case TIDAL_WAVE_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                break;
            }
            acs->tidalWave.inputCount = 1;
            acs->stateTimer = acs->duration;
            acs->tidalWave.prevButton = rand_int(TIDAL_WAVE_INPUT_COUNT - 1);
            acs->state = TIDAL_WAVE_STATE_NEXT_BUTTON;
            acs->wrongInputFrameCounter = 0;

            // fallthrough
        case TIDAL_WAVE_STATE_NEXT_BUTTON:
            btl_set_popup_duration(POPUP_MSG_ON);

            // Pick a new button that doesn't match the old one.
            oldButton = acs->tidalWave.prevButton;
            do {
                newButton = rand_int(TIDAL_WAVE_INPUT_COUNT - 1);
                acs->tidalWave.prevButton = newButton;
            } while (oldButton == newButton);

            hid = acs->hudElemIDs[acs->tidalWave.inputCount];
            hud_element_set_script(hid, HudButtonsUp[newButton]);
            hud_element_set_render_pos(hid, acs->hudPosX + ((acs->tidalWave.inputCount - 1) * 20) + 16, acs->hudPosY);
            hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            sfx_play_sound(SOUND_TIMING_BAR_TICK);
            acs->lookBackCounter = 1;
            acs->state = TIDAL_WAVE_STATE_AWAIT_INPUT;

            // fallthrough
        case TIDAL_WAVE_STATE_AWAIT_INPUT:
            btl_set_popup_duration(POPUP_MSG_ON);

            acs->stateTimer--;
            if (acs->stateTimer == 0) {
                acs->state = TIDAL_WAVE_STATE_WRAPUP;
                break;
            }

            // Stops checking for input if on the 15th button.
            if (acs->tidalWave.inputCount == 15) {
                break;
            }

            // Number of frames until input possible (if negative, used to look backward;
            // allows correct presses to be buffered after an incorrect press).
            acs->lookBackCounter--;
            // Wrong-input lockout frame counter
            acs->wrongInputFrameCounter--;

            if (acs->lookBackCounter <= 0) {
                // Determine number of frames to look back in input buffer (up to 20).
                numLookbackFrames = abs(acs->lookBackCounter);
                if (numLookbackFrames > 20) {
                    numLookbackFrames = 20;
                }

                // Determine starting point in input buffer.
                bufferPos = battleStatus->inputBufferPos - numLookbackFrames;
                if (bufferPos < 0) {
                    bufferPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
                }

                // If determined that 0 frames should be searched, search a minimum of 1.
                if (numLookbackFrames == 0) {
                    numLookbackFrames = 1;
                }

                // Check buffer for past N frames' worth of button presses.
                for (i = 0; i < numLookbackFrames; i++) {
                    if (bufferPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        bufferPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }

                    // If not locked out from previous wrong press...
                    if (acs->wrongInputFrameCounter > 0) {
                        break;
                    };

                    success = FALSE;
                    acs->wrongButtonPressed = FALSE;

                    // Check for presses of the current button.
                    switch (acs->tidalWave.prevButton) {
                        case TIDAL_WAVE_INPUT_A:
                            if (acs->autoSucceed) {
                                success = TRUE;
                            } else {
                                buttonsPressed = battleStatus->pushInputBuffer[bufferPos];
                                if (buttonsPressed != 0) {
                                    if (buttonsPressed & ~BUTTON_A) {
                                        acs->wrongButtonPressed = TRUE;
                                    } else {
                                        success = TRUE;
                                    }
                                }
                            }
                            break;
                        case TIDAL_WAVE_INPUT_B:
                            if (acs->autoSucceed) {
                                success = TRUE;
                            } else {
                                buttonsPressed = battleStatus->pushInputBuffer[bufferPos];
                                if (buttonsPressed != 0) {
                                    if (buttonsPressed & ~BUTTON_B) {
                                        acs->wrongButtonPressed = TRUE;
                                    } else {
                                        success = TRUE;
                                    }
                                }
                            }
                            break;
                        case TIDAL_WAVE_INPUT_C_DOWN:
                            if (acs->autoSucceed) {
                                success = TRUE;
                            } else {
                                buttonsPressed = battleStatus->pushInputBuffer[bufferPos];
                                if (buttonsPressed != 0) {
                                    if (buttonsPressed & ~BUTTON_C_DOWN) {
                                        acs->wrongButtonPressed = TRUE;
                                    } else {
                                        success = TRUE;
                                    }
                                }
                            }
                            break;
                    }

                    if (acs->wrongButtonPressed) {
                        // Wrong; prevent successful inputs for 10 frames.
                        acs->wrongInputFrameCounter = 10;
                        sfx_play_sound(SOUND_MENU_ERROR);
                        acs->lookBackCounter = 0;
                    }

                    if (success) {
                        // Correct; shrink button, set up next button press, etc.
                        hid = acs->hudElemIDs[acs->tidalWave.inputCount];
                        hud_element_set_script(hid, HudButtonsDown[acs->tidalWave.prevButton]);
                        hud_element_set_scale(hid, 0.5f);
                        hud_element_set_render_pos(hid, acs->hudPosX + ((acs->tidalWave.inputCount - 1) * 20), acs->hudPosY + 7);
                        acs->tidalWave.inputCount++;
                        acs->meterFillLevel += battleStatus->actionCmdDifficultyTable[acs->difficulty] * 18;
                        if (acs->meterFillLevel > MAX_MASH_UNITS) {
                            acs->meterFillLevel = MAX_MASH_UNITS;
                        }
                        acs->state = TIDAL_WAVE_STATE_NEXT_BUTTON;
                        battleStatus->actionProgress++;
                        sfx_play_sound(SOUND_APPROVE);
                        return;
                    }

                    bufferPos++;
                }
            }
            break;
        case TIDAL_WAVE_STATE_WRAPUP:
            if (battleStatus->actionProgress == 0) {
                battleStatus->actionQuality = AC_QUALITY_FAILED;
            } else {
                battleStatus->actionQuality = battleStatus->actionProgress;
            }
            battleStatus->actionResult = ACTION_RESULT_SUCCESS;
            if (battleStatus->actionQuality >= 10) {
                increment_action_command_success_count();
            }
            btl_set_popup_duration(POPUP_MSG_OFF);
            acs->stateTimer = 5;
            acs->state = TIDAL_WAVE_STATE_DISPOSE;
            break;
        case TIDAL_WAVE_STATE_DISPOSE:
            if (acs->stateTimer != 0) {
                acs->stateTimer--;
            } else {
                action_command_free();
            }
            break;
    }
}

void N(draw)(void) {
    s32 i;

    for (i = HIDX_FIRST_BUTTON; i < ARRAY_COUNT(gActionCommandStatus.hudElemIDs) - 1; i++) {
        hud_element_draw_clipped(gActionCommandStatus.hudElemIDs[i]);
    }
}

void N(free)(void) {
    s32 i;

    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_METER]);

    for (i = HIDX_FIRST_BUTTON; i < ARRAY_COUNT(gActionCommandStatus.hudElemIDs) - 1; i++) {
        hud_element_free(gActionCommandStatus.hudElemIDs[i]);
    }
}
