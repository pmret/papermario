#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_body_slam

extern s32 actionCmdTableBodySlam[];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_BUTTON         = 0,
    HIDX_METER          = 1,
    HIDX_LIGHT          = 2,
    HIDX_FRAME          = 3,
};

// how much to add to the meter per frame
#define METER_FILL_RATE 154

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hid;

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

    hid = hud_element_create(&HES_AButton);
    acs->hudElements[HIDX_BUTTON] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_BlueMeter);
    acs->hudElements[HIDX_METER] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_FillGaugeResult);
    acs->hudElements[HIDX_FRAME] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_TimingWait);
    acs->hudElements[HIDX_LIGHT] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX + 41, acs->hudPosY + 22);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80);
    return ApiStatus_DONE2;
}

#include "common/MashCommandStart.inc.c"

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hid;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);

            hid = acs->hudElements[HIDX_BUTTON];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElements[HIDX_METER];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElements[HIDX_LIGHT];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElements[HIDX_FRAME];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            acs->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            btl_set_popup_duration(POPUP_MSG_ON);
            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }
            hud_element_set_render_pos(acs->hudElements[HIDX_BUTTON], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[HIDX_METER], acs->hudPosX, acs->hudPosY + 28);
            hud_element_set_render_pos(acs->hudElements[HIDX_LIGHT], acs->hudPosX + 41, acs->hudPosY + 22);
            hud_element_set_render_pos(acs->hudElements[HIDX_FRAME], acs->hudPosX + 42, acs->hudPosY + 24);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }
            hud_element_set_script(acs->hudElements[HIDX_BUTTON], &HES_AButtonDown);
            acs->barFillLevel = 0;
            acs->thresholdLevel = 0;
            acs->frameCounter = acs->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            acs->state = AC_STATE_ACTIVE;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);

            // check for bar-filling input
            if (battleStatus->curButtonsDown & BUTTON_A) {
                acs->barFillLevel += METER_FILL_RATE;
                acs->thresholdLevel += METER_FILL_RATE;
            } else {
                acs->frameCounter = 0;
            }

            // handle bar reaching 100%
            if (acs->barFillLevel >= MAX_MASH_UNITS) {
                acs->barFillLevel = MAX_MASH_UNITS;
                hud_element_set_script(acs->hudElements[HIDX_LIGHT], &HES_TimingReady);
                hud_element_set_script(acs->hudElements[HIDX_BUTTON], &HES_AButton);
                if (!acs->isBarFilled) {
                    sfx_play_sound(SOUND_TIMING_BAR_GO);
                    acs->isBarFilled = TRUE;
                }
            }

            battleStatus->actionQuality = acs->barFillLevel / ONE_PCT_MASH;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, battleStatus->actionQuality * 12);
            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                return;
            }

            do {
                if (acs->thresholdLevel < MAX_MASH_UNITS) {
                    battleStatus->actionSuccess = AC_ACTION_FAILED;
                } else {
                    s32 window = battleStatus->actionCmdDifficultyTable[acs->difficulty] * METER_FILL_RATE;
                    // release needs to be within 2 frames + modifier from difficulty table
                    if (acs->thresholdLevel - window >= MAX_MASH_UNITS + 2 * METER_FILL_RATE + 1) {
                        battleStatus->actionSuccess = AC_ACTION_FAILED;
                    } else {
                        battleStatus->actionSuccess = 1;
                    }
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
    s32 hudX, hudY;
    s32 hid;

    hud_element_draw_clipped(gActionCommandStatus.hudElements[HIDX_BUTTON]);
    hid = gActionCommandStatus.hudElements[HIDX_METER];
    hud_element_draw_clipped(hid);
    hud_element_get_render_pos(hid, &hudX, &hudY);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[HIDX_FRAME]);
    draw_mash_meter_multicolor(hudX, hudY, gActionCommandStatus.barFillLevel / ONE_PCT_MASH);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[HIDX_LIGHT]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[HIDX_BUTTON]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_METER]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_LIGHT]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_FRAME]);
}
