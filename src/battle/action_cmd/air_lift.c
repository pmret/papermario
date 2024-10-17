#include "common.h"
#include "effects.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_air_lift

extern s32 actionCmdTableAirLift[];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_BUTTON         = 0,
    HIDX_METER          = 1,
    HIDX_100_PCT        = 2,
};

// how much to add to the meter per input if all modifiers are neutral
#define METER_FILL_RATE 820

s32 N(DrainRateTable)[] = { 0, 25, 50, 75, 75 };

#define GET_DRAIN_RATE(pct) PCT_TO_TABLE_RATE(N(DrainRateTable), pct)

BSS b32 N(HasStarted);

API_CALLABLE(N(init)) {
    s32 *args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hid;

    battleStatus->actionCmdDifficultyTable = actionCmdTableAirLift;
    battleStatus->unk_82 = 0;
    battleStatus->actionResult = ACTION_RESULT_NONE;

    action_command_init_status();

    // effectiveness for this move comes from AirLiftChance, which ultimately depends on
    // the target actor's HP and status. this value will ONLY be zero if the target actor
    // is transparent, in which case a dummy version of the action command is played out
    // which is guaranteed to fail.
    acs->effectiveness = evt_get_variable(script, *args++);

    acs->actionCommandID = ACTION_COMMAND_AIR_LIFT;
    acs->showHud = TRUE;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    acs->isBarFilled = FALSE;
    battleStatus->actionSuccess = 0;
    battleStatus->actionQuality = 0;

    N(HasStarted) = FALSE;
    acs->hudPrepareTime = 30;
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_AButton);
    acs->hudElements[HIDX_BUTTON] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_BlueMeter);
    acs->hudElements[HIDX_METER] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_100pct);
    acs->hudElements[HIDX_100_PCT] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    action_command_init_status();

    acs->prepareTime = evt_get_variable(script, *args++);
    acs->duration = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);
    acs->targetWeakness = evt_get_variable(script, *args++);

    acs->wrongButtonPressed = FALSE;
    battleStatus->actionSuccess = 0;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    battleStatus->unk_82 = acs->mashMeterCutoffs[acs->mashMeterNumIntervals - 1];

    acs->any.unk_5C = 0;

    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    acs->state = AC_STATE_START;

    increment_action_command_attempt_count();

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hid;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);

            hid = acs->hudElements[HIDX_BUTTON];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElements[HIDX_METER];
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
                return;
            }

            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }

            hud_element_set_render_pos(acs->hudElements[HIDX_BUTTON], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[HIDX_METER], acs->hudPosX, acs->hudPosY + 28);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);

            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }

            hud_element_set_script(acs->hudElements[HIDX_BUTTON], &HES_MashAButton);
            N(HasStarted) = TRUE;
            acs->frameCounter = acs->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            acs->state = AC_STATE_ACTIVE;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);

            // bar can drain if it hasn't been fully filled
            if (!acs->isBarFilled) {
                if (acs->effectiveness != 0) {
                    s32 maxFillLevel = acs->mashMeterCutoffs[acs->mashMeterNumIntervals];
                    acs->barFillLevel -= GET_DRAIN_RATE(acs->barFillLevel / maxFillLevel);
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

            // check for bar-filling input
            if (battleStatus->actionCommandMode != AC_MODE_NOT_LEARNED && (battleStatus->curButtonsPressed & BUTTON_A)) {
                if (acs->effectiveness != 0) {
                    // fill rate = 820 multiplied by two values expressed as percentages
                    s32 difficultyPct = battleStatus->actionCmdDifficultyTable[acs->difficulty];
                    s32 effectivenessPct = METER_FILL_RATE * acs->effectiveness;
                    // divide by 100 for each percent-based multiplier
                    acs->barFillLevel += (difficultyPct * effectivenessPct) / (100 * 100);
                } else {
                    acs->barFillLevel += ONE_PCT_MASH;
                    if (acs->barFillLevel >= 5 * ONE_PCT_MASH) {
                        acs->barFillLevel = 5 * ONE_PCT_MASH;
                    }
                }
            }

            // handle bar reaching 100%
            if (acs->barFillLevel > MAX_MASH_UNITS) {
                acs->barFillLevel = MAX_MASH_UNITS;
                acs->isBarFilled = TRUE;
                hid = acs->hudElements[HIDX_100_PCT];
                hud_element_set_render_pos(hid, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionSuccess = acs->barFillLevel / ONE_PCT_MASH;
            if (battleStatus->actionQuality < battleStatus->actionSuccess) {
                battleStatus->actionQuality = battleStatus->actionSuccess;
            }
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, battleStatus->actionSuccess * 12);

            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                return;
            }

            if (acs->effectiveness == 0) {
                battleStatus->actionQuality = 0;
            }

            // threshold for success is completely random, only guaranteed if the bar is 100% filled
            battleStatus->actionSuccess = battleStatus->actionQuality;
            if (rand_int(99) < battleStatus->actionSuccess) {
                battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                battleStatus->actionSuccess = 1;
            } else {
                battleStatus->actionResult = ACTION_RESULT_MINUS_2;
                battleStatus->actionSuccess = -1;
            }

            if (battleStatus->actionSuccess == 1) {
                increment_action_command_success_count();
            }

            btl_set_popup_duration(POPUP_MSG_OFF);
            sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
            acs->frameCounter = 20;
            acs->state = AC_STATE_DISPOSE;
            break;
        case AC_STATE_DISPOSE:
            if (acs->effectiveness == 0) {
                acs->barFillLevel -= ONE_PCT_MASH;
                if (acs->barFillLevel < 0) {
                    acs->barFillLevel = 0;
                }
            }
            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                return;
            }
            action_command_free();
            break;
    }
}

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hudX, hudY;
    s32 hid;

    if (gBattleStatus.actionCommandMode != AC_MODE_NOT_LEARNED) {
        hud_element_draw_clipped(acs->hudElements[HIDX_BUTTON]);
    }

    hid = acs->hudElements[HIDX_METER];
    hud_element_draw_clipped(hid);
    hud_element_get_render_pos(hid, &hudX, &hudY);

    if (!N(HasStarted)) {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH, 1);
    } else if (!acs->isBarFilled) {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH, 4);
    } else {
        draw_mash_meter_blink_with_divisor(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH, 4);
    }

    hud_element_draw_clipped(acs->hudElements[HIDX_100_PCT]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[HIDX_BUTTON]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_METER]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_100_PCT]);
}
