#include "common.h"

extern s32 NpcHitQueryBehindCollider;
extern s32 NpcHitQueryAheadCollider;

s32 func_80262130(f32 inX, f32 inY, f32 inZ, f32 height, f32 radius) {
    f32 x = inX;
    f32 y = inY;
    f32 z = inZ;
    f32 hitDepth = height;
    s32 ret = FALSE;
    s32 combinedFlags = 0;

    if (npc_raycast_down_around(0, &x, &y, &z, &hitDepth, 90.0f, radius) && hitDepth <= height) {
        s32 colliderAheadFlags = get_collider_flags(NpcHitQueryAheadCollider & 0xFF);
        s32 colliderBehindFlags = get_collider_flags(NpcHitQueryBehindCollider & 0xFF);

        combinedFlags = colliderAheadFlags & colliderBehindFlags;
        if (combinedFlags != (NpcHitQueryAheadCollider & 0xFF)) {
            combinedFlags = 0;
        }
    }

    if (combinedFlags == 1) {
        ret = TRUE;
    }

    return ret;
}

s32 func_8026220C(f32 arg0, f32 arg1) {
    return (arg1 > 100.0f) ? 28 : 0;
}
