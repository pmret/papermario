#include "common.h"
#include "hud_element.h"

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

    hudElement = hud_element_create(HudScript_AButton);
    actionCommandStatus->hudElements[0] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 0);

    hudElement = hud_element_create(HudScript_BlueMeter);
    actionCommandStatus->hudElements[1] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    hudElement = hud_element_create(&D_802AA7F0_425460);
    actionCommandStatus->hudElements[2] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX + 54, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    hudElement = hud_element_create(&D_802AA818_425488);
    actionCommandStatus->hudElements[3] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX + 60, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "battle/action_cmd/whirlwind", func_802A9000_423C70);
#endif

INCLUDE_ASM(s32, "battle/action_cmd/whirlwind", func_802A91E0_423E50);

INCLUDE_ASM(s32, "battle/action_cmd/whirlwind", func_802A92F0_423F60);

// hud element scripts
extern HudScript* D_802AA888_4254F8[];
extern HudScript* D_802AA8A0_425510[];

void func_802A9744_4243B4(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 x, y;
    s32 hudElement;

    if (actionCommandStatus->unk_6A == 0) {
        hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    }
    hudElement = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(hudElement);
    hud_element_get_render_pos(hudElement, &x, &y);

    func_80268798(x, y, (s16) actionCommandStatus->barFillLevel / 100, 1);
    hud_element_draw_clipped(actionCommandStatus->hudElements[3]);
    hudElement = actionCommandStatus->hudElements[2];
    if (actionCommandStatus->unk_64 == 0) {
        if (D_802AA888_4254F8[battleStatus->unk_84] != hud_element_get_script(hudElement)) {
            hud_element_set_script(hudElement, D_802AA888_4254F8[battleStatus->unk_84]);
        }
    } else {
        if (D_802AA8A0_425510[battleStatus->unk_84] != hud_element_get_script(hudElement)) {
            hud_element_set_script(hudElement, D_802AA8A0_425510[battleStatus->unk_84]);
        }
    }
    hud_element_draw_clipped(hudElement);
}

void func_802A9898_424508(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
}
