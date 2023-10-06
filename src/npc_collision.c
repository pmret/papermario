#include "common.h"

SHIFT_BSS s32 NpcHitQueryBehindRightY;
SHIFT_BSS s32 NpcHitQueryBehindCollider;
SHIFT_BSS s32 NpcHitQueryAheadCollider;
SHIFT_BSS s32 NpcHitQueryAheadY;
SHIFT_BSS s32 NpcHitQueryBehindLeftY;
SHIFT_BSS s32 NpcHitQueryColliderID;

PlayerStatus* gPlayerStatusPtr = &gPlayerStatus; // maybe wPlayerStatus

s32 npc_raycast_down(s32 ignoreFlags, f32* startX, f32* startY, f32* startZ, f32* hitDepth) {
    f32 cHitX;
    f32 cHitY;
    f32 cHitZ;
    f32 cHitDepth;
    f32 cHitNx;
    f32 cHitNy;
    f32 cHitNz;
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
    colliderID = test_ray_colliders(ignoreFlags, sx, sy, sz, 0.0f, -1.0f, 0.0f, &cHitX, &cHitY, &cHitZ, &cHitDepth, &cHitNx, &cHitNy, &cHitNz);
    if (!(ignoreFlags & COLLISION_IGNORE_ENTITIES))  {
        entityID = test_ray_entities(*startX, *startY, *startZ, 0.0f, -1.0f, 0.0f, &eHitX, &eHitY, &eHitZ, &eHitDepth, &eHitNx, &eHitNy, &eHitNz);
        if (entityID >= 0) {
            colliderID = entityID | COLLISION_WITH_ENTITY_BIT;
            if (eHitDepth < cHitDepth) {
                cHitDepth = eHitDepth;
                cHitX = eHitX;
                cHitY = eHitY;
                cHitZ = eHitZ;
                cHitNx = eHitNx;
                cHitNy = eHitNy;
                cHitNz = eHitNz;
            }
        }
        if (colliderID < 0) {
            return colliderID;
        }
    }

    *hitDepth = cHitDepth;
    *startX = cHitX;
    *startY = cHitY;
    *startZ = cHitZ;

    if (colliderID < 0) {
        return colliderID;
    }

    gGameStatusPtr->playerGroundTraceNormal.x = cHitNx;
    gGameStatusPtr->playerGroundTraceNormal.y = cHitNy;
    gGameStatusPtr->playerGroundTraceNormal.z = cHitNz;
    gGameStatusPtr->playerGroundTraceAngles.x = -atan2(0.0f, 0.0f, cHitNz * 100.0f, cHitNy * 100.0f);
    gGameStatusPtr->playerGroundTraceAngles.y = 0.0f;
    gGameStatusPtr->playerGroundTraceAngles.z = -atan2(0.0f, 0.0f, cHitNx * 100.0f, cHitNy * 100.0f);

    return colliderID;
}

b32 npc_raycast_down_around(s32 ignoreFlags, f32* posX, f32* posY, f32* posZ, f32* hitDepth, f32 yaw, f32 radius) {
    f32 startX;
    f32 startY;
    f32 startZ;
    f32 depth;
    f32 x;
    f32 y;
    f32 z;
    f32 originalDepth;
    f32 hitYBehindLeft;
    s32 hasCollision;
    f32 cosTheta;
    s32 colliderID;
    f32 deltaX,deltaZ;
    f32 theta, sinTheta, minDepth, hitYAhead, hitYBehindRight;

    hasCollision = FALSE;
    x = *posX;
    y = *posY;
    z = *posZ;
    NpcHitQueryAheadY = *posY;
    NpcHitQueryBehindRightY = *posY;
    NpcHitQueryBehindLeftY = *posY;
    radius /= 2.5;
    hitYBehindLeft = hitYBehindRight = hitYAhead = -32767.0f;
    minDepth = fabsf(*hitDepth);

    theta = DEG_TO_RAD(clamp_angle(yaw + 0.0f));
    sinTheta = sin_rad(theta);
    cosTheta = cos_rad(theta);
    deltaX = radius * sinTheta;
    deltaZ = -radius * cosTheta;

    startX = x + deltaX;
    startY = y;
    startZ = z + deltaZ;
    originalDepth = depth = minDepth;

    colliderID = npc_raycast_down(ignoreFlags, &startX, &startY, &startZ, &depth);
    if (colliderID >= 0) {
        if (depth <= minDepth) {
            hitYAhead = startY;
            NpcHitQueryColliderID = colliderID;
            NpcHitQueryAheadCollider = colliderID;
            NpcHitQueryAheadY = hitYAhead;
            minDepth = depth;
            hasCollision = TRUE;
        }
    }

    theta = DEG_TO_RAD(clamp_angle(yaw + 120.0f));
    sinTheta = sin_rad(theta);
    cosTheta = cos_rad(theta);
    deltaX = radius * sinTheta;
    deltaZ = -radius * cosTheta;

    startX = x + deltaX;
    startY = y;
    startZ = z + deltaZ;
    depth = originalDepth;

    colliderID = npc_raycast_down(ignoreFlags, &startX, &startY, &startZ, &depth);
    if (colliderID >= 0) {
        if (depth <= minDepth) {
            hitYBehindRight = startY;
            NpcHitQueryColliderID = colliderID;
            NpcHitQueryBehindCollider = colliderID;
            NpcHitQueryBehindRightY = hitYBehindRight;
            minDepth = depth;
            hasCollision = TRUE;
        }
    }

    theta = DEG_TO_RAD(clamp_angle(yaw - 120.0f));
    sinTheta = sin_rad(theta);
    cosTheta = cos_rad(theta);
    deltaX = radius * sinTheta;
    deltaZ = -radius * cosTheta;

    startX = x + deltaX;
    startY = y;
    startZ = z + deltaZ;
    depth = originalDepth;

    colliderID = npc_raycast_down(ignoreFlags, &startX, &startY, &startZ, &depth);
    if (colliderID >= 0) {
        if (depth <= minDepth) {
            hitYBehindLeft = startY;
            NpcHitQueryColliderID = colliderID;
            NpcHitQueryBehindCollider = colliderID;
            NpcHitQueryBehindLeftY = hitYBehindLeft;
            minDepth = depth;
            hasCollision = TRUE;
        }
    }

    if (hasCollision) {
        *posY = MAX(hitYBehindRight, hitYAhead);
        if (*posY < hitYBehindLeft) {
            *posY = hitYBehindLeft;
        }
        *hitDepth = minDepth;
        return TRUE;
    }

    *posY = startY;
    return FALSE;
}

b32 npc_raycast_down_sides(s32 ignoreFlags, f32* posX, f32* posY, f32* posZ, f32* hitDepth) {
    f32 startX;
    f32 startY;
    f32 startZ;
    f32 depth;
    f32 x;
    f32 y;
    f32 z;
    f32 originalDepth;
    f32 hitYUnused;
    s32 hasCollision;
    f32 cosTheta;
    s32 colliderID;
    f32 deltaX,deltaZ;
    f32 yaw;
    f32 theta, sinTheta, minDepth, hitYAhead, hitYBehind, radius;

    hasCollision = FALSE;

    x = *posX;
    y = *posY;
    z = *posZ;

    NpcHitQueryAheadY = y;
    NpcHitQueryBehindRightY = *posY;
    NpcHitQueryBehindLeftY = *posY;

    hitYUnused = hitYBehind = hitYAhead = -32767.0f;
    yaw = 0.0f;

    minDepth = fabsf(*hitDepth);
    theta = DEG_TO_RAD(clamp_angle(yaw));
    sinTheta = sin_rad(theta);
    cosTheta = cos_rad(theta);

    radius = 10.0f;

    deltaX = radius * sinTheta;
    deltaZ = -radius * cosTheta;

    startX = x + deltaX;
    startY = y;
    startZ = z + deltaZ;
    originalDepth = depth = minDepth;

    colliderID = npc_raycast_down(ignoreFlags, &startX, &startY, &startZ, &depth);
    if (colliderID >= 0) {
        if (depth <= minDepth) {
            hitYAhead = startY;
            NpcHitQueryColliderID = colliderID;
            NpcHitQueryAheadCollider = colliderID;
            NpcHitQueryAheadY = hitYAhead;
            minDepth = depth;
            hasCollision = TRUE;
        }
    }

    theta = DEG_TO_RAD(clamp_angle(yaw + 180.0f));
    sinTheta = sin_rad(theta);
    cosTheta = cos_rad(theta);
    deltaX = radius * sinTheta;
    deltaZ = -radius * cosTheta;

    startX = x + deltaX;
    startY = y;
    startZ = z + deltaZ;
    depth = originalDepth;

    colliderID = npc_raycast_down(ignoreFlags, &startX, &startY, &startZ, &depth);
    if (colliderID >= 0) {
        if (depth <= minDepth) {
            hitYBehind = startY;
            NpcHitQueryColliderID = colliderID;
            NpcHitQueryBehindCollider = colliderID;
            NpcHitQueryBehindRightY = hitYBehind;
            minDepth = depth;
            hasCollision = TRUE;
        }
    }

    if (hasCollision) {
        *posY = MAX(hitYBehind, hitYAhead);
        if (*posY < hitYUnused) {
            *posY = hitYUnused;
        }
        *hitDepth = minDepth;
        return TRUE;
    }

    return FALSE;
}

s32 npc_raycast_up(s32 ignoreFlags, f32* startX, f32* startY, f32* startZ, f32* hitDepth) {
    f32 cHitX;
    f32 cHitY;
    f32 cHitZ;
    f32 cHitDepth;
    f32 cHitNx;
    f32 cHitNy;
    f32 cHitNz;
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
    ret = test_ray_colliders(ignoreFlags, sx, sy, sz, 0.0f, 1.0f, 0.0f, &cHitX, &cHitY, &cHitZ, &cHitDepth, &cHitNx, &cHitNy, &cHitNz);
    colliderID = ret;
    if (!(ignoreFlags & COLLISION_IGNORE_ENTITIES))  {
        entityID = test_ray_entities(sx, sy, sz, 0.0f, 1.0f, 0.0f, &eHitX, &eHitY, &eHitZ, &eHitDepth, &eHitNx, &eHitNy, &eHitNz);
        ret = entityID | COLLISION_WITH_ENTITY_BIT;
        if (entityID >= 0) {
            cHitDepth = eHitDepth;
            cHitX = eHitX;
            cHitY = eHitY;
            cHitZ = eHitZ;
            cHitNx = eHitNx;
            cHitNy = eHitNy;
            cHitNz = eHitNz;
        } else {
            ret = colliderID;
        }
    }

    if (ret < 0) {
        // TODO find better match
        colliderID = FALSE;
        return colliderID;
    } else {
        *hitDepth = cHitDepth;
        *startX = cHitX;
        *startY = cHitY;
        *startZ = cHitZ;
        NpcHitQueryColliderID = ret;
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
    s32 ret = NO_COLLIDER;

    // needed to match
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
        ret = entityID | COLLISION_WITH_ENTITY_BIT;
        *length = hitDepth;
        *x = sx;
        *y = sy;
        *z = sz;
    }

    return ret;
}

s32 npc_raycast_up_corners(s32 ignoreFlags, f32* posX, f32* posY, f32* posZ, f32* hitDepth, f32 yaw, f32 radius) {
    f32 startX;
    f32 startY;
    f32 startZ;
    f32 depth;
    f32 theta;
    f32 deltaZ;
    f32 deltaX;
    f32 x,y,z;
    s32 ret;
    s32 hitID;
    f32 temp;

    theta = DEG_TO_RAD(yaw);
    deltaX = radius * sin_rad(theta);
    temp = -radius; // needed to match
    deltaZ = temp * cos_rad(theta);

    x = *posX;
    y = *posY;
    z = *posZ;

    depth = *hitDepth;
    startX = x + deltaX;
    startY = y;
    startZ = z + deltaZ;

    ret = NO_COLLIDER;
    hitID = npc_raycast_up_corner(ignoreFlags, &startX, &startY, &startZ, &depth);

    if (hitID < 0) {
        startX = x - deltaX;
        startY = y;
        startZ = z - deltaZ;
        hitID = npc_raycast_up_corner(ignoreFlags, &startX, &startY, &startZ, &depth);
    }

    if (hitID < 0) {
        startX = x + deltaZ;
        startY = y;
        startZ = z + deltaX;
        hitID = npc_raycast_up_corner(ignoreFlags, &startX, &startY, &startZ, &depth);
    }

    if (hitID < 0) {
        startX = x - deltaZ;
        startY = y;
        startZ = z - deltaX;
        hitID = npc_raycast_up_corner(ignoreFlags, &startX, &startY, &startZ, &depth);
    }

    if (hitID >= 0) {
        *posX = startX;
        *posY = startY;
        *posZ = startZ;
        *hitDepth = depth;
        ret = hitID;
    }

    if (ret < 0) {
        *posX = startX;
        *posY = startY;
        *posZ = startZ;
        *hitDepth = 0;
    }

    return ret;
}

s32 npc_raycast_general(s32 flags, f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ, f32* hitX,
                        f32* hitY, f32* hitZ, f32* outDepth, f32* hitNx, f32* hitNy, f32* hitNz) {
    s32 ret;
    s32 entityID;

    ret = NO_COLLIDER;
    if (flags & COLLISION_ONLY_ENTITIES) {
        entityID = test_ray_entities(startX, startY, startZ, dirX, dirY, dirZ, hitX, hitY, hitZ, outDepth, hitNx, hitNy,
                                     hitNz);
        if (entityID >= 0) {
            ret = entityID | COLLISION_WITH_ENTITY_BIT;
        }
    } else {
        ret = test_ray_colliders(flags, startX, startY, startZ, dirX, dirY, dirZ, hitX, hitY, hitZ, outDepth, hitNx,
                                 hitNy, hitNz);
        if (flags & COLLISION_IGNORE_ENTITIES) {
            return ret;
        }

        entityID = test_ray_entities(startX, startY, startZ, dirX, dirY, dirZ, hitX, hitY, hitZ, outDepth, hitNx,
                                        hitNy, hitNz);
        if (entityID >= 0) {
            ret = entityID | COLLISION_WITH_ENTITY_BIT;
        }

        // TODO required to match
        if ((s32)startY && startY && startY);
    }
    return ret;
}

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
    s32 hitResult = NO_COLLIDER;
    f32 a, b;

    sin_cos_rad(DEG_TO_RAD(yaw), &outSinTheta, &outCosTheta);
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
        NpcHitQueryColliderID = raycastHitID;
        hitResult = raycastHitID;
    }

    if (!phi_s5) {
        *x += aX;
        *z += aZ;
    }

    return hitResult;
}

s32 npc_test_move_without_slipping(s32 ignoreFlags, f32* x, f32* y, f32* z, f32 length, f32 yaw, f32 radius) {
    s32 ret = NO_COLLIDER;
    f32 depth;
    f32 originalDepth;
    f32 dirY;
    f32 cosTheta;
    f32 hitNx, hitNy, hitNz;
    f32 hitX, hitY, hitZ;
    s32 hitID;
    f32 temp1;
    f32 temp2;

    sin_cos_rad(DEG_TO_RAD(yaw), &dirY, &cosTheta);
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
        NpcHitQueryColliderID = hitID;
        ret = hitID;
    }

    *x += temp1;
    *z += temp2;
    return ret;
}

b32 npc_test_move_taller_with_slipping(s32 ignoreFlags, f32* x, f32* y, f32* z, f32 length, f32 yaw, f32 height,
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
        ret = TRUE;
        *x = xTemp;
        *z = zTemp;
    }
    return ret;
}

b32 npc_test_move_simple_with_slipping(s32 ignoreFlags, f32* x, f32* y, f32* z, f32 length, f32 yaw, f32 height,
                                       f32 radius) {
    f32 tempX = *x;
    f32 tempY = *y + 10.01f;
    f32 tempZ = *z;
    s32 hitID = npc_test_move_with_slipping(ignoreFlags, &tempX, &tempY, &tempZ, fabsf(length), yaw, radius * 0.5f);

    *x = tempX;
    *z = tempZ;

    return hitID >= 0;
}

b32 npc_test_move_simple_without_slipping(s32 ignoreFlags, f32* x, f32* y, f32* z, f32 length, f32 yaw, f32 height,
                                          f32 radius) {
    f32 tempX = *x;
    f32 tempY = *y + 10.01f;
    f32 tempZ = *z;
    s32 hitID = npc_test_move_without_slipping(ignoreFlags, &tempX, &tempY, &tempZ, fabsf(length), yaw, radius * 0.5f);

    *x = tempX;
    *z = tempZ;

    return hitID >= 0;
}

// traces lateral collision at position +10, +15, +20, and one unit below height
// returns number of traces that hit
s32 npc_test_move_complex_with_slipping(s32 ignoreFlags, f32* x, f32* y, f32* z, f32 length, f32 yaw, f32 height,
                                        f32 radius) {
    f32 startX;
    f32 startY;
    f32 startZ;
    s32 ret = 0;
    s32 hitID;

    radius *= 0.5f;
    startX = *x;
    startY = *y + height - 1.0f;
    startZ = *z;
    if (npc_test_move_with_slipping(ignoreFlags, &startX, &startY, &startZ, fabsf(length), yaw, radius) >= 0) {
        *x = startX;
        *z = startZ;
        ret = 4;
    }

    startX = *x;
    startY = *y + 20.0f;
    startZ = *z;
    if (npc_test_move_with_slipping(ignoreFlags, &startX, &startY, &startZ, fabsf(length), yaw, radius) >= 0) {
        *x = startX;
        *z = startZ;
        ret = 3;
    }

    startX = *x;
    startY = *y + 15.01f;
    startZ = *z;
    if (npc_test_move_with_slipping(ignoreFlags, &startX, &startY, &startZ, fabsf(length), yaw, radius) >= 0) {
        *x = startX;
        *z = startZ;
        ret = 2;
    }

    startX = *x;
    startY = *y + 10.01f;
    startZ = *z;
    hitID = npc_test_move_with_slipping(ignoreFlags, &startX, &startY, &startZ, fabsf(length), yaw, radius);
    *x = startX;
    *z = startZ;
    if (hitID >= 0) {
        ret = 1;
    }

    return ret;
}
