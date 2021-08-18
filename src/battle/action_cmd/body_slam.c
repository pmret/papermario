#include "common.h"

#define NAMESPACE action_command_body_slam

extern s32 D_80108AFC;
extern s32 D_80108B28;
extern s32 D_8029275C;
extern s32 D_80292BAC;
extern s32 D_80294320;

ApiStatus N(CreateHudElements)(ScriptInstance* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElement* hudElement;

    battleStatus->unk_82 = 100;
    battleStatus->unk_434 = &D_80294320;
    battleStatus->unk_86 = 127;
    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }
        
    func_80268858();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_BODY_SLAM;
    actionCommandStatus->unk_61 = 1;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->unk_44 = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = 0;
    battleStatus->actionSuccess = 0;
    actionCommandStatus->hudElementX = -48;
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

    hudElement = create_hud_element(&D_80292BAC);
    actionCommandStatus->hudElements[3] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(&D_8029275C);
    actionCommandStatus->hudElements[2] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX + 41, actionCommandStatus->hudElementY + 22);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x80);
    return ApiStatus_DONE2;
}

#include "common/MashActionCommandInit.inc.c"

INCLUDE_ASM(s32, "battle/action_cmd/body_slam", func_802A92D4_4285B4);

void N(draw_hud_elements)(void) {
    s32 x, y;
    HudElement* hudElement;

    draw_hud_element_clipped(gActionCommandStatus.hudElements[0]);
    hudElement = gActionCommandStatus.hudElements[1];
    draw_hud_element_clipped(hudElement);
    get_hud_element_render_pos(hudElement, &x, &y);
    draw_hud_element_clipped(gActionCommandStatus.hudElements[3]);
    func_80268770(x, y, gActionCommandStatus.unk_44 / 100);
    draw_hud_element_clipped(gActionCommandStatus.hudElements[2]);
}

void N(free_hud_elements)(void) {
	hud_element_free(gActionCommandStatus.hudElements[0]);
	hud_element_free(gActionCommandStatus.hudElements[1]);
	hud_element_free(gActionCommandStatus.hudElements[2]);
	hud_element_free(gActionCommandStatus.hudElements[3]);
}
