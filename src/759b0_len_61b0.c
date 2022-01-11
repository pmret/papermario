#include "common.h"

extern s32 D_8010C970;
extern s32 D_8010C94C;
extern s32 D_8010C974;
extern s32 D_8010C98C;
extern s32 D_8010C968;

PlayerStatus* gPlayerStatusPtr = &gPlayerStatus; // maybe wPlayerStatus

s32 npc_raycast_down(s32 flags, f32 *startX, f32 *startY, f32 *startZ, f32 *hitDepth) {
    f32 hitX;
    f32 hitY;
    f32 hitZ;
    f32 cHitDepth;
    f32 hitNx;
    f32 hitNy;
    f32 hitNz;
    f32 eHitX;
    f32 eHitY;
    f32 eHitZ;
    f32 eHitDepth;
    f32 eHitNx;
    f32 eHitNy;
    f32 eHitNz;
    s32 entityID;
    s32 colliderID;
    f32 sx, sy, sz;

    eHitDepth = cHitDepth = fabsf(*hitDepth);
    sx = *startX;
    sy = *startY;
    sz = *startZ;
    colliderID = test_ray_colliders(flags, sx, sy, sz, 0.0f, -1.0f, 0.0f, &hitX, &hitY, &hitZ, &cHitDepth, &hitNx, &hitNy, &hitNz);
    if ((flags & 0x40000) == 0)  {
        entityID = test_ray_entities(*startX, *startY, *startZ, 0.0f, -1.0f, 0.0f, &eHitX, &eHitY, &eHitZ, &eHitDepth, &eHitNx, &eHitNy, &eHitNz);
        if (entityID >= 0) {
            colliderID = entityID | 0x4000;
            if (eHitDepth < cHitDepth) {
                cHitDepth = eHitDepth;
                hitX = eHitX;
                hitY = eHitY;
                hitZ = eHitZ;
                hitNx = eHitNx;
                hitNy = eHitNy;
                hitNz = eHitNz;
            }
        }
        if (colliderID < 0) {
            return colliderID;
        }
    }

    *hitDepth = cHitDepth;
    *startX = hitX;
    *startY = hitY;
    *startZ = hitZ;

    if (colliderID < 0 ) {
        return colliderID;
    }

    gGameStatusPtr->playerGroundTraceNormal.x = hitNx;
    gGameStatusPtr->playerGroundTraceNormal.y = hitNy;
    gGameStatusPtr->playerGroundTraceNormal.z = hitNz;
    gGameStatusPtr->playerGroundTraceAngles.x = -atan2(0.0f, 0.0f, hitNz * 100.0f, hitNy * 100.0f);
    gGameStatusPtr->playerGroundTraceAngles.y = 0.0f;
    gGameStatusPtr->playerGroundTraceAngles.z = -atan2(0.0f, 0.0f, hitNx * 100.0f, hitNy * 100.0f);

    return colliderID;
}

s32 npc_raycast_down_ahead(s32 flags, f32 *posX, f32 *posY, f32 *posZ, f32 *hitDepth, f32 yaw, f32 radius) {
    f32 startX;
    f32 startY;
    f32 startZ;
    f32 depth; //sp24
    f32 x;
    f32 y;
    f32 z;
    f32 originalDepth;
    f32 sp38;
    s32 hasCollision;

    f32 cosTheta;
    s32 colliderID;
    f32 deltaX,deltaZ;

    f32 theta, sinTheta, smallerRadius, minDepth, f28, f30;

    hasCollision = FALSE;

    x = *posX;
    y = *posY;
    z = *posZ;

    smallerRadius = radius;

    D_8010C970 = y;
    D_8010C94C = *posY;
    D_8010C974 = *posY;

    smallerRadius /= 2.5;
    sp38 = f30 = f28 = -32767.0f;

    minDepth = fabsf(*hitDepth);
    theta = (clamp_angle(yaw + 0.0f) * TAU) / 360.0f;
    sinTheta = sin_rad(theta);
    cosTheta = cos_rad(theta);

    deltaX = smallerRadius * sinTheta;
    deltaZ = -smallerRadius * cosTheta;

    startX = x + deltaX;
    startY = y;
    startZ = z + deltaZ;
    originalDepth = depth = minDepth;

    colliderID = npc_raycast_down(flags, &startX, &startY, &startZ, &depth);
    if (colliderID >= 0) {
        if (depth <= minDepth) {
            f28 = startY;
            D_8010C978 = colliderID;
            D_8010C98C = colliderID;
            D_8010C970 = f28;
            minDepth = depth;

            hasCollision = TRUE;
        }
    }


    theta = clamp_angle(yaw + 120.0f) * TAU / 360.0f;
    sinTheta = sin_rad(theta);
    cosTheta = cos_rad(theta);
    deltaX = smallerRadius * sinTheta;
    deltaZ = -smallerRadius * cosTheta;

    startX = x + deltaX;
    startY = y;
    startZ = z + deltaZ;
    depth = originalDepth;

    colliderID = npc_raycast_down(flags, &startX, &startY, &startZ, &depth);
    if (colliderID >= 0) {
        if (depth <= minDepth) {
            f30 = startY;
            D_8010C978 = colliderID;
            D_8010C968 = colliderID;
            D_8010C94C = f30;
            minDepth = depth;
            hasCollision = TRUE;
        }
    }

    theta = clamp_angle(yaw - 120.0f) * TAU / 360.0f;
    sinTheta = sin_rad(theta);
    cosTheta = cos_rad(theta);
    deltaX = smallerRadius * sinTheta;
    deltaZ = -smallerRadius * cosTheta;

    startX = x + deltaX;
    startY = y;
    startZ = z + deltaZ;
    depth = originalDepth;

    colliderID = npc_raycast_down(flags, &startX, &startY, &startZ, &depth);
    if (colliderID >= 0) {
        if (depth <= minDepth) {
            sp38 = startY;
            D_8010C978 = colliderID;
            D_8010C968 = colliderID;
            D_8010C974 = sp38;
            minDepth = depth;

            hasCollision = TRUE;
        }
    }

    if (hasCollision) {
        *posY = MAX(f30, f28);
        if (*posY < sp38) {
            *posY = sp38;
        }
        *hitDepth = minDepth;
        return TRUE;
    }

    *posY = startY;
    return FALSE;
}

s32 npc_raycast_down_sides(s32 flags, f32 *posX, f32 *posY, f32 *posZ, f32 *hitDepth) {
    f32 startX;
    f32 startY;
    f32 startZ;
    f32 depth; //sp24
    f32 x;
    f32 y;
    f32 z;
    f32 originalDepth;
    f32 sp38;
    s32 hasCollision;

    f32 cosTheta;
    s32 colliderID;
    f32 deltaX,deltaZ;

    f32 yaw;

    f32 theta, sinTheta, minDepth, f28, f30, radius;

    hasCollision = FALSE;

    x = *posX;
    y = *posY;
    z = *posZ;

    D_8010C970 = y;
    D_8010C94C = *posY;
    D_8010C974 = *posY;

    sp38 = f30 = f28 = -32767.0f;
    yaw = 0.0f;

    minDepth = fabsf(*hitDepth);
    theta = (clamp_angle(yaw) * TAU) / 360.0f;
    sinTheta = sin_rad(theta);
    cosTheta = cos_rad(theta);

    radius = 10.0f;

    deltaX = radius * sinTheta;
    deltaZ = -radius * cosTheta;

    startX = x + deltaX;
    startY = y;
    startZ = z + deltaZ;
    originalDepth = depth = minDepth;

    colliderID = npc_raycast_down(flags, &startX, &startY, &startZ, &depth);
    if (colliderID >= 0) {
        if (depth <= minDepth) {
            f28 = startY;
            D_8010C978 = colliderID;
            D_8010C98C = colliderID;
            D_8010C970 = f28;
            minDepth = depth;
            hasCollision = TRUE;
        }
    }

    theta = clamp_angle(yaw + 180.0f) * TAU / 360.0f;
    sinTheta = sin_rad(theta);
    cosTheta = cos_rad(theta);

    deltaX = radius * sinTheta;
    deltaZ = -radius * cosTheta;

    startX = x + deltaX;
    startY = y;
    startZ = z + deltaZ;
    depth = originalDepth;

    colliderID = npc_raycast_down(flags, &startX, &startY, &startZ, &depth);
    if (colliderID >= 0) {
        if (depth <= minDepth) {
            f30 = startY;
            D_8010C978 = colliderID;
            D_8010C968 = colliderID;
            D_8010C94C = f30;
            minDepth = depth;
            hasCollision = TRUE;
        }
    }

    if (hasCollision) {
        *posY = MAX(f30, f28);
        if (*posY < sp38) {
            *posY = sp38;
        }
        *hitDepth = minDepth;
        return TRUE;
    }

    return FALSE;
}

s32 npc_raycast_up(s32 flags, f32 *startX, f32 *startY, f32 *startZ, f32 *hitDepth) {
    f32 hitX;
    f32 hitY;
    f32 hitZ;
    f32 cHitDepth;
    f32 hitNx;
    f32 hitNy;
    f32 hitNz;
    f32 eHitX;
    f32 eHitY;
    f32 eHitZ;
    f32 eHitDepth;
    f32 eHitNx;
    f32 eHitNy;
    f32 eHitNz;
    s32 entityID;
    s32 colliderID;
    f32 sx, sy, sz;
    s32 ret;

    eHitDepth = cHitDepth = *hitDepth;
    sx = *startX;
    sy = *startY;
    sz = *startZ;
    ret = test_ray_colliders(flags, sx, sy, sz, 0.0f, 1.0f, 0.0f, &hitX, &hitY, &hitZ, &cHitDepth, &hitNx, &hitNy, &hitNz);
    colliderID = ret;
    if ((flags & 0x40000) == 0)  {
        entityID = test_ray_entities(sx, sy, sz, 0.0f, 1.0f, 0.0f, &eHitX, &eHitY, &eHitZ, &eHitDepth, &eHitNx, &eHitNy, &eHitNz);
        ret = entityID | 0x4000;
        if (entityID >= 0) {
            cHitDepth = eHitDepth;
            hitX = eHitX;
            hitY = eHitY;
            hitZ = eHitZ;
            hitNx = eHitNx;
            hitNy = eHitNy;
            hitNz = eHitNz;
        } else {
            ret = colliderID;
        }
    }

    if (ret < 0) {
        // TODO find better match
        colliderID = 0;
        return colliderID;
    } else {
        *hitDepth = cHitDepth;
        *startX = hitX;
        *startY = hitY;
        *startZ = hitZ;
        D_8010C978 = ret;
        return TRUE;
    }
}

s32 npc_raycast_up_corner(s32 ignoreFlags, f32* x, f32* y, f32* z, f32* length) {
    f32 hitX;
    f32 hitY;
    f32 hitZ;
    f32 hitDepth;
    f32 hitNx;
    f32 hitNy;
    f32 hitNz;
    s32 colliderID;
    s32 entityID;
    f32 sx, sy, sz;
    f32 sx2, sy2, sz2;
    s32 ret = -1;

    sx2 = sx = *x;
    sy2 = sy = *y;
    sz2 = sz = *z;
    hitDepth = *length;
    colliderID = test_ray_colliders(ignoreFlags, sx, sy, sz, 0.0f, 1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth, &hitNx, &hitNy, &hitNz);
    if (colliderID >= 0 && *length > hitDepth) {
        *length = hitDepth;
        ret = colliderID;
        *x = sx = sx2;
        *y = sy = sy2;
        *z = sz = sz2;
    }

    hitDepth = 10.0f;
    entityID = test_ray_entities(*x, *y, *z, 0.0f, 1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth, &hitNx, &hitNy, &hitNz);
    sx = sx2;
    sy = sy2;
    sz = sz2;
    if (entityID >= 0 && *length > hitDepth) {
        ret = entityID | 0x4000;
        *length = hitDepth;
        *x = sx;
        *y = sy;
        *z = sz;
    }

    return ret;
}

s32 npc_raycast_up_corners(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 arg5, f32 arg6) {
    f32 sp18;
    f32 sp1C;
    f32 sp20;
    f32 sp24;
    f32 temp_f20;
    f32 temp_f26;
    f32 temp_f28;
    f32 x,y,z;
    s32 phi_s4;
    s32 phi_v0;
    f32 q;

    temp_f20 = (arg5 * 6.28318f) / 360.0f;
    temp_f28 = arg6 * sin_rad(temp_f20);
    q = -arg6; // TODO find better match
    temp_f26 = q * cos_rad(temp_f20);

    x = *arg1;
    y = *arg2;
    z = *arg3;

    sp24 = *arg4;
    sp18 = x + temp_f28;
    sp1C = y;
    sp20 = z + temp_f26;

    phi_s4 = -1;
    phi_v0 = npc_raycast_up_corner(arg0, &sp18, &sp1C, &sp20, &sp24);

    if (phi_v0 < 0) {
        sp18 = x - temp_f28;
        sp1C = y;
        sp20 = z - temp_f26;
        phi_v0 = npc_raycast_up_corner(arg0, &sp18, &sp1C, &sp20, &sp24);
    }

    if (phi_v0 < 0) {
        sp18 = x + temp_f26;
        sp1C = y;
        sp20 = z + temp_f28;
        phi_v0 = npc_raycast_up_corner(arg0, &sp18, &sp1C, &sp20, &sp24);
    }

    if (phi_v0 < 0) {
        sp18 = x - temp_f26;
        sp1C = y;
        sp20 = z - temp_f28;
        phi_v0 = npc_raycast_up_corner(arg0, &sp18, &sp1C, &sp20, &sp24);
    }

    if (phi_v0 >= 0) {
        *arg1 = sp18;
        *arg2 = sp1C;
        *arg3 = sp20;
        *arg4 = sp24;
        phi_s4 = phi_v0;
    }

    if (phi_s4 < 0) {
        *arg1 = sp18;
        *arg2 = sp1C;
        *arg3 = sp20;
        *arg4 = 0;
    }

    return phi_s4;
}


s32 npc_raycast_general(s32 ignoreFlags, f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ, f32* hitX,
                        f32* hitY, f32* hitZ, f32* outDepth, f32* hitNx, f32* hitNy, f32* hitNz);
// Dumb float regalloc
#ifdef NON_EQUIVALENT
s32 npc_raycast_general(s32 flags, f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ, f32* hitX,
                        f32* hitY, f32* hitZ, f32* outDepth, f32* hitNx, f32* hitNy, f32* hitNz) {
    s32 ret;
    s32 entityID;

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
        if (temp_f0 > 60.0f && temp_f0 < 90.0f) {
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
