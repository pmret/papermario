#include "common.h"

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;

    s32 hudX;
    s32 hudY;
    s32 hudElement;
    s32 barFillLevel;

    hud_element_draw_clipped(acs->hudElements[0]);

    hudElement = acs->hudElements[1];
    hud_element_draw_clipped(hudElement);
    hud_element_get_render_pos(hudElement, &hudX, &hudY);

    if (!acs->isBarFilled) {
        draw_mash_meter_multicolor(hudX, hudY, acs->barFillLevel / 100);
    } else {
        draw_mash_meter_blink(hudX, hudY, acs->barFillLevel / 100);
    }

    hud_element_draw_clipped(acs->hudElements[2]);
}
