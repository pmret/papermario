#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_spiny_surge

extern s32 actionCmdTableSpinySurge[];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_STICK          = 0,
    HIDX_METER          = 1,
    HIDX_100_PCT        = 2,
};

// how much to add to the meter per input
#define METER_FILL_TICK 1250

s32 N(DrainRateTable)[] = { 0, 25, 50, 75, 75 };

#define GET_DRAIN_RATE(pct) PCT_TO_TABLE_RATE(N(DrainRateTable), pct)

BSS s32 PrevButtons;

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElemID hid;

    battleStatus->maxActionQuality = 16;
    battleStatus->actionCmdDifficultyTable = actionCmdTableSpinySurge;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->actionCommandID = ACTION_COMMAND_SPINY_SURGE;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = false;
    acs->meterFillLevel = 0;
    acs->meterFillWidth = 0;
    acs->isMeterFilled = false;
    battleStatus->actionQuality = 0;
    battleStatus->actionResult = ACTION_RESULT_FAIL;
    acs->hudPrepareTime = 30;
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_StickNeutral);
    acs->hudElemIDs[HIDX_STICK] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_BlueMeter);
    acs->hudElemIDs[HIDX_METER] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_100pct);
    acs->hudElemIDs[HIDX_100_PCT] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER | HUD_ELEMENT_FLAG_DISABLED);

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

    acs->wrongButtonPressed = false;
    acs->meterFillLevel = 0;
    acs->meterFillWidth = 0;
    battleStatus->actionQuality = 0;
    acs->state = AC_STATE_START;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

    increment_action_command_attempt_count();

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElemID hid;
    s32 cutoff;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);

            hid = acs->hudElemIDs[HIDX_STICK];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElemIDs[HIDX_METER];
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
                break;
            }

            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }

            hud_element_set_render_pos(acs->hudElemIDs[HIDX_STICK], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_METER], acs->hudPosX, acs->hudPosY + 28);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);

            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                break;
            }

            hud_element_set_script(acs->hudElemIDs[HIDX_STICK], &HES_StickMashLeft);
            acs->spinySurge.tossState = SPINY_SURGE_NONE;
            PrevButtons = 0;
            acs->stateTimer = acs->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_METER, 0, 0, 0);
            acs->state = AC_STATE_ACTIVE;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);

            // meter can drain if it hasn't been fully filled
            if (!acs->isMeterFilled) {
                cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals];
                acs->meterFillLevel -= GET_DRAIN_RATE(acs->meterFillLevel / cutoff);
                if (acs->meterFillLevel < 0) {
                    acs->meterFillLevel = 0;
                }
            }

            // check for meter-filling input
            if (!acs->isMeterFilled) {
                if (battleStatus->curButtonsPressed & BUTTON_STICK_LEFT) {
                    acs->meterFillLevel += SCALE_BY_PCT(METER_FILL_TICK, battleStatus->actionCmdDifficultyTable[acs->difficulty]);
                }
                // right stick inputs actively drain the meter
                if (battleStatus->curButtonsPressed & BUTTON_STICK_RIGHT) {
                    acs->meterFillLevel -= SCALE_BY_PCT(METER_FILL_TICK, battleStatus->actionCmdDifficultyTable[acs->difficulty]);
                }
            }

            if (acs->meterFillLevel < 0) {
                acs->meterFillLevel = 0;
            }

            // handle meter reaching 100%
            if (acs->meterFillLevel > MAX_MASH_UNITS) {
                acs->meterFillLevel = MAX_MASH_UNITS;
                acs->isMeterFilled = true;
                hid = acs->hudElemIDs[HIDX_100_PCT];
                hud_element_set_render_pos(hid, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            // set signal value for the move script to play throwing animations
            if (PrevButtons & BUTTON_STICK_LEFT) {
                acs->spinySurge.tossState = SPINY_SURGE_HOLD;
            }
            if (PrevButtons & BUTTON_STICK_RIGHT) {
                acs->spinySurge.tossState = SPINY_SURGE_RESET;
            }
            if (!(PrevButtons & BUTTON_STICK_LEFT)
                && !(battleStatus->curButtonsDown & BUTTON_STICK_RIGHT)
                && acs->spinySurge.tossState == SPINY_SURGE_HOLD
            ) {
                acs->spinySurge.tossState = SPINY_SURGE_THROW;
            }
            battleStatus->actionQuality = acs->meterFillLevel / ONE_PCT_MASH;
            PrevButtons = battleStatus->curButtonsDown;
            battleStatus->actionProgress = acs->spinySurge.tossState;

            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_METER, 0, 0, battleStatus->actionQuality * 12);

            if (acs->stateTimer != 0) {
                acs->stateTimer--;
                break;
            }

            if (acs->meterFillLevel == 0) {
                battleStatus->actionQuality = AC_QUALITY_FAILED;
            } else {
                battleStatus->actionQuality = acs->meterFillLevel / ONE_PCT_MASH;
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
            sfx_stop_sound(SOUND_LOOP_CHARGE_METER);
            acs->stateTimer = 5;
            acs->state = AC_STATE_DISPOSE;
            break;
        case AC_STATE_DISPOSE:
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
