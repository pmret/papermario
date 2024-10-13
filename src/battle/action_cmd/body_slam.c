#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_body_slam

extern s32 actionCmdTableBodySlam[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    battleStatus->unk_82 = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTableBodySlam;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    acs->actionCommandID = ACTION_COMMAND_BODY_SLAM;
    acs->showHud = TRUE;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    acs->isBarFilled = FALSE;
    battleStatus->actionSuccess = 0;
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    id = hud_element_create(&HES_AButton);
    acs->hudElements[0] = id;
    hud_element_set_render_pos(id, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_BlueMeter);
    acs->hudElements[1] = id;
    hud_element_set_render_pos(id, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_FillGaugeResult);
    acs->hudElements[3] = id;
    hud_element_set_render_pos(id, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_TimingWait);
    acs->hudElements[2] = id;
    hud_element_set_render_pos(id, acs->hudPosX + 41, acs->hudPosY + 22);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80);
    return ApiStatus_DONE2;
}

#include "common/MashCommandStart.inc.c"

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;
    s32 phi_v0;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);

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

            id = acs->hudElements[2];
            hud_element_set_alpha(id, 255);
            if (acs->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            id = acs->hudElements[3];
            hud_element_set_alpha(id, 255);
            if (acs->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            acs->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            btl_set_popup_duration(POPUP_MSG_ON);
            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }
            hud_element_set_render_pos(acs->hudElements[0], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[1], acs->hudPosX, acs->hudPosY + 28);
            hud_element_set_render_pos(acs->hudElements[2], acs->hudPosX + 41, acs->hudPosY + 22);
            hud_element_set_render_pos(acs->hudElements[3], acs->hudPosX + 42, acs->hudPosY + 24);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }
            hud_element_set_script(acs->hudElements[0], &HES_AButtonDown);
            acs->barFillLevel = 0;
            acs->thresholdLevel = 0;
            acs->frameCounter = acs->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            acs->state = AC_STATE_ACTIVE;
            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);

            if (battleStatus->curButtonsDown & BUTTON_A) {
                acs->barFillLevel += 154;
                acs->thresholdLevel += 154;
            } else {
                acs->frameCounter = 0;
            }

            if (acs->barFillLevel >= 10000) {
                acs->barFillLevel = 10000;
                hud_element_set_script(acs->hudElements[2], &HES_TimingReady);
                hud_element_set_script(acs->hudElements[0], &HES_AButton);
                if (!acs->isBarFilled) {
                    sfx_play_sound(SOUND_TIMING_BAR_GO);
                    acs->isBarFilled = TRUE;
                }
            }

            battleStatus->actionQuality = acs->barFillLevel / 100;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, battleStatus->actionQuality * 12);
            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                return;
            }

            do {
                if (acs->thresholdLevel < 10000) {
                    battleStatus->actionSuccess = -1;
                } else if (acs->thresholdLevel - (battleStatus->actionCmdDifficultyTable[acs->difficulty] * 154) >= 10309) {
                    battleStatus->actionSuccess = -1;
                } else {
                    battleStatus->actionSuccess = 1;
                }
            } while (0); // required to match

            battleStatus->actionResult = ACTION_RESULT_FAIL;
            if (battleStatus->actionSuccess == 1) {
                increment_action_command_success_count();
            }
            btl_set_popup_duration(POPUP_MSG_OFF);
            sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
            acs->frameCounter = 5;
            acs->state = AC_STATE_DISPOSE;
            break;
        case AC_STATE_DISPOSE:
            if (acs->frameCounter != 0) {
                acs->frameCounter--;
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
