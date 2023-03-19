#include "common.h"
#include "../src/world/partners.h"
#include "sprite/npc/WorldKooper.h"

#define NAMESPACE world_kooper

s32 entity_try_partner_interaction_trigger(s32);
s32 test_item_entity_position(f32, f32, f32, f32);
s32 npc_raycast_up_corner(s32 ignoreFlags, f32* x, f32* y, f32* z, f32* length);
void fx_damage_stars(s32, f32, f32, f32, f32, f32, f32, s32);
void auto_collect_item_entity(s32);

BSS s32 N(ShellTossHoldTime);
BSS s32 N(TriggeredBattle);
BSS s32 N(PlayerWasFacingLeft);
BSS s32 N(D_802BEC5C);
BSS s32 N(ShellTossKickFalling);
BSS b32 N(LockingPlayerInput);
BSS s32 N(HeldItemIdx);
BSS s32 N(HasItem);
BSS f32 N(ShellTossPosX);
BSS f32 N(ShellTossPosY);
BSS f32 N(ShellTossPosZ);
BSS s32 D_802BEC7C; // padding?

enum {
    SHELL_TOSS_HITBOX_DISABLED      = 0,
    SHELL_TOSS_HITBOX_ENABLED       = 1,
    SHELL_TOSS_HITBOX_HIT_ENEMY     = 2,
};

s32 ShellTossHitboxState = SHELL_TOSS_HITBOX_DISABLED;

s32 N(lateral_hit_interactable_entity)(Npc* npc) {
    if (NpcHitQueryColliderID < 0) {
        return FALSE;
    }

    if (!(NpcHitQueryColliderID & COLLISION_WITH_ENTITY_BIT)) {
        return FALSE;
    }

    return entity_try_partner_interaction_trigger(NpcHitQueryColliderID & ~COLLISION_WITH_ENTITY_BIT);
}

void N(vertical_hit_interactable_entity)(Npc* kooper) {
    if (NpcHitQueryColliderID < 0) {
        return;
    }

    if (!(NpcHitQueryColliderID & COLLISION_WITH_ENTITY_BIT)) {
        return;
    }

    entity_try_partner_interaction_trigger(NpcHitQueryColliderID & ~COLLISION_WITH_ENTITY_BIT);
}

s32 N(check_for_item_collision)(Npc* kooper) {
    N(HeldItemIdx) = test_item_entity_position(kooper->pos.x, kooper->pos.y, kooper->pos.z, kooper->collisionRadius);

    if (N(HeldItemIdx) < 0) {
        return FALSE;
    }

    N(HasItem) = TRUE;
    gOverrideFlags |= GLOBAL_OVERRIDES_40;
    set_item_entity_flags(N(HeldItemIdx), ITEM_ENTITY_FLAG_CANT_COLLECT);
    return TRUE;
}

void N(init)(Npc* kooper) {
    kooper->collisionHeight = 37;
    kooper->collisionRadius = 24;
    kooper->collisionChannel = COLLISION_CHANNEL_10000;
    N(TriggeredBattle) = FALSE;
}

API_CALLABLE(N(TakeOut)) {
    Npc* kooper = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(kooper);
    }

    if (partner_get_out(kooper)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript EVS_WorldKooper_TakeOut = {
    EVT_CALL(N(TakeOut))
    EVT_RETURN
    EVT_END
};

BSS TweesterPhysics N(TweesterPhysicsData);
TweesterPhysics* N(TweesterPhysicsPtr) = &N(TweesterPhysicsData);

API_CALLABLE(N(Update)) {
    PlayerData* playerData = &gPlayerData;
    Npc* kooper = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_walking_enable(kooper, 1);
        mem_clear(N(TweesterPhysicsPtr), sizeof(TweesterPhysics));
        TweesterTouchingPartner = NULL;
    }

    playerData->partnerUsedTime[PARTNER_KOOPER]++;
    entity = TweesterTouchingPartner;

    if (entity == NULL) {
        partner_walking_update_player_tracking(kooper);
        partner_walking_update_motion(kooper);
        return ApiStatus_BLOCK;
    }

    switch (N(TweesterPhysicsPtr)->state) {
        case TWEESTER_PARTNER_INIT:
            N(TweesterPhysicsPtr)->state++;
            N(TweesterPhysicsPtr)->prevFlags = kooper->flags;
            N(TweesterPhysicsPtr)->radius = fabsf(dist2D(kooper->pos.x, kooper->pos.z,
                                                     entity->position.x, entity->position.z));
            N(TweesterPhysicsPtr)->angle = atan2(entity->position.x, entity->position.z, kooper->pos.x, kooper->pos.z);
            N(TweesterPhysicsPtr)->angularVelocity = 6.0f;
            N(TweesterPhysicsPtr)->liftoffVelocityPhase = 50.0f;
            N(TweesterPhysicsPtr)->countdown = 120;
            kooper->flags |= NPC_FLAG_IGNORE_CAMERA_FOR_YAW | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_8;
            kooper->flags &= ~NPC_FLAG_GRAVITY;
        case TWEESTER_PARTNER_ATTRACT:
            sin_cos_rad(DEG_TO_RAD(N(TweesterPhysicsPtr)->angle), &sinAngle, &cosAngle);

            kooper->pos.x = entity->position.x + (sinAngle * N(TweesterPhysicsPtr)->radius);
            kooper->pos.z = entity->position.z - (cosAngle * N(TweesterPhysicsPtr)->radius);

            N(TweesterPhysicsPtr)->angle = clamp_angle(N(TweesterPhysicsPtr)->angle - N(TweesterPhysicsPtr)->angularVelocity);
            if (N(TweesterPhysicsPtr)->radius > 20.0f) {
                N(TweesterPhysicsPtr)->radius--;
            } else if (N(TweesterPhysicsPtr)->radius < 19.0f) {
                N(TweesterPhysicsPtr)->radius++;
            }

            liftoffVelocity = sin_rad(DEG_TO_RAD(N(TweesterPhysicsPtr)->liftoffVelocityPhase)) * 3.0f;

            N(TweesterPhysicsPtr)->liftoffVelocityPhase += 3.0f;

            if (N(TweesterPhysicsPtr)->liftoffVelocityPhase > 150.0f) {
                N(TweesterPhysicsPtr)->liftoffVelocityPhase = 150.0f;
            }
            kooper->pos.y += liftoffVelocity;

            kooper->renderYaw = clamp_angle(360.0f - N(TweesterPhysicsPtr)->angle);
            N(TweesterPhysicsPtr)->angularVelocity += 0.8;
            if (N(TweesterPhysicsPtr)->angularVelocity > 40.0f) {
                N(TweesterPhysicsPtr)->angularVelocity = 40.0f;
            }

            if (--N(TweesterPhysicsPtr)->countdown == 0) {
                N(TweesterPhysicsPtr)->state++;
            }
            break;
        case TWEESTER_PARTNER_HOLD:
            kooper->flags = N(TweesterPhysicsPtr)->prevFlags;
            N(TweesterPhysicsPtr)->countdown = 30;
            N(TweesterPhysicsPtr)->state++;
            break;
        case TWEESTER_PARTNER_RELEASE:
            partner_walking_update_player_tracking(kooper);
            partner_walking_update_motion(kooper);

            if (--N(TweesterPhysicsPtr)->countdown == 0) {
                N(TweesterPhysicsPtr)->state = TWEESTER_PARTNER_INIT;
                TweesterTouchingPartner = NULL;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

void N(try_cancel_tweester)(Npc* kooper) {
    if (TweesterTouchingPartner != NULL) {
        TweesterTouchingPartner = NULL;
        kooper->flags = N(TweesterPhysicsPtr)->prevFlags;
        N(TweesterPhysicsPtr)->state = TWEESTER_PARTNER_INIT;
        partner_clear_player_tracking(kooper);
    }
}

EvtScript EVS_WorldKooper_Update = {
    EVT_CALL(N(Update))
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(UseAbility)) {
    Camera* cam;
    ItemEntity* heldItem;
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* kooper = script->owner2.npc;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    CollisionStatus* collisionStatus = &gCollisionStatus;
    f32 posX, posY, posZ, hitLength;
    f32 testLength;
    s32 actionState;
    f32 moveAngle;
    f32 colheight;
    f32 angleToStartPos;

    #define USE_STATE functionTemp[0]
    enum {
        SHELL_TOSS_STATE_BEGIN      = 20,
        SHELL_TOSS_STATE_GATHER     = 21,
        SHELL_TOSS_STATE_JUMP       = 2,
        SHELL_TOSS_STATE_KICK       = 3,
        SHELL_TOSS_STATE_PICKUP     = 4,
        SHELL_TOSS_STATE_HOLD       = 5,
        SHELL_TOSS_STATE_RETURN     = 7,
        SHELL_TOSS_STATE_FINISH     = 0,
    };

    if (currentEncounter->unk_08 != 0) {
        return ApiStatus_BLOCK;
    }

    if (isInitialCall) {
        N(try_cancel_tweester)(kooper);
        if (playerStatus->animFlags & PA_FLAG_CHANGING_MAP) {
            return ApiStatus_DONE2;
        }

        if (!N(TriggeredBattle)) {
            actionState = playerStatus->actionState;
            if (actionState == ACTION_STATE_IDLE
             || actionState == ACTION_STATE_WALK
             || actionState == ACTION_STATE_RUN
            ) {
                script->USE_STATE = SHELL_TOSS_STATE_BEGIN;
            } else {
                return ApiStatus_DONE2;
            }
        } else if (partnerStatus->partnerActionState == PARTNER_ACTION_NONE) {
            partnerStatus->partnerActionState = PARTNER_ACTION_KOOPER_GATHER;
            partnerStatus->actingPartner = PARTNER_KOOPER;
            script->USE_STATE = SHELL_TOSS_STATE_HOLD;
            kooper->currentAnim = ANIM_WorldKooper_SpinShell;
            N(ShellTossHoldTime) = 30;
        }
    }

    switch (script->USE_STATE) {
        case SHELL_TOSS_STATE_BEGIN:
            if (playerStatus->inputDisabledCount != 0
             || playerStatus->timeInAir != 0
             || !(kooper->flags & NPC_FLAG_GROUNDED)
            ) {
                return ApiStatus_DONE2;
            }

            disable_player_input();
            script->functionTemp[2] = playerStatus->inputDisabledCount;
            N(LockingPlayerInput) = TRUE;
            ShellTossHitboxState = SHELL_TOSS_HITBOX_DISABLED;
            N(HasItem) = FALSE;
            kooper->flags &= ~(NPC_FLAG_GRAVITY | NPC_FLAG_JUMPING | NPC_FLAG_8);
            kooper->flags |= (NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_WORLD_COLLISION);
            partnerStatus->actingPartner = PARTNER_KOOPER;
            partnerStatus->partnerActionState = PARTNER_ACTION_KOOPER_GATHER;
            N(PlayerWasFacingLeft) = partner_force_player_flip_done();
            enable_npc_blur(kooper);
            kooper->duration = 4;
            kooper->yaw = atan2(kooper->pos.x, kooper->pos.z,
                                playerStatus->position.x, playerStatus->position.z);
            script->USE_STATE++;
            break;

        case SHELL_TOSS_STATE_GATHER:
            if (playerStatus->actionState == ACTION_STATE_HIT_FIRE
             || playerStatus->actionState == ACTION_STATE_KNOCKBACK
             || playerStatus->actionState == ACTION_STATE_HIT_LAVA
             || playerStatus->timeInAir != 0
            ) {
                suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
                script->USE_STATE = SHELL_TOSS_STATE_FINISH;
                break;
            }

            suggest_player_anim_allow_backward(ANIM_Mario1_BeforeJump);
            kooper->moveToPos.x = N(ShellTossPosX) = playerStatus->position.x;
            kooper->moveToPos.y = N(ShellTossPosY) = playerStatus->position.y;
            kooper->moveToPos.z = N(ShellTossPosZ) = playerStatus->position.z;
            kooper->currentAnim = ANIM_WorldKooper_Run;
            add_vec2D_polar(&kooper->moveToPos.x, &kooper->moveToPos.z,
                            playerStatus->colliderDiameter / 3, playerStatus->targetYaw);
            moveAngle = clamp_angle(playerStatus->targetYaw + (N(PlayerWasFacingLeft) ? 90.0f : -90.0f));
            add_vec2D_polar(&kooper->moveToPos.x, &kooper->moveToPos.z,
                            playerStatus->colliderDiameter / 4, moveAngle);
            kooper->pos.x += (kooper->moveToPos.x - kooper->pos.x) / kooper->duration;
            kooper->pos.y += (kooper->moveToPos.y - kooper->pos.y) / kooper->duration;
            kooper->pos.z += (kooper->moveToPos.z - kooper->pos.z) / kooper->duration;

            kooper->duration--;
            if (kooper->duration != 0) {
                break;
            }

            disable_npc_blur(kooper);
            if (script->functionTemp[2] < playerStatus->inputDisabledCount) {
                if (!(playerStatus->animFlags & PA_FLAG_CHANGING_MAP)) {
                    suggest_player_anim_allow_backward(ANIM_Mario1_Idle);
                } else {
                    suggest_player_anim_allow_backward(ANIM_Mario1_Run);
                }
                script->USE_STATE = SHELL_TOSS_STATE_FINISH;
                break;
            }

            kooper->yaw = playerStatus->targetYaw;
            kooper->jumpVelocity = 18.0f;
            kooper->jumpScale = 3.0f;
            kooper->currentAnim = ANIM_WorldKooper_EnterShell;
            kooper->collisionHeight = 12;

            kooper->moveToPos.y = playerStatus->position.y;
            kooper->moveToPos.z = playerStatus->position.y + playerStatus->colliderHeight / 3;
            playerStatus->flags |= PS_FLAG_JUMPING;
            gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;

#if VERSION_PAL
            playerStatus->gravityIntegrator[0] = 0;
            playerStatus->gravityIntegrator[1] = 0;
            playerStatus->gravityIntegrator[2] = 0;
            playerStatus->gravityIntegrator[3] = 0;
#endif

            suggest_player_anim_allow_backward(ANIM_Mario1_Jump);
            N(ShellTossKickFalling) = FALSE;
            sfx_play_sound_at_npc(SOUND_JUMP_2081, SOUND_SPACE_MODE_0, NPC_PARTNER);
            script->USE_STATE = SHELL_TOSS_STATE_JUMP;
            // fallthrough

        case SHELL_TOSS_STATE_JUMP:
            if (playerStatus->actionState == ACTION_STATE_HIT_FIRE
             || playerStatus->actionState == ACTION_STATE_KNOCKBACK
             || playerStatus->actionState == ACTION_STATE_HIT_LAVA
            ) {
                script->USE_STATE = SHELL_TOSS_STATE_FINISH;
                break;
            }

            kooper->jumpVelocity -= kooper->jumpScale;
            playerStatus->position.y += kooper->jumpVelocity;
            if (kooper->jumpVelocity < 0.0f) {
                if (!N(ShellTossKickFalling)) {
                    N(ShellTossKickFalling) = TRUE;
                    suggest_player_anim_allow_backward(ANIM_Mario1_Fall);
                }
            }

            posX = playerStatus->position.x;
            posY = (playerStatus->position.y + playerStatus->colliderHeight / 2) - kooper->jumpVelocity;
            posZ = playerStatus->position.z;
            testLength = hitLength = playerStatus->colliderHeight / 2;

            if ((npc_raycast_up(COLLISION_CHANNEL_10000, &posX, &posY, &posZ, &hitLength)) && (hitLength < testLength)) {
                collisionStatus->currentCeiling = NpcHitQueryColliderID;
                playerStatus->position.y = posY - playerStatus->colliderHeight;
                N(vertical_hit_interactable_entity)(kooper);
            }

            if (!(kooper->jumpVelocity > 0.0f) && (playerStatus->position.y < kooper->moveToPos.z)) {
                N(D_802BEC5C) = 0;
                kooper->flags &= ~NPC_FLAG_IGNORE_PLAYER_COLLISION;
                partnerStatus->actingPartner = PARTNER_KOOPER;
                partnerStatus->partnerActionState = PARTNER_ACTION_KOOPER_TOSS;
                kooper->rotation.z = 0.0f;
                kooper->planarFlyDist = 0.0f;
                kooper->moveSpeed = 8.0f;
                kooper->currentAnim = ANIM_WorldKooper_SpinShell;
                ShellTossHitboxState = SHELL_TOSS_HITBOX_ENABLED;
                fx_damage_stars(3, kooper->pos.x, kooper->pos.y + kooper->collisionHeight, kooper->pos.z,
                        sin_deg(playerStatus->targetYaw), -1.0f, -cos_deg(playerStatus->targetYaw), 3);
                start_bounce_b();

                if (N(LockingPlayerInput)) {
                    enable_player_input();
                    N(LockingPlayerInput) = FALSE;
                }

                script->USE_STATE = SHELL_TOSS_STATE_KICK;
                N(ShellTossKickFalling) = FALSE;
                gCameras[CAM_DEFAULT].moveFlags |= CAMERA_MOVE_IGNORE_PLAYER_Y;
                sfx_play_sound_at_npc(SOUND_283, SOUND_SPACE_MODE_0, NPC_PARTNER);
                sfx_play_sound_at_npc(SOUND_284, SOUND_SPACE_MODE_0, NPC_PARTNER);
            }
            break;

        case SHELL_TOSS_STATE_KICK:
            if (playerStatus->actionState == ACTION_STATE_HIT_FIRE
             || playerStatus->actionState == ACTION_STATE_KNOCKBACK
            ) {
                script->USE_STATE = SHELL_TOSS_STATE_FINISH;
                break;
            }

            // check the forward collision for kooper
            #define TEST_COLLISION_AT_ANGLE(testAngle) \
                ( \
                posX = kooper->pos.x, \
                posY = kooper->pos.y, \
                posZ = kooper->pos.z, \
                npc_test_move_taller_with_slipping(COLLISION_CHANNEL_8000, \
                    &posX, &posY, &posZ, kooper->moveSpeed, testAngle,  \
                    kooper->collisionHeight, kooper->collisionRadius / 2) \
                )

            if (TEST_COLLISION_AT_ANGLE(kooper->yaw - 20.0f)) {
                if (!N(lateral_hit_interactable_entity)(kooper)) {
                    sfx_play_sound_at_npc(SOUND_IMMUNE, SOUND_SPACE_MODE_0, NPC_PARTNER);
                }

                fx_damage_stars(3, kooper->pos.x, kooper->pos.y + kooper->collisionHeight, kooper->pos.z,
                        sin_deg(kooper->yaw), -1.0f, -cos_deg(kooper->yaw), 1);
                sfx_play_sound_at_npc(SOUND_0, SOUND_SPACE_MODE_0, NPC_PARTNER);
                script->USE_STATE = SHELL_TOSS_STATE_RETURN;
                break;
            }

            if (TEST_COLLISION_AT_ANGLE(kooper->yaw + 20.0f)) {
                if (!N(lateral_hit_interactable_entity)(kooper)) {
                    sfx_play_sound_at_npc(SOUND_IMMUNE, SOUND_SPACE_MODE_0, NPC_PARTNER);
                }

                fx_damage_stars(3, kooper->pos.x, kooper->pos.y + kooper->collisionHeight, kooper->pos.z,
                        sin_deg(kooper->yaw), -1.0f, -cos_deg(kooper->yaw), 1);
                sfx_play_sound_at_npc(SOUND_0, SOUND_SPACE_MODE_0, NPC_PARTNER);
                script->USE_STATE = SHELL_TOSS_STATE_RETURN;
                break;
            }

             if (TEST_COLLISION_AT_ANGLE(kooper->yaw)) {
                if (!N(lateral_hit_interactable_entity)(kooper)) {
                    sfx_play_sound_at_npc(SOUND_IMMUNE, SOUND_SPACE_MODE_0, NPC_PARTNER);
                }

                fx_damage_stars(3, kooper->pos.x, kooper->pos.y + kooper->collisionHeight, kooper->pos.z,
                        sin_deg(kooper->yaw), -1.0f, -cos_deg(kooper->yaw), 1);
                sfx_play_sound_at_npc(SOUND_0, SOUND_SPACE_MODE_0, NPC_PARTNER);
                script->USE_STATE = SHELL_TOSS_STATE_RETURN;
                break;
            }
            
            kooper->pos.x = posX;
            kooper->pos.y = posY;
            kooper->pos.z = posZ;
            kooper->planarFlyDist += kooper->moveSpeed;
            spawn_surface_effects(kooper, SURFACE_INTERACT_RUN);

            kooper->moveSpeed += 2.0;
            if (kooper->moveSpeed > 14.0) {
                kooper->moveSpeed = 14.0f;
            }

            if (!(npc_try_snap_to_ground(kooper, 6.0f) || playerStatus->flags & (PS_FLAG_JUMPING | PS_FLAG_FALLING))) {
                kooper->pos.y += (playerStatus->position.y - kooper->pos.y) / 10.0f;
            }

            npc_do_other_npc_collision(kooper);

            if ((kooper->flags & NPC_FLAG_COLLIDING_WITH_NPC)) {
                script->USE_STATE = SHELL_TOSS_STATE_RETURN;
                kooper->moveSpeed = 0.0f;
                sfx_play_sound_at_npc(SOUND_0, SOUND_SPACE_MODE_0, NPC_PARTNER);
                break;
            }

            if (N(check_for_item_collision)(kooper)) {
                sfx_play_sound_at_npc(SOUND_286, SOUND_SPACE_MODE_0, NPC_PARTNER);
                fx_damage_stars(3, kooper->pos.x, kooper->pos.y + kooper->collisionHeight, kooper->pos.z,
                    sin_deg(kooper->yaw), -1.0f, -cos_deg(kooper->yaw), 1);
                sfx_play_sound_at_npc(SOUND_0, SOUND_SPACE_MODE_0, NPC_PARTNER);
                script->USE_STATE = SHELL_TOSS_STATE_PICKUP;
                N(ShellTossHoldTime) = 8;
                kooper->moveSpeed -= 4.0;
                if (kooper->moveSpeed < 0.01) {
                    kooper->moveSpeed = 0.01f;
                    kooper->planarFlyDist += 1.0;
                }
            } else if (ShellTossHitboxState == SHELL_TOSS_HITBOX_HIT_ENEMY) {
                sfx_play_sound_at_npc(SOUND_0, SOUND_SPACE_MODE_0, NPC_PARTNER);
                script->USE_STATE = SHELL_TOSS_STATE_HOLD;
                N(ShellTossHoldTime) = 30;
                kooper->moveSpeed = 0.0f;
            } else {
                if (kooper->planarFlyDist > 140.0f) {
                    label2:
                    script->USE_STATE = SHELL_TOSS_STATE_RETURN;
                    kooper->moveSpeed = 0.0f;
                    sfx_play_sound_at_npc(SOUND_0, SOUND_SPACE_MODE_0, NPC_PARTNER);
                } else if (kooper->planarFlyDist > 105.0f) {
                    kooper->moveSpeed -= 4.0;
                    if (kooper->moveSpeed < 0.01) {
                        kooper->moveSpeed = 0.01f;
                        kooper->planarFlyDist += 1.0;
                    }
                }
            }    
            break;

        case SHELL_TOSS_STATE_PICKUP:
            posX = kooper->pos.x;
            posY = kooper->pos.y;
            posZ = kooper->pos.z;

            npc_test_move_taller_with_slipping(COLLISION_CHANNEL_8000,
                &posX, &posY, &posZ, kooper->moveSpeed, kooper->yaw,
                kooper->collisionHeight, ( kooper->collisionRadius / 2));
                
            kooper->pos.x = posX;
            kooper->pos.y = posY;
            kooper->pos.z = posZ;

            kooper->planarFlyDist += kooper->moveSpeed;
            spawn_surface_effects(kooper, SURFACE_INTERACT_RUN);
            kooper->moveSpeed -= 6.0;

            if (kooper->moveSpeed < 0.01) {
                kooper->moveSpeed = 0.01f;
                kooper->planarFlyDist += 1.0;
            }

            if (N(ShellTossHoldTime) == 0) {
                script->USE_STATE = SHELL_TOSS_STATE_RETURN;
            }
            N(ShellTossHoldTime)--;
            break;

        case SHELL_TOSS_STATE_HOLD:
            if (N(ShellTossHoldTime) != 0) {
                N(ShellTossHoldTime)--;
            } else {
                script->USE_STATE = SHELL_TOSS_STATE_RETURN;
            }
            break;
        }

    if (script->USE_STATE == SHELL_TOSS_STATE_RETURN) {
        kooper->flags |= NPC_FLAG_IGNORE_PLAYER_COLLISION;
        if (playerStatus->actionState == ACTION_STATE_HIT_FIRE
            || playerStatus->actionState == ACTION_STATE_KNOCKBACK
        ) {
            script->USE_STATE = SHELL_TOSS_STATE_FINISH;
        } else {
            angleToStartPos = atan2(N(ShellTossPosX), N(ShellTossPosZ), kooper->pos.x, kooper->pos.z);
            kooper->yaw = angleToStartPos + get_clamped_angle_diff(kooper->yaw, angleToStartPos) * 0.125f;
            npc_move_heading(kooper, -kooper->moveSpeed, kooper->yaw);
            kooper->planarFlyDist -= kooper->moveSpeed;
            spawn_surface_effects(kooper, SURFACE_INTERACT_RUN);
            kooper->moveSpeed += 4.0/3.0;

            if (kooper->moveSpeed > 14.0) {
                kooper->moveSpeed = 14.0f;
            }

            if (npc_try_snap_to_ground(kooper, 6.0f) == 0) {
                kooper->pos.y += (playerStatus->position.y - kooper->pos.y) / 10.0f;
            }

            posX = kooper->pos.x;
            posY = kooper->pos.y;
            posZ = kooper->pos.z;

            if (npc_test_move_taller_with_slipping(COLLISION_CHANNEL_8000,
                &posX, &posY, &posZ, kooper->moveSpeed, clamp_angle(kooper->yaw + 180.0f),
                kooper->collisionHeight, kooper->collisionRadius)
            ) {
                kooper->pos.x = posX;
                kooper->pos.y = posY;
                kooper->pos.z = posZ;
                sfx_play_sound_at_npc(SOUND_IMMUNE, SOUND_SPACE_MODE_0, NPC_PARTNER);
                testLength = sin_deg(kooper->yaw + 180.0f);
                fx_damage_stars(3, kooper->pos.x, kooper->pos.y + kooper->collisionHeight, kooper->pos.z,
                        testLength, -1.0f, -cos_deg(kooper->yaw + 180.0f), 1);
                script->USE_STATE = SHELL_TOSS_STATE_FINISH;
            } else {
                if (N(HasItem)) {
                    heldItem = get_item_entity(N(HeldItemIdx));
                    posX = kooper->pos.x;
                    posY = kooper->pos.y + 8.0f;
                    posZ = kooper->pos.z;

                    moveAngle = clamp_angle(playerStatus->targetYaw - (N(PlayerWasFacingLeft) ? 90.0f : -90.0f));

                    add_vec2D_polar(&posX, &posZ, 4.0f, moveAngle);
                    heldItem->position.x = posX;
                    heldItem->position.y = posY;
                    heldItem->position.z = posZ;
                }

                if (kooper->planarFlyDist + 15.0f < kooper->moveSpeed) {
                    script->USE_STATE = SHELL_TOSS_STATE_FINISH;
                } else if (kooper->planarFlyDist + 15.0f < 35.0f) {
                    kooper->moveSpeed -= 4.0;
                    if (kooper->moveSpeed < 4.0) {
                        kooper->moveSpeed = 4.0;
                    }
                }
            }
        }
    }

    if (script->USE_STATE == SHELL_TOSS_STATE_FINISH) {
        if (N(LockingPlayerInput)) {
            enable_player_input();
            N(LockingPlayerInput) = FALSE;
        }

        ShellTossHitboxState = SHELL_TOSS_HITBOX_DISABLED;
        kooper->flags |= NPC_FLAG_IGNORE_PLAYER_COLLISION;
        kooper->flags &= ~(NPC_FLAG_JUMPING | NPC_FLAG_IGNORE_WORLD_COLLISION);
        partnerStatus->actingPartner = PARTNER_NONE;
        partnerStatus->partnerActionState = PARTNER_ACTION_NONE;
        kooper->jumpVelocity = 0.0f;
        kooper->collisionHeight = 24;
        kooper->currentAnim = ANIM_WorldKooper_Walk;
        sfx_stop_sound(SOUND_284);
        disable_npc_blur(kooper);

        if (N(HasItem)) {
            auto_collect_item_entity(N(HeldItemIdx));
            N(HasItem) = FALSE;
        }

        N(TriggeredBattle) = FALSE;
        partner_clear_player_tracking(kooper);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

EvtScript EVS_WorldKooper_UseAbility = {
    EVT_CALL(N(UseAbility))
    EVT_RETURN
    EVT_END
};

API_CALLABLE(N(PutAway)) {
    Npc* kooper = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(kooper);
    }

    return partner_put_away(kooper) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript EVS_WorldKooper_PutAway = {
    EVT_CALL(N(PutAway))
    EVT_RETURN
    EVT_END
};

s32 N(test_first_strike)(Npc* kooper, Npc* enemy) {
    f32 xTemp, yTemp, zTemp;
    f32 enemyX, enemyY, enemyZ;
    f32 kooperX;
    f32 kooperZ;
    f32 enemyCollHeight;
    f32 kooperY;
    f32 kooperCollHeight;
    f32 enemyCollRadius;
    f32 kooperCollRadius;
    f32 angleToEnemy;
    f32 distToEnemy;

    if (ShellTossHitboxState != SHELL_TOSS_HITBOX_DISABLED) {
        enemyX = enemy->pos.x;
        enemyY = enemy->pos.y;
        enemyZ = enemy->pos.z;

        kooperX = kooper->pos.x;
        kooperY = kooper->pos.y;
        kooperZ = kooper->pos.z;

        enemyCollHeight = enemy->collisionHeight;
        enemyCollRadius = enemy->collisionRadius * 0.55;

        kooperCollHeight = kooper->collisionHeight;
        kooperCollRadius = kooper->collisionRadius * 0.8;

        angleToEnemy = atan2(enemyX, enemyZ, kooperX, kooperZ);
        distToEnemy = dist2D(enemyX, enemyZ, kooperX, kooperZ);

        xTemp = kooper->pos.x;
        yTemp = kooper->pos.y;
        zTemp = kooper->pos.z;

        if (npc_test_move_taller_with_slipping(0, &xTemp, &yTemp, &zTemp, distToEnemy, angleToEnemy,
            kooperCollHeight, kooperCollRadius + enemyCollRadius)
        ) {
            return FALSE;
        }

        if (kooperY > enemyY + enemyCollHeight) {
            return FALSE;
        }

        if (enemyY > kooperY + kooperCollHeight) {
            return FALSE;
        }

        kooperX = enemyX - kooperX;
        kooperZ = enemyZ - kooperZ;
        distToEnemy = SQ(kooperX) + SQ(kooperZ);

        if (!(SQ(kooperCollRadius) + SQ(enemyCollRadius) <= distToEnemy)) {
            ShellTossHitboxState = SHELL_TOSS_HITBOX_HIT_ENEMY;
            return TRUE;
        }
    }
    return FALSE;
}

void N(pre_battle)(Npc* kooper) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PartnerStatus* partnerStatus = &gPartnerStatus;
    N(TriggeredBattle) = FALSE;

    if (partnerStatus->partnerActionState != PARTNER_ACTION_NONE) {
        if (partnerStatus->partnerActionState == PARTNER_ACTION_KOOPER_TOSS) {
            N(TriggeredBattle) = TRUE;
        }

        if (N(LockingPlayerInput)) {
            enable_player_input();
            N(LockingPlayerInput) = FALSE;
        }

        ShellTossHitboxState = SHELL_TOSS_HITBOX_DISABLED;
        playerStatus->flags &= ~PS_FLAG_JUMPING;

        kooper->jumpVelocity = 0.0f;
        kooper->flags &= ~NPC_FLAG_JUMPING;
        kooper->flags &= ~NPC_FLAG_IGNORE_WORLD_COLLISION;

        sfx_stop_sound(SOUND_284);
        set_action_state(ACTION_STATE_IDLE);
        partner_clear_player_tracking(kooper);
        disable_npc_blur(kooper);

        partnerStatus->actingPartner = PARTNER_NONE;
        partnerStatus->partnerActionState = PARTNER_ACTION_NONE;
    }
}

void N(post_battle)(Npc* npc) {
    if (N(TriggeredBattle)) {
        partner_clear_player_tracking(npc);
        partner_use_ability();
    }
}
