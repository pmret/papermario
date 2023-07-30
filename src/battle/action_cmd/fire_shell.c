#include "battle/battle.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_fire_shell

s32 D_802A9950_427320[5] = { 0, 25, 50, 75, 75 };
s32 D_802A9964_427334[4] = { 40, 70, 99, 200 };
s32 D_802A9974_427344[5] = { 35, 60, 80, 99, 200 };
s32 D_802A9988_427358[6] = { 35, 35, 60, 80, 99, 200 };

extern s32 actionCmdTableFireShell[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    battleStatus->unk_82 = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTableFireShell;
    battleStatus->unk_86 = 127;

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }
    action_command_init_status();

    actionCommandStatus->actionCommandID = ACTION_COMMAND_FIRE_SHELL;
    actionCommandStatus->showHud = TRUE;
    actionCommandStatus->hudPrepareTime = 30;
    actionCommandStatus->state = 0;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    actionCommandStatus->isBarFilled = FALSE;
    battleStatus->actionSuccess = 0;
    actionCommandStatus->hudPosX = -48;
    actionCommandStatus->hudPosY = 80;

    id = hud_element_create(&HES_StickNeutral);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_BlueMeter);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_100pct);
    actionCommandStatus->hudElements[2] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    return ApiStatus_DONE2;
}

#include "common/MashActionCommandStart.inc.c"

void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s32 id;
    s32 cutoff;
    s32 fillLevel;

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
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->prepareTime != 0) {
                actionCommandStatus->prepareTime--;
                return;
            }
            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_StickMashLeft);
            actionCommandStatus->barFillLevel = 0;
            battleStatus->unk_85 = 0;
            actionCommandStatus->unk_5C = 0;
            actionCommandStatus->frameCounter = actionCommandStatus->duration;
            sfx_play_sound_with_params(SOUND_80000041, 0, 0, 0);
            actionCommandStatus->state = 11;
        case 11:
            btl_set_popup_duration(99);

            if (!actionCommandStatus->isBarFilled) {
                cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
                actionCommandStatus->barFillLevel -= D_802A9950_427320[actionCommandStatus->barFillLevel / cutoff / 20];
                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
                }
                if (!actionCommandStatus->isBarFilled) {
                    if (battleStatus->curButtonsDown & BUTTON_STICK_LEFT) {
                        actionCommandStatus->unk_5C = 1;
                    }

                    if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT) && (actionCommandStatus->unk_5C != 0)) {
                        actionCommandStatus->barFillLevel += (battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] * 950) / 100;
                        actionCommandStatus->unk_5C = 0;
                    }

                    if (battleStatus->curButtonsPressed & BUTTON_STICK_RIGHT) {
                        actionCommandStatus->barFillLevel -= (battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] * 950) / 100;
                    }
                }
            }

            if (actionCommandStatus->barFillLevel < 0) {
                actionCommandStatus->barFillLevel = 0;
            }

            if (actionCommandStatus->barFillLevel > 10000) {
                id = actionCommandStatus->hudElements[2];
                actionCommandStatus->barFillLevel = 10000;
                actionCommandStatus->isBarFilled = TRUE;
                hud_element_set_render_pos(id, actionCommandStatus->hudPosX + 50, actionCommandStatus->hudPosY + 28);
                hud_element_clear_flags(id, 2);
            }

            battleStatus->actionResult = actionCommandStatus->barFillLevel / 100;
            sfx_adjust_env_sound_params(SOUND_80000041, 0, 0, battleStatus->actionResult * 12);
            switch (partner->actorBlueprint->level) {
                case 0:
                    if (battleStatus->actionResult >= D_802A9964_427334[battleStatus->unk_85]) {
                        battleStatus->unk_85++;
                    }
                    if (battleStatus->unk_85 > 0 && (battleStatus->actionResult < D_802A9964_427334[battleStatus->unk_85 - 1])) {
                        battleStatus->unk_85--;
                    }
                    break;
                case 1:
                    if (battleStatus->actionResult >= D_802A9974_427344[battleStatus->unk_85]) {
                        battleStatus->unk_85++;
                    }
                    if (battleStatus->unk_85 > 0 && (battleStatus->actionResult < D_802A9974_427344[battleStatus->unk_85 - 1])) {
                        battleStatus->unk_85--;
                    }
                    break;
                case 2:
                    if (battleStatus->actionResult >= D_802A9988_427358[battleStatus->unk_85]) {
                        battleStatus->unk_85++;
                    }
                    if (battleStatus->unk_85 > 0 && (battleStatus->actionResult < D_802A9988_427358[battleStatus->unk_85 - 1])) {
                        battleStatus->unk_85--;
                    }
                    break;
            }

            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                return;
            }

            if (actionCommandStatus->barFillLevel == 0) {
                battleStatus->actionSuccess = -1;
            } else {
                battleStatus->actionSuccess = actionCommandStatus->barFillLevel / 100;
            }

            cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
            if (cutoff >= battleStatus->actionSuccess) {
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

#include "common/draw_hud_elements.inc.c"

#include "common/free_hud_elements.inc.c"
