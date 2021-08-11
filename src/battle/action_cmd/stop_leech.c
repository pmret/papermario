#include "common.h"

#define NAMESPACE action_command_stop_leech

extern s32 D_80108AFC;
extern s32 D_80108B28;
extern s32 D_80294260;

ApiStatus func_802A9000_425590(void) {
    HudElement* hudElement;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->unk_82 = 5;
    battleStatus->unk_434 = &D_80294260;
    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->actionCommandID = 6;
    actionCommandStatus->hudElementX = -0x30;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->unk_44 = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->hudElementY = 0x50;

    hudElement = create_hud_element(&D_80108B28);
    actionCommandStatus->hudElements[0] = hudElement;
    set_hud_element_flags(hudElement, 0x82);
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hudElement, 0);

    hudElement = create_hud_element(&D_80108AFC);
    actionCommandStatus->hudElements[1] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 0x1C);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);
    return ApiStatus_DONE2;
}

ApiStatus func_802A9110_4256A0(ScriptInstance* script) {
    Bytecode* args;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    args = script->ptrReadPos;
    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->unk_4E = get_variable(script, *args++);
    actionCommandStatus->unk_52 = get_variable(script, *args++);
    actionCommandStatus->unk_50 = get_variable(script, *args++);
    actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->unk_44 = 0;
    actionCommandStatus->unk_48 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 0;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~0x8000;

    return ApiStatus_DONE2;
}

//INCLUDE_ASM(s32, "battle/action_cmd/stop_leech", func_802A91F8_425788);
extern s32 D_80108B80;

void func_802A91F8_425788(void) {
// changed BattleStatus unk_434
    
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    HudElement* hudElement;
    s16 hudElementX;

    switch (actionCommandStatus->state) {
    case 0:
        btl_set_popup_duration(0x63);
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
        return;
    case 1:
        btl_set_popup_duration(0x63);
        hudElementX = actionCommandStatus->hudElementX + 0x14;
        actionCommandStatus->hudElementX = hudElementX;
        if (hudElementX >= 0x33) {
            actionCommandStatus->hudElementX = 0x32U;
        }
        set_hud_element_render_pos(actionCommandStatus->hudElements[0], (s16) actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
        set_hud_element_render_pos(actionCommandStatus->hudElements[1], (s16) actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 0x1C);
        return;
    case 10:
        btl_set_popup_duration(0x63);
        if (actionCommandStatus->unk_4E != 0) {
            actionCommandStatus->unk_4E -= 1;
            return;
        }
        set_hud_element_script(actionCommandStatus->hudElements[0], &D_80108B80);
        actionCommandStatus->unk_44 = 0U;
        actionCommandStatus->state = 0xB;
        actionCommandStatus->unk_54 = (u16) actionCommandStatus->unk_52;
    case 11:
        btl_set_popup_duration(0x63);
        if (actionCommandStatus->unk_6A == 0) {
            if ((battleStatus->currentButtonsPressed & 0x8000) != 0) {
                actionCommandStatus->unk_44 += (s32)battleStatus->unk_434[actionCommandStatus->unk_50];
            }
        } else {
            actionCommandStatus->unk_44 += (s32)battleStatus->unk_434[actionCommandStatus->unk_50] / 6;
            actionCommandStatus->unk_44 += rand_int(((s32)battleStatus->unk_434[actionCommandStatus->unk_50]) / 6);
        }
        battleStatus->unk_84 = (s16)(actionCommandStatus->unk_44 / 100);
        if (actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals] <= (s16)battleStatus->unk_84) {
            actionCommandStatus->unk_54 = 0;
        }

        if (actionCommandStatus->unk_54 == 0) {
            btl_set_popup_duration(0);
            actionCommandStatus->unk_54 = 5;
            actionCommandStatus->state = 0xC;
            return;
        }
        actionCommandStatus->unk_54 -= 1;
        return;
    case 12:
        if (actionCommandStatus->unk_54 != 0) {
            actionCommandStatus->unk_54 -= 1;
            return;
        }
        battleStatus->actionSuccess = 1;
        battleStatus->unk_86 = 0x7F;
        func_80268C9C();
    default:
        return;
    }
}

void func_802A94A4_425A34(void) {
	s32 x, y;
    HudElement* hudElement;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    if (actionCommandStatus->unk_6A == 0) {
        draw_hud_element_clipped(actionCommandStatus->hudElements[0]);
    }

    hudElement = actionCommandStatus->hudElements[1];
    draw_hud_element_clipped(hudElement);
    get_hud_element_render_pos(hudElement, &x, &y);
    func_80268798(x, y, actionCommandStatus->unk_44 / 100, 2);
}

void func_802A9544_425AD4(void) {
    free_hud_element(gActionCommandStatus.hudElements[0]);
    free_hud_element(gActionCommandStatus.hudElements[1]);
}
