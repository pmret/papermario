#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_bomb

extern s32 actionCmdTableBomb[];

s32 MashBarDrainRates[AC_DIFFICULTY_LEN] = { 0, 25, 50, 75, 75, 0, 0, 0 };

// indices into ActionCommandStatus::hudElements for this action command
enum {
    HIDX_BUTTON         = 0,
    HIDX_METER          = 1,
    HIDX_100_PCT        = 2,
};

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTableBomb;
    battleStatus->actionResult = ACTION_RESULT_NONE;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();
    acs->actionCommandID = ACTION_COMMAND_BOMB;
    acs->showHud = TRUE;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = 0;
    acs->barFillWidth = 0;
    acs->isBarFilled = FALSE;
    battleStatus->actionSuccess = 0;

    acs->hudPosX = -48;
    acs->hudPosY = 80;

    hudElement = hud_element_create(&HES_AButton);
    acs->hudElements[HIDX_BUTTON] = hudElement;
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hudElement = hud_element_create(&HES_BlueMeter);
    acs->hudElements[HIDX_METER] = hudElement;
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hudElement = hud_element_create(&HES_100pct);
    acs->hudElements[HIDX_100_PCT] = hudElement;
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    return ApiStatus_DONE2;
}

#include "common/MashCommandStart.inc.c"

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hid;
    s32 cutoff;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(POPUP_MSG_ON);
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

            acs->state = AC_STATE_APPEAR;
            break;
        case AC_STATE_APPEAR:
            btl_set_popup_duration(POPUP_MSG_ON);

            acs->hudPosX += 20;
            if (acs->hudPosX > 50) {
                acs->hudPosX = 50;
            }

            hud_element_set_render_pos(acs->hudElements[HIDX_BUTTON], acs->hudPosX, acs->hudPosY);
            hud_element_set_render_pos(acs->hudElements[HIDX_METER], acs->hudPosX, acs->hudPosY + 28);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(POPUP_MSG_ON);

            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                break;
            }

            hud_element_set_script(acs->hudElements[HIDX_BUTTON], &HES_MashAButton);
            acs->barFillLevel = 0;
            acs->frameCounter = acs->duration;
            sfx_play_sound_with_params(SOUND_LOOP_CHARGE_BAR, 0, 0, 0);
            acs->state = AC_STATE_ACTIVE;

            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(POPUP_MSG_ON);
            if (!acs->isBarFilled) {
                cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals];
                acs->barFillLevel -= MashBarDrainRates[acs->barFillLevel / cutoff / 20];

                if (acs->barFillLevel < 0) {
                    acs->barFillLevel = 0;
                }
            }

            if (battleStatus->curButtonsPressed & BUTTON_A) {
                switch (acs->targetWeakness) {
                    case 0:
                        acs->barFillLevel += battleStatus->actionCmdDifficultyTable[acs->difficulty] * 235 * 4 / 100;
                        break;
                    case 1:
                        acs->barFillLevel += battleStatus->actionCmdDifficultyTable[acs->difficulty] * 200 * 4 / 100;
                        break;
                    case 2:
                        acs->barFillLevel += battleStatus->actionCmdDifficultyTable[acs->difficulty] * 185 * 4 / 100;
                        break;
                }
            }

            if (acs->barFillLevel > 10000) {
                hid = acs->hudElements[HIDX_100_PCT];
                acs->barFillLevel = 10000;
                acs->isBarFilled = TRUE;
                hud_element_set_render_pos(hid, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(hid, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionQuality = acs->barFillLevel / 100;
            sfx_adjust_env_sound_params(SOUND_LOOP_CHARGE_BAR, 0, 0, battleStatus->actionQuality * 12);

            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                break;
            }

            if (acs->barFillLevel == 0) {
                battleStatus->actionSuccess = -1;
            } else {
                battleStatus->actionSuccess = acs->barFillLevel / 100;
            }

            cutoff = acs->mashMeterCutoffs[acs->mashMeterNumIntervals - 1];
            if (cutoff >= battleStatus->actionSuccess) {
                battleStatus->actionResult = ACTION_RESULT_MINUS_2;
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
            break;
        case AC_STATE_DISPOSE:
            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                break;
            }
            action_command_free();
            break;
    }
}

#include "common/MashCommandDraw.inc.c"

#include "common/MashCommandFree.inc.c"
