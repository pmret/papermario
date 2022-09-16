#include "common.h"
#include "../src/world/partners.h"
#include "npc.h"
#include "effects.h"

extern s16 D_8010C97A;

void partner_kill_ability_script(void);

BSS f32 D_802BFEE0;
BSS s32 bss_802BFEE4;
BSS s32 bss_802BFEE8;
BSS s32 D_802BFEEC;
BSS s32 bss_802BFEF0;
BSS s32 bss_802BFEF4;
BSS s32 D_802BFEF8;
BSS f32 bss_802BFEFC;
BSS s32 bss_802BFF00;
BSS s32 bss_802BFF04;
BSS s32 bss_802BFF08;
BSS s32 bss_802BFF0C;
BSS TweesterPhysics SushieTweesterPhysics;


f32 D_802BFDB0_320B20 = 0.0f;
f32 D_802BFDB4_320B24 = 0.0f;
f32 D_802BFDB8_320B28 = 0.0f;
f32 D_802BFDBC_320B2C = 0.0f;


void func_802BD100_31DE70(void) {
    Npc* partnerNPC = get_npc_unsafe(NPC_PARTNER);
    PlayerStatus* playerStatus = &gPlayerStatus;
    Camera* cam = &gCameras[CAM_DEFAULT];
    s32 phi_v1;

    playerStatus->position.x = partnerNPC->pos.x;
    playerStatus->position.y = partnerNPC->pos.y + 16.0f;
    playerStatus->position.z = partnerNPC->pos.z;
    playerStatus->targetYaw = partnerNPC->yaw;

    if (playerStatus->spriteFacingAngle < 90.0f || playerStatus->spriteFacingAngle > 270.0f) {
        phi_v1 = -8;
    } else {
        phi_v1 = 8;
    }

    playerStatus->position.z -= cos_rad(DEG_TO_RAD(
        cam->currentYaw + playerStatus->spriteFacingAngle - 90.0f + phi_v1)) * -4.0f;
}

void func_802BD20C_31DF7C(f32* arg0, f32* arg1) {
    f32 temp_f22;
    f32 phi_f20;
    f32 temp_f2 = gPartnerActionStatus.stickY;
    f32 temp_f0 = gPartnerActionStatus.stickX;

    D_802BFDB0_320B20 = temp_f0;
    D_802BFDB4_320B24 = temp_f2;
    temp_f22 = clamp_angle(atan2(0.0f, 0.0f, temp_f0, -temp_f2) + gCameras[CAM_DEFAULT].currentYaw);
    phi_f20 = 0.0f;

    if (dist2D(0.0f, 0.0f, D_802BFDB0_320B20, -D_802BFDB4_320B24) >= 1.0) {
        if (SQ(D_802BFDB0_320B20) + SQ(D_802BFDB4_320B24) > 3025.0f) {
            if (bss_802BFEE4) {
                phi_f20 = 2.0f;
            } else {
                phi_f20 = 4.0f;
            }
        } else {
            phi_f20 = 2.0f;
        }
    }

    *arg0 = temp_f22;
    *arg1 = phi_f20;
}

void func_802BD368_31E0D8(s32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5) {
    CollisionStatus* collisionStatus = &gCollisionStatus;
    f32 sp20;

    arg2 += 100.0f;
    sp20 = 200.0f;

    if (npc_raycast_down_around(arg0, &arg1, &arg2, &arg3, &sp20, arg4, arg5) == 0) {
        collisionStatus->currentFloor = -1;
    } else {
        collisionStatus->currentFloor = D_8010C97A;
        D_802BFEE0 = arg2;
    }
}

INCLUDE_ASM(s32, "world/partner/sushie", func_802BD414_31E184);

s32 func_802BE280_31EFF0(s32 arg0, f32* x, f32* y, f32* z, f32 length, f32 radius, f32* yaw) {
    f32 sinAngle, cosAngle, hitX, hitY, hitZ, totalLength, hitNx, hitNy, hitNz;
    s32 hitResult;

    sin_cos_rad(DEG_TO_RAD(*yaw), &sinAngle, &cosAngle);
    cosAngle = -cosAngle;
    totalLength = radius + length;
    hitResult = test_ray_colliders(0x10000, *x, *y, *z, sinAngle, 0.0f, cosAngle, &hitX, &hitY, &hitZ, &totalLength, &hitNx, &hitNy, &hitNz);

    if (hitResult >= 0) {
        *yaw = atan2(0.0f, 0.0f, hitNx, hitNz);
    }

    return hitResult;
}

void func_802BE3A4_31F114(Npc*);
INCLUDE_ASM(s32, "world/partner/sushie", func_802BE3A4_31F114);

EvtScript world_sushie_use_ability = {
    EVT_CALL(func_802BE3A4_31F114)
    EVT_RETURN
    EVT_END
};

void world_sushie_init(Npc* sushie) {
    sushie->collisionHeight = 24;
    sushie->collisionRadius = 36;
    sushie->collisionChannel = 0x10000;
    D_802BFEEC = 0;
    bss_802BFEE4 = 0;
    bss_802BFEE8 = 0;
    bss_802BFEF0 = 0;
    bss_802BFEF4 = 0;
}

s32 SushieTakeOut(Evt* script, s32 isInitialCall) {
    Npc* sushie = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(sushie);
    }

    return partner_get_out(sushie) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_sushie_take_out = {
    EVT_CALL(SushieTakeOut)
    EVT_RETURN
    EVT_END
};

TweesterPhysics* SushieTweesterPhysicsPtr = &SushieTweesterPhysics;

ApiStatus SushieUpdate(Evt* script, s32 isInitialCall) {
    Npc* sushie = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_walking_enable(sushie, 1);
        mem_clear(SushieTweesterPhysicsPtr, sizeof(TweesterPhysics));
        TweesterTouchingPartner = NULL;
    }

    entity = TweesterTouchingPartner;

    if (entity == NULL) {
        partner_walking_update_player_tracking(sushie);
        partner_walking_update_motion(sushie);
        return ApiStatus_BLOCK;
    }

    switch (SushieTweesterPhysicsPtr->state) {
        case 0:
            SushieTweesterPhysicsPtr->state = 1;
            SushieTweesterPhysicsPtr->prevFlags = sushie->flags;
            SushieTweesterPhysicsPtr->radius = fabsf(dist2D(sushie->pos.x, sushie->pos.z,
                                                     entity->position.x, entity->position.z));
            SushieTweesterPhysicsPtr->angle = atan2(entity->position.x, entity->position.z, sushie->pos.x, sushie->pos.z);
            SushieTweesterPhysicsPtr->angularVelocity = 6.0f;
            SushieTweesterPhysicsPtr->liftoffVelocityPhase = 50.0f;
            SushieTweesterPhysicsPtr->countdown = 120;
            sushie->flags |= NPC_FLAG_40000 | NPC_FLAG_100 | NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT;
            sushie->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad(DEG_TO_RAD(SushieTweesterPhysicsPtr->angle), &sinAngle, &cosAngle);
            sushie->pos.x = entity->position.x + (sinAngle * SushieTweesterPhysicsPtr->radius);
            sushie->pos.z = entity->position.z - (cosAngle * SushieTweesterPhysicsPtr->radius);
            SushieTweesterPhysicsPtr->angle = clamp_angle(SushieTweesterPhysicsPtr->angle - SushieTweesterPhysicsPtr->angularVelocity);

            if (SushieTweesterPhysicsPtr->radius > 20.0f) {
                SushieTweesterPhysicsPtr->radius--;
            } else if (SushieTweesterPhysicsPtr->radius < 19.0f) {
                SushieTweesterPhysicsPtr->radius++;
            }

            liftoffVelocity = sin_rad(DEG_TO_RAD(SushieTweesterPhysicsPtr->liftoffVelocityPhase)) * 3.0f;
            SushieTweesterPhysicsPtr->liftoffVelocityPhase += 3.0f;

            if (SushieTweesterPhysicsPtr->liftoffVelocityPhase > 150.0f) {
                SushieTweesterPhysicsPtr->liftoffVelocityPhase = 150.0f;
            }

            sushie->pos.y += liftoffVelocity;
            sushie->renderYaw = clamp_angle(360.0f - SushieTweesterPhysicsPtr->angle);
            SushieTweesterPhysicsPtr->angularVelocity += 0.8;

            if (SushieTweesterPhysicsPtr->angularVelocity > 40.0f) {
                SushieTweesterPhysicsPtr->angularVelocity = 40.0f;
            }

            if (--SushieTweesterPhysicsPtr->countdown == 0) {
                SushieTweesterPhysicsPtr->state++;
            }
            break;
        case 2:
            sushie->flags = SushieTweesterPhysicsPtr->prevFlags;
            SushieTweesterPhysicsPtr->countdown = 30;
            SushieTweesterPhysicsPtr->state++;
            break;
        case 3:
            partner_walking_update_player_tracking(sushie);
            partner_walking_update_motion(sushie);

            if (--SushieTweesterPhysicsPtr->countdown == 0) {
                SushieTweesterPhysicsPtr->state = 0;
                TweesterTouchingPartner = NULL;
            }
            break;
    }

    return ApiStatus_BLOCK;
}

EvtScript world_sushie_update = {
    EVT_CALL(SushieUpdate)
    EVT_RETURN
    EVT_END
};

void func_802BF920_320690(Npc* sushie) {
    if (TweesterTouchingPartner != NULL) {
        TweesterTouchingPartner = NULL;
        sushie->flags = SushieTweesterPhysicsPtr->prevFlags;
        SushieTweesterPhysicsPtr->state = 0;
        partner_clear_player_tracking(sushie);
    }
}

s32 SushiePutAway(Evt* script, s32 isInitialCall) {
    Npc* sushie = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(sushie);
        gPlayerStatusPtr->animFlags &= ~PA_FLAGS_400000;
    }

    return partner_put_away(sushie) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_sushie_put_away = {
    EVT_CALL(SushiePutAway)
    EVT_RETURN
    EVT_END
};

void world_sushie_pre_battle(Npc* sushie) {
    PartnerActionStatus* sushieActionStatus = &gPartnerActionStatus;

    if (D_802BFEEC) {
        sushieActionStatus->npc = *sushie;
        sushieActionStatus->partnerAction_unk_1 = 1;
        enable_player_static_collisions();
        enable_player_input();
        set_action_state(ACTION_STATE_IDLE);
        partner_clear_player_tracking(sushie);
    }

    sushieActionStatus->actingPartner = PARTNER_SUSHIE;
}

void world_sushie_post_battle(Npc* sushie) {
    PartnerActionStatus* sushieActionStatus = &gPartnerActionStatus;

    if (sushieActionStatus->partnerAction_unk_1 != 0) {
        *sushie = sushieActionStatus->npc;
        partner_use_ability();
    }
}

s32 func_802BFAB8_320828(Evt* script, s32 isInitialCall) {
    Npc* partnerNPC = get_npc_unsafe(NPC_PARTNER);
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 temp_f0;
    s32 funcTemp0;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        D_802BFEE0 = playerStatus->position.y;
    }

    funcTemp0 = script->functionTemp[0];

    switch (funcTemp0) {
        case 0:
            gGameStatusPtr->keepUsingPartnerOnMapChange = 1;
            disable_player_static_collisions();
            disable_player_input();
            partnerNPC->pos.x = playerStatus->position.x;
            partnerNPC->pos.z = playerStatus->position.z;
            partnerNPC->pos.y = playerStatus->position.y;
            func_802BD368_31E0D8(partnerNPC->collisionChannel, partnerNPC->pos.x, partnerNPC->pos.y, partnerNPC->pos.z,
                                partnerNPC->yaw, partnerNPC->collisionRadius * 0.5f);
            partnerNPC->pos.y = D_802BFEE0 - (partnerNPC->collisionHeight * 0.5f);
            temp_f0 = atan2(partnerNPC->pos.x, partnerNPC->pos.z, script->varTable[1], script->varTable[3]);
            partnerNPC->currentAnim = 0x7000A;
            partnerNPC->yaw = temp_f0;
            partnerNPC->jumpScale = 0.0f;
            partnerNPC->moveSpeed = 3.0f;
            partnerNPC->moveToPos.x = partnerNPC->pos.x;
            partnerNPC->moveToPos.y = partnerNPC->pos.y;
            partnerNPC->moveToPos.z = partnerNPC->pos.z;
            partnerNPC->flags |= NPC_FLAG_100 | NPC_FLAG_ENABLE_HIT_SCRIPT;
            partnerNPC->flags &= ~NPC_FLAG_GRAVITY;
            disable_npc_shadow(partnerNPC);
            disable_player_shadow();

            if (script->varTable[12] == 0) {
                partner_kill_ability_script();
            } else {
                suggest_player_anim_setUnkFlag(ANIM_Mario_8000F);
                if ((partnerNPC->yaw >= 0.0f) && (partnerNPC->yaw <= 180.0f)) {
                    partnerNPC->yawCamOffset = partnerNPC->yaw;
                    partnerNPC->isFacingAway = 1;
                }
            }

            script->functionTemp[1] = 0x19;
            script->functionTemp[0] = 1;
            break;
        case 1:
            npc_move_heading(partnerNPC, partnerNPC->moveSpeed, partnerNPC->yaw);
            func_802BD100_31DE70();

            if (!(script->functionTemp[1] & 3)) {
                fx_rising_bubble(0, partnerNPC->pos.x, partnerNPC->moveToPos.y +
                        (partnerNPC->collisionHeight * 0.5f), partnerNPC->pos.z, 0);
            }

            script->functionTemp[1]--;
            if (script->functionTemp[1] == 0) {
                if (script->varTable[12] == funcTemp0) {
                    set_action_state(ACTION_STATE_RIDE);
                    partner_use_ability();
                    return ApiStatus_DONE2;
                }

                enable_player_static_collisions();
                enable_player_input();
                return ApiStatus_DONE2;
            }

            break;
    }

    return ApiStatus_BLOCK;
}

EvtScript world_sushie_while_riding = {
    EVT_CALL(func_802BFAB8_320828)
    EVT_RETURN
    EVT_END
};
