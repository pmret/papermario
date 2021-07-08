#include "common.h"

void state_init_intro(void) {
    s8 unk_A8;

    gGameStatusPtr->loadMenuState = 0;

    set_curtain_scale_goal(1.0f);
    set_curtain_fade_goal(0.3f);

    unk_A8 = gGameStatusPtr->creditsViewportMode;
    switch (unk_A8) {
        case 0:
            intro_logos_set_fade_alpha(0);

            D_800A0954 = 0xFF;
            D_800A0956 = 0x10;
            D_800A0958 = 4;
            D_800A0960 = 0;
            D_800A095A = 0xD0;
            D_800A095C = 0xD0;
            D_800A095E = 0xD0;
            D_800A0964 = 0;

            // hos_05 (Star Sanctuary)
            gGameStatusPtr->areaID = AREA_HOS;
            gGameStatusPtr->mapID = 5;
            gGameStatusPtr->entryID = 3;
            break;
        case 1:
            intro_logos_set_fade_alpha(0);

            D_800A0954 = 0;
            D_800A0956 = 0xC;
            D_800A0958 = 4;
            D_800A0960 = unk_A8;
            D_800A095A = 0;
            D_800A095C = 0;
            D_800A095E = 0;
            D_800A0964 = 0;

            // hos_04 (Outside the Sanctuary)
            gGameStatusPtr->areaID = AREA_HOS;
            gGameStatusPtr->mapID = 4;
            gGameStatusPtr->entryID = 4;
            break;
        default:
            intro_logos_set_fade_alpha(0);
            intro_logos_set_fade_color(208);

            gGameStatusPtr->creditsViewportMode = -1;

            D_800A0956 = 6;
            D_800A0958 = 6;

            D_800779B0++;
            if (D_800779B0 >= 4) {
                D_800779B0 = 0;
            }

            D_800A0964 = 3;
            break;
    }

    set_screen_overlay_params_back(D_800A0963, D_800A0954);
    set_screen_overlay_color(1, D_800A095B, D_800A095D, D_800A095F);

    intro_logos_update_fade();
}

INCLUDE_ASM(void, "state_intro", state_step_intro, void);

void state_drawUI_intro(void) {
}
