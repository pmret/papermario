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
             
s32 npc_test_move_with_slipping(s32 ignoreFlags, f32* x, f32* y, f32* z, f32 length, f32 yaw, f32 radius) {
    f32 outX, outY;
    f32 bX, bZ;
    f32 hitNy;
    f32 hitDepth;
    f32 hitX, hitY, hitZ;
    f32 outSinTheta, outCosTheta;
    f32 temp_f0, temp_f20, temp_f22;
    f32 aX, aZ;
    f32 inverseOutCosTheta;
    s32 raycastHitID;
    s32 phi_s5;
    s32 phi_s2 = -1;
    f32 a, b;

    sin_cos_rad((yaw * TAU) / 360.0f, &outSinTheta, &outCosTheta);
    aX = length * outSinTheta;
    temp_f22 = length + radius + (radius * 0.5f);
    inverseOutCosTheta = -outCosTheta;
    outCosTheta = inverseOutCosTheta;
    hitDepth = temp_f22;
    aZ = length * inverseOutCosTheta;
    raycastHitID = npc_raycast_general(ignoreFlags, *x - (radius * outSinTheta * 0.5f), *y,
                                        *z - (radius * inverseOutCosTheta * 0.5f), outSinTheta,
                                        0.0f, inverseOutCosTheta, &hitX, &hitY, &hitZ, &hitDepth, &bX, &hitNy, &bZ);
    phi_s5 = FALSE;

    if (raycastHitID >= 0 && hitDepth <= temp_f22) {
        temp_f0 = atan2(0.0f, 0.0f, sqrtf(SQ(bX) + SQ(bZ)), -hitNy);
        if ((temp_f0 > 60.0f) && (temp_f0 < 90.0f)) {
            phi_s5 = TRUE;
        }

        temp_f20 = hitDepth - (length + radius + (radius * 0.5f));
        a = temp_f20 * outSinTheta;
        b = temp_f20 * outCosTheta;
        npc_get_slip_vector(&outX, &outY, aX, aZ, bX, bZ);
        *x += a + outX;
        *z += b + outY;
        D_8010C978 = raycastHitID;
        phi_s2 = raycastHitID;
    }

    if (phi_s5 == 0) {
        *x += aX;
        *z += aZ;
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
