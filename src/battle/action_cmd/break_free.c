#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_break_free

extern s32 actionCmdTableBreakFree[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    battleStatus->unk_82 = 0;
    battleStatus->actionCmdDifficultyTable = actionCmdTableBreakFree;
    battleStatus->actionResult = ACTION_RESULT_NONE;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    acs->actionCommandID = ACTION_COMMAND_BREAK_FREE;
    acs->showHud = TRUE;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->thresholdLevel = 0;
    acs->barFillWidth = 0;
    battleStatus->actionSuccess = 0;
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    id = hud_element_create(&HES_AButton);
    acs->hudElements[0] = id;
    hud_element_set_render_pos(id, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_BlueMeter);
    acs->hudElements[1] = id;
    hud_element_set_render_pos(id, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_RunningAway);
    acs->hudElements[2] = id;
    hud_element_set_render_pos(id, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_RunAwayOK);
    acs->hudElements[3] = id;
    hud_element_set_render_pos(id, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

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
    acs->effectiveness = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);

    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->thresholdLevel = 0;
    acs->barFillWidth = 0;

    battleStatus->actionSuccess = 0;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    battleStatus->unk_82 = acs->mashMeterCutoffs[acs->mashMeterNumIntervals - 1];

    acs->thresholdLevel = rand_int(acs->effectiveness);
    acs->any.unk_5C = 0;
    acs->state = AC_STATE_START;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hid;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);

            hid = acs->hudElements[0];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElements[1];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElements[2];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElements[3];
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
            hud_element_set_render_pos(acs->hudElements[0], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[1], acs->hudPosX, acs->hudPosY + 28);
            hud_element_set_render_pos(acs->hudElements[2], acs->hudPosX + 31, acs->hudPosY - 1);
            hud_element_set_render_pos(acs->hudElements[3], acs->hudPosX + 31, acs->hudPosY + 17);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }
            hud_element_set_script(acs->hudElements[0], &HES_MashAButton);
            acs->state = AC_STATE_ACTIVE;
            acs->frameCounter = acs->duration;
            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->any.unk_5C == 0) {
                acs->thresholdLevel++;
                if (acs->thresholdLevel >= acs->effectiveness) {
                    acs->thresholdLevel = acs->effectiveness;
                    acs->any.unk_5C = 1;
                }
            } else {
                acs->thresholdLevel--;
                if (acs->thresholdLevel <= 0) {
                    acs->thresholdLevel = 0;
                    acs->any.unk_5C = 0;
                }
            }

            if (!acs->berserkerEnabled) {
                s32 inputBufPos = battleStatus->inputBufferPos;
                s32 windowLen = acs->duration - acs->frameCounter;
                s32 i;

                acs->barFillLevel = 0;

                inputBufPos -= windowLen;
                if (inputBufPos < 0) {
                    inputBufPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
                }

                for (i = 0; i < windowLen; i++, inputBufPos++) {
                    if (inputBufPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        inputBufPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }
                    if (battleStatus->pushInputBuffer[inputBufPos] & BUTTON_A) {
                        acs->barFillLevel += battleStatus->actionCmdDifficultyTable[acs->difficulty];
                    }
                }
            } else {
                acs->barFillLevel += (battleStatus->actionCmdDifficultyTable[acs->difficulty]) / 4;
                acs->barFillLevel += rand_int(battleStatus->actionCmdDifficultyTable[acs->difficulty] / 4);
            }

            battleStatus->actionSuccess = acs->barFillLevel / 100;
            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                return;
            }

            if (battleStatus->actionSuccess >= acs->mashMeterCutoffs[acs->mashMeterNumIntervals] - acs->thresholdLevel) {
                battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                battleStatus->actionSuccess = 1;
            } else {
                battleStatus->actionResult = ACTION_RESULT_MINUS_2;
                battleStatus->actionSuccess = -1;
            }

            btl_set_popup_duration(POPUP_MSG_OFF);
            acs->frameCounter = 20;
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

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32* hudElements = acs->hudElements;
    s32 hudX;
    s32 hudY;
    s32 id;
    s16 mashMeterCutoff;
    s32 thirtyOne;

    mashMeterCutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals];
    hudX = 60 - ((mashMeterCutoff - acs->thresholdLevel) * 60 / mashMeterCutoff);

    // Putting 31 into a variable manually fixes regalloc, so perhaps this was a constant defined somewhere?
    thirtyOne = 31;
    hud_element_set_render_pos(hudElements[3], acs->hudPosX - (hudX - thirtyOne), acs->hudPosY + 17);
    hud_element_set_render_pos(hudElements[2], acs->hudPosX - (hudX - thirtyOne), acs->hudPosY - 1);

    if (!acs->berserkerEnabled) {
        hud_element_draw_clipped(hudElements[0]);
    }

    id = hudElements[1];
    hud_element_draw_clipped(id);
    hud_element_get_render_pos(id, &hudX, &hudY);

    draw_mash_meter_multicolor(hudX, hudY, acs->barFillLevel / 100);
    hud_element_draw_clipped(hudElements[2]);
    hud_element_draw_clipped(hudElements[3]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
}
