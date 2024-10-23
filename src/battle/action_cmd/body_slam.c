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
    HudElemID hid;

    battleStatus->maxActionQuality = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTableBodySlam;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    acs->actionCommandID = ACTION_COMMAND_BODY_SLAM;
    acs->showHud = TRUE;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->meterFillLevel = 0;
    acs->meterFillWidth = 0;
    acs->isMeterFilled = FALSE;
    battleStatus->actionQuality = 0;
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_AButton);
    acs->hudElemIDs[HIDX_BUTTON] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_BlueMeter);
    acs->hudElemIDs[HIDX_METER] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_FillGaugeResult);
    acs->hudElemIDs[HIDX_FRAME] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_TimingWait);
    acs->hudElemIDs[HIDX_LIGHT] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX + 41, acs->hudPosY + 22);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->prepareTime = evt_get_variable(script, *args++);
    acs->duration = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);
    acs->statusChance = evt_get_variable(script, *args++); // unused

    acs->wrongButtonPressed = FALSE;
    acs->meterFillLevel = 0;
    acs->meterFillWidth = 0;
    battleStatus->actionQuality = 0;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    battleStatus->maxActionQuality = acs->mashMeterCutoffs[(acs->mashMeterNumIntervals - 1)];
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    acs->state = AC_STATE_START;

    increment_action_command_attempt_count();

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElemID hid;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);

            hid = acs->hudElemIDs[HIDX_BUTTON];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElemIDs[HIDX_METER];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElemIDs[HIDX_LIGHT];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElemIDs[HIDX_FRAME];
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
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_BUTTON], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_METER], acs->hudPosX, acs->hudPosY + 28);
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_LIGHT], acs->hudPosX + 41, acs->hudPosY + 22);
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_FRAME], acs->hudPosX + 42, acs->hudPosY + 24);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }
            hud_element_set_script(acs->hudElemIDs[HIDX_BUTTON], &HES_AButtonDown);
            acs->meterFillLevel = 0;
            acs->escapeThreshold = 0;
            acs->stateTimer = acs->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_METER, 0, 0, 0);
            acs->state = AC_STATE_ACTIVE;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);

            // check for meter-filling input
            if (battleStatus->curButtonsDown & BUTTON_A) {
                acs->meterFillLevel += METER_FILL_RATE;
                acs->escapeThreshold += METER_FILL_RATE;
            } else {
                acs->stateTimer = 0;
            }

            // handle meter reaching 100%
            if (acs->meterFillLevel >= MAX_MASH_UNITS) {
                acs->meterFillLevel = MAX_MASH_UNITS;
                hud_element_set_script(acs->hudElemIDs[HIDX_LIGHT], &HES_TimingReady);
                hud_element_set_script(acs->hudElemIDs[HIDX_BUTTON], &HES_AButton);
                if (!acs->isMeterFilled) {
                    sfx_play_sound(SOUND_TIMING_BAR_GO);
                    acs->isMeterFilled = TRUE;
                }
            }

            battleStatus->actionProgress = acs->meterFillLevel / ONE_PCT_MASH;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_METER, 0, 0, battleStatus->actionProgress * 12);
            if (acs->stateTimer != 0) {
                acs->stateTimer--;
                return;
            }

            do {
                if (acs->escapeThreshold < MAX_MASH_UNITS) {
                    battleStatus->actionQuality = AC_QUALITY_FAILED;
                } else {
                    s32 window = battleStatus->actionCmdDifficultyTable[acs->difficulty] * METER_FILL_RATE;
                    // release needs to be within 2 frames + modifier from difficulty table
                    if (acs->escapeThreshold - window >= MAX_MASH_UNITS + 2 * METER_FILL_RATE + 1) {
                        battleStatus->actionQuality = AC_QUALITY_FAILED;
                    } else {
                        battleStatus->actionQuality = 1;
                    }
                }
            } while (0); // required to match

            battleStatus->actionResult = ACTION_RESULT_FAIL;
            if (battleStatus->actionQuality == 1) {
                increment_action_command_success_count();
            }

            btl_set_popup_duration(POPUP_MSG_OFF);
            sfx_stop_sound(SOUND_LOOP_CHARGE_METER);
            acs->stateTimer = 5;
            acs->state = AC_STATE_DISPOSE;
            break;
        case AC_STATE_DISPOSE:
            if (acs->stateTimer != 0) {
                acs->stateTimer--;
                return;
            }
            action_command_free();
            break;
    }
}

void N(draw)(void) {
    s32 hudX, hudY;
    HudElemID hid;

    hud_element_draw_clipped(gActionCommandStatus.hudElemIDs[HIDX_BUTTON]);
    hid = gActionCommandStatus.hudElemIDs[HIDX_METER];
    hud_element_draw_clipped(hid);
    hud_element_get_render_pos(hid, &hudX, &hudY);
    hud_element_draw_clipped(gActionCommandStatus.hudElemIDs[HIDX_FRAME]);
    draw_mash_meter_multicolor(hudX, hudY, gActionCommandStatus.meterFillLevel / ONE_PCT_MASH);
    hud_element_draw_clipped(gActionCommandStatus.hudElemIDs[HIDX_LIGHT]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_BUTTON]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_METER]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_LIGHT]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_FRAME]);
}
