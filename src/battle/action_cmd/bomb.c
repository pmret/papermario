#include "common.h"

#define NAMESPACE action_command_bomb

void func_80268770(s32, s32, s32);
void func_8026880C(s32, s32, s32);

extern s32 D_80108AFC[0];
extern s32 D_80108B28[0];
extern s32 D_80292974[0];
extern s32 D_80294300;

ApiStatus func_802A9000_427A70(Evt* script, s32 isInitialCall) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

    battleStatus->unk_82 = 0x64;
    battleStatus->unk_434 = &D_80294300;
    battleStatus->unk_86 = 0x7F;

    if (battleStatus->unk_83 == 0) {
        battleStatus->actionSuccess = 0;
        return ApiStatus_DONE2;
    }

    func_80268858();
    actionCommandStatus->actionCommandID = 0xB;
    actionCommandStatus->unk_61 = 1;
    actionCommandStatus->state = 0;
    actionCommandStatus->unk_60 = 0;
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = 0;
    battleStatus->actionSuccess = 0;

    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->hudElementY = 80;

    hudElement = create_hud_element(D_80108B28);
    actionCommandStatus->hudElements[0] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(D_80108AFC);
    actionCommandStatus->hudElements[1] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(D_80292974);
    actionCommandStatus->hudElements[2] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);
    return ApiStatus_DONE2;
}

#include "common/MashActionCommandInit.inc.c"

INCLUDE_ASM(s32, "battle/action_cmd/bomb", func_802A928C_427CFC);

void func_802A96EC_42815C(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    s32 hudX;
    s32 hudY;
    s32 hudElement;
    s32 barFillLevel;

    draw_hud_element_clipped(actionCommandStatus->hudElements[0]);

    hudElement = actionCommandStatus->hudElements[1];
    draw_hud_element_clipped(hudElement);
    get_hud_element_render_pos(hudElement, &hudY, &hudX);

    if (actionCommandStatus->unk_68 == 0) {
        barFillLevel = actionCommandStatus->barFillLevel / 100;
        func_80268770(hudY, hudX, barFillLevel);
    } else {
        barFillLevel = actionCommandStatus->barFillLevel / 100;
        func_8026880C(hudY, hudX, barFillLevel);
    }

    draw_hud_element_clipped(actionCommandStatus->hudElements[2]);
}


#include "common/free_hud_elements.inc.c"
