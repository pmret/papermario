#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_flee

BSS s32 D_802A9920;

extern s32 actionCmdTableFlee[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 xOffset;
    s32 hudElement;

    battleStatus->unk_82 = 0;
    battleStatus->actionCmdDifficultyTable = actionCmdTableFlee;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    action_command_init_status();
    actionCommandStatus->unk_5A = evt_get_variable(script, *args++);
    actionCommandStatus->actionCommandID = ACTION_COMMAND_FLEE;
    actionCommandStatus->state = 0;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = actionCommandStatus->unk_5A * 100;
    actionCommandStatus->thresholdLevel = rand_int(50);
    actionCommandStatus->barFillWidth = 0;
    actionCommandStatus->unk_5C = 1;
    actionCommandStatus->unk_5A = rand_int(1);
    actionCommandStatus->isBarFilled = FALSE;
    battleStatus->actionSuccess = 0;
    actionCommandStatus->hudPosX = -48;
    D_802A9920 = 0;
    actionCommandStatus->hudPosY = 80;

    hudElement = hud_element_create(&HES_AButton);
    actionCommandStatus->hudElements[0] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hudElement = hud_element_create(&HES_BlueMeter);
    actionCommandStatus->hudElements[1] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hudElement = hud_element_create(&HES_RunningAway);
    actionCommandStatus->hudElements[2] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hudElement = hud_element_create(&HES_RunAwayOK);
    actionCommandStatus->hudElements[3] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    xOffset = 29 - ((100 - actionCommandStatus->thresholdLevel) * 60) / 100;
    hud_element_set_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudPosX - xOffset, actionCommandStatus->hudPosY + 17);
    hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudPosX - xOffset, actionCommandStatus->hudPosY - 1);

    hudElement = hud_element_create(&HES_100pct);
    actionCommandStatus->hudElements[4] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    Bytecode* args = script->ptrReadPos;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    action_command_init_status();
    actionCommandStatus->prepareTime = evt_get_variable(script, *args++);
    actionCommandStatus->duration = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = adjust_action_command_difficulty(actionCommandStatus->difficulty);
    actionCommandStatus->wrongButtonPressed = FALSE;
    battleStatus->actionSuccess = 0;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    battleStatus->unk_82 = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    actionCommandStatus->state = 10;
    return ApiStatus_DONE2;
}

void N(update)(void) {
    s32 temp;
    s32 hudElement;
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    switch (actionCommandStatus->state) {
        case 0:
            hudElement = actionCommandStatus->hudElements[0];
            hud_element_set_alpha(hudElement, 0xFF);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            hudElement = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(hudElement, 0xFF);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            hudElement = actionCommandStatus->hudElements[2];
            hud_element_set_alpha(hudElement, 0xFF);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            hudElement = actionCommandStatus->hudElements[3];
            hud_element_set_alpha(hudElement, 0xFF);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            actionCommandStatus->state = 1;
            break;
        case 1:
            actionCommandStatus->hudPosX += 20;
            if (actionCommandStatus->hudPosX > 50) {
                actionCommandStatus->hudPosX = 50;
            }
            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
            break;
        case 10:
            if (actionCommandStatus->prepareTime != 0) {
                actionCommandStatus->prepareTime--;
                break;
            }

            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_MashAButton);
            D_802A9920 = 1;
            actionCommandStatus->state = 11;
            actionCommandStatus->frameCounter = actionCommandStatus->duration;
        case 11:
            if (battleStatus->actionCommandMode != ACTION_COMMAND_MODE_NOT_LEARNED && (battleStatus->curButtonsPressed & BUTTON_A)) {
                actionCommandStatus->barFillLevel += (battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] * 180 / 100);
            }
            if (actionCommandStatus->barFillLevel >= 10000) {
                hudElement = actionCommandStatus->hudElements[4];
                actionCommandStatus->barFillLevel = 10000;
                actionCommandStatus->isBarFilled = TRUE;
                hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX + 50, actionCommandStatus->hudPosY + 28);
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionSuccess = actionCommandStatus->barFillLevel / 100;
            if (actionCommandStatus->frameCounter == 0) {
                if (battleStatus->actionSuccess >= (100 - actionCommandStatus->thresholdLevel)) {
                    battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                    battleStatus->actionSuccess = 1;
                } else {
                    battleStatus->actionResult = ACTION_RESULT_MINUS_2;
                    battleStatus->actionSuccess = -1;
                }
                actionCommandStatus->frameCounter = 20;
                actionCommandStatus->state = 12;
            } else {
                actionCommandStatus->frameCounter--;
            }
            break;
        case 12:
            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                break;
            }
            action_command_free();
            break;
    }

    switch (actionCommandStatus->state) {
        case 1:
        case 10:
        case 11:
            temp = actionCommandStatus->unk_5A == 0 ? 7 : 8;
            if (actionCommandStatus->unk_5C == 0) {
                actionCommandStatus->thresholdLevel += temp;
                if (actionCommandStatus->thresholdLevel >= 100) {
                    actionCommandStatus->thresholdLevel = 100;
                    actionCommandStatus->unk_5C = 1;
                }
                break;
            }
            actionCommandStatus->thresholdLevel -= temp;
            if (actionCommandStatus->thresholdLevel <= 0) {
                actionCommandStatus->thresholdLevel = 0;
                actionCommandStatus->unk_5C = 0;
            }
    }
}

void N(draw)(void) {
    s32 y;
    s32 x;
    s32 temp_a1;
    s32 hudElement;
    s32 temp_v1;

    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    temp_v1 = (100 - actionCommandStatus->thresholdLevel) * 60;
    x = 60 - temp_v1 / 100;
    temp_a1 = x - 31;

    hud_element_set_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudPosX - temp_a1, actionCommandStatus->hudPosY + 17);
    hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudPosX + 31 - x, actionCommandStatus->hudPosY - 1);

    if (battleStatus->actionCommandMode != ACTION_COMMAND_MODE_NOT_LEARNED) {
        hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    }

    hudElement = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(hudElement);
    hud_element_get_render_pos(hudElement, &x, &y);

    if (D_802A9920 == 0) {
        draw_mash_meter_multicolor_with_divisor(x, y, actionCommandStatus->barFillLevel / 100, 1);
    } else {
        if (!actionCommandStatus->isBarFilled) {
            draw_mash_meter_multicolor_with_divisor(x, y, actionCommandStatus->barFillLevel / 100, 4);
        } else {
            draw_mash_meter_blink(x, y, actionCommandStatus->barFillLevel / 100);
        }
    }

    hud_element_draw_clipped(actionCommandStatus->hudElements[2]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[3]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[4]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
}
