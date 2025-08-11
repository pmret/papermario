#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_break_free

extern s32 actionCmdTableBreakFree[];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_BUTTON         = 0,
    HIDX_METER          = 1,
    HIDX_RUN_AWAY       = 2,
    HIDX_OK             = 3,
};

// how much to add to the meter per input if all modifiers are neutral
#define METER_FILL_RATE 100

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElemID hid;

    battleStatus->maxActionQuality = 0;
    battleStatus->actionCmdDifficultyTable = actionCmdTableBreakFree;
    battleStatus->actionResult = ACTION_RESULT_NONE;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->actionCommandID = ACTION_COMMAND_BREAK_FREE;
    acs->showHud = true;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = false;
    acs->meterFillLevel = 0;
    acs->escapeThreshold = 0;
    acs->meterFillWidth = 0;
    battleStatus->actionQuality = 0;
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_AButton);
    acs->hudElemIDs[HIDX_BUTTON] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_BlueMeter);
    acs->hudElemIDs[HIDX_METER] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_RunningAway);
    acs->hudElemIDs[HIDX_RUN_AWAY] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_RunAwayOK);
    acs->hudElemIDs[HIDX_OK] = hid;
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
    acs->escapeChance = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);

    acs->wrongButtonPressed = false;
    acs->meterFillLevel = 0;
    acs->escapeThreshold = 0;
    acs->meterFillWidth = 0;

    battleStatus->actionQuality = 0;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    battleStatus->maxActionQuality = acs->mashMeterCutoffs[acs->mashMeterNumIntervals - 1];

    acs->escapeThreshold = rand_int(acs->escapeChance);
    acs->breakFree.dir = 0;
    acs->state = AC_STATE_START;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElemID hid;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);

            hid = acs->hudElemIDs[HIDX_BUTTON];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElemIDs[HIDX_METER];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElemIDs[HIDX_RUN_AWAY];
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
            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_BUTTON], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_METER], acs->hudPosX, acs->hudPosY + 28);
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_RUN_AWAY], acs->hudPosX + 31, acs->hudPosY - 1);
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_OK], acs->hudPosX + 31, acs->hudPosY + 17);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }
            hud_element_set_script(acs->hudElemIDs[HIDX_BUTTON], &HES_MashAButton);
            acs->state = AC_STATE_ACTIVE;
            acs->stateTimer = acs->duration;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);

            // update the position of the 'OK' tick
            if (acs->breakFree.dir == 0) {
                acs->escapeThreshold++;
                if (acs->escapeThreshold >= acs->escapeChance) {
                    acs->escapeThreshold = acs->escapeChance;
                    acs->breakFree.dir = 1;
                }
            } else {
                acs->escapeThreshold--;
                if (acs->escapeThreshold <= 0) {
                    acs->escapeThreshold = 0;
                    acs->breakFree.dir = 0;
                }
            }

            // unlike most other mash inputs, this command doesn't just increment meterFillLevel with inputs
            // instead we sum the total number of inputs during the last N frames of the input buffer
            if (!acs->berserkerEnabled) {
                s32 inputBufPos = battleStatus->inputBufferPos;
                s32 windowLen = acs->duration - acs->stateTimer;
                s32 i;

                acs->meterFillLevel = 0;

                inputBufPos -= windowLen;
                if (inputBufPos < 0) {
                    inputBufPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
                }

                for (i = 0; i < windowLen; i++, inputBufPos++) {
                    if (inputBufPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        inputBufPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }
                    if (battleStatus->pushInputBuffer[inputBufPos] & BUTTON_A) {
                        acs->meterFillLevel += SCALE_BY_PCT(METER_FILL_RATE, battleStatus->actionCmdDifficultyTable[acs->difficulty]);
                    }
                }
            } else {
                acs->meterFillLevel += SCALE_BY_PCT(25, battleStatus->actionCmdDifficultyTable[acs->difficulty]);
                acs->meterFillLevel += rand_int(SCALE_BY_PCT(25, battleStatus->actionCmdDifficultyTable[acs->difficulty]));
            }

            battleStatus->actionQuality = acs->meterFillLevel / ONE_PCT_MASH;
            if (acs->stateTimer != 0) {
                acs->stateTimer--;
                break;
            }

            if (battleStatus->actionQuality >= acs->mashMeterCutoffs[acs->mashMeterNumIntervals] - acs->escapeThreshold) {
                battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                battleStatus->actionQuality = 1;
            } else {
                battleStatus->actionResult = ACTION_RESULT_METER_NOT_ENOUGH;
                battleStatus->actionQuality = AC_QUALITY_FAILED;
            }

            btl_set_popup_duration(POPUP_MSG_OFF);
            acs->stateTimer = 20;
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

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32* hudElements = acs->hudElemIDs;
    s32 hudX, hudY;
    HudElemID hid;
    s16 maxMeterValue;

    // equivalent to 60 * acs->escapeThreshold / maxMeterValue
    maxMeterValue = acs->mashMeterCutoffs[acs->mashMeterNumIntervals];
    hudX = 60 - ((maxMeterValue - acs->escapeThreshold) * 60 / maxMeterValue);

    hud_element_set_render_pos(hudElements[HIDX_OK], acs->hudPosX + 31 - hudX, acs->hudPosY + 17);
    hud_element_set_render_pos(hudElements[HIDX_RUN_AWAY], acs->hudPosX + 31 - hudX, acs->hudPosY - 1);

    if (!acs->berserkerEnabled) {
        hud_element_draw_clipped(hudElements[HIDX_BUTTON]);
    }

    hid = hudElements[HIDX_METER];
    hud_element_draw_clipped(hid);
    hud_element_get_render_pos(hid, &hudX, &hudY);

    draw_mash_meter_multicolor(hudX, hudY, acs->meterFillLevel / ONE_PCT_MASH);
    hud_element_draw_clipped(hudElements[HIDX_RUN_AWAY]);
    hud_element_draw_clipped(hudElements[HIDX_OK]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_BUTTON]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_METER]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_RUN_AWAY]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_OK]);
}
