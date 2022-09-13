#include "common.h"
#include "goompa.h"
#include "../src/world/partners.h"

ApiStatus func_802BD14C_324A5C(Evt* script, s32 isInitialCall);

void world_goompa_init(Npc* partner) {
    partner->collisionHeight = 24;
    partner->collisionRadius = 20;
}

ApiStatus GoompaTakeOut(Evt* script, s32 isInitialCall) {
    Npc* goompa = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(goompa);
    }

    return partner_get_out(goompa) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_goompa_take_out = {
    EVT_CALL(GoompaTakeOut)
    EVT_RETURN
    EVT_END
};

BSS TweesterPhysics GoompaTweesterPhysics;

TweesterPhysics* GoompaTweesterPhysicsPtr = &GoompaTweesterPhysics;

ApiStatus func_802BD14C_324A5C(Evt* script, s32 isInitialCall) {
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
        case 0:
            GoompaTweesterPhysicsPtr->state = 1;
            GoompaTweesterPhysicsPtr->prevFlags = goompa->flags;
            GoompaTweesterPhysicsPtr->radius = fabsf(dist2D(goompa->pos.x, goompa->pos.z,
                                                    entity->position.x, entity->position.z));
            GoompaTweesterPhysicsPtr->angle = atan2(entity->position.x, entity->position.z, goompa->pos.x, goompa->pos.z);
            GoompaTweesterPhysicsPtr->angularVelocity = 6.0f;
            GoompaTweesterPhysicsPtr->liftoffVelocityPhase = 50.0f;
            GoompaTweesterPhysicsPtr->countdown = 120;
            goompa->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_100 | NPC_FLAG_40000;
            goompa->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
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
        case 2:
            goompa->flags = GoompaTweesterPhysicsPtr->prevFlags;
            GoompaTweesterPhysicsPtr->countdown = 30;
            GoompaTweesterPhysicsPtr->state++;
            break;
        case 3:
            partner_walking_update_player_tracking(goompa);
            partner_walking_update_motion(goompa);

            if (--GoompaTweesterPhysicsPtr->countdown == 0) {
                GoompaTweesterPhysicsPtr->state = 0;
                TweesterTouchingPartner = NULL;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtScript world_goompa_update = {
    EVT_CALL(func_802BD14C_324A5C)
    EVT_RETURN
    EVT_END
};

void func_802BD4E0_324DF0(Npc* goompa) {
    if (TweesterTouchingPartner != NULL) {
        TweesterTouchingPartner = NULL;
        goompa->flags = GoompaTweesterPhysicsPtr->prevFlags;
        GoompaTweesterPhysicsPtr->state = 0;
        partner_clear_player_tracking(goompa);
    }
}

ApiStatus GoompaUseAbility(Evt* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

EvtScript world_goompa_use_ability = {
    EVT_CALL(GoompaUseAbility)
    EVT_RETURN
    EVT_END
};

ApiStatus GoompaPutAway(Evt* script, s32 isInitialCall) {
    Npc* goompa = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(goompa);
    }

    return partner_put_away(goompa) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_goompa_put_away = {
    EVT_CALL(GoompaPutAway)
    EVT_RETURN
    EVT_END
};
