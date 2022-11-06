#include "common.h"

void N(draw)(void) {
    ActionCommandStatus* actionCommandStatus = &gActionCommandStatus;

    s32 hudX;
    s32 hudY;
    s32 hudElement;
    s32 barFillLevel;

    hud_element_draw_clipped(actionCommandStatus->hudElements[0]);

    hudElement = actionCommandStatus->hudElements[1];
    hud_element_draw_clipped(hudElement);
    hud_element_get_render_pos(hudElement, &hudX, &hudY);

    if (!actionCommandStatus->isBarFilled) {
        draw_mash_meter_multicolor(hudX, hudY, actionCommandStatus->barFillLevel / 100);
    } else {
        draw_mash_meter_blink(hudX, hudY, actionCommandStatus->barFillLevel / 100);
    }

    hud_element_draw_clipped(actionCommandStatus->hudElements[2]);
}
