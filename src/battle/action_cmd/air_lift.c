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
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hudElement;

    battleStatus->actionCmdDifficultyTable = actionCmdTableAirLift;
    battleStatus->unk_82 = 0;
    battleStatus->actionResult = ACTION_RESULT_NONE;

    action_command_init_status();

    acs->unk_5A = evt_get_variable(script, *args++);

    acs->actionCommandID = ACTION_COMMAND_AIR_LIFT;
    acs->showHud = TRUE;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    acs->isBarFilled = FALSE;
    battleStatus->actionSuccess = 0;
    battleStatus->actionQuality = 0;
    acs->hudPrepareTime = 30;
    acs->hudPosX = -48;
    air_lift_bss_0 = 0;
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

    hudElement = hud_element_create(&HES_100pct);
    acs->hudElements[2] = hudElement;
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    u8 mashMeterCutoff;

    action_command_init_status();

    acs->prepareTime = evt_get_variable(script, *args++);
    acs->duration = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);
    acs->targetWeakness = evt_get_variable(script, *args++);

    acs->wrongButtonPressed = FALSE;
    battleStatus->actionSuccess = 0;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    battleStatus->unk_82 = acs->mashMeterCutoffs[acs->mashMeterIntervals - 1];

    acs->any.unk_5C = 0;

    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    acs->state = AC_STATE_START;

    increment_action_command_attempt_count();

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(99);

            id = acs->hudElements[0];
            hud_element_set_alpha(id, 255);
            if (acs->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            id = acs->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (acs->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            acs->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            btl_set_popup_duration(99);

            if (acs->hudPrepareTime != 0) {
                acs->hudPrepareTime--;
                return;
            }

            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }

            hud_element_set_render_pos(acs->hudElements[0], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[1], acs->hudPosX, acs->hudPosY + 28);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(99);

            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }

            hud_element_set_script(acs->hudElements[0], &HES_MashAButton);
            air_lift_bss_0 = 1;
            acs->frameCounter = acs->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            acs->state = AC_STATE_ACTIVE;
            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(99);
            if (!acs->isBarFilled) {
                if (acs->unk_5A != 0) {
                    s32 a = acs->mashMeterCutoffs[acs->mashMeterIntervals];

                    acs->barFillLevel -= D_802A9852_4292C0[acs->barFillLevel / a / 20];
                    if (acs->barFillLevel < 0) {
                        acs->barFillLevel = 0;
                    }
                } else {
                    acs->barFillLevel -= 10;
                    if (acs->barFillLevel < 0) {
                        acs->barFillLevel = 0;
                    }
                }
            }

            if (battleStatus->actionCommandMode != AC_MODE_NOT_LEARNED && (battleStatus->curButtonsPressed & BUTTON_A)) {
                if (acs->unk_5A != 0) {
                    s32 a = battleStatus->actionCmdDifficultyTable[acs->difficulty];
                    s32 b = acs->unk_5A * 820;

                    acs->barFillLevel += (a * b) / 10000;
                } else {
                    acs->barFillLevel += 100;
                    if (acs->barFillLevel >= 500) {
                        acs->barFillLevel = 500;
                    }
                }
            }

            if (acs->barFillLevel > 10000) {
                acs->barFillLevel = 10000;
                acs->isBarFilled = TRUE;
                id = acs->hudElements[2];
                hud_element_set_render_pos(id, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionSuccess = acs->barFillLevel / 100;
            if (battleStatus->actionQuality < battleStatus->actionSuccess) {
                battleStatus->actionQuality = battleStatus->actionSuccess;
            }
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, battleStatus->actionSuccess * 12);

            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                return;
            }

            if (acs->unk_5A == 0) {
                battleStatus->actionQuality = 0;
            }

            battleStatus->actionSuccess = battleStatus->actionQuality;
            if (rand_int(99) < battleStatus->actionSuccess) {
                battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                battleStatus->actionSuccess = 1;
            } else {
                battleStatus->actionResult = ACTION_RESULT_MINUS_2;
                battleStatus->actionSuccess = -1;
            }

            if (battleStatus->actionSuccess == 1) {
                increment_action_command_success_count();
            }
            btl_set_popup_duration(0);
            sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
            acs->frameCounter = 20;
            acs->state = AC_STATE_DISPOSE;
            break;
        case AC_STATE_DISPOSE:
            if (acs->unk_5A == 0) {
                acs->barFillLevel -= 100;
                if (acs->barFillLevel < 0) {
                    acs->barFillLevel = 0;
                }
            }
            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                return;
            }
            action_command_free();
            break;
    }
}

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hudX;
    s32 hudY;
    s32 hudElement1;

    if (gBattleStatus.actionCommandMode != AC_MODE_NOT_LEARNED) {
        hud_element_draw_clipped(acs->hudElements[0]);
    }

    hudElement1 = acs->hudElements[1];
    hud_element_draw_clipped(hudElement1);
    hud_element_get_render_pos(hudElement1, &hudX, &hudY);

    if (air_lift_bss_0 == 0) {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->barFillLevel / 100, 1);
    } else if (!acs->isBarFilled) {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->barFillLevel / 100, 4);
    } else {
        draw_mash_meter_blink_with_divisor(hudX, hudY, acs->barFillLevel / 100, 4);
    }

    hud_element_draw_clipped(acs->hudElements[2]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
}

