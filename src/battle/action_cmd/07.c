#include "common.h"

#define NAMESPACE action_command_07

extern s32 D_80294280;
extern s32 D_802A9620;
extern HudElementAnim D_80108AFC;
extern HudElementAnim D_80108B28;
extern HudElementAnim D_80109244;

s32 func_8024FAFC(s32);

ApiStatus func_802A9000_425B50(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 hudElement;
    s32 hudElementTemp;

    battleStatus->unk_82 = 5;
    battleStatus->unk_434 = &D_80294280;

    actionCommandStatus->autoSucceed = 0;
    actionCommandStatus->actionCommandID = 7;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = evt_get_variable(script, *args);
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->unk_48 = 0;
    D_802A9620 = 0;
    actionCommandStatus->hudElementY = 80;

    hudElement = create_hud_element(&D_80108B28);
    actionCommandStatus->hudElements[0] = hudElement;
    set_hud_element_flags(hudElement, 0x82);
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX,
        actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hudElement, 0);

    // Weird use of an extra temp settles regalloc here.
    hudElementTemp = create_hud_element(&D_80108AFC);
    hudElement = hudElementTemp;
    actionCommandStatus->hudElements[1] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX,
        actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(&D_80109244);
    actionCommandStatus->hudElements[2] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX,
        actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    battleStatus->flags1 &= ~0x8000;

    return ApiStatus_DONE2;
}

ApiStatus func_802A916C_425CBC(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32* args = script->ptrReadPos;
    s32 mask;

    actionCommandStatus->autoSucceed = 0;
    actionCommandStatus->unk_4E = evt_get_variable(script, *args++);
    actionCommandStatus->unk_52 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);

    actionCommandStatus->unk_60 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 0;

    battleStatus->flags1 &= ~0x8000;
    func_8024FAFC(battleStatus->flags1);
    actionCommandStatus->state = 10;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/action_cmd/07", func_802A9228_425D78);

void func_802A94D8_426028(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 hudX;
    s32 hudY;
    s32 hudElement1;

    draw_hud_element_clipped(actionCommandStatus->hudElements[0]);
    hudElement1 = actionCommandStatus->hudElements[1];
    draw_hud_element_clipped(hudElement1);
    get_hud_element_render_pos(hudElement1, &hudX, &hudY);

    if (D_802A9620 == 0) {
        func_80268798(hudX, hudY, actionCommandStatus->barFillLevel / 100, 1);
    } else {
        func_80268798(hudX, hudY, actionCommandStatus->barFillLevel / 100, 2);
    }

    draw_hud_element_clipped(actionCommandStatus->hudElements[2]);
}

#include "common/free_hud_elements.inc.c"
