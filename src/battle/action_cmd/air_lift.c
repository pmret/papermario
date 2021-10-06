#include "common.h"

#define NAMESPACE action_command_air_lift

extern s32 D_80108AFC;
extern s32 D_80108B28;
extern s32 D_80292974;
extern s32 D_80294340;
extern s32 func_802A98B0_42EC50;

ApiStatus func_802A9000_428A70(Evt* script, s32 isInitialCall) {
    s32 *args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    HudElement* hudElement;

    battleStatus->unk_434 = &D_80294340;
    battleStatus->unk_82 = 0;
    battleStatus->unk_86 = 127;
    func_80268858();
    actionCommandStatus->unk_5A = evt_get_variable(script, *args++);
    actionCommandStatus->actionCommandID = ACTION_COMMAND_AIR_LIFT;
    actionCommandStatus->unk_61 = 1;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_84 = 0;
    actionCommandStatus->unk_6C = 30;
    actionCommandStatus->hudElementX = -48;
    func_802A98B0_42EC50 = 0;
    actionCommandStatus->hudElementY = 80;

    hudElement = create_hud_element(&D_80108B28);
    actionCommandStatus->hudElements[0] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(&D_80108AFC);
    actionCommandStatus->hudElements[1] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(&D_80292974);
    actionCommandStatus->hudElements[2] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/action_cmd/air_lift", func_802A9184_428BF4);

INCLUDE_ASM(s32, "battle/action_cmd/air_lift", func_802A9278_428CE8);

INCLUDE_ASM(s32, "battle/action_cmd/air_lift", func_802A96EC_42915C);

#include "common/free_hud_elements.inc.c"
