#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_hammer

extern s32 actionCmdTableHammer[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    battleStatus->unk_82 = 1;
    battleStatus->actionCmdDifficultyTable = actionCmdTableHammer;
    battleStatus->actionResult = ACTION_RESULT_FAIL;

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_SMASH;
    actionCommandStatus->hudPosX = -48;
    actionCommandStatus->state = 0;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->hudPosY = 96;

    id = hud_element_create(&HES_TimingBar1Chance);
    actionCommandStatus->hudElements[0] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 10);

    id = hud_element_create(&HES_TimingWait);
    actionCommandStatus->hudElements[1] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_TimingCharge4a);
    actionCommandStatus->hudElements[2] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_TimingCharge4b);
    actionCommandStatus->hudElements[3] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_TimingCharge4c);
    actionCommandStatus->hudElements[4] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_StickHoldLeft);
    actionCommandStatus->hudElements[5] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);

    id = hud_element_create(&HES_RightOn);
    actionCommandStatus->hudElements[6] = id;
    hud_element_set_flags(id, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(id, actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
    hud_element_set_render_depth(id, 0);
    hud_element_set_alpha(id, 255);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        battleStatus->actionQuality = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    actionCommandStatus->prepareTime = evt_get_variable(script, *args++);
    actionCommandStatus->duration = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = evt_get_variable(script, *args);
    actionCommandStatus->difficulty = adjust_action_command_difficulty(actionCommandStatus->difficulty);
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->playHammerSounds = TRUE;
    if (actionCommandStatus->prepareTime < 0) {
        actionCommandStatus->prepareTime = 0;
        actionCommandStatus->playHammerSounds = FALSE;
    }

    actionCommandStatus->hammerMissedStart = FALSE;
    battleStatus->actionSuccess = 0;
    battleStatus->actionQuality = 0;
    battleStatus->actionResult = ACTION_RESULT_FAIL;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    func_80269118();
    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s32 id;
    f32 temp_f20;
    s32 phi_s0;
    s32 new_var;
    s32 a;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);

            id = actionCommandStatus->hudElements[0];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[1];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[2];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[3];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[4];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[5];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            hud_element_set_alpha(id, 255);

            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);
            actionCommandStatus->hudPosX += 20;
            if (actionCommandStatus->hudPosX > 50) {
                actionCommandStatus->hudPosX = 50;
            }
            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudPosX + 21, actionCommandStatus->hudPosY - 3);
            hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudPosX + 5, actionCommandStatus->hudPosY + 1);
            hud_element_set_render_pos(actionCommandStatus->hudElements[3], actionCommandStatus->hudPosX - 7, actionCommandStatus->hudPosY + 1);
            hud_element_set_render_pos(actionCommandStatus->hudElements[4], actionCommandStatus->hudPosX - 19, actionCommandStatus->hudPosY + 1);
            hud_element_set_render_pos(actionCommandStatus->hudElements[5], actionCommandStatus->hudPosX, actionCommandStatus->hudPosY - 23);
            if (actionCommandStatus->autoSucceed != 0) {
                id = actionCommandStatus->hudElements[6];
                hud_element_set_render_pos(id, actionCommandStatus->hudPosX + 50, actionCommandStatus->hudPosY);
                if (actionCommandStatus->showHud) {
                    hud_element_clear_flags(id, 2);
                    break;
                }
            }
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->prepareTime < 15) {
                hud_element_set_alpha(actionCommandStatus->hudElements[0], 255);
                hud_element_set_alpha(actionCommandStatus->hudElements[1], 255);
                hud_element_set_alpha(actionCommandStatus->hudElements[2], 255);
                hud_element_set_alpha(actionCommandStatus->hudElements[3], 255);
                hud_element_set_alpha(actionCommandStatus->hudElements[4], 255);
                hud_element_set_alpha(actionCommandStatus->hudElements[5], 255);
            }

            if (actionCommandStatus->prepareTime != 0) {
                actionCommandStatus->prepareTime--;
                return;
            }

            actionCommandStatus->frameCounter = 0;
            if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT) && battleStatus->actionCommandMode < ACTION_COMMAND_MODE_TUTORIAL) {
                actionCommandStatus->hammerMissedStart = TRUE;
            }
            actionCommandStatus->state = 11;
        case 11:
            btl_set_popup_duration(99);

            if (battleStatus->actionCommandMode <= ACTION_COMMAND_MODE_TUTORIAL_BLOCK) {
                return;
            }

            phi_s0 = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty];
            new_var = phi_s0 + 2;
            temp_f20 = (actionCommandStatus->duration - new_var) / 3;

            if (actionCommandStatus->frameCounter < temp_f20) {
                hud_element_set_script(actionCommandStatus->hudElements[4], &HES_TimingCharge3);
                battleStatus->actionQuality = 0;
                if (actionCommandStatus->frameCounter == 0 && actionCommandStatus->playHammerSounds) {
                    sfx_play_sound(SOUND_TIMING_BAR_TICK);
                }
            } else if (actionCommandStatus->frameCounter < temp_f20 * 2) {
                hud_element_set_script(actionCommandStatus->hudElements[3], &HES_TimingCharge2);
                battleStatus->actionQuality = 1;
                if (actionCommandStatus->frameCounter == temp_f20) {
                    if (actionCommandStatus->playHammerSounds) {
                        sfx_play_sound(SOUND_TIMING_BAR_TICK);
                    }
                }
            } else if (actionCommandStatus->frameCounter < temp_f20 * 3.0f) {
                hud_element_set_script(actionCommandStatus->hudElements[2], &HES_TimingCharge1);
                battleStatus->actionQuality = 2;
                if (actionCommandStatus->frameCounter == temp_f20 * 2) {
                    if (actionCommandStatus->playHammerSounds) {
                        sfx_play_sound(SOUND_TIMING_BAR_TICK);
                    }
                }
            }

            if (actionCommandStatus->frameCounter == (~phi_s0 + actionCommandStatus->duration)) {
                battleStatus->actionQuality = 3;
                hud_element_set_script(actionCommandStatus->hudElements[1], &HES_TimingReady);
                hud_element_set_script(actionCommandStatus->hudElements[5], &HES_StickTapNeutral);
                if (actionCommandStatus->playHammerSounds) {
                    sfx_play_sound(SOUND_TIMING_BAR_GO);
                }
                if (actionCommandStatus->autoSucceed != 0 && actionCommandStatus->autoSucceed != 2) {
                    actionCommandStatus->autoSucceed = 2;
                    actionCommandStatus->frameCounter = actionCommandStatus->duration - 4;
                }
            }

            a = actionCommandStatus->duration - actionCommandStatus->frameCounter;
            phi_s0 = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] - a + 3;
            if (phi_s0 < 0) {
                phi_s0 = 0;
            }

            if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT) &&
                phi_s0 == 0 &&
                actionCommandStatus->autoSucceed == 0 &&
                battleStatus->actionCommandMode < ACTION_COMMAND_MODE_TUTORIAL)
            {
                battleStatus->actionSuccess = -1;
                battleStatus->actionResult = ACTION_RESULT_EARLY;
                action_command_free();
            } else {
                s32 i;
                s32 bufferPos;

                bufferPos = battleStatus->inputBufferPos;
                bufferPos -= phi_s0;
                if (bufferPos < 0) {
                    bufferPos += ARRAY_COUNT(battleStatus->holdInputBuffer);
                }

                if (battleStatus->actionSuccess == 0) {
                    for (i = 0; i < phi_s0; i++, bufferPos++) {
                        if (bufferPos >= ARRAY_COUNT(battleStatus->holdInputBuffer)) {
                            bufferPos -= ARRAY_COUNT(battleStatus->holdInputBuffer);
                        }

                        if (!(battleStatus->holdInputBuffer[bufferPos] & BUTTON_STICK_LEFT) ||
                            actionCommandStatus->autoSucceed != 0)
                        {
                            battleStatus->actionSuccess = 1;
                            battleStatus->actionResult = ACTION_RESULT_SUCCESS;
                            gBattleStatus.flags1 |= BS_FLAGS1_2000;
                        }
                    }
                }

                if (battleStatus->actionCommandMode < ACTION_COMMAND_MODE_TUTORIAL || actionCommandStatus->frameCounter != actionCommandStatus->duration) {
                    actionCommandStatus->frameCounter++;
                    if (actionCommandStatus->duration < actionCommandStatus->frameCounter) {
                        if (battleStatus->actionSuccess == 0) {
                            battleStatus->actionSuccess = -1;
                        }

                        if (battleStatus->actionSuccess == 1) {
                            func_80269160();
                        }

                        btl_set_popup_duration(0);
                        actionCommandStatus->frameCounter = 5;
                        actionCommandStatus->state = 12;
                    }
                }
            }
            break;
        case 12:
            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                return;
            }
            action_command_free();
            break;
    }
}

void N(draw)(void) {
    hud_element_draw_clipped(gActionCommandStatus.hudElements[0]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[1]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[2]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[3]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[4]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[5]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[6]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
    hud_element_free(gActionCommandStatus.hudElements[5]);
    hud_element_free(gActionCommandStatus.hudElements[6]);
}
