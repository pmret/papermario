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
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Call(SetActorVar, ACTOR_SELF, AVAR_Collapsed, FALSE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(GetOriginalActorType, ACTOR_SELF, LVarA)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOriginalActorType, LVar0, LVar2)
        IfNe(LVar2, LVarA)
            Call(GetActorHP, LVar0, LVar3)
            IfNe(LVar3, 0)
                Return
            EndIf
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(1)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetActorVar, LVar0, AVAR_Collapsed, LVar3)
        IfNe(LVar3, TRUE)
            Return
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(1)
        EndIf
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(2)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(2)
        EndIf
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Call(GetActorVar, ACTOR_SELF, AVAR_Collapsed, LVar0)
        Call(GetStatusFlags, ACTOR_SELF, LVar1)
        Switch(LVar0)
            CaseEq(0)
                Switch(LVar1)
                    CaseFlag(STATUS_FLAG_SLEEP)
                        Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -6, 24)
                        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 1, -5)
                    CaseDefault
                        Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -8, 30)
                        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -10)
                EndSwitch
            CaseEq(1)
                Switch(LVar1)
                    CaseFlag(STATUS_FLAG_SLEEP)
                        Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -1, 10)
                        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
                    CaseDefault
                        Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -1, 10)
                        Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
                EndSwitch
        EndSwitch
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Collapse) = {
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_DRY_BONES_COLLAPSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_DryBones_Anim08)
    Wait(20)
    Call(SetActorVar, ACTOR_SELF, AVAR_Collapsed, TRUE)
    Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(CollapsedAnims)))
    Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(CollapsedDefense)))
    Call(SetStatusTable, ACTOR_SELF, Ref(N(CollapsedStatusTable)))
    Call(ClearStatusEffects, ACTOR_SELF)
    Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -1, 10)
    Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, 0, 0)
    Call(RandInt, 0, LVar0)
    Add(LVar0, BASE_COLLAPSE_DURATION)
    Call(SetActorVar, ACTOR_SELF, AVAR_CollapseTurns, LVar0)
    Call(GetOriginalActorType, ACTOR_SELF, LVarA)
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(0)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetOriginalActorType, LVar0, LVar2)
        IfNe(LVar2, LVarA)
            Return
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(1)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(GetActorVar, LVar0, AVAR_Collapsed, LVar3)
        IfNe(LVar3, TRUE)
            Return
        EndIf
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(1)
        EndIf
    Call(CreateHomeTargetList, TARGET_FLAG_2 | TARGET_FLAG_PRIMARY_ONLY)
    Call(InitTargetIterator)
    Label(2)
        Call(GetOwnerTarget, LVar0, LVar1)
        Call(SetActorFlagBits, LVar0, ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_NO_DMG_APPLY, TRUE)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(2)
        EndIf
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseEq(EVENT_HIT_COMBO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_DryBones_Anim07)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_DryBones_Anim07)
            ExecWait(EVS_Enemy_Hit)
        CaseEq(EVENT_BURN_HIT)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION, TRUE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_DryBones_Anim0B)
            SetConst(LVar2, ANIM_DryBones_Anim0C)
            ExecWait(EVS_Enemy_BurnHit)
            Call(SetPartEventBits, ACTOR_SELF, PRT_MAIN, ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION, FALSE)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_DryBones_Anim0B)
            SetConst(LVar2, ANIM_DryBones_Anim0C)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_DryBones_Anim0C)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_DryBones_Anim07)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_DryBones_Anim07)
            ExecWait(EVS_Enemy_SpinSmashHit)
            ExecWait(N(EVS_Collapse))
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(GetActorVar, ACTOR_SELF, AVAR_Collapsed, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_DryBones_Anim02)
                ExecWait(EVS_Enemy_NoDamageHit)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_DryBones_Anim01)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_DryBones_Anim07)
            ExecWait(EVS_Enemy_Hit)
            Call(GetActorVar, ACTOR_SELF, AVAR_Collapsed, LVar0)
            IfEq(LVar0, 0)
                Wait(10)
                ExecWait(N(EVS_Collapse))
            EndIf
        CaseEq(EVENT_RECOVER_STATUS)
            Call(GetActorVar, ACTOR_SELF, AVAR_Collapsed, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_DryBones_Anim02)
                ExecWait(EVS_Enemy_Recover)
            EndIf
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_DryBones_Anim04)
            SetConst(LVar2, ANIM_DryBones_Anim07)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            Call(GetActorVar, ACTOR_SELF, AVAR_Collapsed, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_DryBones_Anim04)
                ExecWait(EVS_Enemy_AirLift)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_DryBones_Anim09)
                ExecWait(EVS_Enemy_AirLift)
            EndIf
        CaseEq(EVENT_BLOW_AWAY)
            Call(GetActorVar, ACTOR_SELF, AVAR_Collapsed, LVar0)
            IfEq(LVar0, 0)
                Call(GetStatusFlags, ACTOR_SELF, LVar0)
                IfNotFlag(LVar0, STATUS_FLAGS_IMMOBILIZED)
                    IfFlag(LVar0, STATUS_FLAG_SHRINK)
                        Call(SetActorDispOffset, ACTOR_SELF, -1, -2, 0)
                    Else
                        Call(SetActorDispOffset, ACTOR_SELF, -3, -5, 0)
                    EndIf
                EndIf
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_DryBones_Anim07)
                ExecWait(EVS_Enemy_BlowAway)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_DryBones_Anim09)
                ExecWait(EVS_Enemy_BlowAway)
            EndIf
            Return
        CaseEq(EVENT_AIR_LIFT_FAILED)
            Call(GetActorVar, ACTOR_SELF, AVAR_Collapsed, LVar0)
            IfEq(LVar0, 0)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_DryBones_Anim02)
                ExecWait(EVS_Enemy_NoDamageHit)
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_DryBones_Anim01)
                ExecWait(EVS_Enemy_NoDamageHit)
            EndIf
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_SpinBone) = {
    Set(LVar0, 0)
    Label(0)
        Call(SetPartRotation, ACTOR_SELF, PRT_BONE, 0, 0, LVar0)
        Add(LVar0, 60)
        Mod(LVar0, 360)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 1)
    EndIf
    Call(GetBattlePhase, LVar0)
    IfEq(LVar0, PHASE_FIRST_STRIKE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_DryBones_Anim06)
        Goto(100)
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_Collapsed, LVar0)
    IfEq(LVar0, TRUE)
        Call(GetActorVar, ACTOR_SELF, AVAR_CollapseTurns, LVar0)
        Sub(LVar0, 1)
        IfEq(LVar0, 0)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_DRY_BONES_RATTLE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_DryBones_Anim09)
            Wait(10)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_DRY_BONES_ARISE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_DryBones_Anim0A)
            Wait(20)
            Call(SetActorVar, ACTOR_SELF, AVAR_Collapsed, FALSE)
            Call(SetActorVar, ACTOR_SELF, AVAR_CollapseTurns, 0)
            Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DefaultAnims)))
            Call(SetDefenseTable, ACTOR_SELF, PRT_MAIN, Ref(N(DefenseTable)))
            Call(SetStatusTable, ACTOR_SELF, Ref(N(StatusTable)))
            Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_DAMAGE_IMMUNE, FALSE)
            Call(SetTargetOffset, ACTOR_SELF, PRT_MAIN, -8, 30)
            Call(SetProjectileTargetOffset, ACTOR_SELF, PRT_MAIN, -1, -10)
            Call(GetEnemyMaxHP, ACTOR_SELF, LVar0)
            Call(SetEnemyHP, ACTOR_SELF, LVar0)
        Else
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_DRY_BONES_RATTLE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_DryBones_Anim09)
            Wait(10)
            Call(SetActorVar, ACTOR_SELF, AVAR_CollapseTurns, LVar0)
        EndIf
        Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
        Call(UseIdleAnimation, ACTOR_SELF, TRUE)
        Return
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_DryBones_Anim05)
    Wait(15)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_DryBones_Anim06)
    Thread
        Wait(8)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_DryBones_Anim02)
    EndThread
    Label(100)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(SetPartScale, ACTOR_SELF, PRT_BONE, Float(0.4), Float(0.4), Float(0.4))
    Else
        Call(SetPartScale, ACTOR_SELF, PRT_BONE, Float(1.0), Float(1.0), Float(1.0))
    EndIf
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarF, LVar0)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 20)
            Call(SetPartPos, ACTOR_SELF, PRT_BONE, LVar0, LVar1, LVar2)
            Wait(1)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BONE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
            Call(PlaySoundAtPart, ACTOR_SELF, PRT_BONE, SOUND_DRY_BONES_THROW)
            Call(SetPartSounds, ACTOR_SELF, PRT_BONE, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
            Call(SetPartSounds, ACTOR_SELF, PRT_BONE, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
            ExecGetTID(N(EVS_SpinBone), LVarA)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Sub(LVar0, 100)
            Call(SetPartMoveSpeed, ACTOR_SELF, PRT_BONE, Float(12.0))
            Call(RunPartTo, ACTOR_SELF, PRT_BONE, LVar0, LVar1, LVar2, FALSE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BONE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            KillThread(LVarA)
            IfEq(LVarF, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(15)
            Call(YieldTurn)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Wait(20)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 20)
    Call(SetPartPos, ACTOR_SELF, PRT_BONE, LVar0, LVar1, LVar2)
    Wait(1)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_BONE, ACTOR_PART_FLAG_INVISIBLE, FALSE)
    Call(PlaySoundAtPart, ACTOR_SELF, PRT_BONE, SOUND_DRY_BONES_THROW)
    Call(SetPartSounds, ACTOR_SELF, PRT_BONE, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(SetPartSounds, ACTOR_SELF, PRT_BONE, ACTOR_SOUND_JUMP, SOUND_NONE, SOUND_NONE)
    ExecGetTID(N(EVS_SpinBone), LVarA)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetPartMoveSpeed, ACTOR_SELF, PRT_BONE, Float(12.0))
    Call(RunPartTo, ACTOR_SELF, PRT_BONE, LVar0, LVar1, LVar2, FALSE)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, 0, 4, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(GetPartOffset, ACTOR_SELF, PRT_BONE, LVar0, LVar1, LVar2)
            Sub(LVar0, 100)
            Call(SetPartJumpGravity, ACTOR_SELF, PRT_BONE, Float(0.7))
            Call(JumpPartTo, ACTOR_SELF, PRT_BONE, LVar0, 0, LVar2, 30, TRUE)
            Call(SetPartFlagBits, ACTOR_SELF, PRT_BONE, ACTOR_PART_FLAG_INVISIBLE, TRUE)
            KillThread(LVarA)
            Call(YieldTurn)
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
