#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_stop_leech

extern HudElementAnim D_80108B80[];
extern HudElementAnim D_80108AFC[];
extern HudElementAnim D_80108B28[];
extern s32 D_80294260;

ApiStatus func_802A9000_425590(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 5;
    battleStatus->unk_434 = &D_80294260;
    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_STOP_LEECH;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->hudElementY = 80;

    hudElement = create_hud_element(D_80108B28);
    actionCommandStatus->hudElements[0] = hudElement;
    set_hud_element_flags(hudElement, 0x82);
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hudElement, 0);

    hudElement = create_hud_element(D_80108AFC);
    actionCommandStatus->hudElements[1] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);
    return ApiStatus_DONE2;
}

ApiStatus func_802A9110_4256A0(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->unk_4E = evt_get_variable(script, *args++);
    actionCommandStatus->unk_52 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 0;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~0x8000;

    return ApiStatus_DONE2;
}

void func_802A91F8_425788(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 hudElement;
    s16 hudElementX;

    switch (actionCommandStatus->state) {
        case 0:
            btl_set_popup_duration(99);
            hudElement = actionCommandStatus->hudElements[0];
            if (actionCommandStatus->unk_61 != 0) {
                clear_hud_element_flags(hudElement, 2);
            }
            set_hud_element_alpha(hudElement, 0xFF);
            hudElement = actionCommandStatus->hudElements[1];
            set_hud_element_alpha(hudElement, 0xFF);
            if (actionCommandStatus->unk_61 != 0) {
                clear_hud_element_flags(hudElement, 2);
            }
            actionCommandStatus->state = 1;
            break;
        case 1:
            btl_set_popup_duration(99);
            hudElementX = actionCommandStatus->hudElementX + 20;
            actionCommandStatus->hudElementX = hudElementX;
            if (hudElementX > 50) {
                actionCommandStatus->hudElementX = 50;
            }
            set_hud_element_render_pos(actionCommandStatus->hudElements[0], actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
            set_hud_element_render_pos(actionCommandStatus->hudElements[1], actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
            break;
        case 10:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_4E != 0) {
                actionCommandStatus->unk_4E -= 1;
                break;
            }
            set_hud_element_anim(actionCommandStatus->hudElements[0], D_80108B80);
            actionCommandStatus->barFillLevel = 0;
            actionCommandStatus->state = 11;
            actionCommandStatus->unk_54 = actionCommandStatus->unk_52;
        case 11:
            btl_set_popup_duration(99);
            if (actionCommandStatus->unk_6A == 0) {
                if ((battleStatus->currentButtonsPressed & 0x8000) != 0) {
                    actionCommandStatus->barFillLevel += battleStatus->unk_434[actionCommandStatus->unk_50];
                }
            } else {
                actionCommandStatus->barFillLevel += battleStatus->unk_434[actionCommandStatus->unk_50] / 6;
                actionCommandStatus->barFillLevel += rand_int((battleStatus->unk_434[actionCommandStatus->unk_50]) / 6);
            }
            battleStatus->unk_84 = actionCommandStatus->barFillLevel / 100;
            if (actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals] <= battleStatus->unk_84) {
                actionCommandStatus->unk_54 = 0;
            }

            if (actionCommandStatus->unk_54 == 0) {
                btl_set_popup_duration(0);
                actionCommandStatus->unk_54 = 5;
                actionCommandStatus->state = 12;
                break;
            }
            actionCommandStatus->unk_54 -= 1;
            break;
        case 12:
            if (actionCommandStatus->unk_54 != 0) {
                actionCommandStatus->unk_54 -= 1;
                break;
            }
            battleStatus->actionSuccess = 1;
            battleStatus->unk_86 = 127;
            func_80268C9C();
        default:
            break;
    }
}

void func_802A94A4_425A34(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 x, y;
    s32 hudElement;

    if (actionCommandStatus->unk_6A == 0) {
        draw_hud_element_clipped(actionCommandStatus->hudElements[0]);
    }

    hudElement = actionCommandStatus->hudElements[1];
    draw_hud_element_clipped(hudElement);
    get_hud_element_render_pos(hudElement, &x, &y);
    func_80268798(x, y, actionCommandStatus->barFillLevel / 100, 2);
}

void func_802A9544_425AD4(void) {
    free_hud_element(gActionCommandStatus.hudElements[0]);
    free_hud_element(gActionCommandStatus.hudElements[1]);
}
