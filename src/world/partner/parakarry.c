#include "common.h"
#include "../src/world/partners.h"

BSS s32 D_802BEBB0;
BSS s32 D_802BEBB4;
BSS s32 D_802BEBB8;
BSS s32 D_802BEBBC;
BSS s32 D_802BEBC0_31CBE0;
BSS s32 D_802BEBC4;
BSS TweesterPhysics ParakarryTweesterPhysics;

void world_parakarry_init(Npc* parakarry) {
    parakarry->collisionHeight = 37;
    parakarry->collisionRadius = 40;
    D_802BEBB0 = 0;
    D_802BEBC0_31CBE0 = 0;
    D_802BEBB4 = 0;
    D_802BEBB8 = 0;
    D_802BEBBC = 0;
    D_802BEBC4 = 0;
}

ApiStatus ParakarryTakeOut(Evt* script, s32 isInitialCall) {
    Npc* parakarry = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(parakarry);
    }

    return partner_get_out(parakarry) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_parakarry_take_out = {
    EVT_CALL(ParakarryTakeOut)
    EVT_RETURN
    EVT_END
};

TweesterPhysics* ParakarryTweesterPhysicsPtr = &ParakarryTweesterPhysics;

ApiStatus ParakarryUpdate(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* parakarry = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_flying_enable(parakarry, 1);
        mem_clear(ParakarryTweesterPhysicsPtr, sizeof(TweesterPhysics));
        TweesterTouchingPartner = NULL;
    }

    playerData->partnerUsedTime[PARTNER_PARAKARRY]++;
    entity = TweesterTouchingPartner;

    if (entity == NULL) {
        partner_flying_update_player_tracking(parakarry);
        partner_flying_update_motion(parakarry);
        return ApiStatus_BLOCK;
    }

    switch (ParakarryTweesterPhysicsPtr->state) {
        case 0:
            ParakarryTweesterPhysicsPtr->state = 1;
            ParakarryTweesterPhysicsPtr->prevFlags = parakarry->flags;
            ParakarryTweesterPhysicsPtr->radius = fabsf(dist2D(parakarry->pos.x, parakarry->pos.z,
                                                     entity->position.x, entity->position.z));
            ParakarryTweesterPhysicsPtr->angle = atan2(entity->position.x, entity->position.z,
                                              parakarry->pos.x, parakarry->pos.z);
            ParakarryTweesterPhysicsPtr->angularVelocity = 6.0f;
            ParakarryTweesterPhysicsPtr->liftoffVelocityPhase = 50.0f;
            ParakarryTweesterPhysicsPtr->countdown = 120;
            parakarry->flags |= NPC_FLAG_40000 | NPC_FLAG_100 | NPC_FLAG_40 | NPC_FLAG_ENABLE_HIT_SCRIPT;
            parakarry->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad((ParakarryTweesterPhysicsPtr->angle * TAU) / 360.0f, &sinAngle, &cosAngle);
            parakarry->pos.x = entity->position.x + (sinAngle * ParakarryTweesterPhysicsPtr->radius);
            parakarry->pos.z = entity->position.z - (cosAngle * ParakarryTweesterPhysicsPtr->radius);
            ParakarryTweesterPhysicsPtr->angle = clamp_angle(ParakarryTweesterPhysicsPtr->angle - ParakarryTweesterPhysicsPtr->angularVelocity);

            if (ParakarryTweesterPhysicsPtr->radius > 20.0f) {
                ParakarryTweesterPhysicsPtr->radius--;
            } else if (ParakarryTweesterPhysicsPtr->radius < 19.0f) {
                ParakarryTweesterPhysicsPtr->radius++;
            }

            liftoffVelocity = sin_rad((ParakarryTweesterPhysicsPtr->liftoffVelocityPhase * TAU) / 360.0f) * 3.0f;
            ParakarryTweesterPhysicsPtr->liftoffVelocityPhase += 3.0f;

            if (ParakarryTweesterPhysicsPtr->liftoffVelocityPhase > 150.0f) {
                ParakarryTweesterPhysicsPtr->liftoffVelocityPhase = 150.0f;
            }

            parakarry->pos.y += liftoffVelocity;
            parakarry->renderYaw = clamp_angle(360.0f - ParakarryTweesterPhysicsPtr->angle);
            ParakarryTweesterPhysicsPtr->angularVelocity += 0.8;

            if (ParakarryTweesterPhysicsPtr->angularVelocity > 40.0f) {
                ParakarryTweesterPhysicsPtr->angularVelocity = 40.0f;
            }

            if (--ParakarryTweesterPhysicsPtr->countdown == 0) {
                ParakarryTweesterPhysicsPtr->state++;
            }
            break;
        case 2:
            parakarry->flags = ParakarryTweesterPhysicsPtr->prevFlags;
            ParakarryTweesterPhysicsPtr->countdown = 30;
            ParakarryTweesterPhysicsPtr->state++;
            break;
        case 3:
            partner_flying_update_player_tracking(parakarry);
            partner_flying_update_motion(parakarry);

            if (--ParakarryTweesterPhysicsPtr->countdown == 0) {
                ParakarryTweesterPhysicsPtr->state = 0;
                TweesterTouchingPartner = NULL;
            }
            break;
    }
    return ApiStatus_BLOCK;
}

EvtScript world_parakarry_update = {
    EVT_CALL(ParakarryUpdate)
    EVT_RETURN
    EVT_END
};

void func_802BD514_319A84(Npc* parakarry) {
    if (TweesterTouchingPartner) {
        TweesterTouchingPartner = NULL;
        parakarry->flags = ParakarryTweesterPhysicsPtr->prevFlags;
        ParakarryTweesterPhysicsPtr->state = 0;
        partner_clear_player_tracking (parakarry);
    }
}

s32 func_802BD558_319AC8(void) {
    f32 sp28, sp2C, sp30, sp34, sp38, sp3C, sp40, sp44;
    f32 colliderBaseHeight = gPlayerStatus.colliderHeight;
    s32 raycastResult;

    sp28 = gPlayerStatus.position.x;
    sp2C = gPlayerStatus.position.y + (colliderBaseHeight * 0.5);
    sp30 = gPlayerStatus.position.z;
    sp34 = colliderBaseHeight * 0.5f;
    
    raycastResult = player_raycast_below_cam_relative(&gPlayerStatus, &sp28, &sp2C, &sp30, &sp34, &sp38,
                                                      &sp3C, &sp40, &sp44);

    if (((get_collider_type_by_id(raycastResult) & 0xFF) - 2) < 2U) {
        gPlayerStatus.unk_BF = 2;
        D_802BEBC0_31CBE0 = 0x15;
        gPlayerStatus.flags |= PLAYER_STATUS_FLAGS_800;
    }

    return raycastResult;
}

s32 func_802BD660_319BD0(void);
INCLUDE_ASM(s32, "world/partner/parakarry", func_802BD660_319BD0);

EvtScript world_parakarry_use_ability = {
    EVT_CALL(func_802BD660_319BD0)
    EVT_RETURN
    EVT_END
};

ApiStatus ParakarryPutAway(Evt* script, s32 isInitialCall) {
    Npc* parakarry = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(parakarry);
    }

    return partner_put_away(parakarry) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_parakarry_put_away = {
    EVT_CALL(ParakarryPutAway)
    EVT_RETURN
    EVT_END
};

void world_parakarry_pre_battle(Npc* parakarry) {
    PartnerActionStatus* parakarryActionStatus = &gPartnerActionStatus;

    if (D_802BEBB0) {
        if (D_802BEBB8) {
            enable_player_static_collisions();
        }

        if (D_802BEBB4) {
            enable_player_input();
        }

        set_action_state(ACTION_STATE_IDLE);
        parakarryActionStatus->npc = *parakarry;
        parakarryActionStatus->actionState.b[1] = 1;
        partner_clear_player_tracking(parakarry);
    }

    parakarryActionStatus->actionState.b[3] = 4;
}

void world_parakarry_post_battle(Npc* parakarry) {
    PartnerActionStatus* parakarryActionStatus = &gPartnerActionStatus;

    if (parakarryActionStatus->actionState.b[1] != 0) {
        if (D_802BEBB8) {
            disable_player_static_collisions();
        }
        if (D_802BEBB4) {
            disable_player_input();
        }

        set_action_state(ACTION_STATE_RIDE);
        *parakarry = parakarryActionStatus->npc;
        parakarryActionStatus->actionState.b[3] = 0;
        parakarryActionStatus->actionState.b[0] = 0;
        partner_clear_player_tracking(parakarry);
        partner_use_ability();
    }
}
