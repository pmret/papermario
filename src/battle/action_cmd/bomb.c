#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_bomb

s32 D_802A9810_428280[] = { 0, 25, 50, 75, 75, 0, 0, 0 };

extern s32 actionCmdTableBomb[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTableBomb;
    battleStatus->unk_86 = 127;

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_BOMB;
    actionCommandStatus->showHud = TRUE;
    actionCommandStatus->state = 0;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    actionCommandStatus->isBarFilled = FALSE;
    battleStatus->actionSuccess = 0;

    actionCommandStatus->hudPosX = -48;
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

    hudElement = hud_element_create(&HES_100pct);
    actionCommandStatus->hudElements[2] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    return ApiStatus_DONE2;
}

#include "common/MashActionCommandStart.inc.c"

void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;
    s32 mashMeterCutoff;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);
            hudElement = actionCommandStatus->hudElements[0];
            hud_element_set_alpha(hudElement, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            hudElement = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(hudElement, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
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

            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_MashAButton);
            actionCommandStatus->barFillLevel = 0;
            actionCommandStatus->frameCounter = actionCommandStatus->duration;
            sfx_play_sound_with_params(SOUND_80000041, 0, 0, 0);
            actionCommandStatus->state = 11;

            // fallthrough
        case 11:
            btl_set_popup_duration(99);
            if (!actionCommandStatus->isBarFilled) {
                mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
                actionCommandStatus->barFillLevel -=
                    D_802A9810_428280[actionCommandStatus->barFillLevel / mashMeterCutoff / 20];

                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
                }
            }

            if (battleStatus->curButtonsPressed & BUTTON_A) {
                switch (actionCommandStatus->targetWeakness) {
                    case 0: {
                        s32 fillOffset = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] * 235 * 4;
                        actionCommandStatus->barFillLevel += fillOffset / 100;
                        break;
                    }
                    case 1:
                        actionCommandStatus->barFillLevel += battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] * 8;
                        break;
                    case 2: {
                        s32 fillOffset = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] * 185 * 4;
                        actionCommandStatus->barFillLevel += fillOffset / 100;
                        break;
                    }
                }
            }

            if (actionCommandStatus->barFillLevel > 10000) {
                hudElement = actionCommandStatus->hudElements[2];
                actionCommandStatus->barFillLevel = 10000;
                actionCommandStatus->isBarFilled = TRUE;
                hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX + 50,
                    actionCommandStatus->hudPosY + 28);
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionResult = actionCommandStatus->barFillLevel / 100;
            sfx_adjust_env_sound_params(SOUND_80000041, 0, 0, battleStatus->actionResult * 12);

            if (actionCommandStatus->frameCounter == 0) {
                if (actionCommandStatus->barFillLevel == 0) {
                    battleStatus->actionSuccess = -1;
                } else {
                    battleStatus->actionSuccess = actionCommandStatus->barFillLevel / 100;
                }

                mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
                if (mashMeterCutoff >= battleStatus->actionSuccess) {
                    battleStatus->unk_86 = -2;
                } else {
                    battleStatus->unk_86 = 1;
                }

                if (battleStatus->actionSuccess == 100) {
                    func_80269160();
                }

                sfx_stop_sound(SOUND_80000041);
                btl_set_popup_duration(0);
                actionCommandStatus->frameCounter = 5;
                actionCommandStatus->state = 12;
            } else {
                actionCommandStatus->frameCounter--;
            }
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

#include "common/draw_hud_elements.inc.c"

#include "common/free_hud_elements.inc.c"
