#include "common.h"
#include "audio/public.h"
#include "battle/action_cmd.h"

//TODO action command
#define NAMESPACE action_command_mega_shock

s32 D_802A9930_42E340[AC_DIFFICULTY_LEN] = { 0, 25, 50, 75, 75, 0, 0, 0 };

extern s32 actionCmdTableMegaShock[];

API_CALLABLE(N(init)) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 elementID;

    battleStatus->unk_82 = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTableMegaShock;
    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }
    action_command_init_status();

    acs->actionCommandID = ACTION_COMMAND_MEGA_SHOCK;
    acs->state = AC_STATE_INIT;
    acs->hudPrepareTime = 30;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    acs->isBarFilled = FALSE;
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    elementID = hud_element_create(&HES_AButton);
    acs->hudElements[0] = elementID;
    hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(elementID, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(elementID, 0);

    elementID = hud_element_create(&HES_BButton);
    acs->hudElements[2] = elementID;
    hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(elementID, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(elementID, 0);

    elementID = hud_element_create(&HES_BlueMeter);
    acs->hudElements[1] = elementID;
    hud_element_set_render_pos(elementID, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(elementID, 0);
    hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    elementID = hud_element_create(&HES_100pct);
    acs->hudElements[4] = elementID;
    hud_element_set_render_pos(elementID, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(elementID, 0);
    hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    Bytecode* readPos = script->ptrReadPos;
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    s16 arg;
    ApiStatus result;

    if (battleStatus->actionCommandMode != AC_MODE_NOT_LEARNED) {
        action_command_init_status();

        acs->prepareTime = evt_get_variable(script, *readPos++);
        acs->duration = evt_get_variable(script, *readPos++);
        arg = evt_get_variable(script, *readPos++);

        acs->difficulty = arg;
        acs->difficulty = adjust_action_command_difficulty(arg);
        acs->targetWeakness = evt_get_variable(script, *readPos++);
        acs->wrongButtonPressed = FALSE;
        acs->barFillLevel = 0;
        acs->barFillWidth = 0;

        battleStatus->actionSuccess = 0;
        battleStatus->actionResult = ACTION_RESULT_FAIL;
        acs->state = AC_STATE_START;
        battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

        increment_action_command_attempt_count();
        result = ApiStatus_DONE2;
    } else {
        battleStatus->actionSuccess = 0;
        result = ApiStatus_DONE2;
    }

    return result;
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    s32 buttonsPushed;
    s32 frameCount;
    s32 buttonsAB;
    s32 bufferPos;
    s32 hid;
    s32 mashMeterIndex;
    s32 mashMeterCutoff;
    s8 adjustedFillLevel;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);

            hid = acs->hudElements[0];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);

            hid = acs->hudElements[2];
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hid, 255);

            hid = acs->hudElements[1];
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

            hud_element_set_render_pos(acs->hudElements[0], acs->hudPosX - 17, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[2], acs->hudPosX + 23, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[1], acs->hudPosX, acs->hudPosY + 28);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                break;
            }
            hud_element_set_script(acs->hudElements[0], &HES_MashAButton);
            hud_element_set_script(acs->hudElements[2], &HES_MashBButton1);
            acs->barFillLevel = 0;
            acs->any.unk_5C = 0;
            acs->frameCounter = acs->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            acs->state = AC_STATE_ACTIVE;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (!acs->isBarFilled) {
                s16 newFillLevel;

                if (acs->targetWeakness != 0) {
                    s8 mashMeterIntervals = acs->mashMeterNumIntervals;
                    s16* mashMeterCutoffs = acs->mashMeterCutoffs;
                    s32 index;

                    mashMeterCutoff = mashMeterCutoffs[mashMeterIntervals];
                    index = acs->barFillLevel / mashMeterCutoff / 20;
                    newFillLevel = acs->barFillLevel - D_802A9930_42E340[index];
                } else {
                    newFillLevel = acs->barFillLevel - 10;
                }

                acs->barFillLevel = newFillLevel;
                if (acs->barFillLevel < 0) {
                    acs->barFillLevel = 0;
                }
            }

            bufferPos = battleStatus->inputBufferPos;
            bufferPos -= 2;
            if (bufferPos < 0) {
                bufferPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
            }

            buttonsPushed = 0;
            frameCount = 1;

            while (frameCount >= 0) {
                if (bufferPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                    bufferPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                }

                buttonsPushed |= battleStatus->pushInputBuffer[bufferPos++];
                frameCount--;
            }

            buttonsAB = BUTTON_A | BUTTON_B;
            if ((buttonsPushed & buttonsAB) == buttonsAB) {
                if (acs->targetWeakness != 0) {
                    s32 fillLevel;

                    fillLevel = acs->targetWeakness * 780;
                    fillLevel = fillLevel / 100 * battleStatus->actionCmdDifficultyTable[acs->difficulty];

                    // Perplexing reuse of buttonsPushed here, but it fixes register allocation. Likely another
                    // subexpression from above can be put into a variable and reused instead.
                    //
                    // TODO: Find a way to avoid reusing buttonsPushed.
                    buttonsPushed = fillLevel / 100;

                    acs->barFillLevel += buttonsPushed;
                } else {
                    acs->barFillLevel += ONE_PCT_MASH;

                    if (acs->barFillLevel >= 500) {
                        acs->barFillLevel = 500;
                    }
                }

                bufferPos = battleStatus->inputBufferPos;
                bufferPos -= 2;
                if (bufferPos < 0) {
                    bufferPos += ARRAY_COUNT(battleStatus->pushInputBuffer);
                }

                frameCount = 1;
                while (frameCount >= 0) {
                    if (bufferPos >= ARRAY_COUNT(battleStatus->pushInputBuffer)) {
                        bufferPos -= ARRAY_COUNT(battleStatus->pushInputBuffer);
                    }

                    battleStatus->pushInputBuffer[bufferPos++] = 0;
                    frameCount--;
                }
            }

            if (acs->barFillLevel > MAX_MASH_UNITS) {
                acs->barFillLevel = MAX_MASH_UNITS;
                acs->isBarFilled = TRUE;
                hid = acs->hudElements[4];
                hud_element_set_render_pos(hid, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            adjustedFillLevel = acs->barFillLevel / ONE_PCT_MASH;

            battleStatus->actionQuality = adjustedFillLevel;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, adjustedFillLevel * 12);

            if (acs->frameCounter == 0) {
                s16 threshold;

                // Again, reusing buttonsPushed specifically for reg-alloc. See above.
                //
                // TODO: Find a way to avoid reusing buttonsPushed.
                buttonsPushed = acs->barFillLevel;
                if (acs->targetWeakness == 0) {
                    buttonsPushed = 0;
                }

                if (buttonsPushed == 0) {
                    battleStatus->actionSuccess = -1;
                } else {
                    battleStatus->actionSuccess = buttonsPushed / ONE_PCT_MASH;
                }

                mashMeterIndex = acs->mashMeterNumIntervals - 1;
                mashMeterCutoff = acs->mashMeterCutoffs[mashMeterIndex];
                threshold = mashMeterCutoff / 2;

                if (battleStatus->actionQuality <= threshold) {
                    battleStatus->actionResult = ACTION_RESULT_MINUS_4;
                } else {
                    battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                }

                if (battleStatus->actionSuccess == 100) {
                    increment_action_command_success_count();
                }

                sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
                btl_set_popup_duration(POPUP_MSG_OFF);
                acs->frameCounter = 5;
                acs->state = AC_STATE_DISPOSE;
            } else {
                acs->frameCounter--;
            }
            break;
        case AC_STATE_DISPOSE:
            if (acs->targetWeakness == 0) {
                acs->barFillLevel -= ONE_PCT_MASH;
                if (acs->barFillLevel < 0) {
                    acs->barFillLevel = 0;
                }
            }

            if (acs->frameCounter != 0) {
                acs->frameCounter--;
            } else {
                action_command_free();
            }
            break;
    }
}

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hid;
    s32 hudX;
    s32 hudY;

    hud_element_draw_clipped(acs->hudElements[0]);
    hud_element_draw_clipped(acs->hudElements[2]);

    hid = acs->hudElements[1];
    hud_element_draw_clipped(hid);
    hud_element_get_render_pos(hid, &hudX, &hudY);

    if (!acs->isBarFilled) {
        draw_mash_meter_multicolor(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH);
    } else {
        draw_mash_meter_blink(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH);
    }

    hud_element_draw_clipped(acs->hudElements[4]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
}
