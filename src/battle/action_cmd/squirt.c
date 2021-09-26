#include "common.h"

#define NAMESPACE action_command_squirt

extern s32 D_80108AFC[];
extern s32 D_80108B28[];
extern s32 D_80294380;

ApiStatus func_802A9000_429D20(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElement* hudElement;

    battleStatus->unk_82 = 5;
    battleStatus->unk_434 = &D_80294380;
    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }
    
    func_80268858();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_SQUIRT;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->unk_44 = 0;
    actionCommandStatus->unk_48 = 0;
    battleStatus->unk_84 = 0;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->unk_5C = 0;
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

ApiStatus func_802A911C_429E3C(Evt* script) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

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
    actionCommandStatus->unk_44 = 0;
    actionCommandStatus->unk_48 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 0;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~0x8000;
    func_80269118();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/action_cmd/squirt", func_802A9208_429F28);

void func_802A9634_42A354(void) {
    s32 x, y;
    s32 hudElement;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    draw_hud_element_clipped(actionCommandStatus->hudElements[0]);
    hudElement = actionCommandStatus->hudElements[1];
    draw_hud_element_clipped(hudElement);
    get_hud_element_render_pos(hudElement, &x, &y);
    if (actionCommandStatus->unk_5C == 0) {
        func_80268798(x, y, actionCommandStatus->unk_44 / 100, 1);
    } else {
        func_802687E4(x, y, actionCommandStatus->unk_44 / 100, 1, 1);
    }
}

void func_802A9720_42A440(void) {
    sfx_stop_sound(0x80000041);
    free_hud_element(gActionCommandStatus.hudElements[0]);
    free_hud_element(gActionCommandStatus.hudElements[1]);
}
