#include "common.h"
#include "battle/action_cmd.h"

/**
 * The player must mash A to fill up a meter.
 *
 * After a fixed period of time, the fill amount is compared to a "random" threshold
 * value to determine success. This "random" value is selected using a mechanic similar
 * to the flee command -- a random initial value is chosen which begins increasing and
 * decreasing, bounded by the limits of the meter, at a fixed rate until the command
 * is done. However, since the "speed" of the moving value and the duration are both
 * fixed, this is effectively just choosing a random threhsold value.
 */

#define NAMESPACE action_command_power_shock

extern s32 actionCmdTablePowerShock[];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_BUTTON         = 0,
    HIDX_METER          = 1,
    HIDX_RUN_AWAY       = 2, // unused
    HIDX_100_PCT        = 3,
    HIDX_OK             = 4,
};

// how much to add to the meter per input
#define METER_FILL_TICK 850

s32 N(DrainRateTable)[] = { 0, 25, 50, 75, 75 };

#define GET_DRAIN_RATE(pct) (N(DrainRateTable)[((pct) / (ONE_PCT_MASH / 5))])

BSS s32 N(HasStarted);

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElemID hid;
    s32 offsetX;

    battleStatus->maxActionQuality = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTablePowerShock;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    acs->actionCommandID = ACTION_COMMAND_POWER_SHOCK;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = false;
    acs->meterFillLevel = 0;
    acs->meterFillWidth = 0;
    acs->escapeThreshold = rand_int(100);
    acs->hudPrepareTime = 30;
    acs->isMeterFilled = false;
    acs->thresholdMoveDir = 0;
    N(HasStarted) = false;

    acs->hudPosX = -48;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_AButton);
    acs->hudElemIDs[HIDX_BUTTON] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);

    hid = hud_element_create(&HES_BlueMeter);
    acs->hudElemIDs[HIDX_METER] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_100pct);
    acs->hudElemIDs[HIDX_100_PCT] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_RunAwayOK);
    acs->hudElemIDs[HIDX_OK] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    offsetX = 29 - ((100 - acs->escapeThreshold) * 60) / 100;
    hud_element_set_render_pos(acs->hudElemIDs[HIDX_100_PCT], acs->hudPosX - offsetX, acs->hudPosY + 17);
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
    acs->statusChance = evt_get_variable(script, *args++); // chance for enemy to be affected

    acs->wrongButtonPressed = false;
    acs->meterFillLevel = 0;
    acs->meterFillWidth = 0;
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
    HudElemID hid;
    s32 amt;
    s32 cutoff;
    s32 offsetX;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);
            hid = acs->hudElemIDs[HIDX_BUTTON];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);
            hid = acs->hudElemIDs[HIDX_METER];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hid = acs->hudElemIDs[HIDX_OK];
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
                hud_element_set_render_pos(acs->hudElemIDs[HIDX_BUTTON], acs->hudPosX, acs->hudPosY);
                hud_element_set_render_pos(acs->hudElemIDs[HIDX_METER], acs->hudPosX, acs->hudPosY + 28);

                amt = 100 - acs->escapeThreshold;
                offsetX = 29 - (amt * 60) / 100;
                hud_element_set_render_pos(acs->hudElemIDs[HIDX_OK], acs->hudPosX - offsetX, acs->hudPosY + 17);
            }
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                break;
            }
            hud_element_set_script(acs->hudElemIDs[HIDX_BUTTON], &HES_MashAButton);
            acs->meterFillLevel = 0;
            acs->any.unk_5C = 0;
            N(HasStarted) = true;
            acs->stateTimer = acs->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_METER, 0, 0, 0);
            acs->state = AC_STATE_ACTIVE;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);

            // meter can drain if it hasn't been fully filled
            if (!acs->isMeterFilled) {
                if (acs->statusChance != 0) {
                    cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals];
                    acs->meterFillLevel -= GET_DRAIN_RATE(acs->meterFillLevel / cutoff);
                    if (acs->meterFillLevel < 0) {
                        acs->meterFillLevel = 0;
                    }
                } else {
                    acs->meterFillLevel -= 10;
                    if (acs->meterFillLevel < 0) {
                        acs->meterFillLevel = 0;
                    }
                }
            }

            // check for meter-filling input
            if (battleStatus->curButtonsPressed & BUTTON_A) {
                if (acs->statusChance != 0) {
                    s32 difficultyPct = battleStatus->actionCmdDifficultyTable[acs->difficulty];
                    amt = SCALE_BY_PCT(SCALE_BY_PCT(METER_FILL_TICK, difficultyPct), acs->statusChance);

                    acs->meterFillLevel += amt;
                } else {
                    acs->meterFillLevel += ONE_PCT_MASH;
                    if (acs->meterFillLevel >= 5 * ONE_PCT_MASH) {
                        acs->meterFillLevel = 5 * ONE_PCT_MASH;
                    }
                }
            }

            // handle meter reaching 100%
            if (acs->meterFillLevel > MAX_MASH_UNITS) {
                acs->meterFillLevel = MAX_MASH_UNITS;
                acs->isMeterFilled = true;
                hid = acs->hudElemIDs[HIDX_100_PCT];
                hud_element_set_render_pos(hid, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionProgress = acs->meterFillLevel / ONE_PCT_MASH;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_METER, 0, 0, battleStatus->actionProgress * 12);

            if (acs->stateTimer != 0) {
                acs->stateTimer--;
                break;
            }

            amt = acs->meterFillLevel;
            if (acs->statusChance == 0) {
                amt = 0;
            }

            battleStatus->actionProgress = amt / ONE_PCT_MASH;
            if (amt == 0) {
                battleStatus->actionQuality = AC_QUALITY_FAILED;
            } else if (battleStatus->actionProgress >= acs->escapeThreshold) {
                battleStatus->actionQuality = 1;
            } else {
                battleStatus->actionQuality = 0;
            }

            // a good result is filling the meter over halfway to the second-highest interval
            cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals - 1];
            if (battleStatus->actionProgress <= cutoff / 2) {
                battleStatus->actionResult = ACTION_RESULT_METER_BELOW_HALF;
            } else {
                battleStatus->actionResult = ACTION_RESULT_SUCCESS;
            }

            if (battleStatus->actionQuality == 1) {
                increment_action_command_success_count();
            }

            sfx_stop_sound(SOUND_LOOP_CHARGE_METER);
            btl_set_popup_duration(POPUP_MSG_OFF);
            acs->stateTimer = 5;
            acs->state = AC_STATE_DISPOSE;
            break;
        case AC_STATE_DISPOSE:
            if (acs->statusChance == 0) {
                acs->meterFillLevel -= ONE_PCT_MASH;
                if (acs->meterFillLevel < 0) {
                    acs->meterFillLevel = 0;
                }
            }
            if (acs->stateTimer != 0) {
                acs->stateTimer--;
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
                acs->escapeThreshold += 7;
                if (acs->escapeThreshold >= 100) {
                    acs->escapeThreshold = 100;
                    acs->thresholdMoveDir = 1;
                }
            } else {
                acs->escapeThreshold -= 7;
                if (acs->escapeThreshold <= 0) {
                    acs->escapeThreshold = 0;
                    acs->thresholdMoveDir = 0;
                }
            }
    }
}

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hudX, hudY;
    HudElemID hid;

    hudX = 60 - (acs->escapeThreshold * 60 / 100);
    hud_element_set_render_pos(acs->hudElemIDs[HIDX_OK], acs->hudPosX + 31 - hudX, acs->hudPosY + 17);
    hud_element_draw_clipped(acs->hudElemIDs[HIDX_BUTTON]);

    hid = acs->hudElemIDs[HIDX_METER];
    hud_element_draw_clipped(hid);
    hud_element_get_render_pos(hid, &hudX, &hudY);
    // Redundant call, but needed to match.
    hud_element_get_render_pos(hid, &hudX, &hudY);

    if (!N(HasStarted)) {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->meterFillLevel / ONE_PCT_MASH, 1);
    } else if (!acs->isMeterFilled) {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->meterFillLevel / ONE_PCT_MASH, 4);
    } else {
        draw_mash_meter_blink_with_divisor(hudX, hudY, acs->meterFillLevel / ONE_PCT_MASH, 4);
    }
    hid = acs->hudElemIDs[HIDX_100_PCT];
    hud_element_draw_clipped(hid);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_BUTTON]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_METER]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_100_PCT]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_OK]);
}
