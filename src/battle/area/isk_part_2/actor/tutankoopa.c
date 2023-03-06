#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/Tutankoopa.h"
#include "sprite/npc/ChainChomp.h"
#include "sprite/npc/BuzzyBeetle.h"

#define NAMESPACE b_area_isk_part_2_tutankoopa

extern ActorBlueprint b_area_isk_part_2_chain_chomp;
extern EvtScript N(init_8021BC1C);
extern EvtScript N(takeTurn_8021CCD4);
extern EvtScript N(idle_8021BE28);
extern EvtScript N(handleEvent_8021BFD0);
extern EvtScript N(nextTurn_8021F9C4);
extern EvtScript N(8021C748);
extern EvtScript N(8021C974);
extern EvtScript N(8021D04C);
extern EvtScript N(8021D81C);
extern EvtScript N(8021DDE8);
extern EvtScript N(8021E008);
extern EvtScript N(8021E9C8);
extern EvtScript N(8021F42C);
extern EvtScript N(8021F5E8);
extern EvtScript N(8021F80C);
extern EvtScript N(8021FA54);

s32 N(IdleAnimations_8021B960)[] = {
    STATUS_NORMAL,    ANIM_Tutankoopa_Anim01,
    STATUS_STONE,     ANIM_Tutankoopa_Anim00,
    STATUS_SLEEP,     ANIM_Tutankoopa_Anim0C,
    STATUS_POISON,    ANIM_Tutankoopa_Anim01,
    STATUS_STOP,      ANIM_Tutankoopa_Anim00,
    STATUS_STATIC,    ANIM_Tutankoopa_Anim00,
    STATUS_PARALYZE,  ANIM_Tutankoopa_Anim00,
    STATUS_PARALYZE,  ANIM_Tutankoopa_Anim00,
    STATUS_DIZZY,     ANIM_Tutankoopa_Anim0A,
    STATUS_END,
};

s32 N(IdleAnimations_8021B9AC)[] = {
    STATUS_NORMAL,    ANIM_Tutankoopa_Anim0A,
    STATUS_STONE,     ANIM_Tutankoopa_Anim07,
    STATUS_SLEEP,     ANIM_Tutankoopa_Anim0D,
    STATUS_POISON,    ANIM_Tutankoopa_Anim0A,
    STATUS_STOP,      ANIM_Tutankoopa_Anim07,
    STATUS_STATIC,    ANIM_Tutankoopa_Anim0A,
    STATUS_PARALYZE,  ANIM_Tutankoopa_Anim0A,
    STATUS_PARALYZE,  ANIM_Tutankoopa_Anim0A,
    STATUS_DIZZY,     ANIM_Tutankoopa_Anim0A,
    STATUS_END,
};

s32 N(IdleAnimations_8021B9F8)[] = {
    STATUS_NORMAL,    ANIM_BuzzyBeetle_Anim06,
    STATUS_END,
};

s32 N(IdleAnimations_8021BA04)[] = {
    STATUS_NORMAL,    ANIM_Tutankoopa_Anim16,
    STATUS_END,
};

s32 N(IdleAnimations_8021BA10)[] = {
    STATUS_NORMAL,    ANIM_Tutankoopa_Anim16,
    STATUS_END,
};

s32 N(DefenseTable_8021BA1C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable_8021BA28)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 20,
    STATUS_POISON, 0,
    STATUS_FROZEN, 0,
    STATUS_DIZZY, 30,
    STATUS_FEAR, 0,
    STATUS_STATIC, 0,
    STATUS_PARALYZE, 30,
    STATUS_SHRINK, 60,
    STATUS_STOP, 40,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, -1,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, -1,
    STATUS_SHRINK_TURN_MOD, -1,
    STATUS_STOP_TURN_MOD, -2,
    STATUS_END,
};

ActorPartBlueprint N(PartsTable_8021BAD4)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 40 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021B960),
        .defenseTable = N(DefenseTable_8021BA1C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET,
        .index = 2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 39 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021B960),
        .defenseTable = N(DefenseTable_8021BA1C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -5, -15 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_40000000,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021B9F8),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_40000000,
        .index = 4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021B9F8),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION | ACTOR_PART_FLAG_40000000,
        .index = 5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021B9F8),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 6,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021BA04),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 7,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021BA04),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 8,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_8021BA10),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_TUTANKOOPA,
    .level = 55,
    .maxHP = 30,
    .partCount = ARRAY_COUNT( N(PartsTable_8021BAD4)),
    .partsData = N(PartsTable_8021BAD4),
    .initScript = &N(init_8021BC1C),
    .statusTable = N(StatusTable_8021BA28),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 70,
    .coinReward = 0,
    .size = { 56, 45 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 35 },
    .statusMessageOffset = { 10, 35 },
};

#include "common/UnkBattleFunc1.inc.c"

API_CALLABLE(func_8021875C_4EFBFC) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);
    EffectInstance* effect = fx_floating_rock(2, var1, 150.0f, var3, var2, -0.5f, -0.9f, 0.5f, 60);

    effect->data.floatingRock->unk_30.x = 0;
    effect->data.floatingRock->unk_30.z = 0;
    effect->data.floatingRock->unk_30.y = 0;
    return ApiStatus_DONE2;
}

EvtScript N(init_8021BC1C) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn_8021CCD4)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle_8021BE28)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent_8021BFD0)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn_8021F9C4)))
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_CALL(ForceHomePos, ACTOR_SELF, 97, 70, 15)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, 70, 70, 3)
    EVT_CALL(SetPartPos, ACTOR_SELF, 4, 80, 70, -7)
    EVT_CALL(SetPartPos, ACTOR_SELF, 5, 60, 70, -7)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 4, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, 3)
    EVT_CALL(SetActorVar, ACTOR_SELF, 6, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 11, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 12, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 13, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_8021BE28) = {
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_DIZZY)
                EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, -10, 22)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 2, 2, -8)
                EVT_CALL(N(UnkBattleFunc1), -25, 15, 0, 20)
            EVT_ELSE
                EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, 0, 39)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 2, -5, -15)
                EVT_CALL(N(UnkBattleFunc1), -17, 23, 11, 32)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, 2, -10, 22)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, 2, 2, -8)
            EVT_CALL(N(UnkBattleFunc1), -25, 15, 0, 20)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_8021BFD0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetActorScale, ACTOR_SELF, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(GetLastElement, LVarE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Anim06)
            EVT_EXEC_WAIT(DoNormalHit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Anim06)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(GetActorVar, ACTOR_SELF, 13, LVar2)
            EVT_IF_NE(LVar2, 0)
                EVT_CALL(SetActorVar, ACTOR_SELF, 13, 0)
                EVT_EXEC_WAIT(N(8021C974))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BEGIN_FIRST_STRIKE)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, 6815762)
            EVT_SET(LVar2, 6815763)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET(LVar0, 1)
            EVT_SET(LVar1, 6815762)
            EVT_SET(LVar2, 6815763)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Anim13)
            EVT_EXEC_WAIT(N(8021FA54))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_EXEC_WAIT(N(8021C748))
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Anim0E)
            EVT_EXEC_WAIT(DoShockHit)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Anim06)
            EVT_EXEC_WAIT(DoJumpBack)
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Anim02)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.6))
            EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
        EVT_CASE_OR_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, 1)
            EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar1)
            EVT_IF_EQ(LVar1, 1)
                EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
                EVT_IF_NE(LVar1, 0)
                    EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Anim0A)
                EVT_ELSE
                    EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Anim01)
                EVT_END_IF
            EVT_ELSE
                EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Anim01)
            EVT_END_IF
            EVT_EXEC_WAIT(DoImmune)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_TAUNT)
            EVT_CALL(GetActorVar, ACTOR_SELF, 1, LVar1)
            EVT_IF_EQ(LVar1, 0)
                EVT_IF_FLAG(LVarE, DAMAGE_TYPE_JUMP)
                    EVT_CALL(GetActorVar, ACTOR_SELF, 11, LVar0)
                    EVT_IF_EQ(LVar0, 0)
                        EVT_CALL(SetActorVar, ACTOR_SELF, 11, 1)
                        EVT_WAIT(60)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_IF
        EVT_CASE_OR_EQ(EVENT_SHOCK_DEATH)
        EVT_CASE_OR_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Anim06)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Anim06)
            EVT_EXEC_WAIT(N(8021FA54))
            EVT_RETURN
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_EXEC_WAIT(N(8021C748))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Anim06)
            EVT_EXEC_WAIT(N(8021FA54))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim06)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim02)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim01)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim06)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim02)
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
            EVT_CALL(RunToGoal, ACTOR_SELF, 0, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim01)
        EVT_CASE_EQ(EVENT_END_FIRST_STRIKE)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Anim01)
            EVT_EXEC_WAIT(DoReturnHome)
            EVT_CALL(HPBarToHome, ACTOR_SELF)
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_Tutankoopa_Anim01)
            EVT_EXEC_WAIT(DoRecover)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021C748) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim06)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetGoalPos, ACTOR_SELF, 150, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 0, FALSE, TRUE, FALSE)
    EVT_SUB(LVar1, 20)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetActorSpeed, ACTOR_SELF, EVT_FLOAT(6.0))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 130, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 5, FALSE, TRUE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim07)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim08)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim02)
    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim01)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021C974) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(func_8027D32C, ACTOR_SELF)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E3)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim06)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.9))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 10)
    EVT_SET(LVar1, 0)
    EVT_ADD(LVar2, 24)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    EVT_THREAD
        EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(1.1), EVT_FLOAT(0.5), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(1.0), EVT_FLOAT(0.7), EVT_FLOAT(1.0))
        EVT_WAIT(1)
        EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_THREAD
    EVT_CALL(StartRumble, 1)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E4)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim07)
    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(3.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 40)
    EVT_PLAY_EFFECT(EFFECT_STARS_ORBITING, 0, LVar0, LVar1, LVar2, 20, 4, LVarF, 0)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim0A)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E5)
    EVT_WAIT(30)
    EVT_CALL(RemoveEffect, LVarF)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 2)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_8021B9AC)))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_8021CCD4) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_LABEL(0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_CALL(GetActorVar, ACTOR_SELF, 12, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_EXEC_WAIT(N(8021E9C8))
                EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
                EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
                EVT_RETURN
            EVT_ELSE
                EVT_SUB(LVar0, 1)
                EVT_CALL(SetActorVar, ACTOR_SELF, 12, LVar0)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
            EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
        EVT_END_IF
        EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
                EVT_IF_EQ(LVar0, 0)
                    EVT_EXEC_WAIT(N(8021D81C))
                    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
                EVT_ELSE
                    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SHRINK)
                        EVT_EXEC_WAIT(N(8021D04C))
                        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
                    EVT_ELSE
                        EVT_EXEC_WAIT(N(8021D81C))
                        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
                    EVT_END_IF
                EVT_END_IF
            EVT_CASE_DEFAULT
                EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
                EVT_EXEC_WAIT(N(8021D81C))
        EVT_END_SWITCH
        EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_ELSE
        EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
        EVT_EXEC_WAIT(N(8021F80C))
        EVT_EXEC_WAIT(N(8021F5E8))
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_RETURN
    EVT_END
};

EvtScript N(8021D04C) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetActorVar, ACTOR_SELF, 2, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(1)
            EVT_SET(LVar9, 5)
        EVT_CASE_EQ(2)
            EVT_SET(LVar9, 4)
        EVT_CASE_EQ(3)
            EVT_SET(LVar9, 3)
        EVT_CASE_DEFAULT
            EVT_RETURN
    EVT_END_SWITCH
    EVT_SUB(LVar0, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 2, LVar0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
    EVT_CALL(SetBattleCamZoom, 320)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(BattleCamTargetActorPart, ACTOR_SELF, LVar9)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim02)
    EVT_CALL(GetPartOffset, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_SUB(LVar2, 3)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim01)
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim04)
    EVT_WAIT(7)
    EVT_CALL(GetPartOffset, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 20)
    EVT_ADD(LVar1, 40)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar9, EVT_FLOAT(0.8))
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 5, TRUE)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_SELF, LVar9, ANIM_BuzzyBeetle_Anim05)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2F9)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim05)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar9, EVT_FLOAT(14.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar9, EVT_FLOAT(0.2))
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_SET(LVar1, -5)
            EVT_CALL(FlyPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 0, 30, EASING_LINEAR)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 65)
            EVT_SET(LVar1, -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar9, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar9, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 0, 15, EASING_LINEAR)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar9, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(SetGoalToHome, ACTOR_SELF)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim02)
            EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim01)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim05)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar9, EVT_FLOAT(14.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar9, EVT_FLOAT(0.2))
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar9, EVT_FLOAT(0.2))
    EVT_CALL(FlyPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 0, 30, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar8, DAMAGE_TYPE_NO_CONTACT, 0, 0, 3, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 55)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar9, EVT_FLOAT(6.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar9, EVT_FLOAT(0.1))
    EVT_CALL(FlyPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 0, 25, EASING_LINEAR)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, LVar9, EVT_FLOAT(4.0))
    EVT_SUB(LVar0, 20)
    EVT_CALL(FlyPartTo, ACTOR_SELF, LVar9, LVar0, LVar1, LVar2, 0, 21, EASING_LINEAR)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar9, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_WAIT(19)
    EVT_IF_EQ(LVar8, HIT_RESULT_10)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(YieldTurn)
    EVT_CALL(SetGoalToHome, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim02)
    EVT_CALL(RunToGoal, ACTOR_SELF, 10, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim01)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021D81C) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
    EVT_CALL(SetBattleCamZoom, 350)
    EVT_CALL(SetBattleCamOffsetZ, 0)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetActorVar, ACTOR_SELF, 6, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(ActorSpeak, MSG_CH2_00E5, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim03, ANIM_Tutankoopa_Anim03)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim03)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_HIEROGLYPHS, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 45, 0)
    EVT_WAIT(30)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 70)
    EVT_CALL(PlaySound, SOUND_20E7)
    EVT_PLAY_EFFECT(EFFECT_CHOMP_DROP, 0, 0, 60, 0, EVT_FLOAT(0.2), 0, EVT_FLOAT(1.4), 255, EVT_FLOAT(0.1), 150, 0)
    EVT_WAIT(15)
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP | STATUS_FLAG_TRANSPARENT)
        EVT_CALL(UseIdleAnimation, ACTOR_PLAYER, FALSE)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Flail)
        EVT_WAIT(49)
        EVT_CALL(PlaySound, SOUND_20E9)
        EVT_WAIT(5)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim05)
        EVT_WAIT(8)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Crouch)
        EVT_WAIT(5)
        EVT_CALL(StartRumble, 10)
        EVT_CALL(PlaySound, SOUND_20EA)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 5, EVT_FLOAT(4.0))
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Question)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_PLAY_EFFECT(EFFECT_EMOTE, 2, 0, LVar0, LVar1, LVar2, 20, 315, 30, 0, 0)
        EVT_CALL(PlaySound, SOUND_20E8)
    EVT_ELSE
        EVT_WAIT(50)
        EVT_CALL(PlaySound, SOUND_20E9)
        EVT_WAIT(18)
        EVT_CALL(StartRumble, 10)
        EVT_CALL(PlaySound, SOUND_20EA)
        EVT_WAIT(20)
        EVT_CALL(PlaySound, SOUND_20E8)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, 6, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 1)
            EVT_EXEC_WAIT(N(8021E008))
        EVT_CASE_EQ(1)
            EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
            EVT_CALL(SetActorVar, ACTOR_SELF, 6, 2)
            EVT_IF_GT(LVar0, 2)
                EVT_EXEC_WAIT(N(8021DDE8))
            EVT_ELSE
                EVT_EXEC_WAIT(N(8021E008))
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_CALL(RandInt, 2, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
                EVT_IF_GT(LVar0, 2)
                    EVT_EXEC_WAIT(N(8021DDE8))
                EVT_ELSE
                    EVT_EXEC_WAIT(N(8021E008))
                EVT_END_IF
            EVT_ELSE
                EVT_EXEC_WAIT(N(8021E008))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8021DDE8) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_ENEMY0)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, 170)
    EVT_CALL(SetPartPos, ACTOR_SELF, 8, LVar0, LVar3, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 8, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 8, ANIM_Tutankoopa_Anim16)
    EVT_CALL(PlaySound, SOUND_20EB)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 8, EVT_FLOAT(8.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 8, EVT_FLOAT(0.3))
    EVT_CALL(FallPartTo, ACTOR_SELF, 8, LVar0, LVar1, LVar2, 20)
    EVT_THREAD
        EVT_LOOP(20)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 8, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 8, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetStatusFlags, ACTOR_PLAYER, LVar0)
    EVT_IF_NOT_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_ThumbsUp)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 13, 1)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021E008) = {
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, 0, 0, 1, BS_FLAGS1_10)
    EVT_SWITCH(LVarA)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_THREAD
                EVT_LOOP(6)
                    EVT_CALL(RandInt, 120, LVar0)
                    EVT_SUB(LVar0, 150)
                    EVT_CALL(RandInt, 90, LVar1)
                    EVT_SUB(LVar0, 40)
                    EVT_CALL(PlaySound, SOUND_20EB)
                    EVT_CALL(func_8021875C_4EFBFC, LVar0, 0, LVar1)
                    EVT_CALL(RandInt, 5, LVar0)
                    EVT_ADD(LVar0, 5)
                    EVT_WAIT(LVar0)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarB, 0, 0, 1, BS_FLAGS1_10)
            EVT_SWITCH(LVarB)
                EVT_CASE_EQ(HIT_RESULT_MISS)
                    EVT_RETURN
                EVT_CASE_DEFAULT
                    EVT_CALL(func_8026BF48, 1)
                    EVT_THREAD
                        EVT_CALL(PlaySound, SOUND_20EB)
                        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
                        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
                        EVT_SUB(LVar0, 5)
                        EVT_SET(LVar1, 0)
                        EVT_SET(LVar3, 170)
                        EVT_CALL(SetPartPos, ACTOR_SELF, 6, LVar0, LVar3, LVar2)
                        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                        EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Tutankoopa_Anim16)
                        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(8.0))
                        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.3))
                        EVT_CALL(FallPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 20)
                        EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Tutankoopa_Anim17)
                        EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                            EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
                        EVT_END_IF
                    EVT_END_THREAD
                    EVT_WAIT(25)
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
                    EVT_SUB(LVar4, 5)
                    EVT_ADD(LVar5, 5)
                    EVT_SET(LVar7, 170)
                    EVT_CALL(SetPartPos, ACTOR_SELF, 7, LVar4, LVar7, LVar6)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 7, ACTOR_PART_FLAG_INVISIBLE, FALSE)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 7, ANIM_Tutankoopa_Anim16)
                    EVT_CALL(PlaySound, SOUND_20EB)
                    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 7, EVT_FLOAT(8.0))
                    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 7, EVT_FLOAT(0.3))
                    EVT_CALL(FallPartTo, ACTOR_SELF, 7, LVar4, LVar5, LVar6, 20)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Tutankoopa_Anim17)
                    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
                    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
                    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
                    EVT_WAIT(20)
                    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 7, ACTOR_PART_FLAG_INVISIBLE, TRUE)
                    EVT_CALL(func_8026BF48, 0)
                    EVT_RETURN
            EVT_END_SWITCH
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_LOOP(6)
            EVT_CALL(RandInt, 120, LVar0)
            EVT_SUB(LVar0, 150)
            EVT_CALL(RandInt, 90, LVar1)
            EVT_SUB(LVar0, 40)
            EVT_CALL(PlaySound, SOUND_20EB)
            EVT_CALL(func_8021875C_4EFBFC, LVar0, 0, LVar1)
            EVT_CALL(RandInt, 5, LVar0)
            EVT_ADD(LVar0, 5)
            EVT_WAIT(LVar0)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(func_8026BF48, 1)
    EVT_THREAD
        EVT_WAIT(25)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(GetGoalPos, ACTOR_SELF, LVar4, LVar5, LVar6)
        EVT_SUB(LVar4, 5)
        EVT_ADD(LVar5, 5)
        EVT_SET(LVar7, 170)
        EVT_CALL(SetPartPos, ACTOR_SELF, 7, LVar4, LVar7, LVar6)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 7, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, 7, ANIM_Tutankoopa_Anim16)
        EVT_CALL(PlaySound, SOUND_20EB)
        EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 7, EVT_FLOAT(8.0))
        EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 7, EVT_FLOAT(0.3))
        EVT_CALL(FallPartTo, ACTOR_SELF, 7, LVar4, LVar5, LVar6, 20)
        EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Tutankoopa_Anim17)
        EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PARTNER)
        EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_WAIT(20)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, 7, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_CALL(func_8026BF48, 0)
    EVT_END_THREAD
    EVT_CALL(PlaySound, SOUND_20EB)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 5)
    EVT_ADD(LVar1, 5)
    EVT_SET(LVar3, 170)
    EVT_CALL(SetPartPos, ACTOR_SELF, 6, LVar0, LVar3, LVar2)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Tutankoopa_Anim16)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 6, EVT_FLOAT(8.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 6, EVT_FLOAT(0.3))
    EVT_CALL(FallPartTo, ACTOR_SELF, 6, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetAnimation, ACTOR_SELF, 6, ANIM_Tutankoopa_Anim17)
    EVT_WAIT(2)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_WAIT(19)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 6, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_IF_EQ(LVar0, HIT_RESULT_10)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

Vec3i N(vector3D_8021E9A0) = { 190, 0, 0 };

Formation N(specialFormation_8021E9AC) = {
    { .actor = &b_area_isk_part_2_chain_chomp, .home = { .vec = &N(vector3D_8021E9A0) }, .priority = 100 },
};

EvtScript N(8021E9C8) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim03)
        EVT_CALL(ActorSpeak, MSG_CH2_00E6, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim03, ANIM_Tutankoopa_Anim03)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim03)
        EVT_CALL(ActorSpeak, MSG_CH2_00E7, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim03, ANIM_Tutankoopa_Anim03)
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim01)
    EVT_CALL(GetActorVar, ACTOR_SELF, 8, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
        EVT_CALL(SetBattleCamZoom, 225)
        EVT_CALL(SetBattleCamOffsetZ, -30)
        EVT_CALL(MoveBattleCamOver, 40)
    EVT_ELSE
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(func_8024ECF8, -1, 1, 0)
        EVT_CALL(SetBattleCamZoom, 200)
        EVT_CALL(SetBattleCamOffsetZ, 35)
        EVT_CALL(MoveBattleCamOver, 40)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, 0)
    EVT_THREAD
        EVT_LABEL(0)
        EVT_CALL(StartRumble, 1)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_WAIT(1)
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
        EVT_IF_LT(LVar0, 60)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(PlaySound, SOUND_26B)
    EVT_LABEL(10)
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVarD)
    EVT_CALL(TranslateModel, 31, 0, LVarD, 0)
    EVT_ADD(LVarD, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, LVarD)
    EVT_WAIT(1)
    EVT_IF_LT(LVarD, 60)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(StopSound, SOUND_26B)
    EVT_WAIT(10)
    EVT_CALL(SummonEnemy, EVT_PTR(N(specialFormation_8021E9AC)), 0)
    EVT_SET(LVarB, LVar0)
    EVT_SET(LVar0, 165)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, -30)
    EVT_CALL(SetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(SetActorDispOffset, LVarB, 0, 0, 0)
    EVT_CALL(UseIdleAnimation, LVarB, FALSE)
    EVT_CALL(EnableIdleScript, LVarB, 0)
    EVT_CALL(SetAnimation, LVarB, 1, ANIM_ChainChomp_Anim05)
    EVT_CALL(SetActorSpeed, LVarB, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, LVarB, EVT_FLOAT(0.8))
    EVT_SET(LVar0, 90)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, -30)
    EVT_SET(LVar3, 8)
    EVT_SET(LVar4, 30)
    EVT_EXEC_WAIT(N(8021F42C))
    EVT_CALL(GetActorVar, ACTOR_SELF, 3, LVar5)
    EVT_IF_EQ(LVar5, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
        EVT_CALL(SetBattleCamZoom, 160)
        EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
        EVT_SET(LVar1, 60)
        EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
        EVT_CALL(MoveBattleCamOver, 8)
        EVT_LOOP(3)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamZoom, 150)
            EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
            EVT_CALL(MoveBattleCamOver, 5)
            EVT_WAIT(4)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2061)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
            EVT_CALL(SetBattleCamZoom, 200)
            EVT_CALL(SetBattleCamTarget, LVar0, LVar1, LVar2)
            EVT_CALL(MoveBattleCamOver, 5)
            EVT_WAIT(4)
        EVT_END_LOOP
    EVT_ELSE
        EVT_WAIT(8)
        EVT_CALL(SetGoalPos, LVarB, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, LVarB, 8, FALSE, TRUE, FALSE)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_THREAD
        EVT_CALL(SetGoalPos, LVarB, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, LVarB, 8, FALSE, TRUE, FALSE)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_THREAD
        EVT_WAIT(8)
    EVT_END_IF
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetActorSpeed, LVarB, EVT_FLOAT(3.0))
    EVT_CALL(SetActorJumpGravity, LVarB, EVT_FLOAT(0.8))
    EVT_SET(LVar0, 20)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 20)
    EVT_SET(LVar3, 8)
    EVT_SET(LVar4, 20)
    EVT_EXEC_WAIT(N(8021F42C))
    EVT_CALL(GetActorPos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, LVarB, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, LVarB, 2, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, LVarB)
    EVT_CALL(SetActorSpeed, LVarB, EVT_FLOAT(6.0))
    EVT_CALL(SetActorJumpGravity, LVarB, EVT_FLOAT(0.8))
    EVT_CALL(EnableIdleScript, LVarB, 1)
    EVT_CALL(UseIdleAnimation, LVarB, TRUE)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, 60)
    EVT_THREAD
        EVT_LABEL(40)
        EVT_CALL(StartRumble, 1)
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_WAIT(1)
        EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_GOTO(40)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(PlaySound, SOUND_26B)
    EVT_LABEL(50)
    EVT_CALL(GetActorVar, ACTOR_SELF, 5, LVarD)
    EVT_CALL(TranslateModel, 31, 0, LVarD, 0)
    EVT_SUB(LVarD, 1)
    EVT_CALL(SetActorVar, ACTOR_SELF, 5, LVarD)
    EVT_WAIT(1)
    EVT_IF_GT(LVarD, 0)
        EVT_GOTO(50)
    EVT_END_IF
    EVT_CALL(StopSound, SOUND_26B)
    EVT_CALL(PlaySound, SOUND_26C)
    EVT_CALL(ShakeCam, CAM_BATTLE, 0, 4, EVT_FLOAT(0.5))
    EVT_CALL(SetActorVar, ACTOR_SELF, 3, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021F42C) = {
    EVT_LABEL(20)
    EVT_CALL(GetActorPos, LVarB, LVar5, LVar6, LVar7)
    EVT_IF_EQ(LVar5, LVar0)
        EVT_GOTO(30)
    EVT_END_IF
    EVT_SET(LVar6, LVar5)
    EVT_SUB(LVar6, LVar0)
    EVT_IF_LT(LVar6, LVar4)
        EVT_CALL(SetGoalPos, LVarB, LVar0, LVar1, LVar2)
        EVT_CALL(JumpToGoal, LVarB, LVar3, FALSE, TRUE, FALSE)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_THREAD
    EVT_ELSE
        EVT_SUB(LVar5, LVar4)
        EVT_CALL(SetGoalPos, LVarB, LVar5, LVar1, LVar2)
        EVT_CALL(JumpToGoal, LVarB, LVar3, FALSE, TRUE, FALSE)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_2062)
        EVT_THREAD
            EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_END_THREAD
    EVT_END_IF
    EVT_GOTO(20)
    EVT_LABEL(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021F5E8) = {
    EVT_CALL(SetActorVar, ACTOR_SELF, 7, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E1)
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim08)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_PLAY_EFFECT(EFFECT_HIEROGLYPHS, 0, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 45, 0)
    EVT_WAIT(45)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 60)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20E6)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(0.1))
    EVT_CALL(SetGoalPos, ACTOR_SELF, 97, 70, 15)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 45, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BA)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3B4)
    EVT_END_THREAD
    EVT_WAIT(5)
    EVT_CALL(SetActorVar, ACTOR_SELF, 8, 0)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(HPBarToHome, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(8021F80C) = {
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim08)
    EVT_CALL(SetActorJumpGravity, ACTOR_SELF, EVT_FLOAT(1.0))
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_20BA)
    EVT_THREAD
        EVT_WAIT(1)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_3B4)
    EVT_END_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim01)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_8021B960)))
    EVT_WAIT(10)
    EVT_CALL(GetActorVar, ACTOR_SELF, 4, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_WAIT(20)
        EVT_CALL(ActorSpeak, MSG_CH2_00E4, ACTOR_SELF, 1, ANIM_Tutankoopa_Anim0B, ANIM_Tutankoopa_Anim01)
        EVT_CALL(SetActorVar, ACTOR_SELF, 4, 1)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn_8021F9C4) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_PLAYER_BEGIN)
            EVT_CALL(GetActorVar, ACTOR_SELF, 10, LVar0)
            EVT_SWITCH(LVar0)
                EVT_CASE_EQ(0)
                    EVT_CALL(SetActorVar, ACTOR_SELF, 10, 1)
            EVT_END_SWITCH
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8021FA54) = {
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar2)
    EVT_IF_NE(LVar2, FALSE)
        EVT_CALL(GetActorHP, ACTOR_ENEMY1, LVar2)
        EVT_IF_NE(LVar2, 0)
            EVT_THREAD
                EVT_CALL(func_8027D32C, ACTOR_ENEMY1)
                EVT_CALL(EnableIdleScript, ACTOR_ENEMY1, 0)
                EVT_CALL(UseIdleAnimation, ACTOR_ENEMY1, FALSE)
                EVT_CALL(SetAnimation, ACTOR_ENEMY1, 1, ANIM_ChainChomp_Anim06)
                EVT_WAIT(10)
                EVT_SET(LVar2, 0)
                EVT_LOOP(24)
                    EVT_CALL(SetActorYaw, ACTOR_ENEMY1, LVar2)
                    EVT_ADD(LVar2, 30)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(SetActorYaw, ACTOR_ENEMY1, 0)
                EVT_CALL(GetActorPos, ACTOR_ENEMY1, LVar0, LVar1, LVar2)
                EVT_ADD(LVar1, 10)
                EVT_PLAY_EFFECT(EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0)
                EVT_CALL(PlaySoundAtActor, ACTOR_ENEMY1, SOUND_DEATH)
                EVT_SET(LVar3, 0)
                EVT_LOOP(12)
                    EVT_CALL(SetActorRotation, ACTOR_ENEMY1, LVar3, 0, 0)
                    EVT_ADD(LVar3, 8)
                    EVT_WAIT(1)
                EVT_END_LOOP
                EVT_CALL(RemoveActor, ACTOR_ENEMY1)
            EVT_END_THREAD
        EVT_END_IF
    EVT_END_IF
    EVT_EXEC_WAIT(D_8029AF08)
    EVT_LABEL(0)
    EVT_CALL(ActorExists, ACTOR_ENEMY1, LVar0)
    EVT_IF_NE(LVar0, FALSE)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(RemoveActor, ACTOR_SELF)
    EVT_RETURN
    EVT_END
};
