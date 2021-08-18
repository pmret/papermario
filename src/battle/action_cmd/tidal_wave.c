#include "common.h"

#define NAMESPACE action_command_tidal_wave

extern s32 D_80108AFC;
extern s32 D_80108B28;
extern s32 D_802944A0;

ApiStatus N(CreateHudElements)(ScriptInstance* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElement* hudElement;
    s32 i;

    battleStatus->unk_82 = 5;
    battleStatus->unk_434 = &D_802944A0;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    } else {
        func_80268858();
        actionCommandStatus->actionCommandID = ACTION_COMMAND_TIDAL_WAVE;
        actionCommandStatus->state = 0;
        actionCommandStatus->unk_60 = 0;
        actionCommandStatus->unk_44 = 0;
        actionCommandStatus->unk_48 = 0;
        battleStatus->unk_84 = 0;
        actionCommandStatus->hudElementX = -48;
        actionCommandStatus->hudElementY = 80;
        hudElement = create_hud_element(&D_80108AFC);
        actionCommandStatus->hudElements[0] = hudElement;
        set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
        set_hud_element_render_depth(hudElement, 0);
        set_hud_element_flags(hudElement, 0x82);

        for (i = 1; i < 15; i++) {
            hudElement = create_hud_element(&D_80108B28);
            actionCommandStatus->hudElements[i] = hudElement;
            set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
            set_hud_element_render_depth(hudElement, 0);
            set_hud_element_flags(hudElement, 0x82);
        }

        return ApiStatus_DONE2;
    }
}

ApiStatus func_802A9138_42C828(ScriptInstance* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

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
    battleStatus->unk_84 = 0;
    battleStatus->unk_86 = 0;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~0x8000;
    func_80269118();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/action_cmd/tidal_wave", func_802A9228_42C918);

void N(draw_hud_elements)(void) {
    s32 i;

    for (i = 1; i < 15; i++) {
        draw_hud_element_clipped(gActionCommandStatus.hudElements[i]);
    }
}

void N(free_hud_elements)(void) {
    s32 i;

    free_hud_element(gActionCommandStatus.hudElements[0]);

    for (i = 1; i < 15; i++) {
        free_hud_element(gActionCommandStatus.hudElements[i]);
    }
}
