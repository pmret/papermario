#include "common.h"
#include "audio/public.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_spook

s32 D_802A9920_430940[] = { 0, 25, 50, 75, 75, 0, 0, 0 };

extern s32 actionCmdTableSpook[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    battleStatus->unk_82 = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTableSpook;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }
    action_command_init_status();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_SPOOK;
    actionCommandStatus->showHud = TRUE;
    actionCommandStatus->hudPrepareTime = 30;
    actionCommandStatus->state = AC_STATE_INIT;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    actionCommandStatus->isBarFilled = FALSE;
    battleStatus->actionSuccess = 0;
    battleStatus->actionQuality = 0;
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

#include "common/MashCommandStart.inc.c"

void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
    s32 cutoff;
    s32 fillLevel;

    switch (actionCommandStatus->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(99);

            id = actionCommandStatus->hudElements[0];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            id = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            actionCommandStatus->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            btl_set_popup_duration(99);
            actionCommandStatus->hudPosX += 20;
            if (actionCommandStatus->hudPosX > 50) {
                actionCommandStatus->hudPosX = 50;
            }
            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(99);
            if (actionCommandStatus->prepareTime != 0) {
                actionCommandStatus->prepareTime--;
                return;
            }
            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_StickMashLeft);
            actionCommandStatus->barFillLevel = 0;
            battleStatus->actionQuality = 0;
            actionCommandStatus->any.unk_5C = 0;
            actionCommandStatus->frameCounter = actionCommandStatus->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            actionCommandStatus->state = AC_STATE_ACTIVE;
            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(99);
            if (!actionCommandStatus->isBarFilled) {
                if (actionCommandStatus->targetWeakness != 0) {
                    cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];

                    actionCommandStatus->barFillLevel -= D_802A9920_430940[actionCommandStatus->barFillLevel / cutoff / 20];
                    if (actionCommandStatus->barFillLevel < 0) {
                        actionCommandStatus->barFillLevel = 0;
                    }
                } else {
                    actionCommandStatus->barFillLevel -= 10;
                    if (actionCommandStatus->barFillLevel < 0) {
                        actionCommandStatus->barFillLevel = 0;
                    }
                }

                 if (!actionCommandStatus->isBarFilled) {
                    if (actionCommandStatus->targetWeakness != 0) {

                        if (battleStatus->curButtonsDown & BUTTON_STICK_LEFT) {
                            actionCommandStatus->any.unk_5C = TRUE;
                        }

                        if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT) && actionCommandStatus->any.unk_5C) {
                            s32 a = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty];
                            s32 b = actionCommandStatus->targetWeakness * 850;

                            actionCommandStatus->barFillLevel += (a * b) / 10000;
                            actionCommandStatus->any.unk_5C = 0;
                        }

                        if (battleStatus->curButtonsPressed & BUTTON_STICK_RIGHT) {
                            s32 a = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty];
                            s32 b = actionCommandStatus->targetWeakness * 850;

                            actionCommandStatus->barFillLevel -= (a * b) / 10000;
                        }
                    } else {
                        if (battleStatus->curButtonsDown & BUTTON_STICK_LEFT) {
                            actionCommandStatus->any.unk_5C = TRUE;
                        }

                        if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT) && actionCommandStatus->any.unk_5C) {
                            actionCommandStatus->barFillLevel += 100;
                            if (actionCommandStatus->barFillLevel >= 500) {
                                actionCommandStatus->barFillLevel = 500;
                            }
                            actionCommandStatus->any.unk_5C = 0;
                        }

                        if (battleStatus->curButtonsPressed & BUTTON_STICK_RIGHT) {
                            actionCommandStatus->barFillLevel -= 100;
                        }
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
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionQuality = actionCommandStatus->barFillLevel / 100;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, battleStatus->actionQuality * 12);

            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                return;
            }

            fillLevel = actionCommandStatus->barFillLevel;
            if (actionCommandStatus->targetWeakness == 0) {
                fillLevel = 0;
            }

            if (fillLevel == 0) {
                battleStatus->actionSuccess = -1;
            } else {
                battleStatus->actionSuccess = fillLevel / 100;

            }

            cutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
            if (battleStatus->actionSuccess > cutoff) {
                battleStatus->actionResult = ACTION_RESULT_SUCCESS;
            } else {
                battleStatus->actionResult = ACTION_RESULT_MINUS_2;
            }

            if (battleStatus->actionSuccess == 100) {
                increment_action_command_success_count();
            }
            btl_set_popup_duration(0);
            sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
            actionCommandStatus->frameCounter = 5;
            actionCommandStatus->state = AC_STATE_DISPOSE;
            break;
        case AC_STATE_DISPOSE:
            if (actionCommandStatus->targetWeakness == 0) {
                actionCommandStatus->barFillLevel -= 100;
                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
                }
            }

            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                return;
            }
            action_command_free();
            break;
    }
}

#include "common/MashCommandDraw.inc.c"

#include "common/MashCommandFree.inc.c"
