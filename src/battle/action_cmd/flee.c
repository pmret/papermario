#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_flee

BSS b32 FleeCommandStarted;

extern s32 actionCmdTableFlee[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 xOffset;
    s32 hudElement;

    battleStatus->unk_82 = 0;
    battleStatus->actionCmdDifficultyTable = actionCmdTableFlee;
    battleStatus->actionResult = ACTION_RESULT_NONE;

    action_command_init_status();

    acs->effectiveness = evt_get_variable(script, *args++);

    acs->actionCommandID = ACTION_COMMAND_FLEE;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = acs->effectiveness * 100;
    acs->thresholdLevel = rand_int(50);
    acs->barFillWidth = 0;
    acs->flee.dir = 1;
    acs->effectiveness = rand_int(1);
    acs->isBarFilled = FALSE;
    battleStatus->actionSuccess = 0;
    FleeCommandStarted = FALSE;
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    hudElement = hud_element_create(&HES_AButton);
    acs->hudElements[0] = hudElement;
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hudElement = hud_element_create(&HES_BlueMeter);
    acs->hudElements[1] = hudElement;
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hudElement = hud_element_create(&HES_RunningAway);
    acs->hudElements[2] = hudElement;
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hudElement = hud_element_create(&HES_RunAwayOK);
    acs->hudElements[3] = hudElement;
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    xOffset = 29 - ((100 - acs->thresholdLevel) * 60) / 100;
    hud_element_set_render_pos(acs->hudElements[3], acs->hudPosX - xOffset, acs->hudPosY + 17);
    hud_element_set_render_pos(acs->hudElements[2], acs->hudPosX - xOffset, acs->hudPosY - 1);

    hudElement = hud_element_create(&HES_100pct);
    acs->hudElements[4] = hudElement;
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    Bytecode* args = script->ptrReadPos;
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    action_command_init_status();
    acs->prepareTime = evt_get_variable(script, *args++);
    acs->duration = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);
    acs->wrongButtonPressed = FALSE;
    battleStatus->actionSuccess = 0;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    battleStatus->unk_82 = acs->mashMeterCutoffs[acs->mashMeterNumIntervals - 1];
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    acs->state = AC_STATE_START;
    return ApiStatus_DONE2;
}

void N(update)(void) {
    s32 temp;
    s32 hudElement;
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* acs = &gActionCommandStatus;

    switch (acs->state) {
        case AC_STATE_INIT:
            hudElement = acs->hudElements[0];
            hud_element_set_alpha(hudElement, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            hudElement = acs->hudElements[1];
            hud_element_set_alpha(hudElement, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            hudElement = acs->hudElements[2];
            hud_element_set_alpha(hudElement, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            hudElement = acs->hudElements[3];
            hud_element_set_alpha(hudElement, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            acs->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }
            hud_element_set_render_pos(acs->hudElements[0], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[1], acs->hudPosX, acs->hudPosY + 28);
            break;
        case AC_STATE_START:
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                break;
            }

            hud_element_set_script(acs->hudElements[0], &HES_MashAButton);
            FleeCommandStarted = TRUE;
            acs->state = AC_STATE_ACTIVE;
            acs->frameCounter = acs->duration;
            // fallthrough
        case AC_STATE_ACTIVE:
            if (battleStatus->actionCommandMode != AC_MODE_NOT_LEARNED && (battleStatus->curButtonsPressed & BUTTON_A)) {
                acs->barFillLevel += (battleStatus->actionCmdDifficultyTable[acs->difficulty] * 180 / 100);
            }
            if (acs->barFillLevel >= 10000) {
                hudElement = acs->hudElements[4];
                acs->barFillLevel = 10000;
                acs->isBarFilled = TRUE;
                hud_element_set_render_pos(hudElement, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionSuccess = acs->barFillLevel / 100;
            if (acs->frameCounter == 0) {
                if (battleStatus->actionSuccess >= (100 - acs->thresholdLevel)) {
                    battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                    battleStatus->actionSuccess = 1;
                } else {
                    battleStatus->actionResult = ACTION_RESULT_MINUS_2;
                    battleStatus->actionSuccess = -1;
                }
                acs->frameCounter = 20;
                acs->state = AC_STATE_DISPOSE;
            } else {
                acs->frameCounter--;
            }
            break;
        case AC_STATE_DISPOSE:
            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                break;
            }
            action_command_free();
            break;
    }

    switch (acs->state) {
        case AC_STATE_APPEAR:
        case AC_STATE_START:
        case AC_STATE_ACTIVE:
            temp = acs->effectiveness == 0 ? 7 : 8;
            if (acs->flee.dir == 0) {
                acs->thresholdLevel += temp;
                if (acs->thresholdLevel >= 100) {
                    acs->thresholdLevel = 100;
                    acs->flee.dir = 1;
                }
                break;
            }
            acs->thresholdLevel -= temp;
            if (acs->thresholdLevel <= 0) {
                acs->thresholdLevel = 0;
                acs->flee.dir = 0;
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
    ActionCommandStatus* acs = &gActionCommandStatus;

    temp_v1 = (100 - acs->thresholdLevel) * 60;
    x = 60 - temp_v1 / 100;
    temp_a1 = x - 31;

    hud_element_set_render_pos(acs->hudElements[3], acs->hudPosX - temp_a1, acs->hudPosY + 17);
    hud_element_set_render_pos(acs->hudElements[2], acs->hudPosX + 31 - x, acs->hudPosY - 1);

    if (battleStatus->actionCommandMode != AC_MODE_NOT_LEARNED) {
        hud_element_draw_clipped(acs->hudElements[0]);
    }

    hudElement = acs->hudElements[1];
    hud_element_draw_clipped(hudElement);
    hud_element_get_render_pos(hudElement, &x, &y);

    if (!FleeCommandStarted) {
        draw_mash_meter_multicolor_with_divisor(x, y, acs->barFillLevel / 100, 1);
    } else {
        if (!acs->isBarFilled) {
            draw_mash_meter_multicolor_with_divisor(x, y, acs->barFillLevel / 100, 4);
        } else {
            draw_mash_meter_blink(x, y, acs->barFillLevel / 100);
        }
    }

    hud_element_draw_clipped(acs->hudElements[2]);
    hud_element_draw_clipped(acs->hudElements[3]);
    hud_element_draw_clipped(acs->hudElements[4]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
}
