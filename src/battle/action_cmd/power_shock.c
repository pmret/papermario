#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_power_shock

s32 D_802A9AA0_42D9B0[] = { 0, 25, 50, 75, 75, 0, 0, 0};

BSS s32 D_802A9B00;

extern s32 actionCmdTablePowerShock[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
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

    id = hud_element_create(&HES_AButton);
    acs->hudElements[0] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_BlueMeter);
    acs->hudElements[1] = id;
    hud_element_set_render_pos(id, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_100pct);
    acs->hudElements[3] = id;
    hud_element_set_render_pos(id, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_RunAwayOK);
    acs->hudElements[4] = id;
    hud_element_set_render_pos(id, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

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
    s32 id;
    s32 phi_a1;
    s32 cutoff;
    s32 new_var;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(99);
            id = acs->hudElements[0];
            if (acs->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(id, 255);
            id = acs->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (acs->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }
            id = acs->hudElements[4];
            hud_element_set_alpha(id, 255);
            if (acs->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }
            acs->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            btl_set_popup_duration(99);
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
            btl_set_popup_duration(99);
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
            btl_set_popup_duration(99);

            if (!acs->isBarFilled) {
                if (acs->targetWeakness != 0) {
                    cutoff = acs->mashMeterCutoffs[acs->mashMeterIntervals];
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
                    acs->barFillLevel += 100;
                    if (acs->barFillLevel >= 500) {
                        acs->barFillLevel = 500;
                    }
                }
            }

            if (acs->barFillLevel > 10000) {
                acs->barFillLevel = 10000;
                acs->isBarFilled = TRUE;
                id = acs->hudElements[3];
                hud_element_set_render_pos(id, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionQuality = acs->barFillLevel / 100;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, battleStatus->actionQuality * 12);

            if (acs->frameCounter == 0) {
                phi_a1 = acs->barFillLevel;
                if (acs->targetWeakness == 0) {
                    phi_a1 = 0;
                }

                battleStatus->actionQuality = phi_a1 / 100;
                if (phi_a1 == 0) {
                    battleStatus->actionSuccess = -1;
                } else if (battleStatus->actionQuality >= acs->thresholdLevel) {
                    battleStatus->actionSuccess = 1;
                } else {
                    battleStatus->actionSuccess = 0;
                }

                cutoff = acs->mashMeterCutoffs[acs->mashMeterIntervals - 1];
                if (cutoff / 2 < battleStatus->actionQuality) {
                    battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                } else {
                    battleStatus->actionResult = ACTION_RESULT_MINUS_4;
                }

                if (battleStatus->actionSuccess == 1) {
                    increment_action_command_success_count();
                }

                sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
                btl_set_popup_duration(0);
                acs->frameCounter = 5;
                acs->state = AC_STATE_DISPOSE;
            } else {
                acs->frameCounter--;
            }
            break;
        case AC_STATE_DISPOSE:
            if (acs->targetWeakness == 0) {
                acs->barFillLevel -= 100;
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
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 y;
    s32 x;
    s32 id;
    s32 temp_a1;
    s32 temp_v0;

    temp_v0 = actionCommandStatus->thresholdLevel * 60;
    x = 60 - temp_v0 / 100;
    temp_a1 = x - 31;
    hud_element_set_render_pos(actionCommandStatus->hudElements[4], actionCommandStatus->hudPosX - temp_a1, actionCommandStatus->hudPosY + 17);
    hud_element_draw_clipped(actionCommandStatus->hudElements[0]);

    id = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(id);
    hud_element_get_render_pos(id, &x, &y);
    // Redundant call, but needed to match.
    hud_element_get_render_pos(id, &x, &y);

    if (!D_802A9B00) {
        draw_mash_meter_multicolor_with_divisor(x, y, actionCommandStatus->barFillLevel / 100, 1);
    } else if (!actionCommandStatus->isBarFilled) {
        draw_mash_meter_multicolor_with_divisor(x, y, actionCommandStatus->barFillLevel / 100, 4);
    } else {
        draw_mash_meter_blink_with_divisor(x, y, actionCommandStatus->barFillLevel / 100, 4);
    }
    id = actionCommandStatus->hudElements[3];
    hud_element_draw_clipped(id);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
}
