#include "common.h"
#include "battle/action_cmd.h"

/**
 * Seems to be an unused, partially broken version of the Flee action command.
 * The player must mash A to fill a meter up to an OK mark.
 *
 * Unlike the normal flee command, the OK mark does not move and the command will only
 * succeed of the meter is filled. Once filled, it rapidly drains and must be refilled.
 */

#define NAMESPACE action_command_unused_flee

void btl_message_unlock_box_pos(void);

extern s32 actionCmdTable07[];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_BUTTON         = 0,
    HIDX_METER          = 1,
    HIDX_OK             = 2,
};

// how much to add to the meter per input if all modifiers are neutral
#define METER_FILL_TICK 600

BSS b32 N(HasStarted);

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    HudElemID hid;
    s32 temp;

    battleStatus->maxActionQuality = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTable07;

    acs->autoSucceed = FALSE;
    acs->actionCommandID = ACTION_COMMAND_UNUSED_FLEE;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->meterFillLevel = evt_get_variable(script, *args);
    acs->hudPosX = -48;
    acs->meterFillWidth = 0;
    N(HasStarted) = FALSE;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_AButton);
    acs->hudElemIDs[HIDX_BUTTON] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);

    // Weird use of an extra temp settles regalloc here.
    hid = temp = hud_element_create(&HES_BlueMeter);
    acs->hudElemIDs[HIDX_METER] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_RunAwayOK);
    acs->hudElemIDs[HIDX_OK] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    acs->autoSucceed = FALSE;
    acs->prepareTime = evt_get_variable(script, *args++);
    acs->duration = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);

    acs->wrongButtonPressed = FALSE;
    battleStatus->actionQuality = 0;
    battleStatus->actionResult = ACTION_RESULT_FAIL;

    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    btl_message_unlock_box_pos();
    acs->state = AC_STATE_START;

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
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);

            hid = acs->hudElemIDs[HIDX_METER];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElemIDs[HIDX_OK];
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
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_OK], acs->hudPosX + 31, acs->hudPosY + 14);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);

            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }

            hud_element_set_script(acs->hudElemIDs[HIDX_BUTTON], &HES_MashAButton);
            battleStatus->actionQuality = 0;
            N(HasStarted) = TRUE;
            acs->flee.drainDelay = 0;
            acs->state = AC_STATE_ACTIVE;
            acs->stateTimer = acs->duration;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);

            // check for meter-filling input
            if (battleStatus->curButtonsPressed & BUTTON_A) {
                s32 fillAmt = SCALE_BY_PCT(METER_FILL_TICK, battleStatus->actionCmdDifficultyTable[acs->difficulty]);

                if (acs->flee.drainDelay == 0) {
                    acs->meterFillLevel += fillAmt;
                }
            }

            // handle meter reaching 100%
            if (acs->meterFillLevel > MAX_MASH_UNITS) {
                acs->meterFillLevel = MAX_MASH_UNITS;
                acs->flee.drainDelay = 3;
            }

            // meter can reset if mashing stops after it's been fully filled
            if (acs->flee.drainDelay != 0) {
                acs->flee.drainDelay--;
                if (acs->flee.drainDelay == 0) {
                    acs->meterFillLevel = 0;
                    battleStatus->actionQuality++;
                }
            }

            battleStatus->actionProgress = acs->meterFillLevel / ONE_PCT_MASH;

            if (acs->stateTimer != 0) {
                acs->stateTimer--;
                return;
            }
            btl_set_popup_duration(POPUP_MSG_OFF);
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
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hudX, hudY;
    HudElemID hid;

    hud_element_draw_clipped(acs->hudElemIDs[HIDX_BUTTON]);
    hid = acs->hudElemIDs[HIDX_METER];
    hud_element_draw_clipped(hid);
    hud_element_get_render_pos(hid, &hudX, &hudY);

    if (!N(HasStarted)) {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->meterFillLevel / ONE_PCT_MASH, 1);
    } else {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->meterFillLevel / ONE_PCT_MASH, 2);
    }

    hud_element_draw_clipped(acs->hudElemIDs[HIDX_OK]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_BUTTON]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_METER]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_OK]);
}
