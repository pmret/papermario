#include "battle/battle.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_air_raid

extern s32 actionCmdTableAirRaid[];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_STICK          = 0,
    HIDX_METER          = 1,
    HIDX_100_PCT        = 2,
};

// how much to add to the meter per input if all modifiers are neutral
#define METER_FILL_RATE 850

s32 N(DrainRateTable)[] = { 0, 25, 50, 75, 75 };

#define GET_DRAIN_RATE(pct) PCT_TO_TABLE_RATE(N(DrainRateTable), pct)

// threshold meter values; not used for anything
// these correspond to values provided via SetupMashMeter
s32 N(BasicThresholds)[] = { 40, 70, 99, 200 };
s32 N(SuperThresholds)[] = { 35, 60, 80, 99, 200 };
s32 N(UltraThresholds)[] = { 35, 35, 60, 80, 99, 200 };

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElemID hid;

    battleStatus->maxActionQuality = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTableAirRaid;
    battleStatus->actionResult = ACTION_RESULT_NONE;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->actionCommandID = ACTION_COMMAND_AIR_RAID;
    acs->showHud = TRUE;
    acs->hudPrepareTime = 30;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->meterFillLevel = 0;
    acs->meterFillWidth = 0;
    acs->isMeterFilled = FALSE;
    battleStatus->actionQuality = 0;
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_StickNeutral);
    acs->hudElemIDs[HIDX_STICK] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

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
    acs->statusChance = evt_get_variable(script, *args++); // unused

    acs->wrongButtonPressed = FALSE;
    acs->meterFillLevel = 0;
    acs->meterFillWidth = 0;
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
    Actor* partner = battleStatus->partnerActor;
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
                return;
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
                return;
            }

            hud_element_set_script(acs->hudElemIDs[HIDX_STICK], &HES_StickMashLeft);
            acs->meterFillLevel = 0;
            battleStatus->resultTier = 0;
            acs->airRaid.holdingLeft = FALSE;
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
                if (battleStatus->curButtonsDown & BUTTON_STICK_LEFT) {
                    acs->airRaid.holdingLeft = TRUE;
                }

                if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT)) {
                    if (acs->airRaid.holdingLeft) {
                        acs->meterFillLevel += SCALE_BY_PCT(METER_FILL_RATE, battleStatus->actionCmdDifficultyTable[acs->difficulty]);
                        acs->airRaid.holdingLeft = FALSE;
                    }
                }

                // right stick inputs actively drain the meter
                if (battleStatus->curButtonsPressed & BUTTON_STICK_RIGHT) {
                    acs->meterFillLevel -= SCALE_BY_PCT(METER_FILL_RATE, battleStatus->actionCmdDifficultyTable[acs->difficulty]);
                }
            }


            if (acs->meterFillLevel < 0) {
                acs->meterFillLevel = 0;
            }

            // handle meter reaching 100%
            if (acs->meterFillLevel > MAX_MASH_UNITS) {
                acs->meterFillLevel = MAX_MASH_UNITS;
                acs->isMeterFilled = TRUE;
                hid = acs->hudElemIDs[HIDX_100_PCT];
                hud_element_set_render_pos(hid, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionProgress = acs->meterFillLevel / ONE_PCT_MASH;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_METER, 0, 0, battleStatus->actionProgress * 12);

            // resultTier is not used by this move; uses actionProgress instead via the move script
            switch (partner->actorBlueprint->level) {
                case PARTNER_RANK_NORMAL:
                    if (battleStatus->actionProgress >= N(BasicThresholds)[battleStatus->resultTier]) {
                        battleStatus->resultTier++;
                    }

                    if (battleStatus->resultTier > 0 && battleStatus->actionProgress < N(BasicThresholds)[battleStatus->resultTier - 1]) {
                        battleStatus->resultTier--;
                    }
                    break;
                case PARTNER_RANK_SUPER:
                    if (battleStatus->actionProgress >= N(SuperThresholds)[battleStatus->resultTier]) {
                        battleStatus->resultTier++;
                    }
                    if (battleStatus->resultTier > 0 && battleStatus->actionProgress < N(SuperThresholds)[battleStatus->resultTier - 1]) {
                        battleStatus->resultTier--;
                    }
                    break;
                case PARTNER_RANK_ULTRA:
                    if (battleStatus->actionProgress >= N(UltraThresholds)[battleStatus->resultTier]) {
                        battleStatus->resultTier++;
                    }
                    if (battleStatus->resultTier > 0 && battleStatus->actionProgress < N(UltraThresholds)[battleStatus->resultTier - 1]) {
                        battleStatus->resultTier--;
                    }
                    break;
            }

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
