#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_hurricane

extern s32 D_80294420;
extern HudElementAnim D_80108AFC;
extern HudElementAnim D_80108B28;
extern HudElementAnim D_8029231C;
extern HudElementAnim D_80292974;

ApiStatus func_802A9000_42F6E0(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 5;
    battleStatus->unk_434 = &D_80294420;
    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();

    actionCommandStatus->actionCommandID = 20;
    actionCommandStatus->unk_6C = 30;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = 0;
    actionCommandStatus->hudElementY = 80;

    hudElement = create_hud_element(&D_80108B28);
    actionCommandStatus->hudElements[0] = hudElement;
    set_hud_element_flags(hudElement, 0x82);
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hudElement, 0);

    hudElement = create_hud_element(&D_8029231C);
    actionCommandStatus->hudElements[2] = hudElement;
    set_hud_element_flags(hudElement, 0x82);
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hudElement, 0);

    hudElement = create_hud_element(&D_80108AFC);
    actionCommandStatus->hudElements[1] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(&D_80292974);
    actionCommandStatus->hudElements[4] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    return ApiStatus_DONE2;
}

ApiStatus func_802A91A0_42F880(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32* args = script->ptrReadPos;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();

    actionCommandStatus->unk_4E = evt_get_variable(script, *args++);
    actionCommandStatus->unk_52 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = evt_get_variable(script, *args++);;
    actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);
    actionCommandStatus->unk_64 = evt_get_variable(script, *args++);

    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 0;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~0x8000;

    func_80269118();

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/action_cmd/hurricane", func_802A92A0_42F980);

void func_802A97AC_42FE8C(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 hudY;
    s32 hudX;
    s32 hudElement;

    draw_hud_element_clipped(actionCommandStatus->hudElements[0]);
    draw_hud_element_clipped(actionCommandStatus->hudElements[2]);

    hudElement = actionCommandStatus->hudElements[1];
    draw_hud_element_clipped(hudElement);
    get_hud_element_render_pos(hudElement, &hudX, &hudY);

    if (actionCommandStatus->unk_68 == 0) {
        func_80268770(hudX, hudY, actionCommandStatus->barFillLevel / 100);
    } else {
        func_8026880C(hudX, hudY, actionCommandStatus->barFillLevel / 100);
    }

    draw_hud_element_clipped(actionCommandStatus->hudElements[4]);
}

void func_802A9894_42FF74(void) {
    free_hud_element(gActionCommandStatus.hudElements[0]);
    free_hud_element(gActionCommandStatus.hudElements[1]);
    free_hud_element(gActionCommandStatus.hudElements[2]);
    free_hud_element(gActionCommandStatus.hudElements[4]);
}
