#include "common.h"

ApiStatus N(ChainChompChainUpdateHelperFunc2)(ChainAnimationState* script, f32 magnitude, f32 angleDeg) {
    f32 angle = (angleDeg * TAU) / 360.0f;
    f32 dirX = sin_rad(angle);
    f32 dirY = cos_rad(angle);

    script->currentPos.x = magnitude * dirY;
}
