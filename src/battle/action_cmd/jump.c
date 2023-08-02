#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_jump

extern s32 actionCmdTableJump[];

API_CALLABLE(N(init)) {
    s32 hudElement;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    gBattleStatus.unk_82 = 1;
    gBattleStatus.actionCmdDifficultyTable = actionCmdTableJump;
    gBattleStatus.unk_86 = 0;

    if (gBattleStatus.actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        gBattleStatus.actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_JUMP;
    actionCommandStatus->hudPosX = -48;
    actionCommandStatus->state = 0;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->hudPosY = 80;

    hudElement = hud_element_create(&HES_AButton);
    actionCommandStatus->hudElements[0] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_alpha(hudElement, 255);

    hudElement = hud_element_create(&HES_RightOn);
    actionCommandStatus->hudElements[1] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_alpha(hudElement, 255);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    s32 hudElement;

    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    } else {
        action_command_init_status();
        actionCommandStatus->prepareTime = evt_get_variable(script, *args++);
        actionCommandStatus->difficulty = evt_get_variable(script, *args++);
        actionCommandStatus->difficulty = adjust_action_command_difficulty(actionCommandStatus->difficulty);
        actionCommandStatus->wrongButtonPressed = FALSE;
        battleStatus->actionSuccess = 0;

        hudElement = actionCommandStatus->hudElements[0];
        actionCommandStatus->hudPosX = 50;
        battleStatus->flags1 &= ~BS_FLAGS1_8000;
        battleStatus->flags1 &= ~BS_FLAGS1_2000;
        hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
        if (actionCommandStatus->showHud) {
            hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
        }

        actionCommandStatus->state = 10;
        func_80269118();
        btl_set_popup_duration(10);
        return ApiStatus_DONE2;
    }
}

void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;
    s32 temp_s0_3;

    switch (actionCommandStatus->state) {
        case 0:
            if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_TUTORIAL) {
                btl_set_popup_duration(99);
            }
            actionCommandStatus->state = 1;
            break;
        case 1:
            if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_TUTORIAL) {
                btl_set_popup_duration(99);
            }

            actionCommandStatus->hudPosX += 20;
            if (actionCommandStatus->hudPosX > 50) {
                actionCommandStatus->hudPosX = 50;
            }

            hudElement = actionCommandStatus->hudElements[0];
            hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            if (actionCommandStatus->autoSucceed) {
                hudElement = actionCommandStatus->hudElements[1];
                hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX + 50, actionCommandStatus->hudPosY);
                if (actionCommandStatus->showHud) {
                    hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
                    break;
                }
            }
            break;
        case 10:
            if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_TUTORIAL) {
                btl_set_popup_duration(99);
            }

            temp_s0_3 = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty];
            if (((actionCommandStatus->prepareTime - temp_s0_3) - 2) <= 0) {
                hud_element_set_script(actionCommandStatus->hudElements[0], &HES_AButtonDown);
            }
            if ((battleStatus->curButtonsPressed & BUTTON_A) && (actionCommandStatus->autoSucceed == 0)) {
                actionCommandStatus->wrongButtonPressed = TRUE;
                battleStatus->unk_86 = -1;
            }
            if ((actionCommandStatus->prepareTime - temp_s0_3) > 0) {
                actionCommandStatus->prepareTime -= 1;
                break;
            }

            actionCommandStatus->frameCounter = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty];
            battleStatus->actionSuccess = -1;
            actionCommandStatus->state = 11;
        case 11:
            if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_TUTORIAL) {
                btl_set_popup_duration(99);
            }
            if (battleStatus->actionCommandMode >= ACTION_COMMAND_MODE_TUTORIAL) {
                if (actionCommandStatus->frameCounter == 0) {
                    break;
                }
            } else {
                if (battleStatus->actionSuccess >= 0) {
                    hudElement = actionCommandStatus->hudElements[0];
                    if (actionCommandStatus->showHud) {
                        hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
                    }
                }
            }

            if (battleStatus->actionSuccess < 0) {
                if (((battleStatus->curButtonsPressed & BUTTON_A)&&
                    !actionCommandStatus->wrongButtonPressed) ||
                    (actionCommandStatus->autoSucceed != 0)) {
                    battleStatus->actionSuccess = 1;
                    battleStatus->unk_86 = 1;
                    gBattleStatus.flags1 |= BS_FLAGS1_2000;
                }
            }

            if (actionCommandStatus->frameCounter == 0) {
                if (battleStatus->actionSuccess == 1) {
                    func_80269160();
                }
                if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_TUTORIAL) {
                    btl_set_popup_duration(0);
                }
                actionCommandStatus->frameCounter = 5;
                actionCommandStatus->state = 12;
                break;
            }
            actionCommandStatus->frameCounter -= 1;
            break;
        case 12:
            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter -= 1;
                break;
            }
            action_command_free();
            break;
    }
}

void N(draw)(void) {
    hud_element_draw_clipped(gActionCommandStatus.hudElements[0]);
    if (!(gGameStatusPtr->demoFlags & 1)) {
        hud_element_draw_clipped(gActionCommandStatus.hudElements[1]);
    }
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
}
