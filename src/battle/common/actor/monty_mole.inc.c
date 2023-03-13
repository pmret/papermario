#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/MontyMole.h"

extern s32 N(IdleAnimations)[];
extern s32 N(IdleAnimations2)[];
extern EvtScript N(init);
extern EvtScript N(takeTurn);
extern EvtScript N(idle);
extern EvtScript N(handleEvent);

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_NORMAL, 0,
    STATUS_DEFAULT, 0,
    STATUS_SLEEP, 90,
    STATUS_POISON, 80,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 90,
    STATUS_FEAR, 0,
    STATUS_STATIC, 10,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 90,
    STATUS_STOP, 100,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, -1,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 1,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -2, 16 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -7 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_MULTI_TARGET | ACTOR_PART_FLAG_80000000,
        .index = 2,
        .posOffset = { 0, 0, -15 },
        .targetOffset = { -2, 12 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -7 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = 3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations2),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_MONTY_MOLE,
    .level = 8,
    .maxHP = 3,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(StatusTable),
    .escapeChance = 80,
    .airLiftChance = 70,
    .hurricaneChance = 50,
    .spookChance = 85,
    .upAndAwayChance = 95,
    .spinSmashReq = 4,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 34, 18 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

s32 N(IdleAnimations)[] = {
    STATUS_NORMAL,    ANIM_MontyMole_Anim01,
    STATUS_STONE,     ANIM_MontyMole_Anim00,
    STATUS_SLEEP,     ANIM_MontyMole_Anim14,
    STATUS_POISON,    ANIM_MontyMole_Anim01,
    STATUS_STOP,      ANIM_MontyMole_Anim00,
    STATUS_STATIC,    ANIM_MontyMole_Anim01,
    STATUS_PARALYZE,  ANIM_MontyMole_Anim00,
    STATUS_DIZZY,     ANIM_MontyMole_Anim14,
    STATUS_FEAR,      ANIM_MontyMole_Anim14,
    STATUS_END,
};

s32 N(IdleAnimations2)[] = {
    STATUS_NORMAL,    ANIM_MontyMole_Anim0F,
    STATUS_END,
};

s32 N(IdleAnimations_hole)[] = {
    STATUS_NORMAL,    ANIM_MontyMole_Anim12,
    STATUS_END,
};


s32 N(IdleAnimations_unused)[] = {
    STATUS_NORMAL,    ANIM_MontyMole_Anim06,
    STATUS_END,
};

ActorPartBlueprint N(parts_hole)[] = {
    {
        .flags = ACTOR_PART_FLAG_2000 | ACTOR_PART_FLAG_NO_TARGET,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(IdleAnimations_hole),
        .defenseTable = NULL,
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

EvtScript N(init_hole) = {
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(SetPartScale, ACTOR_SELF, 1, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

ActorBlueprint N(hole) = {
    .flags = ACTOR_FLAG_NO_SHADOW | ACTOR_FLAG_HIDE_HP_BAR | ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY,
    .type = ACTOR_TYPE_MONTY_HOLE,
    .level = 9,
    .maxHP = 5,
    .partCount = ARRAY_COUNT(N(parts_hole)),
    .partsData = N(parts_hole),
    .initScript = &N(init_hole),
    .statusTable = NULL,
    .escapeChance = 80,
    .airLiftChance = 0,
    .hurricaneChance = 80,
    .spookChance = 80,
    .upAndAwayChance = 90,
    .spinSmashReq = 4,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 32, 18 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusMessageOffset = { 10, 20 },
};

Vec3i N(hole_pos) = { NPC_DISPOSE_LOCATION, };

Formation N(formation_hole_1) = {
    { .actor = &N(hole), .home = { .vec = &N(hole_pos) },},
};

Formation N(formation_hole_2) = {
    { .actor = &N(hole), .home = { .vec = &N(hole_pos) }, .var0 = 1 },
};

EvtScript N(makeHole) = {
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SummonEnemy, EVT_PTR(N(formation_hole_2)), 0)
    EVT_ELSE
        EVT_CALL(SummonEnemy, EVT_PTR(N(formation_hole_1)), 0)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_SUB(LVar3, 1)
    EVT_CALL(SetActorPos, LVar0, LVar1, LVar2, LVar3)
    EVT_RETURN
    EVT_END
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(GetLastElement, LVarE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_IF_FLAG(LVarE, DAMAGE_TYPE_SMASH)
                EVT_CHILD_THREAD
                    EVT_WAIT(8)
                    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim07)
                EVT_END_CHILD_THREAD
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_MontyMole_Anim06)
                EVT_EXEC_WAIT(DoNormalHit)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim08)
                EVT_WAIT(10)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_MontyMole_Anim05)
                EVT_EXEC_WAIT(DoNormalHit)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_MontyMole_Anim0A)
            EVT_SET_CONST(LVar2, ANIM_MontyMole_Anim0B)
            EVT_EXEC_WAIT(DoBurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_MontyMole_Anim0A)
            EVT_SET_CONST(LVar2, ANIM_MontyMole_Anim0B)
            EVT_EXEC_WAIT(DoBurnHit)
            EVT_EXEC_WAIT(N(makeHole))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_MontyMole_Anim0C)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(GetLastElement, LVar0)
            EVT_IF_FLAG(LVar0, DAMAGE_TYPE_SMASH)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim11)
                EVT_WAIT(80)
                EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
                EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim10)
                EVT_WAIT(20)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim14)
                EVT_WAIT(20)
            EVT_ELSE
                EVT_SET_CONST(LVar0, 1)
                EVT_SET_CONST(LVar1, ANIM_MontyMole_Anim01)
                EVT_EXEC_WAIT(DoImmune)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_MontyMole_Anim05)
            EVT_EXEC_WAIT(DoNormalHit)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim06)
            EVT_WAIT(10)
            EVT_EXEC_WAIT(N(makeHole))
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_MontyMole_Anim09)
            EVT_EXEC_WAIT(DoDeath)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim06)
            EVT_WAIT(8)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim07)
            EVT_WAIT(5)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim08)
            EVT_WAIT(8)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim06)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim07)
            EVT_WAIT(15)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim08)
            EVT_WAIT(15)
            EVT_CALL(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_TARGET_ONLY | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, 1, EVT_PTR(N(IdleAnimations_hole)))
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_MontyMole_Anim05)
            EVT_EXEC_WAIT(DoAirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_EXEC_WAIT(N(makeHole))
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_FLAG(LVar0, STATUS_FLAG_SLEEP | STATUS_FLAG_FROZEN | STATUS_FLAG_FEAR | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
                EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -5, 0)
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim19)
            EVT_ELSE
                EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -9, 0)
                EVT_ELSE
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, 0, -23, 0)
                EVT_END_IF
                EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim09)
            EVT_END_IF
            EVT_WAIT(1000)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(2.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim11)
            EVT_WAIT(40)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
            EVT_CALL(SetAnimationRate, ACTOR_SELF, 1, EVT_FLOAT(1.0))
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim10)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim14)
            EVT_WAIT(20)
        EVT_CASE_EQ(EVENT_UP_AND_AWAY)
            EVT_EXEC_WAIT(N(makeHole))
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 0)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_DIG)
        EVT_WAIT(20)
        EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_BURROW_SURFACE)
    EVT_END_CHILD_THREAD
    EVT_CALL(SetAnimation, ACTOR_SELF, 1, ANIM_MontyMole_Anim04)
    EVT_WAIT(37)
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetPartPos, ACTOR_SELF, 3, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, 3, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, 3, SOUND_MOLE_THROW)
    EVT_CALL(SetPartSounds, ACTOR_SELF, 3, ACTOR_SOUND_FLY, 0, 0)
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 100)
            EVT_SET(LVar1, -5)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 3, EVT_FLOAT(12.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 3, EVT_FLOAT(0.1))
            EVT_CALL(SetAnimation, ACTOR_SELF, 3, ANIM_MontyMole_Anim0F)
            EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LVar0, LVar1, LVar2, 0, 30, EASING_LINEAR)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_CALL(YieldTurn)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 3, EVT_FLOAT(12.0))
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 3, EVT_FLOAT(0.1))
    EVT_CALL(SetAnimation, ACTOR_SELF, 3, ANIM_MontyMole_Anim0F)
    EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LVar0, LVar1, LVar2, 0, 20, EASING_LINEAR)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 2, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 55)
            EVT_SET(LVar1, 0)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 3, EVT_FLOAT(6.0))
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, 3, EVT_FLOAT(0.1))
            EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LVar0, LVar1, LVar2, 0, 25, EASING_LINEAR)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, 3, EVT_FLOAT(4.0))
            EVT_SUB(LVar0, 20)
            EVT_CALL(FlyPartTo, ACTOR_SELF, 3, LVar0, LVar1, LVar2, 0, 21, EASING_LINEAR)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, 3, ACTOR_PART_FLAG_INVISIBLE, TRUE)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
