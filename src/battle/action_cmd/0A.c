#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_0A

extern s32 actionCmdTable0A[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 100;
    battleStatus->actionCmdDifficultyTable = actionCmdTable0A;
    battleStatus->actionResult = ACTION_RESULT_NONE;

    if (battleStatus->actionCommandMode == AC_MODE_NOT_LEARNED) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    action_command_init_status();

    acs->actionCommandID = ACTION_COMMAND_0A;
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
    s32 id;
    s32 cutoff;

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

            hud_element_set_script(acs->hudElements[0], &HES_MashAButton);
            acs->barFillLevel = 0;
            acs->state = AC_STATE_ACTIVE;
            acs->frameCounter = acs->duration;
            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(99);

            if (battleStatus->curButtonsPressed & BUTTON_A) {
                acs->barFillLevel += battleStatus->actionCmdDifficultyTable[acs->difficulty] * 15;
            }

            if (acs->barFillLevel >= 10000) {
                id = acs->hudElements[2];
                acs->barFillLevel = 10000;
                acs->isBarFilled = TRUE;
                hud_element_set_render_pos(id, acs->hudPosX + 50, acs->hudPosY + 28);
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            battleStatus->actionQuality = acs->barFillLevel / 100;

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
            if (battleStatus->actionSuccess >= cutoff) {
                battleStatus->actionResult = ACTION_RESULT_SUCCESS;
            } else {
                battleStatus->actionResult = ACTION_RESULT_MINUS_2;
            }

            if (battleStatus->actionSuccess == 100) {
                increment_action_command_success_count();
            }

            btl_set_popup_duration(0);
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
