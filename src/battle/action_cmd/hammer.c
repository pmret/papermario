#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_hammer

// icon indexes for hud elements
extern HudScript HudScript_TimingBar1Chance;
extern HudScript HudScript_TimingWait;
extern HudScript HudScript_TimingCharge4a;
extern HudScript HudScript_TimingCharge4b;
extern HudScript HudScript_TimingCharge4c;
extern HudScript HudScript_StickHoldLeft;
extern HudScript HudScript_RightOn;

extern s32 D_802941E0;

ApiStatus N(CreateHudElements)(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 1;
    battleStatus->unk_434 = &D_802941E0;
    battleStatus->unk_86 = 0;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        battleStatus->unk_84 = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_SMASH;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->hudElementY = 96;

    hudElement = hud_element_create(&HudScript_TimingBar1Chance);
    actionCommandStatus->hudElements[0] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 10);

    hudElement = hud_element_create(&HudScript_TimingWait);
    actionCommandStatus->hudElements[1] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 0);

    hudElement = hud_element_create(&HudScript_TimingCharge4a);
    actionCommandStatus->hudElements[2] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 0);

    hudElement = hud_element_create(&HudScript_TimingCharge4b);
    actionCommandStatus->hudElements[3] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 0);

    hudElement = hud_element_create(&HudScript_TimingCharge4c);
    actionCommandStatus->hudElements[4] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 0);

    hudElement = hud_element_create(&HudScript_StickHoldLeft);
    actionCommandStatus->hudElements[5] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 0);

    hudElement = hud_element_create(&HudScript_RightOn);
    actionCommandStatus->hudElements[6] = hudElement;
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_alpha(hudElement, 0xFF);

    return ApiStatus_DONE2;
}

ApiStatus func_802A9258_422258(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        battleStatus->unk_84 = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->unk_4E = evt_get_variable(script, *args++);
    actionCommandStatus->unk_52 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = evt_get_variable(script, *args);
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
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~0x8000;
    func_80269118();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/action_cmd/hammer", func_802A936C_42236C);

void N(draw_hud_elements)(void) {
    hud_element_draw_clipped(gActionCommandStatus.hudElements[0]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[1]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[2]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[3]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[4]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[5]);
    hud_element_draw_clipped(gActionCommandStatus.hudElements[6]);
}

void N(free_hud_elements)(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
    hud_element_free(gActionCommandStatus.hudElements[4]);
    hud_element_free(gActionCommandStatus.hudElements[5]);
    hud_element_free(gActionCommandStatus.hudElements[6]);
}
