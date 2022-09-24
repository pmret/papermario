#include "common.h"
#include "sprite/npc/WorldGoombario.h"
#include "goombario.h"
#include "../src/world/partners.h"
#include "message_ids.h"

extern s32* D_802B79A8_E21858;

BSS s32 D_802BDF30;
BSS s32 D_802BDF34;
BSS Npc* D_802BDF38;
BSS s32 D_802BDF3C;
BSS TweesterPhysics GoombarioTweesterPhysics;
BSS s32 D_802BDF5C;
BSS s32 GoombarioGetTattleID;
BSS s32 D_802BDF64;

s32 EntityTattles[] = {
    ENTITY_TYPE_HAMMER1_BLOCK,        MSG_EntityTattle_HammerBlock1_CanBreak,
    ENTITY_TYPE_HAMMER1_BLOCK_TINY,   MSG_EntityTattle_HammerBlock1_CanBreak,
    ENTITY_TYPE_HAMMER2_BLOCK,        MSG_EntityTattle_HammerBlock2_CantBreak,
    ENTITY_TYPE_HAMMER2_BLOCK_TINY,   MSG_EntityTattle_HammerBlock2_CantBreak,
    ENTITY_TYPE_HAMMER3_BLOCK,        MSG_EntityTattle_HammerBlock3_CantBreak,
    ENTITY_TYPE_HAMMER3_BLOCK_TINY,   MSG_EntityTattle_HammerBlock3_CantBreak,
    ENTITY_TYPE_BRICK_BLOCK,          MSG_EntityTattle_BrickBlock,
    ENTITY_TYPE_MULTI_COIN_BRICK,     MSG_EntityTattle_BrickBlock,
    ENTITY_TYPE_YELLOW_BLOCK,         MSG_EntityTattle_ItemBlock,
    ENTITY_TYPE_SINGLE_TRIGGER_BLOCK, MSG_EntityTattle_ItemBlock,
    ENTITY_TYPE_MULTI_TRIGGER_BLOCK,  MSG_EntityTattle_InertBlock,
    ENTITY_TYPE_PUSH_BLOCK,           MSG_EntityTattle_PushBlock,
    ENTITY_TYPE_RED_BLOCK,            MSG_EntityTattle_BadgeBlock,
    ENTITY_TYPE_SIMPLE_SPRING,        MSG_EntityTattle_Spring,
    ENTITY_TYPE_SCRIPT_SPRING,        MSG_EntityTattle_Spring,
    ENTITY_TYPE_BLUE_SWITCH,          MSG_EntityTattle_Switch,
    ENTITY_TYPE_RED_SWITCH,           MSG_EntityTattle_Switch,
    ENTITY_TYPE_HUGE_BLUE_SWITCH,     MSG_EntityTattle_BigSwitch_SpinJump,
    ENTITY_TYPE_GREEN_STOMP_SWITCH,   MSG_EntityTattle_FloorSwitch_SpinJump,
    ENTITY_TYPE_BLUE_WARP_PIPE,       MSG_EntityTattle_Pipe,
    ENTITY_TYPE_PADLOCK,              MSG_EntityTattle_PadLock,
    ENTITY_TYPE_PADLOCK_RED_FRAME,    MSG_EntityTattle_PadLock,
    ENTITY_TYPE_PADLOCK_RED_FACE,     MSG_EntityTattle_PadLock,
    ENTITY_TYPE_PADLOCK_BLUE_FACE,    MSG_EntityTattle_PadLock,
    ENTITY_TYPE_SIGNPOST,             MSG_EntityTattle_0012,
    ENTITY_TYPE_RED_ARROW_SIGNS,      MSG_EntityTattle_Sign,
    ENTITY_TYPE_BOMBABLE_ROCK,        MSG_EntityTattle_BombableRock,
    ENTITY_TYPE_CHEST,                MSG_EntityTattle_Chest,
    ENTITY_TYPE_WOODEN_CRATE,         MSG_EntityTattle_WoodenCrate_CantBreak,
    ENTITY_TYPE_BOARDED_FLOOR,        MSG_EntityTattle_BoardedFloor_CantBreak,
    ENTITY_TYPE_STAR_BOX_LAUCHER,     MSG_EntityTattle_JackInTheBox_SpinJump,
    ENTITY_TYPE_BELLBELL_PLANT,       MSG_EntityTattle_BellbellPlant,
    ENTITY_TYPE_TRUMPET_PLANT,        MSG_EntityTattle_TrumpetPlant,
    ENTITY_TYPE_CYMBAL_PLANT,         MSG_EntityTattle_CymbalBush,
    ENTITY_TYPE_MUNCHLESIA,           MSG_EntityTattle_Munchlesia,
    ENTITY_TYPE_SPINNING_FLOWER,      MSG_EntityTattle_SpinningFlower,
    ENTITY_TYPE_PINK_FLOWER,          MSG_EntityTattle_BulbBush,
    -1
};

s32 func_802BD100_317020(s32 arg0) {
    s32 i;

    for (i = 0; i < 0x40; i++) {
        Trigger* trigger = get_trigger_by_id(i);

        if (trigger != NULL && trigger->flags.flags & TRIGGER_WALL_PRESS_A && trigger->location.colliderID == arg0) {
            return trigger->unk_tr_2C;
        }
    }
    return 0;
}

void world_goombario_init(Npc* goombario) {
    goombario->collisionHeight = 24;
    goombario->collisionRadius = 20;
}

ApiStatus func_802BD188_3170A8(Evt* script, s32 isInitialCall) {
    Npc* goombario = script->owner2.npc;
    GoombarioGetTattleID = -1;

    if (isInitialCall) {
        partner_init_get_out(goombario);
    }

    return partner_get_out(goombario) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_goombario_take_out = {
    EVT_CALL(func_802BD188_3170A8)
    EVT_RETURN
    EVT_END
};

TweesterPhysics* GoombarioTweesterPhysicsPtr = &GoombarioTweesterPhysics;

s32 func_802BD1D0_3170F0(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* npc = script->owner2.npc;
    f32 sinAngle, cosAngle, liftoffVelocity;
    Entity* entity;

    if (isInitialCall) {
        partner_walking_enable(npc, 1);
        mem_clear(GoombarioTweesterPhysicsPtr, sizeof(TweesterPhysics));
        TweesterTouchingPartner = NULL;
    }

    playerData->partnerUsedTime[PARTNER_GOOMBARIO]++;
    entity = TweesterTouchingPartner;

    if (entity == NULL) {
        partner_walking_update_player_tracking(npc);
        partner_walking_update_motion(npc);
        return 0;
    }

    switch (GoombarioTweesterPhysicsPtr->state) {
        case 0:
            GoombarioTweesterPhysicsPtr->state = 1;
            GoombarioTweesterPhysicsPtr->prevFlags = npc->flags;
            GoombarioTweesterPhysicsPtr->radius = fabsf(dist2D(npc->pos.x, npc->pos.z, entity->position.x, entity->position.z));
            GoombarioTweesterPhysicsPtr->angle = atan2(entity->position.x, entity->position.z, npc->pos.x, npc->pos.z);
            GoombarioTweesterPhysicsPtr->angularVelocity = 6.0f;
            GoombarioTweesterPhysicsPtr->liftoffVelocityPhase = 50.0f;
            GoombarioTweesterPhysicsPtr->countdown = 120;
            npc->flags |= NPC_FLAG_ENABLE_HIT_SCRIPT | NPC_FLAG_40 | NPC_FLAG_100 | NPC_FLAG_40000;
            npc->flags &= ~NPC_FLAG_GRAVITY;
        case 1:
            sin_cos_rad(DEG_TO_RAD(GoombarioTweesterPhysicsPtr->angle), &sinAngle, &cosAngle);

            npc->pos.x = entity->position.x + (sinAngle * GoombarioTweesterPhysicsPtr->radius);
            npc->pos.z = entity->position.z - (cosAngle * GoombarioTweesterPhysicsPtr->radius);
            GoombarioTweesterPhysicsPtr->angle = clamp_angle(GoombarioTweesterPhysicsPtr->angle - GoombarioTweesterPhysicsPtr->angularVelocity);

            if (GoombarioTweesterPhysicsPtr->radius > 20.0f) {
                GoombarioTweesterPhysicsPtr->radius--;
            } else if (GoombarioTweesterPhysicsPtr->radius < 19.0f) {
                GoombarioTweesterPhysicsPtr->radius++;
            }

            liftoffVelocity = sin_rad(DEG_TO_RAD(GoombarioTweesterPhysicsPtr->liftoffVelocityPhase)) * 3.0f;
            GoombarioTweesterPhysicsPtr->liftoffVelocityPhase += 3.0f;

            if (GoombarioTweesterPhysicsPtr->liftoffVelocityPhase > 150.0f) {
                GoombarioTweesterPhysicsPtr->liftoffVelocityPhase = 150.0f;
            }

            npc->pos.y += liftoffVelocity;

            npc->renderYaw = clamp_angle(360.0f - GoombarioTweesterPhysicsPtr->angle);
            GoombarioTweesterPhysicsPtr->angularVelocity += 0.8;

            if (GoombarioTweesterPhysicsPtr->angularVelocity > 40.0f) {
                GoombarioTweesterPhysicsPtr->angularVelocity = 40.0f;
            }

            if (--GoombarioTweesterPhysicsPtr->countdown == 0) {
                GoombarioTweesterPhysicsPtr->state++;
            }
            break;
        case 2:
            npc->flags = GoombarioTweesterPhysicsPtr->prevFlags;
            GoombarioTweesterPhysicsPtr->countdown = 30;
            GoombarioTweesterPhysicsPtr->state++;
            break;
        case 3:
            partner_walking_update_player_tracking(npc);
            partner_walking_update_motion(npc);

            if (--GoombarioTweesterPhysicsPtr->countdown == 0) {
                GoombarioTweesterPhysicsPtr->state = 0;
                TweesterTouchingPartner = NULL;
            }
            break;
    }
    return 0;
}

EvtScript world_goombario_update = {
    EVT_CALL(func_802BD1D0_3170F0)
    EVT_RETURN
    EVT_END
};

void func_802BD564_317484(Npc* goombario) {
    if (TweesterTouchingPartner) {
        TweesterTouchingPartner = NULL;
        goombario->flags = GoombarioTweesterPhysicsPtr->prevFlags;
        GoombarioTweesterPhysicsPtr->state = 0;
        partner_clear_player_tracking (goombario);
    }
}

s32 world_goombario_can_pause(Npc* goombario) {
    PartnerActionStatus* goombarioActionStatus = &gPartnerActionStatus;
    s32 new_var;

    if (goombarioActionStatus->partnerActionState != PARTNER_ACTION_NONE) {
        return FALSE;
    }

    if ((goombario->flags & (NPC_FLAG_1000 | NPC_FLAG_JUMPING)) != NPC_FLAG_1000) {
        return new_var = 0;
        do { } while (new_var); // why though
    }

    return TRUE;
}

// get message for tattle routine
ApiStatus func_802BD5D8_3174F8(Evt* script, s32 isInitialCall);
INCLUDE_ASM(ApiStatus, "world/partner/goombario", func_802BD5D8_3174F8, Evt* script, s32 isInitialCall);

ApiStatus func_802BDB30_317A50(Evt* script, s32 isInitialCall) {
    PartnerActionStatus* goombarioActionStatus = &gPartnerActionStatus;

    set_time_freeze_mode(TIME_FREEZE_NORMAL);

    if (D_802BDF64 != 0) {
        D_802BDF64 = 0;
        enable_player_input();
    }

    goombarioActionStatus->partnerActionState = PARTNER_ACTION_NONE;
    goombarioActionStatus->actingPartner = PARTNER_NONE;
    return ApiStatus_DONE2;
}

EvtScript world_goombario_use_ability = {
    EVT_CALL(func_802BD5D8_3174F8)
    EVT_IF_EQ(LVar0, -1)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(func_802BDB30_317A50)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar1, 0)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_WorldGoombario_Talk,
                 ANIM_WorldGoombario_Idle, 0, LVar0)
    EVT_END_IF
    EVT_WAIT(1)
    EVT_CALL(func_802BDB30_317A50)
    EVT_RETURN
    EVT_END
};

ApiStatus func_802BDB84(Evt* script, s32 isInitialCall) {
    Npc* goombario = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(goombario);
    }

    return partner_put_away(goombario) ? ApiStatus_DONE1 : ApiStatus_BLOCK;
}

EvtScript world_goombario_put_away = {
    EVT_CALL(func_802BDB84)
    EVT_RETURN
    EVT_END
};

void world_goombario_pre_battle(Npc* goombario) {
    PartnerActionStatus* goombarioActionStatus = &gPartnerActionStatus;

    if (goombarioActionStatus->partnerActionState != PARTNER_ACTION_NONE) {
        set_time_freeze_mode(TIME_FREEZE_NORMAL);
        enable_player_input();
        cancel_current_message();
        partner_clear_player_tracking(goombario);
        goombarioActionStatus->partnerActionState = PARTNER_ACTION_NONE;
        goombarioActionStatus->actingPartner = PARTNER_NONE;
        disable_npc_blur(goombario);
    }

    goombarioActionStatus->actingPartner = PARTNER_GOOMBARIO;
}
