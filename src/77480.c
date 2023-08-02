#include "common.h"
#include "ld_addrs.h"
#include "world/actions.h"
#include "sprite.h"
#include "world/partner/watt.h"
#include "sprite/player.h"

#ifdef SHIFT
#define inspect_icon_VRAM inspect_icon_VRAM
#define speech_bubble_VRAM speech_bubble_VRAM
#define pulse_stone_VRAM pulse_stone_VRAM
#define i_spy_VRAM i_spy_VRAM
#else
#define inspect_icon_VRAM (void*)0x802B7000
#define speech_bubble_VRAM (void*)0x802B7000
#define pulse_stone_VRAM (void*)0x802B7000
#define i_spy_VRAM (void*)0x802B7000
#endif

SHIFT_BSS UNK_FUN_PTR(ISpyNotificationCallback);
SHIFT_BSS UNK_FUN_PTR(PulseStoneNotificationCallback);
SHIFT_BSS UNK_FUN_PTR(TalkNotificationCallback);
SHIFT_BSS UNK_FUN_PTR(InteractNotificationCallback);
SHIFT_BSS s32 D_8010C950;

extern f32 D_800F7B48;
extern s32 D_800F7B4C;
extern s32 WorldTattleInteractionID;

s32 player_raycast_down(f32*, f32*, f32*, f32*);
s32 player_raycast_up_corner(f32* x, f32* y, f32* z, f32* length);
s32 player_raycast_general(s32, f32, f32, f32, f32, f32, f32, f32*, f32*, f32*, f32*, f32*, f32*, f32*);
void player_get_slip_vector(f32* outX, f32* outY, f32 x, f32 y, f32 nX, f32 nY);
void phys_update_standard(void);
void phys_update_lava_reset(void);
void update_player_blink(void);
void check_for_ispy(void);
void render_ispy_icon(void);
void check_for_pulse_stone(void);
void clear_ispy_icon(void);
void render_pulse_stone_icon(void);
void clear_pulse_stone_icon(void);
void check_for_conversation_prompt(void);
void render_conversation_prompt(void);
void clear_conversation_prompt(void);
void check_for_interactables(void);
void render_interact_prompt(void);
void func_800E0B14(void);
void update_partner_timers(void);
void player_update_sprite(void);
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
    ret = NO_COLLIDER;
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

    return player_raycast_below(yaw - 90.0f + gCameras[gCurrentCameraID].curYaw, playerStatus->colliderDiameter,
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
    s32 ret = NO_COLLIDER;

    hitDepth = *length;
    entityID = test_ray_entities(*x, *y, *z, 0.0f, -1.0f, 0.0f, &hitX, &hitY, &hitZ, &hitDepth, &hitNx, &hitNy, &hitNz);
    if (entityID >= 0) {
        entity = get_entity_by_index(entityID);
        if (entity->alpha < 255) {
            entity->collisionTimer = 4;
            entity->flags |= ENTITY_FLAG_CONTINUOUS_COLLISION;
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

    ret = NO_COLLIDER;
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

    ret = NO_COLLIDER;

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
    ret = NO_COLLIDER;

    if (!(playerStatus->flags & (PS_FLAG_FALLING | PS_FLAG_JUMPING))) {
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
    ret = NO_COLLIDER;
    if (entityID >= 0) {
        entity = get_entity_by_index(entityID);
        if (entity->alpha < 255) {
            entity->collisionTimer = 0;
            entity->flags |= ENTITY_FLAG_CONTINUOUS_COLLISION;
        } else {
            ret = entityID | COLLISION_WITH_ENTITY_BIT;
        }
    } else if (mode == 3) {
        ret = test_ray_colliders(COLLIDER_FLAG_IGNORE_SHELL, startX, startY, startZ, dirX, dirY, dirZ,
            hitX, hitY, hitZ, hitDepth, hitNx, hitNy, hitNz);
    }

    if (mode == 1 || mode == 3) {
        return ret;
    }

    if (mode == 4) {
        ignoreFlags = COLLISION_CHANNEL_80000;
    } else {
        ignoreFlags = COLLIDER_FLAG_IGNORE_PLAYER;
    }

    colliderID = test_ray_colliders(ignoreFlags, startX, startY, startZ, dirX, dirY, dirZ,
        hitX, hitY, hitZ, hitDepth, hitNx, hitNy, hitNz);

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

s32 player_test_move_without_slipping(PlayerStatus* playerStatus, f32* x, f32* y, f32* z, f32 length, f32 yaw, s32* hasClimbableStep) {
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
    ret = NO_COLLIDER;

    raycastID = player_raycast_general(0, *x, *y + 0.1, *z, sinTheta, 0, cosTheta, &hitX, &hitY, &hitZ, &hitDepth, &hitNx, &hitNy, &hitNz);
    if (raycastID >= 0 && hitDepth <= depth) {
        *hasClimbableStep = TRUE;
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
    s32 ret = NO_COLLIDER;

    height = 0.0f;
    if (!(playerStatus->flags & (PS_FLAG_JUMPING | PS_FLAG_FALLING))) {
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

    if ((playerStatus->timeInAir > 100) || (playerStatus->pos.y < -2000.0f)) {
        if (!(playerStatus->animFlags & PA_FLAG_NO_OOB_RESPAWN)) {
            playerStatus->timeInAir = 0;
            playerStatus->pos.x = playerStatus->lastGoodPos.x;
            playerStatus->pos.y = playerStatus->lastGoodPos.y;
            playerStatus->pos.z = playerStatus->lastGoodPos.z;

            if (playerStatus->animFlags & PA_FLAG_RIDING_PARTNER) {
                Npc* partner;

                playerStatus->animFlags |= PA_FLAG_DISMOUNTING_ALLOWED | PA_FLAG_INTERRUPT_USE_PARTNER;
                partner = get_npc_unsafe(NPC_PARTNER);
                partner->pos.x = playerStatus->lastGoodPos.x;
                partner->pos.y = playerStatus->lastGoodPos.y + playerStatus->colliderHeight;
                partner->pos.z = playerStatus->lastGoodPos.z;
                partner->moveToPos.y = playerStatus->lastGoodPos.y;
            } else {
                playerStatus->timeInAir = 10;
            }
        }
    }

    collisionStatus->curWall = NO_COLLIDER;
    collisionStatus->lastWallHammered = NO_COLLIDER;
    collisionStatus->curInspect = NO_COLLIDER;
    collisionStatus->floorBelow = TRUE;

    update_player_input();
    playerStatus->flags &= ~PS_FLAG_SPECIAL_LAND;
    update_player_blink();

    if (playerStatus->flags & PS_FLAG_NO_STATIC_COLLISION) {
        phys_update_action_state();
        if (!game_scripts_disabled()) {
            collision_main_lateral();
        }
    } else if (playerStatus->actionState != ACTION_STATE_HIT_LAVA) {
        phys_update_standard();
    } else {
        phys_update_lava_reset();
    }

    if (playerStatus->flags & PS_FLAG_CUTSCENE_MOVEMENT) {
        playerStatus->moveFrames--;
        if (playerStatus->moveFrames <= 0) {
            playerStatus->moveFrames = 0;
            playerStatus->flags &= ~PS_FLAG_CUTSCENE_MOVEMENT;
        }
    }

    if (!(playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS)) {
        handle_floor_behavior();
    }

    player_update_sprite();

    gameStatus = gGameStatusPtr;
    gameStatus->playerPos.x = playerStatus->pos.x;
    gameStatus->playerPos.y = playerStatus->pos.y;
    gameStatus->playerPos.z = playerStatus->pos.z;
    gameStatus->playerYaw = playerStatus->curYaw;

    check_input_open_menus();
    if (!(playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS)) {
        check_input_status_bar();
    }

    update_player_shadow();
    check_for_interactables();
    check_for_conversation_prompt();
    check_for_pulse_stone();
    check_for_ispy();

    playerStatus->pushVel.x = 0.0f;
    playerStatus->pushVel.y = 0.0f;
    playerStatus->pushVel.z = 0.0f;
    playerStatus->flags &= ~PS_FLAG_SLIDING;
    playerStatus->animFlags &= ~PA_FLAG_FORCE_USE_PARTNER;
}

void check_input_use_partner(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;
    u32 actionState = playerStatus->actionState;

    if (!(playerStatus->animFlags & PA_FLAG_8BIT_MARIO)
        && (playerStatus->animFlags & PA_FLAG_FORCE_USE_PARTNER || playerStatus->inputDisabledCount == 0)
        && (playerStatus->pressedButtons & BUTTON_C_DOWN && !(playerStatus->flags & PS_FLAG_NO_PARTNER_USAGE))
        && !(playerStatus->pressedButtons & BUTTON_B)
        && !(playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS)
        && actionState <= ACTION_STATE_RUN
    ) {
        if (playerData->curPartner == PARTNER_GOOMBARIO) {
            WorldTattleInteractionID = playerStatus->interactingWithID;
        }
        partner_use_ability();
    }
}

void phys_update_standard(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 flags;

    check_input_use_partner();
    phys_update_action_state();

    if (!(playerStatus->flags & PS_FLAG_FLYING)) {
        if (playerStatus->flags & PS_FLAG_JUMPING) {
            phys_update_jump();
        }
    }

    if (playerStatus->flags & PS_FLAG_FALLING) {
        if (!(playerStatus->flags & PS_FLAG_FLYING)) {
            phys_update_falling();
        }
    }

    check_input_midair_jump();

    if (playerStatus->actionState != ACTION_STATE_SLIDING) {
        collision_main_lateral();
        collision_check_player_overlaps();

        if (collision_main_above() < 0 && playerStatus->timeInAir == 0 &&
            playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS) {
            collision_lateral_peach();
        }

        if ((playerStatus->actionState != ACTION_STATE_ENEMY_FIRST_STRIKE)
            && (playerStatus->actionState != ACTION_STATE_STEP_UP)) {
            phys_main_collision_below();
        }
    }

    if (playerStatus->animFlags & PA_FLAG_WATT_IN_HANDS) {
        world_watt_sync_held_position();
    }

    if (!(playerStatus->flags & PS_FLAG_CAMERA_DOESNT_FOLLOW)) {
        gCameras[CAM_DEFAULT].targetPos.x = playerStatus->pos.x;
        gCameras[CAM_DEFAULT].targetPos.y = playerStatus->pos.y;
        gCameras[CAM_DEFAULT].targetPos.z = playerStatus->pos.z;
    }
}

void phys_update_lava_reset(void) {
    phys_update_action_state();
    collision_main_lateral();
    collision_lava_reset_check_additional_overlaps();

    if (!(gPlayerStatusPtr->flags & PS_FLAG_CAMERA_DOESNT_FOLLOW)) {
        Camera* camera = &gCameras[CAM_DEFAULT];

        camera->targetPos.x = gPlayerStatusPtr->pos.x;
        camera->targetPos.y = gPlayerStatusPtr->pos.y;
        camera->targetPos.z = gPlayerStatusPtr->pos.z;
    }
}

void clear_player_status(void) {
    mem_clear(&gPlayerStatus, sizeof(gPlayerStatus));
}

void player_reset_data(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    mem_clear(playerStatus, sizeof(PlayerStatus));
    playerStatus->flags = PS_FLAG_HAS_REFLECTION;
    reset_player_status();
    playerStatus->shadowID = create_shadow_type(0, playerStatus->pos.x, playerStatus->pos.y,
                             playerStatus->pos.z);
    func_800E6B68();
    func_800E0B14();
    clear_conversation_prompt();
    clear_pulse_stone_icon();
    clear_ispy_icon();
    func_800E5520();
}

b32 is_player_dismounted(void) {
    if (gPartnerStatus.partnerActionState == PARTNER_ACTION_USE &&
        (gPartnerStatus.actingPartner == PARTNER_WATT
        || gPartnerStatus.actingPartner == PARTNER_BOW
        || gPartnerStatus.actingPartner == PARTNER_SUSHIE
        || gPartnerStatus.actingPartner == PARTNER_PARAKARRY
        || gPartnerStatus.actingPartner == PARTNER_LAKILESTER)) {
        return FALSE;
    }
    return TRUE;
}

s32 get_overriding_player_anim(s32 anim) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;

    if (playerStatus->actionState == ACTION_STATE_USE_SPINNING_FLOWER
        && anim != ANIM_Mario1_Flail
        && anim != ANIM_Mario1_Jump
    ) {
        return -1;
    }

    if (partnerStatus->partnerActionState != PARTNER_ACTION_NONE) {
        if (partnerStatus->actingPartner == PARTNER_LAKILESTER && anim == ANIM_Mario1_Idle) {
            anim = ANIM_MarioW2_RideLaki;
        }

        if (partnerStatus->partnerActionState != PARTNER_ACTION_NONE
            && partnerStatus->actingPartner == PARTNER_BOW
            && anim != ANIM_Mario1_Crouch
            && anim != ANIM_Mario1_Idle
        ) {
            return -1;
        }
    }

    if (anim == ANIM_Mario1_ThumbsUp && partnerStatus->partnerActionState == PARTNER_ACTION_USE) {
        return -1;
    }

    if (anim == ANIM_MarioW1_Lift || anim == ANIM_Peach2_SpreadArms || anim == ANIM_Mario1_Idle) {
        if (!(playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS)) {
            if (!is_player_dismounted()) {
                return -1;
            }
        } else if (!(playerStatus->animFlags & PA_FLAG_INVISIBLE)) {
            anim = ANIM_Peach2_SpreadArms;
        } else {
            peach_set_disguise_anim(BasicPeachDisguiseAnims[playerStatus->peachDisguise].hold);
            return -1;
        }
    } else if (playerStatus->animFlags & PA_FLAG_USING_PEACH_PHYSICS) {
        if ((playerStatus->peachItemHeld != 0)
        && (anim == ANIM_Peach2_RaiseArms || anim == ANIM_Peach2_Talk || anim == ANIM_Peach2_LowerArms)) {
            anim = ANIM_Peach3_PresentCompleteCake;
        }
    }

    if (anim == ANIM_MarioW2_Collapse) {
        exec_ShakeCam1(0, 0, 2);
    }

    return anim;
}

void suggest_player_anim_allow_backward(AnimID anim) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    AnimID newAnim = get_overriding_player_anim(anim);

    if (newAnim != -1) {
        playerStatus->anim = newAnim;
        playerStatus->animNotifyValue = 0;
        playerStatus->flags &= ~PS_FLAG_FACE_FORWARDS;
    }
}

void force_player_anim(AnimID anim) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->anim = anim;
    playerStatus->animNotifyValue = 0;
    playerStatus->flags &= ~PS_FLAG_FACE_FORWARDS;
}

void suggest_player_anim_always_forward(AnimID anim) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    AnimID newAnim = get_overriding_player_anim(anim);

    if (newAnim != -1) {
        playerStatus->anim = newAnim;
        playerStatus->animNotifyValue = 0;
        playerStatus->flags |= PS_FLAG_FACE_FORWARDS;
    }
}

void update_player_blink(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 outtaSight = FALSE;
    u8 phi_v1;
    u8* alpha;

    if (gPartnerStatus.actingPartner == PARTNER_BOW) {
        outtaSight = gPartnerStatus.partnerActionState != PARTNER_ACTION_NONE;
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
                playerStatus->flags |= PS_FLAG_HAZARD_INVINCIBILITY;
            } else {
                playerStatus->alpha1 = 255;
                playerStatus->flags &= ~PS_FLAG_HAZARD_INVINCIBILITY;
            }
        } else {
            playerStatus->flags |= PS_FLAG_HAZARD_INVINCIBILITY;
        }
    }
}

// dist_to_player2D
f32 get_xz_dist_to_player(f32 x, f32 z) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    return dist2D(x, z, playerStatus->pos.x, playerStatus->pos.z);
}

void enable_player_shadow(void) {
    get_shadow_by_index(gPlayerStatus.shadowID)->flags &= ~ENTITY_FLAG_HIDDEN;
}

void disable_player_shadow(void) {
    get_shadow_by_index(gPlayerStatus.shadowID)->flags |= ENTITY_FLAG_HIDDEN;
}

s32 disable_player_static_collisions(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->flags |= PS_FLAG_NO_STATIC_COLLISION;
    playerStatus->enableCollisionOverlapsCheck++;
    return playerStatus->enableCollisionOverlapsCheck;
}

s32 enable_player_static_collisions(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->enableCollisionOverlapsCheck--;
    if (playerStatus->enableCollisionOverlapsCheck == 0) {
        playerStatus->flags &= ~PS_FLAG_NO_STATIC_COLLISION;
    }
    return playerStatus->enableCollisionOverlapsCheck;
}

s32 disable_player_input(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->flags |= PS_FLAG_INPUT_DISABLED;
    playerStatus->inputDisabledCount++;
    return playerStatus->inputDisabledCount;
}

s32 enable_player_input(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    playerStatus->inputDisabledCount--;
    if (playerStatus->inputDisabledCount == 0) {
        playerStatus->flags &= ~PS_FLAG_INPUT_DISABLED;
    }
    return playerStatus->inputDisabledCount;
}

void func_800E01DC(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (playerStatus->animFlags & PA_FLAG_INTERACT_PROMPT_AVAILABLE) {
        playerStatus->flags |= PS_FLAG_INTERACTED;
    }
}

s32 game_scripts_disabled(void) {
    s32 ret = FALSE;

    if (gGameStatusPtr->disableScripts && (gGameStatusPtr->curButtons[0] & BUTTON_R)) {
        if (gPartnerStatus.partnerActionState == PARTNER_ACTION_NONE) {
            set_action_state(ACTION_STATE_IDLE);
        }
        ret = TRUE;
    }
    return ret;
}

void player_render_interact_prompts(void) {
    render_conversation_prompt();
    render_interact_prompt();
    render_pulse_stone_icon();
    render_ispy_icon();
}

void check_for_ispy(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    if (gCurrentHiddenPanels.activateISpy && ISpyNotificationCallback == NULL) {
        if (!(playerStatus->animFlags &
            (PA_FLAG_SPEECH_PROMPT_AVAILABLE | PA_FLAG_INTERACT_PROMPT_AVAILABLE))) {
            DMA_COPY_SEGMENT(i_spy);
            ISpyNotificationCallback = ispy_notification_setup;
        }
    }

    if (ISpyNotificationCallback != NULL) {
        ISpyNotificationCallback();
    }
}

void render_ispy_icon(void) {
    if ((gPlayerStatusPtr->animFlags & PA_FLAG_ISPY_VISIBLE) && (ISpyNotificationCallback != NULL)) {
        appendGfx_ispy_icon();
    }
}

void clear_ispy_icon(void) {
    ISpyNotificationCallback = NULL;
    gPlayerStatusPtr->animFlags &= ~PA_FLAG_ISPY_VISIBLE;
}

void check_for_pulse_stone(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    s32 dx, dy;

    if (PulseStoneNotificationCallback == NULL) {
        if (gPlayerStatus.animFlags & PA_FLAG_ISPY_VISIBLE) {
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

        if (!(gPlayerStatus.animFlags & (PA_FLAG_USING_PULSE_STONE | PA_FLAG_PULSE_STONE_VISIBLE))) {
            return;
        }

        if (gPlayerStatus.flags & PS_FLAG_PAUSED || gPlayerStatus.inputDisabledCount != 0) {
            return;
        }

        if (!(gPlayerStatus.animFlags & (PA_FLAG_SPEECH_PROMPT_AVAILABLE | PA_FLAG_INTERACT_PROMPT_AVAILABLE))) {
            DMA_COPY_SEGMENT(pulse_stone);
            PulseStoneNotificationCallback = pulse_stone_notification_setup;
        }
    }

    if (PulseStoneNotificationCallback != NULL) {
        PulseStoneNotificationCallback();
    }
}

void render_pulse_stone_icon(void) {
    if ((gPlayerStatusPtr->animFlags & PA_FLAG_PULSE_STONE_VISIBLE) && (PulseStoneNotificationCallback != NULL)) {
        appendGfx_pulse_stone_icon();
    }
}

void clear_pulse_stone_icon(void) {
    PulseStoneNotificationCallback = NULL;
    gPlayerStatusPtr->animFlags &= ~PA_FLAG_PULSE_STONE_VISIBLE;
}

s32 has_valid_conversation_npc(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = playerStatus->encounteredNPC;
    s32 ret = FALSE;
    s32 cond;

    if (npc != NULL && !(npc->flags & NPC_FLAG_10000000)) {
        cond = (playerStatus->flags & (PS_FLAG_HAS_CONVERSATION_NPC | PS_FLAG_INPUT_DISABLED)) == PS_FLAG_HAS_CONVERSATION_NPC;
        ret = cond;
    }
    return ret;
}

void check_for_conversation_prompt(void) {
    if (gPlayerStatus.animFlags & PA_FLAG_ISPY_VISIBLE || InteractNotificationCallback || PulseStoneNotificationCallback != NULL) {
        return;
    }

    if (TalkNotificationCallback == NULL) {
        if (gPlayerStatus.inputDisabledCount || gPlayerStatus.flags & PS_FLAG_PAUSED) {
            return;
        }

        if (has_valid_conversation_npc()) {
            TalkNotificationCallback = NULL;
            DMA_COPY_SEGMENT(speech_bubble);
            TalkNotificationCallback = interact_speech_setup;
        } else {
            TalkNotificationCallback = NULL;
            return;
        }
    }

    if (TalkNotificationCallback != NULL) {
        TalkNotificationCallback();
    }
}

void render_conversation_prompt(void) {
    if ((gPlayerStatusPtr->animFlags & PA_FLAG_SPEECH_PROMPT_AVAILABLE) && (TalkNotificationCallback != NULL)) {
        appendGfx_speech_bubble();
    }
}

void clear_conversation_prompt(void) {
    TalkNotificationCallback = NULL;
    gPlayerStatusPtr->animFlags &= ~PA_FLAG_SPEECH_PROMPT_AVAILABLE;
}

void func_800E06C0(s32 arg0) {
    D_8010C950 = (arg0 == 1);
}

s32 func_800E06D8(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = playerStatus->encounteredNPC;
    s32 interactingID = playerStatus->interactingWithID;
    s32 currentWall;

    if (playerStatus->timeInAir != 0 || playerStatus->inputDisabledCount != 0) {
        return FALSE;
    }
    if (gCollisionStatus.curWall == NO_COLLIDER) {
        return FALSE;
    }
    if (playerStatus->flags & PS_FLAG_HAS_CONVERSATION_NPC
        && !(playerStatus->flags & PS_FLAG_INPUT_DISABLED)
        && npc != NULL
        && npc->flags & NPC_FLAG_10000000
    ) {
        playerStatus->interactingWithID = NO_COLLIDER;
        return TRUE;
    }

    currentWall = gCollisionStatus.curWall;
    if (!(currentWall & COLLISION_WITH_ENTITY_BIT)) {
        if (!should_collider_allow_interact(currentWall)) {
            return FALSE;
        }
    } else if (!phys_can_player_interact()) {
        playerStatus->interactingWithID = NO_COLLIDER;
        return FALSE;
    } else if (get_entity_type(currentWall) == ENTITY_TYPE_PUSH_BLOCK) {
        return FALSE;
    }

    if (interactingID == currentWall) {
        if (playerStatus->flags & PS_FLAG_INTERACTED) {
            return FALSE;
        }
    } else {
        playerStatus->flags &= ~PS_FLAG_INTERACTED;
    }
    playerStatus->interactingWithID = NO_COLLIDER;

    return TRUE;
}

static const f32 padding = 0.0f;

void check_for_interactables(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = gPlayerStatus.encounteredNPC;
    s32 phi_s2;

    if ((playerStatus->animFlags & PA_FLAG_ISPY_VISIBLE) || TalkNotificationCallback || PulseStoneNotificationCallback != NULL) {
        return;
    }

    if (InteractNotificationCallback == NULL) {
        s32 curInteraction = gCollisionStatus.curWall;

        if (playerStatus->inputDisabledCount != 0) {
            if (gPlayerStatus.interactingWithID != curInteraction) {
                gPlayerStatus.interactingWithID = curInteraction;
            }
            return;
        }

        if (playerStatus->timeInAir != 0) {
            return;
        }

        if (curInteraction == NO_COLLIDER) {
            s32 floor = gCollisionStatus.curFloor;

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
                        curInteraction = NO_COLLIDER;
                        break;
                }
            } else if (
                ((playerStatus->flags & (PS_FLAG_HAS_CONVERSATION_NPC | PS_FLAG_INPUT_DISABLED)) == PS_FLAG_HAS_CONVERSATION_NPC)
                && (npc != NULL)
                && (npc->flags & NPC_FLAG_10000000)
            ) {
                curInteraction = npc->npcID | COLLISION_WITH_NPC_BIT;
                if (playerStatus->interactingWithID == curInteraction) {
                    return;
                }
                phi_s2 = 0;
            } else {
                playerStatus->interactingWithID = NO_COLLIDER;
                playerStatus->flags &= ~PS_FLAG_INTERACTED;
                return;
            }
        } else {
            if (!(curInteraction & COLLISION_WITH_ENTITY_BIT)) {
                phi_s2 = 0;
                if (!(curInteraction & COLLISION_WITH_NPC_BIT)) {
                    if (!should_collider_allow_interact(curInteraction)) {
                        playerStatus->interactingWithID = NO_COLLIDER;
                        playerStatus->flags &= ~PS_FLAG_INTERACTED;
                        return;
                    }
                }
            } else {
                if (!phys_can_player_interact()) {
                    phi_s2 = 1;
                    playerStatus->interactingWithID = NO_COLLIDER;
                    playerStatus->flags &= ~PS_FLAG_INTERACTED;
                    return;
                }
                phi_s2 = 1;
            }
        }
        if (playerStatus->interactingWithID == curInteraction) {
            if ((playerStatus->flags & PS_FLAG_INTERACTED)) {
                return;
            }
        } else {
            playerStatus->flags &= ~PS_FLAG_INTERACTED;
        }

        playerStatus->interactingWithID = curInteraction;
        if ((phi_s2 == 0) || curInteraction >= 0 && get_entity_by_index(curInteraction)->flags & ENTITY_FLAG_SHOWS_INSPECT_PROMPT) {
            if (playerStatus->actionState == ACTION_STATE_IDLE || playerStatus->actionState == ACTION_STATE_WALK || playerStatus->actionState == ACTION_STATE_RUN) {
                playerStatus->animFlags |= PA_FLAG_INTERACT_PROMPT_AVAILABLE;
                func_800EF3D4(2);
            }
        }
    }

    if (!(playerStatus->animFlags & PA_FLAG_INTERACT_PROMPT_AVAILABLE)) {
        func_800EF3D4(0);
        partner_reset_tether_distance();
        return;
    }

    if (InteractNotificationCallback == NULL) {
        DMA_COPY_SEGMENT(inspect_icon);
        InteractNotificationCallback = interact_inspect_setup;

    }

    if (InteractNotificationCallback != NULL) {
        InteractNotificationCallback();
    }
}

void appendGfx_interact_prompt(void);

void render_interact_prompt(void) {
    if ((gPlayerStatusPtr->animFlags & PA_FLAG_INTERACT_PROMPT_AVAILABLE) && (InteractNotificationCallback != NULL)) {
        appendGfx_interact_prompt();
    }
}

void func_800E0B14(void) {
    InteractNotificationCallback = NULL;
    gPlayerStatusPtr->animFlags &= ~PA_FLAG_INTERACT_PROMPT_AVAILABLE;
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

void player_update_sprite(void) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 cameraYaw = gCameras[gCurrentCameraID].curYaw;
    f32 camRelativeYaw = get_clamped_angle_diff(cameraYaw, playerStatus->curYaw);
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

        if (fabsf(get_clamped_angle_diff(cameraYaw, playerStatus->curYaw)) >= 90.0f) {
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

    if (playerStatus->flags & PS_FLAG_NO_FLIPPING) {
        angle = 0.0f;
    }

    playerStatus->flipYaw[gCurrentCameraID] = angle;

    PrevPlayerCamRelativeYaw = angle = clamp_angle(camRelativeYaw);
    angle = clamp_angle(playerStatus->flipYaw[gCurrentCameraID] + angle);
    if (playerStatus->curSpeed == 0.0f) {
        D_800F7B48 = 0.0f;
    }

    trueAnim = playerStatus->anim;
    if (playerStatus->flags & PS_FLAG_SPINNING) {
        playerStatus->trueAnimation = trueAnim;
    } else {
        sprIndex = (trueAnim >> 0x10) & 0xFF;

        if (playerStatus->actionState != ACTION_STATE_TORNADO_JUMP && !(playerStatus->flags & PS_FLAG_ROTATION_LOCKED)) {
            playerStatus->spriteFacingAngle = angle + D_800F7B48;
            trueAnim = playerStatus->anim;
            if (!(playerStatus->flags & PS_FLAG_FACE_FORWARDS)
                && (sprIndex == SPR_Mario1 || sprIndex == SPR_MarioW1 || sprIndex == SPR_Peach1)
                && fabsf(get_clamped_angle_diff(cameraYaw, playerStatus->curYaw)) < 60.0f
            ) {
                trueAnim = get_player_back_anim(trueAnim);
            }
            playerStatus->trueAnimation = trueAnim;
            playerStatus->curYaw = playerStatus->targetYaw;
        } else {
            trueAnim = playerStatus->anim;
            if (!(playerStatus->flags & PS_FLAG_FACE_FORWARDS)
                && (sprIndex == SPR_Mario1 || sprIndex == SPR_MarioW1 || sprIndex == SPR_Peach1)
                && playerStatus->spriteFacingAngle < 350.0f && playerStatus->spriteFacingAngle > 190.0f
            ) {
                trueAnim = get_player_back_anim(trueAnim);
            }
            playerStatus->trueAnimation = trueAnim;
        }
    }

    timescale = 1.0f;
    if (playerStatus->flags & PS_FLAG_ENTERING_BATTLE) {
        timescale = 0.5f;
    }
    if (playerStatus->flags & PS_FLAG_TIME_STOPPED) {
        timescale = 0.0f;
    }
    playerStatus->animNotifyValue = spr_update_player_sprite(PLAYER_SPRITE_MAIN, playerStatus->trueAnimation, timescale);
    playerStatus->flags |= PS_FLAG_SPRITE_REDRAW;
}

s32 get_player_back_anim(s32 anim) {
    s32 sprIndex = (anim >> 16) & 0xff;
    s32 outAnim = 0;

    if (sprIndex != SPR_Mario1) {
        if (sprIndex != SPR_MarioW1 && sprIndex != SPR_Peach1) {
            return anim;
        }

        if (sprIndex == SPR_Mario1) {
            if (anim > ANIM_Mario1_SpinFall) {
                return anim;
            }
        } else if (sprIndex == SPR_MarioW1) {
            if (anim == ANIM_MarioW1_Lift) {
                outAnim = ANIM_MarioW1_Lift_Back;
            } else if (anim == ANIM_MarioW1_Toss) {
                outAnim = ANIM_MarioW1_Toss_Back;
            } else if (anim == ANIM_MarioW1_Smash1_Miss) {
                outAnim = ANIM_MarioW1_Smash1_Miss_Back;
            } else if (anim == ANIM_MarioW1_Smash1_Hit) {
                outAnim = ANIM_MarioW1_Smash1_Hit_Back;
            } else if (anim == ANIM_MarioW1_Smash2_Miss) {
                outAnim = ANIM_MarioW1_Smash2_Miss_Back;
            } else if (anim == ANIM_MarioW1_Smash2_Hit) {
                outAnim = ANIM_MarioW1_Smash2_Hit_Back;
            } else if (anim == ANIM_MarioW1_Smash3_Miss) {
                outAnim = ANIM_MarioW1_Smash3_Miss_Back;
            } else if (anim == ANIM_MarioW1_Smash3_Hit) {
                outAnim = ANIM_MarioW1_Smash3_Hit_Back;
            }
        } else if (sprIndex == SPR_Peach1) {
            if (anim > ANIM_Peach1_StepDown) {
                outAnim = anim + 1;
            }
        }
    } else if (anim > ANIM_Mario1_SpinFall) {
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

    if (playerStatus->flags & PS_FLAG_SPRITE_REDRAW) {
        playerStatus->flags &= ~PS_FLAG_SPRITE_REDRAW;
        get_screen_coords(gCurrentCamID, playerStatus->pos.x, playerStatus->pos.y,
                          playerStatus->pos.z, &x, &y, &z);
        if (!(playerStatus->flags & PS_FLAG_SPINNING)) {
            if (playerStatus->alpha1 != playerStatus->alpha2) {
                if (playerStatus->alpha1 < 254) {
                    if (!(playerStatus->animFlags & PA_FLAG_MAP_HAS_SWITCH)) {
                        renderModeTemp = RENDER_MODE_SURFACE_XLU_LAYER1;
                    } else {
                        renderModeTemp = RENDER_MODE_SURFACE_XLU_LAYER2;
                    }

                    playerStatus->renderMode = renderModeTemp;
                    set_player_imgfx_comp(PLAYER_SPRITE_MAIN, -1, IMGFX_SET_ALPHA, 0, 0, 0, playerStatus->alpha1, 0);

                } else {
                    playerStatus->renderMode = RENDER_MODE_ALPHATEST;
                    set_player_imgfx_comp(PLAYER_SPRITE_MAIN, -1, IMGFX_CLEAR, 0, 0, 0, 0, 0);
                }
            }

            playerStatus->alpha2 = playerStatus->alpha1;

        } else {
            playerStatus->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
            playerStatus->alpha2 = 0;
        }

        if (!(playerStatus->animFlags & PA_FLAG_INVISIBLE)) {
            rtPtr->appendGfxArg = playerStatus;
            rtPtr->dist = -z;
            rtPtr->renderMode = playerStatus->renderMode;


            if (!(playerStatus->flags & PS_FLAG_SPINNING)) {
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
    f32 temp_f0 = -gCameras[gCurrentCamID].curYaw;
    s32 spriteIdx;

    if (playerStatus->actionState == ACTION_STATE_SLIDING) {
        guScaleF(spE0, SPRITE_WORLD_SCALE_D, SPRITE_WORLD_SCALE_D, SPRITE_WORLD_SCALE_D);
        guRotateF(sp20, temp_f0, 0.0f, 1.0f, 0.0f);
        guMtxCatF(spE0, sp20, sp20);
        guRotateF(spA0, playerStatus->spriteFacingAngle, 0.0f, 1.0f, 0.0f);
        guMtxCatF(sp20, spA0, sp20);
        guTranslateF(sp60, playerStatus->pos.x, playerStatus->pos.y - 1.0f, playerStatus->pos.z);
        guMtxCatF(sp20, sp60, sp20);
        spr_draw_player_sprite(PLAYER_SPRITE_MAIN, 0, 0, 0, sp20);
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
        guScaleF(spE0, SPRITE_WORLD_SCALE_D, SPRITE_WORLD_SCALE_D, SPRITE_WORLD_SCALE_D);
        guMtxCatF(sp20, spE0, sp20);
        guTranslateF(sp60, playerStatus->pos.x, playerStatus->pos.y, playerStatus->pos.z);
        guMtxCatF(sp20, sp60, sp20);

        if (playerStatus->animFlags & PA_FLAG_SHIVERING) {
            playerStatus->animFlags = playerStatus->animFlags & ~PA_FLAG_SHIVERING;
            playerStatus->shiverTime = 22;
            set_player_imgfx_comp(PLAYER_SPRITE_MAIN, -1, IMGFX_CLEAR, 0, 0, 0, 0, 0);
            set_player_imgfx_all(playerStatus->anim, IMGFX_SET_ANIM, IMGFX_ANIM_SHIVER, 1, 1, 0, 0);
        }

        if (playerStatus->shiverTime != 0) {
            playerStatus->shiverTime--;
            if (playerStatus->shiverTime == 0) {
                set_player_imgfx_comp(PLAYER_SPRITE_MAIN, -1, IMGFX_CLEAR, 0, 0, 0, 0, 0);
            }
        }

        if (playerStatus->spriteFacingAngle >= 90.0f && playerStatus->spriteFacingAngle < 270.0f) {
            spriteIdx = PLAYER_SPRITE_MAIN | DRAW_SPRITE_UPSIDE_DOWN;
        } else {
            spriteIdx = PLAYER_SPRITE_MAIN;
        }

        spr_draw_player_sprite(spriteIdx, 0, 0, 0, sp20);
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
    s32 spriteIdx;

    for (i = 0; i < 2; i++) {
        yaw = -gCameras[gCurrentCamID].curYaw;

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

            set_player_imgfx_all(PLAYER_SPRITE_MAIN, IMGFX_SET_COLOR, tint, tint, tint, 255, 0);

            guRotateF(rotation, yaw, 0.0f, -1.0f, 0.0f);
            guRotateF(mtx, clamp_angle(playerStatus->pitch), 0.0f, 0.0f, 1.0f);
            guMtxCatF(rotation, mtx, mtx);
            px = playerStatus->pos.x;
            py = playerStatus->pos.y;
            pz = playerStatus->pos.z;
        } else {
            blurAngle = phys_get_spin_history(i, &x, &y, &z);

            if (y == 0x80000000) {
                py = playerStatus->pos.y;
            } else {
                py = y;
            }

            px = playerStatus->pos.x;
            pz = playerStatus->pos.z;
            set_player_imgfx_comp(PLAYER_SPRITE_MAIN, -1, IMGFX_SET_ALPHA, 0, 0, 0, 64, 0);
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
            spriteIdx = PLAYER_SPRITE_MAIN | DRAW_SPRITE_UPSIDE_DOWN;
        } else {
            spriteIdx = PLAYER_SPRITE_MAIN;
        }

        spr_draw_player_sprite(spriteIdx, 0, 0, 0, mtx);
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

    raycastYaw = (yawTemp - 90.0f) + gCameras[gCurrentCameraID].curYaw;
    shadow->pos.x = playerX = playerStatus->pos.x;
    shadow->pos.z = playerZ = playerStatus->pos.z;
    x = playerX;
    y = playerStatus->pos.y + (playerStatus->colliderHeight / 3.5f);
    z = playerZ;
    shadowScale = 1024.0f;
    gCollisionStatus.floorBelow = player_raycast_below(raycastYaw, playerStatus->colliderDiameter, &x, &y, &z,
                                                       &shadowScale, &hitRx, &hitRz, &hitDirX, &hitDirZ);
    shadow->rot.x = hitRx;
    shadow->rot.z = hitRz;
    shadow->rot.y = clamp_angle(-camera->curYaw);
    hitRx += 180.0f;
    hitRz += 180.0f;

    if (hitRx != 0.0f || hitRz != 0.0f) {
        s32 dist = dist2D(x, z, playerStatus->pos.x, playerStatus->pos.z);
        f32 tan = atan2(playerStatus->pos.x, playerStatus->pos.z, x, z);
        s32 angleTemp = clamp_angle((-90.0f - tan) + get_player_normal_yaw());

        if (gGameStatusPtr->playerGroundTraceNormal.y != 0.0f) {
            y -= sqrtf(SQ(gGameStatusPtr->playerGroundTraceNormal.x) + SQ(gGameStatusPtr->playerGroundTraceNormal.z)) /
                       gGameStatusPtr->playerGroundTraceNormal.y * dist * sin_deg(angleTemp);
        }
    }

    shadow->pos.y = y;
    shadow->alpha = (f64)playerStatus->alpha1 / 2;

    if (!(gGameStatusPtr->peachFlags & PEACH_STATUS_FLAG_IS_PEACH)) {
        set_standard_shadow_scale(shadow, shadowScale);
    } else {
        set_peach_shadow_scale(shadow, shadowScale);
    }
}
