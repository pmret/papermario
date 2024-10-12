#include "battle/battle.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_air_raid

s32 D_802A9970_429C90[] = { 0, 25, 50, 75, 75 };
s32 D_802A9984_429CA4[] = { 40, 70, 99, 200 };
s32 D_802A9994_429CB4[] = { 35, 60, 80, 99, 200 };
s32 D_802A99A8_429CC8[] = { 35, 35, 60, 80, 99, 200 };

extern s32 actionCmdTableAirRaid[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTableAirRaid;
    battleStatus->actionResult = ACTION_RESULT_NONE;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->actionCommandID = ACTION_COMMAND_AIR_RAID;
    acs->showHud = TRUE;
    acs->hudPrepareTime = 30;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    acs->isBarFilled = FALSE;
    battleStatus->actionSuccess = 0;
    acs->hudPosX = -48;
    acs->hudPosY = 80;

    hudElement = hud_element_create(&HES_StickNeutral);
    acs->hudElements[0] = hudElement;
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hudElement = hud_element_create(&HES_BlueMeter);
    acs->hudElements[1] = hudElement;
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hudElement = hud_element_create(&HES_100pct);
    acs->hudElements[2] = hudElement;
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    return ApiStatus_DONE2;
}

#include "common/MashCommandStart.inc.c"

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s32 cutoff;
    s32 id;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(99);

            id = acs->hudElements[0];
            hud_element_set_alpha(id, 255);
            if (acs->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            id = acs->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (acs->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            acs->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            btl_set_popup_duration(99);

            if (acs->hudPrepareTime != 0) {
                acs->hudPrepareTime--;
                return;
            }

            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }

            hud_element_set_render_pos(acs->hudElements[0], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[1], acs->hudPosX, acs->hudPosY + 28);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(99);

            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }

            hud_element_set_script(acs->hudElements[0], &HES_StickMashLeft);
            acs->barFillLevel = 0;
            battleStatus->unk_85 = 0;
            acs->any.unk_5C = 0;
            acs->frameCounter = acs->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            acs->state = AC_STATE_ACTIVE;
            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(99);
            if (!acs->isBarFilled) {
                cutoff = acs->mashMeterCutoffs[acs->mashMeterIntervals];

                acs->barFillLevel -= D_802A9970_429C90[acs->barFillLevel / cutoff / 20];
                if (acs->barFillLevel < 0) {
                    acs->barFillLevel = 0;
                }

                if (!acs->isBarFilled) {
                    if (battleStatus->curButtonsDown & BUTTON_STICK_LEFT) {
                        acs->any.unk_5C = 1;
                    }

                    if (!(battleStatus->curButtonsDown & BUTTON_STICK_LEFT)) {
                        if (acs->any.unk_5C != 0) {
                            acs->barFillLevel += (battleStatus->actionCmdDifficultyTable[acs->difficulty] * 850) / 100;
                            acs->any.unk_5C = 0;
                        }
                    }

                    if (battleStatus->curButtonsPressed & BUTTON_STICK_RIGHT) {
                        acs->barFillLevel -= (battleStatus->actionCmdDifficultyTable[acs->difficulty] * 850) / 100;
                    }
                }
            }

            if (acs->barFillLevel < 0) {
                acs->barFillLevel = 0;
            }

            if (acs->barFillLevel > 10000) {
                id = acs->hudElements[2];
                acs->barFillLevel = 10000;
                acs->isBarFilled = TRUE;
                hud_element_set_render_pos(id, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionQuality = acs->barFillLevel / 100;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, battleStatus->actionQuality * 12);

            switch (partner->actorBlueprint->level) {
                case PARTNER_RANK_NORMAL:
                    if (battleStatus->actionQuality >= D_802A9984_429CA4[battleStatus->unk_85]) {
                        battleStatus->unk_85++;
                    }

                    if (battleStatus->unk_85 > 0 && battleStatus->actionQuality < D_802A9984_429CA4[battleStatus->unk_85 - 1]) {
                        battleStatus->unk_85--;
                    }
                    break;
                case PARTNER_RANK_SUPER:
                    if (battleStatus->actionQuality >= D_802A9994_429CB4[battleStatus->unk_85]) {
                        battleStatus->unk_85++;
                    }
                    if (battleStatus->unk_85 > 0 && battleStatus->actionQuality < D_802A9994_429CB4[battleStatus->unk_85 - 1]) {
                        battleStatus->unk_85--;
                    }
                    break;
                case PARTNER_RANK_ULTRA:
                    if (battleStatus->actionQuality >= D_802A99A8_429CC8[battleStatus->unk_85]) {
                        battleStatus->unk_85++;
                    }
                    if (battleStatus->unk_85 > 0 && battleStatus->actionQuality < D_802A99A8_429CC8[battleStatus->unk_85 - 1]) {
                        battleStatus->unk_85--;
                    }
                    break;
            }

            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                return;
            }

            if (acs->barFillLevel == 0) {
                battleStatus->actionSuccess = -1;
            } else {
                battleStatus->actionSuccess = acs->barFillLevel / 100;
            }

            cutoff = acs->mashMeterCutoffs[acs->mashMeterIntervals - 1];
            if (battleStatus->actionSuccess <= cutoff) {
                battleStatus->actionResult = ACTION_RESULT_MINUS_2;
            } else {
                battleStatus->actionResult = ACTION_RESULT_SUCCESS;
            }

            if (battleStatus->actionSuccess == 100) {
                increment_action_command_success_count();
            }

            btl_set_popup_duration(0);
            sfx_stop_sound(SOUND_LOOP_CHARGE_BAR);
            acs->frameCounter = 5;
            acs->state = AC_STATE_DISPOSE;
            break;
        case AC_STATE_DISPOSE:
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
