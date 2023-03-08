#include "common.h"
#include "goompa.h"
#include "../src/world/partners.h"

API_CALLABLE(GoompaUpdate);

void world_goompa_init(Npc* partner) {
    partner->collisionHeight = 24;
    partner->collisionRadius = 20;
}

API_CALLABLE(GoompaTakeOut) {
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

EvtScript EVS_WorldGoompaTakeOut = {
    EVT_CALL(GoompaTakeOut)
    EVT_RETURN
    EVT_END
};

BSS TweesterPhysics GoompaTweesterPhysics;
TweesterPhysics* GoompaTweesterPhysicsPtr = &GoompaTweesterPhysics;

API_CALLABLE(GoompaUpdate) {
    PlayerData* playerData = &gPlayerData;
    Npc* goompa = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_walking_enable(goompa, 1);
        mem_clear(GoompaTweesterPhysicsPtr, sizeof(TweesterPhysics));
        TweesterTouchingPartner = NULL;
    }

    playerData->partnerUsedTime[PARTNER_GOOMPA]++;
    entity = TweesterTouchingPartner;

    if (entity == NULL) {
        partner_walking_update_player_tracking(goompa);
        partner_walking_update_motion(goompa);
        return ApiStatus_BLOCK;
    }

    switch (GoompaTweesterPhysicsPtr->state) {
        case TWEESTER_PARTNER_INIT:
            GoompaTweesterPhysicsPtr->state++;
            GoompaTweesterPhysicsPtr->prevFlags = goompa->flags;
            GoompaTweesterPhysicsPtr->radius = fabsf(dist2D(goompa->pos.x, goompa->pos.z,
                                                    entity->position.x, entity->position.z));
            GoompaTweesterPhysicsPtr->angle = atan2(entity->position.x, entity->position.z, goompa->pos.x, goompa->pos.z);
            GoompaTweesterPhysicsPtr->angularVelocity = 6.0f;
            GoompaTweesterPhysicsPtr->liftoffVelocityPhase = 50.0f;
            GoompaTweesterPhysicsPtr->countdown = 120;
            goompa->flags |= NPC_FLAG_8 | NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_CAMERA_FOR_YAW;
            goompa->flags &= ~NPC_FLAG_GRAVITY;
        case TWEESTER_PARTNER_ATTRACT:
            sin_cos_rad(DEG_TO_RAD(GoompaTweesterPhysicsPtr->angle), &sinAngle, &cosAngle);
            goompa->pos.x = entity->position.x + (sinAngle * GoompaTweesterPhysicsPtr->radius);
            goompa->pos.z = entity->position.z - (cosAngle * GoompaTweesterPhysicsPtr->radius);
            GoompaTweesterPhysicsPtr->angle = clamp_angle(GoompaTweesterPhysicsPtr->angle - GoompaTweesterPhysicsPtr->angularVelocity);

            if (GoompaTweesterPhysicsPtr->radius > 20.0f) {
                GoompaTweesterPhysicsPtr->radius--;
            } else if (GoompaTweesterPhysicsPtr->radius < 19.0f) {
                GoompaTweesterPhysicsPtr->radius++;
            }

            liftoffVelocity = sin_rad(DEG_TO_RAD(GoompaTweesterPhysicsPtr->liftoffVelocityPhase)) * 3.0f;
            GoompaTweesterPhysicsPtr->liftoffVelocityPhase += 3.0f;

            if (GoompaTweesterPhysicsPtr->liftoffVelocityPhase > 150.0f) {
                GoompaTweesterPhysicsPtr->liftoffVelocityPhase = 150.0f;
            }

            goompa->pos.y += liftoffVelocity;
            goompa->renderYaw = clamp_angle(360.0f - GoompaTweesterPhysicsPtr->angle);
            GoompaTweesterPhysicsPtr->angularVelocity += 0.8;

            if (GoompaTweesterPhysicsPtr->angularVelocity > 40.0f) {
                GoompaTweesterPhysicsPtr->angularVelocity = 40.0f;
            }

            if (--GoompaTweesterPhysicsPtr->countdown == 0) {
                GoompaTweesterPhysicsPtr->state++;
            }
            break;
        case TWEESTER_PARTNER_HOLD:
            goompa->flags = GoompaTweesterPhysicsPtr->prevFlags;
            GoompaTweesterPhysicsPtr->countdown = 30;
            GoompaTweesterPhysicsPtr->state++;
            break;
        case TWEESTER_PARTNER_RELEASE:
            partner_walking_update_player_tracking(goompa);
            partner_walking_update_motion(goompa);

            if (--GoompaTweesterPhysicsPtr->countdown == 0) {
                GoompaTweesterPhysicsPtr->state = TWEESTER_PARTNER_INIT;
                TweesterTouchingPartner = NULL;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtScript EVS_WorldGoompaUpdate = {
    EVT_CALL(GoompaUpdate)
    EVT_RETURN
    EVT_END
};

void goompa_try_cancel_tweester(Npc* goompa) {
    if (TweesterTouchingPartner != NULL) {
        TweesterTouchingPartner = NULL;
        goompa->flags = GoompaTweesterPhysicsPtr->prevFlags;
        GoompaTweesterPhysicsPtr->state = TWEESTER_PARTNER_INIT;
        partner_clear_player_tracking(goompa);
    }
}

API_CALLABLE(GoompaUseAbility) {
    return ApiStatus_DONE2;
}

EvtScript EVS_WorldGoompaUseAbility = {
    EVT_CALL(GoompaUseAbility)
    EVT_RETURN
    EVT_END
};

API_CALLABLE(GoompaPutAway) {
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

EvtScript EVS_WorldGoompaPutAway = {
    EVT_CALL(GoompaPutAway)
    EVT_RETURN
    EVT_END
};
