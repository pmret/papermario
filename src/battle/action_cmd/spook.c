#include "common.h"
#include "audio/public.h"
#include "battle/action_cmd.h"

//TODO action command
#define NAMESPACE action_command_spook

s32 D_802A9920_430940[AC_DIFFICULTY_LEN] = { 0, 25, 50, 75, 75, 0, 0, 0 };

extern s32 actionCmdTableSpook[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hid;

    battleStatus->unk_82 = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTableSpook;
    battleStatus->actionResult = ACTION_RESULT_NONE;
    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }
    action_command_init_status();
    acs->actionCommandID = ACTION_COMMAND_SPOOK;
    acs->showHud = TRUE;
    acs->hudPrepareTime = 30;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    acs->isBarFilled = FALSE;
    battleStatus->actionSuccess = 0;
    battleStatus->actionQuality = 0;
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    hid = hud_element_create(&HES_StickNeutral);
    acs->hudElements[0] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_BlueMeter);
    acs->hudElements[1] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hid = hud_element_create(&HES_100pct);
    acs->hudElements[2] = hid;
    hud_element_set_render_pos(hid, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hid, 0);
    hud_element_set_flags(hid, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    return ApiStatus_DONE2;
}

#include "common/MashCommandStart.inc.c"

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hid;
    s32 cutoff;
    s32 fillLevel;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);

            hid = acs->hudElements[0];
            hud_element_set_alpha(hid, 255);
            if (acs->showHud) {
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            hid = acs->hudElements[1];
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
            hud_element_set_render_pos(acs->hudElements[0], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[1], acs->hudPosX, acs->hudPosY + 28);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }
            hud_element_set_script(acs->hudElements[0], &HES_StickMashLeft);
            acs->barFillLevel = 0;
            battleStatus->actionQuality = 0;
            acs->any.unk_5C = 0;
            acs->frameCounter = acs->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            acs->state = AC_STATE_ACTIVE;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (!acs->isBarFilled) {
                if (acs->targetWeakness != 0) {
                    cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals];

                    acs->barFillLevel -= D_802A9920_430940[acs->barFillLevel / cutoff / 20];
                    if (acs->barFillLevel < 0) {
                        acs->barFillLevel = 0;
                    }
                } else {
                    acs->barFillLevel -= 10;
                    if (acs->barFillLevel < 0) {
                        acs->barFillLevel = 0;
                    }
                }

                 if (!acs->isBarFilled) {
                    if (acs->targetWeakness != 0) {

                        if (battleStatus->curButtonsDown & BUTTON_STICK_LEFT) {
                            acs->any.unk_5C = TRUE;
                        }

                        if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT) && acs->any.unk_5C) {
                            s32 a = battleStatus->actionCmdDifficultyTable[acs->difficulty];
                            s32 b = acs->targetWeakness * 850;

                            acs->barFillLevel += (a * b) / (100 * 100);
                            acs->any.unk_5C = 0;
                        }

                        if (battleStatus->curButtonsPressed & BUTTON_STICK_RIGHT) {
                            s32 a = battleStatus->actionCmdDifficultyTable[acs->difficulty];
                            s32 b = acs->targetWeakness * 850;

                            acs->barFillLevel -= (a * b) / (100 * 100);
                        }
                    } else {
                        if (battleStatus->curButtonsDown & BUTTON_STICK_LEFT) {
                            acs->any.unk_5C = TRUE;
                        }

                        if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT) && acs->any.unk_5C) {
                            acs->barFillLevel += ONE_PCT_MASH;
                            if (acs->barFillLevel >= 5 * ONE_PCT_MASH) {
                                acs->barFillLevel = 5 * ONE_PCT_MASH;
                            }
                            acs->any.unk_5C = 0;
                        }

                        if (battleStatus->curButtonsPressed & BUTTON_STICK_RIGHT) {
                            acs->barFillLevel -= ONE_PCT_MASH;
                        }
                    }
                }
            }

            if (acs->barFillLevel < 0) {
                acs->barFillLevel = 0;
            }
            if (acs->barFillLevel > MAX_MASH_UNITS) {
                acs->barFillLevel = MAX_MASH_UNITS;
                acs->isBarFilled = TRUE;
                hid = acs->hudElements[2];
                hud_element_set_render_pos(hid, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionQuality = acs->barFillLevel / ONE_PCT_MASH;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, battleStatus->actionQuality * 12);

            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                return;
            }

            fillLevel = acs->barFillLevel;
            if (acs->targetWeakness == 0) {
                fillLevel = 0;
            }

            if (fillLevel == 0) {
                battleStatus->actionSuccess = -1;
            } else {
                battleStatus->actionSuccess = fillLevel / ONE_PCT_MASH;

            }

            cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals - 1];
            if (battleStatus->actionSuccess > cutoff) {
                battleStatus->actionResult = ACTION_RESULT_SUCCESS;
            } else {
                battleStatus->actionResult = ACTION_RESULT_MINUS_2;
            }

            if (battleStatus->actionSuccess == 100) {
                increment_action_command_success_count();
            }
            btl_set_popup_duration(POPUP_MSG_OFF);
            sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
            acs->frameCounter = 5;
            acs->state = AC_STATE_DISPOSE;
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
                return;
            }
            action_command_free();
            break;
    }
}

#include "common/MashCommandDraw.inc.c"

#include "common/MashCommandFree.inc.c"
