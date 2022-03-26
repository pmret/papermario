#include "common.h"

void N(UnkActionCommandFunc1)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    s32 hudX;
    s32 hudY;
    s32 hudElement;
    s32 barFillLevel;

    hud_element_draw_clipped(actionCommandStatus->hudElements[0]);

    hudElement = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(hudElement);
    hud_element_get_render_pos(hudElement, &hudX, &hudY);

    if (actionCommandStatus->unk_68 == 0) {
        func_80268770(hudX, hudY, actionCommandStatus->barFillLevel / 100);
    } else {
        func_8026880C(hudX, hudY, actionCommandStatus->barFillLevel / 100);
    }

    hud_element_draw_clipped(actionCommandStatus->hudElements[2]);
}
