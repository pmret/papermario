#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/DryBones.h"

#define NAMESPACE A(dry_bones)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_BONE        = 2,
};

enum N(ActorVars) {
    AVAR_CollapseTurns  = 0,
    AVAR_Collapsed      = 8,
};

enum N(ActorParams) {
    DMG_UNK         = 0,
};

#define BASE_COLLAPSE_DURATION  2

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_DryBones_Anim02,
    STATUS_KEY_STONE,     ANIM_DryBones_Anim00,
    STATUS_KEY_SLEEP,     ANIM_DryBones_Anim0E,
    STATUS_KEY_POISON,    ANIM_DryBones_Anim02,
    STATUS_KEY_STOP,      ANIM_DryBones_Anim00,
    STATUS_KEY_STATIC,    ANIM_DryBones_Anim02,
    STATUS_KEY_PARALYZE,  ANIM_DryBones_Anim00,
    STATUS_KEY_DIZZY,     ANIM_DryBones_Anim0D,
    STATUS_KEY_FEAR,      ANIM_DryBones_Anim0D,
    STATUS_END,
};

s32 N(CollapsedAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_DryBones_Anim01,
    STATUS_END,
};

s32 N(BoneAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_DryBones_Anim0F,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   2,
    ELEMENT_FIRE,   -10,
    ELEMENT_BLAST,  -10,
    ELEMENT_END,
};

s32 N(CollapsedDefense)[] = {
    ELEMENT_NORMAL,  99,
    ELEMENT_FIRE,   -10,
    ELEMENT_BLAST,  -10,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           50,
    STATUS_KEY_SHRINK,             60,
    STATUS_KEY_STOP,               85,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

s32 N(CollapsedStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,                0,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -8, 30 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -10 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_NO_TARGET | ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION,
        .index = PRT_BONE,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = N(BoneAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_DRY_BONES,
    .level = ACTOR_LEVEL_DRY_BONES,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 75,
    .hurricaneChance = 70,
    .spookChance = 10,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 1,
    .size = { 28, 32 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -15, 15 },
    .statusTextOffset = { 3, 27 },
};

EvtScript N(EVS_Init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_SELF, EVT_PTR(N(EVS_HandlePhase)))
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Collapsed, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVarA)
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetOriginalActorType, LVar0, LVar2)
        EVT_IF_NE(LVar2, LVarA)
            EVT_CALL(GetActorHP, LVar0, LVar3)
            EVT_IF_NE(LVar3, 0)
                EVT_RETURN
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetActorVar, LVar0, AVAR_Collapsed, LVar3)
        EVT_IF_NE(LVar3, TRUE)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(2)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_LABEL(0)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Collapsed, LVar0)
        EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar1)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(0)
                EVT_SWITCH(LVar1)
                    EVT_CASE_FLAG(STATUS_FLAG_SLEEP)
                        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -6, 24)
                        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 1, -5)
                    EVT_CASE_DEFAULT
                        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -8, 30)
                        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -10)
                EVT_END_SWITCH
            EVT_CASE_EQ(1)
                EVT_SWITCH(LVar1)
                    EVT_CASE_FLAG(STATUS_FLAG_SLEEP)
                        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -1, 10)
                        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
                    EVT_CASE_DEFAULT
                        EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -1, 10)
                        EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
                EVT_END_SWITCH
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Collapse) = {
    EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DRY_BONES_COLLAPSE)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_DryBones_Anim08)
    EVT_WAIT(20)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Collapsed, TRUE)
    EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(CollapsedAnims)))
    EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(CollapsedDefense)))
    EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(CollapsedStatusTable)))
    EVT_CALL(ClearStatusEffects, ACTOR_SELF)
    EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -1, 10)
    EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
    EVT_CALL(RandInt, 0, LVar0)
    EVT_ADD(LVar0, BASE_COLLAPSE_DURATION)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CollapseTurns, LVar0)
    EVT_CALL(GetOriginalActorType, ACTOR_SELF, LVarA)
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetOriginalActorType, LVar0, LVar2)
        EVT_IF_NE(LVar2, LVarA)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(1)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(GetActorVar, LVar0, AVAR_Collapsed, LVar3)
        EVT_IF_NE(LVar3, TRUE)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_CALL(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(2)
        EVT_CALL(GetOwnerTarget, LVar0, LVar1)
        EVT_CALL(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(2)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, FALSE)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    EVT_CALL(GetLastEvent, ACTOR_SELF, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(EVENT_HIT_COMBO)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION, TRUE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim0B)
            EVT_SET_CONST(LVar2, ANIM_DryBones_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_CALL(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION, FALSE)
        EVT_CASE_EQ(EVENT_BURN_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim0B)
            EVT_SET_CONST(LVar2, ANIM_DryBones_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_BurnHit)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim0C)
            EVT_EXEC_WAIT(EVS_Enemy_Death)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_SPIN_SMASH_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
        EVT_CASE_EQ(EVENT_SPIN_SMASH_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_SpinSmashHit)
            EVT_EXEC_WAIT(N(EVS_Collapse))
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Collapsed, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim02)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim01)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_IF
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_DEATH)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_Hit)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Collapsed, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_WAIT(10)
                EVT_EXEC_WAIT(N(EVS_Collapse))
            EVT_END_IF
        EVT_CASE_EQ(EVENT_RECOVER_STATUS)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Collapsed, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim02)
                EVT_EXEC_WAIT(EVS_Enemy_Recover)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_SCARE_AWAY)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_DryBones_Anim04)
            EVT_SET_CONST(LVar2, ANIM_DryBones_Anim07)
            EVT_EXEC_WAIT(EVS_Enemy_ScareAway)
            EVT_RETURN
        EVT_CASE_EQ(EVENT_BEGIN_AIR_LIFT)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Collapsed, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim04)
                EVT_EXEC_WAIT(EVS_Enemy_AirLift)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim09)
                EVT_EXEC_WAIT(EVS_Enemy_AirLift)
            EVT_END_IF
        EVT_CASE_EQ(EVENT_BLOW_AWAY)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Collapsed, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
                EVT_IF_NOT_FLAG(LVar0, STATUS_FLAGS_IMMOBILIZED)
                    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
                        EVT_CALL(SetActorDispOffset, ACTOR_SELF, -1, -2, 0)
                    EVT_ELSE
                        EVT_CALL(SetActorDispOffset, ACTOR_SELF, -3, -5, 0)
                    EVT_END_IF
                EVT_END_IF
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim07)
                EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim09)
                EVT_EXEC_WAIT(EVS_Enemy_BlowAway)
            EVT_END_IF
            EVT_RETURN
        EVT_CASE_EQ(EVENT_AIR_LIFT_FAILED)
            EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Collapsed, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim02)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_ELSE
                EVT_SET_CONST(LVar0, PRT_MAIN)
                EVT_SET_CONST(LVar1, ANIM_DryBones_Anim01)
                EVT_EXEC_WAIT(EVS_Enemy_NoDamageHit)
            EVT_END_IF
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpinBone) = {
    EVT_SET(LVar0, 0)
    EVT_LABEL(0)
        EVT_CALL(SetPartRotation, ACTOR_SELF, PRT_BONE, 0, 0, LVar0)
        EVT_ADD(LVar0, 60)
        EVT_MOD(LVar0, 360)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
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
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_DryBones_Anim06)
        EVT_GOTO(100)
    EVT_END_IF
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Collapsed, LVar0)
    EVT_IF_EQ(LVar0, TRUE)
        EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_CollapseTurns, LVar0)
        EVT_SUB(LVar0, 1)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DRY_BONES_RATTLE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_DryBones_Anim09)
            EVT_WAIT(10)
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DRY_BONES_ARISE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_DryBones_Anim0A)
            EVT_WAIT(20)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Collapsed, FALSE)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CollapseTurns, 0)
            EVT_CALL(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefaultAnims)))
            EVT_CALL(SetDefenseTable, ACTOR_SELF, PRT_MAIN, EVT_PTR(N(DefenseTable)))
            EVT_CALL(SetStatusTable, ACTOR_SELF, EVT_PTR(N(StatusTable)))
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_DAMAGE_IMMUNE, FALSE)
            EVT_CALL(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -8, 30)
            EVT_CALL(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -10)
            EVT_CALL(GetEnemyMaxHP, ACTOR_SELF, LVar0)
            EVT_CALL(SetEnemyHP, ACTOR_SELF, LVar0)
        EVT_ELSE
            EVT_CALL(PlaySoundAtActor, ACTOR_SELF, SOUND_DRY_BONES_RATTLE)
            EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_DryBones_Anim09)
            EVT_WAIT(10)
            EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_CollapseTurns, LVar0)
        EVT_END_IF
        EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_DryBones_Anim05)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_DryBones_Anim06)
    EVT_THREAD
        EVT_WAIT(8)
        EVT_CALL(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_DryBones_Anim02)
    EVT_END_THREAD
    EVT_LABEL(100)
    EVT_CALL(GetStatusFlags, ACTOR_SELF, LVar0)
    EVT_IF_FLAG(LVar0, STATUS_FLAG_SHRINK)
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_BONE, EVT_FLOAT(0.4), EVT_FLOAT(0.4), EVT_FLOAT(0.4))
    EVT_ELSE
        EVT_CALL(SetPartScale, ACTOR_SELF, PRT_BONE, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_END_IF
    EVT_CALL(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_MISS)
        EVT_CASE_OR_EQ(HIT_RESULT_LUCKY)
            EVT_SET(LVarF, LVar0)
            EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_ADD(LVar1, 20)
            EVT_CALL(SetPartPos, ACTOR_SELF, PRT_BONE, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BONE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_BONE, SOUND_DRY_BONES_THROW)
            EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_BONE, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
            EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_BONE, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
            EVT_EXEC_GET_TID(N(EVS_SpinBone), LVarA)
            EVT_CALL(SetGoalToTarget, ACTOR_SELF)
            EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 100)
            EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_BONE, EVT_FLOAT(12.0))
            EVT_CALL(RunPartTo, ACTOR_SELF, PRT_BONE, LVar0, LVar1, LVar2, FALSE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BONE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_KILL_THREAD(LVarA)
            EVT_IF_EQ(LVarF, HIT_RESULT_LUCKY)
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
    EVT_CALL(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetPartPos, ACTOR_SELF, PRT_BONE, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BONE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    EVT_CALL(PlaySoundAtPart, ACTOR_SELF, PRT_BONE, SOUND_DRY_BONES_THROW)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_BONE, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_CALL(SetPartSounds, ACTOR_SELF, PRT_BONE, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    EVT_EXEC_GET_TID(N(EVS_SpinBone), LVarA)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetPartMoveSpeed, ACTOR_SELF, PRT_BONE, EVT_FLOAT(12.0))
    EVT_CALL(RunPartTo, ACTOR_SELF, PRT_BONE, LVar0, LVar1, LVar2, FALSE)
    EVT_WAIT(2)
    EVT_CALL(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 4, BS_FLAGS1_TRIGGER_EVENTS)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(GetPartOffset, ACTOR_SELF, PRT_BONE, LVar0, LVar1, LVar2)
            EVT_SUB(LVar0, 100)
            EVT_CALL(SetPartJumpGravity, ACTOR_SELF, PRT_BONE, EVT_FLOAT(0.7))
            EVT_CALL(JumpPartTo, ACTOR_SELF, PRT_BONE, LVar0, 0, LVar2, 30, TRUE)
            EVT_CALL(SetPartFlagBits, ACTOR_SELF, PRT_BONE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            EVT_KILL_THREAD(LVarA)
            EVT_CALL(YieldTurn)
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
