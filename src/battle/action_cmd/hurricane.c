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
    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    actionCommandStatus->actionCommandID = ACTION_COMMAND_HURRICANE;
    actionCommandStatus->hudPrepareTime = 30;
    actionCommandStatus->hudPosX = -48;
    actionCommandStatus->state = 0;
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
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    actionCommandStatus->prepareTime = evt_get_variable(script, *args++);
    actionCommandStatus->duration = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = adjust_action_command_difficulty(actionCommandStatus->difficulty);
    actionCommandStatus->targetWeakness = evt_get_variable(script, *args++);

    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->actionResult = ACTION_RESULT_FAIL;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

    func_80269118();

    return ApiStatus_DONE2;
}

// Almost identical to action_command_mega_shock_update (mega_shock)
void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    s32 buttonsPushed;
    s32 frameCount;
    s32 buttonsAB;
    s32 bufferPos;
    s32 hudElement;
    s32 mashMeterIndex;
    s32 mashMeterCutoff;
    s8 adjustedFillLevel;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);

            hudElement = actionCommandStatus->hudElements[0];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hudElement, 255);

            hudElement = actionCommandStatus->hudElements[2];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(hudElement, 255);

            hudElement = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(hudElement, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);
            if (actionCommandStatus->hudPrepareTime != 0) {
                actionCommandStatus->hudPrepareTime--;
                break;
            }

            actionCommandStatus->hudPosX += 20;
            if (actionCommandStatus->hudPosX > 50) {
                actionCommandStatus->hudPosX = 50;
            }

            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudPosX - 17,
                actionCommandStatus->hudPosY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudPosX + 23,
                actionCommandStatus->hudPosY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudPosX,
                actionCommandStatus->hudPosY + 28);
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->prepareTime != 0) {
                actionCommandStatus->prepareTime--;
                break;
            }
            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_MashAButton);
            hud_element_set_script(actionCommandStatus->hudElements[2], &HES_MashBButton1);
            actionCommandStatus->barFillLevel = 0;
            actionCommandStatus->unk_5C = 0;
            actionCommandStatus->frameCounter = actionCommandStatus->duration;
            actionCommandStatus->state = 11;
            // fallthrough
        case 11:
            btl_set_popup_duration(99);
            if (!actionCommandStatus->isBarFilled) {
                s16 newFillLevel;

                if (actionCommandStatus->targetWeakness != 0) {
                    s8 mashMeterIntervals = actionCommandStatus->mashMeterIntervals;
                    s16* mashMeterCutoffs = actionCommandStatus->mashMeterCutoffs;
                    s32 index;

                    mashMeterCutoff = mashMeterCutoffs[mashMeterIntervals];
                    index = actionCommandStatus->barFillLevel / mashMeterCutoff / 20;
                    newFillLevel = actionCommandStatus->barFillLevel - D_802A98E0_42FFC0[index];
                } else {
                    newFillLevel = actionCommandStatus->barFillLevel - 10;
                }

                actionCommandStatus->barFillLevel = newFillLevel;
                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
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
                if (actionCommandStatus->targetWeakness != 0) {
                    s32 fillLevel;

                    fillLevel = actionCommandStatus->targetWeakness * 650;
                    fillLevel = fillLevel / 100 * battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty];

                    // Perplexing reuse of buttonsPushed here, but it fixes register allocation. Likely another
                    // subexpression from above can be put into a variable and reused instead.
                    //
                    // TODO: Find a way to avoid reusing buttonsPushed.
                    buttonsPushed = fillLevel / 100;

                    actionCommandStatus->barFillLevel += buttonsPushed;
                } else {
                    actionCommandStatus->barFillLevel += 100;

                    if (actionCommandStatus->barFillLevel >= 500) {
                        actionCommandStatus->barFillLevel = 500;
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

            if (actionCommandStatus->barFillLevel > 10000) {
                hudElement = actionCommandStatus->hudElements[4];
                actionCommandStatus->barFillLevel = 10000;
                actionCommandStatus->isBarFilled = TRUE;
                hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX + 50,
                    actionCommandStatus->hudPosY + 28);
                hud_element_clear_flags(hudElement, HUD_ELEMENT_FLAG_DISABLED);
            }

            adjustedFillLevel = actionCommandStatus->barFillLevel / 100;

            battleStatus->actionQuality = adjustedFillLevel;

            if (actionCommandStatus->frameCounter == 0) {
                s16 threshold;

                // Again, reusing buttonsPushed specifically for reg-alloc. See above.
                //
                // TODO: Find a way to avoid reusing buttonsPushed.
                buttonsPushed = actionCommandStatus->barFillLevel;
                if (actionCommandStatus->targetWeakness == 0) {
                    buttonsPushed = 0;
                }

                if (buttonsPushed == 0) {
                    battleStatus->actionSuccess = -1;
                } else {
                    battleStatus->actionSuccess = buttonsPushed / 100;
                }

                mashMeterIndex = actionCommandStatus->mashMeterIntervals - 1;
                mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[mashMeterIndex];
                threshold = mashMeterCutoff / 2;

                if (battleStatus->actionQuality <= threshold) {
                    battleStatus->actionResult = ACTION_RESULT_MINUS_4;
                } else {
                    battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                }

                if (battleStatus->actionSuccess == 100) {
                    func_80269160();
                }

                btl_set_popup_duration(0);
                actionCommandStatus->frameCounter = 5;
                actionCommandStatus->state = 12;
            } else {
                actionCommandStatus->frameCounter -= 1;
            }
            break;
        case 12:
            if (actionCommandStatus->targetWeakness == 0) {
                actionCommandStatus->barFillLevel -= 100;
                if (actionCommandStatus->barFillLevel < 0) {
                    actionCommandStatus->barFillLevel = 0;
                }
            }

            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter -= 1;
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
