#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_hurricane

extern s32 actionCmdTableHurricane[];

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_A_BUTTON       = 0,
    HIDX_METER          = 1,
    HIDX_B_BUTTON       = 2,
    HIDX_100_PCT        = 4,
};

// how much to add to the meter per input
#define METER_FILL_TICK 650

s32 N(DrainRateTable)[] = { 0, 25, 50, 75, 75 };

#define GET_DRAIN_RATE(pct) PCT_TO_TABLE_RATE(N(DrainRateTable), pct)

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElemID hid;

    battleStatus->maxActionQuality = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTableHurricane;
    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->actionCommandID = ACTION_COMMAND_HURRICANE;
    acs->hudPrepareTime = 30;
    acs->hudPosX = -48;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = false;
    acs->meterFillLevel = 0;
    acs->meterFillWidth = 0;
    acs->isMeterFilled = false;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_AButton);
    acs->hudElemIDs[HIDX_A_BUTTON] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);

    hid = hud_element_create(&HES_BButton);
    acs->hudElemIDs[HIDX_B_BUTTON] = hid;
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);

    hid = hud_element_create(&HES_BlueMeter);
    acs->hudElemIDs[HIDX_METER] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_100pct);
    acs->hudElemIDs[HIDX_100_PCT] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

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
    acs->statusChance = evt_get_variable(script, *args++); // average chance for enemies to be affected

    acs->wrongButtonPressed = false;
    acs->meterFillLevel = 0;
    acs->meterFillWidth = 0;
    battleStatus->actionQuality = 0;
    battleStatus->actionResult = ACTION_RESULT_FAIL;
    acs->state = AC_STATE_START;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

    increment_action_command_attempt_count();

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElemID hid;
    s32 cutoff;
    s32 buttonsPushed;
    s32 buttonsAB;
    s32 bufferPos;
    s32 i;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);

            hid = acs->hudElemIDs[HIDX_A_BUTTON];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);

            hid = acs->hudElemIDs[HIDX_B_BUTTON];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);

            hid = acs->hudElemIDs[HIDX_METER];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            acs->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->hudPrepareTime != 0) {
                acs->hudPrepareTime--;
                break;
            }

            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }

            hud_element_set_render_pos(acs->hudElemIDs[HIDX_A_BUTTON], acs->hudPosX - 17, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_B_BUTTON], acs->hudPosX + 23, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElemIDs[HIDX_METER], acs->hudPosX, acs->hudPosY + 28);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                break;
            }
            hud_element_set_script(acs->hudElemIDs[HIDX_A_BUTTON], &HES_MashAButton);
            hud_element_set_script(acs->hudElemIDs[HIDX_B_BUTTON], &HES_MashBButton1);
            acs->meterFillLevel = 0;
            acs->any.unk_5C = 0;
            acs->stateTimer = acs->duration;
            acs->state = AC_STATE_ACTIVE;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);

            // meter can drain if it hasn't been fully filled
            if (!acs->isMeterFilled) {
                if (acs->statusChance != 0) {
                    cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals];
                    acs->meterFillLevel -= GET_DRAIN_RATE(acs->meterFillLevel / cutoff);
                    if (acs->meterFillLevel < 0) {
                        acs->meterFillLevel = 0;
                    }
                } else {
                    acs->meterFillLevel -= 10;
                    if (acs->meterFillLevel < 0) {
                        acs->meterFillLevel = 0;
                    }
                }
            }

            // step back two frames in the input buffer
            bufferPos = battleStatus->inputBufferPos;
            bufferPos -= 2;
            if (bufferPos < 0) {
                bufferPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
            }

            buttonsPushed = 0;

            // get combined input during the last two frames
            for (i = 1; i >= 0; i--) {
                if (bufferPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                    bufferPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                }
                buttonsPushed |= battleStatus->pushInputBuffer[bufferPos];
                bufferPos++;
            }

            buttonsAB = BUTTON_A | BUTTON_B;
            if ((buttonsPushed & buttonsAB) == buttonsAB) {
                if (acs->statusChance != 0) {
                    s32 amt;

                    amt = SCALE_BY_PCT(METER_FILL_TICK, acs->statusChance);
                    amt = SCALE_BY_PCT(amt, battleStatus->actionCmdDifficultyTable[acs->difficulty]);

                    // Perplexing reuse of buttonsPushed here, but it fixes register allocation. Likely another
                    // subexpression from above can be put into a variable and reused instead.
                    //
                    // TODO: Find a way to avoid reusing buttonsPushed.
                    buttonsPushed = amt;

                    acs->meterFillLevel += buttonsPushed;
                } else {
                    acs->meterFillLevel += ONE_PCT_MASH;

                    if (acs->meterFillLevel >= 5 * ONE_PCT_MASH) {
                        acs->meterFillLevel = 5 * ONE_PCT_MASH;
                    }
                }

                // step back two frames in the input buffer
                bufferPos = battleStatus->inputBufferPos;
                bufferPos -= 2;
                if (bufferPos < 0) {
                    bufferPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
                }

                // clear buffer to be ready for the next input
                for (i = 1; i >= 0; i--) {
                    if (bufferPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        bufferPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }
                    battleStatus->pushInputBuffer[bufferPos] = 0;
                    bufferPos++;
                }
            }

            // handle meter reaching 100%
            if (acs->meterFillLevel > MAX_MASH_UNITS) {
                acs->meterFillLevel = MAX_MASH_UNITS;
                acs->isMeterFilled = true;
                hid = acs->hudElemIDs[HIDX_100_PCT];
                hud_element_set_render_pos(hid, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionProgress = acs->meterFillLevel / ONE_PCT_MASH;

            if (acs->stateTimer != 0) {
                acs->stateTimer--;
                break;
            }

            // Again, reusing buttonsPushed specifically for reg-alloc. See above.
            //
            // TODO: Find a way to avoid reusing buttonsPushed.
            buttonsPushed = acs->meterFillLevel;
            if (acs->statusChance == 0) {
                buttonsPushed = 0;
            }

            if (buttonsPushed == 0) {
                battleStatus->actionQuality = AC_QUALITY_FAILED;
            } else {
                battleStatus->actionQuality = buttonsPushed / ONE_PCT_MASH;
            }

            // a good result is filling the meter over halfway to the second-highest interval
            cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals - 1];
            if (battleStatus->actionProgress <= cutoff / 2) {
                battleStatus->actionResult = ACTION_RESULT_METER_BELOW_HALF;
            } else {
                battleStatus->actionResult = ACTION_RESULT_SUCCESS;
            }

            if (battleStatus->actionQuality == 100) {
                // only count 100% fill as success for this action command
                increment_action_command_success_count();
            }

            btl_set_popup_duration(POPUP_MSG_OFF);
            acs->stateTimer = 5;
            acs->state = AC_STATE_DISPOSE;
            break;
        case AC_STATE_DISPOSE:
            if (acs->statusChance == 0) {
                acs->meterFillLevel -= ONE_PCT_MASH;
                if (acs->meterFillLevel < 0) {
                    acs->meterFillLevel = 0;
                }
            }

            if (acs->stateTimer != 0) {
                acs->stateTimer--;
                break;
            }
            action_command_free();
            break;
    }
}

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hudX, hudY;
    HudElemID hid;

    hud_element_draw_clipped(acs->hudElemIDs[HIDX_A_BUTTON]);
    hud_element_draw_clipped(acs->hudElemIDs[HIDX_B_BUTTON]);

    hid = acs->hudElemIDs[HIDX_METER];
    hud_element_draw_clipped(hid);
    hud_element_get_render_pos(hid, &hudX, &hudY);

    if (!acs->isMeterFilled) {
        draw_mash_meter_multicolor(hudX, hudY, acs->meterFillLevel / ONE_PCT_MASH);
    } else {
        draw_mash_meter_blink(hudX, hudY, acs->meterFillLevel / ONE_PCT_MASH);
    }

    hud_element_draw_clipped(acs->hudElemIDs[HIDX_100_PCT]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_A_BUTTON]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_METER]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_B_BUTTON]);
    hud_element_free(gActionCommandStatus.hudElemIDs[HIDX_100_PCT]);
}
