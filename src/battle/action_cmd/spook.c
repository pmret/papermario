#include "common.h"

#define NAMESPACE action_command_spook

extern s32 D_80108AFC;
extern s32 D_80108E1C;
extern s32 D_80292974;
extern s32 D_80294440;

ApiStatus func_802A9000_430020(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    HudElement* hudElement;

    battleStatus->unk_82 = 100;
    battleStatus->unk_434 = &D_80294440;
    battleStatus->unk_86 = 127;
    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }
    func_80268858();
    actionCommandStatus->actionCommandID = ACTION_COMMAND_SPOOK;
    actionCommandStatus->unk_61 = 1;
    actionCommandStatus->unk_6C = 30;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->unk_44 = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_84 = 0;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->hudElementY = 80;

    hudElement = create_hud_element(&D_80108E1C);
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

#include "common/MashActionCommandInit.inc.c"

// wip: decomp.me/scratch/tAhNa
INCLUDE_ASM(s32, "battle/action_cmd/spook", func_802A9298_4302B8);

void func_802A97FC_43081C(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 renderPosY;
    s32 renderPosX;
    HudElement* hudElement;

    draw_hud_element_clipped(actionCommandStatus->hudElements[0]);
    hudElement = actionCommandStatus->hudElements[1];
    draw_hud_element_clipped(hudElement);
    get_hud_element_render_pos(hudElement, &renderPosX, &renderPosY);
    if (actionCommandStatus->unk_68 == 0) {
        func_80268770(renderPosX, renderPosY, actionCommandStatus->unk_44 / 100);
    } else {
        func_8026880C(renderPosX, renderPosY, actionCommandStatus->unk_44 / 100);
    }
    draw_hud_element_clipped(actionCommandStatus->hudElements[2]);
}

#include "common/free_hud_elements.inc.c"
