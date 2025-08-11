#include "common.h"
#include "battle/action_cmd.h"

/**
 * Differs from most mash commands by not having a fixed time limit and not having
 * a rising sound effect as it fills.
 */

#define NAMESPACE action_command_stop_leech

extern s32 actionCmdTableStopLeech[];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_BUTTON         = 0,
    HIDX_METER          = 1,
};

// how much to add to the meter per input if all modifiers are neutral
#define METER_FILL_TICK 100

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElemID hid;

    battleStatus->maxActionQuality = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTableStopLeech;
    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->actionCommandID = ACTION_COMMAND_STOP_LEECH;
    acs->hudPosX = -48;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = false;
    acs->meterFillLevel = 0;
    acs->meterFillWidth = 0;
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
    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    Bytecode* args = script->ptrReadPos;
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

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
    battleStatus->actionResult = ACTION_RESULT_FAIL;
    acs->state = AC_STATE_START;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

    return ApiStatus_DONE2;
}

void N(update)(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* acs = &gActionCommandStatus;
    HudElemID hid;

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
            acs->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            btl_set_popup_duration(POPUP_MSG_ON);
            acs->hudPosX = acs->hudPosX + 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_BUTTON], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_METER], acs->hudPosX, acs->hudPosY + 28);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                break;
            }
            hud_element_set_script(acs->hudElemIDs[HIDX_BUTTON], &HES_MashAButton);
            acs->meterFillLevel = 0;
            acs->state = AC_STATE_ACTIVE;
            acs->stateTimer = acs->duration;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);

            // check for meter-filling input
            if (!acs->berserkerEnabled) {
                if (battleStatus->curButtonsPressed & BUTTON_A) {
                    acs->meterFillLevel += SCALE_BY_PCT(METER_FILL_TICK, battleStatus->actionCmdDifficultyTable[acs->difficulty]);
                }
            } else {
                acs->meterFillLevel += SCALE_BY_PCT(METER_FILL_TICK, battleStatus->actionCmdDifficultyTable[acs->difficulty]) / 6;
                acs->meterFillLevel += rand_int(SCALE_BY_PCT(METER_FILL_TICK, battleStatus->actionCmdDifficultyTable[acs->difficulty]) / 6);
            }
            battleStatus->actionProgress = acs->meterFillLevel / ONE_PCT_MASH;

            // handle filling the meter
            if (acs->mashMeterCutoffs[acs->mashMeterNumIntervals] <= battleStatus->actionProgress) {
                acs->stateTimer = 0;
            }

            if (acs->stateTimer == 0) {
                btl_set_popup_duration(POPUP_MSG_OFF);
                acs->stateTimer = 5;
                acs->state = AC_STATE_DISPOSE;
                break;
            }
            acs->stateTimer--;
            break;
        case AC_STATE_DISPOSE:
            if (acs->stateTimer != 0) {
                acs->stateTimer--;
                break;
            }
            battleStatus->actionQuality = 1;
            battleStatus->actionResult = ACTION_RESULT_NONE;
            action_command_free();
        default:
            break;
    }
}

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hudX, hudY;
    HudElemID hid;

    if (!acs->berserkerEnabled) {
        hud_element_draw_clipped(acs->hudElemIDs[HIDX_BUTTON]);
    }

    hid = acs->hudElemIDs[HIDX_METER];
    hud_element_draw_clipped(hid);
    hud_element_get_render_pos(hid, &hudX, &hudY);
    draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->meterFillLevel / ONE_PCT_MASH, 2);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_BUTTON]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_METER]);
}
