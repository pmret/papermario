#include "common.h"
#include "battle/action_cmd.h"

//TODO action command
#define NAMESPACE action_command_power_shock

s32 D_802A9AA0_42D9B0[AC_DIFFICULTY_LEN] = { 0, 25, 50, 75, 75, 0, 0, 0};

BSS s32 D_802A9B00;

extern s32 actionCmdTablePowerShock[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hid;
    s32 temp_v1;

    battleStatus->unk_82 = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTablePowerShock;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    acs->actionCommandID = ACTION_COMMAND_POWER_SHOCK;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    acs->thresholdLevel = rand_int(100);
    acs->hudPrepareTime = 30;
    acs->hudPosX = -48;
    acs->isBarFilled = FALSE;
    acs->thresholdMoveDir = 0;
    D_802A9B00 = FALSE;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_AButton);
    acs->hudElements[0] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);

    hid = hud_element_create(&HES_BlueMeter);
    acs->hudElements[1] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_100pct);
    acs->hudElements[3] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_RunAwayOK);
    acs->hudElements[4] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    temp_v1 = (100 - acs->thresholdLevel) * 60;
    temp_v1 /= 100;
    temp_v1 = 29 - temp_v1;
    hud_element_set_render_pos(acs->hudElements[3], acs->hudPosX - temp_v1, acs->hudPosY + 17);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->prepareTime = evt_get_variable(script, *args++);
    acs->duration = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);
    acs->targetWeakness = evt_get_variable(script, *args++);

    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->actionResult = ACTION_RESULT_FAIL;
    acs->state = AC_STATE_START;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

    increment_action_command_attempt_count();

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hid;
    s32 phi_a1;
    s32 cutoff;
    s32 new_var;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);
            hid = acs->hudElements[0];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);
            hid = acs->hudElements[1];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hid = acs->hudElements[4];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            acs->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->hudPrepareTime != 0) {
                acs->hudPrepareTime--;
            } else {
                acs->hudPosX += 20;
                if (acs->hudPosX > 50) {
                    acs->hudPosX = 50;
                }
                hud_element_set_render_pos(acs->hudElements[0], acs->hudPosX, acs->hudPosY);
                hud_element_set_render_pos(acs->hudElements[1], acs->hudPosX, acs->hudPosY + 28);

                phi_a1 = 100 - acs->thresholdLevel;
                new_var = 29 - (phi_a1 * 60) / 100;
                hud_element_set_render_pos(acs->hudElements[4], acs->hudPosX - new_var, acs->hudPosY + 17);
            }
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                break;
            }
            hud_element_set_script(acs->hudElements[0], &HES_MashAButton);
            acs->barFillLevel = 0;
            acs->any.unk_5C = 0;
            D_802A9B00 = TRUE;
            acs->frameCounter = acs->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            acs->state = AC_STATE_ACTIVE;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);

            if (!acs->isBarFilled) {
                if (acs->targetWeakness != 0) {
                    cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals];
                    acs->barFillLevel -= D_802A9AA0_42D9B0[acs->barFillLevel / cutoff / 20];
                    if (acs->barFillLevel < 0) {
                        acs->barFillLevel = 0;
                    }
                } else {
                    acs->barFillLevel -= 10;
                    if (acs->barFillLevel < 0) {
                        acs->barFillLevel = 0;
                    }
                }
            }

            if (battleStatus->curButtonsPressed & BUTTON_A) {
                phi_a1 = acs->targetWeakness;
                if (phi_a1 != 0) {
                    s32 a = battleStatus->actionCmdDifficultyTable[acs->difficulty];

                    phi_a1 = (((a * 850) / 100) * phi_a1) / 100;
                    acs->barFillLevel += phi_a1;
                } else {
                    acs->barFillLevel += ONE_PCT_MASH;
                    if (acs->barFillLevel >= 5 * ONE_PCT_MASH) {
                        acs->barFillLevel = 5 * ONE_PCT_MASH;
                    }
                }
            }

            if (acs->barFillLevel > MAX_MASH_UNITS) {
                acs->barFillLevel = MAX_MASH_UNITS;
                acs->isBarFilled = TRUE;
                hid = acs->hudElements[3];
                hud_element_set_render_pos(hid, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionQuality = acs->barFillLevel / ONE_PCT_MASH;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, battleStatus->actionQuality * 12);

            if (acs->frameCounter == 0) {
                phi_a1 = acs->barFillLevel;
                if (acs->targetWeakness == 0) {
                    phi_a1 = 0;
                }

                battleStatus->actionQuality = phi_a1 / ONE_PCT_MASH;
                if (phi_a1 == 0) {
                    battleStatus->actionSuccess = -1;
                } else if (battleStatus->actionQuality >= acs->thresholdLevel) {
                    battleStatus->actionSuccess = 1;
                } else {
                    battleStatus->actionSuccess = 0;
                }

                cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals - 1];
                if (cutoff / 2 < battleStatus->actionQuality) {
                    battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                } else {
                    battleStatus->actionResult = ACTION_RESULT_MINUS_4;
                }

                if (battleStatus->actionSuccess == 1) {
                    increment_action_command_success_count();
                }

                sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
                btl_set_popup_duration(POPUP_MSG_OFF);
                acs->frameCounter = 5;
                acs->state = AC_STATE_DISPOSE;
            } else {
                acs->frameCounter--;
            }
            break;
        case AC_STATE_DISPOSE:
            if (acs->targetWeakness == 0) {
                acs->barFillLevel -= ONE_PCT_MASH;
                if (acs->barFillLevel < 0) {
                    acs->barFillLevel = 0;
                }
            }
            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                break;
            }
            action_command_free();
            break;
    }

    // Invisible "run away"-like meter that determines success threshold.
    // https://www.youtube.com/watch?v=FagUpV0c67s
    switch (acs->state) {
        case AC_STATE_APPEAR:
        case AC_STATE_START:
        case AC_STATE_ACTIVE:
            if (acs->thresholdMoveDir == 0) {
                acs->thresholdLevel += 7;
                if (acs->thresholdLevel >= 100) {
                    acs->thresholdLevel = 100;
                    acs->thresholdMoveDir = 1;
                }
            } else {
                acs->thresholdLevel -= 7;
                if (acs->thresholdLevel <= 0) {
                    acs->thresholdLevel = 0;
                    acs->thresholdMoveDir = 0;
                }
            }
    }
}

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hudX, hudY;
    s32 hid;
    s32 temp_a1;
    s32 temp_v0;

    temp_v0 = acs->thresholdLevel * 60;
    hudX = 60 - temp_v0 / 100;
    temp_a1 = hudX - 31;
    hud_element_set_render_pos(acs->hudElements[4], acs->hudPosX - temp_a1, acs->hudPosY + 17);
    hud_element_draw_clipped(acs->hudElements[0]);

    hid = acs->hudElements[1];
    hud_element_draw_clipped(hid);
    hud_element_get_render_pos(hid, &hudX, &hudY);
    // Redundant call, but needed to match.
    hud_element_get_render_pos(hid, &hudX, &hudY);

    if (!D_802A9B00) {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH, 1);
    } else if (!acs->isBarFilled) {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH, 4);
    } else {
        draw_mash_meter_blink_with_divisor(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH, 4);
    }
    hid = acs->hudElements[3];
    hud_element_draw_clipped(hid);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
}
