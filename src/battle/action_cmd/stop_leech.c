#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_stop_leech

extern s32 actionCmdTableStopLeech[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTableStopLeech;
    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    acs->actionCommandID = ACTION_COMMAND_STOP_LEECH;
    acs->hudPosX = -48;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    acs->hudPosY = 80;

    hudElement = hud_element_create(&HES_AButton);
    acs->hudElements[0] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hudElement, 0);

    hudElement = hud_element_create(&HES_BlueMeter);
    acs->hudElements[1] = hudElement;
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    Bytecode* args = script->ptrReadPos;
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

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

    return ApiStatus_DONE2;
}

void N(update)(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hudElement;
    s16 hudElementX;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);
            hudElement = acs->hudElements[0];
            if (acs->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hudElement, 255);
            hudElement = acs->hudElements[1];
            hud_element_set_alpha(hudElement, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }
            acs->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            btl_set_popup_duration(POPUP_MSG_ON);
            hudElementX = acs->hudPosX + 20;
            acs->hudPosX = hudElementX;
            if (hudElementX > 50) {
                acs->hudPosX = 50;
            }
            hud_element_set_render_pos(acs->hudElements[0], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[1], acs->hudPosX, acs->hudPosY + 28);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime -= 1;
                break;
            }
            hud_element_set_script(acs->hudElements[0], &HES_MashAButton);
            acs->barFillLevel = 0;
            acs->state = AC_STATE_ACTIVE;
            acs->frameCounter = acs->duration;
            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (!acs->berserkerEnabled) {
                if (battleStatus->curButtonsPressed & BUTTON_A) {
                    acs->barFillLevel += battleStatus->actionCmdDifficultyTable[acs->difficulty];
                }
            } else {
                acs->barFillLevel += battleStatus->actionCmdDifficultyTable[acs->difficulty] / 6;
                acs->barFillLevel += rand_int((battleStatus->actionCmdDifficultyTable[acs->difficulty]) / 6);
            }
            battleStatus->actionQuality = acs->barFillLevel / 100;
            if (acs->mashMeterCutoffs[acs->mashMeterNumIntervals] <= battleStatus->actionQuality) {
                acs->frameCounter = 0;
            }

            if (acs->frameCounter == 0) {
                btl_set_popup_duration(POPUP_MSG_OFF);
                acs->frameCounter = 5;
                acs->state = AC_STATE_DISPOSE;
                break;
            }
            acs->frameCounter -= 1;
            break;
        case AC_STATE_DISPOSE:
            if (acs->frameCounter != 0) {
                acs->frameCounter -= 1;
                break;
            }
            battleStatus->actionSuccess = 1;
            battleStatus->actionResult = ACTION_RESULT_NONE;
            action_command_free();
        default:
            break;
    }
}

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 x, y;
    s32 hudElement;

    if (!acs->berserkerEnabled) {
        hud_element_draw_clipped(acs->hudElements[0]);
    }

    hudElement = acs->hudElements[1];
    hud_element_draw_clipped(hudElement);
    hud_element_get_render_pos(hudElement, &x, &y);
    draw_mash_meter_multicolor_with_divisor(x, y, acs->barFillLevel / 100, 2);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
}
