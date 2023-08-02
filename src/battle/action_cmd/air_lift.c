#include "common.h"
#include "effects.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_air_lift

s32 D_802A9852_4292C0[] = { 0, 25, 50, 75, 75, 0, 0, 0 };

BSS s32 air_lift_bss_0;

extern s32 actionCmdTableAirLift[];

API_CALLABLE(N(init)) {
    s32 *args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 hudElement;

    battleStatus->actionCmdDifficultyTable = actionCmdTableAirLift;
    battleStatus->unk_82 = 0;
    battleStatus->unk_86 = 127;
    action_command_init_status();
    actionCommandStatus->unk_5A = evt_get_variable(script, *args++);
    actionCommandStatus->actionCommandID = ACTION_COMMAND_AIR_LIFT;
    actionCommandStatus->showHud = TRUE;
    actionCommandStatus->state = 0;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    actionCommandStatus->isBarFilled = FALSE;
    battleStatus->actionSuccess = 0;
    battleStatus->actionResult = 0;
    actionCommandStatus->hudPrepareTime = 30;
    actionCommandStatus->hudPosX = -48;
    air_lift_bss_0 = 0;
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

API_CALLABLE(N(start)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    u8 mashMeterCutoff;

    action_command_init_status();

    actionCommandStatus->prepareTime = evt_get_variable(script, *args++);
    actionCommandStatus->duration = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = adjust_action_command_difficulty(actionCommandStatus->difficulty);
    actionCommandStatus->targetWeakness = evt_get_variable(script, *args++);

    actionCommandStatus->wrongButtonPressed = FALSE;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 127;

    mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
    actionCommandStatus->unk_5C = 0;

    battleStatus->flags1 &= ~BS_FLAGS1_8000;
    actionCommandStatus->state = 10;
    battleStatus->unk_82 = mashMeterCutoff;

    func_80269118();

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
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

            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_MashAButton);
            air_lift_bss_0 = 1;
            actionCommandStatus->frameCounter = actionCommandStatus->duration;
            sfx_play_sound_with_params(SOUND_80000041, 0, 0, 0);
            actionCommandStatus->state = 11;
            // fallthrough
        case 11:
            btl_set_popup_duration(99);
            if (!actionCommandStatus->isBarFilled) {
                if (actionCommandStatus->unk_5A != 0) {
                    s32 a = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];

                    actionCommandStatus->barFillLevel -= D_802A9852_4292C0[actionCommandStatus->barFillLevel / a / 20];
                    if (actionCommandStatus->barFillLevel < 0) {
                        actionCommandStatus->barFillLevel = 0;
                    }
                } else {
                    actionCommandStatus->barFillLevel -= 10;
                    if (actionCommandStatus->barFillLevel < 0) {
                        actionCommandStatus->barFillLevel = 0;
                    }
                }
            }

            if (battleStatus->actionCommandMode != ACTION_COMMAND_MODE_NOT_LEARNED && (battleStatus->curButtonsPressed & BUTTON_A)) {
                if (actionCommandStatus->unk_5A != 0) {
                    s32 a = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty];
                    s32 b = actionCommandStatus->unk_5A * 820;

                    actionCommandStatus->barFillLevel += (a * b) / 10000;
                } else {
                    actionCommandStatus->barFillLevel += 100;
                    if (actionCommandStatus->barFillLevel >= 500) {
                        actionCommandStatus->barFillLevel = 500;
                    }
                }

            }

            if (actionCommandStatus->barFillLevel > 10000) {
                actionCommandStatus->barFillLevel = 10000;
                actionCommandStatus->isBarFilled = TRUE;
                id = actionCommandStatus->hudElements[2];
                hud_element_set_render_pos(id, actionCommandStatus->hudPosX + 50, actionCommandStatus->hudPosY + 28);
                hud_element_clear_flags(id, 2);
            }

            battleStatus->actionSuccess = actionCommandStatus->barFillLevel / 100;
            if (battleStatus->actionResult < battleStatus->actionSuccess) {
                battleStatus->actionResult = battleStatus->actionSuccess;
            }
            sfx_adjust_env_sound_params(SOUND_80000041, 0, 0, battleStatus->actionSuccess * 12);

            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                return;
            }

            if (actionCommandStatus->unk_5A == 0) {
                battleStatus->actionResult = 0;
            }

            battleStatus->actionSuccess = battleStatus->actionResult;
            if (rand_int(99) < battleStatus->actionSuccess) {
                battleStatus->unk_86 = 1;
                battleStatus->actionSuccess = 1;
            } else {
                battleStatus->unk_86 = -2;
                battleStatus->actionSuccess = -1;
            }

            if (battleStatus->actionSuccess == 1) {
                func_80269160();
            }
            btl_set_popup_duration(0);
            sfx_stop_sound(SOUND_80000041);
            actionCommandStatus->frameCounter = 20;
            actionCommandStatus->state = 12;
            break;
        case 12:
            if (actionCommandStatus->unk_5A == 0) {
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

void N(draw)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 hudX;
    s32 hudY;
    s32 hudElement1;

    if (gBattleStatus.actionCommandMode != ACTION_COMMAND_MODE_NOT_LEARNED) {
        hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    }

    hudElement1 = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(hudElement1);
    hud_element_get_render_pos(hudElement1, &hudX, &hudY);

    if (air_lift_bss_0 == 0) {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, actionCommandStatus->barFillLevel / 100, 1);
    } else if (!actionCommandStatus->isBarFilled) {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, actionCommandStatus->barFillLevel / 100, 4);
    } else {
        draw_mash_meter_blink_with_divisor(hudX, hudY, actionCommandStatus->barFillLevel / 100, 4);
    }

    hud_element_draw_clipped(actionCommandStatus->hudElements[2]);
}

#include "common/free_hud_elements.inc.c"
