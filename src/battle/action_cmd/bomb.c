#include "common.h"

#define NAMESPACE action_command_bomb

extern HudElementAnim D_80108AFC;
extern HudElementAnim D_80108B28;
extern HudElementAnim D_80292974;
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

    hudElement = create_hud_element(&D_80292974);
    actionCommandStatus->hudElements[2] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);
    return ApiStatus_DONE2;
}

#include "common/MashActionCommandInit.inc.c"

INCLUDE_ASM(s32, "battle/action_cmd/bomb", func_802A928C_427CFC);

#include "battle/action_cmd/common/UnkActionCommandFunc1.inc.c"

#include "common/free_hud_elements.inc.c"
