#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_squirt

s32 D_802A9760_42A480[] = { 300, 300, 265, 220, 175, 175 };
s32 D_802A9778_42A498[] = { 300, 300, 265, 220, 175, 175 };

extern s32 actionCmdTableSquirt[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    battleStatus->unk_82 = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTableSquirt;
    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->actionCommandID = ACTION_COMMAND_SQUIRT;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    battleStatus->actionQuality = 0;
    acs->hudPosX = -48;
    acs->any.unk_5C = 0;
    acs->hudPosY = 80;

    id = hud_element_create(&HES_AButton);
    acs->hudElements[0] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_BlueMeter);
    acs->hudElements[1] = id;
    hud_element_set_render_pos(id, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->prepareTime = evt_get_variable(script, *args++);
    acs->duration = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);

    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->actionResult = ACTION_RESULT_FAIL;
    acs->state = AC_STATE_START;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

    increment_action_command_attempt_count();

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
    s32 mashMeterCutoff;
    s32 cutoff;
    s32 temp;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(99);

            id = acs->hudElements[0];
            if (acs->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(id, 255);

            id = acs->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (acs->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            acs->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            btl_set_popup_duration(99);

            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }

            hud_element_set_render_pos(acs->hudElements[0], acs->hudPosX,
                acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[1], acs->hudPosX,
                acs->hudPosY + 28);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(99);

            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                break;
            }

            hud_element_set_script(acs->hudElements[0], &HES_AButtonDown);
            acs->barFillLevel = 0;
            acs->any.unk_5C = 0;
            acs->frameCounter = acs->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            acs->state = AC_STATE_ACTIVE;
            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(99);
            cutoff = acs->mashMeterCutoffs[acs->mashMeterIntervals];
            temp = acs->barFillLevel / cutoff;
            if (acs->any.unk_5C == 0) {
                if (!(battleStatus->curButtonsDown & BUTTON_A)) {
                    acs->barFillLevel -= D_802A9760_42A480[temp / 20];
                    if (acs->barFillLevel < 0) {
                        acs->barFillLevel = 0;
                    }
                } else {
                    acs->barFillLevel += D_802A9778_42A498[temp / 20] * battleStatus->actionCmdDifficultyTable[acs->difficulty] / 100;
                    if (acs->barFillLevel > 10000) {
                        acs->barFillLevel = 10000;
                        acs->any.unk_5C = 1;
                    }
                }
            } else {
                acs->barFillLevel -= 250;
                if (acs->barFillLevel <= 0) {
                    acs->barFillLevel = 0;
                    acs->any.unk_5C = 0;
                }
            }

            battleStatus->actionQuality = acs->barFillLevel / 100;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, battleStatus->actionQuality * 12);
            id = acs->hudElements[0];
            if (temp < 80) {
                if (hud_element_get_script(id) != &HES_AButtonDown) {
                    hud_element_set_script(id, &HES_AButtonDown);
                }
            } else {
                if (hud_element_get_script(id) != &HES_PressAButton) {
                    hud_element_set_script(id, &HES_PressAButton);
                }
            }

            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                return;
            }

            if (acs->barFillLevel == 0) {
                battleStatus->actionSuccess = -1;
            } else {
                battleStatus->actionSuccess = battleStatus->actionQuality;
            }

            cutoff = acs->mashMeterCutoffs[acs->mashMeterIntervals - 1];
            if (cutoff / 2 < battleStatus->actionQuality) {
                battleStatus->actionResult = ACTION_RESULT_SUCCESS;
            } else {
                battleStatus->actionResult = ACTION_RESULT_MINUS_4;
            }

            if (battleStatus->actionSuccess == 100) {
                increment_action_command_success_count();
            }
            btl_set_popup_duration(0);
            sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
            acs->frameCounter = 5;
            acs->state = AC_STATE_DISPOSE;
            break;
        case AC_STATE_DISPOSE:
            if (acs->frameCounter != 0) {
                acs->frameCounter--;
            } else {
                action_command_free();
            }
            break;
    }
}

void N(draw)(void) {
    s32 x, y;
    s32 id;
    ActionCommandStatus* acs = &gActionCommandStatus;

    hud_element_draw_clipped(acs->hudElements[0]);
    id = acs->hudElements[1];
    hud_element_draw_clipped(id);
    hud_element_get_render_pos(id, &x, &y);
    if (acs->any.unk_5C == 0) {
        draw_mash_meter_multicolor_with_divisor(x, y, acs->barFillLevel / 100, 1);
    } else {
        draw_mash_meter_mode_with_divisor(x, y, acs->barFillLevel / 100, 1, MASH_METER_MODE_ONE_COLOR);
    }
}

void N(free)(void) {
    sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
}
