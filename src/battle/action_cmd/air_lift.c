#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "hud_element.h"

#define NAMESPACE action_command_air_lift

void func_80268834(s32, s32, s16, s32);

extern HudScript HudScript_BlueMeter[];
extern HudScript HudScript_AButton[];
extern HudScript HudScript_100pct[];
extern s32 D_80294340;
BSS s32 air_lift_bss_0;

ApiStatus func_802A9000_428A70(Evt* script, s32 isInitialCall) {
    s32 *args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 hudElement;

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
    air_lift_bss_0 = 0;
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

    hudElement = hud_element_create(HudScript_100pct);
    actionCommandStatus->hudElements[2] = hudElement;
    hud_element_set_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    hud_element_set_render_depth(hudElement, 0);
    hud_element_set_flags(hudElement, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);

    return ApiStatus_DONE2;
}

ApiStatus func_802A9184_428BF4(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    u8 mashMeterCutoff;

    func_80268858();

    actionCommandStatus->unk_4E = evt_get_variable(script, *args++);
    actionCommandStatus->unk_52 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = evt_get_variable(script, *args++);
    actionCommandStatus->unk_50 = func_80268224(actionCommandStatus->unk_50);
    actionCommandStatus->unk_64 = evt_get_variable(script, *args++);

    actionCommandStatus->unk_60 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_86 = 127;

    mashMeterCutoff = actionCommandStatus->mashMeterCutoffs[actionCommandStatus->mashMeterIntervals - 1];
    actionCommandStatus->unk_5C = 0;

    battleStatus->flags1 &= ~0x8000;
    actionCommandStatus->state = 10;
    battleStatus->unk_82 = mashMeterCutoff;

    func_80269118();

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/action_cmd/air_lift", func_802A9278_428CE8);

void func_802A96EC_42915C(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 hudX;
    s32 hudY;
    s32 hudElement1;

    if (gBattleStatus.unk_83 != 0) {
        hud_element_draw_clipped(actionCommandStatus->hudElements[0]);
    }

    hudElement1 = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(hudElement1);
    hud_element_get_render_pos(hudElement1, &hudX, &hudY);

    if (air_lift_bss_0 == 0) {
        func_80268798(hudX, hudY, actionCommandStatus->barFillLevel / 100, 1);
    } else if (actionCommandStatus->unk_68 == 0) {
        func_80268798(hudX, hudY, actionCommandStatus->barFillLevel / 100, 4);
    } else {
        func_80268834(hudX, hudY, actionCommandStatus->barFillLevel / 100, 4);
    }

    hud_element_draw_clipped(actionCommandStatus->hudElements[2]);
}

#include "common/free_hud_elements.inc.c"
