#include "common.h"
#include "audio/public.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_mega_shock

s32 D_802A9930_42E340[] = { 0, 25, 50, 75, 75, 0, 0, 0 };

extern s32 actionCmdTableMegaShock[];

API_CALLABLE(N(init)) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 elementID;

    battleStatus->unk_82 = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTableMegaShock;
    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }
    action_command_init_status();

    actionCommandStatus->actionCommandID = ACTION_COMMAND_MEGA_SHOCK;
    actionCommandStatus->state = 0;
    actionCommandStatus->hudPrepareTime = 30;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->barFillWidth = 0;
    actionCommandStatus->isBarFilled = FALSE;
    actionCommandStatus->hudPosX = -48;
    actionCommandStatus->hudPosY = 80;

    elementID = hud_element_create(&HES_AButton);
    actionCommandStatus->hudElements[0] = elementID;
    hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(elementID, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(elementID, 0);

    elementID = hud_element_create(&HES_BButton);
    actionCommandStatus->hudElements[2] = elementID;
    hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(elementID, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(elementID, 0);

    elementID = hud_element_create(&HES_BlueMeter);
    actionCommandStatus->hudElements[1] = elementID;
    hud_element_set_render_pos(elementID, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 0x1C);
    hud_element_set_render_depth(elementID, 0);
    hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    elementID = hud_element_create(&HES_100pct);
    actionCommandStatus->hudElements[4] = elementID;
    hud_element_set_render_pos(elementID, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 0x1C);
    hud_element_set_render_depth(elementID, 0);
    hud_element_set_flags(elementID, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    Bytecode* readPos = script->ptrReadPos;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    s16 arg;
    ApiStatus result;

    if (battleStatus->actionCommandMode != ACTION_COMMAND_MODE_NOT_LEARNED) {
        action_command_init_status();

        actionCommandStatus->prepareTime = evt_get_variable(script, *readPos++);
        actionCommandStatus->duration = evt_get_variable(script, *readPos++);
        arg = evt_get_variable(script, *readPos++);

        actionCommandStatus->difficulty = arg;
        actionCommandStatus->difficulty = adjust_action_command_difficulty(arg);
        actionCommandStatus->targetWeakness = evt_get_variable(script, *readPos++);
        actionCommandStatus->wrongButtonPressed = FALSE;
        actionCommandStatus->barFillLevel = 0;
        actionCommandStatus->barFillWidth = 0;

        battleStatus->actionSuccess = 0;
        battleStatus->actionResult = ACTION_RESULT_FAIL;
        actionCommandStatus->state = 10;
        battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

        func_80269118();
        result = ApiStatus_DONE2;
    } else {
        battleStatus->actionSuccess = 0;
        result = ApiStatus_DONE2;
    }

    return result;
}

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
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            actionCommandStatus->state = 11;
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
                    newFillLevel = actionCommandStatus->barFillLevel - D_802A9930_42E340[index];
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

                    fillLevel = actionCommandStatus->targetWeakness * 780;
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
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, adjustedFillLevel * 12);

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

                sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
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

    s32 hudElement;
    s32 hudElementX;
    s32 hudElementY;

    hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[2]);

    hudElement = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(hudElement);
    hud_element_get_render_pos(hudElement, &hudElementX, &hudElementY);

    if (!actionCommandStatus->isBarFilled) {
        draw_mash_meter_multicolor(hudElementX, hudElementY, actionCommandStatus->barFillLevel / 100);
    } else {
        draw_mash_meter_blink(hudElementX, hudElementY, actionCommandStatus->barFillLevel / 100);
    }

    hud_element_draw_clipped(actionCommandStatus->hudElements[4]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
}
