#include "common.h"
#include "audio/public.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_spook

extern s32 actionCmdTableSpook[];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_STICK          = 0,
    HIDX_METER          = 1,
    HIDX_100_PCT        = 2,
};

// how much to add to the meter per input
#define METER_FILL_TICK 850

s32 N(DrainRateTable)[] = { 0, 25, 50, 75, 75 };

#define GET_DRAIN_RATE(pct) PCT_TO_TABLE_RATE(N(DrainRateTable), pct)

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hid;

    battleStatus->maxActionQuality = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTableSpook;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }
    action_command_init_status();
    acs->actionCommandID = ACTION_COMMAND_SPOOK;
    acs->showHud = TRUE;
    acs->hudPrepareTime = 30;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    acs->isBarFilled = FALSE;
    battleStatus->actionQuality = 0;
    battleStatus->actionProgress = 0;
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_StickNeutral);
    acs->hudElements[HIDX_STICK] = hid;
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

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->prepareTime = evt_get_variable(script, *args++);
    acs->duration = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);
    acs->statusChance = evt_get_variable(script, *args++); // average chance for enemies to be affected

    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    battleStatus->actionQuality = 0;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    battleStatus->maxActionQuality = acs->mashMeterCutoffs[(acs->mashMeterNumIntervals - 1)];
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    acs->state = AC_STATE_START;

    increment_action_command_attempt_count();

    return ApiStatus_DONE2;
}


void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hid;
    s32 cutoff;
    s32 fillLevel;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);

            hid = acs->hudElements[HIDX_STICK];
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
            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }
            hud_element_set_render_pos(acs->hudElements[HIDX_STICK], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[HIDX_METER], acs->hudPosX, acs->hudPosY + 28);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }
            hud_element_set_script(acs->hudElements[HIDX_STICK], &HES_StickMashLeft);
            acs->barFillLevel = 0;
            battleStatus->actionProgress = 0;
            acs->spook.holdingLeft = FALSE;
            acs->stateTimer = acs->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            acs->state = AC_STATE_ACTIVE;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);

            // bar can drain if it hasn't been fully filled
            if (!acs->isBarFilled) {
                if (acs->statusChance != 0) {
                    cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals];
                    acs->barFillLevel -= GET_DRAIN_RATE(acs->barFillLevel / cutoff);
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
            if (!acs->isBarFilled) {
                if (acs->statusChance != 0) {

                    if (battleStatus->curButtonsDown & BUTTON_STICK_LEFT) {
                        acs->spook.holdingLeft = TRUE;
                    }

                    if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT) && acs->spook.holdingLeft) {
                        s32 a = battleStatus->actionCmdDifficultyTable[acs->difficulty];
                        s32 b = METER_FILL_TICK * acs->statusChance;
                        // divide by 100 for each percent-based multiplier
                        acs->barFillLevel += (a * b) / (100 * 100);
                        acs->spook.holdingLeft = FALSE;
                    }

                    if (battleStatus->curButtonsPressed & BUTTON_STICK_RIGHT) {
                        s32 a = battleStatus->actionCmdDifficultyTable[acs->difficulty];
                        s32 b = METER_FILL_TICK * acs->statusChance;
                        // divide by 100 for each percent-based multiplier
                        acs->barFillLevel -= (a * b) / (100 * 100);
                    }
                } else {
                    if (battleStatus->curButtonsDown & BUTTON_STICK_LEFT) {
                        acs->spook.holdingLeft = TRUE;
                    }

                    if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT) && acs->spook.holdingLeft) {
                        acs->barFillLevel += ONE_PCT_MASH;
                        if (acs->barFillLevel >= 5 * ONE_PCT_MASH) {
                            acs->barFillLevel = 5 * ONE_PCT_MASH;
                        }
                        acs->spook.holdingLeft = FALSE;
                    }

                    if (battleStatus->curButtonsPressed & BUTTON_STICK_RIGHT) {
                        acs->barFillLevel -= ONE_PCT_MASH;
                    }
                }
            }

            if (acs->barFillLevel < 0) {
                acs->barFillLevel = 0;
            }

            // handle bar reaching 100%
            if (acs->barFillLevel > MAX_MASH_UNITS) {
                acs->barFillLevel = MAX_MASH_UNITS;
                acs->isBarFilled = TRUE;
                hid = acs->hudElements[HIDX_100_PCT];
                hud_element_set_render_pos(hid, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionProgress = acs->barFillLevel / ONE_PCT_MASH;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, battleStatus->actionProgress * 12);

            if (acs->stateTimer != 0) {
                acs->stateTimer--;
                break;
            }

            fillLevel = acs->barFillLevel;
            if (acs->statusChance == 0) {
                fillLevel = 0;
            }

            if (fillLevel == 0) {
                battleStatus->actionQuality = AC_QUALITY_FAILED;
            } else {
                battleStatus->actionQuality = fillLevel / ONE_PCT_MASH;

            }

            cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals - 1];
            if (battleStatus->actionQuality > cutoff) {
                battleStatus->actionResult = ACTION_RESULT_SUCCESS;
            } else {
                battleStatus->actionResult = ACTION_RESULT_METER_NOT_ENOUGH;
            }

            if (battleStatus->actionQuality == 100) {
                // only count 100% fill as success for this action command
                increment_action_command_success_count();
            }

            btl_set_popup_duration(POPUP_MSG_OFF);
            sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
            acs->stateTimer = 5;
            acs->state = AC_STATE_DISPOSE;
            break;
        case AC_STATE_DISPOSE:
            if (acs->statusChance == 0) {
                acs->barFillLevel -= ONE_PCT_MASH;
                if (acs->barFillLevel < 0) {
                    acs->barFillLevel = 0;
                }
            }

            if (acs->stateTimer != 0) {
                acs->stateTimer--;
                break;
            }
            action_command_free();
            break;
    }
}

#include "common/MashCommandDraw.inc.c"

#include "common/MashCommandFree.inc.c"
