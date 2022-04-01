#include "common.h"

extern s32 D_8010C968;
extern s32 D_8010C98C;

s32 func_80262130(f32 inX, f32 inY, f32 inZ, f32 arg3, f32 radius) {
    f32 x = inX;
    f32 y = inY;
    f32 z = inZ;
    f32 hitDepth = arg3;
    s32 ret = FALSE;
    s32 phi_s0 = 0;

    if (npc_raycast_down_around(0, &x, &y, &z, &hitDepth, 90.0f, radius) && hitDepth <= arg3) {
        s32 type = get_collider_type_by_id(D_8010C98C & 0xFF);
        s32 type2 = get_collider_type_by_id(D_8010C968 & 0xFF);

        phi_s0 = type & type2;
        if (phi_s0 != (D_8010C98C & 0xFF)) {
            phi_s0 = 0;
        }
    }

    if (phi_s0 == 1) {
        ret = TRUE;
    }

    return ret;
}

s32 func_8026220C(f32 arg0, f32 arg1) {
    return (arg1 > 100.0f) ? 28 : 0;
}
