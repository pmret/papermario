#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_hammer

extern s32 actionCmdTableHammer[];

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

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hid;

    battleStatus->maxActionSuccess = 1;
    battleStatus->actionCmdDifficultyTable = actionCmdTableHammer;
    battleStatus->actionResult = ACTION_RESULT_FAIL;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    acs->actionCommandID = ACTION_COMMAND_SMASH;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->hudPosX = -48;
    acs->hudPosY = 96;

    hid = hud_element_create(&HES_TimingBar1Chance);
    acs->hudElements[HIDX_BAR] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 10);

    hid = hud_element_create(&HES_TimingWait);
    acs->hudElements[HIDX_WAIT] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);

    hid = hud_element_create(&HES_TimingCharge4a);
    acs->hudElements[HIDX_CHARGE_A] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);

    hid = hud_element_create(&HES_TimingCharge4b);
    acs->hudElements[HIDX_CHARGE_B] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);

    hid = hud_element_create(&HES_TimingCharge4c);
    acs->hudElements[HIDX_CHARGE_C] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);

    hid = hud_element_create(&HES_StickHoldLeft);
    acs->hudElements[HIDX_STICK] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);

    hid = hud_element_create(&HES_RightOn);
    acs->hudElements[HIDX_RIGHT_ON] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_alpha(hid, 255);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    acs->prepareTime = evt_get_variable(script, *args++);
    acs->duration = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);
    acs->wrongButtonPressed = FALSE;
    acs->playHammerSounds = TRUE;
    if (acs->prepareTime < 0) {
        acs->prepareTime = 0;
        acs->playHammerSounds = FALSE;
    }

    acs->hammerMissedStart = FALSE;
    battleStatus->actionSuccess = 0;
    battleStatus->actionQuality = 0;
    battleStatus->actionResult = ACTION_RESULT_FAIL;
    acs->state = AC_STATE_START;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

    increment_action_command_attempt_count();

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s32 hid;
    f32 oneThird;
    s32 inputWindow;
    s32 bufferPos;
    s32 i;
    s32 new_var;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);

            hid = acs->hudElements[HIDX_BAR];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);

            hid = acs->hudElements[HIDX_WAIT];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);

            hid = acs->hudElements[HIDX_CHARGE_A];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);

            hid = acs->hudElements[HIDX_CHARGE_B];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);

            hid = acs->hudElements[HIDX_CHARGE_C];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);

            hid = acs->hudElements[HIDX_STICK];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);

            acs->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            btl_set_popup_duration(POPUP_MSG_ON);
            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }
            hud_element_set_render_pos(acs->hudElements[HIDX_BAR], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[HIDX_WAIT], acs->hudPosX + 21, acs->hudPosY - 3);
            hud_element_set_render_pos(acs->hudElements[HIDX_CHARGE_A], acs->hudPosX + 5, acs->hudPosY + 1);
            hud_element_set_render_pos(acs->hudElements[HIDX_CHARGE_B], acs->hudPosX - 7, acs->hudPosY + 1);
            hud_element_set_render_pos(acs->hudElements[HIDX_CHARGE_C], acs->hudPosX - 19, acs->hudPosY + 1);
            hud_element_set_render_pos(acs->hudElements[HIDX_STICK], acs->hudPosX, acs->hudPosY - 23);
            if (acs->autoSucceed != 0) {
                hid = acs->hudElements[HIDX_RIGHT_ON];
                hud_element_set_render_pos(hid, acs->hudPosX + 50, acs->hudPosY);
                if (acs->showHud) {
                    hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
                    break;
                }
            }
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime < 15) {
                hud_element_set_alpha(acs->hudElements[HIDX_BAR], 255);
                hud_element_set_alpha(acs->hudElements[HIDX_WAIT], 255);
                hud_element_set_alpha(acs->hudElements[HIDX_CHARGE_A], 255);
                hud_element_set_alpha(acs->hudElements[HIDX_CHARGE_B], 255);
                hud_element_set_alpha(acs->hudElements[HIDX_CHARGE_C], 255);
                hud_element_set_alpha(acs->hudElements[HIDX_STICK], 255);
            }

            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }

            acs->frameCounter = 0;
            if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT) && battleStatus->actionCommandMode < AC_MODE_TUTORIAL) {
                acs->hammerMissedStart = TRUE;
            }
            acs->state = AC_STATE_ACTIVE;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);

            if (battleStatus->actionCommandMode <= AC_MODE_TUTORIAL_BLOCK) {
                return;
            }

            inputWindow = battleStatus->actionCmdDifficultyTable[acs->difficulty];
            new_var = inputWindow + 2;
            oneThird = (acs->duration - new_var) / 3;

            if (acs->frameCounter < oneThird) {
                hud_element_set_script(acs->hudElements[HIDX_CHARGE_C], &HES_TimingCharge3);
                battleStatus->actionQuality = 0;
                if (acs->frameCounter == 0) {
                    if (acs->playHammerSounds) {
                        sfx_play_sound(SOUND_TIMING_BAR_TICK);
                    }
                }
            } else if (acs->frameCounter < oneThird * 2) {
                hud_element_set_script(acs->hudElements[HIDX_CHARGE_B], &HES_TimingCharge2);
                battleStatus->actionQuality = 1;
                if (acs->frameCounter == oneThird) {
                    if (acs->playHammerSounds) {
                        sfx_play_sound(SOUND_TIMING_BAR_TICK);
                    }
                }
            } else if (acs->frameCounter < oneThird * 3) {
                hud_element_set_script(acs->hudElements[HIDX_CHARGE_A], &HES_TimingCharge1);
                battleStatus->actionQuality = 2;
                if (acs->frameCounter == oneThird * 2) {
                    if (acs->playHammerSounds) {
                        sfx_play_sound(SOUND_TIMING_BAR_TICK);
                    }
                }
            }

            if (acs->frameCounter == (~inputWindow + acs->duration)) {
                battleStatus->actionQuality = 3;
                hud_element_set_script(acs->hudElements[HIDX_WAIT], &HES_TimingReady);
                hud_element_set_script(acs->hudElements[HIDX_STICK], &HES_StickTapNeutral);
                if (acs->playHammerSounds) {
                    sfx_play_sound(SOUND_TIMING_BAR_GO);
                }
                if (acs->autoSucceed != 0 && acs->autoSucceed != 2) {
                    acs->autoSucceed = 2;
                    acs->frameCounter = acs->duration - 4;
                }
            }
            inputWindow = battleStatus->actionCmdDifficultyTable[acs->difficulty] - (acs->duration - acs->frameCounter) + 3;
            if (inputWindow < 0) {
                inputWindow = 0;
            }

            // has the stick been release too early?
            if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT)
                && inputWindow == 0
                && acs->autoSucceed == 0
                && battleStatus->actionCommandMode < AC_MODE_TUTORIAL
            ) {
                battleStatus->actionSuccess = AC_ACTION_FAILED;
                battleStatus->actionResult = ACTION_RESULT_EARLY;
                action_command_free();
                return;
            }

            // step back several frames in the input buffer
            bufferPos = battleStatus->inputBufferPos;
            bufferPos -= inputWindow;
            if (bufferPos < 0) {
                bufferPos += ARRAY_COUNT(battleStatus->holdInputBuffer);
            }

            // has the stick been released within the window?
            if (battleStatus->actionSuccess == 0) {
                for (i = 0; i < inputWindow; i++) {
                    if (bufferPos >= ARRAY_COUNT(battleStatus->holdInputBuffer)) {
                        bufferPos -= ARRAY_COUNT(battleStatus->holdInputBuffer);
                    }

                    if (!(battleStatus->holdInputBuffer[bufferPos] & BUTTON_STICK_LEFT) || acs->autoSucceed != 0) {
                        battleStatus->actionSuccess = 1;
                        battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                        gBattleStatus.flags1 |= BS_FLAGS1_2000;
                    }
                    bufferPos++;
                }
            }

            if (battleStatus->actionCommandMode < AC_MODE_TUTORIAL || acs->frameCounter != acs->duration) {
                acs->frameCounter++;
                if (acs->duration < acs->frameCounter) {
                    if (battleStatus->actionSuccess == 0) {
                        battleStatus->actionSuccess = AC_ACTION_FAILED;
                    }

                    if (battleStatus->actionSuccess == 1) {
                        increment_action_command_success_count();
                    }

                    btl_set_popup_duration(POPUP_MSG_OFF);
                    acs->frameCounter = 5;
                    acs->state = AC_STATE_DISPOSE;
                }
            }
            break;
        case AC_STATE_DISPOSE:
            if (acs->frameCounter != 0) {
                acs->frameCounter--;
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
