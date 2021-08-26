#include "common.h"

#define NAMESPACE action_command_0A

INCLUDE_ASM(s32, "battle/action_cmd/0A", func_802A9000_4273B0);

#include "common/MashActionCommandInit.inc.c"

INCLUDE_ASM(s32, "battle/action_cmd/0A", func_802A928C_42763C);

// INCLUDE_ASM(s32, "battle/action_cmd/0A", func_802A955C_42790C);

void func_802A955C_42790C(void) {
    s32 sp14;
    s32 sp10;
    s32 temp_s0;

    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    draw_hud_element_clipped((s32) actionCommandStatus->hudElements[0]);
    temp_s0 = actionCommandStatus->hudElements[1];
    draw_hud_element_clipped((s32) temp_s0);
    get_hud_element_render_pos((s32) temp_s0, &sp10, &sp14);
    if (actionCommandStatus->unk_68 == 0) {
        func_80268770(sp10, sp14, actionCommandStatus->unk_44 / 100);
    } else {
        func_8026880C(sp10, sp14, actionCommandStatus->unk_44 / 100);
    }
    draw_hud_element_clipped((s32) actionCommandStatus->hudElements[2]);
}

#include "common/free_hud_elements.inc.c"
