#include "battle/battle.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_fire_shell

extern s32 actionCmdTableFireShell[];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_STICK          = 0,
    HIDX_METER          = 1,
    HIDX_100_PCT        = 2,
};

// how much to add to the meter per input
#define METER_FILL_TICK 950

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
    s32 hid;

    battleStatus->unk_82 = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTableFireShell;
    battleStatus->actionResult = ACTION_RESULT_NONE;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }
    action_command_init_status();

    acs->actionCommandID = ACTION_COMMAND_FIRE_SHELL;
    acs->showHud = TRUE;
    acs->hudPrepareTime = 30;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    acs->isBarFilled = FALSE;
    battleStatus->actionSuccess = 0;
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

#include "common/MashCommandStart.inc.c"

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s32 hid;
    s32 cutoff;

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
            battleStatus->resultTier = 0;
            acs->fireShell.holdingLeft = FALSE;
            acs->frameCounter = acs->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            acs->state = AC_STATE_ACTIVE;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);

            // bar can drain if it hasn't been fully filled
            if (!acs->isBarFilled) {
                cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals];
                acs->barFillLevel -= GET_DRAIN_RATE(acs->barFillLevel / cutoff);
                if (acs->barFillLevel < 0) {
                    acs->barFillLevel = 0;
                }
            }

            // check for bar-filling input
            if (!acs->isBarFilled) {
                if (battleStatus->curButtonsDown & BUTTON_STICK_LEFT) {
                    acs->fireShell.holdingLeft = TRUE;
                }

                if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT)) {
                    if (acs->fireShell.holdingLeft != 0) {
                        s32 difficultyPct = battleStatus->actionCmdDifficultyTable[acs->difficulty];
                        acs->barFillLevel += SCALE_BY_PCT(METER_FILL_TICK, difficultyPct);
                        acs->fireShell.holdingLeft = FALSE;
                    }
                }

                // right stick inputs actively drain the bar
                if (battleStatus->curButtonsPressed & BUTTON_STICK_RIGHT) {
                    s32 difficultyPct = battleStatus->actionCmdDifficultyTable[acs->difficulty];
                    acs->barFillLevel -= SCALE_BY_PCT(METER_FILL_TICK, difficultyPct);
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

            battleStatus->actionQuality = acs->barFillLevel / ONE_PCT_MASH;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, battleStatus->actionQuality * 12);

            // resultTier is not used by this move; uses actionQuality instead via the move script
            switch (partner->actorBlueprint->level) {
                case PARTNER_RANK_NORMAL:
                    if (battleStatus->actionQuality >= N(BasicThresholds)[battleStatus->resultTier]) {
                        battleStatus->resultTier++;
                    }
                    if (battleStatus->resultTier > 0 && (battleStatus->actionQuality < N(BasicThresholds)[battleStatus->resultTier - 1])) {
                        battleStatus->resultTier--;
                    }
                    break;
                case PARTNER_RANK_SUPER:
                    if (battleStatus->actionQuality >= N(SuperThresholds)[battleStatus->resultTier]) {
                        battleStatus->resultTier++;
                    }
                    if (battleStatus->resultTier > 0 && (battleStatus->actionQuality < N(SuperThresholds)[battleStatus->resultTier - 1])) {
                        battleStatus->resultTier--;
                    }
                    break;
                case PARTNER_RANK_ULTRA:
                    if (battleStatus->actionQuality >= N(UltraThresholds)[battleStatus->resultTier]) {
                        battleStatus->resultTier++;
                    }
                    if (battleStatus->resultTier > 0 && (battleStatus->actionQuality < N(UltraThresholds)[battleStatus->resultTier - 1])) {
                        battleStatus->resultTier--;
                    }
                    break;
            }

            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                return;
            }

            if (acs->barFillLevel == 0) {
                battleStatus->actionSuccess = AC_ACTION_FAILED;
            } else {
                battleStatus->actionSuccess = acs->barFillLevel / ONE_PCT_MASH;
            }

            cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals - 1];
            if (battleStatus->actionSuccess > cutoff) {
                battleStatus->actionResult = ACTION_RESULT_SUCCESS;
            } else {
                battleStatus->actionResult = ACTION_RESULT_MINUS_2;
            }

            if (battleStatus->actionSuccess == 100) {
                // only count 100% fill as success for this action command
                increment_action_command_success_count();
            }

            sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
            btl_set_popup_duration(POPUP_MSG_OFF);
            acs->frameCounter = 5;
            acs->state = AC_STATE_DISPOSE;
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

#include "common/MashCommandDraw.inc.c"

#include "common/MashCommandFree.inc.c"
