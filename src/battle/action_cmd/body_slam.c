#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_body_slam

extern s32 actionCmdTableBodySlam[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    battleStatus->unk_82 = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTableBodySlam;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_BODY_SLAM;
    actionCommandStatus->showHud = TRUE;
    actionCommandStatus->state = 0;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    actionCommandStatus->isBarFilled = FALSE;
    battleStatus->actionSuccess = 0;
    actionCommandStatus->hudPosX = -48;
    actionCommandStatus->hudPosY = 80;

    id = hud_element_create(&HES_AButton);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_BlueMeter);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_FillGaugeResult);
    actionCommandStatus->hudElements[3] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_TimingWait);
    actionCommandStatus->hudElements[2] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX + 41, actionCommandStatus->hudPosY + 22);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80);
    return ApiStatus_DONE2;
}

#include "common/MashActionCommandStart.inc.c"

void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
    s32 phi_v0;

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

            id = actionCommandStatus->hudElements[2];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }

            id = actionCommandStatus->hudElements[3];
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
            hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudPosX + 41, actionCommandStatus->hudPosY + 22);
            hud_element_set_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudPosX + 42, actionCommandStatus->hudPosY + 24);
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->prepareTime != 0) {
                actionCommandStatus->prepareTime--;
                return;
            }
            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_AButtonDown);
            actionCommandStatus->barFillLevel = 0;
            actionCommandStatus->thresholdLevel = 0;
            actionCommandStatus->frameCounter = actionCommandStatus->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            actionCommandStatus->state = 11;
        case 11:
            btl_set_popup_duration(99);

            if (battleStatus->curButtonsDown & BUTTON_A) {
                actionCommandStatus->barFillLevel += 154;
                actionCommandStatus->thresholdLevel += 154;
            } else {
                actionCommandStatus->frameCounter = 0;
            }

            if (actionCommandStatus->barFillLevel >= 10000) {
                actionCommandStatus->barFillLevel = 10000;
                hud_element_set_script(actionCommandStatus->hudElements[2], &HES_TimingReady);
                hud_element_set_script(actionCommandStatus->hudElements[0], &HES_AButton);
                if (!actionCommandStatus->isBarFilled) {
                    sfx_play_sound(SOUND_TIMING_BAR_GO);
                    actionCommandStatus->isBarFilled = TRUE;
                }
            }

            battleStatus->actionQuality = actionCommandStatus->barFillLevel / 100;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, battleStatus->actionQuality * 12);
            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                return;
            }

            do {
                if (actionCommandStatus->thresholdLevel < 10000) {
                    battleStatus->actionSuccess = -1;
                } else if (actionCommandStatus->thresholdLevel - (battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] * 154) >= 10309) {
                    battleStatus->actionSuccess = -1;
                } else {
                    battleStatus->actionSuccess = 1;
                }
            } while (0); // required to match

            battleStatus->actionResult = ACTION_RESULT_FAIL;
            if (battleStatus->actionSuccess == 1) {
                func_80269160();
            }
            btl_set_popup_duration(0);
            sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
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

void N(draw)(void) {
    s32 x, y;
    s32 hudElement;

    hud_element_draw_clipped(gActionCommandStatus.hudElements[0]);
    hudElement = gActionCommandStatus.hudElements[1];
    hud_element_draw_clipped(hudElement);
    hud_element_get_render_pos(hudElement, &x, &y);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[3]);
    draw_mash_meter_multicolor(x, y, gActionCommandStatus.barFillLevel / 100);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[2]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
}
