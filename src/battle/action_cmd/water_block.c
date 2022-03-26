#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_water_block

// requires .data migration
INCLUDE_ASM(s32, "battle/action_cmd/water_block", func_802A9000_42A4F0);

ApiStatus func_802A9398_42A888(Evt* script, s32 isInitialCall) {
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
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    battleStatus->unk_84 = 1;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 0;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~0x8000;
    func_80269118();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/action_cmd/water_block", func_802A948C_42A97C);

extern HudScript* D_802AB180_42C670[];

void func_802AA014_42B504(void) {
    s32 hudElement;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[1]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[2]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[3]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[4]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[6]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[7]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[8]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[13]);

    hudElement = actionCommandStatus->hudElements[10];
    if (hud_element_get_script(hudElement) != D_802AB180_42C670[battleStatus->unk_84]) {
        hud_element_set_script(hudElement, D_802AB180_42C670[battleStatus->unk_84]);
    }

    hud_element_draw_clipped(hudElement);
    hud_element_draw_clipped(actionCommandStatus->hudElements[11]);
    hud_element_draw_clipped(actionCommandStatus->hudElements[12]);
}

void func_802AA0D8_42B5C8(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
    hud_element_free(gActionCommandStatus.hudElements[6]);
    hud_element_free(gActionCommandStatus.hudElements[7]);
    hud_element_free(gActionCommandStatus.hudElements[8]);
    hud_element_free(gActionCommandStatus.hudElements[10]);
    hud_element_free(gActionCommandStatus.hudElements[11]);
    hud_element_free(gActionCommandStatus.hudElements[12]);
    hud_element_free(gActionCommandStatus.hudElements[13]);
}
