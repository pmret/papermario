#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/battle_watt.h"
#include "effects.h"

ApiStatus N(UnkWattEffectFunc1)(Evt* script, s32 isInitialCall) {
    WattEffectData* wattEffectData;
    f32 x, y, z;
    Actor* actor = get_actor(script->owner1.enemyID);
    ActorState* state = &actor->state;

    if (isInitialCall) {
        wattEffectData = heap_malloc(sizeof(*wattEffectData));
        actor->state.varTablePtr[2] = wattEffectData;
        wattEffectData->unk_04 = TRUE;
        wattEffectData->angle = 0;
        wattEffectData->unk_0C = TRUE;
        wattEffectData->unk_10 = 0;
        wattEffectData->effect1 = fx_static_status(0, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z, (actor->debuff != STATUS_SHRINK) ? 1.0f : 0.4f, 5, 0);
        wattEffectData->effect2 = fx_static_status(1, actor->currentPos.x, -1000.0f, actor->currentPos.z, (actor->debuff != STATUS_SHRINK) ? 1.0f : 0.4f, 5, 0);
        wattEffectData->flags = TRUE;
        wattEffectData->debuff = actor->debuff;
    }

    wattEffectData = state->varTablePtr[2];
    if (wattEffectData->flags) {
        if (wattEffectData->unk_04 && actor->debuff != STATUS_STOP) {
            wattEffectData->angle += 15;
            wattEffectData->angle = clamp_angle(wattEffectData->angle);
        }
        actor->unk_19A = sin_rad(DEG_TO_RAD(wattEffectData->angle)) * 3.0f;

        x = actor->currentPos.x + actor->headOffset.x;
        y = actor->currentPos.y + actor->headOffset.y + actor->unk_19A + (actor->debuff != STATUS_SHRINK ? 12.0 : 4.800000000000001); // 4.8 doesn't match
        z = actor->currentPos.z + actor->headOffset.z;
        if (wattEffectData->unk_0C) {
            switch (wattEffectData->unk_10) {
                case 0:
                    if (wattEffectData->effect1 == NULL) {
                        wattEffectData->effect1 = fx_static_status(0, x, y, z, (actor->debuff != STATUS_SHRINK) ? 1.0f : 0.4f, 5, 0);
                    }

                    if (wattEffectData->effect2 != NULL) {
                        wattEffectData->effect2->flags |= EFFECT_INSTANCE_FLAGS_10;
                        wattEffectData->effect2 = NULL;
                    }
                    wattEffectData->effect1->data.staticStatus->unk_04 = x;
                    wattEffectData->effect1->data.staticStatus->unk_08 = y;
                    wattEffectData->effect1->data.staticStatus->unk_0C = z;
                    break;
                case 1:
                    if (wattEffectData->effect1 != NULL) {
                        wattEffectData->effect1->flags |= EFFECT_INSTANCE_FLAGS_10;
                        wattEffectData->effect1 = NULL;
                    }
                    if (wattEffectData->effect2 == NULL) {
                        wattEffectData->effect2 = fx_static_status(1, x, y, z, (actor->debuff != STATUS_SHRINK) ? 1.0f : 0.4f, 5, 0);

                    }
                    wattEffectData->effect2->data.staticStatus->unk_04 = x;
                    wattEffectData->effect2->data.staticStatus->unk_08 = y;
                    wattEffectData->effect2->data.staticStatus->unk_0C = z;
                    break;
            }
        } else {
            if (wattEffectData->effect1 != NULL) {
                wattEffectData->effect1->flags |= EFFECT_INSTANCE_FLAGS_10;
                wattEffectData->effect1 = NULL;
            }
            if (wattEffectData->effect2 != NULL) {
                wattEffectData->effect2->flags |= EFFECT_INSTANCE_FLAGS_10;
                wattEffectData->effect2 = NULL;
            }
        }
        if (wattEffectData->debuff != actor->debuff && wattEffectData->unk_0C) {
            if (wattEffectData->effect1 != NULL) {
                wattEffectData->effect1->flags |= EFFECT_INSTANCE_FLAGS_10;
                wattEffectData->effect1 = NULL;
            }
            if (wattEffectData->effect2 != NULL) {
                wattEffectData->effect2->flags |= EFFECT_INSTANCE_FLAGS_10;
                wattEffectData->effect2 = NULL;
            }
        }
        wattEffectData->debuff = actor->debuff;
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}



ApiStatus N(UnkWattEffectFunc2)(Evt* script, s32 isInitialCall) {
    WattEffectData* wattEffectData = get_actor(script->owner1.enemyID)->state.varTablePtr[2];

    wattEffectData->flags = FALSE;

    if (wattEffectData->effect1 != NULL) {
        wattEffectData->effect1->flags |= EFFECT_INSTANCE_FLAGS_10;
    }

    if (wattEffectData->effect2 != NULL) {
        wattEffectData->effect2->flags |= EFFECT_INSTANCE_FLAGS_10;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(UnkWattEffectFunc3)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    WattEffectData* wattEffectData = get_actor(script->owner1.enemyID)->state.varTablePtr[2];

    wattEffectData->unk_04 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus N(UnkWattEffectFunc4)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    WattEffectData* wattEffectData = get_actor(script->owner1.enemyID)->state.varTablePtr[2];

    wattEffectData->unk_0C = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus N(UnkWattEffectFunc5)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    WattEffectData* wattEffectData = get_actor(script->owner1.enemyID)->state.varTablePtr[2];

    wattEffectData->unk_10 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

extern EvtScript N(watt_init);
extern EvtScript N(watt_takeTurn);
extern EvtScript N(watt_idle);
extern EvtScript N(watt_handleEvent);

s32 N(watt_idleAnimations)[] = {
    STATUS_NORMAL, NPC_ANIM_battle_watt_Palette_00_Anim_1,
    STATUS_STONE, NPC_ANIM_battle_watt_Palette_00_Anim_0,
    STATUS_SLEEP, NPC_ANIM_battle_watt_Palette_00_Anim_0,
    STATUS_POISON, NPC_ANIM_battle_watt_Palette_00_Anim_1,
    STATUS_STOP, NPC_ANIM_battle_watt_Palette_00_Anim_0,
    STATUS_STATIC, NPC_ANIM_battle_watt_Palette_00_Anim_1,
    STATUS_PARALYZE, NPC_ANIM_battle_watt_Palette_00_Anim_0,
    STATUS_DIZZY, NPC_ANIM_battle_watt_Palette_00_Anim_F,
    STATUS_FEAR, NPC_ANIM_battle_watt_Palette_00_Anim_F,
    STATUS_END,
};

s32 N(watt_defenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_SHOCK, 99,
    ELEMENT_END,
};

s32 N(watt_statusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 60,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 75,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 75,
    STATUS_SHRINK, 75,
    STATUS_STOP, 80,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, -1,
    STATUS_END,
};

ActorPartBlueprint N(watt_parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -1, 20 },
        .opacity = 255,
        .idleAnimations = N(watt_idleAnimations),
        .defenseTable = N(watt_defenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ELECTRIFIED,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -8,
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { -1, -30 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(watt_defenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ELECTRIFIED,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
        .unk_1D = -8,
    },
};

ActorBlueprint N(watt) = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_GHOST_WATT,
    .level = 23,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(watt_parts)),
    .partsData = N(watt_parts),
    .script = &N(watt_init),
    .statusTable = N(watt_statusTable),
    .escapeChance = 50,
    .airLiftChance = 80,
    .spookChance = 70,
    .baseStatusChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 34, 28 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

EvtScript N(watt_init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(watt_takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(watt_idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(watt_handleEvent)))
    EVT_RETURN
    EVT_END
};

EvtScript N(watt_idle) = {
    EVT_SET_PRIORITY(99)
    EVT_CALL(N(UnkWattEffectFunc1))
    EVT_RETURN
    EVT_END
};

EvtScript N(watt_handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(N(UnkWattEffectFunc3), 0)
    EVT_CALL(N(UnkWattEffectFunc4), 1)
    EVT_CALL(N(UnkWattEffectFunc5), 0)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_watt_Palette_00_Anim_D)
            EVT_SET_CONST(LVar2, NPC_ANIM_battle_watt_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_watt_Palette_00_Anim_D)
            EVT_SET_CONST(LVar2, NPC_ANIM_battle_watt_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_CALL(N(UnkWattEffectFunc2))
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_watt_Palette_00_Anim_E)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoSpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_CALL(N(UnkWattEffectFunc2))
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoSpinSmashHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_watt_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_CALL(N(UnkWattEffectFunc2))
            EVT_EXEC_WAIT(N(OnDeath))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_watt_Palette_00_Anim_1)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_watt_Palette_00_Anim_3)
            EVT_SET_CONST(LVar2, NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_watt_Palette_00_Anim_3)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, NPC_ANIM_battle_watt_Palette_00_Anim_C)
            EVT_EXEC_WAIT(DoBlowAway)
            EVT_RETURN
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(N(UnkWattEffectFunc3), 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(watt_takeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(SetBattleCamOffsetZ, 40)
    EVT_CALL(MoveBattleCamOver, 80)
    EVT_CALL(func_8024ECF8, -1, 1, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_3)
    EVT_CALL(N(UnkWattEffectFunc5), 1)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 15, -10, 5)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_1)
    EVT_CALL(N(UnkWattEffectFunc5), 0)
    EVT_WAIT(5)
    EVT_CALL(N(UnkWattEffectFunc3), 0)
    EVT_CALL(AddGoalPos, ACTOR_SELF, 25, 20, 0)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 15, -20, 10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_5)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(FlyToGoal, ACTOR_SELF, 5, 0, 10)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_THREAD
                EVT_WAIT(5)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_1)
            EVT_END_THREAD
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(AddGoalPos, ACTOR_SELF, -40, 10, 0)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 10, -20, 4)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(N(UnkWattEffectFunc4), 1)
            EVT_CALL(N(UnkWattEffectFunc3), 1)
            EVT_WAIT(20)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_3)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(N(UnkWattEffectFunc4), 0)
    EVT_SET(LVarA, 40)
    EVT_CALL(AddBattleCamZoom, -75)
    EVT_CALL(MoveBattleCamOver, LVarA)
    EVT_CALL(func_8024ECF8, 0, 0, 1)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_289)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 4)
        EVT_CALL(PlayEffect, EFFECT_RADIAL_SHIMMER, 8, LVar0, LVar1, LVar2, EVT_FLOAT(0.52), LVarA, 0, 0, 0, 0, 0, 0, 0)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 12)
        EVT_CALL(PlayEffect, EFFECT_RADIAL_SHIMMER, 8, LVar0, LVar1, LVar2, EVT_FLOAT(1.3), LVarA, 0, 0, 0, 0, 0, 0, 0)
    EVT_END_IF
    EVT_CALL(N(UnkBackgroundFunc3))
    EVT_SET(LVar9, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_6)
    EVT_LOOP(LVarA)
        EVT_ADD(LVar9, 3)
        EVT_IF_GT(LVar9, 200)
            EVT_SET(LVar9, 200)
        EVT_END_IF
        EVT_CALL(N(SetBackgroundAlpha), LVar9)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_1)
    EVT_CALL(func_8026EA7C, ACTOR_SELF, 1, 9)
    EVT_CALL(AddBattleCamZoom, 75)
    EVT_CALL(MoveBattleCamOver, 5)
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(N(SetBackgroundAlpha), 0)
    EVT_END_THREAD
    EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar9)
    EVT_SWITCH(LVar9)
        EVT_CASE_EQ(0)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ELECTRIC | DAMAGE_TYPE_IGNORE_DEFENSE, 65535, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(1)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ELECTRIC | DAMAGE_TYPE_IGNORE_DEFENSE, 65535, 0, 4, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_EQ(2)
            EVT_WAIT(2)
            EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_ELECTRIC | DAMAGE_TYPE_IGNORE_DEFENSE, 65535, 0, 5, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_QUAKE_IMMUNE)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(N(UnkWattEffectFunc4), 1)
            EVT_CALL(N(UnkWattEffectFunc3), 1)
            EVT_CALL(AddGoalPos, ACTOR_SELF, 25, 10, 0)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 15, -10, 10)
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_3)
            EVT_CALL(FlyToGoal, ACTOR_SELF, 30, 0, 10)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, NPC_ANIM_battle_watt_Palette_00_Anim_1)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
