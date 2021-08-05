#include "common.h"

#define NAMESPACE action_command_hammer

extern s32 D_80108E48;
// icon indexes for hud elements
extern s32 D_802922F0;
extern s32 D_8029275C;
extern s32 D_802927F0;
extern s32 D_80292848;
extern s32 D_802928A0;
extern s32 D_80292A2C;

extern s32 D_802941E0;

// createHudElements
ApiStatus func_802A9000_422000(void) {
    HudElement* hud_element;

    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->unk_82 = 1;
    battleStatus->unk_434 = &D_802941E0;
    battleStatus->unk_86 = 0;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        battleStatus->unk_84 = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->actionCommandID = 2;
    actionCommandStatus->hudElementX = -0x30;
    actionCommandStatus->unk_4C = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->hudElementY = 0x60;

    hud_element = create_hud_element(&D_802922F0);
    actionCommandStatus->hudElements[0] = hud_element;
    set_hud_element_flags(hud_element, 0x82);
    set_hud_element_render_pos(hud_element, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hud_element, 0xA);

    hud_element = create_hud_element(&D_8029275C);
    actionCommandStatus->hudElements[1] = hud_element;
    set_hud_element_flags(hud_element, 0x82);
    set_hud_element_render_pos(hud_element, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hud_element, 0);

    hud_element = create_hud_element(&D_802927F0);
    actionCommandStatus->hudElements[2] = hud_element;
    set_hud_element_flags(hud_element, 0x82);
    set_hud_element_render_pos(hud_element, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hud_element, 0);

    hud_element = create_hud_element(&D_80292848);
    actionCommandStatus->hudElements[3] = hud_element;
    set_hud_element_flags(hud_element, 0x82);
    set_hud_element_render_pos(hud_element, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hud_element, 0);

    hud_element = create_hud_element(&D_802928A0);
    actionCommandStatus->hudElements[4] = hud_element;
    set_hud_element_flags(hud_element, 0x82);
    set_hud_element_render_pos(hud_element, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hud_element, 0);

    hud_element = create_hud_element(&D_80108E48);
    actionCommandStatus->hudElements[5] = hud_element;
    set_hud_element_flags(hud_element, 0x82);
    set_hud_element_render_pos(hud_element, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hud_element, 0);

    hud_element = create_hud_element(&D_80292A2C);
    actionCommandStatus->hudElements[6] = hud_element;
    set_hud_element_flags(hud_element, 0x82);
    set_hud_element_render_pos(hud_element, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hud_element, 0);
    set_hud_element_alpha(hud_element, 0xFF);

    return ApiStatus_DONE2;
}

ApiStatus func_802A9258_422258(ScriptInstance* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 *ptrReadPos = script->ptrReadPos;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        battleStatus->unk_84 = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->unk_4E = get_variable(script, *ptrReadPos++);
    actionCommandStatus->unk_52 = get_variable(script, *ptrReadPos++);
    actionCommandStatus->unk_50 = get_variable(script, *ptrReadPos);
    actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->unk_62 = 1;
    if (actionCommandStatus->unk_4E < 0) {
        actionCommandStatus->unk_4E = 0;
        actionCommandStatus->unk_62 = 0;
    }

    actionCommandStatus->unk_5F = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_84 = 0;
    battleStatus->unk_86 = 0;
    actionCommandStatus->unk_4C = 0xA;
    battleStatus->flags1 &= ~0x00008000;
    func_80269118();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/action_cmd/hammer", func_802A936C_42236C);

// drawHudElements
void func_802A99D4_4229D4(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    draw_hud_element_clipped(actionCommandStatus->hudElements[0]);
    draw_hud_element_clipped(actionCommandStatus->hudElements[1]);
    draw_hud_element_clipped(actionCommandStatus->hudElements[2]);
    draw_hud_element_clipped(actionCommandStatus->hudElements[3]);
    draw_hud_element_clipped(actionCommandStatus->hudElements[4]);
    draw_hud_element_clipped(actionCommandStatus->hudElements[5]);
    draw_hud_element_clipped(actionCommandStatus->hudElements[6]);
}

// freeHudElements
void func_802A9A30_422A30(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    free_hud_element(actionCommandStatus->hudElements[0]);
    free_hud_element(actionCommandStatus->hudElements[1]);
    free_hud_element(actionCommandStatus->hudElements[2]);
    free_hud_element(actionCommandStatus->hudElements[3]);
    free_hud_element(actionCommandStatus->hudElements[4]);
    free_hud_element(actionCommandStatus->hudElements[5]);
    free_hud_element(actionCommandStatus->hudElements[6]);
}