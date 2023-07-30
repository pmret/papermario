#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_squirt

s32 D_802A9760_42A480[] = { 300, 300, 265, 220, 175, 175 };
s32 D_802A9778_42A498[] = { 300, 300, 265, 220, 175, 175 };

extern s32 actionCmdTableSquirt[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    battleStatus->unk_82 = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTableSquirt;
    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_SQUIRT;
    actionCommandStatus->state = 0;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    battleStatus->actionResult = 0;
    actionCommandStatus->hudPosX = -48;
    actionCommandStatus->unk_5C = 0;
    actionCommandStatus->hudPosY = 80;

    id = hud_element_create(&HES_AButton);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_BlueMeter);
    actionCommandStatus->hudElements[1] = id;
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
    actionCommandStatus->difficulty = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = adjust_action_command_difficulty(actionCommandStatus->difficulty);
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 0;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~BS_FLAGS1_8000;
    func_80269118();
    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
    s32 mashMeterCutoff;
    s32 cutoff;
    s32 temp;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);

            id = actionCommandStatus->hudElements[0];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);

            actionCommandStatus->hudPosX += 20;
            if (actionCommandStatus->hudPosX > 50) {
                actionCommandStatus->hudPosX = 50;
            }

            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudPosX,
                actionCommandStatus->hudPosY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudPosX,
                actionCommandStatus->hudPosY + 28);
            break;
        case 10:
            btl_set_popup_duration(99);

            if (actionCommandStatus->prepareTime != 0) {
                actionCommandStatus->prepareTime--;
                break;
            }

            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_AButtonDown);
            actionCommandStatus->barFillLevel = 0;
            actionCommandStatus->unk_5C = 0;
            actionCommandStatus->frameCounter = actionCommandStatus->duration;
            sfx_play_sound_with_params(SOUND_80000041, 0, 0, 0);
            actionCommandStatus->state = 11;
            // fallthrough
        case 11:
            btl_set_popup_duration(99);
            cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
            temp = actionCommandStatus->barFillLevel / cutoff;
            if (actionCommandStatus->unk_5C == 0) {
                if (!(battleStatus->curButtonsDown & BUTTON_A)) {
                    actionCommandStatus->barFillLevel -= D_802A9760_42A480[temp / 20];
                    if (actionCommandStatus->barFillLevel < 0) {
                        actionCommandStatus->barFillLevel = 0;
                    }
                } else {
                    actionCommandStatus->barFillLevel += D_802A9778_42A498[temp / 20] * battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] / 100;
                    if (actionCommandStatus->barFillLevel > 10000) {
                        actionCommandStatus->barFillLevel = 10000;
                        actionCommandStatus->unk_5C = 1;
                    }
                }
            } else {
                actionCommandStatus->barFillLevel -= 250;
                if (actionCommandStatus->barFillLevel <= 0) {
                    actionCommandStatus->barFillLevel = 0;
                    actionCommandStatus->unk_5C = 0;
                }
            }

            battleStatus->actionResult = actionCommandStatus->barFillLevel / 100;
            sfx_adjust_env_sound_params(SOUND_80000041, 0, 0, battleStatus->actionResult * 12);
            id = actionCommandStatus->hudElements[0];
            if (temp < 80) {
                if (hud_element_get_script(id) != &HES_AButtonDown) {
                    hud_element_set_script(id, &HES_AButtonDown);
                }
            } else {
                if (hud_element_get_script(id) != &HES_PressAButton) {
                    hud_element_set_script(id, &HES_PressAButton);
                }
            }

            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                return;
            }

            if (actionCommandStatus->barFillLevel == 0) {
                battleStatus->actionSuccess = -1;
            } else {
                battleStatus->actionSuccess = battleStatus->actionResult;
            }

            cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
            if (cutoff / 2 < battleStatus->actionResult) {
                battleStatus->unk_86 = 1;
            } else {
                battleStatus->unk_86 = -4;
            }

            if (battleStatus->actionSuccess == 100) {
                func_80269160();
            }
            btl_set_popup_duration(0);
            sfx_stop_sound(SOUND_80000041);
            actionCommandStatus->frameCounter = 5;
            actionCommandStatus->state = 12;
            break;
        case 12:
            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
            } else {
                action_command_free();
            }
            break;
    }
}

void N(draw)(void) {
    s32 x, y;
    s32 id;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    id = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(id);
    hud_element_get_render_pos(id, &x, &y);
    if (actionCommandStatus->unk_5C == 0) {
        draw_mash_meter_multicolor_with_divisor(x, y, actionCommandStatus->barFillLevel / 100, 1);
    } else {
        draw_mash_meter_mode_with_divisor(x, y, actionCommandStatus->barFillLevel / 100, 1, MASH_METER_MODE_ONE_COLOR);
    }
}

void N(free)(void) {
    sfx_stop_sound(SOUND_80000041);
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
}
