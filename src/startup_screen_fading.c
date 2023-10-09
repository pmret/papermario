#include "common.h"

void startup_set_fade_screen_alpha(s16 alpha) {
    gGameStatusPtr->screenColorA = alpha;
}

void startup_set_fade_screen_color(s16 color) {
    gGameStatusPtr->screenColorB = color;
    gGameStatusPtr->screenColorG = color;
    gGameStatusPtr->screenColorR = color;
}

b32 startup_fade_screen_in(s16 subtractAlpha) {
    if (gGameStatusPtr->screenColorA == 0) {
        return TRUE;
    }

    gGameStatusPtr->screenColorA -= subtractAlpha;
    if (gGameStatusPtr->screenColorA < 0) {
        gGameStatusPtr->screenColorA = 0;
    }

    return FALSE;
}

b32 startup_fade_screen_out(s16 addAlpha) {
    if (gGameStatusPtr->screenColorA == 255) {
        return TRUE;
    }

    gGameStatusPtr->screenColorA += addAlpha;
    if (gGameStatusPtr->screenColorA > 255) {
        gGameStatusPtr->screenColorA = 255;
    }
   
    return FALSE;
}

void startup_fade_screen_update(void) {
    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, gGameStatusPtr->screenColorA);
    set_screen_overlay_color(SCREEN_LAYER_FRONT,
        gGameStatusPtr->screenColorR,
        gGameStatusPtr->screenColorG,
        gGameStatusPtr->screenColorB);
}
