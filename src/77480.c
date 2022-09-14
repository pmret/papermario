#include "common.h"
#include "ld_addrs.h"
#include "world/actions.h"
#include "sprite.h"

// TODO linker stuff
#define E20110_VRAM_DEF (void*)0x802B7000
#define E20EB0_VRAM_DEF (void*)0x802B7000
#define E21870_VRAM_DEF (void*)0x802B7000
#define E225B0_VRAM_DEF (void*)0x802B7000

extern f32 D_800F7B48;
extern s32 D_800F7B4C;
extern UNK_FUN_PTR(D_8010C93C);
extern s8 D_8015A57A;
extern s32 GoombarioGetTattleID;

s32 player_raycast_down(f32*, f32*, f32*, f32*);
s32 player_raycast_up_corner(f32* x, f32* y, f32* z, f32* length);
s32 player_raycast_general(s32, f32, f32, f32, f32, f32, f32, f32*, f32*, f32*, f32*, f32*, f32*, f32*);
void player_get_slip_vector(f32* outX, f32* outY, f32 x, f32 y, f32 nX, f32 nY);
void phys_update_standard(void);
void phys_update_lava_reset(void);
void update_player_blink(void);
void check_for_ispy(void);
void func_800E0330(void);
void check_for_pulse_stone(void);
void func_800E0374(void);
void func_800E04D0(void);
void func_800E0514(void);
void check_for_conversation_prompt(void);
void func_800E0658(void);
void func_800E069C(void);
void check_for_interactables(void);
void func_800E0AD0(void);
void func_800E0B14(void);
void update_partner_timers(void);
void func_800E0B90(void);
s32 get_player_back_anim(s32 arg0);
void appendGfx_player(void* data);
void appendGfx_player_spin(void* data);
void update_player_shadow(void);
s32 partner_use_ability(void);

s32 player_raycast_below(f32 yaw, f32 diameter, f32* outX, f32* outY, f32* outZ, f32* outLength, f32* hitRx, f32* hitRz,
                         f32* hitDirX, f32* hitDirZ) {
    f32 x, y, z, length;
    f32 inputX, inputY, inputZ, inputLength;
    f32 cosTheta;
    f32 sinTheta;
    f32 temp_f20;
    f32 cosTemp;
    f32 sinTemp;
    s32 hitObjectID;
    s32 ret;

    *hitRx = 0.0f;
    *hitRz = 0.0f;
    *hitDirX = 0.0f;
    *hitDirZ = 0.0f;
    inputLength = *outLength;
    temp_f20 = diameter * 0.28f;
    sin_cos_rad(DEG_TO_RAD(yaw), &sinTheta, &cosTheta);
    sinTemp = temp_f20 * sinTheta;
    cosTemp = -temp_f20 * cosTheta;
    inputX = *outX;
    inputY = *outY;
    inputZ = *outZ;

    x = inputX + sinTemp;
    y = inputY;
    z = inputZ + cosTemp;
    length = inputLength;
    hitObjectID = player_raycast_down(&x, &y, &z, &length);
    ret = -1;
    if (hitObjectID >= 0 && length <= fabsf(*outLength)) {
        *hitRx = -gGameStatusPtr->playerGroundTraceAngles.x;
        *hitRz = -gGameStatusPtr->playerGroundTraceAngles.z;
        *outX = x;
        *outY = y;
        *outZ = z;
        *outLength = length;
        *hitDirX = sinTemp;
        *hitDirZ = cosTemp;
        ret = hitObjectID;
    }

    x = inputX - sinTemp;
    y = inputY;
    z = inputZ - cosTemp;
    length = inputLength;
    hitObjectID = player_raycast_down(&x, &y, &z, &length);
    if (hitObjectID >= 0 && length <= fabsf(*outLength)) {
        *hitRx = -gGameStatusPtr->playerGroundTraceAngles.x;
        *hitRz = -gGameStatusPtr->playerGroundTraceAngles.z;
        *outX = x;
        *outY = y;
        *outZ = z;
        *outLength = length;
        *hitDirX = -sinTemp;
        *hitDirZ = -cosTemp;
        ret = hitObjectID;
    }

    x = inputX + cosTemp;
    y = inputY;
    z = inputZ + sinTemp;
    length = inputLength;
    hitObjectID = player_raycast_down(&x, &y, &z, &length);
    if (hitObjectID >= 0 && length <= fabsf(*outLength)) {
        *hitRx = -gGameStatusPtr->playerGroundTraceAngles.x;
        *hitRz = -gGameStatusPtr->playerGroundTraceAngles.z;
        *outX = x;
        *outY = y;
        *outZ = z;
        *outLength = length;
        *hitDirX = sinTemp;
        *hitDirZ = cosTemp;
        ret = hitObjectID;
    }

    x = inputX - cosTemp;
    y = inputY;
    z = inputZ - sinTemp;
    length = inputLength;
    hitObjectID = player_raycast_down(&x, &y, &z, &length);
    if (hitObjectID >= 0 && length <= fabsf(*outLength)) {
        *hitRx = -gGameStatusPtr->playerGroundTraceAngles.x;
        *hitRz = -gGameStatusPtr->playerGroundTraceAngles.z;
        *outX = x;
        *outY = y;
        *outZ = z;
        *outLength = length;
        *hitDirX = -sinTemp;
        *hitDirZ = -cosTemp;
        ret = hitObjectID;
    }

    x = inputX;
    y = inputY;
    z = inputZ;
    length = inputLength;
    hitObjectID = player_raycast_down(&x, &y, &z, &length);
    if (hitObjectID >= 0 && length <= fabsf(*outLength)) {
        *hitRx = -gGameStatusPtr->playerGroundTraceAngles.x;
        *hitRz = -gGameStatusPtr->playerGroundTraceAngles.z;
        *outX = x;
        *outY = y;
        *outZ = z;
        *outLength = length;
        *hitDirX = 0.0f;
        *hitDirZ = 0.0f;
        ret = hitObjectID;
    }

    if (ret < 0) {
        *outX = x;
        *outY = y;
        *outZ = z;
    }

    return ret;
}

s32 player_raycast_below_cam_relative(PlayerStatus* playerStatus, f32* outX, f32* outY, f32* outZ, f32* outLength,
                                      f32* hitRx, f32* hitRz, f32* hitDirX, f32* hitDirZ) {
    f32 yaw = 0.0f;

    if (playerStatus->spriteFacingAngle >= 90.0f && playerStatus->spriteFacingAngle < 270.0f) {
        yaw = 180.0f;
    }

    return player_raycast_below(yaw - 90.0f + gCameras[gCurrentCameraID].currentYaw, playerStatus->colliderDiameter,
                                outX, outY, outZ, outLength, hitRx, hitRz, hitDirX, hitDirZ);
}

s32 player_raycast_down(f32* x, f32* y, f32* z, f32* length) {
    f32 hitX;
    f32 hitY;
    f32 hitZ;
    f32 hitDepth;
    f32 hitNx;
    f32 hitNy;
    f32 hitNz;
    s32 entityID, colliderID;
    Entity* entity;
    s32 ret = -1;

    hitDepth = *length;
    entityID = test_ray_entities(*x, *y, *z, 0.0f, -1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth, &hitNx, &hitNy, &hitNz);
    if (entityID >= 0) {
        entity = get_entity_by_index(entityID);
        if (entity->alpha < 255) {
            entity->collisionTimer = 4;
            entity->flags |= ENTITY_FLAGS_CONTINUOUS_COLLISION;
        } else {
            ret = entityID | COLLISION_WITH_ENTITY_BIT;
        }
    }

    colliderID = test_ray_colliders(0x10000, *x, *y, *z, 0, -1.0f, 0, &hitX, &hitY, &hitZ, &hitDepth, &hitNx, &hitNy, &hitNz);
    if (colliderID >= 0) {
        ret = colliderID;
    }

    if (ret >= 0) {
        *length = hitDepth;
        *x = hitX;
        *y = hitY;
        *z = hitZ;
        gGameStatusPtr->playerGroundTraceNormal.x = hitNx;
        gGameStatusPtr->playerGroundTraceNormal.y = hitNy;
        gGameStatusPtr->playerGroundTraceNormal.z = hitNz;
        D_8010C938 = get_player_normal_yaw();
        D_8010C990 = get_player_normal_pitch();
        gGameStatusPtr->playerGroundTraceAngles.x = atan2(0.0f, 0.0f, hitNz * 100.0, hitNy * 100.0);
        gGameStatusPtr->playerGroundTraceAngles.y = 0.0f;
        gGameStatusPtr->playerGroundTraceAngles.z = atan2(0.0f, 0.0f, hitNx * 100.0, hitNy * 100.0);
    } else {
        gGameStatusPtr->playerGroundTraceAngles.x = 0.0f;
        gGameStatusPtr->playerGroundTraceAngles.y = 0.0f;
        gGameStatusPtr->playerGroundTraceAngles.z = 0.0f;
    }
    return ret;
}

s32 player_raycast_up_corners(PlayerStatus* player, f32* posX, f32* posY, f32* posZ, f32* hitDepth, f32 yaw) {
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
    f32 radius;

    radius = player->colliderDiameter * 0.3f;
    theta = DEG_TO_RAD(yaw);
    deltaX = radius * sin_rad(theta);
    deltaZ = -radius * cos_rad(theta);

    x = *posX;
    y = *posY;
    z = *posZ;

    depth = *hitDepth;
    startX = x + deltaX;
    startY = y;
    startZ = z + deltaZ;

    ret = -1;
    hitID = player_raycast_up_corner(&startX, &startY, &startZ, &depth);

    if (hitID < 0) {
        startX = x - deltaX;
        startY = y;
        startZ = z - deltaZ;
        hitID = player_raycast_up_corner(&startX, &startY, &startZ, &depth);
    }

    if (hitID < 0) {
        startX = x + deltaZ;
        startY = y;
        startZ = z + deltaX;
        hitID = player_raycast_up_corner(&startX, &startY, &startZ, &depth);
    }

    if (hitID < 0) {
        startX = x - deltaZ;
        startY = y;
        startZ = z - deltaX;
        hitID = player_raycast_up_corner(&startX, &startY, &startZ, &depth);
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

s32 player_raycast_up_corner(f32* x, f32* y, f32* z, f32* length) {
    f32 hitX;
    f32 hitY;
    f32 hitZ;
    f32 hitDepth;
    f32 hitNx;
    f32 hitNy;
    f32 hitNz;
    s32 hitID;
    Entity* entity;
    s32 ret;
    f32 sx, sy, sz;
    f32 sx2, sy2, sz2;
    f32 startX, startY, startZ;

    ret = -1;

     // needed to match
    sx2 = sx = *x;
    sy2 = sy = *y;
    sz2 = sz = *z;
    hitDepth = *length;
    hitID = test_ray_colliders(0x10000, sx, sy, sz, 0.0f, 1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth, &hitNx, &hitNy, &hitNz);
    if (hitID >= 0 && *length > hitDepth) {
        *length = hitDepth;
        ret = hitID;
        *x = sx = sx2;
        *y = sy = sy2;
        *z = sz = sz2;
    }

    hitDepth = 10.0f;
    hitID = test_ray_entities(*x, *y, *z, 0.0f, 1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth, &hitNx, &hitNy, &hitNz);
    sx = sx2;
    sy = sy2;
    sz = sz2;
    if (hitID >= 0 && *length > hitDepth) {
        get_entity_by_index(hitID);
        ret = hitID | COLLISION_WITH_ENTITY_BIT;
        *length = hitDepth;
        *x = sx;
        *y = sy;
        *z = sz;
    }

    return ret;
}

s32 player_test_lateral_overlap(s32 mode, PlayerStatus* playerStatus, f32* x, f32* y, f32* z, f32 length, f32 yaw) {
    f32 sinTheta;
    f32 cosTheta;
    f32 hitX;
    f32 hitY;
    f32 hitZ;
    f32 hitDepth;
    f32 hitNx;
    f32 hitNy;
    f32 hitNz;
    f32 slipDx;
    f32 slipDz;
    f32 depthDiff;
    f32 radius;
    f32 originalDepth;
    s32 hitID;
    f32 height;
    f32 targetDx;
    f32 targetDz;
    f32 dx;
    f32 dz;
    s32 ret;

    radius = playerStatus->colliderDiameter * 0.5f;
    ret = -1;

    if (!(playerStatus->flags & (PS_FLAGS_FALLING | PS_FLAGS_JUMPING))) {
        height = playerStatus->colliderHeight * 0.286f;
    } else {
        height = 1.0f;
    }

    sin_cos_rad(DEG_TO_RAD(yaw), &sinTheta, &cosTheta);
    cosTheta = -cosTheta;
    hitDepth = length + radius;
    hitID = player_raycast_general(mode, *x, *y + height, *z, sinTheta, 0, cosTheta, &hitX, &hitY, &hitZ, &hitDepth, &hitNx, &hitNy, &hitNz);

    if (mode == 3) {
        targetDx = 0.0f;
        targetDz = 0.0f;
    } else {
        targetDx = length * sinTheta;
        targetDz = length * cosTheta;
    }

    if (hitID >= 0) {
        originalDepth = length + radius;
        if (hitDepth <= originalDepth) {
            depthDiff = hitDepth - originalDepth;
            dx = depthDiff * sinTheta;
            dz = depthDiff * cosTheta;

            player_get_slip_vector(&slipDx, &slipDz, targetDx, targetDz, hitNx, hitNz);
            *x += dx + slipDx;
            *z += dz + slipDz;
            ret = hitID;
        }
    }

    *x += targetDx;
    *z += targetDz;
    return ret;
}

s32 player_raycast_general(s32 mode, f32 startX, f32 startY, f32 startZ, f32 dirX, f32 dirY, f32 dirZ, f32* hitX,
                            f32* hitY, f32* hitZ, f32* hitDepth, f32*hitNx, f32* hitNy, f32* hitNz) {
    f32 nAngleX;
    f32 nAngleZ;
    s32 entityID;
    s32 colliderID;
    Entity* entity;
    s32 ignoreFlags;
    s32 ret;

    entityID = test_ray_entities(startX, startY, startZ, dirX, dirY, dirZ, hitX, hitY, hitZ, hitDepth, hitNx, hitNy,
                                hitNz);
    ret = -1;
    if (entityID >= 0) {
        entity = get_entity_by_index(entityID);
        if (entity->alpha < 255) {
            entity->collisionTimer = 0;
            entity->flags |= ENTITY_FLAGS_CONTINUOUS_COLLISION;
        } else {
            ret = entityID | COLLISION_WITH_ENTITY_BIT;
        }
    } else if (mode == 3) {
        ret = test_ray_colliders(COLLIDER_FLAGS_IGNORE_SHELL, startX, startY, startZ, dirX, dirY, dirZ, hitX, hitY, hitZ, hitDepth,
                                 hitNx, hitNy, hitNz);
    }

    if (mode == 1 || mode == 3)
        return ret;

    ignoreFlags = COLLIDER_FLAGS_IGNORE_PLAYER;
    if (mode == 4) {
            ignoreFlags = 0x80000;
    }
    colliderID = test_ray_colliders(ignoreFlags, startX, startY, startZ, dirX, dirY, dirZ, hitX, hitY, hitZ, hitDepth,
                                    hitNx, hitNy, hitNz);

    if (ret < 0) {
        ret = colliderID;
    }

    if (ret >= 0) {
        nAngleZ = 180.0f - atan2(0, 0, *hitNz * 100.0, *hitNy * 100.0);
        nAngleX = 180.0f - atan2(0, 0, *hitNx * 100.0, *hitNy * 100.0);

        if (!(nAngleZ == 90.0f && nAngleX == 90.0f || fabs(nAngleZ) >= 30.0 || fabs(nAngleX) >= 30.0)) {
            ret = -1;
        }
    }

    return ret;
}

s32 player_test_move_without_slipping(PlayerStatus* playerStatus, f32* x, f32* y, f32* z, f32 length, f32 yaw, s32* arg6) {
    f32 sinTheta;
    f32 cosTheta;
    f32 hitX;
    f32 hitY;
    f32 hitZ;
    f32 hitDepth;
    f32 hitNx;
    f32 hitNy;
    f32 hitNz;
    f32 slipDx;
    f32 slipDz;
    f32 depth;
    f32 radius;
    f32 depthDiff;
    f32 height;
    s32 ret;
    s32 raycastID;
    f32 targetDx;
    f32 targetDz;
    f32 dx, dz;

    radius = playerStatus->colliderDiameter * 0.5f;
    height = playerStatus->colliderHeight * 0.286f;
    sin_cos_rad(DEG_TO_RAD(yaw), &sinTheta, &cosTheta);

    depth = length + radius;
    cosTheta = -cosTheta;
    hitDepth = depth;
    dx = radius * sinTheta;
    ret = -1;

    raycastID = player_raycast_general(0, *x, *y + 0.1, *z, sinTheta, 0, cosTheta, &hitX, &hitY, &hitZ, &hitDepth, &hitNx, &hitNy, &hitNz);
    if (raycastID >= 0 && hitDepth <= depth) {
        *arg6 = 1;
    }

    depth = length + radius;
    hitDepth = depth;
    dz = radius * cosTheta;

    raycastID = player_raycast_general(0, *x, *y + height, *z, sinTheta, 0, cosTheta, &hitX, &hitY, &hitZ, &hitDepth, &hitNx, &hitNy, &hitNz);

    targetDx = 0.0f;
    targetDz = 0.0f;

    if ((raycastID >= 0) && (hitDepth <= depth)) {
        depthDiff = hitDepth - depth;
        dx = depthDiff * sinTheta;
        dz = depthDiff * cosTheta;
        player_get_slip_vector(&slipDx, &slipDz, 0.0f, 0.0f, hitNx, hitNz);
        *x += dx + slipDx;
        *z += dz + slipDz;
        ret = raycastID;
    }
    *x += targetDx;
    *z += targetDz;
    return ret;
}

void player_get_slip_vector(f32* outX, f32* outY, f32 x, f32 y, f32 nX, f32 nY) {
    f32 projectionLength = (x * nX) + (y * nY);

    *outX = (x - projectionLength * nX) * 0.5f;
    *outY = (y - projectionLength * nY) * 0.5f;
}

s32 player_test_move_with_slipping(PlayerStatus* playerStatus, f32* x, f32* y, f32* z, f32 length, f32 yaw) {
    f32 sinTheta;
    f32 cosTheta;
    f32 hitX;
    f32 hitY;
    f32 hitZ;
    f32 hitDepth;
    f32 hitNx;
    f32 hitNy;
    f32 hitNz;
    f32 slipDx;
    f32 slipDz;
    f32 radius;
    f32 height;
    s32 hitID;
    f32 targetDx, targetDz;
    f32 dx, dz;
    f32 depthDiff;
    s32 ret = -1;

    height = 0.0f;
    if (!(playerStatus->flags & (PS_FLAGS_JUMPING | PS_FLAGS_FALLING))) {
        height = 10.01f;
    }
    radius = playerStatus->colliderDiameter * 0.5f;

    sin_cos_rad(DEG_TO_RAD(yaw), &sinTheta, &cosTheta);
    cosTheta = -cosTheta;
    hitDepth = length + radius;

    targetDx = length * sinTheta;
    targetDz = length * cosTheta;

    hitID = player_raycast_general(0, *x, *y + height, *z, sinTheta, 0, cosTheta, &hitX, &hitY, &hitZ, &hitDepth, &hitNx, &hitNy, &hitNz);
    if (hitID >= 0 && (depthDiff = hitDepth, depthDiff <= length + radius)) {
        depthDiff -= (length + radius);
        dx = depthDiff * sinTheta;
        dz = depthDiff * cosTheta;
        player_get_slip_vector(&slipDx, &slipDz, targetDx, targetDz, hitNx, hitNz);
        *x += dx + slipDx;
        *z += dz + slipDz;
        ret = hitID;
    } else {
        height = playerStatus->colliderHeight * 0.75;
        hitID = player_raycast_general(0, *x, *y + height, *z, sinTheta, 0, cosTheta, &hitX, &hitY, &hitZ, &hitDepth, &hitNx, &hitNy, &hitNz);
        if (hitID >= 0 && (depthDiff = hitDepth, depthDiff <= length + radius)) {
            depthDiff -= (length + radius);
            dx = depthDiff * sinTheta;
            dz = depthDiff * cosTheta;
            player_get_slip_vector(&slipDx, &slipDz, targetDx, targetDz, hitNx, hitNz);
            *x += dx + slipDx;
            *z += dz + slipDz;
            ret = hitID;
        }
    }

    *x += targetDx;
    *z += targetDz;
    return ret;
}

void update_player(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    GameStatus* gameStatus;

    update_partner_timers();

    if ((playerStatus->timeInAir > 100) || (playerStatus->position.y < -2000.0f)) {
        if (!(playerStatus->animFlags & PA_FLAGS_10000000)) {
            playerStatus->timeInAir = 0;
            playerStatus->position.x = playerStatus->lastGoodPosition.x;
            playerStatus->position.y = playerStatus->lastGoodPosition.y;
            playerStatus->position.z = playerStatus->lastGoodPosition.z;

            if (playerStatus->animFlags & PA_FLAGS_400000) {
                Npc* partner;

                playerStatus->animFlags |= PA_FLAGS_20000000 | PA_FLAGS_4;
                partner = get_npc_unsafe(NPC_PARTNER);
                partner->pos.x = playerStatus->lastGoodPosition.x;
                partner->pos.y = playerStatus->lastGoodPosition.y + playerStatus->colliderHeight;
                partner->pos.z = playerStatus->lastGoodPosition.z;
                partner->moveToPos.y = playerStatus->lastGoodPosition.y;
            } else {
                playerStatus->timeInAir = 10;
            }
        }
    }

    collisionStatus->currentWall = -1;
    collisionStatus->lastWallHammered = -1;
    collisionStatus->currentInspect = -1;
    collisionStatus->floorBelow = 1;

    update_player_input();
    playerStatus->flags &= ~PS_FLAGS_400;
    update_player_blink();

    if (playerStatus->flags & PA_FLAGS_USING_PEACH_PHYSICS) {
        phys_update_action_state();
        if (!func_800E0208()) {
            collision_main_lateral();
        }
    } else if (playerStatus->actionState != ACTION_STATE_HIT_LAVA) {
        phys_update_standard();
    } else {
        phys_update_lava_reset();
    }

    if (playerStatus->flags & PS_FLAGS_4000) {
        playerStatus->moveFrames--;
        if (playerStatus->moveFrames <= 0) {
            playerStatus->moveFrames = 0;
            playerStatus->flags &= ~PS_FLAGS_4000;
        }
    }

    if (!(playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS)) {
        func_800EFD08();
    }

    func_800E0B90();

    gameStatus = gGameStatusPtr;
    gameStatus->playerPos.x = playerStatus->position.x;
    gameStatus->playerPos.y = playerStatus->position.y;
    gameStatus->playerPos.z = playerStatus->position.z;
    gameStatus->playerYaw = playerStatus->currentYaw;

    check_input_open_menus();
    if (!(playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS)) {
        check_input_status_menu();
    }

    update_player_shadow();
    check_for_interactables();
    check_for_conversation_prompt();
    check_for_pulse_stone();
    check_for_ispy();

    playerStatus->extraVelocity.x = 0.0f;
    playerStatus->extraVelocity.y = 0.0f;
    playerStatus->extraVelocity.z = 0.0f;
    playerStatus->flags &= ~PS_FLAGS_10;
    playerStatus->animFlags &= ~PA_FLAGS_8;
}

void check_input_use_partner(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    u32 actionState = playerStatus->actionState;

    if (!(playerStatus->animFlags & PA_FLAGS_8BIT_MARIO)) {
        if (playerStatus->animFlags & PA_FLAGS_8 || playerStatus->inputEnabledCounter == 0) {
            if (playerStatus->pressedButtons & BUTTON_C_DOWN && !(playerStatus->flags & PS_FLAGS_80) &&
                !(playerStatus->pressedButtons & BUTTON_B) && !(playerStatus->animFlags & PS_FLAGS_1000) &&
                actionState <= ACTION_STATE_RUN) {

                if (playerData->currentPartner == PARTNER_GOOMBARIO) {
                    GoombarioGetTattleID = playerStatus->interactingWithID;
                }
                partner_use_ability();
            }
        }
    }
}

void phys_update_standard(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 flags;

    check_input_use_partner();
    phys_update_action_state();

    if (!(playerStatus->flags & PS_FLAGS_FLYING)) {
        if (playerStatus->flags & PS_FLAGS_JUMPING) {
            phys_update_jump();
        }
    }

    if (playerStatus->flags & PS_FLAGS_FALLING) {
        if (!(playerStatus->flags & PS_FLAGS_FLYING)) {
            phys_update_falling();
        }
    }

    check_input_midair_jump();

    if (playerStatus->actionState != ACTION_STATE_SLIDING) {
        collision_main_lateral();
        collision_check_player_overlaps();

        if (collision_main_above() < 0 && playerStatus->timeInAir == 0 &&
            playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS) {
            func_800E4F10();
        }

        if ((playerStatus->actionState != ACTION_STATE_ENEMY_FIRST_STRIKE)
            && (playerStatus->actionState != ACTION_STATE_STEP_UP)) {
            phys_main_collision_below();
        }
    }

    if (playerStatus->animFlags & PA_FLAGS_2) {
        world_watt_sync_held_position();
    }

    if (!(playerStatus->flags & PS_FLAGS_CAMERA_DOESNT_FOLLOW)) {
        gCameras[CAM_DEFAULT].targetPos.x = playerStatus->position.x;
        gCameras[CAM_DEFAULT].targetPos.y = playerStatus->position.y;
        gCameras[CAM_DEFAULT].targetPos.z = playerStatus->position.z;
    }
}

void phys_update_lava_reset(void) {
    phys_update_action_state();
    collision_main_lateral();
    collision_lava_reset_check_additional_overlaps();

    if (!(gPlayerStatusPtr->flags & PS_FLAGS_CAMERA_DOESNT_FOLLOW)) {
        Camera* camera = &gCameras[CAM_DEFAULT];

        camera->targetPos.x = gPlayerStatusPtr->position.x;
        camera->targetPos.y = gPlayerStatusPtr->position.y;
        camera->targetPos.z = gPlayerStatusPtr->position.z;
    }
}

void clear_player_status(void) {
    mem_clear(&gPlayerStatus, sizeof(gPlayerStatus));
}

void player_reset_data(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    mem_clear(playerStatus, sizeof(PlayerStatus));
    playerStatus->flags = 1;
    reset_player_status();
    playerStatus->shadowID = create_shadow_type(0, playerStatus->position.x, playerStatus->position.y,
                             playerStatus->position.z);
    func_800E6B68();
    func_800E0B14();
    func_800E069C();
    func_800E0514();
    func_800E0374();
    func_800E5520();
}

s32 func_800DFCF4(void) {
    if (gPartnerActionStatus.partnerActionState == PARTNER_ACTION_USE &&
        (gPartnerActionStatus.actingPartner == PARTNER_WATT
        || gPartnerActionStatus.actingPartner == PARTNER_BOW
        || gPartnerActionStatus.actingPartner == PARTNER_SUSHIE
        || gPartnerActionStatus.actingPartner == PARTNER_PARAKARRY
        || gPartnerActionStatus.actingPartner == PARTNER_LAKILESTER)) {
        return FALSE;
    }
    return TRUE;
}

s32 get_overriding_player_anim(s32 anim) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerActionStatus* partnerActionStatus = &gPartnerActionStatus;

    if (playerStatus->actionState == ACTION_STATE_USE_SPINNING_FLOWER && anim != ANIM_Mario_1002B && anim != ANIM_Mario_AnimMidairStill) {
        return -1;
    }

    if (partnerActionStatus->partnerActionState != PARTNER_ACTION_NONE) {
        if (partnerActionStatus->actingPartner == PARTNER_LAKILESTER && anim == ANIM_Mario_10002) {
            anim = ANIM_Mario_8000E;
        }

        if (partnerActionStatus->partnerActionState != PARTNER_ACTION_NONE && partnerActionStatus->actingPartner == PARTNER_BOW) {
            if (anim != ANIM_Mario_Crouch && anim != ANIM_Mario_10002) {
                    return -1;
            }
        }
    }

    if (anim == ANIM_Mario_ThumbsUp && partnerActionStatus->partnerActionState == PARTNER_ACTION_USE) {
        return -1;
    }

    if (anim == ANIM_Mario_6000C || anim == ANIM_Peach_C0010 || anim == ANIM_Mario_10002) {
        if (!(playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS)) {
            if (!func_800DFCF4()) {
                return -1;
            }
        } else if (!(playerStatus->animFlags & PA_FLAGS_IN_DISGUISE)) {
            anim = ANIM_Peach_C0010;
        } else {
            peach_set_disguise_anim(BasicPeachDisguiseAnims[playerStatus->peachDisguise].hold);
            return -1;
        }
    } else if (playerStatus->animFlags & PA_FLAGS_USING_PEACH_PHYSICS) {
        if ((playerStatus->peachItemHeld != 0)
        && (anim == ANIM_Peach_C0000 || anim == ANIM_Peach_C0001 || anim == ANIM_Peach_C0002)) {
            anim = ANIM_Peach_D0000;
        }
    }

    if (anim == ANIM_Mario_80003) {
        exec_ShakeCam1(0, 0, 2);
    }

    return anim;
}

void suggest_player_anim_clearUnkFlag(AnimID anim) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    AnimID newAnim = get_overriding_player_anim(anim);

    if (newAnim != -1) {
        playerStatus->anim = newAnim;
        playerStatus->animNotifyValue = 0;
        playerStatus->flags &= ~PS_FLAGS_10000000;
    }
}

void force_player_anim(AnimID anim) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->anim = anim;
    playerStatus->animNotifyValue = 0;
    playerStatus->flags &= ~PS_FLAGS_10000000;
}

void suggest_player_anim_setUnkFlag(AnimID anim) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    AnimID newAnim = get_overriding_player_anim(anim);

    if (newAnim != -1) {
        playerStatus->anim = newAnim;
        playerStatus->animNotifyValue = 0;
        playerStatus->flags |= PS_FLAGS_10000000;
    }
}

void update_player_blink(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 outtaSight = FALSE;
    u8 phi_v1;
    u8* alpha;

    if (gPartnerActionStatus.actingPartner == PARTNER_BOW) {
        outtaSight = gPartnerActionStatus.partnerActionState != PARTNER_ACTION_NONE;
    }

    if (playerStatus->blinkTimer > 0) {
        playerStatus->blinkTimer--;
        alpha = &playerStatus->alpha1;
        if (!(gGameStatusPtr->frameCounter & 1)) {
            if (outtaSight) {
                phi_v1 = 192;
            } else {
                phi_v1 = 255;
            }
        } else {
            phi_v1 = 96;
        }
        *alpha = phi_v1;

        if (!playerStatus->blinkTimer) {
            if (outtaSight) {
                playerStatus->alpha1 = 128;
                playerStatus->flags |= PS_FLAGS_8000;
            } else {
                playerStatus->alpha1 = 255;
                playerStatus->flags &= ~PS_FLAGS_8000;
            }
        } else {
            playerStatus->flags |= PS_FLAGS_8000;
        }
    }
}

// dist_to_player2D
f32 get_xz_dist_to_player(f32 x, f32 z) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    return dist2D(x, z, playerStatus->position.x, playerStatus->position.z);
}

void enable_player_shadow(void) {
    get_shadow_by_index(gPlayerStatus.shadowID)->flags &= ~ENTITY_FLAGS_HIDDEN;
}

void disable_player_shadow(void) {
    get_shadow_by_index(gPlayerStatus.shadowID)->flags |= ENTITY_FLAGS_HIDDEN;
}

s32 disable_player_static_collisions(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->flags |= PS_FLAGS_1000;
    playerStatus->enableCollisionOverlapsCheck++;
    return playerStatus->enableCollisionOverlapsCheck;
}

s32 enable_player_static_collisions(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->enableCollisionOverlapsCheck--;
    if (playerStatus->enableCollisionOverlapsCheck == 0) {
        playerStatus->flags &= ~PS_FLAGS_1000;
    }
    return playerStatus->enableCollisionOverlapsCheck;
}

s32 disable_player_input(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->flags |= PS_FLAGS_INPUT_DISABLED;
    playerStatus->inputEnabledCounter++;
    return playerStatus->inputEnabledCounter;
}

s32 enable_player_input(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->inputEnabledCounter--;
    if (playerStatus->inputEnabledCounter == 0) {
        playerStatus->flags &= ~PS_FLAGS_INPUT_DISABLED;
    }
    return playerStatus->inputEnabledCounter;
}

void func_800E01DC(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->animFlags & PA_FLAGS_INTERACT_PROMPT_AVAILABLE) {
        playerStatus->flags |= PS_FLAGS_8000000;
    }
}

s32 func_800E0208(void) {
    s32 ret = FALSE;

    if (gGameStatusPtr->disableScripts && (gGameStatusPtr->currentButtons[0] & BUTTON_R)) {
        if (gPartnerActionStatus.partnerActionState == PARTNER_ACTION_NONE) {
            set_action_state(ACTION_STATE_IDLE);
        }
        ret = TRUE;
    }
    return ret;
}

void player_render_interact_prompts(void) {
    func_800E0658();
    func_800E0AD0();
    func_800E04D0();
    func_800E0330();
}

void check_for_ispy(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (D_8015A57A != 0 && D_8010C93C == NULL) {
        if (!(playerStatus->animFlags &
            (PA_FLAGS_SPEECH_PROMPT_AVAILABLE | PA_FLAGS_INTERACT_PROMPT_AVAILABLE))) {
            dma_copy(E225B0_ROM_START, E225B0_ROM_END, E225B0_VRAM_DEF);
            D_8010C93C = func_802B72C0_E22870;
        }
    }

    if (D_8010C93C != NULL) {
        D_8010C93C();
    }
}

void func_800E0330(void) {
    if ((gPlayerStatusPtr->animFlags & PA_FLAGS_100) && (D_8010C93C != NULL)) {
        func_802B7000_E225B0();
    }
}

void func_800E0374(void) {
    D_8010C93C = NULL;
    gPlayerStatusPtr->animFlags &= ~PA_FLAGS_100;
}

void check_for_pulse_stone(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 dx, dy;

    if (D_8010C920 == NULL) {
        if (gPlayerStatus.animFlags & PA_FLAGS_100) {
            return;
        }

        if (gGameStatusPtr->areaID != AREA_SBK || gGameStatusPtr->isBattle) {
            return;
        }

        dx = abs(gGameStatusPtr->mapID % 7 - 2);
        dy = gGameStatusPtr->mapID / 7;
        if ((dx + dy) > 5) {
            return;
        }

        if (!(gPlayerStatus.animFlags & (PA_FLAGS_USING_PULSE_STONE | PA_FLAGS_40))) {
            return;
        }

        if (gPlayerStatus.flags & PS_FLAGS_20 || gPlayerStatus.inputEnabledCounter) {
            return;
        }

        if (!(gPlayerStatus.animFlags & (PA_FLAGS_SPEECH_PROMPT_AVAILABLE | PA_FLAGS_INTERACT_PROMPT_AVAILABLE))) {
            dma_copy(E21870_ROM_START, E21870_ROM_END, E21870_VRAM_DEF);
            D_8010C920 = func_802B7140;
        }
    }

    if (D_8010C920 != NULL) {
        D_8010C920();
    }
}

void func_800E04D0(void) {
    if ((gPlayerStatusPtr->animFlags & PA_FLAGS_40) && (D_8010C920 != 0)) {
        func_802B71D4();
    }
}

void func_800E0514(void) {
    D_8010C920 = 0;
    gPlayerStatusPtr->animFlags &= ~PA_FLAGS_40;
}

s32 has_valid_conversation_npc(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = playerStatus->encounteredNPC;
    s32 ret = FALSE;
    s32 cond;

    if (npc != NULL && !(npc->flags & 0x10000000)) {
        cond = (playerStatus->flags & (PS_FLAGS_HAS_CONVERSATION_NPC | PS_FLAGS_INPUT_DISABLED))
        == PS_FLAGS_HAS_CONVERSATION_NPC;
        ret = cond;
    }
    return ret;
}

void check_for_conversation_prompt(void) {
    if (gPlayerStatus.animFlags & PA_FLAGS_100 || D_8010C958 || D_8010C920) {
        return;
    }

    if (D_8010C940 == NULL) {
        if (gPlayerStatus.inputEnabledCounter || gPlayerStatus.flags & PS_FLAGS_20) {
            return;
        }

        if (has_valid_conversation_npc()) {
            D_8010C940 = NULL;
            dma_copy(E20EB0_ROM_START, E20EB0_ROM_END, E20EB0_VRAM_DEF);
            D_8010C940 = func_802B70B4_E201C4;
        } else {
            D_8010C940 = NULL;
            return;
        }
    }

    if (D_8010C940 != NULL) {
        D_8010C940();
    }
}

void func_800E0658(void) {
    if ((gPlayerStatusPtr->animFlags & PA_FLAGS_SPEECH_PROMPT_AVAILABLE) && (D_8010C940 != 0)) {
        func_802B71C8();
    }
}

void func_800E069C(void) {
    D_8010C940 = 0;
    gPlayerStatusPtr->animFlags &= ~PA_FLAGS_SPEECH_PROMPT_AVAILABLE;
}

void func_800E06C0(s32 arg0) {
    D_8010C950 = (arg0 == 1);
}

s32 func_800E06D8(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = playerStatus->encounteredNPC;
    s32 temp = playerStatus->interactingWithID;
    s32 wall;

    if (playerStatus->timeInAir || playerStatus->inputEnabledCounter) {
            return FALSE;
    }
    if (gCollisionStatus.currentWall == -1) {
        return FALSE;
    }
    if (playerStatus->flags & PS_FLAGS_HAS_CONVERSATION_NPC && !(playerStatus->flags & PS_FLAGS_INPUT_DISABLED)
        && npc != NULL && npc->flags & NPC_FLAG_10000000) {
        playerStatus->interactingWithID = -1;
        return TRUE;
    }

    wall = gCollisionStatus.currentWall;
    if (!(wall & COLLISION_WITH_ENTITY_BIT)) {
        if (!should_collider_allow_interact(wall)) {
            return FALSE;
        }
    } else if (!phys_can_player_interact()) {
        playerStatus->interactingWithID = -1;
        return FALSE;
    } else if (get_entity_type(wall) == 0xC) {
        return FALSE;
    }

    if (temp == wall) {
        if (playerStatus->flags & PS_FLAGS_8000000) {
            return FALSE;
        }
    } else {
        playerStatus->flags &= ~PS_FLAGS_8000000;
    }
    playerStatus->interactingWithID = -1;

    return TRUE;
}

static const f32 padding = 0.0f;

void check_for_interactables(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = gPlayerStatus.encounteredNPC;
    s32 phi_s2;

    if ((playerStatus->animFlags & PA_FLAGS_100) || D_8010C940 || D_8010C920) {
        return;
    }

    if (D_8010C958 == NULL) {
        s32 curInteraction = gCollisionStatus.currentWall;

        if (playerStatus->inputEnabledCounter != 0) {
            if (gPlayerStatus.interactingWithID != curInteraction) {
                gPlayerStatus.interactingWithID = curInteraction;
            }
            return;
        }

        if (playerStatus->timeInAir != 0) {
            return;
        }

        if (curInteraction == -1) {
            s32 floor = gCollisionStatus.currentFloor;

            if ((floor >= 0) && (floor & COLLISION_WITH_ENTITY_BIT)) {
                phi_s2 = 1;
                curInteraction = floor;
                switch (get_entity_type(floor)) {
                    case ENTITY_TYPE_PADLOCK:
                    case ENTITY_TYPE_PADLOCK_RED_FRAME:
                    case ENTITY_TYPE_PADLOCK_RED_FACE:
                    case ENTITY_TYPE_PADLOCK_BLUE_FACE:
                    case ENTITY_TYPE_PUSH_BLOCK:
                    case ENTITY_TYPE_CHEST:
                    case ENTITY_TYPE_SIGNPOST:
                        curInteraction = -1;
                        break;
                }
            } else if (((playerStatus->flags & (PS_FLAGS_HAS_CONVERSATION_NPC | PS_FLAGS_INPUT_DISABLED)) == PS_FLAGS_HAS_CONVERSATION_NPC)
                         && (npc != NULL) && (npc->flags & NPC_FLAG_10000000)) {
                curInteraction = npc->npcID | COLLISION_WITH_NPC_BIT;
                if (playerStatus->interactingWithID == curInteraction) {
                    return;
                }
                phi_s2 = 0;
            } else {
                playerStatus->interactingWithID = -1;
                playerStatus->flags &= ~PS_FLAGS_8000000;
                return;
            }
        } else {
            if (!(curInteraction & COLLISION_WITH_ENTITY_BIT)) {
                phi_s2 = 0;
                if (!(curInteraction & COLLISION_WITH_NPC_BIT)) {
                    if (!should_collider_allow_interact(curInteraction)) {
                        playerStatus->interactingWithID = -1;
                        playerStatus->flags &= ~PS_FLAGS_8000000;
                        return;
                    }
                }
            } else {
                if (!phys_can_player_interact()) {
                    phi_s2 = 1;
                    playerStatus->interactingWithID = -1;
                    playerStatus->flags &= ~PS_FLAGS_8000000;
                    return;
                }
                phi_s2 = 1;
            }
        }
        if (playerStatus->interactingWithID == curInteraction) {
            if ((playerStatus->flags & PS_FLAGS_8000000)) {
                return;
            }
        } else {
            playerStatus->flags &= ~PS_FLAGS_8000000;
        }

        playerStatus->interactingWithID = curInteraction;
        if ((phi_s2 == 0) || curInteraction >= 0 && get_entity_by_index(curInteraction)->flags & ENTITY_FLAGS_SHOWS_INSPECT_PROMPT) {
            if (playerStatus->actionState == ACTION_STATE_IDLE || playerStatus->actionState == ACTION_STATE_WALK || playerStatus->actionState == ACTION_STATE_RUN) {
                playerStatus->animFlags |= PA_FLAGS_INTERACT_PROMPT_AVAILABLE;
                func_800EF3D4(2);
            }
        }
    }

    if (!(playerStatus->animFlags & PA_FLAGS_INTERACT_PROMPT_AVAILABLE)) {
        func_800EF3D4(0);
        repartner_set_tether_distance();
        return;
    }

    if (D_8010C958 == NULL) {
        dma_copy(E20110_ROM_START, E20110_ROM_END, E20110_VRAM_DEF);
        D_8010C958 = func_802B70B4_E201C4;

    }

    if (D_8010C958 != NULL) {
        D_8010C958();
    }
}

void func_802B71E8_E202F8(void);

void func_800E0AD0(void) {
    if ((gPlayerStatusPtr->animFlags & PS_FLAGS_10) && (D_8010C958 != 0)) {
        func_802B71E8_E202F8();
    }
}

void func_800E0B14(void) {
    D_8010C958 = 0;
    gPlayerStatusPtr->animFlags &= ~PS_FLAGS_10;
}

void update_partner_timers(void) {
    PlayerData* playerData = &gPlayerData;

    if (!gGameStatusPtr->isBattle) {
        s32 i;

        for (i = 1; i < ARRAY_COUNT(playerData->partnerUnlockedTime); i++) {
            if (playerData->partners[i].enabled) {
                playerData->partnerUnlockedTime[i]++;
            }
        }
    }
}

void func_800E0B90(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 cameraYaw = gCameras[gCurrentCameraID].currentYaw;
    f32 camRelativeYaw = get_clamped_angle_diff(cameraYaw, playerStatus->currentYaw);
    s32 trueAnim;
    s32 sprIndex;
    f32 angle;
    s32 direction;
    f32 timescale;

    D_800F7B48 = 0.0f;
    if (camRelativeYaw < -5.0f && camRelativeYaw > -175.0f) {
        camRelativeYaw = 0.0f;
        direction = 0;
    } else if (camRelativeYaw > 5.0f && camRelativeYaw < 175.0f) {
        camRelativeYaw = 180.0f;
        direction = 1;
    } else {
        // direction is close to flipping, use saved value
        camRelativeYaw = PrevPlayerCamRelativeYaw;
        direction = 2;
    }
    // detect direction change
    if (PrevPlayerDirection != direction && direction != 2) {
        PrevPlayerDirection = direction;
        playerStatus->flipYaw[gCurrentCameraID] = (direction != 0) ? 180.0f : -180.0f;

        if (fabsf(get_clamped_angle_diff(cameraYaw, playerStatus->currentYaw)) >= 90.0f) {
            playerStatus->flipYaw[gCurrentCameraID] = -playerStatus->flipYaw[gCurrentCameraID];
        }
    }
    // handle sprite 'flipping' when changing direction
    angle = playerStatus->flipYaw[gCurrentCameraID];
    if (angle != 0.0f) {
        if (angle < 0.0f) {
            angle += 28.0f;
            if (angle > 0.0f) {
                angle = 0.0f;
            }
        }
        if (angle > 0.0f) {
            angle -= 28.0f;
            if (angle < 0.0f) {
                angle = 0.0f;
            }
        }
    }

    if (playerStatus->flags & PS_FLAGS_200000) {
        angle = 0.0f;
    }

    playerStatus->flipYaw[gCurrentCameraID] = angle;

    PrevPlayerCamRelativeYaw = angle = clamp_angle(camRelativeYaw);
    angle = clamp_angle(playerStatus->flipYaw[gCurrentCameraID] + angle);
    if (playerStatus->currentSpeed == 0.0f) {
        D_800F7B48 = 0.0f;
    }

    trueAnim = playerStatus->anim;
    if (playerStatus->flags & PS_FLAGS_20000) {
        playerStatus->trueAnimation = trueAnim;
    } else {
        sprIndex = (trueAnim >> 0x10) & 0xFF;

        if (playerStatus->actionState != ACTION_STATE_TORNADO_JUMP && !(playerStatus->flags & PS_FLAGS_100000)) {
            playerStatus->spriteFacingAngle = angle + D_800F7B48;
            trueAnim = playerStatus->anim;
            if (!(playerStatus->flags & PS_FLAGS_10000000) &&
                (sprIndex == SPR_Mario_1 || sprIndex == SPR_Mario_6 || sprIndex == SPR_Peach_A) &&
                fabsf(get_clamped_angle_diff(cameraYaw, playerStatus->currentYaw)) < 60.0f)
            {
                trueAnim = get_player_back_anim(trueAnim);
            }
            playerStatus->trueAnimation = trueAnim;
            playerStatus->currentYaw = playerStatus->targetYaw;
        } else {
            trueAnim = playerStatus->anim;
            if (!(playerStatus->flags & PS_FLAGS_10000000) &&
                (sprIndex == SPR_Mario_1 || sprIndex == SPR_Mario_6 || sprIndex == SPR_Peach_A) &&
                playerStatus->spriteFacingAngle < 350.0f && playerStatus->spriteFacingAngle > 190.0f)
            {
                trueAnim = get_player_back_anim(trueAnim);
            }
            playerStatus->trueAnimation = trueAnim;
        }
    }

    timescale = 1.0f;
    if (playerStatus->flags & PS_FLAGS_40000) {
        timescale = 0.5f;
    }
    if (playerStatus->flags & PS_FLAGS_20000000) {
        timescale = 0.0f;
    }
    playerStatus->animNotifyValue = spr_update_player_sprite(0, playerStatus->trueAnimation, timescale);
    playerStatus->flags |= PS_FLAGS_40000000;
}

s32 get_player_back_anim(s32 anim) {
    s32 sprIndex = (anim >> 16) & 0xff;
    s32 outAnim = 0;

    if (sprIndex != SPR_Mario_1) {
        if (sprIndex != SPR_Mario_6 && sprIndex != SPR_Peach_A) {
            return anim;
        }

        if (sprIndex == SPR_Mario_1) {
            if (anim > ANIM_Mario_1000C) {
                return anim;
            }
        } else if (sprIndex == SPR_Mario_6) {
            if (anim == ANIM_Mario_6000C) {
                outAnim = ANIM_Mario_6000D;
            } else if (anim == ANIM_Mario_6000E) {
                outAnim = ANIM_Mario_6000F;
            } else if (anim == ANIM_Mario_60010) {
                outAnim = ANIM_Mario_60011;
            } else if (anim == ANIM_Mario_60012) {
                outAnim = ANIM_Mario_60013;
            } else if (anim == ANIM_Mario_60014) {
                outAnim = ANIM_Mario_60015;
            } else if (anim == ANIM_Mario_60016) {
                outAnim = ANIM_Mario_60017;
            } else if (anim == ANIM_Mario_60018) {
                outAnim = ANIM_Mario_60019;
            } else if (anim == ANIM_Mario_6001A) {
                outAnim = ANIM_Mario_6001B;
            }
        } else if (sprIndex == SPR_Peach_A) {
            if (anim > ANIM_Peach_A0006) {
                outAnim = anim + 1;
            }
        }
    } else if (anim > ANIM_Mario_1000C) {
        return anim;
    }

    if (outAnim != 0) {
        return outAnim;
    } else {
        return anim | SPRITE_ID_BACK_FACING;
    }
}

void render_player(void) {
    if (!gGameStatusPtr->disableScripts) {
        render_player_model();
    }
}

void render_player_model(void) {
    RenderTask task;
    RenderTask* rtPtr = &task;
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 x, y, z;
    s8 renderModeTemp;
    void (*appendGfx)(void*);

    if (playerStatus->flags & PS_FLAGS_40000000) {
        playerStatus->flags &= ~PS_FLAGS_40000000;
        get_screen_coords(gCurrentCamID, playerStatus->position.x, playerStatus->position.y,
                          playerStatus->position.z, &x, &y, &z);
        if (!(playerStatus->flags & PS_FLAGS_20000)) {
            if (playerStatus->alpha1 != playerStatus->alpha2) {
                if (playerStatus->alpha1 < 254) {
                    if (!(playerStatus->animFlags & PA_FLAGS_1000000)) {
                        renderModeTemp = RENDER_MODE_SURFACE_XLU_LAYER1;
                    } else {
                        renderModeTemp = RENDER_MODE_SURFACE_XLU_LAYER2;
                    }

                    playerStatus->renderMode = renderModeTemp;
                    func_802DDEE4(0, -1, 7, 0, 0, 0, playerStatus->alpha1, 0);

                } else {
                    playerStatus->renderMode = RENDER_MODE_ALPHATEST;
                    func_802DDEE4(0, -1, 0, 0, 0, 0, 0, 0);
                }
            }

            playerStatus->alpha2 = playerStatus->alpha1;

        } else {
            playerStatus->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
            playerStatus->alpha2 = 0;
        }

        if (!(playerStatus->animFlags & PA_FLAGS_IN_DISGUISE)) {
            rtPtr->appendGfxArg = playerStatus;
            rtPtr->distance = -z;
            rtPtr->renderMode = playerStatus->renderMode;


            if (!(playerStatus->flags & PA_FLAGS_20000)) {
                appendGfx = appendGfx_player;
            } else {
                appendGfx = appendGfx_player_spin;
            }

            rtPtr->appendGfx = appendGfx;
            queue_render_task(rtPtr);
        }

        func_800F0C9C();
    }
}

void appendGfx_player(void* data) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Matrix4f sp20, sp60, spA0, spE0;
    f32 temp_f0 = -gCameras[gCurrentCamID].currentYaw;
    s32 flags;

    if (playerStatus->actionState == ACTION_STATE_SLIDING) {
        guScaleF(spE0, SPRITE_WORLD_SCALE_D, SPRITE_WORLD_SCALE_D, SPRITE_WORLD_SCALE_D);
        guRotateF(sp20, temp_f0, 0.0f, 1.0f, 0.0f);
        guMtxCatF(spE0, sp20, sp20);
        guRotateF(spA0, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp20, spA0, sp20);
        guTranslateF(sp60, playerStatus->position.x, playerStatus->position.y - 1.0f, playerStatus->position.z);
        guMtxCatF(sp20, sp60, sp20);
        spr_draw_player_sprite(0, 0, 0, 0, sp20);
    } else {
        guRotateF(spA0, temp_f0, 0.0f, -1.0f, 0.0f);
        guRotateF(sp20, clamp_angle(playerStatus->pitch), 0.0f, 0.0f, 1.0f);
        guMtxCatF(spA0, sp20, sp20);
        guTranslateF(sp60, 0.0f, -playerStatus->colliderHeight * 0.5f, 0.0f);
        guMtxCatF(sp60, sp20, sp20);
        guRotateF(spA0, temp_f0, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp20, spA0, sp20);
        guRotateF(spA0, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp20, spA0, sp20);
        guTranslateF(sp60, 0.0f, playerStatus->colliderHeight * 0.5f, 0.0f);
        guMtxCatF(sp20, sp60, sp20);
        guScaleF(spE0, SPRITE_WORLD_SCALE_F, SPRITE_WORLD_SCALE_D, SPRITE_WORLD_SCALE_D);
        guMtxCatF(sp20, spE0, sp20);
        guTranslateF(sp60, playerStatus->position.x, playerStatus->position.y, playerStatus->position.z);
        guMtxCatF(sp20, sp60, sp20);

        if (playerStatus->animFlags & PA_FLAGS_SHIVERING) {
            playerStatus->animFlags = playerStatus->animFlags & ~PA_FLAGS_SHIVERING;
            playerStatus->shiverTime = 22;
            func_802DDEE4(0, -1, 0, 0, 0, 0, 0, 0);
            func_802DDFF8(playerStatus->anim, 5, 1, 1, 1, 0, 0);
        }

        if (playerStatus->shiverTime != 0) {
            playerStatus->shiverTime--;
            if (playerStatus->shiverTime == 0) {
                func_802DDEE4(0, -1, 0, 0, 0, 0, 0, 0);
            }
        }
      
        if (playerStatus->spriteFacingAngle >= 90.0f && playerStatus->spriteFacingAngle < 270.0f) {
            flags = 0x10000000;
        } else {
            flags = 0;
        }

        spr_draw_player_sprite(flags, 0, 0, 0, sp20);
    }

    D_800F7B4C++;

    if (D_800F7B4C >= 3) {
        D_800F7B4C = 0;
    }
}

/// Only used when speedy spinning.
void appendGfx_player_spin(void* data) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Matrix4f mtx;
    Matrix4f translation;
    Matrix4f rotation;
    Matrix4f scale;
    f32 yaw;
    f32 blurAngle;
    s32 tint;
    f32 px, py, pz;
    s32 x, y, z;
    s32 i;
    s32 flags;

    for (i = 0; i < 2; i++) {
        yaw = -gCameras[gCurrentCamID].currentYaw;

        if (i == 0) {
            if (playerStatus->spriteFacingAngle > 90.0f && playerStatus->spriteFacingAngle <= 180.0f) {
                yaw = 180.0f - playerStatus->spriteFacingAngle;
            } else {
                if (playerStatus->spriteFacingAngle > 180.0f && playerStatus->spriteFacingAngle <= 270.0f) {
                    yaw = playerStatus->spriteFacingAngle - 180.0f;
                } else if (playerStatus->spriteFacingAngle > 270.0f && playerStatus->spriteFacingAngle <= 360.0f) {
                    yaw = 360.0f - playerStatus->spriteFacingAngle;
                } else {
                    yaw = playerStatus->spriteFacingAngle;
                }
            }

            tint = yaw / 25.0f;
            tint = 255 - (tint * 60);
            if (tint < 100) {
                tint = 100;
            }

            func_802DDFF8(0, 6, tint, tint, tint, 255, 0);

            guRotateF(rotation, yaw, 0.0f, -1.0f, 0.0f);
            guRotateF(mtx, clamp_angle(playerStatus->pitch), 0.0f, 0.0f, 1.0f);
            guMtxCatF(rotation, mtx, mtx);
            px = playerStatus->position.x;
            py = playerStatus->position.y;
            pz = playerStatus->position.z;
        } else {
            blurAngle = phys_get_spin_history(i, &x, &y, &z);

            if (y == 0x80000000) {
                py = playerStatus->position.y;
            } else {
                py = y;
            }

            px = playerStatus->position.x;
            pz = playerStatus->position.z;
            func_802DDEE4(0, -1, 7, 0, 0, 0, 64, 0);
            guRotateF(mtx, yaw, 0.0f, -1.0f, 0.0f);
            guRotateF(rotation, yaw, 0.0f, -1.0f, 0.0f);
            guRotateF(mtx, blurAngle, 0.0f, 1.0f, 0.0f);
            guMtxCatF(rotation, mtx, mtx);
        }

        guTranslateF(translation, 0.0f, -playerStatus->colliderHeight * 0.5f, 0.0f);
        guMtxCatF(translation, mtx, mtx);
        guRotateF(rotation, yaw, 0.0f, 1.0f, 0.0f);
        guMtxCatF(mtx, rotation, mtx);
        guRotateF(rotation, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
        guMtxCatF(mtx, rotation, mtx);
        guTranslateF(translation, 0.0f, playerStatus->colliderHeight * 0.5f, 0.0f);
        guMtxCatF(mtx, translation, mtx);
        guScaleF(scale, SPRITE_WORLD_SCALE_D, SPRITE_WORLD_SCALE_D, SPRITE_WORLD_SCALE_D);
        guMtxCatF(mtx, scale, mtx);
        guTranslateF(translation, px, py, pz);
        guMtxCatF(mtx, translation, mtx);

        if (playerStatus->spriteFacingAngle >= 90.0f && playerStatus->spriteFacingAngle < 270.0f) {
            flags = 0x10000000;
        } else {
            flags = 0;
        }

        spr_draw_player_sprite(flags, 0, 0, 0, mtx);
    }
}

void update_player_shadow(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Shadow* shadow = get_shadow_by_index(gPlayerStatusPtr->shadowID);
    Camera* camera = &gCameras[gCurrentCameraID];
    f32 shadowScale = 0.0f;
    f32 yawTemp = 0.0f;
    f32 hitDirX, hitDirZ;
    f32 hitRx, hitRz;
    f32 x, y, z;
    f32 playerX, playerZ;
    s32 dist;
    f32 raycastYaw;

    if (playerStatus->spriteFacingAngle >= 90.0f && playerStatus->spriteFacingAngle < 270.0f) {
        yawTemp = 180.0f;
    }

    raycastYaw = (yawTemp - 90.0f) + gCameras[gCurrentCameraID].currentYaw;
    shadow->position.x = playerX = playerStatus->position.x;
    shadow->position.z = playerZ = playerStatus->position.z;
    x = playerX;
    y = playerStatus->position.y + (playerStatus->colliderHeight / 3.5f);
    z = playerZ;
    shadowScale = 1024.0f;
    gCollisionStatus.floorBelow = player_raycast_below(raycastYaw, playerStatus->colliderDiameter, &x, &y, &z,
                                                       &shadowScale, &hitRx, &hitRz, &hitDirX, &hitDirZ);
    shadow->rotation.x = hitRx;
    shadow->rotation.z = hitRz;
    shadow->rotation.y = clamp_angle(-camera->currentYaw);
    hitRx += 180.0f;
    hitRz += 180.0f;

    if (hitRx != 0.0f || hitRz != 0.0f) {
        s32 dist = dist2D(x, z, playerStatus->position.x, playerStatus->position.z);
        f32 tan = atan2(playerStatus->position.x, playerStatus->position.z, x, z);
        s32 angleTemp = clamp_angle((-90.0f - tan) + get_player_normal_yaw());

        if (gGameStatusPtr->playerGroundTraceNormal.y != 0.0f) {
            y -= sqrtf(SQ(gGameStatusPtr->playerGroundTraceNormal.x) + SQ(gGameStatusPtr->playerGroundTraceNormal.z)) /
                       gGameStatusPtr->playerGroundTraceNormal.y * dist * sin_deg(angleTemp);
        }
    }

    shadow->position.y = y;
    shadow->alpha = (f64)playerStatus->alpha1 / 2;

    if (!(gGameStatusPtr->peachFlags & 1)) {
        set_standard_shadow_scale(shadow, shadowScale);
    } else {
        set_peach_shadow_scale(shadow, shadowScale);
    }
}
