#include "common.h"

#define NAMESPACE action_command_0A

INCLUDE_ASM(s32, "battle/action_cmd/0A", func_802A9000_4273B0);

#include "common/MashActionCommandInit.inc.c"

INCLUDE_ASM(s32, "battle/action_cmd/0A", func_802A928C_42763C);

void func_802A955C_42790C(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;
    s32 renderPosX;
    s32 renderPosY;
    s32 hudElementID;

    draw_hud_element_clipped(actionCommandStatus->hudElements[0]);
    hudElementID = actionCommandStatus->hudElements[1];
    draw_hud_element_clipped(hudElementID);
    get_hud_element_render_pos(hudElementID, &renderPosX, &renderPosY);
    if (actionCommandStatus->unk_68 == 0) {
        func_80268770(renderPosX, renderPosY, actionCommandStatus->barFillLevel / 100);
    } else {
        func_8026880C(renderPosX, renderPosY, actionCommandStatus->barFillLevel / 100);
    }
    draw_hud_element_clipped(actionCommandStatus->hudElements[2]);
}

#include "common/free_hud_elements.inc.c"
