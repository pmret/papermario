#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_jump

extern s32 actionCmdTableJump[];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_BUTTON         = 0,
    HIDX_RIGHT_ON       = 1,
};

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    HudElemID hid;

    gBattleStatus.maxActionQuality = 1;
    gBattleStatus.actionCmdDifficultyTable = actionCmdTableJump;
    gBattleStatus.actionResult = ACTION_RESULT_FAIL;

    if (gBattleStatus.actionCommandMode == AC_MODE_NOT_LEARNED) {
        gBattleStatus.actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    acs->actionCommandID = ACTION_COMMAND_JUMP;
    acs->hudPosX = -48;
    acs->state = 0;
    acs->wrongButtonPressed = false;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_AButton);
    acs->hudElemIDs[HIDX_BUTTON] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_alpha(hid, 255);

    hid = hud_element_create(&HES_RightOn);
    acs->hudElemIDs[HIDX_RIGHT_ON] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_MANUAL_RENDER | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_alpha(hid, 255);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    HudElemID hid;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    acs->prepareTime = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);
    acs->wrongButtonPressed = false;
    battleStatus->actionQuality = 0;

    hid = acs->hudElemIDs[HIDX_BUTTON];
    acs->hudPosX = 50;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    battleStatus->flags1 &= ~BS_FLAGS1_2000;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    if (acs->showHud) {
        hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
    }

    acs->state = AC_STATE_START;
    increment_action_command_attempt_count();
    btl_set_popup_duration(10);

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElemID hid;
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

            hid = acs->hudElemIDs[HIDX_BUTTON];
            hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            if (acs->autoSucceed) {
                hid = acs->hudElemIDs[HIDX_RIGHT_ON];
                hud_element_set_render_pos(hid, acs->hudPosX + 50, acs->hudPosY);
                if (acs->showHud) {
                    hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
                }
            }
            break;
        case AC_STATE_START:
            // this state is the time before valid input is allowed

            if (battleStatus->actionCommandMode == AC_MODE_TUTORIAL) {
                btl_set_popup_duration(POPUP_MSG_ON);
            }

            // show the A button being pressed two frames before input is allowed
            successWindow = battleStatus->actionCmdDifficultyTable[acs->difficulty];
            if (((acs->prepareTime - successWindow) - 2) <= 0) {
                hud_element_set_script(acs->hudElemIDs[HIDX_BUTTON], &HES_AButtonDown);
            }
            // inputs during this state will cause the action to fail
            if ((battleStatus->curButtonsPressed & BUTTON_A) && !acs->autoSucceed) {
                acs->wrongButtonPressed = true;
                battleStatus->actionResult = ACTION_RESULT_EARLY;
            }
            // continue until we begin the window for valid input
            if ((acs->prepareTime - successWindow) > 0) {
                acs->prepareTime--;
                break;
            }

            acs->stateTimer = battleStatus->actionCmdDifficultyTable[acs->difficulty];
            battleStatus->actionQuality = AC_QUALITY_FAILED;
            acs->state = AC_STATE_ACTIVE;

            // fallthrough
        case AC_STATE_ACTIVE:
            if (battleStatus->actionCommandMode == AC_MODE_TUTORIAL) {
                btl_set_popup_duration(POPUP_MSG_ON);
            }
            if (battleStatus->actionCommandMode >= AC_MODE_TUTORIAL) {
                if (acs->stateTimer == 0) {
                    break;
                }
            } else {
                if (battleStatus->actionQuality >= 0) {
                    hid = acs->hudElemIDs[HIDX_BUTTON];
                    if (acs->showHud) {
                        hud_element_set_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
                    }
                }
            }

            // valid input is allowed during this state
            if (battleStatus->actionQuality < 0) {
                if (((battleStatus->curButtonsPressed & BUTTON_A) && !acs->wrongButtonPressed) || acs->autoSucceed) {
                    battleStatus->actionQuality = 1;
                    battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                    gBattleStatus.flags1 |= BS_FLAGS1_2000;
                }
            }

            if (acs->stateTimer == 0) {
                if (battleStatus->actionQuality == 1) {
                    increment_action_command_success_count();
                }
                if (battleStatus->actionCommandMode == AC_MODE_TUTORIAL) {
                    btl_set_popup_duration(POPUP_MSG_OFF);
                }
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
            action_command_free();
            break;
    }
}

void N(draw)(void) {
    hud_element_draw_clipped(gActionCommandStatus.hudElemIDs[HIDX_BUTTON]);
    if (!(gGameStatusPtr->demoBattleFlags & DEMO_BTL_FLAG_ENABLED)) {
        hud_element_draw_clipped(gActionCommandStatus.hudElemIDs[HIDX_RIGHT_ON]);
    }
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_BUTTON]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_RIGHT_ON]);
}
