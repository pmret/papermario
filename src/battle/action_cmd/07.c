#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_07

void btl_message_unlock_box_pos(void);

BSS s32 D_802A9620;

extern s32 actionCmdTable07[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 hudElement;
    s32 hudElementTemp;

    battleStatus->unk_82 = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTable07;

    acs->autoSucceed = 0;
    acs->actionCommandID = ACTION_COMMAND_07;
    acs->state = AC_STATE_INIT;
    acs->wrongButtonPressed = FALSE;
    acs->barFillLevel = evt_get_variable(script, *args);
    acs->hudPosX = -48;
    acs->barFillWidth = 0;
    D_802A9620 = 0;
    acs->hudPosY = 80;

    hudElement = hud_element_create(&HES_AButton);
    acs->hudElements[0] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY);
    hud_element_set_render_depth(hudElement, 0);

    // Weird use of an extra temp settles regalloc here.
    hudElementTemp = hud_element_create(&HES_BlueMeter);
    hudElement = hudElementTemp;
    acs->hudElements[1] = hudElement;
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hudElement = hud_element_create(&HES_RunAwayOK);
    acs->hudElements[2] = hudElement;
    hud_element_set_render_pos(hudElement, acs->hudPosX, acs->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32* args = script->ptrReadPos;
    s32 mask;

    acs->autoSucceed = 0;
    acs->prepareTime = evt_get_variable(script, *args++);
    acs->duration = evt_get_variable(script, *args++);
    acs->difficulty = evt_get_variable(script, *args++);
    acs->difficulty = adjust_action_command_difficulty(acs->difficulty);

    acs->wrongButtonPressed = FALSE;
    battleStatus->actionSuccess = 0;
    battleStatus->actionResult = ACTION_RESULT_FAIL;

    battleStatus->flags1 &= ~BS_FLAGS1_FREE_ACTION_COMMAND;
    btl_message_unlock_box_pos();
    acs->state = AC_STATE_START;

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    switch (acs->state) {
        case AC_STATE_INIT:
            btl_set_popup_duration(99);

            id = acs->hudElements[0];
            if (acs->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }
            hud_element_set_alpha(id, 255);

            id = acs->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (acs->showHud) {
                hud_element_clear_flags(id, HUD_ELEMENT_FLAG_DISABLED);
            }

            id = acs->hudElements[2];
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
            hud_element_set_render_pos(acs->hudElements[2], acs->hudPosX + 31, acs->hudPosY + 14);
            break;
        case AC_STATE_START:
            btl_set_popup_duration(99);

            if (acs->prepareTime != 0) {
                acs->prepareTime--;
                return;
            }

            hud_element_set_script(acs->hudElements[0], &HES_MashAButton);
            battleStatus->actionSuccess = 0;
            D_802A9620 = 1;
            acs->any.unk_5D = 0;
            acs->state = AC_STATE_ACTIVE;
            acs->frameCounter = acs->duration;
            // fallthrough
        case AC_STATE_ACTIVE:
            btl_set_popup_duration(99);

            if (battleStatus->curButtonsPressed & BUTTON_A) {
                s32 fillAmt = battleStatus->actionCmdDifficultyTable[acs->difficulty] * 6;

                if (acs->any.unk_5D == 0) {
                    acs->barFillLevel += fillAmt;
                }
            }

            if (acs->barFillLevel > 10000) {
                acs->barFillLevel = 10000;
                acs->any.unk_5D = 3;
            }

            if (acs->any.unk_5D != 0) {
                acs->any.unk_5D--;
                if (acs->any.unk_5D == 0) {
                    acs->barFillLevel = 0;
                    battleStatus->actionSuccess++;
                }
            }

            battleStatus->actionQuality = acs->barFillLevel / 100;

            if (acs->frameCounter != 0) {
                acs->frameCounter--;
                return;
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

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hudX;
    s32 hudY;
    s32 hudElement1;

    hud_element_draw_clipped(acs->hudElements[0]);
    hudElement1 = acs->hudElements[1];
    hud_element_draw_clipped(hudElement1);
    hud_element_get_render_pos(hudElement1, &hudX, &hudY);

    if (D_802A9620 == 0) {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->barFillLevel / 100, 1);
    } else {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, acs->barFillLevel / 100, 2);
    }

    hud_element_draw_clipped(acs->hudElements[2]);
}

void N(free)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
}
