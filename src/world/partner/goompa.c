#include "common.h"
#include "goompa.h"
#include "../src/world/partners.h"

#define NAMESPACE world_goompa

void N(init)(Npc* partner) {
    partner->collisionHeight = 24;
    partner->collisionDiameter = 20;
}

API_CALLABLE(N(TakeOut)) {
    Npc* goompa = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(goompa);
    }

    if (partner_get_out(goompa)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript EVS_WorldGoompa_TakeOut = {
    Call(N(TakeOut))
    Return
    End
};

BSS TweesterPhysics N(TweesterPhysicsData);
TweesterPhysics* N(TweesterPhysicsPtr) = &N(TweesterPhysicsData);

API_CALLABLE(N(Update)) {
    PlayerData* playerData = &gPlayerData;
    Npc* goompa = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_walking_enable(goompa, 1);
        mem_clear(N(TweesterPhysicsPtr), sizeof(TweesterPhysics));
        TweesterTouchingPartner = nullptr;
    }

    playerData->partnerUsedTime[PARTNER_GOOMPA]++;
    entity = TweesterTouchingPartner;

    if (entity == nullptr) {
        partner_walking_update_player_tracking(goompa);
        partner_walking_update_motion(goompa);
        return ApiStatus_BLOCK;
    }

    switch (N(TweesterPhysicsPtr)->state) {
        case TWEESTER_PARTNER_INIT:
            N(TweesterPhysicsPtr)->state++;
            N(TweesterPhysicsPtr)->prevFlags = goompa->flags;
            N(TweesterPhysicsPtr)->radius = fabsf(dist2D(goompa->pos.x, goompa->pos.z,
                                                    entity->pos.x, entity->pos.z));
            N(TweesterPhysicsPtr)->angle = atan2(entity->pos.x, entity->pos.z, goompa->pos.x, goompa->pos.z);
            N(TweesterPhysicsPtr)->angularVel = 6.0f;
            N(TweesterPhysicsPtr)->liftoffVelPhase = 50.0f;
            N(TweesterPhysicsPtr)->countdown = 120;
            goompa->flags |= NPC_FLAG_FLYING | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_CAMERA_FOR_YAW;
            goompa->flags &= ~NPC_FLAG_GRAVITY;
        case TWEESTER_PARTNER_ATTRACT:
            sin_cos_rad(DEG_TO_RAD(N(TweesterPhysicsPtr)->angle), &sinAngle, &cosAngle);
            goompa->pos.x = entity->pos.x + (sinAngle * N(TweesterPhysicsPtr)->radius);
            goompa->pos.z = entity->pos.z - (cosAngle * N(TweesterPhysicsPtr)->radius);
            N(TweesterPhysicsPtr)->angle = clamp_angle(N(TweesterPhysicsPtr)->angle - N(TweesterPhysicsPtr)->angularVel);

            if (N(TweesterPhysicsPtr)->radius > 20.0f) {
                N(TweesterPhysicsPtr)->radius--;
            } else if (N(TweesterPhysicsPtr)->radius < 19.0f) {
                N(TweesterPhysicsPtr)->radius++;
            }

            liftoffVelocity = sin_rad(DEG_TO_RAD(N(TweesterPhysicsPtr)->liftoffVelPhase)) * 3.0f;
            N(TweesterPhysicsPtr)->liftoffVelPhase += 3.0f;

            if (N(TweesterPhysicsPtr)->liftoffVelPhase > 150.0f) {
                N(TweesterPhysicsPtr)->liftoffVelPhase = 150.0f;
            }

            goompa->pos.y += liftoffVelocity;
            goompa->renderYaw = clamp_angle(360.0f - N(TweesterPhysicsPtr)->angle);
            N(TweesterPhysicsPtr)->angularVel += 0.8;

            if (N(TweesterPhysicsPtr)->angularVel > 40.0f) {
                N(TweesterPhysicsPtr)->angularVel = 40.0f;
            }

            if (--N(TweesterPhysicsPtr)->countdown == 0) {
                N(TweesterPhysicsPtr)->state++;
            }
            break;
        case TWEESTER_PARTNER_HOLD:
            goompa->flags = N(TweesterPhysicsPtr)->prevFlags;
            N(TweesterPhysicsPtr)->countdown = 30;
            N(TweesterPhysicsPtr)->state++;
            break;
        case TWEESTER_PARTNER_RELEASE:
            partner_walking_update_player_tracking(goompa);
            partner_walking_update_motion(goompa);

            if (--N(TweesterPhysicsPtr)->countdown == 0) {
                N(TweesterPhysicsPtr)->state = TWEESTER_PARTNER_INIT;
                TweesterTouchingPartner = nullptr;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtScript EVS_WorldGoompa_Update = {
    Call(N(Update))
    Return
    End
};

void N(try_cancel_tweester)(Npc* goompa) {
    if (TweesterTouchingPartner != nullptr) {
        TweesterTouchingPartner = nullptr;
        goompa->flags = N(TweesterPhysicsPtr)->prevFlags;
        N(TweesterPhysicsPtr)->state = TWEESTER_PARTNER_INIT;
        partner_clear_player_tracking(goompa);
    }
}

API_CALLABLE(N(UseAbility)) {
    return ApiStatus_DONE2;
}

EvtScript EVS_WorldGoompa_UseAbility = {
    Call(N(UseAbility))
    Return
    End
};

API_CALLABLE(N(PutAway)) {
    Npc* goompa = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(goompa);
    }

    if (partner_put_away(goompa)) {
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript EVS_WorldGoompa_PutAway = {
    Call(N(PutAway))
    Return
    End
};
