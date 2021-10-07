#include "common.h"

void func_80268770(s32, s32, s32);
void func_8026880C(s32, s32, s32);

void N(UnkActionCommandFunc1)(void) {
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
        func_80268770(hudY, hudX, actionCommandStatus->barFillLevel / 100);
    } else {
        func_8026880C(hudY, hudX, actionCommandStatus->barFillLevel / 100);
    }

    draw_hud_element_clipped(actionCommandStatus->hudElements[2]);
}
