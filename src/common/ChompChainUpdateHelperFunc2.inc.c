#include "common.h"

ApiStatus N(ChompChainUpdateHelperFunc2)(f32* x, f32 magnitude, f32 angleDeg) {
    f32 angle = (angleDeg * TAU) / 360.0f;
    f32 dirX = sin_rad(angle);
    f32 dirY = cos_rad(angle);

    *x = magnitude * dirY;
}
