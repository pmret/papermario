#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_squirt

extern s32 actionCmdTableSquirt[];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_BUTTON         = 0,
    HIDX_METER          = 1,
};

// how much to subtract from the meter per frame after overfilling it
#define METER_DRAIN_RATE 250

s32 N(DrainRateTable)[] = { 300, 300, 265, 220, 175, 175 };
s32 N(FillRateTable)[] = { 300, 300, 265, 220, 175, 175 };

// bug: the sixth entry is not accessible due to the way idx is calculated in these macros
#define GET_DRAIN_RATE(pct) (N(DrainRateTable)[((pct) / (ONE_PCT_MASH / 5))])
#define GET_FILL_RATE(pct)  (N(FillRateTable)[((pct) / (ONE_PCT_MASH / 5))])

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hid;

    battleStatus->unk_82 = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTableSquirt;
    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->actionCommandID = ACTION_COMMAND_SQUIRT;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    battleStatus->actionQuality = 0;
    acs->hudPosX = -48;
    acs->squirt.draining = FALSE;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_AButton);
    acs->hudElements[HIDX_BUTTON] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);

    hid = hud_element_create(&HES_BlueMeter);
    acs->hudElements[HIDX_METER] = hid;
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
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->prepareTime = evt_get_variable(script, *args++);
    acs->duration = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);

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
    s32 fillPct;
    s32 cutoff;
    s32 idx;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);

            hid = acs->hudElements[HIDX_BUTTON];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);

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

            hud_element_set_render_pos(acs->hudElements[HIDX_BUTTON], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[HIDX_METER], acs->hudPosX, acs->hudPosY + 28);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);

            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                break;
            }

            hud_element_set_script(acs->hudElements[HIDX_BUTTON], &HES_AButtonDown);
            acs->barFillLevel = 0;
            acs->squirt.draining = FALSE;
            acs->frameCounter = acs->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            acs->state = AC_STATE_ACTIVE;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);

            // bar filling and draining
            cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals];
            fillPct = acs->barFillLevel / cutoff;
            if (!acs->squirt.draining) {
                if (!(battleStatus->curButtonsDown & BUTTON_A)) {
                    acs->barFillLevel -= GET_DRAIN_RATE(fillPct);
                    if (acs->barFillLevel < 0) {
                        acs->barFillLevel = 0;
                    }
                } else {
                    s32 amt = GET_FILL_RATE(fillPct);
                    acs->barFillLevel += SCALE_BY_PCT(amt, battleStatus->actionCmdDifficultyTable[acs->difficulty]);
                    if (acs->barFillLevel > MAX_MASH_UNITS) {
                        acs->barFillLevel = MAX_MASH_UNITS;
                        acs->squirt.draining = TRUE;
                    }
                }
            } else {
                acs->barFillLevel -= METER_DRAIN_RATE;
                if (acs->barFillLevel <= 0) {
                    acs->barFillLevel = 0;
                    acs->squirt.draining = FALSE;
                }
            }

            battleStatus->actionQuality = acs->barFillLevel / ONE_PCT_MASH;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, battleStatus->actionQuality * 12);

            hid = acs->hudElements[HIDX_BUTTON];
            if (fillPct < 80) {
                if (hud_element_get_script(hid) != &HES_AButtonDown) {
                    hud_element_set_script(hid, &HES_AButtonDown);
                }
            } else {
                if (hud_element_get_script(hid) != &HES_PressAButton) {
                    hud_element_set_script(hid, &HES_PressAButton);
                }
            }

            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                return;
            }

            if (acs->barFillLevel == 0) {
                battleStatus->actionSuccess = AC_ACTION_FAILED;
            } else {
                battleStatus->actionSuccess = battleStatus->actionQuality;
            }

            // a good result is filling the bar over halfway to the second-highest interval
            cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals - 1];
            if (cutoff / 2 < battleStatus->actionQuality) {
                battleStatus->actionResult = ACTION_RESULT_SUCCESS;
            } else {
                battleStatus->actionResult = ACTION_RESULT_MINUS_4;
            }

            if (battleStatus->actionSuccess == 100) {
                // only count 100% fill as success for this action command
                increment_action_command_success_count();
            }

            btl_set_popup_duration(POPUP_MSG_OFF);
            sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
            acs->frameCounter = 5;
            acs->state = AC_STATE_DISPOSE;
            break;
        case AC_STATE_DISPOSE:
            if (acs->frameCounter != 0) {
                acs->frameCounter--;
            } else {
                action_command_free();
            }
            break;
    }
}

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hudX, hudY;
    s32 hid;

    hud_element_draw_clipped(acs->hudElements[HIDX_BUTTON]);
    hid = acs->hudElements[HIDX_METER];
    hud_element_draw_clipped(hid);
    hud_element_get_render_pos(hid, &hudX, &hudY);
    if (!acs->squirt.draining) {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH, 1);
    } else {
        draw_mash_meter_mode_with_divisor(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH, 1, MASH_METER_MODE_ONE_COLOR);
    }
}

void N(free)(void) {
    sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_BUTTON]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_METER]);
}
