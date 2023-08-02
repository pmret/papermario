#include "common.h"
#include "battle/action_cmd.h"

#define NAMESPACE action_command_07

void func_8024FAFC(void);

BSS s32 D_802A9620;

extern s32 actionCmdTable07[];

API_CALLABLE(N(init)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 hudElement;
    s32 hudElementTemp;

    battleStatus->unk_82 = 5;
    battleStatus->actionCmdDifficultyTable = actionCmdTable07;

    actionCommandStatus->autoSucceed = 0;
    actionCommandStatus->actionCommandID = ACTION_COMMAND_07;
    actionCommandStatus->state = 0;
    actionCommandStatus->wrongButtonPressed = FALSE;
    actionCommandStatus->barFillLevel = evt_get_variable(script, *args);
    actionCommandStatus->hudPosX = -48;
    actionCommandStatus->barFillWidth = 0;
    D_802A9620 = 0;
    actionCommandStatus->hudPosY = 80;

    hudElement = hud_element_create(&HES_AButton);
    actionCommandStatus->hudElements[0] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX,
        actionCommandStatus->hudPosY);
    hud_element_set_render_depth(hudElement, 0);

    // Weird use of an extra temp settles regalloc here.
    hudElementTemp = hud_element_create(&HES_BlueMeter);
    hudElement = hudElementTemp;
    actionCommandStatus->hudElements[1] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX,
        actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    hudElement = hud_element_create(&HES_RunAwayOK);
    actionCommandStatus->hudElements[2] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudPosX,
        actionCommandStatus->hudPosY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAG_80 | HUD_ELEMENT_FLAG_DISABLED);

    battleStatus->flags1 &= ~BS_FLAGS1_8000;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(start)) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32* args = script->ptrReadPos;
    s32 mask;

    actionCommandStatus->autoSucceed = 0;
    actionCommandStatus->prepareTime = evt_get_variable(script, *args++);
    actionCommandStatus->duration = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = evt_get_variable(script, *args++);
    actionCommandStatus->difficulty = adjust_action_command_difficulty(actionCommandStatus->difficulty);

    actionCommandStatus->wrongButtonPressed = FALSE;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 0;

    battleStatus->flags1 &= ~BS_FLAGS1_8000;
    func_8024FAFC();
    actionCommandStatus->state = 10;

    return ApiStatus_DONE2;
}

void N(update)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 id;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);

            id = actionCommandStatus->hudElements[0];
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }
            hud_element_set_alpha(id, 255);

            id = actionCommandStatus->hudElements[1];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }

            id = actionCommandStatus->hudElements[2];
            hud_element_set_alpha(id, 255);
            if (actionCommandStatus->showHud) {
                hud_element_clear_flags(id, 2);
            }

            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);

            actionCommandStatus->hudPosX += 20;
            if (actionCommandStatus->hudPosX > 50) {
                actionCommandStatus->hudPosX = 50;
            }

            hud_element_set_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudPosX, actionCommandStatus->hudPosY);
            hud_element_set_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudPosX, actionCommandStatus->hudPosY + 28);
            hud_element_set_render_pos(actionCommandStatus->hudElements[2], actionCommandStatus->hudPosX + 31, actionCommandStatus->hudPosY + 14);
            break;
        case 10:
            btl_set_popup_duration(99);

            if (actionCommandStatus->prepareTime != 0) {
                actionCommandStatus->prepareTime--;
                return;
            }

            hud_element_set_script(actionCommandStatus->hudElements[0], &HES_MashAButton);
            battleStatus->actionSuccess = 0;
            D_802A9620 = 1;
            actionCommandStatus->unk_5D = 0;
            actionCommandStatus->state = 11;
            actionCommandStatus->frameCounter = actionCommandStatus->duration;
            // fallthrough
        case 11:
            btl_set_popup_duration(99);

            if (battleStatus->curButtonsPressed & BUTTON_A) {
                s32 fillAmt = battleStatus->actionCmdDifficultyTable[actionCommandStatus->difficulty] * 6;

                if (actionCommandStatus->unk_5D == 0) {
                    actionCommandStatus->barFillLevel += fillAmt;
                }
            }

            if (actionCommandStatus->barFillLevel > 10000) {
                actionCommandStatus->barFillLevel = 10000;
                actionCommandStatus->unk_5D = 3;
            }

            if (actionCommandStatus->unk_5D != 0) {
                actionCommandStatus->unk_5D--;
                if (actionCommandStatus->unk_5D == 0) {
                    actionCommandStatus->barFillLevel = 0;
                    battleStatus->actionSuccess++;
                }
            }

            battleStatus->actionResult = actionCommandStatus->barFillLevel / 100;

            if (actionCommandStatus->frameCounter != 0) {
                actionCommandStatus->frameCounter--;
                return;
            }
            btl_set_popup_duration(0);
            actionCommandStatus->frameCounter = 5;
            actionCommandStatus->state = 12;
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
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 hudX;
    s32 hudY;
    s32 hudElement1;

    hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    hudElement1 = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(hudElement1);
    hud_element_get_render_pos(hudElement1, &hudX, &hudY);

    if (D_802A9620 == 0) {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, actionCommandStatus->barFillLevel / 100, 1);
    } else {
        draw_mash_meter_multicolor_with_divisor(hudX, hudY, actionCommandStatus->barFillLevel / 100, 2);
    }

    hud_element_draw_clipped(actionCommandStatus->hudElements[2]);
}

#include "common/free_hud_elements.inc.c"
