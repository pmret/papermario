#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_break_free

extern s32 D_80294220;
extern HudScript HudScript_AButton[];
extern HudScript HudScript_BlueMeter[];
extern HudScript HudScript_RunningAway[];
extern HudScript HudScript_RunAwayOK[];

ApiStatus func_802A9000_4233F0(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 0;
    battleStatus->unk_434 = &D_80294220;
    battleStatus->unk_86 = 127;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_BREAK_FREE;
    actionCommandStatus->unk_61 = 1;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_46 = 0;
    actionCommandStatus->unk_48 = 0;
    battleStatus->actionSuccess = 0;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->hudElementY = 80;

    hudElement = hud_element_create(HudScript_AButton);
    actionCommandStatus->hudElements[0] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    hudElement = hud_element_create(HudScript_BlueMeter);
    actionCommandStatus->hudElements[1] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    hudElement = hud_element_create(HudScript_RunningAway);
    actionCommandStatus->hudElements[2] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    hudElement = hud_element_create(HudScript_RunAwayOK);
    actionCommandStatus->hudElements[3] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    return ApiStatus_DONE2;
}

ApiStatus func_802A91B0_4235A0(Evt* script, s32 isInitialCall) {
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
    actionCommandStatus->unk_5A = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);

    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_46 = 0;
    actionCommandStatus->unk_48 = 0;

    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 0x7F;
    battleStatus->unk_82 = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];

    actionCommandStatus->unk_46 = rand_int(actionCommandStatus->unk_5A);
    actionCommandStatus->unk_5C = 0;
    actionCommandStatus->state = 10;
    battleStatus->flags1 &= ~0x8000;

    return ApiStatus_DONE2;
}
INCLUDE_ASM(s32, "battle/action_cmd/break_free", func_802A92DC_4236CC);

void func_802A96B8_423AA8(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32* hudElements = actionCommandStatus->hudElements;
    s32 hudX;
    s32 hudY;
    s32 hudElement;
    s16 mashMeterCutoff;
    s32 thirtyOne;

    mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals];
    hudX = 60 - ((mashMeterCutoff - actionCommandStatus->unk_46) * 60 / mashMeterCutoff);

    // Putting 31 into a variable manually fixes regalloc, so perhaps this was a constant defined somewhere?
    thirtyOne = 31;
    hud_element_set_render_pos(hudElements[3], actionCommandStatus->hudElementX - (hudX - thirtyOne),
        actionCommandStatus->hudElementY + 17);
    hud_element_set_render_pos(hudElements[2], actionCommandStatus->hudElementX - (hudX - thirtyOne),
        actionCommandStatus->hudElementY - 1);

    if (actionCommandStatus->unk_6A == 0) {
        hud_element_draw_clipped(hudElements[0]);
    }

    hudElement = hudElements[1];
    hud_element_draw_clipped(hudElement);
    hud_element_get_render_pos(hudElement, &hudX, &hudY);

    func_80268770(hudX, hudY, actionCommandStatus->barFillLevel / 100);
    hud_element_draw_clipped(hudElements[2]);
    hud_element_draw_clipped(hudElements[3]);
}

void func_802A97FC_423BEC(void) {
    hud_element_free(gActionCommandStatus.hudElements[0]);
    hud_element_free(gActionCommandStatus.hudElements[1]);
    hud_element_free(gActionCommandStatus.hudElements[2]);
    hud_element_free(gActionCommandStatus.hudElements[3]);
}
