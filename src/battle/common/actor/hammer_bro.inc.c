#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/HammerBros.h"

#define NAMESPACE A(hammer_bro)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_HAMMER_1    = 2,
    PRT_HAMMER_2    = 3,
    PRT_HAMMER_3    = 4,
    PRT_HAMMER_4    = 5,
    PRT_HAMMER_5    = 6,
};

enum N(ActorVars) {
    AVAR_Unused     = 8, // possibly a topple state that was never implemented
};

enum N(ActorParams) {
    DMG_HAMMER_THROW    = 5,
    DMG_HAMMER_SURGE    = 2,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_HammerBros_Anim02,
    STATUS_KEY_STONE,     ANIM_HammerBros_Anim00,
    STATUS_KEY_SLEEP,     ANIM_HammerBros_Anim11,
    STATUS_KEY_POISON,    ANIM_HammerBros_Anim02,
    STATUS_KEY_STOP,      ANIM_HammerBros_Anim00,
    STATUS_KEY_STATIC,    ANIM_HammerBros_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_HammerBros_Anim00,
    STATUS_KEY_DIZZY,     ANIM_HammerBros_Anim12,
    STATUS_KEY_FEAR,      ANIM_HammerBros_Anim12,
    STATUS_END,
};

s32 N(HammerAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_HammerBros_Anim0D,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   1,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,             60,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              70,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,             80,
    STATUS_KEY_PARALYZE,           70,
    STATUS_KEY_SHRINK,             70,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -3, 35 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -3, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_HAMMER_1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(HammerAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_HAMMER_2,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(HammerAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_HAMMER_3,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(HammerAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_HAMMER_4,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(HammerAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_HAMMER_5,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(HammerAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_HAMMER_BROS,
    .level = ACTOR_LEVEL_HAMMER_BROS,
    .maxHP = 12,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 30,
    .airLiftChance = 75,
    .hurricaneChance = 60,
    .spookChance = 40,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 80,
    .coinReward = 2,
    .size = { 28, 38 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 35 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unused, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_FLAG(STATUS_FLAG_SLEEP)
                EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 15)
                EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
            EVT_CASE_DEFAULT
                EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unused, LVar0)
                EVT_SWITCH(LVar0)
                    EVT_CASE_EQ(0)
                        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -3, 35)
                        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -3, -10)
                    EVT_CASE_EQ(1)
                        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -5, 15)
                        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
                EVT_END_SWITCH
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0F)
            EVT_SET_CONST(LVar2, ANIM_HammerBros_Anim10)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0F)
            EVT_SET_CONST(LVar2, ANIM_HammerBros_Anim10)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim10)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim15)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HammerBros_Anim17)
                EVT_WAIT(10)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_WAIT(10)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_Recover)
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim07)
            EVT_SET_CONST(LVar2, ANIM_HammerBros_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_AirLift)
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
            EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -2, 1, 0)
                EVT_ELSE
                    EVT_CALL(SetActorDispOffset, ACTOR_SELF, -5, 3, 0)
                EVT_END_IF
            EVT_END_IF
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim0E)
            EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_HammerBros_Anim02)
            EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_HammerThrow) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 1)
    EVT_END_IF
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_IF_EQ(LVar0, PHASE_FIRST_STRIKE)
        EVT_CHILD_THREAD
            EVT_SET(LVar0, 0)
            EVT_LABEL(0)
            EVT_ADD(LVar0, 20)
            EVT_MOD(LVar0, 360)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_HAMMER_1, 0, 0, LVar0)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_CHILD_THREAD
        EVT_CALL(SetPartPos, ACTOR_SELF, PRT_HAMMER_1, 0, 50, 0)
        EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_HAMMER_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HammerBros_Anim0C)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CHILD_THREAD
        EVT_SET(LVar0, 0)
        EVT_LABEL(0)
        EVT_ADD(LVar0, 20)
        EVT_MOD(LVar0, 360)
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_HAMMER_1, 0, 0, LVar0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_CHILD_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 23)
    EVT_ADD(LVar1, 23)
    EVT_SUB(LVar2, 2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_HAMMER_1, LVar0, LVar1, LVar2)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HammerBros_Anim0C)
    EVT_WAIT(8)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_HAMMER_1, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_LABEL(100)
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HammerBros_Anim02)
    EVT_END_THREAD
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_HAMMER_1, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_HAMMER_1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_HAMMER_1, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_HAMMER_1, SOUND_HAMMER_BROS_THROW)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 20)
            EVT_SET(LVar1, 10)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_HAMMER_1, EVT_FLOAT(1.3))
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_HAMMER_1, LVar0, LVar1, LVar2, 15, TRUE)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVarA, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_SUB(LVar0, 40)
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_HAMMER_1, LVar0, LVar1, LVar2, 15, TRUE)
            EVT_SUB(LVar0, 30)
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_HAMMER_1, LVar0, LVar1, LVar2, 10, TRUE)
            EVT_SUB(LVar0, 20)
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_HAMMER_1, LVar0, LVar1, LVar2, 5, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_HAMMER_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_WAIT(20)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_HAMMER_1, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_HAMMER_1, SOUND_HAMMER_BROS_THROW)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_HAMMER_1, EVT_FLOAT(1.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_HAMMER_1, LVar0, LVar1, LVar2, 15, TRUE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, DMG_STATUS_KEY(STATUS_FLAG_SHRINK, 3, 50), DMG_HAMMER_THROW, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_HAMMER_1, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 50)
            EVT_SET(LVar1, 10)
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_HAMMER_1, LVar0, LVar1, LVar2, 20, TRUE)
            EVT_SUB(LVar0, 30)
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_HAMMER_1, LVar0, LVar1, LVar2, 10, TRUE)
            EVT_SUB(LVar0, 20)
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_HAMMER_1, LVar0, LVar1, LVar2, 5, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_HAMMER_1, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HammerSurge_Miss) = {
    EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(2.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HammerBros_Anim02)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HammerBros_Anim0C)
    EVT_WAIT(4)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetPartSounds, ACTOR_SELF, LVar0, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, LVar0, SOUND_HAMMER_BROS_THROW)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_SET(LVar2, 10)
    EVT_CALL(RandInt, 60, LVar4)
    EVT_SET(LVar5, 30)
    EVT_SUB(LVar5, LVar4)
    EVT_ADD(LVar1, LVar5)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar0, EVT_FLOAT(1.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3, 15, TRUE)
    EVT_SUB(LVar1, 50)
    EVT_SET(LVar2, 10)
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3, 20, TRUE)
    EVT_SUB(LVar1, 30)
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3, 10, TRUE)
    EVT_SUB(LVar1, 20)
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3, 5, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HammerSurge_Hit) = {
    EVT_CALL(SetAnimationRate, ACTOR_SELF, PRT_MAIN, EVT_FLOAT(2.0))
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HammerBros_Anim02)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HammerBros_Anim0C)
    EVT_WAIT(4)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(SetPartSounds, ACTOR_SELF, LVar0, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, LVar0, SOUND_HAMMER_BROS_THROW)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar1, LVar2, LVar3)
    EVT_CALL(SetPartJumpGravity, ACTOR_SELF, LVar0, EVT_FLOAT(1.3))
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3, 15, TRUE)
    EVT_SUB(LVar1, 50)
    EVT_SET(LVar2, 10)
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3, 20, TRUE)
    EVT_SUB(LVar1, 30)
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3, 10, TRUE)
    EVT_SUB(LVar1, 20)
    EVT_CALL(JumpPartTo, ACTOR_SELF, LVar0, LVar1, LVar2, LVar3, 5, TRUE)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, LVar0, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Attack_HammerSurge) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(100)
            EVT_ADD(LVar0, 20)
            EVT_MOD(LVar0, 360)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_HAMMER_1, 0, 0, LVar0)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_HAMMER_2, 0, 0, LVar0)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_HAMMER_3, 0, 0, LVar0)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_HAMMER_4, 0, 0, LVar0)
            EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_HAMMER_5, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 23)
    EVT_ADD(LVar1, 23)
    EVT_SUB(LVar2, 2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_HAMMER_1, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_HAMMER_2, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_HAMMER_3, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_HAMMER_4, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_HAMMER_5, LVar0, LVar1, LVar2)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_HAMMER_1, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_HAMMER_2, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_HAMMER_3, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_HAMMER_4, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_HAMMER_5, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_HAMMER_1, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_HAMMER_2, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_HAMMER_3, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_HAMMER_4, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_HAMMER_5, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarA, LVar0)
            EVT_SET(LVar0, PRT_HAMMER_1)
            EVT_EXEC(N(EVS_HammerSurge_Miss))
            EVT_WAIT(5)
            EVT_SET(LVar0, PRT_HAMMER_2)
            EVT_EXEC(N(EVS_HammerSurge_Miss))
            EVT_WAIT(5)
            EVT_SET(LVar0, PRT_HAMMER_3)
            EVT_EXEC(N(EVS_HammerSurge_Miss))
            EVT_WAIT(5)
            EVT_SET(LVar0, PRT_HAMMER_4)
            EVT_EXEC(N(EVS_HammerSurge_Miss))
            EVT_WAIT(5)
            EVT_SET(LVar0, PRT_HAMMER_5)
            EVT_EXEC(N(EVS_HammerSurge_Miss))
            EVT_WAIT(5)
            EVT_WAIT(20)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HammerBros_Anim02)
            EVT_IF_EQ(LVarA, HIT_RESULT_LUCKY)
                EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EVT_END_IF
            EVT_WAIT(15)
            EVT_CALL(YieldTurn)
            EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            EVT_WAIT(20)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
            EVT_RETURN
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_THREAD
        EVT_SET(LVar0, PRT_HAMMER_1)
        EVT_EXEC(N(EVS_HammerSurge_Hit))
        EVT_WAIT(5)
        EVT_SET(LVar0, PRT_HAMMER_2)
        EVT_EXEC(N(EVS_HammerSurge_Hit))
        EVT_WAIT(5)
        EVT_SET(LVar0, PRT_HAMMER_3)
        EVT_EXEC(N(EVS_HammerSurge_Hit))
        EVT_WAIT(5)
        EVT_SET(LVar0, PRT_HAMMER_4)
        EVT_EXEC(N(EVS_HammerSurge_Hit))
        EVT_WAIT(5)
        EVT_SET(LVar0, PRT_HAMMER_5)
        EVT_EXEC(N(EVS_HammerSurge_Hit))
    EVT_END_THREAD
    EVT_WAIT(21)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_HAMMER_SURGE, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_WAIT(5)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_HAMMER_SURGE, BS_FLAGS1_NICE_HIT)
    EVT_WAIT(5)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_HAMMER_SURGE, BS_FLAGS1_NICE_HIT)
    EVT_WAIT(5)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_HammerBros_Anim02)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_HAMMER_SURGE, BS_FLAGS1_NICE_HIT)
    EVT_WAIT(5)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, DMG_STATUS_KEY(STATUS_FLAG_SHRINK, 3, 50), DMG_HAMMER_SURGE, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_WAIT(20)
            EVT_CALL(YieldTurn)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetActorHP, ACTOR_SELF, LVar0)
    EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    EVT_MULF(LVar0, EVT_FLOAT(100.0))
    EVT_DIVF(LVar0, LVar1)
    EVT_IF_GT(LVar0, 34)
        EVT_EXEC_WAIT(N(EVS_Attack_HammerThrow))
    EVT_ELSE
        EVT_EXEC_WAIT(N(EVS_Attack_HammerSurge))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
