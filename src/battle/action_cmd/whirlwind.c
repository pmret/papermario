#include "common.h"

#define NAMESPACE action_command_whirlwind

// requires .data migration
#ifdef NON_MATCHING
ApiStatus func_802A9000_423C70(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s16 temp_v0;
    HudElement* hudElement;

    battleStatus->unk_82 = 5;
    battleStatus->unk_434 = &D_80294240;
    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    temp_v0 = evt_get_variable(script, *args);
    actionCommandStatus->unk_64 = temp_v0;
    actionCommandStatus->actionCommandID = ACTION_COMMAND_WHIRLWIND;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->unk_44 = 0;
    actionCommandStatus->unk_48 = 0;
    if (temp_v0 == 0) {
        battleStatus->unk_84 = 0;
    } else {
        battleStatus->unk_84 = 3;
    }
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->hudElementY = 80;

    hudElement = create_hud_element(&D_80108B28);
    actionCommandStatus->hudElements[0] = hudElement;
    set_hud_element_flags(hudElement, 0x82);
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hudElement, 0);

    hudElement = create_hud_element(&D_80108AFC);
    actionCommandStatus->hudElements[1] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(&D_802AA7F0_425460);
    actionCommandStatus->hudElements[2] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX + 54, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(&D_802AA818_425488);
    actionCommandStatus->hudElements[3] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX + 60, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "battle/action_cmd/whirlwind", func_802A9000_423C70);
#endif

INCLUDE_ASM(s32, "battle/action_cmd/whirlwind", func_802A91E0_423E50);

INCLUDE_ASM(s32, "battle/action_cmd/whirlwind", func_802A92F0_423F60);

// hud element scripts
extern s32* D_802AA888_4254F8[];
extern s32* D_802AA8A0_425510[];

void func_802A9744_4243B4(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 x, y;
    HudElement* hudElement;

    if (actionCommandStatus->unk_6A == 0) {
        draw_hud_element_clipped(actionCommandStatus->hudElements[0]);
    }
    hudElement = actionCommandStatus->hudElements[1];
    draw_hud_element_clipped(hudElement);
    get_hud_element_render_pos(hudElement, &x, &y);

    func_80268798(x, y, (s16)actionCommandStatus->barFillLevel / 100, 1);
    draw_hud_element_clipped(actionCommandStatus->hudElements[3]);
    hudElement = actionCommandStatus->hudElements[2];
    if (actionCommandStatus->unk_64 == 0) {
        if (D_802AA888_4254F8[battleStatus->unk_84] != get_hud_element_anim(hudElement)) {
            set_hud_element_anim(hudElement, D_802AA888_4254F8[battleStatus->unk_84]);
        }
    } else {
        if (D_802AA8A0_425510[battleStatus->unk_84] != get_hud_element_anim(hudElement)) {
            set_hud_element_anim(hudElement, D_802AA8A0_425510[battleStatus->unk_84]);
        }
    }
    draw_hud_element_clipped(hudElement);
}

void func_802A9898_424508(void) {
    free_hud_element(gActionCommandStatus.hudElements[0]);
    free_hud_element(gActionCommandStatus.hudElements[1]);
    free_hud_element(gActionCommandStatus.hudElements[2]);
    free_hud_element(gActionCommandStatus.hudElements[3]);
}
