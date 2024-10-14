#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_flee

extern s32 actionCmdTableFlee[];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_BUTTON         = 0,
    HIDX_METER          = 1,
    HIDX_RUN_AWAY       = 2,
    HIDX_OK             = 3,
    HIDX_100_PCT        = 4,
};

// how much to add to the meter per input if all modifiers are neutral
#define BASE_FILL_RATE 180

BSS b32 N(HasStarted);

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 offsetX;
    s32 hid;

    battleStatus->unk_82 = 0;
    battleStatus->actionCmdDifficultyTable = actionCmdTableFlee;
    battleStatus->actionResult = ACTION_RESULT_NONE;

    action_command_init_status();

    acs->effectiveness = evt_get_variable(script, *args++);

    acs->actionCommandID = ACTION_COMMAND_FLEE;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = acs->effectiveness * 100;
    acs->thresholdLevel = rand_int(50);
    acs->barFillWidth = 0;
    acs->flee.dir = 1;
    acs->effectiveness = rand_int(1);
    acs->isBarFilled = FALSE;
    battleStatus->actionSuccess = 0;
    N(HasStarted) = FALSE;
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

    hid = hud_element_create(&HES_RunningAway);
    acs->hudElements[HIDX_RUN_AWAY] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_RunAwayOK);
    acs->hudElements[HIDX_OK] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    offsetX = 29 - ((100 - acs->thresholdLevel) * 60) / 100;
    hud_element_set_render_pos(acs->hudElements[HIDX_OK], acs->hudPosX - offsetX, acs->hudPosY + 17);
    hud_element_set_render_pos(acs->hudElements[HIDX_RUN_AWAY], acs->hudPosX - offsetX, acs->hudPosY - 1);

    hid = hud_element_create(&HES_100pct);
    acs->hudElements[HIDX_100_PCT] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    action_command_init_status();

    acs->prepareTime = evt_get_variable(script, *args++);
    acs->duration = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);

    acs->wrongButtonPressed = FALSE;
    battleStatus->actionSuccess = 0;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    battleStatus->unk_82 = acs->mashMeterCutoffs[acs->mashMeterNumIntervals - 1];
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    acs->state = AC_STATE_START;

    return ApiStatus_DONE2;
}

void N(update)(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hid;
    s32 temp;

    switch (acs->state) {
        case AC_STATE_INIT:
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

            hid = acs->hudElements[HIDX_RUN_AWAY];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElements[HIDX_OK];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            acs->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }
            hud_element_set_render_pos(acs->hudElements[HIDX_BUTTON], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[HIDX_METER], acs->hudPosX, acs->hudPosY + 28);
            break;
        case AC_STATE_START:
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                break;
            }

            hud_element_set_script(acs->hudElements[HIDX_BUTTON], &HES_MashAButton);
            N(HasStarted) = TRUE;
            acs->state = AC_STATE_ACTIVE;
            acs->frameCounter = acs->duration;

            // fallthrough
        case AC_STATE_ACTIVE:
            // check for bar-filling input
            if (battleStatus->actionCommandMode != AC_MODE_NOT_LEARNED && (battleStatus->curButtonsPressed & BUTTON_A)) {
                acs->barFillLevel += (battleStatus->actionCmdDifficultyTable[acs->difficulty] * BASE_FILL_RATE) / 100;
            }

            // handle bar reaching 100%
            if (acs->barFillLevel >= MAX_MASH_UNITS) {
                acs->barFillLevel = MAX_MASH_UNITS;
                acs->isBarFilled = TRUE;
                hid = acs->hudElements[HIDX_100_PCT];
                hud_element_set_render_pos(hid, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionSuccess = acs->barFillLevel / ONE_PCT_MASH;
            if (acs->frameCounter == 0) {
                if (battleStatus->actionSuccess >= (100 - acs->thresholdLevel)) {
                    battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                    battleStatus->actionSuccess = 1;
                } else {
                    battleStatus->actionResult = ACTION_RESULT_MINUS_2;
                    battleStatus->actionSuccess = -1;
                }
                acs->frameCounter = 20;
                acs->state = AC_STATE_DISPOSE;
            } else {
                acs->frameCounter--;
            }
            break;
        case AC_STATE_DISPOSE:
            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                break;
            }
            action_command_free();
            break;
    }

    // update the position of the 'OK' tick
    switch (acs->state) {
        case AC_STATE_APPEAR:
        case AC_STATE_START:
        case AC_STATE_ACTIVE:
            temp = acs->effectiveness == 0 ? 7 : 8;
            if (acs->flee.dir == 0) {
                acs->thresholdLevel += temp;
                if (acs->thresholdLevel >= 100) {
                    acs->thresholdLevel = 100;
                    acs->flee.dir = 1;
                }
                break;
            }
            acs->thresholdLevel -= temp;
            if (acs->thresholdLevel <= 0) {
                acs->thresholdLevel = 0;
                acs->flee.dir = 0;
            }
            break;
    }
}

void N(draw)(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hudX, hudY;
    s32 hid;

    // equivalent to 60 * acs->thresholdLevel / 100
    hudX = 60 - ((100 - acs->thresholdLevel) * 60 / 100);

    hud_element_set_render_pos(acs->hudElements[HIDX_OK], acs->hudPosX + 31 - hudX, acs->hudPosY + 17);
    hud_element_set_render_pos(acs->hudElements[HIDX_RUN_AWAY], acs->hudPosX + 31 - hudX, acs->hudPosY - 1);

    if (battleStatus->actionCommandMode != AC_MODE_NOT_LEARNED) {
        hud_element_draw_clipped(acs->hudElements[HIDX_BUTTON]);
    }

    hid = acs->hudElements[HIDX_METER];
    hud_element_draw_clipped(hid);
    hud_element_get_render_pos(hid, &hudX, &hudY);

    if (!N(HasStarted)) {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH, 1);
    } else if (!acs->isBarFilled) {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH, 4);
    } else {
        draw_mash_meter_blink(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH);
    }

    hud_element_draw_clipped(acs->hudElements[HIDX_RUN_AWAY]);
    hud_element_draw_clipped(acs->hudElements[HIDX_OK]);
    hud_element_draw_clipped(acs->hudElements[HIDX_100_PCT]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[HIDX_BUTTON]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_METER]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_RUN_AWAY]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_OK]);
    hud_element_free(gActionCommandStatus.hudElements[HIDX_100_PCT]);
}
