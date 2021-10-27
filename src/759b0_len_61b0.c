#include "common.h"

PlayerStatus* gPlayerStatusPtr = &gPlayerStatus; // maybe wPlayerStatus

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_down);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_down_ahead, s32, f32*, f32*, f32*, f32*, f32, f32);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_down_sides, s32 arg0, f32* arg1, f32* arg2, f32* arg3, f32* arg4);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_up);

s32 npc_raycast_up_corner(s32 ignoreFlags, f32* x, f32* y, f32* z, f32* length);
INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_up_corner, s32 ignoreFlags, f32* x, f32* y, f32* z, f32* length);

INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_up_corners);

s32 npc_raycast_general(s32 ignoreFlags, f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ, f32* hitX,
                        f32* hitY, f32* hitZ, f32* outDepth, f32* hitNx, f32* hitNy, f32* hitNz);
// Dumb float regalloc
#ifdef NON_MATCHING
s32 npc_raycast_general(s32 flags, f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ, f32* hitX,
                        f32* hitY, f32* hitZ, f32* outDepth, f32* hitNx, f32* hitNy, f32* hitNz) {
    s32 entityID;
    s32 ret;

    ret = -1;
    if (flags & 0x100000) {
        entityID = test_ray_entities(startX, startY, startZ, dirX, dirY, dirZ, hitX, hitY, hitZ, outDepth, hitNx, hitNy,
                                     hitNz);
        if (entityID >= 0) {
            ret = entityID | 0x4000;
        }
    } else {
        ret = test_ray_colliders(flags, startX, startY, startZ, dirX, dirY, dirZ, hitX, hitY, hitZ, outDepth, hitNx,
                                 hitNy, hitNz);
        if (flags & 0x40000) {
            return ret;
        }

        entityID = test_ray_entities(startX, startY, startZ, dirX, dirY, dirZ, hitX, hitY, hitZ, outDepth, hitNx,
                                        hitNy, hitNz);
        if (entityID >= 0) {
            ret = entityID | 0x4000;
        }
    }
    return ret;
}
#else
INCLUDE_ASM(s32, "759b0_len_61b0", npc_raycast_general, s32 ignoreFlags, f32 startX, f32 startY, f32 startZ, f32 dirX,
            f32 dirY, f32 dirZ, f32* hitX, f32* hitY, f32* hitZ, f32* outDepth, f32* hitNx, f32* hitNy, f32* hitNz);
#endif

void npc_get_slip_vector(f32* outX, f32* outZ, f32 aX, f32 aZ, f32 bX, f32 bZ) {
    f32 dotProduct = (aX * bX) + (aZ * bZ);

    *outX = (aX - (dotProduct * bX)) * 0.5f;
    *outZ = (aZ - (dotProduct * bZ)) * 0.5f;
}
             
s32 npc_test_move_with_slipping(s32 ignoreFlags, f32 *x, f32 *y, f32 *z, f32 length, f32 yaw, f32 radius) {
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 sp54;
    f32 sp50;
    f32 sp4C;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    f32 temp_f0;
    f32 temp_f20;
    f32 temp_f22;
    f32 temp_f26;
    f32 temp_f28;
    f32 temp_f2;
    s32 temp_s0;
    s32 phi_s5;
    s32 phi_s2 = -1;
    f32 a;
    f32 b;

    sin_cos_rad((yaw * TAU) / 360.0f, &sp38, &sp3C);
    temp_f28 = length * sp38;
    temp_f22 = length + radius + (radius * 0.5f);
    temp_f2 = -sp3C;
    sp3C = temp_f2;
    sp4C = temp_f22;
    temp_f26 = length * temp_f2;
    temp_s0 = npc_raycast_general(ignoreFlags, *x - (radius * sp38 * 0.5f), *y, *z - (radius * temp_f2 * 0.5f), sp38,
                                    0.0f, temp_f2, &sp40, &sp44, &sp48, &sp4C, &sp50, &sp54, &sp58);
    phi_s5 = 0;

    if ((temp_s0 >= 0) && (sp4C <= temp_f22)) {
        temp_f0 = atan2(0.0f, 0.0f, sqrtf((sp50 * sp50) + (sp58 * sp58)), -sp54);
        if ((temp_f0 > 60.0f) && (temp_f0 < 90.0f)) {
            phi_s5 = 1;
        }

        temp_f20 = sp4C - (length + radius + (radius * 0.5f));
        a = temp_f20 * sp38;
        b = temp_f20 * sp3C;
        npc_get_slip_vector(&sp5C, &sp60, temp_f28, temp_f26, sp50, sp58);
        *x += a + sp5C;
        *z += b + sp60;
        D_8010C978 = temp_s0;
        phi_s2 = temp_s0;
    }

    if (phi_s5 == 0) {
        *x += temp_f28;
        *z += temp_f26;
    }

    return phi_s2;
}

s32 npc_test_move_without_slipping(s32 ignoreFlags, f32* x, f32* y, f32* z, f32 length, f32 yaw, f32 radius) {
    s32 ret = -1;
    f32 depth;
    f32 originalDepth;
    f32 dirY;
    f32 cosTheta;
    f32 hitNx, hitNy, hitNz;
    f32 hitX, hitY, hitZ;
    s32 hitID;
    f32 temp1;
    f32 temp2;

    sin_cos_rad(yaw * TAU / 360.0f, &dirY, &cosTheta);
    cosTheta = -cosTheta;
    originalDepth = length + radius + (radius * 0.5f);
    depth = originalDepth;
    temp1 = length * dirY;
    temp2 = length * cosTheta;

    hitID = npc_raycast_general(ignoreFlags, *x - (radius * dirY * 0.5f), *y, *z - (radius * cosTheta * 0.5f), dirY,
                                0.0f, cosTheta, &hitX, &hitY, &hitZ, &depth, &hitNx, &hitNy, &hitNz);

    if (hitID >= 0 && depth <= originalDepth) {
        f32 depthDiff = depth - originalDepth;
        f32 cosThetaTemp = cosTheta; // needed to match

        *x += depthDiff * dirY;
        *z += depthDiff * cosThetaTemp;
        D_8010C978 = hitID;
        ret = hitID;
    }
    
    *x += temp1;
    *z += temp2;
    return ret;
}

s32 npc_test_move_taller_with_slipping(s32 ignoreFlags, f32* x, f32* y, f32* z, f32 length, f32 yaw, f32 height,
                                       f32 radius) {
    f32 xTemp = *x;
    f32 yTemp = *y + height - 1.0f;
    f32 zTemp = *z;
    s32 ret;

    radius *= 0.5f;
    if (npc_test_move_with_slipping(ignoreFlags, &xTemp, &yTemp, &zTemp, fabsf(length), yaw, radius) < 0) {
        xTemp = *x;
        yTemp = *y + 10.01f;
        zTemp = *z;
        ret = npc_test_move_with_slipping(ignoreFlags, &xTemp, &yTemp, &zTemp, fabsf(length), yaw, radius) >= 0;
        *x = xTemp;
        *z = zTemp;
    } else {
        ret = 1;
        *x = xTemp;
        *z = zTemp;
    }
    return ret;
}

s32 npc_test_move_simple_with_slipping(s32 ignoreFlags, f32* x, f32* y, f32* z, f32 length, f32 yaw, f32 height,
                                       f32 radius) {
    f32 tempX = *x;
    f32 tempY = *y + 10.01f;
    f32 tempZ = *z;
    s32 hitID = npc_test_move_with_slipping(ignoreFlags, &tempX, &tempY, &tempZ, fabsf(length), yaw, radius * 0.5f);

    *x = tempX;
    *z = tempZ;

    return hitID >= 0;
}

s32 npc_test_move_simple_without_slipping(s32 ignoreFlags, f32* x, f32* y, f32* z, f32 length, f32 yaw, f32 height,
                                          f32 radius) {
    f32 tempX = *x;
    f32 tempY = *y + 10.01f;
    f32 tempZ = *z;
    s32 hitID = npc_test_move_without_slipping(ignoreFlags, &tempX, &tempY, &tempZ, fabsf(length), yaw, radius * 0.5f);

    *x = tempX;
    *z = tempZ;

    return hitID >= 0;
}


INCLUDE_ASM(s32, "759b0_len_61b0", npc_test_move_complex_with_slipping, s32, f32*, f32*, f32*, f32, f32, f32, f32);
