#include "common.h"

#define NAMESPACE action_command_body_slam

extern s32 D_80108AFC;
extern s32 D_80108B28;
extern s32 D_8029275C;
extern s32 D_80292BAC;
extern s32 D_80294320;

ApiStatus N(CreateHudElements)(ScriptInstance* script, s32 isInitialCall) {
    HudElement* hudElement;
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->unk_82 = 0x64;
    battleStatus->unk_434 = &D_80294320;
    battleStatus->unk_86 = 0x7F;
    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }
        
    func_80268858();
    actionCommandStatus->actionCommandID = 0xC;
    actionCommandStatus->unk_61 = 1;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->unk_44 = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = 0;
    battleStatus->actionSuccess = 0;
    actionCommandStatus->hudElementX = -0x30;
    actionCommandStatus->hudElementY = 0x50;

    hudElement = create_hud_element(&D_80108B28);
    actionCommandStatus->hudElements[0] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(&D_80108AFC);
    actionCommandStatus->hudElements[1] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 0x1C);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(&D_80292BAC);
    actionCommandStatus->hudElements[3] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 0x1C);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(&D_8029275C);
    actionCommandStatus->hudElements[2] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX + 0x29, actionCommandStatus->hudElementY + 0x16);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x80);
    return ApiStatus_DONE2;
}

#include "common/MashActionCommandInit.inc.c"

INCLUDE_ASM(s32, "battle/action_cmd/body_slam", func_802A92D4_4285B4);

void N(DrawHudElements)(void) {
    s32 sp14;
    s32 sp10;
    HudElement* hudElement;

    draw_hud_element_clipped(gActionCommandStatus.hudElements[0]);
    hudElement = gActionCommandStatus.hudElements[1];
    draw_hud_element_clipped(hudElement);
    get_hud_element_render_pos(hudElement, &sp10, &sp14);
    draw_hud_element_clipped(gActionCommandStatus.hudElements[3]);
    func_80268770(sp10, sp14, gActionCommandStatus.unk_44 / 100);
    draw_hud_element_clipped(gActionCommandStatus.hudElements[2]);
}

void N(FreeHudElements)(void) {
	free_hud_element(gActionCommandStatus.hudElements[0]);
	free_hud_element(gActionCommandStatus.hudElements[1]);
	free_hud_element(gActionCommandStatus.hudElements[2]);
	free_hud_element(gActionCommandStatus.hudElements[3]);
}