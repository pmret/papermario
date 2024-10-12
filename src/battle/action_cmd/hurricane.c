#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_hurricane

s32 D_802A98E0_42FFC0[8] = { 0, 25, 50, 75, 75, 0, 0, 0 };

extern s32 actionCmdTableHurricane[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    battleStatus->unk_82 = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTableHurricane;
    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    actionCommandStatus->actionCommandID = ACTION_COMMAND_HURRICANE;
    actionCommandStatus->hudPrepareTime = 30;
    actionCommandStatus->hudPosX = -48;
    actionCommandStatus->state = AC_STATE_INIT;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    actionCommandStatus->isBarFilled = FALSE;
    actionCommandStatus->hudPosY = 80;

    id = hud_element_create(&HES_AButton);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_BButton);
    actionCommandStatus->hudElements[2] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_BlueMeter);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(id, 0);
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    id = hud_element_create(&HES_100pct);
    actionCommandStatus->hudElements[4] = id;
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
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
    acs->targetWeakness = evt_get_variable(script, *args++);

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

// Almost identical to action_command_mega_shock_update (mega_shock)
void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    s32 buttonsPushed;
    s32 frameCount;
    s32 buttonsAB;
    s32 bufferPos;
    s32 hudElement;
    s32 mashMeterIndex;
    s32 mashMeterCutoff;
    s8 adjustedFillLevel;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(99);

            hudElement = acs->hudElements[0];
            if (acs->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hudElement, 255);

            hudElement = acs->hudElements[2];
            if (acs->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hudElement, 255);

            hudElement = acs->hudElements[1];
            hud_element_set_alpha(hudElement, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            acs->state = 1;
            break;
        case AC_STATE_APPEAR:
            btl_set_popup_duration(99);
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
            btl_set_popup_duration(99);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                break;
            }
            hud_element_set_script(acs->hudElements[0], &HES_MashAButton);
            hud_element_set_script(acs->hudElements[2], &HES_MashBButton1);
            acs->barFillLevel = 0;
            acs->any.unk_5C = 0;
            acs->frameCounter = acs->duration;
            acs->state = 11;
            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(99);
            if (!acs->isBarFilled) {
                s16 newFillLevel;

                if (acs->targetWeakness != 0) {
                    s8 mashMeterIntervals = acs->mashMeterIntervals;
                    s16* mashMeterCutoffs = acs->mashMeterCutoffs;
                    s32 index;

                    mashMeterCutoff = mashMeterCutoffs[mashMeterIntervals];
                    index = acs->barFillLevel / mashMeterCutoff / 20;
                    newFillLevel = acs->barFillLevel - D_802A98E0_42FFC0[index];
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

                    fillLevel = acs->targetWeakness * 650;
                    fillLevel = fillLevel / 100 * battleStatus->actionCmdDifficultyTable[acs->difficulty];

                    // Perplexing reuse of buttonsPushed here, but it fixes register allocation. Likely another
                    // subexpression from above can be put into a variable and reused instead.
                    //
                    // TODO: Find a way to avoid reusing buttonsPushed.
                    buttonsPushed = fillLevel / 100;

                    acs->barFillLevel += buttonsPushed;
                } else {
                    acs->barFillLevel += 100;

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

            if (acs->barFillLevel > 10000) {
                hudElement = acs->hudElements[4];
                acs->barFillLevel = 10000;
                acs->isBarFilled = TRUE;
                hud_element_set_render_pos(hudElement, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            adjustedFillLevel = acs->barFillLevel / 100;

            battleStatus->actionQuality = adjustedFillLevel;

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
                    battleStatus->actionSuccess = buttonsPushed / 100;
                }

                mashMeterIndex = acs->mashMeterIntervals - 1;
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

                btl_set_popup_duration(0);
                acs->frameCounter = 5;
                acs->state = 12;
            } else {
                acs->frameCounter -= 1;
            }
            break;
        case AC_STATE_DISPOSE:
            if (acs->targetWeakness == 0) {
                acs->barFillLevel -= 100;
                if (acs->barFillLevel < 0) {
                    acs->barFillLevel = 0;
                }
            }

            if (acs->frameCounter != 0) {
                acs->frameCounter -= 1;
            } else {
                action_command_free();
            }
            break;
    }
}

void N(draw)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 hudY;
    s32 hudX;
    s32 id;

    hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[2]);

    id = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(id);
    hud_element_get_render_pos(id, &hudX, &hudY);

    if (!actionCommandStatus->isBarFilled) {
        draw_mash_meter_multicolor(hudX, hudY, actionCommandStatus->barFillLevel / 100);
    } else {
        draw_mash_meter_blink(hudX, hudY, actionCommandStatus->barFillLevel / 100);
    }

    hud_element_draw_clipped(actionCommandStatus->hudElements[4]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
}
