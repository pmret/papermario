#include "common.h"
#include "hud_element.h"

#define NAMESPACE action_command_spook

extern HudElementAnim HudScript_BlueMeter[];
extern HudElementAnim HudScript_StickNeutral[];
extern HudElementAnim HudScript_100pct[];
extern s32 D_80294440;

ApiStatus func_802A9000_430020(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hudElement;

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
    actionCommandStatus->barFillLevel = 0;
    actionCommandStatus->unk_48 = 0;
    actionCommandStatus->unk_68 = 0;
    battleStatus->actionSuccess = 0;
    battleStatus->unk_84 = 0;
    actionCommandStatus->hudElementX = -48;
    actionCommandStatus->hudElementY = 80;

    hudElement = create_hud_element(HudScript_StickNeutral);
    actionCommandStatus->hudElements[0] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(HudScript_BlueMeter);
    actionCommandStatus->hudElements[1] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    hudElement = create_hud_element(HudScript_100pct);
    actionCommandStatus->hudElements[2] = hudElement;
    set_hud_element_render_pos(hudElement, actionCommandStatus->hudElementX, actionCommandStatus->hudElementY + 28);
    set_hud_element_render_depth(hudElement, 0);
    set_hud_element_flags(hudElement, 0x82);

    return ApiStatus_DONE2;
}

#include "common/MashActionCommandInit.inc.c"

INCLUDE_ASM(s32, "battle/action_cmd/spook", func_802A9298_4302B8);

#include "common/UnkActionCommandFunc1.inc.c"

#include "common/free_hud_elements.inc.c"
