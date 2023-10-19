#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_power_shock

s32 D_802A9AA0_42D9B0[] = { 0, 25, 50, 75, 75, 0, 0, 0};

BSS s32 D_802A9B00;

extern s32 actionCmdTablePowerShock[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
    s32 temp_v1;

    battleStatus->unk_82 = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTablePowerShock;

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_POWER_SHOCK;
    actionCommandStatus->state = 0;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    actionCommandStatus->thresholdLevel = rand_int(100);
    actionCommandStatus->hudPrepareTime = 30;
    actionCommandStatus->hudPosX = -48;
    actionCommandStatus->isBarFilled = FALSE;
    actionCommandStatus->thresholdMoveDir = 0;
    D_802A9B00 = FALSE;
    actionCommandStatus->hudPosY = 80;

    id = hud_element_create(&HES_AButton);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_BlueMeter);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_100pct);
    actionCommandStatus->hudElements[3] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_RunAwayOK);
    actionCommandStatus->hudElements[4] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    temp_v1 = (100 - actionCommandStatus->thresholdLevel) * 60;
    temp_v1 /= 100;
    temp_v1 = 29 - temp_v1;
    hud_element_set_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudPosX - temp_v1, actionCommandStatus->hudPosY + 17);
    return ApiStatus_DONE2;
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
    actionCommandStatus->targetWeakness = evt_get_variable(script, *args++);
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    battleStatus->actionSuccess = 0;
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
    s32 phi_a1;
    s32 cutoff;
    s32 new_var;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);
            id = actionCommandStatus->hudElements[0];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(id, 255);
            id = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }
            id = actionCommandStatus->hudElements[4];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }
            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);
            if (actionCommandStatus->hudPrepareTime != 0) {
                actionCommandStatus->hudPrepareTime--;
            } else {
                actionCommandStatus->hudPosX += 20;
                if (actionCommandStatus->hudPosX > 50) {
                    actionCommandStatus->hudPosX = 50;
                }
                hud_element_set_render_pos(
                    actionCommandStatus->hudElements[0],
                    actionCommandStatus->hudPosX,
                    actionCommandStatus->hudPosY);
                hud_element_set_render_pos(
                    actionCommandStatus->hudElements[1],
                    actionCommandStatus->hudPosX,
                    actionCommandStatus->hudPosY + 28);

                phi_a1 = 100 - actionCommandStatus->thresholdLevel;
                new_var = 29 - (phi_a1 * 60) / 100;
                hud_element_set_render_pos(
                    actionCommandStatus->hudElements[4],
                    actionCommandStatus->hudPosX - new_var,
                    actionCommandStatus->hudPosY + 17);
            }
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->prepareTime != 0) {
                actionCommandStatus->prepareTime--;
                break;
            }
            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_MashAButton);
            actionCommandStatus->barFillLevel = 0;
            actionCommandStatus->unk_5C = 0;
            D_802A9B00 = TRUE;
            actionCommandStatus->frameCounter = actionCommandStatus->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            actionCommandStatus->state = 11;
            // fallthrough
        case 11:
            btl_set_popup_duration(99);

            if (!actionCommandStatus->isBarFilled) {
                if (actionCommandStatus->targetWeakness != 0) {
                    cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
                    actionCommandStatus->barFillLevel -= D_802A9AA0_42D9B0[actionCommandStatus->barFillLevel / cutoff / 20];
                    if (actionCommandStatus->barFillLevel < 0) {
                        actionCommandStatus->barFillLevel = 0;
                    }
                } else {
                    actionCommandStatus->barFillLevel -= 10;
                    if (actionCommandStatus->barFillLevel < 0) {
                        actionCommandStatus->barFillLevel = 0;
                    }
                }
            }

            if (battleStatus->curButtonsPressed & BUTTON_A) {
                phi_a1 = actionCommandStatus->targetWeakness;
                if (phi_a1 != 0) {
                    s32 a = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty];

                    phi_a1 = (((a * 850) / 100) * phi_a1) / 100;
                    actionCommandStatus->barFillLevel += phi_a1;
                } else {
                    actionCommandStatus->barFillLevel += 100;
                    if (actionCommandStatus->barFillLevel >= 500) {
                        actionCommandStatus->barFillLevel = 500;
                    }
                }
            }

            if (actionCommandStatus->barFillLevel > 10000) {
                actionCommandStatus->barFillLevel = 10000;
                actionCommandStatus->isBarFilled = TRUE;
                id = actionCommandStatus->hudElements[3];
                hud_element_set_render_pos(
                    id,
                    actionCommandStatus->hudPosX + 50,
                    actionCommandStatus->hudPosY + 28);
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionQuality = actionCommandStatus->barFillLevel / 100;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, battleStatus->actionQuality * 12);

            if (actionCommandStatus->frameCounter == 0) {
                phi_a1 = actionCommandStatus->barFillLevel;
                if (actionCommandStatus->targetWeakness == 0) {
                    phi_a1 = 0;
                }

                battleStatus->actionQuality = phi_a1 / 100;
                if (phi_a1 == 0) {
                    battleStatus->actionSuccess = -1;
                } else if (battleStatus->actionQuality >= actionCommandStatus->thresholdLevel) {
                    battleStatus->actionSuccess = 1;
                } else {
                    battleStatus->actionSuccess = 0;
                }

                cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
                if (cutoff / 2 < battleStatus->actionQuality) {
                    battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                } else {
                    battleStatus->actionResult = ACTION_RESULT_MINUS_4;
                }

                if (battleStatus->actionSuccess == 1) {
                    func_80269160();
                }

                sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
                btl_set_popup_duration(0);
                actionCommandStatus->frameCounter = 5;
                actionCommandStatus->state = 12;
            } else {
                actionCommandStatus->frameCounter--;
            }
            break;
        case 12:
            if (actionCommandStatus->targetWeakness == 0) {
                actionCommandStatus->barFillLevel -= 100;
                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
                }
            }
            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                break;
            }
            action_command_free();
            break;
    }

    // Invisible "run away"-like meter that determines success threshold.
    // https://www.youtube.com/watch?v=FagUpV0c67s
    switch (actionCommandStatus->state) {
        case 1:
        case 10:
        case 11:
            if (actionCommandStatus->thresholdMoveDir == 0) {
                actionCommandStatus->thresholdLevel += 7;
                if (actionCommandStatus->thresholdLevel >= 100) {
                    actionCommandStatus->thresholdLevel = 100;
                    actionCommandStatus->thresholdMoveDir = 1;
                }
            } else {
                actionCommandStatus->thresholdLevel -= 7;
                if (actionCommandStatus->thresholdLevel <= 0) {
                    actionCommandStatus->thresholdLevel = 0;
                    actionCommandStatus->thresholdMoveDir = 0;
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
