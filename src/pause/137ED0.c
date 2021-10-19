#include "common.h"
#include "hud_element.h"

void pause_tabs_draw_invis(void) {
}

INCLUDE_ASM(s32, "pause/137ED0", pause_tabs_draw_stats);

INCLUDE_ASM(s32, "pause/137ED0", pause_tabs_draw_badges);

INCLUDE_ASM(s32, "pause/137ED0", pause_tabs_draw_items);

INCLUDE_ASM(s32, "pause/137ED0", pause_tabs_draw_party);

INCLUDE_ASM(s32, "pause/137ED0", pause_tabs_draw_spirits);

INCLUDE_ASM(s32, "pause/137ED0", pause_tabs_draw_map);

INCLUDE_ASM(s32, "pause/137ED0", pause_tabs_init);

INCLUDE_ASM(s32, "pause/137ED0", pause_tabs_handle_input);

INCLUDE_ASM(s32, "pause/137ED0", pause_tabs_update);

void pause_tabs_cleanup(void) {
    s32* iconIDs = gPauseMenuTabIconIDs;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(gPauseMenuTabIconIDs); i++) {
        free_hud_element(iconIDs[i]);
    }
}
