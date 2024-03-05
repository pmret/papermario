#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_tidal_wave

HudScript* D_802A97C0_42CEB0[3] = { &HES_PressAButton, &HES_PressBButton, &HES_PressCDownButton };
HudScript* D_802A97CC_42CEBC[3] = { &HES_AButtonDown, &HES_BButtonHeld, &HES_CDownButtonHeld };

extern s32 actionCmdTableTidalWave[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
    s32 i;

    battleStatus->unk_82 = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTableTidalWave;

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    } else {
        action_command_init_status();
        actionCommandStatus->actionCommandID = ACTION_COMMAND_TIDAL_WAVE;
        actionCommandStatus->state = 0;
        actionCommandStatus->wrongButtonPressed = FALSE;
        actionCommandStatus->barFillLevel = 0;
        actionCommandStatus->barFillWidth = 0;
        battleStatus->actionQuality = 0;
        actionCommandStatus->hudPosX = -48;
        actionCommandStatus->hudPosY = 80;

        id = hud_element_create(&HES_BlueMeter);
        actionCommandStatus->hudElements[0] = id;
        hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
        hud_element_set_render_depth(id, 0);
        hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

        for (i = 1; i < ARRAY_COUNT(actionCommandStatus->hudElements) - 1; i++) {
            id = hud_element_create(&HES_AButton);
            actionCommandStatus->hudElements[i] = id;
            hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
            hud_element_set_render_depth(id, 0);
            hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
        }

        return ApiStatus_DONE2;
    }
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    actionCommandStatus->prepareTime = evt_get_variable(script, *args++);
    actionCommandStatus->duration = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = adjust_action_command_difficulty(actionCommandStatus->difficulty);
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->actionQuality = 0;
    battleStatus->actionResult = ACTION_RESULT_FAIL;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    func_80269118();
    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
    s8 oldButton;
    s8 newButton;
    s32 numLookbackFrames;
    s32 bufferPos;
    s32 buttonsPressed;
    s32 success;
    s32 i;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);
            id = actionCommandStatus->hudElements[0];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(id, 255);
            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);
            actionCommandStatus->hudPosX += 20;
            if (actionCommandStatus->hudPosX > 50) {
                actionCommandStatus->hudPosX = 50;
            }
            hud_element_set_render_pos(
                actionCommandStatus->hudElements[0],
                actionCommandStatus->hudPosX + 21,
                actionCommandStatus->hudPosY + 28);
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->prepareTime != 0) {
                actionCommandStatus->prepareTime--;
                break;
            }
            actionCommandStatus->unk_5D = 1;
            actionCommandStatus->frameCounter = actionCommandStatus->duration;
            actionCommandStatus->unk_5C = rand_int(2);
            actionCommandStatus->state = 11;
            actionCommandStatus->wrongInputFrameCounter = 0;
            // fallthrough
        case 11:
            btl_set_popup_duration(99);

            // Pick a new button that doesn't match the old one.
            oldButton = actionCommandStatus->unk_5C;
            do {
                newButton = rand_int(2);
                actionCommandStatus->unk_5C = newButton;
            } while (oldButton == newButton);

            id = actionCommandStatus->hudElements[actionCommandStatus->unk_5D];
            hud_element_set_script(
                id, D_802A97C0_42CEB0[newButton]);
            hud_element_set_render_pos(
                id,
                actionCommandStatus->hudPosX + ((actionCommandStatus->unk_5D - 1) * 20) + 16,
                actionCommandStatus->hudPosY);
            hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            sfx_play_sound(SOUND_TIMING_BAR_TICK);
            actionCommandStatus->lookBackCounter = 1;
            actionCommandStatus->state = 12;
            // fallthrough
        case 12:
            btl_set_popup_duration(99);
            if (--actionCommandStatus->frameCounter == 0) {
                actionCommandStatus->state = 13;
                break;
            }

            // Stops checking for input if on the 15th button.
            if (actionCommandStatus->unk_5D == 15) {
                break;
            }

            // Number of frames until input possible (if negative, used to look backward;
            // allows correct presses to be buffered after an incorrect press).
            actionCommandStatus->lookBackCounter--;
            // Wrong-input lockout frame counter
            actionCommandStatus->wrongInputFrameCounter--;

            if (actionCommandStatus->lookBackCounter <= 0) {
                // Determine number of frames to look back in input buffer (up to 20).
                numLookbackFrames = abs(actionCommandStatus->lookBackCounter);
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
                    if (actionCommandStatus->wrongInputFrameCounter > 0) {
                        break;
                    };

                    success = FALSE;
                    actionCommandStatus->wrongButtonPressed = FALSE;

                    // Check for presses of the current button.
                    switch (actionCommandStatus->unk_5C) {
                        case 0:
                            if (actionCommandStatus->autoSucceed) {
                                success = TRUE;
                            } else {
                                buttonsPressed = battleStatus->pushInputBuffer[bufferPos];
                                if (buttonsPressed != 0) {
                                    if (buttonsPressed & ~BUTTON_A) {
                                        actionCommandStatus->wrongButtonPressed = TRUE;
                                    } else {
                                        success = TRUE;
                                    }
                                }
                            }
                            break;
                        case 1:
                            if (actionCommandStatus->autoSucceed) {
                                success = TRUE;
                            } else {
                                buttonsPressed = battleStatus->pushInputBuffer[bufferPos];
                                if (buttonsPressed != 0) {
                                    if (buttonsPressed & ~BUTTON_B) {
                                        actionCommandStatus->wrongButtonPressed = TRUE;
                                    } else {
                                        success = TRUE;
                                    }
                                }
                            }
                            break;
                        case 2:
                            if (actionCommandStatus->autoSucceed) {
                                success = TRUE;
                            } else {
                                buttonsPressed = battleStatus->pushInputBuffer[bufferPos];
                                if (buttonsPressed != 0) {
                                    if (buttonsPressed & ~BUTTON_C_DOWN) {
                                        actionCommandStatus->wrongButtonPressed = TRUE;
                                    } else {
                                        success = TRUE;
                                    }
                                }
                            }
                            break;
                    }

                    if (actionCommandStatus->wrongButtonPressed) {
                        // Wrong; prevent successful inputs for 10 frames.
                        actionCommandStatus->wrongInputFrameCounter = 10;
                        sfx_play_sound(SOUND_MENU_ERROR);
                        actionCommandStatus->lookBackCounter = 0;
                    }

                    if (success) {
                        // Correct; shrink button, set up next button press, etc.
                        id = actionCommandStatus->hudElements[actionCommandStatus->unk_5D];
                        hud_element_set_script(id, D_802A97CC_42CEBC[actionCommandStatus->unk_5C]);
                        hud_element_set_scale(id, 0.5f);
                        hud_element_set_render_pos(
                            id,
                            actionCommandStatus->hudPosX + ((actionCommandStatus->unk_5D - 1) * 20),
                            actionCommandStatus->hudPosY + 7);
                        actionCommandStatus->unk_5D++;
                        actionCommandStatus->barFillLevel +=
                            battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] * 0x12;
                        if (actionCommandStatus->barFillLevel > 10000) {
                            actionCommandStatus->barFillLevel = 10000;
                        }
                        actionCommandStatus->state = 11;
                        battleStatus->actionQuality++;
                        sfx_play_sound(SOUND_APPROVE);
                        return;
                    }

                    bufferPos++;
                }
            }
            break;
        case 13:
            if (battleStatus->actionQuality == 0) {
                battleStatus->actionSuccess = -1;
            } else {
                battleStatus->actionSuccess = battleStatus->actionQuality;
            }
            battleStatus->actionResult = ACTION_RESULT_SUCCESS;
            if (battleStatus->actionSuccess >= 10) {
                func_80269160();
            }
            btl_set_popup_duration(0);
            actionCommandStatus->frameCounter = 5;
            actionCommandStatus->state = 14;
            break;
        case 14:
            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
            } else {
                action_command_free();
            }
            break;
    }
}

void N(draw)(void) {
    s32 i;

    for (i = 1; i < ARRAY_COUNT(gActionCommandStatus.hudElements) - 1; i++) {
        hud_element_draw_clipped(gActionCommandStatus.hudElements[i]);
    }
}

void N(free)(void) {
    s32 i;

    hud_element_free(gActionCommandStatus.hudElements[0]);

    for (i = 1; i < ARRAY_COUNT(gActionCommandStatus.hudElements) - 1; i++) {
        hud_element_free(gActionCommandStatus.hudElements[i]);
    }
}
