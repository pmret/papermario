#include "common.h"

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hudX, hudY;
    s32 hid;

    hud_element_draw_clipped(acs->hudElements[0]);

    hid = acs->hudElements[1];
    hud_element_draw_clipped(hid);
    hud_element_get_render_pos(hid, &hudX, &hudY);

    if (!acs->isBarFilled) {
        draw_mash_meter_multicolor(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH);
    } else {
        draw_mash_meter_blink(hudX, hudY, acs->barFillLevel / ONE_PCT_MASH);
    }

    hud_element_draw_clipped(acs->hudElements[2]);
}
