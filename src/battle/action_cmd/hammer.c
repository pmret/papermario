#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_hammer

extern s32 actionCmdTableHammer[];

enum HammerActionResult {
    HAMMER_RESULT_FAILED = -1,
    HAMMER_RESULT_NONE   = 0,
    HAMMER_RESULT_GOOD   = 1,
};

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_BAR            = 0,
    HIDX_WAIT           = 1,
    HIDX_CHARGE_A       = 2,
    HIDX_CHARGE_B       = 3,
    HIDX_CHARGE_C       = 4,
    HIDX_STICK          = 5,
    HIDX_RIGHT_ON       = 6,
};

API_CALLABLE(ActionCommandInitHammer) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    battleStatus->unk_82 = 1;
    battleStatus->actionCmdDifficultyTable = actionCmdTableHammer;
    battleStatus->actionResult = ACTION_RESULT_FAIL;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = HAMMER_RESULT_NONE;
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_SMASH;
    actionCommandStatus->state = AC_STATE_INIT;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->hudPosX = -48;
    actionCommandStatus->hudPosY = 96;

    id = hud_element_create(&HES_TimingBar1Chance);
    actionCommandStatus->hudElements[HIDX_BAR] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 10);

    id = hud_element_create(&HES_TimingWait);
    actionCommandStatus->hudElements[HIDX_WAIT] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_TimingCharge4a);
    actionCommandStatus->hudElements[HIDX_CHARGE_A] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_TimingCharge4b);
    actionCommandStatus->hudElements[HIDX_CHARGE_B] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_TimingCharge4c);
    actionCommandStatus->hudElements[HIDX_CHARGE_C] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_StickHoldLeft);
    actionCommandStatus->hudElements[HIDX_STICK] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_RightOn);
    actionCommandStatus->hudElements[HIDX_RIGHT_ON] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_alpha(id, 255);

    return ApiStatus_DONE2;
}

// args: prep time, duration, difficulty
API_CALLABLE(ActionCommandStartHammer) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = HAMMER_RESULT_NONE;
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    actionCommandStatus->prepareTime = evt_get_variable(script, *args++);
    actionCommandStatus->duration = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = adjust_action_command_difficulty(actionCommandStatus->difficulty);
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->playHammerSounds = TRUE;
    if (actionCommandStatus->prepareTime < 0) {
        actionCommandStatus->prepareTime = 0;
        actionCommandStatus->playHammerSounds = FALSE;
    }

    actionCommandStatus->hammerMissedStart = FALSE;
    battleStatus->actionSuccess = HAMMER_RESULT_NONE;
    battleStatus->actionQuality = 0;
    battleStatus->actionResult = ACTION_RESULT_FAIL;
    actionCommandStatus->state = AC_STATE_START;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    increment_action_command_attempt_count();
    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s32 id;
    f32 oneThird;
    s32 phi_s0;
    s32 new_var;
    s32 a;

    switch (actionCommandStatus->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(99);

            id = actionCommandStatus->hudElements[HIDX_BAR];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[HIDX_WAIT];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[HIDX_CHARGE_A];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[HIDX_CHARGE_B];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[HIDX_CHARGE_C];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[HIDX_STICK];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(id, 255);

            actionCommandStatus->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            btl_set_popup_duration(99);
            actionCommandStatus->hudPosX += 20;
            if (actionCommandStatus->hudPosX > 50) {
                actionCommandStatus->hudPosX = 50;
            }
            hud_element_set_render_pos(actionCommandStatus->hudElements[HIDX_BAR], actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[HIDX_WAIT], actionCommandStatus->hudPosX + 21, actionCommandStatus->hudPosY - 3);
            hud_element_set_render_pos(actionCommandStatus->hudElements[HIDX_CHARGE_A], actionCommandStatus->hudPosX + 5, actionCommandStatus->hudPosY + 1);
            hud_element_set_render_pos(actionCommandStatus->hudElements[HIDX_CHARGE_B], actionCommandStatus->hudPosX - 7, actionCommandStatus->hudPosY + 1);
            hud_element_set_render_pos(actionCommandStatus->hudElements[HIDX_CHARGE_C], actionCommandStatus->hudPosX - 19, actionCommandStatus->hudPosY + 1);
            hud_element_set_render_pos(actionCommandStatus->hudElements[HIDX_STICK], actionCommandStatus->hudPosX, actionCommandStatus->hudPosY - 23);
            if (actionCommandStatus->autoSucceed != 0) {
                id = actionCommandStatus->hudElements[HIDX_RIGHT_ON];
                hud_element_set_render_pos(id, actionCommandStatus->hudPosX + 50, actionCommandStatus->hudPosY);
                if (actionCommandStatus->showHud) {
                    hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
                    break;
                }
            }
            break;
        case AC_STATE_START:
            btl_set_popup_duration(99);
            if (actionCommandStatus->prepareTime < 15) {
                hud_element_set_alpha(actionCommandStatus->hudElements[HIDX_BAR], 255);
                hud_element_set_alpha(actionCommandStatus->hudElements[HIDX_WAIT], 255);
                hud_element_set_alpha(actionCommandStatus->hudElements[HIDX_CHARGE_A], 255);
                hud_element_set_alpha(actionCommandStatus->hudElements[HIDX_CHARGE_B], 255);
                hud_element_set_alpha(actionCommandStatus->hudElements[HIDX_CHARGE_C], 255);
                hud_element_set_alpha(actionCommandStatus->hudElements[HIDX_STICK], 255);
            }

            if (actionCommandStatus->prepareTime != 0) {
                actionCommandStatus->prepareTime--;
                return;
            }

            actionCommandStatus->frameCounter = 0;
            if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT) && battleStatus->actionCommandMode < AC_MODE_TUTORIAL) {
                actionCommandStatus->hammerMissedStart = TRUE;
            }
            actionCommandStatus->state = AC_STATE_ACTIVE;
            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(99);

            if (battleStatus->actionCommandMode <= AC_MODE_TUTORIAL_BLOCK) {
                return;
            }

            phi_s0 = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty];
            new_var = phi_s0 + 2;
            oneThird = (actionCommandStatus->duration - new_var) / 3;

            if (actionCommandStatus->frameCounter < oneThird) {
                hud_element_set_script(actionCommandStatus->hudElements[HIDX_CHARGE_C], &HES_TimingCharge3);
                battleStatus->actionQuality = 0;
                if (actionCommandStatus->frameCounter == 0 && actionCommandStatus->playHammerSounds) {
                    sfx_play_sound(SOUND_TIMING_BAR_TICK);
                }
            } else if (actionCommandStatus->frameCounter < oneThird * 2) {
                hud_element_set_script(actionCommandStatus->hudElements[HIDX_CHARGE_B], &HES_TimingCharge2);
                battleStatus->actionQuality = 1;
                if (actionCommandStatus->frameCounter == oneThird) {
                    if (actionCommandStatus->playHammerSounds) {
                        sfx_play_sound(SOUND_TIMING_BAR_TICK);
                    }
                }
            } else if (actionCommandStatus->frameCounter < oneThird * 3) {
                hud_element_set_script(actionCommandStatus->hudElements[HIDX_CHARGE_A], &HES_TimingCharge1);
                battleStatus->actionQuality = 2;
                if (actionCommandStatus->frameCounter == oneThird * 2) {
                    if (actionCommandStatus->playHammerSounds) {
                        sfx_play_sound(SOUND_TIMING_BAR_TICK);
                    }
                }
            }

            if (actionCommandStatus->frameCounter == (~phi_s0 + actionCommandStatus->duration)) {
                battleStatus->actionQuality = 3;
                hud_element_set_script(actionCommandStatus->hudElements[HIDX_WAIT], &HES_TimingReady);
                hud_element_set_script(actionCommandStatus->hudElements[HIDX_STICK], &HES_StickTapNeutral);
                if (actionCommandStatus->playHammerSounds) {
                    sfx_play_sound(SOUND_TIMING_BAR_GO);
                }
                if (actionCommandStatus->autoSucceed != 0 && actionCommandStatus->autoSucceed != 2) {
                    actionCommandStatus->autoSucceed = 2;
                    actionCommandStatus->frameCounter = actionCommandStatus->duration - 4;
                }
            }

            a = actionCommandStatus->duration - actionCommandStatus->frameCounter;
            phi_s0 = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] - a + 3;
            if (phi_s0 < 0) {
                phi_s0 = 0;
            }

            if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT)
                && phi_s0 == 0
                && actionCommandStatus->autoSucceed == 0
                && battleStatus->actionCommandMode < AC_MODE_TUTORIAL
            ) {
                battleStatus->actionSuccess = HAMMER_RESULT_FAILED;
                battleStatus->actionResult = ACTION_RESULT_EARLY;
                action_command_free();
            } else {
                s32 i;
                s32 bufferPos;

                bufferPos = battleStatus->inputBufferPos;
                bufferPos -= phi_s0;
                if (bufferPos < 0) {
                    bufferPos += ARRAY_COUNT(battleStatus->holdInputBuffer);
                }

                if (battleStatus->actionSuccess == HAMMER_RESULT_NONE) {
                    for (i = 0; i < phi_s0; i++, bufferPos++) {
                        if (bufferPos >= ARRAY_COUNT(battleStatus->holdInputBuffer)) {
                            bufferPos -= ARRAY_COUNT(battleStatus->holdInputBuffer);
                        }

                        if (!(battleStatus->holdInputBuffer[bufferPos] & BUTTON_STICK_LEFT) ||
                            actionCommandStatus->autoSucceed != 0)
                        {
                            battleStatus->actionSuccess = HAMMER_RESULT_GOOD;
                            battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                            gBattleStatus.flags1 |= BS_FLAGS1_2000;
                        }
                    }
                }

                if (battleStatus->actionCommandMode < AC_MODE_TUTORIAL || actionCommandStatus->frameCounter != actionCommandStatus->duration) {
                    actionCommandStatus->frameCounter++;
                    if (actionCommandStatus->duration < actionCommandStatus->frameCounter) {
                        if (battleStatus->actionSuccess == HAMMER_RESULT_NONE) {
                            battleStatus->actionSuccess = HAMMER_RESULT_FAILED;
                        }

                        if (battleStatus->actionSuccess == HAMMER_RESULT_GOOD) {
                            increment_action_command_success_count();
                        }

                        btl_set_popup_duration(0);
                        actionCommandStatus->frameCounter = 5;
                        actionCommandStatus->state = AC_STATE_DISPOSE;
                    }
                }
            }
            break;
        case AC_STATE_DISPOSE:
            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                return;
            }
            action_command_free();
            break;
    }
}

void N(draw)(void) {
    hud_element_draw_clipped(gActionCommandStatus.hudElements[HIDX_BAR]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[HIDX_WAIT]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[HIDX_CHARGE_A]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[HIDX_CHARGE_B]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[HIDX_CHARGE_C]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[HIDX_STICK]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[HIDX_RIGHT_ON]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[HIDX_BAR]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_WAIT]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_CHARGE_A]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_CHARGE_B]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_CHARGE_C]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_STICK]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_RIGHT_ON]);
}
