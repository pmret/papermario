#include "battle/battle.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_air_raid

s32 D_802A9970_429C90[] = { 0, 25, 50, 75, 75 };
s32 D_802A9984_429CA4[] = { 40, 70, 99, 200 };
s32 D_802A9994_429CB4[] = { 35, 60, 80, 99, 200 };
s32 D_802A99A8_429CC8[] = { 35, 35, 60, 80, 99, 200 };

extern s32 actionCmdTableAirRaid[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTableAirRaid;
    battleStatus->unk_86 = 127;

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    actionCommandStatus->actionCommandID = ACTION_COMMAND_AIR_RAID;
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

    hudElement = hud_element_create(&HES_StickNeutral);
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
    Actor* partner = battleStatus->partnerActor;
    s32 cutoff;
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

            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);

            if (actionCommandStatus->hudPrepareTime != 0) {
                actionCommandStatus->hudPrepareTime--;
                return;
            }

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
            // fallthrough
        case 11:
            btl_set_popup_duration(99);
            if (!actionCommandStatus->isBarFilled) {
                cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];

                actionCommandStatus->barFillLevel -= D_802A9970_429C90[actionCommandStatus->barFillLevel / cutoff / 20];
                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
                }

                if (!actionCommandStatus->isBarFilled) {
                    if (battleStatus->curButtonsDown & BUTTON_STICK_LEFT) {
                        actionCommandStatus->unk_5C = 1;
                    }

                    if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT)) {
                        if (actionCommandStatus->unk_5C != 0) {
                            actionCommandStatus->barFillLevel += (battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] * 850) / 100;
                            actionCommandStatus->unk_5C = 0;
                        }
                    }

                    if (battleStatus->curButtonsPressed & BUTTON_STICK_RIGHT) {
                        actionCommandStatus->barFillLevel -= (battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] * 850) / 100;
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
                    if (battleStatus->actionResult >= D_802A9984_429CA4[battleStatus->unk_85]) {
                        battleStatus->unk_85++;
                    }

                    if (battleStatus->unk_85 > 0 && battleStatus->actionResult < D_802A9984_429CA4[battleStatus->unk_85 - 1]) {
                        battleStatus->unk_85--;
                    }
                    break;
                case 1:
                    if (battleStatus->actionResult >= D_802A9994_429CB4[battleStatus->unk_85]) {
                        battleStatus->unk_85++;
                    }
                    if (battleStatus->unk_85 > 0 && battleStatus->actionResult < D_802A9994_429CB4[battleStatus->unk_85 - 1]) {
                        battleStatus->unk_85--;
                    }
                    break;
                case 2:
                    if (battleStatus->actionResult >= D_802A99A8_429CC8[battleStatus->unk_85]) {
                        battleStatus->unk_85++;
                    }
                    if (battleStatus->unk_85 > 0 && battleStatus->actionResult < D_802A99A8_429CC8[battleStatus->unk_85 - 1]) {
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
            if (battleStatus->actionSuccess <= cutoff) {
                battleStatus->unk_86 = -2;
            } else {
                battleStatus->unk_86 = 1;
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
                return;
            }
            action_command_free();
            break;
    }
}

#include "common/draw_hud_elements.inc.c"

#include "common/free_hud_elements.inc.c"
