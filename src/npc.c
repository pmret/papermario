#include "common.h"
#include "npc.h"
#include "entity.h"
#include "effects.h"
#include "sprite.h"
#include "world/partners.h"
#include "sprite/npc/WorldWatt.h"

SHIFT_BSS s16 gNpcCount;
SHIFT_BSS NpcList gWorldNpcList;
SHIFT_BSS NpcList gBattleNpcList;
SHIFT_BSS NpcList* gCurrentNpcListPtr;
SHIFT_BSS b8 gNpcPlayerCollisionsEnabled;

#define PAL_ANIM_END 0xFF

enum PalSwapState {
    PAL_SWAP_HOLD_A     = 0,
    PAL_SWAP_A_TO_B     = 1,
    PAL_SWAP_HOLD_B     = 2,
    PAL_SWAP_B_TO_A     = 3,
};

// palette types for watt palette animations
enum {
    WATT_DEFAULT   = 0,
    WATT_BRIGHTEST = 1,
    WATT_BRIGHTER  = 2,
};

u8 wWattIdlePalettesAnim[] = {
    WATT_BRIGHTEST,   2,
    WATT_DEFAULT,    52,
    WATT_BRIGHTEST,   4,
    WATT_DEFAULT,    54,
    WATT_DEFAULT,    54,
    WATT_BRIGHTEST,   2,
    WATT_DEFAULT,    28,
    WATT_BRIGHTEST,   2,
    WATT_DEFAULT,     6,
    WATT_BRIGHTEST,   2,
    WATT_DEFAULT,    44,
    WATT_BRIGHTEST,   2,
    WATT_DEFAULT,    44,
    PAL_ANIM_END
};

s32 D_80077C0C = 0; //  padding?
f32 D_80077C10 = 0.0f;
s16 D_80077C14 = 4;
s16 D_80077C16 = 0; // padding?
f32 D_80077C18 = 0;
s16 D_80077C1C = 4;
s16 D_80077C1E = 5;
s32 D_80077C20 = 0;
f32 D_80077C24 = 0.0f;
s16 D_80077C28 = 4;
s16 D_80077C2A = 0; // padding?
f32 D_80077C2C = 0.0f;
s16 D_80077C30 = 4;
s16 D_80077C32 = 0; // padding?
s32 D_80077C34 = 0;
s16 D_80077C38 = 4;
s16 D_80077C3A = 4;

void STUB_npc_callback(Npc* npc) {
}

void mtx_ident_mirror_y(Matrix4f mtx) {
    guMtxIdentF(mtx);
    mtx[0][0] = 1.0f;
    mtx[1][1] = -1.0f;
    mtx[2][2] = 1.0f;
    mtx[3][3] = 1.0f;
}

void clear_npcs(void) {
    s32 i;

    if (!gGameStatusPtr->isBattle) {
        gCurrentNpcListPtr = &gWorldNpcList;
    } else {
        gCurrentNpcListPtr = &gBattleNpcList;
    }

    for (i = 0; i < MAX_NPCS; i++) {
        (*gCurrentNpcListPtr)[i] = NULL;
    }

    gNpcCount = 0;
    gNpcPlayerCollisionsEnabled = TRUE;
}

void init_npc_list(void) {
    if (!gGameStatusPtr->isBattle) {
        gCurrentNpcListPtr = &gWorldNpcList;
    } else {
        gCurrentNpcListPtr = &gBattleNpcList;
    }

    gNpcCount = 0;
    gNpcPlayerCollisionsEnabled = TRUE;
}

void npc_iter_no_op(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentNpcListPtr); i++) {
        // Needed to avoid loop optimization.
        do {} while (FALSE);
    }
}

s32 create_npc_impl(NpcBlueprint* blueprint, AnimID* animList, s32 isPeachNpc) {
    Npc* npc;
    s32 i;
    s32 j;

    for (i = 0; i < MAX_NPCS; i++) {
        if ((*gCurrentNpcListPtr)[i] == NULL) {
            break;
        }
    }
    ASSERT(i < MAX_NPCS);

    (*gCurrentNpcListPtr)[i] = npc = heap_malloc(sizeof(*npc));
    gNpcCount++;
    ASSERT(npc != NULL);

    npc->flags = blueprint->flags | (NPC_FLAG_TOUCHES_GROUND | NPC_FLAG_DIRTY_SHADOW | NPC_FLAG_HAS_SHADOW | NPC_FLAG_ENABLED);
    if (isPeachNpc) {
        npc->flags |= NPC_FLAG_NO_ANIMS_LOADED;
    }

    npc->collisionDiameter = 32;
    npc->collisionHeight = 64;
    npc->renderMode = 13;
    npc->blur.any = NULL;
    npc->yaw = 0.0f;
    npc->jumpVel = 0.0f;
    npc->pos.x = 0.0f;
    npc->pos.y = 0.0f;
    npc->pos.z = 0.0f;
    npc->colliderPos.x = 0.0f;
    npc->colliderPos.y = 0.0f;
    npc->colliderPos.z = 0.0f;
    npc->rotPivotOffsetY = 0.0f;
    npc->rot.x = 0.0f;
    npc->rot.y = 0.0f;
    npc->rot.z = 0.0f;
    npc->homePos.x = 0.0f;
    npc->homePos.y = 0.0f;
    npc->homePos.z = 0.0f;
    npc->unk_96 = 0; // TODO: fix
    npc->verticalRenderOffset = 0;
    npc->alpha = 255;
    npc->hideAlpha = 255;
    npc->jumpScale = 1.0f;
    npc->moveSpeed = 4.0f;
    npc->scale.x = 1.0f;
    npc->scale.y = 1.0f;
    npc->scale.z = 1.0f;
    npc->curAnim = blueprint->initialAnim;
    npc->animationSpeed = 1.0f;
    npc->renderYaw = 0.0f;
    npc->imgfxType = IMGFX_CLEAR;
    npc->imgfxFlags = 0;
    npc->collisionChannel = COLLIDER_FLAG_IGNORE_NPC;
    npc->isFacingAway = FALSE;
    npc->yawCamOffset = 0;
    npc->turnAroundYawAdjustment = 0;
    npc->curFloor = NO_COLLIDER;
    npc->curWall = NO_COLLIDER;
    npc->palSwapType = NPC_PAL_ADJUST_NONE;
    npc->palSwapPrevType = NPC_PAL_ADJUST_NONE;
    npc->screenSpaceOffset2D[0] = 0.0f;
    npc->screenSpaceOffset2D[1] = 0.0f;
    npc->verticalStretch = 1.0f;

    for (j = 0; j < ARRAY_COUNT(npc->decorations); j++) {
        npc->decorations[j] = 0;
        npc->decorationType[j] = 0;
    }

    npc->onUpdate = blueprint->onUpdate;
    if (npc->onUpdate == NULL) {
        npc->onUpdate = &STUB_npc_callback;
    }

    npc->onRender = blueprint->onRender;
    if (npc->onRender == NULL) {
        npc->onRender = &STUB_npc_callback;
    }
    if (!isPeachNpc) {
        npc->extraAnimList = animList;
        if (!(npc->flags & NPC_FLAG_HAS_NO_SPRITE)) {
            if (!(npc->flags & NPC_FLAG_PARTNER)) {
                npc->spriteInstanceID = spr_load_npc_sprite(npc->curAnim, animList);
            } else {
                npc->spriteInstanceID = spr_load_npc_sprite(npc->curAnim | SPRITE_ID_TAIL_ALLOCATE, animList);
            }
        } else {
            npc->flags |= NPC_FLAG_INVISIBLE;
        }
    }

    npc->shadowIndex = create_shadow_type(SHADOW_VARYING_CIRCLE, npc->pos.x, npc->pos.y, npc->pos.z);
    npc->shadowScale = 1.0f;

    if (gGameStatusPtr->isBattle) {
        i |= BATTLE_NPC_ID_BIT;
    }
    return i;
}

s32 create_basic_npc(NpcBlueprint* blueprint) {
    return create_npc_impl(blueprint, NULL, FALSE);
}

s32 create_standard_npc(NpcBlueprint* blueprint, AnimID* animList) {
    return create_npc_impl(blueprint, animList, FALSE);
}

s32 create_peach_npc(NpcBlueprint* blueprint) {
    return create_npc_impl(blueprint, NULL, TRUE);
}

void free_npc_by_index(s32 listIndex) {
    Npc* npc;
    s32 i;

    listIndex &= ~BATTLE_NPC_ID_BIT;

    npc = (*gCurrentNpcListPtr)[listIndex];
    if (npc != NULL) {
        if (npc->flags) {
            if (npc->blur.any != NULL) {
                heap_free(npc->blur.any);
                npc->blur.any = NULL;
            }

            if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
                ASSERT((npc->flags & NPC_FLAG_HAS_NO_SPRITE) || !spr_free_sprite(npc->spriteInstanceID));
            }

            delete_shadow(npc->shadowIndex);

            for (i = 0; i < MAX_NPC_DECORATIONS; i++) {
                npc_remove_decoration(npc, i);
            }

            if (npc->flags & NPC_FLAG_MOTION_BLUR) {
                disable_npc_blur(npc);
            }

            heap_free((*gCurrentNpcListPtr)[listIndex]);
            (*gCurrentNpcListPtr)[listIndex] = NULL;
            gNpcCount--;
        }
    }
}

void free_npc(Npc* npc) {
    s32 i;

    if (npc->blur.any != NULL) {
        heap_free(npc->blur.any);
        npc->blur.any = NULL;
    }

    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
        ASSERT((npc->flags & NPC_FLAG_HAS_NO_SPRITE) || !spr_free_sprite(npc->spriteInstanceID));
    }

    delete_shadow(npc->shadowIndex);

    for (i = 0; i < MAX_NPC_DECORATIONS; i++) {
        npc_remove_decoration(npc, i);
    }

    if (npc->flags & NPC_FLAG_MOTION_BLUR) {
        disable_npc_blur(npc);
    }

    heap_free(npc);

    for (i = 0; i < MAX_NPCS; i++) {
        if ((*gCurrentNpcListPtr)[i] == npc) {
            break;
        }
    }

    (*gCurrentNpcListPtr)[i] = NULL;
    gNpcCount--;
}

Npc* get_npc_by_index(s32 listIndex) {
    return (*gCurrentNpcListPtr)[listIndex & ~BATTLE_NPC_ID_BIT];
}

// checks for lateral collision with the world directly in front of the NPC and in an X pattern offset 45 degrees from
// the forward direction. when a collision is detected, the NPC position is adjusted an appropriate NPC flags are set
// to signal the collision has occurred.
void npc_do_world_collision(Npc* npc) {
    f32 testAngle;
    s32 hit;
    f32 testX;
    f32 testY;
    f32 testZ;

    if (npc->flags & NPC_FLAG_IGNORE_WORLD_COLLISION) {
        npc->flags |= NPC_FLAG_WORLD_COLLISION_DIRTY;
    } else if (
           (npc->pos.x != npc->colliderPos.x)
        || (npc->pos.y != npc->colliderPos.y)
        || (npc->pos.z != npc->colliderPos.z)
        || npc->flags & NPC_FLAG_WORLD_COLLISION_DIRTY
    ) {
        npc->flags &= ~NPC_FLAG_WORLD_COLLISION_DIRTY;
        testAngle = clamp_angle(npc->yaw);
        testX = npc->pos.x;
        testY = npc->pos.y;
        testZ = npc->pos.z;

        if (!(npc->flags & NPC_FLAG_PARTNER)) {
            hit = npc_test_move_simple_with_slipping(npc->collisionChannel, &testX, &testY, &testZ, 0, testAngle, npc->collisionHeight, npc->collisionDiameter);
        } else {
            hit = npc_test_move_complex_with_slipping(npc->collisionChannel, &testX, &testY, &testZ, 0, testAngle, npc->collisionHeight, npc->collisionDiameter);
        }

        if (hit) {
            npc->flags |= (NPC_FLAG_COLLDING_WITH_WORLD | NPC_FLAG_COLLDING_FORWARD_WITH_WORLD);
            npc->curWall = NpcHitQueryColliderID;
            npc->pos.x = testX;
            npc->pos.z = testZ;
        } else {
            npc->flags &= ~(NPC_FLAG_COLLDING_WITH_WORLD | NPC_FLAG_COLLDING_FORWARD_WITH_WORLD);
        }

        testAngle = clamp_angle(npc->yaw + 45.0f);
        testX = npc->pos.x;
        testY = npc->pos.y;
        testZ = npc->pos.z;

        if (!(npc->flags & NPC_FLAG_PARTNER)) {
            hit = npc_test_move_simple_with_slipping(npc->collisionChannel, &testX, &testY, &testZ, 0, testAngle, npc->collisionHeight, npc->collisionDiameter);
        } else {
            hit = npc_test_move_taller_with_slipping(npc->collisionChannel, &testX, &testY, &testZ, 0, testAngle, npc->collisionHeight, npc->collisionDiameter);
        }

        if (hit) {
            npc->flags |= NPC_FLAG_COLLDING_WITH_WORLD;
            npc->pos.x = testX;
            npc->pos.z = testZ;
        } else {
            npc->flags &= ~NPC_FLAG_COLLDING_WITH_WORLD;
        }

        testAngle = clamp_angle(npc->yaw - 45.0f);
        testX = npc->pos.x;
        testY = npc->pos.y;
        testZ = npc->pos.z;
        if (!(npc->flags & NPC_FLAG_PARTNER)) {
            hit = npc_test_move_simple_with_slipping(npc->collisionChannel, &testX, &testY, &testZ, 0, testAngle, npc->collisionHeight, npc->collisionDiameter);
        } else {
            hit = npc_test_move_taller_with_slipping(npc->collisionChannel, &testX, &testY, &testZ, 0, testAngle, npc->collisionHeight, npc->collisionDiameter);
        }

        if (hit != 0) {
            npc->flags |= NPC_FLAG_COLLDING_WITH_WORLD;
            npc->pos.x = testX;
            npc->pos.z = testZ;
        } else {
            npc->flags &= ~NPC_FLAG_COLLDING_WITH_WORLD;
        }

        if (npc->flags & NPC_FLAG_PARTNER) {
            testAngle = clamp_angle(npc->yaw + 45.0f + 180.0f);
            testX = npc->pos.x;
            testY = npc->pos.y;
            testZ = npc->pos.z;
            if (npc_test_move_simple_with_slipping(npc->collisionChannel, &testX, &testY, &testZ, 0, testAngle, npc->collisionHeight,
                              npc->collisionDiameter) != 0) {
                npc->flags |= NPC_FLAG_COLLDING_WITH_WORLD;
                npc->pos.x = testX;
                npc->pos.z = testZ;
            } else {
                npc->flags &= ~NPC_FLAG_COLLDING_WITH_WORLD;
            }

            testAngle = clamp_angle((npc->yaw - 45.0f) + 180.0f);
            testX = npc->pos.x;
            testY = npc->pos.y;
            testZ = npc->pos.z;
            if (npc_test_move_simple_with_slipping(npc->collisionChannel, &testX, &testY, &testZ, 0, testAngle, npc->collisionHeight,
                              npc->collisionDiameter) != 0) {
                npc->flags |= NPC_FLAG_COLLDING_WITH_WORLD;
                npc->pos.x = testX;
                npc->pos.z = testZ;
                return;
            }
            npc->flags &= ~NPC_FLAG_COLLDING_WITH_WORLD;
        }
    }
}

void npc_do_other_npc_collision(Npc* npc) {
    Npc* otherNpc;
    f32 angle;
    f32 thisX, thisY, thisZ;
    f32 thisBuf;
    f32 otherX, otherZ;
    f32 otherBuf;
    f32 xDiff, zDiff;
    f32 dist;
    s32 collision;
    s32 i;

    if (!(npc->flags & NPC_FLAG_IGNORE_PLAYER_COLLISION)) {
        npc->flags &= ~NPC_FLAG_COLLIDING_WITH_NPC;
        thisBuf = npc->collisionDiameter * 0.5f;
        thisX = npc->pos.x;
        thisY = npc->pos.y;
        thisZ = npc->pos.z;

        for (i = 0; i < MAX_NPCS; i++) {
            otherNpc = get_npc_by_index(i);
            if (otherNpc != NULL && npc != otherNpc) {
                if (otherNpc->flags != 0 && !(otherNpc->flags & (NPC_FLAG_SUSPENDED | NPC_FLAG_IGNORE_PLAYER_COLLISION))) {
                    if (!(otherNpc->pos.y + otherNpc->collisionHeight < thisY) &&
                        !(thisY + npc->collisionHeight < otherNpc->pos.y))
                    {
                        otherX = otherNpc->pos.x;
                        xDiff = otherX - thisX;
                        otherZ = otherNpc->pos.z;
                        zDiff = otherZ - thisZ;
                        otherBuf = otherNpc->collisionDiameter * 0.5f;
                        dist = sqrtf(SQ(xDiff) + SQ(zDiff));

                        if (!(thisBuf + otherBuf <= dist)) {
                            collision = FALSE;
                            if (npc->flags & NPC_FLAG_PARTNER) {
                                collision = gPartnerStatus.partnerActionState == PARTNER_ACTION_NONE;
                            } else if (!(otherNpc->flags & NPC_FLAG_PARTNER) ||
                                        gPartnerStatus.partnerActionState == PARTNER_ACTION_NONE)
                            {
                                collision = TRUE;
                            }

                            if (collision) {
                                angle = DEG_TO_RAD(atan2(otherX, otherZ, thisX, thisZ));
                                dist = (thisBuf + otherBuf) - dist;
                                xDiff = dist * sin_rad(angle);
                                zDiff = -dist * cos_rad(angle);
                                thisX += xDiff * 0.1f;
                                thisZ += zDiff * 0.1f;
                            }
                            npc->flags |= NPC_FLAG_COLLIDING_WITH_NPC;
                        }
                    }
                }
            }
        }
        npc->pos.x = thisX;
        npc->pos.z = thisZ;
    }
}

s32 npc_do_player_collision(Npc* npc) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 playerX, playerZ;
    f32 playerYaw, yaw;
    f32 npcX, npcZ;
    f32 dist, colDist, distToNpc;
    f32 npcColRadius, playerColRadius;
    f32 deltaX, deltaZ;

    if (npc->flags & NPC_FLAG_IGNORE_PLAYER_COLLISION) {
        return FALSE;
    }

    if (npc->flags & NPC_FLAG_PARTNER) {
        return FALSE;
    }

    if (!gNpcPlayerCollisionsEnabled) {
        return FALSE;
    }

    if (playerStatus->pos.y + playerStatus->colliderHeight < npc->pos.y) {
        return FALSE;
    }

    if (npc->pos.y + npc->collisionHeight < playerStatus->pos.y) {
        return FALSE;
    }

    playerX = playerStatus->pos.x;
    playerZ = playerStatus->pos.z;

    npcColRadius = npc->collisionDiameter / 2;
    playerColRadius = playerStatus->colliderDiameter / 2;

    npcX = npc->pos.x;
    npcZ = npc->pos.z;

    deltaX = playerX - npcX;
    deltaZ = playerZ - npcZ;

    distToNpc = sqrtf(SQ(deltaX) + SQ(deltaZ));
    colDist = npcColRadius + playerColRadius;
    if (colDist < distToNpc) {
        return FALSE;
    }

    playerStatus->animFlags |= PA_FLAG_NPC_COLLIDED;

    npcX = npc->colliderPos.x;
    npcZ = npc->colliderPos.z;

    deltaX = playerX - npcX;
    deltaZ = playerZ - npcZ;

    dist = sqrtf(SQ(deltaX) + SQ(deltaZ));
    yaw = atan2(playerX, playerZ, npcX, npcZ);

    playerYaw = playerStatus->targetYaw;
    dist = colDist - dist;
    deltaX = dist * sin_rad(DEG_TO_RAD(yaw));
    deltaZ = -dist * cos_rad(DEG_TO_RAD(yaw));

    if (playerStatus->animFlags & PA_FLAG_RIDING_PARTNER) {
        if (fabsf(get_clamped_angle_diff(yaw, playerYaw)) < 45.0f) {
            playerStatus->pos.x -= deltaX;
            playerStatus->pos.z -= deltaZ;
            wPartnerNpc->pos.x -= deltaX;
            wPartnerNpc->pos.z -= deltaZ;
        } else {
            playerStatus->pos.x -= deltaX * 0.5f;
            playerStatus->pos.z -= deltaZ * 0.5f;
            wPartnerNpc->pos.x -= deltaX * 0.5f;
            wPartnerNpc->pos.z -= deltaZ * 0.5f;
        }
    } else {
        if (playerStatus->flags & (PS_FLAG_JUMPING | PS_FLAG_FALLING)) {
            playerStatus->pos.x -= deltaX * 0.4f;
            playerStatus->pos.z -= deltaZ * 0.4f;
        } else {
            dist = get_clamped_angle_diff(yaw, playerYaw); // required to match
            if (fabsf(dist) < 45.0f) {
                playerStatus->pos.x -= deltaX;
                playerStatus->pos.z -= deltaZ;
            } else {
                playerStatus->pos.x -= deltaX * 0.5f;
                playerStatus->pos.z -= deltaZ * 0.5f;
            }
        }
    }
    npc->pos.x = npc->colliderPos.x;
    npc->pos.y = npc->colliderPos.y;
    npc->pos.z = npc->colliderPos.z;
    return TRUE;
}

// update NPC position using gravitational acceleration = 1.0
// if the NPC is within 16 units of the floor, they are snapped to it
void npc_try_apply_gravity(Npc* npc) {
    f32 x, y, z, testLength;
    f32 length;
    s32 hitID;

    if (!(npc->flags & NPC_FLAG_GRAVITY)) {
        return;
    }

    if (npc->flags & NPC_FLAG_JUMPING) {
        npc->flags &= ~NPC_FLAG_GROUNDED;
        return;
    }

    npc->jumpScale = 1.0f;
    npc->jumpVel -= npc->jumpScale;
    npc->pos.y += npc->jumpVel;

    x = npc->pos.x;
    y = npc->pos.y + 13;
    z = npc->pos.z;
    testLength = length = fabsf(npc->jumpVel) + 16;

    if (!(npc->flags & NPC_FLAG_PARTNER)) {
        hitID = npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &length);
    } else {
        hitID = npc_raycast_down_around(npc->collisionChannel, &x, &y, &z, &length, npc->yaw, npc->collisionDiameter);
    }

    if (hitID && length <= testLength) {
        npc->jumpVel = 0.0f;
        npc->flags |= NPC_FLAG_GROUNDED;
        npc->pos.y = y;
        npc->curFloor = NpcHitQueryColliderID;
    } else {
        npc->flags &= ~NPC_FLAG_GROUNDED;
    }
}

// perform only collision traces and snapping to ground from gravity code
s32 npc_try_snap_to_ground(Npc* npc, f32 velocity) {
    f32 x, y, z, testLength;
    f32 length;
    s32 hitID;

    if (npc->flags & (NPC_FLAG_GRAVITY | NPC_FLAG_FLYING)) {
        return FALSE;
    }

    if (npc->flags & NPC_FLAG_JUMPING) {
        npc->flags &= ~NPC_FLAG_GROUNDED;
        return FALSE;
    }

    length = testLength = fabsf(velocity) + 16;
    x = npc->pos.x;
    y = npc->pos.y + 13;
    z = npc->pos.z;

    if (!(npc->flags & NPC_FLAG_PARTNER)) {
        hitID = npc_raycast_down_sides(npc->collisionChannel, &x, &y, &z, &length);
    } else {
        hitID = npc_raycast_down_around(npc->collisionChannel, &x, &y, &z, &length, npc->yaw, npc->collisionDiameter);
    }

    if (hitID != 0 && length <= testLength) {
        npc->pos.y = y;
        npc->curFloor = NpcHitQueryColliderID;
        npc->flags |= NPC_FLAG_GROUNDED;
        return TRUE;
    }

    npc->flags &= ~NPC_FLAG_GROUNDED;
    return FALSE;
}

void update_npcs(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 x, y, z;
    f32 hitYaw, hitPitch, hitLength;

    playerStatus->animFlags &= ~PA_FLAG_NPC_COLLIDED;
    if (!(gOverrideFlags & (GLOBAL_OVERRIDES_800 | GLOBAL_OVERRIDES_400))) {
        s32 i;

        for (i = 0; i < MAX_NPCS; i++) {
            Npc* npc = (*gCurrentNpcListPtr)[i];

            if (npc != NULL) {
                if (npc->flags != 0) {
                    if (npc->flags & (NPC_FLAG_SUSPENDED | NPC_FLAG_INACTIVE)) {
                        npc_do_world_collision(npc);
                        continue;
                    }

                    npc->onUpdate(npc);
                    if (npc->flags & NPC_FLAG_IGNORE_ENTITY_COLLISION) {
                        npc->collisionChannel |= COLLISION_IGNORE_ENTITIES;
                    } else {
                        npc->collisionChannel &= ~COLLISION_IGNORE_ENTITIES;
                    }

                    npc->curFloor = NO_COLLIDER;
                    npc->curWall = NO_COLLIDER;
                    npc->flags &= ~(NPC_FLAG_COLLDING_FORWARD_WITH_WORLD | NPC_FLAG_COLLDING_WITH_WORLD);

                    npc_do_world_collision(npc);
                    npc_try_apply_gravity(npc);
                    npc_try_snap_to_ground(npc, 0.0f);
                    npc_do_player_collision(npc);
                    npc_do_other_npc_collision(npc);

                    if (npc->flags & NPC_FLAG_MOTION_BLUR) {
                        update_npc_blur(npc);
                    }

                    if ((npc->pos.y < -2000.0f) && !(npc->flags & NPC_FLAG_PARTNER)) {
                        npc->pos.y = playerStatus->pos.y;
                        npc->jumpVel = 0.0f;
                        npc->moveSpeed = 0.0f;
                        npc->jumpScale = 0.0f;
                        npc->flags &= ~NPC_FLAG_JUMPING;
                    }

                    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
                        if (!(npc->flags & NPC_FLAG_HAS_NO_SPRITE)) {
                            if (npc->curAnim != 0) {
                                if (npc->spriteInstanceID >= 0) {
                                    spr_update_sprite(npc->spriteInstanceID, npc->curAnim, npc->animationSpeed);
                                }
                            }
                        }
                    } else {
                        spr_update_player_sprite(PLAYER_SPRITE_AUX1, npc->curAnim, npc->animationSpeed);
                    }

                    if (npc->flags & NPC_FLAG_HAS_SHADOW) {
                        Shadow* shadow = get_shadow_by_index(npc->shadowIndex);
                        EntityModel* entityModel = get_entity_model(shadow->entityModelID);

                        entityModel->flags &= ~ENTITY_MODEL_FLAG_REFLECT;
                        if (npc->flags & NPC_FLAG_REFLECT_WALL) {
                            entityModel->flags |= ENTITY_MODEL_FLAG_REFLECT;
                        }

                        x = npc->pos.x;
                        y = npc->pos.y;
                        z = npc->pos.z;
                        if (!(npc->flags & NPC_FLAG_NO_SHADOW_RAYCAST)) {
                            if (   x != npc->colliderPos.x
                                || y != npc->colliderPos.y
                                || z != npc->colliderPos.z
                                || (npc->flags & NPC_FLAG_DIRTY_SHADOW)
                            ) {
                                x = npc->pos.x;
                                y = npc->pos.y + (npc->collisionHeight / 2);
                                z = npc->pos.z;
                                hitLength = 1000.0f;
                                entity_raycast_down(&x, &y, &z, &hitYaw, &hitPitch, &hitLength);
                                set_npc_shadow_scale(shadow, hitLength, npc->collisionDiameter);
                                shadow->pos.x = x;
                                shadow->pos.y = y;
                                shadow->pos.z = z;
                                shadow->rot.x = hitYaw;
                                shadow->rot.y = npc->renderYaw;
                                shadow->rot.z = hitPitch;
                                shadow->scale.x *= npc->shadowScale;
                                npc->flags &= ~NPC_FLAG_DIRTY_SHADOW;
                            }
                        } else {
                            if (npc->flags & NPC_FLAG_DONT_UPDATE_SHADOW_Y) {
                                shadow->pos.x = npc->pos.x;
                                shadow->pos.z = npc->pos.z;
                            } else {
                                shadow->pos.x = npc->pos.x;
                                shadow->pos.y = npc->pos.y;
                                shadow->pos.z = npc->pos.z;
                            }
                        }
                    }

                    npc->colliderPos.x = npc->pos.x;
                    npc->colliderPos.y = npc->pos.y;
                    npc->colliderPos.z = npc->pos.z;
                    npc_update_decorations(npc);

                    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
                        if (!(npc->flags & NPC_FLAG_HAS_NO_SPRITE)) {
                            if (npc->spriteInstanceID < 0) {
                                npc->spriteInstanceID++;
                                if (npc->spriteInstanceID == -1) {
                                    npc->spriteInstanceID = spr_load_npc_sprite(npc->curAnim, npc->extraAnimList);
                                    ASSERT(npc->spriteInstanceID >= 0);
                                    spr_update_sprite(npc->spriteInstanceID, npc->curAnim, npc->animationSpeed);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

f32 npc_get_render_yaw(Npc* npc) {
    Camera* camera = &gCameras[gCurrentCamID];
    f32 cameraYaw;
    f32 camRelativeYaw;
    f32 yaw;
    s32 direction;

    if (!(gOverrideFlags & (GLOBAL_OVERRIDES_PREV_800 | GLOBAL_OVERRIDES_PREV_400))) {
        cameraYaw = camera->curYaw;
        camRelativeYaw = get_clamped_angle_diff(cameraYaw, npc->yaw);

        if (camRelativeYaw < -5.0f && camRelativeYaw > -175.0f) {
            direction = 0;
            camRelativeYaw = 0.0f;
        } else if (camRelativeYaw > 5.0f && camRelativeYaw < 175.0f) {
            direction = 1;
            camRelativeYaw = 180.0f;
        } else {
            // direction is close to flipping, use saved value
            direction = 2;
            camRelativeYaw = npc->yawCamOffset;
        }

        npc->yawCamOffset = yaw = clamp_angle(camRelativeYaw);

        if (!(npc->flags & NPC_FLAG_IGNORE_CAMERA_FOR_YAW)) {
            if (npc->isFacingAway != direction && direction != 2) {
                npc->isFacingAway = direction;

                if (npc->isFacingAway) {
                    npc->turnAroundYawAdjustment = 180;
                } else {
                    npc->turnAroundYawAdjustment = -180;
                }

                if (fabsf(get_clamped_angle_diff(cameraYaw, npc->yaw)) >= 90.0f) {
                    npc->turnAroundYawAdjustment = -npc->turnAroundYawAdjustment;
                }
            }

            if (npc->turnAroundYawAdjustment != 0) {
                if (npc->turnAroundYawAdjustment < 0) {
                    npc->turnAroundYawAdjustment += 20;
                }
                if (npc->turnAroundYawAdjustment > 0) {
                    npc->turnAroundYawAdjustment -= 20;
                }
            }

            if (npc->flags & NPC_FLAG_200000) {
                npc->turnAroundYawAdjustment = 0;
            }

            npc->renderYaw = clamp_angle(clamp_angle(npc->turnAroundYawAdjustment + yaw) - cameraYaw);
            yaw = npc->renderYaw;
        } else {
            yaw = npc->renderYaw;
        }
    } else {
        yaw = npc->renderYaw;
    }
    return yaw;
}

void appendGfx_npc(void* data) {
    Npc* npc = data;
    Matrix4f mtx1, mtx2;
    f32 renderYaw = npc_get_render_yaw(npc);

    guTranslateF(mtx1, npc->pos.x, npc->pos.y + npc->verticalRenderOffset, npc->pos.z);
    if (npc->flags & NPC_FLAG_UPSIDE_DOWN) {
        mtx_ident_mirror_y(mtx2);
        guMtxCatF(mtx2, mtx1, mtx1);
    }

    if (npc->rotPivotOffsetY != 0.0f) {
        guTranslateF(mtx2, 0.0f, npc->rotPivotOffsetY, 0.0f);
        guMtxCatF(mtx2, mtx1, mtx1);
    }

    if (npc->rot.y != 0.0f) {
        guRotateF(mtx2, npc->rot.y, 0.0f, 1.0f, 0.0f);
        guMtxCatF(mtx2, mtx1, mtx1);
    }

    if (npc->rot.x != 0.0f) {
        guRotateF(mtx2, npc->rot.x, 1.0f, 0.0f, 0.0f);
        guMtxCatF(mtx2, mtx1, mtx1);
    }

    if (npc->rot.z != 0.0f) {
        guRotateF(mtx2, npc->rot.z, 0.0f, 0.0f, 1.0f);
        guMtxCatF(mtx2, mtx1, mtx1);
    }

    if (npc->rotPivotOffsetY != 0.0f) {
        guTranslateF(mtx2, 0.0f, -npc->rotPivotOffsetY, 0.0f);
        guMtxCatF(mtx2, mtx1, mtx1);
    }

    if ((npc->screenSpaceOffset2D[0] != 0.0f) || (npc->screenSpaceOffset2D[1] != 0.0f)) {
        guTranslateF(mtx1, npc->screenSpaceOffset2D[0], npc->screenSpaceOffset2D[1], 0.0f);
        guMtxCatF(mtx2, mtx1, mtx1);
    }

    if (npc->scale.x * SPRITE_WORLD_SCALE_D != 1.0f
        || (npc->scale.y * npc->verticalStretch) * SPRITE_WORLD_SCALE_D != 1.0f
        || npc->scale.z * SPRITE_WORLD_SCALE_D != 1.0f
    ) {
        guScaleF(mtx2, npc->scale.x * SPRITE_WORLD_SCALE_D, (npc->scale.y * npc->verticalStretch) * SPRITE_WORLD_SCALE_D,
                 npc->scale.z * SPRITE_WORLD_SCALE_D);
        guMtxCatF(mtx2, mtx1, mtx1);
    }

    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
        if (!(npc->flags & NPC_FLAG_HAS_NO_SPRITE) && (npc->curAnim != 0) && (npc->spriteInstanceID >= 0)) {
            npc_draw_with_palswap(npc, renderYaw, mtx1);
            npc->animNotifyValue = spr_get_notify_value(npc->spriteInstanceID);
        }
    } else {
        npc_draw_with_palswap(npc, renderYaw, mtx1);
        npc->animNotifyValue = func_802DDEC4(PLAYER_SPRITE_AUX1);
    }

    if (npc->flags & NPC_FLAG_REFLECT_WALL) {
        guTranslateF(mtx1, npc->pos.x, npc->pos.y + npc->verticalRenderOffset, -npc->pos.z);
        if (npc->flags & NPC_FLAG_UPSIDE_DOWN) {
            mtx_ident_mirror_y(mtx2);
            guMtxCatF(mtx2, mtx1, mtx1);
        }
        if ((npc->rot.y != 0.0f) || (npc->rot.x != 0.0f) || (npc->rot.z != 0.0f)) {
            guRotateRPYF(mtx2, npc->rot.x, npc->rot.y, npc->rot.z);
            guMtxCatF(mtx2, mtx1, mtx1);
        }


        if (npc->scale.x * SPRITE_WORLD_SCALE_D != 1.0f
            || (npc->scale.y * npc->verticalStretch) * SPRITE_WORLD_SCALE_D != 1.0f
            || npc->scale.z * SPRITE_WORLD_SCALE_D != 1.0f
        ) {
            do {
                guScaleF(mtx2, npc->scale.x * SPRITE_WORLD_SCALE_D,
                               (npc->scale.y * npc->verticalStretch) * SPRITE_WORLD_SCALE_D,
                               npc->scale.z * SPRITE_WORLD_SCALE_D);
            } while (0); // required to match (macro?)
            guMtxCatF(mtx2, mtx1, mtx1);

        }

        if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
            if (!(npc->flags & NPC_FLAG_HAS_NO_SPRITE) && (npc->curAnim != 0)) {
                spr_draw_npc_sprite(npc->spriteInstanceID, renderYaw, 0, 0, mtx1);
            }
        } else {
            spr_draw_player_sprite(PLAYER_SPRITE_AUX1 | DRAW_SPRITE_OVERRIDE_YAW, renderYaw, 0, 0, mtx1);
        }
    }

    if (npc->flags & NPC_FLAG_REFLECT_FLOOR) {
        guTranslateF(mtx1, npc->pos.x, -(npc->pos.y + npc->verticalRenderOffset), npc->pos.z);
        mtx_ident_mirror_y(mtx2);
        guMtxCatF(mtx2, mtx1, mtx1);

        if (npc->rot.y != 0.0f || npc->rot.x != 0.0f || npc->rot.z != 0.0f) {
            guRotateRPYF(mtx2, npc->rot.x, npc->rot.y, npc->rot.z);
            guMtxCatF(mtx2, mtx1, mtx1);
        }

        if (npc->scale.x * SPRITE_WORLD_SCALE_D != 1.0f
            || (npc->scale.y * npc->verticalStretch) * SPRITE_WORLD_SCALE_D != 1.0f
            || npc->scale.z * SPRITE_WORLD_SCALE_D != 1.0f
        ) {
            do {
                guScaleF(mtx2, npc->scale.x * SPRITE_WORLD_SCALE_D,
                               (npc->scale.y * npc->verticalStretch) * SPRITE_WORLD_SCALE_D,
                               npc->scale.z * SPRITE_WORLD_SCALE_D);
            } while (0); // required to match (macro?)

            guMtxCatF(mtx2, mtx1, mtx1);
        }
        if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
            if (!(npc->flags & NPC_FLAG_HAS_NO_SPRITE) && (npc->curAnim != 0)) {
                spr_draw_npc_sprite(npc->spriteInstanceID, renderYaw, 0, 0, mtx1);
            }
        } else {
            spr_draw_player_sprite(PLAYER_SPRITE_AUX1 | DRAW_SPRITE_OVERRIDE_YAW, renderYaw, 0, 0, mtx1);
        }
    }
    npc->onRender(npc);
}

void render_npcs(void) {
    Npc* npc;
    RenderTask renderTask;
    RenderTask* renderTaskPtr = &renderTask;
    Camera* cam = &gCameras[gCurrentCamID];
    f32 x, y, z, s;
    f32 renderDist;
    s32 i;

    for (i = 0; i < MAX_NPCS; i++) {
        Npc* npc = (*gCurrentNpcListPtr)[i];
        if ((npc != NULL)
            && (npc->flags != 0)
            && !(npc->flags & (NPC_FLAG_SUSPENDED | NPC_FLAG_HAS_NO_SPRITE | NPC_FLAG_INACTIVE | NPC_FLAG_INVISIBLE))
        ) {
            transform_point(cam->perspectiveMatrix, npc->pos.x, npc->pos.y, npc->pos.z, 1.0f, &x, &y, &z, &s);
            if (!(s < 0.01) || !(s > -0.01)) {
                renderDist = ((z * 5000.0f) / s) + 5000.0f;
                if (renderDist < 0.0f) {
                    renderDist = 0.0f;
                } else if (renderDist > 10000.0f) {
                    renderDist = 10000.0f;
                }

                renderTaskPtr->dist = -renderDist;
                renderTaskPtr->appendGfxArg = npc;
                renderTaskPtr->appendGfx = appendGfx_npc;
                renderTaskPtr->renderMode = npc->renderMode;

                if (npc->flags & NPC_FLAG_HIDING) {
                    u8 r, g, b, a;
                    mdl_get_shroud_tint_params(&r, &g, &b, &a);
                    npc->hideAlpha = 255 - a;
                } else {
                    npc->hideAlpha = 255;
                }

                if (npc->hideAlpha != 0) {
                    queue_render_task(renderTaskPtr);
                }

                if (npc->flags & NPC_FLAG_MOTION_BLUR) {
                    renderTaskPtr->dist = -renderDist;
                    renderTaskPtr->appendGfx = appendGfx_npc_blur;
                    renderTaskPtr->appendGfxArg = npc;
                    renderTaskPtr->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
                    queue_render_task(renderTaskPtr);
                }
            }
        }
    }
}

void npc_move_heading(Npc* npc, f32 speed, f32 yaw) {
    f32 angle = DEG_TO_RAD(yaw);
    f32 sin = sin_rad(angle);
    f32 cos = cos_rad(angle);

    npc->pos.x += speed * sin;
    npc->pos.z += -speed * cos;
}

Npc* get_npc_unsafe(s32 npcID) {
    s32 i;
    Npc* npc;

    for (i = 0; i < MAX_NPCS; i++) {
        npc = (*gCurrentNpcListPtr)[i];
        if (npc != NULL && npc->flags != 0 && npc->npcID == npcID) {
            break;
        }
    }
    ASSERT(i < MAX_NPCS);

    return npc;
}

Npc* get_npc_safe(s32 npcID) {
    s32 i;
    Npc* npc;

    for (i = 0; i < MAX_NPCS; i++) {
        npc = (*gCurrentNpcListPtr)[i];
        if (npc != NULL && npc->flags != 0 && npc->npcID == npcID) {
            break;
        }
    }
    if (i >= MAX_NPCS) {
        return NULL;
    }

    return npc;
}

void enable_npc_shadow(Npc* npc) {
    Shadow* shadow;

    if (!(npc->flags & NPC_FLAG_HAS_SHADOW)) {
        shadow = get_shadow_by_index(npc->shadowIndex);
        shadow->flags &= ~ENTITY_FLAG_HIDDEN;
        npc->flags |= (NPC_FLAG_DIRTY_SHADOW | NPC_FLAG_HAS_SHADOW);
    }
}

void disable_npc_shadow(Npc* npc) {
    Shadow* shadow;

    if (npc->flags & NPC_FLAG_HAS_SHADOW) {
        shadow = get_shadow_by_index(npc->shadowIndex);
        shadow->flags |= ENTITY_FLAG_HIDDEN;
        npc->flags &= ~NPC_FLAG_HAS_SHADOW;
        npc->flags &= ~NPC_FLAG_DIRTY_SHADOW;
    }
}

void set_npc_sprite(Npc* npc, s32 anim, AnimID* extraAnimList) {
    ASSERT((npc->flags & NPC_FLAG_HAS_NO_SPRITE) || spr_free_sprite(npc->spriteInstanceID) == 0);

    npc->extraAnimList = extraAnimList;

    if (!(npc->flags & NPC_FLAG_HAS_NO_SPRITE)) {
        npc->spriteInstanceID = spr_load_npc_sprite(anim, extraAnimList);
        ASSERT(npc->spriteInstanceID >= 0);
    }

    npc->curAnim = anim;

    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
        if (!(npc->flags & NPC_FLAG_HAS_NO_SPRITE)) {
            spr_update_sprite(npc->spriteInstanceID, anim, npc->animationSpeed);
        }
    }
}

void enable_npc_blur(Npc* npc) {
    if (!(npc->flags & NPC_FLAG_MOTION_BLUR)) {
        NpcMotionBlur* motionBlur;
        s32 i;

        npc->flags |= NPC_FLAG_MOTION_BLUR;

        motionBlur = heap_malloc(sizeof(*motionBlur));
        npc->blur.motion = motionBlur;
        ASSERT(motionBlur != NULL);
        motionBlur->unused = 0;
        motionBlur->index = 0;

        for (i = 0; i < ARRAY_COUNT(motionBlur->posX); i++) {
            motionBlur->posX[i] = npc->pos.x;
            motionBlur->posY[i] = npc->pos.y;
            motionBlur->posZ[i] = npc->pos.z;
        }
    }
}

void disable_npc_blur(Npc* npc) {
    if (npc->flags & NPC_FLAG_MOTION_BLUR) {
        npc->flags &= ~NPC_FLAG_MOTION_BLUR;

        heap_free(npc->blur.motion);
        npc->blur.motion = NULL;
    }
}

void update_npc_blur(Npc* npc) {
    NpcMotionBlur* motionBlur = npc->blur.motion;
    s32 index = motionBlur->index;

    motionBlur->posX[index] = npc->pos.x;
    motionBlur->posY[index] = npc->pos.y;
    motionBlur->posZ[index] = npc->pos.z;

    index++;
    if (index >= 20) {
        index = 0;
    }

    motionBlur->index = index;
}

void appendGfx_npc_blur(void* data) {
    Npc* npc = (Npc*) data;
    Matrix4f mtx, tempMtx;
    f32 x, y, z;
    f32 yaw;
    s32 strideIdx;
    s32 drawIdx;
    s32 bufPos;
    NpcMotionBlur* blur;

    strideIdx = 0;
    drawIdx = 0;
    blur = npc->blur.motion;
    bufPos = blur->index;

    while (TRUE) {
        bufPos--;
        strideIdx++;

        if (bufPos < 0) {
            bufPos = NPC_BLUR_FRAMES - 1;
        }

        if (bufPos == blur->index) {
            break;
        }

        // only draw every third blur frame
        if (strideIdx < 3) {
            continue;
        }

        strideIdx = 0;
        drawIdx++;

        // draw three blur samples
        if (drawIdx > 3) {
            break;
        }

        x = blur->posX[bufPos];
        y = blur->posY[bufPos];
        z = blur->posZ[bufPos];
        set_npc_imgfx_all(npc->spriteInstanceID, IMGFX_SET_ALPHA, 255, 255, 255, 120 - (drawIdx * 20), 0);
        yaw = npc->renderYaw;
        guTranslateF(mtx, x, y, z);

        if (npc->rot.y != 0.0f) {
            guRotateF(tempMtx, npc->rot.y, 0.0f, 1.0f, 0.0f);
            guMtxCatF(tempMtx, mtx, mtx);
        }
        if (npc->rot.x != 0.0f) {
            guRotateF(tempMtx, npc->rot.y, 0.0f, 1.0f, 0.0f);
            guMtxCatF(tempMtx, mtx, mtx);
        }
        if (npc->rot.z != 0.0f) {
            guRotateF(tempMtx, npc->rot.y, 0.0f, 1.0f, 0.0f);
            guMtxCatF(tempMtx, mtx, mtx);
        }

        if ((npc->scale.x * SPRITE_WORLD_SCALE_D) != 1.0
            || ((npc->scale.y * npc->verticalStretch) * SPRITE_WORLD_SCALE_D) != 1.0
            || (npc->scale.z * SPRITE_WORLD_SCALE_D) != 1.0
        ) {
            guScaleF(
                tempMtx,
                npc->scale.x * SPRITE_WORLD_SCALE_D,
                (npc->scale.y * npc->verticalStretch) * SPRITE_WORLD_SCALE_D,
                npc->scale.z * SPRITE_WORLD_SCALE_D
            );
            guMtxCatF(tempMtx, mtx, mtx);
        }

        if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
            if (!(npc->flags & NPC_FLAG_HAS_NO_SPRITE)) {
                spr_draw_npc_sprite(npc->spriteInstanceID, yaw, 0, 0, mtx);
            }
        } else {
            spr_draw_player_sprite(PLAYER_SPRITE_AUX1 | DRAW_SPRITE_OVERRIDE_YAW, yaw, 0, 0, mtx);
        }
    }
    npc_imgfx_update(npc);
}

void npc_enable_collisions(void) {
    gNpcPlayerCollisionsEnabled = TRUE;
}

void npc_disable_collisions(void) {
    gNpcPlayerCollisionsEnabled = FALSE;
}

void func_8003B1A8(void) {
}

void npc_reload_all(void) {
    s32 i;
    s32 j;

    for (i = 0; i < MAX_NPCS; i++) {
        Npc* npc = (*gCurrentNpcListPtr)[i];
        if (npc != NULL) {
            if (npc->flags && !(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
                if (!(npc->flags & NPC_FLAG_HAS_NO_SPRITE)) {
                    if (!(npc->flags & NPC_FLAG_PARTNER)) {
                        npc->spriteInstanceID = spr_load_npc_sprite(npc->curAnim, npc->extraAnimList);
                    } else {
                        npc->spriteInstanceID = spr_load_npc_sprite(npc->curAnim | SPRITE_ID_TAIL_ALLOCATE, npc->extraAnimList);
                    }
                }
                if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
                    if (!(npc->flags & NPC_FLAG_HAS_NO_SPRITE) && (npc->palSwapType != NPC_PAL_ADJUST_NONE)) {
                        npc->originalPalettesList = spr_get_npc_palettes(npc->curAnim >> 16);
                        npc->originalPalettesCount = 0;
                        while (npc->originalPalettesList[npc->originalPalettesCount] != (PAL_PTR) -1) {
                            npc->originalPalettesCount++;
                        }
                        npc->spriteColorVariations = spr_get_npc_color_variations(npc->curAnim >> 16);
                    }
                    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
                        if (!(npc->flags & NPC_FLAG_HAS_NO_SPRITE)) {
                            for (j = 0; j < MAX_NPC_DECORATIONS; j++) {
                                npc_reset_current_decoration(npc, j);
                            }
                            npc_imgfx_update(npc);
                        }
                    }
                }
            }
        }
    }
}

void set_npc_yaw(Npc* npc, f32 yaw) {
    npc->yaw = yaw;

    if (get_clamped_angle_diff(gCameras[gCurrentCameraID].curYaw, yaw) >= 0.0f) {
        npc->yawCamOffset = 180;
        npc->isFacingAway = TRUE;
    } else {
        npc->yawCamOffset = 0;
        npc->isFacingAway = FALSE;
    }
}

void npc_set_palswap_mode_A(Npc* npc, s32 mode) {
    if (npc->palSwapType != mode) {
        npc->palSwapPrevType = npc->palSwapType;
        npc->palSwapType = mode;
        npc->palAnimState = PAL_SWAP_HOLD_A;
        npc->resetPalAdjust = 1;
    }
}

void npc_set_palswap_mode_B(Npc* npc, s32 mode) {
    if (npc->palSwapType != mode) {
        npc->palSwapPrevType = npc->palSwapType;
        npc->palSwapType = mode;
        npc->palAnimState = PAL_SWAP_HOLD_A;
        npc->resetPalAdjust = -1;
    }
}

void npc_revert_palswap_mode(Npc* npc) {
    if (npc->palSwapPrevType == NPC_PAL_ADJUST_NONE) {
        npc->palSwapType = NPC_PAL_ADJUST_NONE;
        return;
    }
    npc->palSwapType = npc->palSwapPrevType;
    npc->palSwapPrevType = NPC_PAL_ADJUST_NONE;
    npc->palAnimState = PAL_SWAP_HOLD_A;
    npc->resetPalAdjust = 1;
}

void npc_set_palswap_1(Npc* npc, s32 palIndexA, s32 palIndexB, s32 timeHoldA, s32 timeAB) {
    npc->blendPalA = palIndexA;
    npc->blendPalB = palIndexB;
    npc->palswapTimeHoldA = timeHoldA;
    npc->palswapTimeAtoB = timeAB;
}

void npc_set_palswap_2(Npc* npc, s32 timeHoldB, s32 timeBA, s32 palIndexC, s32 palIndexD) {
    npc->palswapTimeHoldB = timeHoldB;
    npc->palswapTimeBtoA = timeBA;
    npc->blendPalC = palIndexC;
    npc->blendPalD = palIndexD;
}

void npc_draw_with_palswap(Npc* npc, s32 yaw, Matrix4f mtx) {
    switch (npc->palSwapType) {
        case NPC_PAL_ADJUST_NONE:
            npc_render_without_adjusted_palettes(npc, yaw, mtx);
            break;
        case NPC_PAL_ADJUST_WATT_IDLE:
            npc_render_with_watt_idle_palettes(npc, yaw, mtx);
            break;
        case NPC_PAL_ADJUST_BLEND_PALETTES_UNIFORM_INTERVALS:
            npc_render_with_single_pal_blending(npc, yaw, FALSE, mtx);
            break;
        case NPC_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS:
            npc_render_with_single_pal_blending(npc, yaw, TRUE, mtx);
            break;
        case NPC_PAL_ADJUST_BLEND_DOUBLE_PALETTES:
            npc_render_with_double_pal_blending(npc, yaw, mtx);
            break;
    }
}

void npc_render_without_adjusted_palettes(Npc* npc, s32 arg1, Matrix4f mtx) {
    if (npc->resetPalAdjust != 0) {
        npc->verticalStretch = 1.0f;
        npc->screenSpaceOffset2D[0] = 0.0f;
        npc->screenSpaceOffset2D[1] = 0.0f;
        npc->resetPalAdjust = 0;
    }

    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
        s32 alpha = (npc->alpha * npc->hideAlpha / 255);
        u32 mask;
        if (alpha < 255) {
            mask = DRAW_SPRITE_OVERRIDE_ALPHA;
        } else {
            mask = 0;
        }
        spr_draw_npc_sprite(npc->spriteInstanceID | mask, arg1, alpha, NULL, mtx);
    } else {
        spr_draw_player_sprite(PLAYER_SPRITE_AUX1 | DRAW_SPRITE_OVERRIDE_YAW, arg1, 0, 0, mtx);
    }
}

s32 npc_render_with_watt_idle_palettes(Npc* npc, s32 arg1, Matrix4f mtx) {
    s32 i, j;
    s32 brightness;
    PAL_PTR src;
    PAL_PTR dst;

    if (npc->resetPalAdjust != 0) {
        npc->originalPalettesList = spr_get_npc_palettes(npc->curAnim >> 16);
        npc->originalPalettesCount = 0;
        while ((s32)npc->originalPalettesList[npc->originalPalettesCount] != -1) {
            npc->originalPalettesCount++;
        }

        npc->spriteColorVariations = spr_get_npc_color_variations(npc->curAnim >> 16);
        for (i = 0; i < npc->originalPalettesCount; i++) {
            dst = npc->copiedPalettes[i];
            src = npc->originalPalettesList[i];
            if (src != NULL) {
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *dst++ = *src++;
                }
            }
        }

        npc->palAnimState = -2;
        npc->palBlendAlpha = 0;
        npc->resetPalAdjust = 0;
        npc->nextPalTime = 0;
    }

    if (npc->nextPalTime == 0) {
        npc->palAnimState += 2;
        brightness = wWattIdlePalettesAnim[npc->palAnimState];
        if (brightness == 255) {
            npc->palAnimState = 0;
        }
        npc->nextPalTime = wWattIdlePalettesAnim[npc->palAnimState + 1] / 2;
    }

    brightness = wWattIdlePalettesAnim[npc->palAnimState];
    npc->nextPalTime--;

    switch(brightness) {
        case WATT_DEFAULT:
            for (i = 0; i < npc->spriteColorVariations; i++) {
                dst = npc->copiedPalettes[i];
                src = npc->originalPalettesList[i];
                if (src != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *dst++ = *src++;
                    }
                }
            }
            break;
        case WATT_BRIGHTEST:
            for (i = 0; i < npc->spriteColorVariations; i++) {
                // use watt's Brightest palettes
                dst = npc->copiedPalettes[i];
                src = npc->originalPalettesList[npc->spriteColorVariations * SPR_PAL_WorldWatt_Brightest + i];
                if (src != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *dst++ = *src++;
                    }
                }
            }
            break;
        case WATT_BRIGHTER:
            for (i = 0; i < npc->spriteColorVariations; i++) {
                // use watt's Brighter palettes
                dst = npc->copiedPalettes[i];
                src = npc->originalPalettesList[npc->spriteColorVariations * SPR_PAL_WorldWatt_Brighter + i];
                if (src != NULL) {
                    for (j = 0; j < SPR_PAL_SIZE; j++) {
                        *dst++ = *src++;
                    }
                }
            }
            break;
    }

    for (i = 0; i < npc->originalPalettesCount; i++) {
        npc->adjustedPalettes[i] = npc->copiedPalettes[i];
    }

    if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
        s32 alpha = npc->alpha * npc->hideAlpha / 255;
        u32 mask = 0;
        if (alpha < 255) {
            mask |= DRAW_SPRITE_OVERRIDE_ALPHA;
        }
        mask |= DRAW_SPRITE_OVERRIDE_PALETTES;
        spr_draw_npc_sprite(npc->spriteInstanceID | mask, arg1, alpha, npc->adjustedPalettes, mtx);
    }
    npc->palBlendAlpha--;
}

u16 npc_blend_palette_colors(u16 colorA, u16 colorB, s32 lerpAlpha) {
    u8 r = (UNPACK_PAL_R(colorA) * (255 - lerpAlpha) + UNPACK_PAL_R(colorB) * lerpAlpha) / 255;
    u8 g = (UNPACK_PAL_G(colorA) * (255 - lerpAlpha) + UNPACK_PAL_G(colorB) * lerpAlpha) / 255;
    u8 b = (UNPACK_PAL_B(colorA) * (255 - lerpAlpha) + UNPACK_PAL_B(colorB) * lerpAlpha) / 255;
    u8 a = UNPACK_PAL_A(colorB);

    return PACK_PAL_RGBA(r, g, b, a);
}

s32 npc_render_with_single_pal_blending(Npc* npc, s32 yaw, b32 hasDifferentIntervals, Matrix4f mtx) {
    PAL_PTR color1;
    PAL_PTR color2;
    PAL_PTR outColor;
    s32 i, j;
    s32 blendAlpha;

    // copy palettes from sprite data
    if (npc->resetPalAdjust != 0) {
        if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
            npc->originalPalettesList = spr_get_npc_palettes(npc->curAnim >> 16);
        }

        npc->originalPalettesCount = 0;
        while ((s32)npc->originalPalettesList[npc->originalPalettesCount] != -1) {
            npc->originalPalettesCount++;
        }

        if (npc->resetPalAdjust == 1) {
            npc->palAnimState = PAL_SWAP_HOLD_A;
            npc->palBlendAlpha = 0;
        } else {
            npc->palAnimState = PAL_SWAP_HOLD_A;
            npc->palBlendAlpha = 255;
        }

        for (i = 0; i < npc->originalPalettesCount; i++) {
            color1 = npc->copiedPalettes[i];
            color2 = npc->originalPalettesList[i];
            npc->adjustedPalettes[i] = color1;
            if (color2 != NULL) {
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *color1++ = *color2++;
                }
            }
        }

        if (!hasDifferentIntervals) {
            npc->palswapTimeAtoB = npc->palswapTimeHoldA;
            npc->palswapTimeHoldB = npc->palswapTimeHoldA;
            npc->palswapTimeBtoA = npc->palswapTimeAtoB;
            npc->palswapTimeHoldA = 0;
        }

        npc->nextPalTime = npc->palswapTimeHoldA;
        npc->palBlendAlpha = 0;
        npc->palAnimState = PAL_SWAP_HOLD_A;
        npc->resetPalAdjust = 0;
    }

    // blending from A -> B
    switch (npc->palAnimState) {
        case PAL_SWAP_HOLD_A:
            if (npc->nextPalTime != 0) {
                npc->nextPalTime--;
                break;
            } else {
                npc->palBlendAlpha = 0;
                npc->palAnimState = PAL_SWAP_A_TO_B;
            }
            // fallthrough
        case PAL_SWAP_A_TO_B:
            npc->palBlendAlpha += 25600 / npc->palswapTimeAtoB;
            if (npc->palBlendAlpha > 25500) {
                npc->palBlendAlpha = 25500;
            }
            blendAlpha = npc->palBlendAlpha / 100;
            // blend two palettes
            outColor = npc->copiedPalettes[0];
            color2 = npc->originalPalettesList[npc->blendPalA];
            color1 = npc->originalPalettesList[npc->blendPalB];
            npc->adjustedPalettes[0] = outColor;

            for (j = 0; j < SPR_PAL_SIZE; j++) {
                *outColor++ = npc_blend_palette_colors(*color2++, *color1++, blendAlpha);
            }

            if (blendAlpha == 255) {
                npc->palAnimState = PAL_SWAP_HOLD_B;
                npc->nextPalTime = npc->palswapTimeHoldB;
            }
            break;
    }

    // blending from B -> A
    switch (npc->palAnimState) {
        case PAL_SWAP_HOLD_B:
            if (npc->nextPalTime != 0) {
                npc->nextPalTime--;
                break;
            } else {
                npc->palBlendAlpha = 0;
                npc->palAnimState = PAL_SWAP_B_TO_A;
            }
            // fallthrough
        case PAL_SWAP_B_TO_A:
            npc->palBlendAlpha += 25600 / npc->palswapTimeBtoA;
            if (npc->palBlendAlpha > 25500) {
                npc->palBlendAlpha = 25500;
            }
            blendAlpha = npc->palBlendAlpha / 100;
            // blend two palettes
            outColor = npc->copiedPalettes[0];
            color2 = npc->originalPalettesList[npc->blendPalB];
            color1 = npc->originalPalettesList[npc->blendPalA];
            npc->adjustedPalettes[0] = outColor;

            for (j = 0; j < SPR_PAL_SIZE; j++) {
                *outColor++ = npc_blend_palette_colors(*color2++, *color1++, blendAlpha);
            }

            if (blendAlpha == 255) {
                npc->palAnimState = PAL_SWAP_HOLD_A;
                npc->nextPalTime = npc->palswapTimeHoldA;
            }
            break;
    }

    switch (npc->palAnimState) {
        case PAL_SWAP_HOLD_A:
        case PAL_SWAP_A_TO_B:
        case PAL_SWAP_HOLD_B:
        case PAL_SWAP_B_TO_A:
            if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
                u32 mask = 0;
                blendAlpha = npc->alpha * npc->hideAlpha / 255;
                if (blendAlpha < 255) {
                    mask |= DRAW_SPRITE_OVERRIDE_ALPHA;
                }
                mask |= DRAW_SPRITE_OVERRIDE_PALETTES;
                spr_draw_npc_sprite(npc->spriteInstanceID | mask, yaw, blendAlpha, npc->adjustedPalettes, mtx);
            }
            break;
    }
}

s32 npc_render_with_double_pal_blending(Npc* npc, s32 yaw, Matrix4f mtx) {
    PAL_PTR color1;
    PAL_PTR color2;
    PAL_PTR outColor;
    s32 i, j;
    u8 blendAlpha;

    // copy palettes from sprite data
    if (npc->resetPalAdjust != 0) {
        if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
            npc->originalPalettesList = spr_get_npc_palettes(npc->curAnim >> 16);
        }

        npc->originalPalettesCount = 0;
        while ((s32)npc->originalPalettesList[npc->originalPalettesCount] != -1) {
            npc->originalPalettesCount++;
        }

        if (npc->resetPalAdjust == 1) {
            npc->palAnimState = PAL_SWAP_HOLD_A;
            npc->palBlendAlpha = 0;
        } else {
            npc->palAnimState = PAL_SWAP_HOLD_A;
            npc->palBlendAlpha = 255;
        }

        for (i = 0; i < npc->originalPalettesCount; i++) {
            color1 = npc->copiedPalettes[i];
            color2 = npc->originalPalettesList[i];
            npc->adjustedPalettes[i] = color1;
            if (color2 != NULL) {
                for (j = 0; j < SPR_PAL_SIZE; j++) {
                    *color1++ = *color2++;
                }
            }
        }

        npc->nextPalTime = npc->palswapTimeHoldA;
        npc->palBlendAlpha = 0;
        npc->palAnimState = PAL_SWAP_HOLD_A;
        npc->resetPalAdjust = 0;
    }

    // blending from A -> B
    switch (npc->palAnimState) {
        case PAL_SWAP_HOLD_A:
            if (npc->nextPalTime != 0) {
                npc->nextPalTime--;
                break;
            }
            npc->palBlendAlpha = 0;
            npc->palAnimState = PAL_SWAP_A_TO_B;
            // fallthrough
        case PAL_SWAP_A_TO_B:
            npc->palBlendAlpha += 25600 / npc->palswapTimeAtoB;
            if (npc->palBlendAlpha > 25500) {
                npc->palBlendAlpha = 25500;
            }
            blendAlpha = npc->palBlendAlpha / 100;

            // blend first two palettes
            outColor = npc->copiedPalettes[0];
            color2 = npc->originalPalettesList[npc->blendPalA];
            color1 = npc->originalPalettesList[npc->blendPalB];
            npc->adjustedPalettes[0] = outColor;

            for (j = 0; j < SPR_PAL_SIZE; j++) {
                *outColor++ = npc_blend_palette_colors(*color2++, *color1++, blendAlpha);
            }

            // blend next palettes
            outColor = npc->copiedPalettes[3];
            color2 = npc->originalPalettesList[npc->blendPalC];
            color1 = npc->originalPalettesList[npc->blendPalD];
            npc->adjustedPalettes[3] = outColor;

            for (j = 0; j < SPR_PAL_SIZE; j++) {
                *outColor++ = npc_blend_palette_colors(*color2++, *color1++, blendAlpha);
            }

            if (blendAlpha == 255) {
                npc->palAnimState = PAL_SWAP_HOLD_B;
                npc->nextPalTime = npc->palswapTimeHoldB;
            }
            break;
    }

    // blending from B -> A
    switch (npc->palAnimState) {
        case PAL_SWAP_HOLD_B:
            if (npc->nextPalTime != 0) {
                npc->nextPalTime--;
                break;
            } else {
                npc->palBlendAlpha = 0;
                npc->palAnimState = PAL_SWAP_B_TO_A;
            }
            // fallthrough
        case PAL_SWAP_B_TO_A:
            npc->palBlendAlpha += 25600 / npc->palswapTimeBtoA;
            if (npc->palBlendAlpha > 25500) {
                npc->palBlendAlpha = 25500;
            }
            blendAlpha = npc->palBlendAlpha / 100;

            // blend first two palettes
            outColor = npc->copiedPalettes[0];
            color2 = npc->originalPalettesList[npc->blendPalB];
            color1 = npc->originalPalettesList[npc->blendPalA];
            npc->adjustedPalettes[0] = outColor;

            for (j = 0; j < SPR_PAL_SIZE; j++) {
                *outColor++ = npc_blend_palette_colors(*color2++, *color1++, blendAlpha);
            }

            // blend next palettes
            outColor = npc->copiedPalettes[1]; /// @bug? should this be index 3?
            color2 = npc->originalPalettesList[npc->blendPalD];
            color1 = npc->originalPalettesList[npc->blendPalC];
            npc->adjustedPalettes[3] = npc->copiedPalettes[3];

            for (j = 0; j < SPR_PAL_SIZE; j++) {
                *outColor++ = npc_blend_palette_colors(*color2++, *color1++, blendAlpha);
            }

            if (blendAlpha == 255) {
                npc->palAnimState = PAL_SWAP_HOLD_A;
                npc->nextPalTime = npc->palswapTimeHoldA;
            }
            break;
    }

    switch (npc->palAnimState) {
        case PAL_SWAP_HOLD_A:
        case PAL_SWAP_A_TO_B:
        case PAL_SWAP_HOLD_B:
        case PAL_SWAP_B_TO_A:
            if (!(npc->flags & NPC_FLAG_NO_ANIMS_LOADED)) {
                u32 mask = 0;
                blendAlpha = npc->alpha * npc->hideAlpha / 255;
                if (blendAlpha < 255) {
                    mask |= DRAW_SPRITE_OVERRIDE_ALPHA;
                }
                mask |= DRAW_SPRITE_OVERRIDE_PALETTES;
                spr_draw_npc_sprite(npc->spriteInstanceID | mask, yaw, blendAlpha, npc->adjustedPalettes, mtx);
            }
            break;
    }
}

void npc_set_decoration(Npc* npc, s32 idx, s32 decorationType) {
    npc_remove_decoration_impl(npc, idx);
    npc->decorationType[idx] = decorationType;
    npc->changedDecoration[idx] = 1;
    npc->decorationInitialized[idx] = 0;
}

void npc_remove_decoration(Npc* npc, s32 idx) {
    npc_remove_decoration_impl(npc, idx);
}

s32 npc_update_decorations(Npc* npc) {
    s32 i;

    for (i = 0; i < MAX_NPC_DECORATIONS; i++) {
        switch (npc->decorationType[i]) {
            case NPC_DECORATION_NONE:
                npc_update_decoration_none(npc, i);
                break;
            case NPC_DECORATION_BOWSER_AURA:
                npc_update_decoration_bowser_aura(npc, i);
                break;
            case NPC_DECORATION_SWEAT:
                npc_update_decoration_sweat(npc, i);
                break;
            case NPC_DECORATION_SEEING_STARS:
                npc_update_decoration_seeing_stars(npc, i);
                break;
            case NPC_DECORATION_WHITE_GLOW_FRONT:
                npc_update_decoration_glow_in_front(npc, i);
                break;
            case NPC_DECORATION_WHITE_GLOW_BEHIND:
                npc_update_decoration_glow_behind(npc, i);
                break;
            case NPC_DECORATION_CHARGED:
                npc_update_decoration_charged(npc, i);
                break;
        }
    }
}

void npc_remove_decoration_impl(Npc* npc, s32 idx) {
    switch (npc->decorationType[idx]) {
        case NPC_DECORATION_NONE:
            npc_remove_decoration_none(npc, idx);
            break;
        case NPC_DECORATION_BOWSER_AURA:
            npc_remove_decoration_bowser_aura(npc, idx);
            break;
        case NPC_DECORATION_SWEAT:
            npc_remove_decoration_sweat(npc, idx);
            break;
        case NPC_DECORATION_SEEING_STARS:
            npc_remove_decoration_seeing_stars(npc, idx);
            break;
        case NPC_DECORATION_WHITE_GLOW_FRONT:
            npc_remove_decoration_glow_in_front(npc, idx);
            break;
        case NPC_DECORATION_WHITE_GLOW_BEHIND:
            npc_remove_decoration_glow_behind(npc, idx);
            break;
        case NPC_DECORATION_CHARGED:
            npc_remove_decoration_charged(npc, idx);
            break;
    }
    npc->decorationType[idx] = NPC_DECORATION_NONE;
}

void npc_reset_current_decoration(Npc* npc, s32 idx) {
    switch (npc->decorationType[idx]) {
        case NPC_DECORATION_NONE:
        case NPC_DECORATION_BOWSER_AURA:
        case NPC_DECORATION_SWEAT:
        case NPC_DECORATION_SEEING_STARS:
        case NPC_DECORATION_WHITE_GLOW_FRONT:
        case NPC_DECORATION_WHITE_GLOW_BEHIND:
            break;
        case NPC_DECORATION_CHARGED:
            npc__reset_current_decoration(npc, idx);
            break;
    }
}

void npc_update_decoration_none(Npc* npc, s32 idx) {
}

void npc_remove_decoration_none(Npc* npc, s32 idx) {
}

void npc_update_decoration_bowser_aura(Npc* npc, s32 idx) {
    AuraFXData* data;

    switch (npc->decorationInitialized[idx]) {
        case 0:
            fx_aura(FX_AURA_BLUE, npc->pos.x, npc->pos.y, npc->pos.z, 1.0f, &npc->decorations[idx]);
            npc->decorationInitialized[idx] = 1;
            // fallthrough
        case 1:
            data = npc->decorations[idx]->data.aura;
            data->posA.x = npc->pos.x;
            data->posA.y = npc->pos.y;
            data->posA.z = npc->pos.z;
            data->scale.x = (npc->scale.x * npc->collisionDiameter) * 0.01;
            data->scale.y = (npc->scale.y * npc->collisionHeight) * 0.01;
            data->renderYaw = npc->renderYaw;
            break;
    }
}

void npc_remove_decoration_bowser_aura(Npc* npc, s32 idx) {
    npc->decorations[idx]->data.aura->fadeTime = 5;
}

void npc_update_decoration_sweat(Npc* npc, s32 idx) {
    switch (npc->decorationInitialized[idx]) {
        case 0:
            if (npc->yawCamOffset > 90) {
                fx_sweat(0, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, 5.0f, 45.0f, 20);
            } else {
                fx_sweat(0, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, 5.0f, -45.0f, 20);
            }
            npc->decorationGlowPhase[idx] = 10;
            npc->decorationInitialized[idx] = 1;
            break;
        case 1:
            if (npc->decorationGlowPhase[idx] != 0) {
                npc->decorationGlowPhase[idx]--;
            } else {
                npc->decorationInitialized[idx] = 0;
            }
            break;
    }
}

void npc_remove_decoration_sweat(Npc* npc, s32 idx) {
}

void npc_update_decoration_seeing_stars(Npc* npc, s32 idx) {
    StarsOrbitingFXData* data;

    switch (npc->decorationInitialized[idx]) {
        case 0:
            fx_stars_orbiting(0, npc->pos.x, npc->pos.y + npc->collisionHeight, npc->pos.z, 20.0f, 3, &npc->decorations[idx]);
            npc->decorationInitialized[idx] = 1;
            break;
        case 1:
            data = npc->decorations[idx]->data.starsOrbiting;
            data->pos.x = npc->pos.x;
            data->pos.y = npc->pos.y + npc->collisionHeight;
            data->pos.z = npc->pos.z;
            break;
    }
}

void npc_remove_decoration_seeing_stars(Npc* npc, s32 idx) {
    remove_effect(npc->decorations[idx]);
}

void npc_update_decoration_glow_in_front(Npc* npc, s32 idx) {
    EnergyOrbWaveFXData* data;

    switch (npc->decorationInitialized[idx]) {
        case 0:
            npc->decorations[idx] = fx_energy_orb_wave(2, npc->pos.x, npc->pos.y + npc->collisionHeight * 0.5, npc->pos.z, npc->scale.x * 0.8 + 0.2f, -1);
            npc->decorationInitialized[idx] = 1;
            break;
        case 1:
            data = npc->decorations[idx]->data.energyOrbWave;
            data->pos.x = npc->pos.x;
            data->pos.y = npc->pos.y + npc->collisionHeight * 0.5 * npc->scale.x;
            data->pos.z = npc->pos.z;
            data->scale = npc->scale.x * 0.8 + 0.2f;
            break;
    }
}

void npc_remove_decoration_glow_in_front(Npc* npc, s32 idx) {
    remove_effect(npc->decorations[idx]);
}

void npc_update_decoration_glow_behind(Npc* npc, s32 idx) {
    EnergyOrbWaveFXData* data;

    switch (npc->decorationInitialized[idx]) {
        case 0:
            npc->decorations[idx] = fx_energy_orb_wave(2, npc->pos.x, npc->pos.y + npc->collisionHeight * 0.5, npc->pos.z - 5.0f, 1.0f, 0);
            npc->decorationInitialized[idx] = 1;
            break;
        case 1:
            data = npc->decorations[idx]->data.energyOrbWave;
            data->pos.x = npc->pos.x;
            data->pos.y = npc->pos.y + npc->collisionHeight * 0.5;
            data->pos.z = npc->pos.z - 5.0f;
            data->scale = 1.0f;
            break;
    }
}

void npc_remove_decoration_glow_behind(Npc* npc, s32 idx) {
    remove_effect(npc->decorations[idx]);
}

void npc_update_decoration_charged(Npc* npc, s32 idx) {
    u8 rbuf[20];
    u8 gbuf[20];
    u8 bbuf[20];
    s32 color;
    s32 alpha;
    s32 i;

    if (npc->decorationInitialized[idx] == 0) {
        set_npc_imgfx_all(npc->spriteInstanceID, IMGFX_ALLOC_COLOR_BUF, 20, 0, 0, 255, 0);
        npc->decorationInitialized[idx] = 1;
    }
    if (npc->decorationInitialized[idx] == 1) {
        npc->decorationGlowPhase[idx] += 7;
        if (npc->decorationGlowPhase[idx] >= 360) {
            npc->decorationGlowPhase[idx] %= 360;
        }

        for (i = 0; i < 20; i++) {
            rbuf[i] = (cosine(npc->decorationGlowPhase[idx] + (25 * i)) + 1.0) * 80.0f;
            gbuf[i] = (cosine(npc->decorationGlowPhase[idx] + (25 * i) + 45) + 1.0) * 80.0f;
            bbuf[i] = (cosine(npc->decorationGlowPhase[idx] + (25 * i) + 90) + 1.0) * 80.0f;
        }

        alpha = 255;
        for (i = 0; i < 20; i++) {
            color = (rbuf[i] << 24) | (gbuf[i] << 16) | (bbuf[i] << 8) | alpha;
            set_npc_imgfx_all(npc->spriteInstanceID, IMGFX_COLOR_BUF_SET_MODULATE, i, color, 0, 255, 0);
        }
    }
}

void npc_remove_decoration_charged(Npc* npc, s32 idx) {
}

void npc__reset_current_decoration(Npc* npc, s32 idx) {
    npc->decorationInitialized[idx] = 0;
}

Npc* npc_find_closest(f32 x, f32 y, f32 z, f32 radius) {
    Npc* closestNpc = NULL;
    f32 closestDist = radius;
    f32 maxDist = radius;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentNpcListPtr); i++) {
        Npc* npc = (*gCurrentNpcListPtr)[i];

        if (npc != NULL && npc->flags != 0 && !(npc->flags & NPC_FLAG_PARTNER)) {
            if (!(npc->flags & (NPC_FLAG_SUSPENDED | NPC_FLAG_INACTIVE))) {
                f32 distance = fabsf(dist2D(npc->pos.x, npc->pos.z, x, z));

                if (distance <= maxDist) {
                    if (distance < closestDist) {
                        closestDist = distance;
                        closestNpc = npc;
                    }
                }
            }
        }
    }

    return closestNpc;
}

Npc* npc_find_closest_simple(f32 x, f32 y, f32 z, f32 radius) {
    Npc* closestNpc = NULL;
    f32 closestDist = radius;
    f32 maxDist = radius;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(*gCurrentNpcListPtr); i++) {
        Npc* npc = (*gCurrentNpcListPtr)[i];

        if (npc != NULL && npc->flags != 0 && (npc->flags & NPC_FLAG_PARTNER)) {
            if (!(npc->flags & (NPC_FLAG_SUSPENDED | NPC_FLAG_INACTIVE))) {
                f32 distance = fabsf(dist2D(npc->pos.x, npc->pos.z, x, z));

                if (distance <= maxDist) {
                    if (distance < closestDist) {
                        closestDist = distance;
                        closestNpc = npc;
                    }
                }
            }
        }
    }

    return closestNpc;
}

s32 npc_find_standing_on_entity(s32 entityIndex) {
    s32 idx = entityIndex | COLLISION_WITH_ENTITY_BIT;
    s32 y = get_entity_by_index(idx)->pos.y - 10.0f;
    Npc* npc;
    s32 i;
    s32 var_v1;

    npc->pos = npc->pos; // TODO required to match

    for (i = 0; i < ARRAY_COUNT(*gCurrentNpcListPtr); i++) {
        npc = (*gCurrentNpcListPtr)[i];

        if (npc == NULL) {
            continue;
        }
        if (npc->flags == 0) {
            continue;
        }
        if (npc->flags & (NPC_FLAG_SUSPENDED | NPC_FLAG_INACTIVE)) {
            continue;
        }
        if (npc->flags & NPC_FLAG_PARTNER) {
            var_v1 = i; // TODO required to match (dummy if statement to load NPC_FLAG_PARTNER into s5)
        }
        if (npc->pos.y < y) {
            continue;
        }
        if (npc->flags & (NPC_FLAG_IGNORE_ENTITY_COLLISION | NPC_FLAG_FLYING)) {
            var_v1 = npc_get_collider_below(npc);
            if (var_v1 != 0) {
                if (idx == var_v1) {
                    return i;
                }
            }
        } else {
            var_v1 = npc->curFloor;
            if (npc->curFloor & COLLISION_WITH_ENTITY_BIT) { // TODO required to match (can't use var_v1)
                if (idx == var_v1) {
                    npc->pos = npc->pos; // TODO required to match
                    return i;
                }
            }
        }
    }

    return -1;
}

s32 npc_get_collider_below(Npc* npc) {
    f32 x;
    f32 y;
    f32 z;
    f32 yaw;

    if (npc->flags & NPC_FLAG_PARTNER) {
        y = get_shadow_by_index(npc->shadowIndex)->pos.y + 13.0f;
    } else {
        y = npc->pos.y + 13.0f;
    }

    yaw = 16.0f;
    x = npc->pos.x;
    z = npc->pos.z;

    if (npc_raycast_down_sides(COLLIDER_FLAG_IGNORE_SHELL | COLLIDER_FLAG_IGNORE_PLAYER | COLLIDER_FLAG_IGNORE_NPC, &x, &y, &z, &yaw)) {
        if (yaw <= 16.0f) {
            return NpcHitQueryColliderID;
        }
    }
    return 0;
}

void npc_imgfx_update(Npc* npc) {
    s32 imgfxType = npc->imgfxType;
    s32 imgfxArg1 = npc->imgfxArg1;
    s32 imgfxArg2 = npc->imgfxArg2;
    s32 imgfxArg3 = npc->imgfxArg3;
    s32 imgfxArg4 = npc->imgfxArg4;
    s32 imgfxFlags = npc->imgfxFlags;

    set_npc_imgfx_all(npc->spriteInstanceID, IMGFX_CLEAR, 0, 0, 0, 0, 0);

    switch (imgfxType) {
        case IMGFX_CLEAR:
            npc->renderMode = RENDER_MODE_ALPHATEST;
            set_npc_imgfx_all(npc->spriteInstanceID, IMGFX_CLEAR, 0, 0, 0, 0, imgfxFlags);
            break;
        case IMGFX_UNK_2:
        case IMGFX_RESET:
            npc->renderMode = RENDER_MODE_ALPHATEST;
            // fallthrough
        case IMGFX_UNK_1:
            set_npc_imgfx_all(npc->spriteInstanceID, imgfxType, 0, 0, 0, 0, imgfxFlags);
            break;
        case IMGFX_SET_WAVY:
            npc->renderMode = RENDER_MODE_ALPHATEST;
            set_npc_imgfx_all(npc->spriteInstanceID, IMGFX_SET_WAVY, imgfxArg1, imgfxArg2, imgfxArg3, 0, imgfxFlags);
            break;
        case IMGFX_SET_COLOR:
            npc->renderMode = RENDER_MODE_ALPHATEST;
            set_npc_imgfx_all(npc->spriteInstanceID, IMGFX_SET_COLOR, imgfxArg1, imgfxArg2, imgfxArg3, 255, imgfxFlags);
            break;
        case IMGFX_SET_ALPHA:
            npc->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
            set_npc_imgfx_all(npc->spriteInstanceID, IMGFX_SET_ALPHA, 255, 255, 255, imgfxArg1, imgfxFlags);
            break;
        case IMGFX_SET_TINT:
            npc->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
            set_npc_imgfx_all(npc->spriteInstanceID, IMGFX_SET_TINT, imgfxArg1, imgfxArg2, imgfxArg3, imgfxArg4, imgfxFlags);
            break;
        case IMGFX_SET_WHITE_FADE:
            npc->renderMode = RENDER_MODE_ALPHATEST;
            set_npc_imgfx_all(npc->spriteInstanceID, IMGFX_SET_WHITE_FADE, imgfxArg1, imgfxArg2, imgfxArg3, 255, imgfxFlags);
            break;
        case IMGFX_SET_CREDITS_FADE:
            npc->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
            set_npc_imgfx_all(npc->spriteInstanceID, IMGFX_SET_CREDITS_FADE, imgfxArg1, imgfxArg2, imgfxArg3, imgfxArg4, imgfxFlags);
            break;
        case IMGFX_SET_ANIM:
            npc->renderMode = RENDER_MODE_ALPHATEST;
            set_npc_imgfx_all(npc->spriteInstanceID, IMGFX_SET_ANIM, imgfxArg1, imgfxArg2, imgfxArg3, 0, imgfxFlags);
            break;
        case IMGFX_HOLOGRAM:
            npc->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
            set_npc_imgfx_all(npc->spriteInstanceID, IMGFX_HOLOGRAM, imgfxArg1, imgfxArg2, imgfxArg3, imgfxArg4, imgfxFlags);
            break;
        case IMGFX_FILL_COLOR:
            npc->renderMode = RENDER_MODE_ALPHATEST;
            set_npc_imgfx_all(npc->spriteInstanceID, IMGFX_FILL_COLOR, imgfxArg1, imgfxArg2, imgfxArg3, 255, imgfxFlags);
            break;
        case IMGFX_OVERLAY:
            npc->renderMode = RENDER_MODE_ALPHATEST;
            set_npc_imgfx_all(npc->spriteInstanceID, IMGFX_OVERLAY, imgfxArg1, 255, 0, 255, imgfxFlags);
            break;
        case IMGFX_OVERLAY_XLU:
            npc->renderMode = RENDER_MODE_SURFACE_XLU_LAYER2;
            set_npc_imgfx_all(npc->spriteInstanceID, IMGFX_OVERLAY, imgfxArg1, imgfxArg2, 0, imgfxArg2, imgfxFlags);
            break;
    }
}

void npc_set_imgfx_params(Npc* npc, s32 imgfxType, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    npc->imgfxType = imgfxType;
    npc->imgfxArg1 = arg2;
    npc->imgfxArg2 = arg3;
    npc->imgfxArg3 = arg4;
    npc->imgfxArg4 = arg5;
    npc->imgfxFlags = arg6;
    npc_imgfx_update(npc);
}

//TODO begin split for npc_surfaces

void spawn_surface_effects(Npc* npc, SurfaceInteractMode mode) {
    PartnerStatus* temp = &gPartnerStatus;

    if (!(npc->flags & NPC_FLAG_INVISIBLE) && (npc->flags & NPC_FLAG_TOUCHES_GROUND)) {
        if (npc->moveSpeed != 0.0f) {
            s32 surfaceType = get_collider_flags((u16)npc->curFloor) & COLLIDER_FLAGS_SURFACE_TYPE_MASK;
            switch (surfaceType) {
                case SURFACE_TYPE_FLOWERS:
                    spawn_flower_surface_effects(npc, mode);
                    break;
                case SURFACE_TYPE_CLOUD:
                    spawn_cloud_surface_effects(npc, mode);
                    break;
                case SURFACE_TYPE_SNOW:
                    if ((temp->partnerActionState == PARTNER_ACTION_NONE) || (temp->actingPartner != PARTNER_LAKILESTER)) {
                        spawn_snow_surface_effects(npc, mode);
                    }
                    break;
                case SURFACE_TYPE_HEDGES:
                    spawn_hedge_surface_effects(npc, mode);
                    break;
                case SURFACE_TYPE_WATER:
                    spawn_water_surface_effects(npc, mode);
                    break;
                case SURFACE_TYPE_SPIKES:
                case SURFACE_TYPE_LAVA:
                case SURFACE_TYPE_DOCK_WALL:
                case SURFACE_TYPE_SLIDE:
                default:
                    spawn_default_surface_effects(npc, mode);
                    break;
            }
        }
    }
}

void spawn_default_surface_effects(Npc* npc, SurfaceInteractMode mode) {
    s32 mapIsStarWay;
    f32 sinTheta;
    f32 cosTheta;

    mapIsStarWay = FALSE;
    if (gGameStatusPtr->areaID == AREA_HOS) {
        mapIsStarWay = gGameStatusPtr->mapID == 2; //TODO hard-coded map ID
    }
    if (mode == SURFACE_INTERACT_LAND) {
        f32 x = npc->pos.x;
        f32 y = npc->pos.y + 0.0f;
        f32 z = npc->pos.z;

        if (!mapIsStarWay) {
            fx_landing_dust(0, x, y, z, D_80077C10);
            D_80077C10 = clamp_angle(D_80077C10 + 35.0f);
        } else {
            fx_misc_particles(3, x, y, z,  13.0f, 10.0f, 1.0f, 5, 30);
        }
    } else if (mode != SURFACE_INTERACT_WALK) {
        if (D_80077C14++ >= 4) {
            D_80077C14 = 0;
            if (!mapIsStarWay) {
                sin_cos_rad(DEG_TO_RAD(clamp_angle(-npc->yaw)), &sinTheta, &cosTheta);
                fx_walking_dust(0, npc->pos.x + (npc->collisionDiameter * sinTheta * 0.2f), npc->pos.y + 1.5f,
                               npc->pos.z + (npc->collisionDiameter * cosTheta * 0.2f), sinTheta, cosTheta);
            } else {
                sin_cos_rad(DEG_TO_RAD(clamp_angle(npc->yaw)), &sinTheta, &cosTheta);
                fx_misc_particles(3, npc->pos.x + (npc->collisionDiameter * sinTheta), npc->pos.y + 1.5f,
                              npc->pos.z + (npc->collisionDiameter * cosTheta), 5.0f, 10.0f, 1.0f, 5, 30);
            }
        }
    }
}

void spawn_flower_surface_effects(Npc* npc, SurfaceInteractMode mode) {
    f32 theta;
    f32 sinTheta;
    f32 cosTheta;
    f32 x, y, z;

    if (mode == SURFACE_INTERACT_LAND && D_80077C1E == 5) {
        x = npc->pos.x;
        y = npc->pos.y + + 14.0f;
        z = npc->pos.z;

        fx_flower_splash(x, y, z, D_80077C18);
        D_80077C18 = clamp_angle(D_80077C18 + 35.0f);
        D_80077C1E = 0;
        return;
    }

    D_80077C1E++;
    if (D_80077C1E > 5) {
        D_80077C1E = 5;
    }

    if (D_80077C1C++ > 0) {
        D_80077C1C = 0;
        theta = DEG_TO_RAD(clamp_angle(-npc->yaw));
        sinTheta = sin_rad(theta);
        cosTheta = cos_rad(theta);

        x = npc->pos.x + (npc->collisionDiameter * sinTheta * -0.4f);
        z = npc->pos.z + (npc->collisionDiameter * cosTheta * -0.4f);
        y = npc->pos.y + 15.5f;

        fx_flower_trail(1, x, y, z, -npc->yaw + rand_int(10) - 5.0f, D_80077C20);
        D_80077C20 = D_80077C20 == 0;
    }
}

void spawn_cloud_surface_effects(Npc* npc, SurfaceInteractMode mode) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 xTemp, yTemp, zTemp;
    f32 xTemp2, yTemp2, zTemp2;
    f32 theta;
    f32 sinTheta;
    f32 cosTheta;
    f32 angle;
    s32 i;

    D_80077C2C += 0.1f;
    if (mode == SURFACE_INTERACT_LAND) {
        fx_cloud_puff(npc->pos.x, (npc->pos.y + 14.0f) - 5.0f, npc->pos.z, D_80077C24);

        D_80077C24 = clamp_angle(D_80077C24 + 35.0f);

        for (i = 0; i < 4; i++) {
            xTemp = rand_int(10) - 5;
            zTemp = rand_int(10) - 5;
            yTemp = -2.0f - ((SQ(xTemp) + SQ(zTemp)) / 5.0f);
            D_80077C28 = 0;

            theta = DEG_TO_RAD(clamp_angle(-npc->yaw + (i * 90)));
            sinTheta = sin_rad(theta);
            cosTheta = cos_rad(theta);

            fx_cloud_trail(
                1,
                npc->pos.x + (npc->collisionDiameter * sinTheta * -0.3f) + xTemp,
                npc->pos.y + 15.5f + yTemp,
                npc->pos.z + (npc->collisionDiameter * cosTheta * -0.3f) + zTemp
            );
        }
    } else {
        xTemp2 = rand_int(10) - 5;
        zTemp2 = rand_int(10) - 5;
        yTemp2 = -2.0f - ((SQ(xTemp2) + SQ(zTemp2)) / 5.0f);

        D_80077C28 = 0;

        theta = DEG_TO_RAD(clamp_angle(-npc->yaw));
        sinTheta = sin_rad(theta);
        cosTheta = cos_rad(theta);
        fx_cloud_trail(
            1,
            npc->pos.x + (npc->collisionDiameter * sinTheta * -0.3f) + xTemp2,
            npc->pos.y + 15.5f + yTemp2,
            npc->pos.z + (npc->collisionDiameter * cosTheta * -0.3f) + zTemp2
        );
    }
}

void spawn_snow_surface_effects(Npc* npc, SurfaceInteractMode mode) {
    if (D_80077C30++ >= 4) {
        f32 temp_f20;
        f32 x;
        f32 z;

        D_80077C30 = 0;
        temp_f20 = DEG_TO_RAD(clamp_angle(-npc->yaw));
        x = sin_rad(temp_f20);
        z = cos_rad(temp_f20);
        fx_footprint(npc->pos.x + (npc->collisionDiameter * x * 0.2f), npc->pos.y + 1.5f,
                  npc->pos.z + (npc->collisionDiameter * z * 0.2f), -npc->yaw, D_80077C34);
        D_80077C34 = !D_80077C34;
    }
}

void spawn_hedge_surface_effects(Npc* npc, SurfaceInteractMode mode) {
    if (D_80077C38++ >= 4) {
        f32 theta;
        f32 sinTheta;
        f32 cosTheta;

        D_80077C38 = 0;
        theta = DEG_TO_RAD(clamp_angle(-npc->yaw));
        sinTheta = sin_rad(theta);
        cosTheta = cos_rad(theta);
        fx_falling_leaves(1, npc->pos.x + (npc->collisionDiameter * sinTheta * 0.2f),
                  40.0f, npc->pos.z + (npc->collisionDiameter * cosTheta * 0.2f));
    }
}

void spawn_water_surface_effects(Npc* npc, SurfaceInteractMode mode) {
    if (D_80077C3A++ >= 4) {
        f32 temp_f20;
        f32 x;
        f32 z;

        D_80077C3A = 0;
        temp_f20 = DEG_TO_RAD(clamp_angle(-npc->yaw));
        x = sin_rad(temp_f20);
        z = cos_rad(temp_f20);
        fx_rising_bubble(0, npc->pos.x + (npc->collisionDiameter * x * 0.2f), npc->pos.y + 0.0f,
                  npc->pos.z + (npc->collisionDiameter * z * 0.2f), 0.0f);
    }
}

//TODO end split for npc_surfaces
static const f32 padding[2] = { 0.0f, 0.0f }; // remove after splitting

void COPY_set_defeated(s32 mapID, s32 encounterID) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 encounterIdx = encounterID / 32;
    s32 encounterShift;
    s32 flag;

    flag = encounterID % 32;
    encounterShift = flag;
    flag = currentEncounter->defeatFlags[mapID][encounterIdx];
    currentEncounter->defeatFlags[mapID][encounterIdx] = flag | (1 << encounterShift);

    // TODO: The below should work but has regalloc issues:
    /*EncounterStatus *currentEncounter = &gCurrentEncounter;
    s32 encounterIdx = encounterID / 32;
    s32 encounterShift = encounterID % 32;

    currentEncounter->defeatFlags[mapID][encounterIdx] |= (1 << encounterShift);*/
}

void init_encounter_status(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(currentEncounter->encounterList); i++) {
        currentEncounter->encounterList[i] = 0;
    }

    currentEncounter->flags = ENCOUNTER_STATUS_FLAG_0;
    currentEncounter->numEncounters = 0;
    currentEncounter->firstStrikeType = FIRST_STRIKE_NONE;
    currentEncounter->hitType = 0;
    currentEncounter->battleTriggerCooldown = 0;
    currentEncounter->npcGroupList = 0;
    currentEncounter->unk_08 = 0;
    currentEncounter->dropWhackaBump = FALSE;

    for (i = 0; i < ARRAY_COUNT(currentEncounter->defeatFlags); i++) {
        for (j = 0; j < ARRAY_COUNT(currentEncounter->defeatFlags[i]); j++) {
            currentEncounter->defeatFlags[i][j] = 0;
        }
    }

    for (i = 0; i < ARRAY_COUNT(currentEncounter->recentMaps); i++) {
        currentEncounter->recentMaps[i] = -1;
    }

    func_80045AC0();
    gEncounterState = ENCOUNTER_STATE_NONE;
    create_worker_world(NULL, npc_render_worker_do_nothing);
}

void clear_encounter_status(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < ARRAY_COUNT(currentEncounter->encounterList); i++) {
        currentEncounter->encounterList[i] = 0;
    }

    if (gGameStatusPtr->didAreaChange) {
        for (i = 0; i < ARRAY_COUNT(currentEncounter->defeatFlags); i++) {
            for (j = 0; j < ARRAY_COUNT(currentEncounter->defeatFlags[i]); j++) {
                currentEncounter->defeatFlags[i][j] = 0;
            }
        }

        if (gGameStatusPtr->didAreaChange) {
            for (i = 0; i < ARRAY_COUNT(currentEncounter->recentMaps); i++) {
                currentEncounter->recentMaps[i] = -1;
            }
        }
    }

    currentEncounter->numEncounters = 0;
    currentEncounter->firstStrikeType = FIRST_STRIKE_NONE;
    currentEncounter->hitType = 0;
    currentEncounter->battleTriggerCooldown = 0;
    currentEncounter->curAreaIndex = gGameStatusPtr->areaID;
    currentEncounter->curMapIndex = gGameStatusPtr->mapID;
    currentEncounter->curEntryIndex = gGameStatusPtr->entryID;
    currentEncounter->npcGroupList = 0;
    currentEncounter->unk_08 = 0;
    currentEncounter->scriptedBattle = FALSE;

    func_80045AC0();
    gEncounterState = ENCOUNTER_STATE_NONE;
    create_worker_world(NULL, npc_render_worker_do_nothing);
}

void func_8003E50C(void) {
}

void func_8003E514(s8 arg0) {
    gCurrentEncounter.unk_08 = arg0;
}

void update_encounters(void) {
    switch (gEncounterState) {
        case ENCOUNTER_STATE_NONE:
            break;
        case ENCOUNTER_STATE_CREATE:
            create_encounters();
            break;
        case ENCOUNTER_STATE_NEUTRAL:
            update_encounters_neutral();
            break;
        case ENCOUNTER_STATE_PRE_BATTLE:
            update_encounters_pre_battle();
            break;
        case ENCOUNTER_STATE_CONVERSATION:
            update_encounters_conversation();
            break;
        case ENCOUNTER_STATE_POST_BATTLE:
            update_encounters_post_battle();
            break;
    }

    update_merlee_messages();
}

void draw_encounter_ui(void) {
    switch (gEncounterState) {
        case ENCOUNTER_STATE_NONE:
            break;
        case ENCOUNTER_STATE_CREATE:
            init_encounters_ui();
            break;
        case ENCOUNTER_STATE_NEUTRAL:
            draw_encounters_neutral();
            break;
        case ENCOUNTER_STATE_PRE_BATTLE:
            draw_encounters_pre_battle();
            break;
        case ENCOUNTER_STATE_CONVERSATION:
            draw_encounters_conversation();
            break;
        case ENCOUNTER_STATE_POST_BATTLE:
            draw_encounters_post_battle();
            break;
    }

    draw_merlee_messages();
}

void draw_first_strike_ui(void) {
    switch (gEncounterState) {
        case ENCOUNTER_STATE_NONE:
            break;
        case ENCOUNTER_STATE_PRE_BATTLE:
            show_first_strike_message();
            break;
    }
}

void npc_render_worker_do_nothing(void) {
}

void make_npcs(s32 flags, s32 mapID, s32* npcGroupList) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 i;
    s32 j;

    currentEncounter->resetMapEncounterFlags = flags;
    currentEncounter->mapID = mapID;
    currentEncounter->npcGroupList = npcGroupList;

    if (gGameStatusPtr->didAreaChange) {
        for (i = 0; i < ARRAY_COUNT(currentEncounter->defeatFlags); i++) {
            for (j = 0; j < ARRAY_COUNT(currentEncounter->defeatFlags[i]); j++) {
                currentEncounter->defeatFlags[i][j] = 0;
            }
        }

        if (gGameStatusPtr->didAreaChange) {
            for (i = 0; i < ARRAY_COUNT(currentEncounter->recentMaps); i++) {
                currentEncounter->recentMaps[i] = -1;
            }
        }
    }

    if (npcGroupList != NULL) {
        gEncounterState = ENCOUNTER_STATE_CREATE;
        D_8009A678 = 1;
        gEncounterSubState = ENCOUNTER_SUBSTATE_CREATE_INIT;
    }
}

s32 kill_encounter(Enemy* enemy) {
    Encounter* encounter = gCurrentEncounter.encounterList[enemy->encounterIndex];
    s32 i;

    for (i = 0; i < encounter->count; i++) {
        Enemy* currentEnemy = encounter->enemy[i];
        if (currentEnemy != NULL) {
            kill_enemy(currentEnemy);
            encounter->enemy[i] = NULL;
        }
    }
}

void kill_enemy(Enemy* enemy) {
    EncounterStatus* encounterStatus = &gCurrentEncounter;
    Encounter* encounter = encounterStatus->encounterList[enemy->encounterIndex];
    s32 i;
    s32 j;

    for (i = 0; i < encounter->count; i++) {
        Enemy* currentEnemy = encounter->enemy[i];
        if (currentEnemy == enemy) {
            break;
        }
    }

    if (enemy->initScript != NULL) {
        kill_script_by_ID(enemy->initScriptID);
    }
    if (enemy->interactScript != NULL) {
        kill_script_by_ID(enemy->interactScriptID);
    }
    if (enemy->aiScript != NULL) {
        kill_script_by_ID(enemy->aiScriptID);
    }
    if (enemy->hitScript != NULL) {
        kill_script_by_ID(enemy->hitScriptID);
    }
    if (enemy->auxScript != NULL) {
        kill_script_by_ID(enemy->auxScriptID);
    }
    if (enemy->defeatScript != NULL) {
        kill_script_by_ID(enemy->defeatScriptID);
    }

    enemy->interactBytecode = NULL;
    enemy->aiBytecode = NULL;
    enemy->hitBytecode = NULL;
    enemy->auxBytecode = NULL;
    enemy->defeatBytecode = NULL;

    free_npc(get_npc_unsafe(enemy->npcID));

    if (enemy->unk_64 != NULL) {
        heap_free(enemy->unk_64);
    }

    for (j = 0; j < ARRAY_COUNT(encounter->enemy); j++) {
        if (encounter->enemy[j] == enemy) {
            encounter->enemy[j] = NULL;
        }
    }

    do {
        if (!(enemy->flags & ENEMY_FLAG_4)
            && (!(enemy->flags & ENEMY_FLAG_ENABLE_HIT_SCRIPT) || (enemy == encounterStatus->curEnemy))
            && !(enemy->flags & ENEMY_FLAG_PASSIVE)
        ) {
            if (!(enemy->flags & ENEMY_FLAG_FLED)) {
                COPY_set_defeated(encounterStatus->mapID, encounter->encounterID + i);
            }
        }
    } while (0); // required to match

    heap_free(enemy);
}

s32 bind_enemy_ai(Enemy* enemy, EvtScript* aiScriptBytecode) {
    Evt* aiScript;
    s32 id;

    if (enemy->aiScript != NULL) {
        kill_script_by_ID(enemy->aiScript->id);
    }
    enemy->aiBytecode = aiScriptBytecode;
    aiScript = enemy->aiScript = start_script(aiScriptBytecode, EVT_PRIORITY_A, 0);
    id = enemy->aiScriptID = aiScript->id;
    aiScript->owner1.enemy = enemy;
    return id;
}

s32 bind_enemy_aux(Enemy* enemy, EvtScript* auxScriptBytecode) {
    Evt* auxScript;
    s32 id;

    if (enemy->auxScript != NULL) {
        kill_script_by_ID(enemy->auxScript->id);
    }
    enemy->auxBytecode = auxScriptBytecode;
    auxScript = enemy->auxScript = start_script(auxScriptBytecode, EVT_PRIORITY_A, 0);
    id = enemy->auxScriptID = auxScript->id;
    auxScript->owner1.enemy = enemy;
    return id;
}

s32 bind_enemy_interact(Enemy* enemy, EvtScript* interactScriptBytecode) {
    Evt* interactScript;
    s32 id;

    if (enemy->interactScript != NULL) {
        kill_script_by_ID(enemy->interactScript->id);
    }
    enemy->interactBytecode = interactScriptBytecode;
    interactScript = enemy->interactScript = start_script(interactScriptBytecode, EVT_PRIORITY_A, 0);
    id = enemy->interactScriptID = interactScript->id;
    interactScript->owner1.enemy = enemy;
    return id;
}

void bind_npc_ai(s32 npcID, EvtScript* npcAiBytecode) {
    EncounterStatus* currentEncounterStatus = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < currentEncounterStatus->numEncounters; i++) {
        Encounter* currentEncounter = currentEncounterStatus->encounterList[i];
        if (currentEncounter != NULL) {
            for (j = 0; j < currentEncounter->count; j++) {
                Enemy* currentEnemy = currentEncounter->enemy[j];
                if ((currentEnemy != NULL) && (currentEnemy->npcID == npcID)) {
                    bind_enemy_ai(currentEnemy, npcAiBytecode);
                    break;
                }
            }
        }
    }
}

void bind_npc_aux(s32 npcID, EvtScript* npcAuxBytecode) {
    EncounterStatus* currentEncounterStatus = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < currentEncounterStatus->numEncounters; i++) {
        Encounter* currentEncounter = currentEncounterStatus->encounterList[i];
        if (currentEncounter != NULL) {
            for (j = 0; j < currentEncounter->count; j++) {
                Enemy* currentEnemy = currentEncounter->enemy[j];
                if ((currentEnemy != NULL) && (currentEnemy->npcID == npcID)) {
                    bind_enemy_aux(currentEnemy, npcAuxBytecode);
                    break;
                }
            }
        }
    }
}

void bind_npc_interact(s32 npcID, EvtScript* npcInteractBytecode) {
    EncounterStatus* currentEncounterStatus = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < currentEncounterStatus->numEncounters; i++) {
        Encounter* currentEncounter = currentEncounterStatus->encounterList[i];
        if (currentEncounter != NULL) {
            for (j = 0; j < currentEncounter->count; j++) {
                Enemy* currentEnemy = currentEncounter->enemy[j];
                if ((currentEnemy != NULL) && (currentEnemy->npcID == npcID)) {
                    bind_enemy_interact(currentEnemy, npcInteractBytecode);
                    break;
                }
            }
        }
    }
}

Enemy* get_enemy(s32 npcID) {
    EncounterStatus* currentEncounterStatus = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < currentEncounterStatus->numEncounters; i++) {
        Encounter* currentEncounter = currentEncounterStatus->encounterList[i];
        if (currentEncounter != NULL) {
            for (j = 0; j < currentEncounter->count; j++) {
                Enemy* currentEnemy = currentEncounter->enemy[j];
                if ((currentEnemy != NULL) && (currentEnemy->npcID == npcID)) {
                    return currentEnemy;
                }
            }
        }
    }
    PANIC();
}

Enemy* get_enemy_safe(s32 npcID) {
    EncounterStatus* currentEncounterStatus = &gCurrentEncounter;
    s32 i;
    s32 j;

    for (i = 0; i < currentEncounterStatus->numEncounters; i++) {
        Encounter* currentEncounter = currentEncounterStatus->encounterList[i];

        if (currentEncounter != NULL) {
            for (j = 0; j < currentEncounter->count; j++) {
                Enemy* currentEnemy = currentEncounter->enemy[j];
                if ((currentEnemy != NULL) && (currentEnemy->npcID == npcID)) {
                    return currentEnemy;
                }
            }
        }
    }
    return NULL;
}
