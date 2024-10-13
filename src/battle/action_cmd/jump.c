#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_jump

extern s32 actionCmdTableJump[];

API_CALLABLE(N(init)) {
    s32 hudElement;
    ActionCommandStatus* acs = &gActionCommandStatus;

    gBattleStatus.unk_82 = 1;
    gBattleStatus.actionCmdDifficultyTable = actionCmdTableJump;
    gBattleStatus.actionResult = ACTION_RESULT_FAIL;

    if (gBattleStatus.actionCommandMode == AC_MODE_NOT_LEARNED) {
        gBattleStatus.actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    acs->actionCommandID = ACTION_COMMAND_JUMP;
    acs->hudPosX = -48;
    acs->state = 0;
    acs->wrongButtonPressed = FALSE;
    acs->hudPosY = 80;

    hudElement = hud_element_create(&HES_AButton);
    acs->hudElements[0] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_alpha(hudElement, 255);

    hudElement = hud_element_create(&HES_RightOn);
    acs->hudElements[1] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_alpha(hudElement, 255);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    s32 hudElement;

    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    } else {
        action_command_init_status();
        acs->prepareTime = evt_get_variable(script, *args++);
        acs->difficulty = evt_get_variable(script, *args++);
        acs->difficulty = adjust_action_command_difficulty(acs->difficulty);
        acs->wrongButtonPressed = FALSE;
        battleStatus->actionSuccess = 0;

        hudElement = acs->hudElements[0];
        acs->hudPosX = 50;
        battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
        battleStatus->flags1 &= ~BS_FLAGS1_2000;
        hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY);
        if (acs->showHud) {
            hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
        }

        acs->state = AC_STATE_START;
        increment_action_command_attempt_count();
        btl_set_popup_duration(10);
        return ApiStatus_DONE2;
    }
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;
    s32 successWindow;

    switch (acs->state) {
        case AC_STATE_INIT:
            if (battleStatus->actionCommandMode == AC_MODE_TUTORIAL) {
                btl_set_popup_duration(POPUP_MSG_ON);
            }
            acs->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            if (battleStatus->actionCommandMode == AC_MODE_TUTORIAL) {
                btl_set_popup_duration(POPUP_MSG_ON);
            }

            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }

            hudElement = acs->hudElements[0];
            hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY);
            if (acs->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            if (acs->autoSucceed) {
                hudElement = acs->hudElements[1];
                hud_element_set_render_pos(hudElement, acs->hudPosX + 50, acs->hudPosY);
                if (acs->showHud) {
                    hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
                    break;
                }
            }
            break;
        case AC_STATE_START:
            if (battleStatus->actionCommandMode == AC_MODE_TUTORIAL) {
                btl_set_popup_duration(POPUP_MSG_ON);
            }

            successWindow = battleStatus->actionCmdDifficultyTable[acs->difficulty];
            if (((acs->prepareTime - successWindow) - 2) <= 0) {
                hud_element_set_script(acs->hudElements[0], &HES_AButtonDown);
            }
            if ((battleStatus->curButtonsPressed & BUTTON_A) && !acs->autoSucceed) {
                acs->wrongButtonPressed = TRUE;
                battleStatus->actionResult = ACTION_RESULT_EARLY;
            }
            if ((acs->prepareTime - successWindow) > 0) {
                acs->prepareTime -= 1;
                break;
            }

            acs->frameCounter = battleStatus->actionCmdDifficultyTable[acs->difficulty];
            battleStatus->actionSuccess = -1;
            acs->state = AC_STATE_ACTIVE;
            // fall through
        case AC_STATE_ACTIVE:
            if (battleStatus->actionCommandMode == AC_MODE_TUTORIAL) {
                btl_set_popup_duration(POPUP_MSG_ON);
            }
            if (battleStatus->actionCommandMode >= AC_MODE_TUTORIAL) {
                if (acs->frameCounter == 0) {
                    break;
                }
            } else {
                if (battleStatus->actionSuccess >= 0) {
                    hudElement = acs->hudElements[0];
                    if (acs->showHud) {
                        hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
                    }
                }
            }

            if (battleStatus->actionSuccess < 0) {
                if (((battleStatus->curButtonsPressed & BUTTON_A) &&
                    !acs->wrongButtonPressed) ||
                    acs->autoSucceed) {
                    battleStatus->actionSuccess = 1;
                    battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                    gBattleStatus.flags1 |= BS_FLAGS1_2000;
                }
            }

            if (acs->frameCounter == 0) {
                if (battleStatus->actionSuccess == 1) {
                    increment_action_command_success_count();
                }
                if (battleStatus->actionCommandMode == AC_MODE_TUTORIAL) {
                    btl_set_popup_duration(POPUP_MSG_OFF);
                }
                acs->frameCounter = 5;
                acs->state = AC_STATE_DISPOSE;
                break;
            }
            acs->frameCounter--;
            break;
        case AC_STATE_DISPOSE:
            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                break;
            }
            action_command_free();
            break;
    }
}

void N(draw)(void) {
    hud_element_draw_clipped(gActionCommandStatus.hudElements[0]);
    if (!(gGameStatusPtr->demoBattleFlags & DEMO_BTL_FLAG_ENABLED)) {
        hud_element_draw_clipped(gActionCommandStatus.hudElements[1]);
    }
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
}
