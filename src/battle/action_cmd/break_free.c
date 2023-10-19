#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_break_free

extern s32 actionCmdTableBreakFree[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    battleStatus->unk_82 = 0;
    battleStatus->actionCmdDifficultyTable = actionCmdTableBreakFree;
    battleStatus->actionResult = ACTION_RESULT_NONE;

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_BREAK_FREE;
    actionCommandStatus->showHud = TRUE;
    actionCommandStatus->state = 0;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->thresholdLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    battleStatus->actionSuccess = 0;
    actionCommandStatus->hudPosX = -48;
    actionCommandStatus->hudPosY = 80;

    id = hud_element_create(&HES_AButton);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_BlueMeter);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_RunningAway);
    actionCommandStatus->hudElements[2] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_RunAwayOK);
    actionCommandStatus->hudElements[3] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    actionCommandStatus->prepareTime = evt_get_variable(script, *args++);
    actionCommandStatus->duration = evt_get_variable(script, *args++);
    actionCommandStatus->unk_5A = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = adjust_action_command_difficulty(actionCommandStatus->difficulty);

    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->thresholdLevel = 0;
    actionCommandStatus->barFillWidth = 0;

    battleStatus->actionSuccess = 0;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    battleStatus->unk_82 = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];

    actionCommandStatus->thresholdLevel = rand_int(actionCommandStatus->unk_5A);
    actionCommandStatus->unk_5C = 0;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);

            id = actionCommandStatus->hudElements[0];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }

            id = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }

            id = actionCommandStatus->hudElements[2];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }

            id = actionCommandStatus->hudElements[3];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }

            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);
            actionCommandStatus->hudPosX += 20;
            if (actionCommandStatus->hudPosX > 50) {
                actionCommandStatus->hudPosX = 50;
            }
            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
            hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudPosX + 31, actionCommandStatus->hudPosY - 1);
            hud_element_set_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudPosX + 31, actionCommandStatus->hudPosY + 17);
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->prepareTime != 0) {
                actionCommandStatus->prepareTime--;
                return;
            }
            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_MashAButton);
            actionCommandStatus->state = 11;
            actionCommandStatus->frameCounter = actionCommandStatus->duration;
        case 11:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_5C == 0) {
                actionCommandStatus->thresholdLevel++;
                if (actionCommandStatus->thresholdLevel >= actionCommandStatus->unk_5A) {
                    actionCommandStatus->thresholdLevel = actionCommandStatus->unk_5A;
                    actionCommandStatus->unk_5C = 1;
                }
            } else {
                actionCommandStatus->thresholdLevel--;
                if (actionCommandStatus->thresholdLevel <= 0) {
                    actionCommandStatus->thresholdLevel = 0;
                    actionCommandStatus->unk_5C = 0;
                }
            }

            if (!actionCommandStatus->berserkerEnabled) {
                s32 inputBufPos = battleStatus->inputBufferPos;
                s32 temp_a2 = actionCommandStatus->duration - actionCommandStatus->frameCounter;
                s32 i;

                actionCommandStatus->barFillLevel = 0;

                inputBufPos -= temp_a2;
                if (inputBufPos < 0) {
                    inputBufPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
                }

                for (i = 0; i < temp_a2; i++, inputBufPos++) {
                    if (inputBufPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        inputBufPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }
                    if (battleStatus->pushInputBuffer[inputBufPos] & BUTTON_A) {
                        actionCommandStatus->barFillLevel += battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty];
                    }
                }
            } else {
                actionCommandStatus->barFillLevel += (battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty]) / 4;
                actionCommandStatus->barFillLevel += rand_int(battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] / 4);
            }

            battleStatus->actionSuccess = actionCommandStatus->barFillLevel / 100;
            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                return;
            }

            if (battleStatus->actionSuccess >= actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals] - actionCommandStatus->thresholdLevel) {
                battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                battleStatus->actionSuccess = 1;
            } else {
                battleStatus->actionResult = ACTION_RESULT_MINUS_2;
                battleStatus->actionSuccess = -1;
            }

            btl_set_popup_duration(0);
            actionCommandStatus->frameCounter = 20;
            actionCommandStatus->state = 12;
            break;
        case 12:
            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                return;
            }
            action_command_free();
            break;
    }
}

void N(draw)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32* hudElements = actionCommandStatus->hudElements;
    s32 hudX;
    s32 hudY;
    s32 id;
    s16 mashMeterCutoff;
    s32 thirtyOne;

    mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
    hudX = 60 - ((mashMeterCutoff - actionCommandStatus->thresholdLevel) * 60 / mashMeterCutoff);

    // Putting 31 into a variable manually fixes regalloc, so perhaps this was a constant defined somewhere?
    thirtyOne = 31;
    hud_element_set_render_pos(hudElements[3], actionCommandStatus->hudPosX - (hudX - thirtyOne),
        actionCommandStatus->hudPosY + 17);
    hud_element_set_render_pos(hudElements[2], actionCommandStatus->hudPosX - (hudX - thirtyOne),
        actionCommandStatus->hudPosY - 1);

    if (!actionCommandStatus->berserkerEnabled) {
        hud_element_draw_clipped(hudElements[0]);
    }

    id = hudElements[1];
    hud_element_draw_clipped(id);
    hud_element_get_render_pos(id, &hudX, &hudY);

    draw_mash_meter_multicolor(hudX, hudY, actionCommandStatus->barFillLevel / 100);
    hud_element_draw_clipped(hudElements[2]);
    hud_element_draw_clipped(hudElements[3]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
}
