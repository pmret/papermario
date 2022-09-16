#include "common.h"

ApiStatus N(ChompChainUpdateHelperFunc)(ChompChainAnimationState* script, f32 magnitude, f32 angleDeg) {
    f32 angle = DEG_TO_RAD(angleDeg);
    f32 dirX = sin_rad(angle);
    f32 dirY = cos_rad(angle);

    script->currentPos.x += -magnitude * dirX;
    script->currentPos.y += magnitude * dirY;
}
