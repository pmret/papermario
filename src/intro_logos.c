#include "common.h"

void intro_logos_set_fade_alpha(s16 alpha) {
    gGameStatusPtr->bootAlpha = alpha;
}

void intro_logos_set_fade_color(s16 color) {
    gGameStatusPtr->bootRed = color;
    gGameStatusPtr->bootGreen = color;
    gGameStatusPtr->bootBlue = color;
}

s32 intro_logos_fade_in(s16 subtractAlpha) {
    if (gGameStatusPtr->bootAlpha != 0) {
        gGameStatusPtr->bootAlpha -= subtractAlpha;
        if (gGameStatusPtr->bootAlpha < 0) {
            gGameStatusPtr->bootAlpha = 0;
        }
    } else {
        return TRUE;
    }
    return FALSE;
}

s32 intro_logos_fade_out(s16 addAlpha) {
    if (gGameStatusPtr->bootAlpha != 255) {
        gGameStatusPtr->bootAlpha += addAlpha;
        if (gGameStatusPtr->bootAlpha > 255) {
            gGameStatusPtr->bootAlpha = 255;
        }
    } else {
        return TRUE;
    }
    return FALSE;
}

void intro_logos_update_fade(void) {
    set_screen_overlay_params_front(OVERLAY_SCREEN_COLOR, gGameStatusPtr->bootAlpha);
    set_screen_overlay_color(SCREEN_LAYER_FRONT, gGameStatusPtr->bootBlue, gGameStatusPtr->bootGreen, gGameStatusPtr->bootRed);
}
