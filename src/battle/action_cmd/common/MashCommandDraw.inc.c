#include "common.h"

void N(draw)(void) {
    ActionCommandStatus* acs = &gActionCommandStatus;
    s32 hudX, hudY;
    HudElemID hid;

    hud_element_draw_clipped(acs->hudElemIDs[0]);

    hid = acs->hudElemIDs[1];
    hud_element_draw_clipped(hid);
    hud_element_get_render_pos(hid, &hudX, &hudY);

    if (!acs->isMeterFilled) {
        draw_mash_meter_multicolor(hudX, hudY, acs->meterFillLevel / ONE_PCT_MASH);
    } else {
        draw_mash_meter_blink(hudX, hudY, acs->meterFillLevel / ONE_PCT_MASH);
    }

    hud_element_draw_clipped(acs->hudElemIDs[2]);
}
