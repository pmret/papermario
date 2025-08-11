#include "../area.h"
#include "sprite/npc/Blooper.h"

#define NAMESPACE A(blooper)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Attack_SpinDrop);
extern EvtScript N(EVS_Attack_InkBlast);
extern EvtScript N(EVS_Death);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
};

enum N(ActorParams) {
    DMG_SPIN_DROP   = 3,
    DMG_INK_BLAST   = 3,
};

EvtScript N(EVS_FloatToPos) = {
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0C)
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    IfGt(LVarB, 20)
        Sub(LVarB, 20)
    Else
        Set(LVarB, 0)
    EndIf
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.3))
    Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(FallToGoal, ACTOR_SELF, 8)
    Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BLOOPER_MOVE)
    Set(LVar7, LVar4)
    Add(LVar7, LVar4)
    Add(LVar7, LVar0)
    MulF(LVar7, Float(0.33))
    Set(LVar8, LVar5)
    Add(LVar8, LVar5)
    Add(LVar8, LVar1)
    MulF(LVar8, Float(0.33))
    Set(LVar9, LVar6)
    Add(LVar9, LVar6)
    Add(LVar9, LVar2)
    MulF(LVar9, Float(0.33))
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetGoalPos, ACTOR_SELF, LVar7, LVar8, LVar9)
    Call(FlyToGoal, ACTOR_SELF, LVar3, -2, EASING_CUBIC_OUT)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0C)
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Sub(LVarB, 20)
    Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.3))
    Call(FallToGoal, ACTOR_SELF, 8)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BLOOPER_MOVE)
    Set(LVar7, LVar0)
    Add(LVar7, LVar0)
    Add(LVar7, LVar4)
    MulF(LVar7, Float(0.33))
    Set(LVar8, LVar1)
    Add(LVar8, LVar1)
    Add(LVar8, LVar5)
    MulF(LVar8, Float(0.33))
    Set(LVar9, LVar2)
    Add(LVar9, LVar2)
    Add(LVar9, LVar6)
    MulF(LVar9, Float(0.33))
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetGoalPos, ACTOR_SELF, LVar7, LVar8, LVar9)
    Call(FlyToGoal, ACTOR_SELF, LVar3, -2, EASING_CUBIC_OUT)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0C)
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Sub(LVarB, 20)
    Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.3))
    Call(FallToGoal, ACTOR_SELF, 8)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BLOOPER_MOVE)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_SELF, LVar3, -2, EASING_CUBIC_OUT)
    Return
    End
};

EvtScript N(EVS_FloatToHome) = {
    Call(SetGoalToHome, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar3, 12)
    ExecWait(N(EVS_FloatToPos))
    Return
    End
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Blooper_Anim00,
    STATUS_KEY_STOP,      ANIM_Blooper_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Blooper_Anim07,
    STATUS_KEY_PARALYZE,  ANIM_Blooper_Anim08,
    STATUS_KEY_PARALYZE,  ANIM_Blooper_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Blooper_Anim08,
    STATUS_KEY_SHRINK,    ANIM_Blooper_Anim00,
    STATUS_END,
};

s32 N(AscendAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Blooper_Anim0C,
    STATUS_KEY_STOP,      ANIM_Blooper_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Blooper_Anim07,
    STATUS_KEY_PARALYZE,  ANIM_Blooper_Anim08,
    STATUS_KEY_PARALYZE,  ANIM_Blooper_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Blooper_Anim08,
    STATUS_KEY_SHRINK,    ANIM_Blooper_Anim0C,
    STATUS_END,
};

s32 N(DescendAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_Blooper_Anim00,
    STATUS_KEY_STOP,      ANIM_Blooper_Anim00,
    STATUS_KEY_SLEEP,     ANIM_Blooper_Anim07,
    STATUS_KEY_PARALYZE,  ANIM_Blooper_Anim08,
    STATUS_KEY_PARALYZE,  ANIM_Blooper_Anim00,
    STATUS_KEY_DIZZY,     ANIM_Blooper_Anim08,
    STATUS_KEY_SHRINK,    ANIM_Blooper_Anim00,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              70,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              80,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           90,
    STATUS_KEY_SHRINK,             90,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 50 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_TARGET,
        .posOffset = { 0, 20, 0 },
        .targetOffset = { 0, 30 },
        .opacity = 255,
        .idleAnimations = nullptr,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -37 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_BLOOPER,
    .level = ACTOR_LEVEL_BLOOPER,
    .maxHP = 30,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 90,
    .coinReward = 0,
    .size = { 57, 61 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { 0, 22 },
    .statusTextOffset = { 15, 55 },
};

EvtScript N(EVS_Init) = {
    Call(SetActorScale, ACTOR_SELF, Float(0.75), Float(0.75), Float(1.0))
    Call(ForceHomePos, ACTOR_SELF, 90, 45, -10)
    Call(HPBarToHome, ACTOR_SELF)
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            Wait(1)
            Goto(0)
        EndIf
        Call(SetIdleGoalToHome, ACTOR_SELF)
        Call(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 0)
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        IfGe(LVar4, LVar1)
            Goto(11)
        EndIf
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(AscendAnims)))
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
        Wait(9)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0C)
        Call(SetActorIdleJumpGravity, ACTOR_SELF, Float(1.0))
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(1.0))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleFlyToGoal, ACTOR_SELF, 0, 0, EASING_SIN_OUT)
        Label(11)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            Wait(1)
            Goto(0)
        EndIf
        Call(SetIdleGoalToHome, ACTOR_SELF)
        Call(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 10)
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        IfGe(LVar4, LVar1)
            Goto(12)
        EndIf
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(AscendAnims)))
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
        Wait(9)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0C)
        Call(SetActorIdleJumpGravity, ACTOR_SELF, Float(1.0))
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(1.0))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleFlyToGoal, ACTOR_SELF, 0, 0, EASING_SIN_OUT)
        Wait(3)
        Label(12)
        Call(GetStatusFlags, ACTOR_SELF, LVarA)
        IfFlag(LVarA, STATUS_FLAG_SLEEP | STATUS_FLAG_PARALYZE | STATUS_FLAG_DIZZY | STATUS_FLAG_STONE | STATUS_FLAG_STOP)
            Wait(1)
            Goto(0)
        EndIf
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(DescendAnims)))
        Call(SetIdleGoalToHome, ACTOR_SELF)
        Call(GetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, -10)
        Call(SetActorIdleJumpGravity, ACTOR_SELF, Float(0.8))
        Call(SetActorIdleSpeed, ACTOR_SELF, Float(0.3))
        Call(SetIdleGoal, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(IdleFlyToGoal, ACTOR_SELF, 0, 1, EASING_SIN_OUT)
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(EVS_Enemy_Hit)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_BURN_HIT)
            Set(LVar0, PRT_MAIN)
            Set(LVar1, ANIM_Blooper_Anim05)
            Set(LVar2, ANIM_Blooper_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            Set(LVar0, PRT_MAIN)
            Set(LVar1, ANIM_Blooper_Anim05)
            Set(LVar2, ANIM_Blooper_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar1, ANIM_Blooper_Anim06)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(N(EVS_Death))
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim00)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_FloatToHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_END_FIRST_STRIKE)
            ExecWait(N(EVS_FloatToHome))
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim00)
            ExecWait(EVS_Enemy_Recover)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_Death) = {
    SetConst(LVar0, PRT_MAIN)
    ExecWait(EVS_Enemy_Death)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(RandInt, 100, LVar0)
        IfLt(LVar0, 50)
            ExecWait(N(EVS_Attack_SpinDrop))
        Else
            ExecWait(N(EVS_Attack_InkBlast))
        EndIf
    Else
        ExecWait(N(EVS_Attack_SpinDrop))
    EndIf
    Return
    End
};

EvtScript N(EVS_Attack_SpinDrop) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 95)
        Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(SetBattleCamDist, 400)
        Call(MoveBattleCamOver, 130)
    Else
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 72)
        Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(SetBattleCamDist, 340)
        Call(MoveBattleCamOver, 130)
    EndIf
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Set(LVar1, 100)
    Set(LVar3, 15)
    ExecWait(N(EVS_FloatToPos))
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BLOOPER_FALL)
    Call(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Thread
                Set(LVar0, 0)
                Loop(36)
                    Add(LVar0, 30)
                    Call(SetActorYaw, ACTOR_SELF, LVar0)
                    Wait(1)
                EndLoop
                Call(SetActorYaw, ACTOR_SELF, 0)
            EndThread
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0D)
            Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 16, false, true, false)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
            IfEq(LVarF, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 12, false, true, false)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, false, true, false)
            ExecWait(N(EVS_FloatToHome))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Thread
        Set(LVar0, 0)
        Loop(16)
            Add(LVar0, 30)
            Call(SetActorYaw, ACTOR_SELF, LVar0)
            Wait(1)
        EndLoop
        Call(SetActorYaw, ACTOR_SELF, 0)
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0D)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 30)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 16, false, true, false)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, DMG_SPIN_DROP, BS_FLAGS1_TRIGGER_EVENTS)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
    IfFlag(LVar0, STATUS_FLAG_STONE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim04)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
    EndIf
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Sub(LVar1, 15)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, false, true, false)
    ExecWait(N(EVS_FloatToHome))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

#include "common/StartRumbleWithParams.inc.c"
#include "common/SpitInk.inc.c"

EvtScript N(EVS_Attack_InkBlast) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 85)
    Add(LVar1, 45)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0C)
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    IfGt(LVarB, 30)
        Sub(LVarB, 30)
    Else
        Set(LVarB, 0)
    EndIf
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.3))
    Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(FallToGoal, ACTOR_SELF, 8)
    Thread
        Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
        Sub(LVar0, 30)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(SetBattleCamDist, 350)
        Call(MoveBattleCamOver, 50)
    EndThread
    Call(GetActorPos, ACTOR_SELF, LVar4, LVar5, LVar6)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BLOOPER_MOVE)
    Set(LVar7, LVar4)
    Add(LVar7, LVar0)
    MulF(LVar7, Float(0.5))
    Set(LVar8, LVar5)
    Add(LVar8, LVar1)
    MulF(LVar8, Float(0.5))
    Set(LVar9, LVar6)
    Add(LVar9, LVar2)
    MulF(LVar9, Float(0.5))
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetGoalPos, ACTOR_SELF, LVar7, LVar8, LVar9)
    Call(FlyToGoal, ACTOR_SELF, 15, -2, EASING_CUBIC_OUT)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0C)
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Sub(LVarB, 20)
    Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.3))
    Call(FallToGoal, ACTOR_SELF, 8)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BLOOPER_MOVE)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_SELF, 15, -2, EASING_CUBIC_OUT)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim03)
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Sub(LVarB, 30)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.2))
    Call(SetActorSpeed, ACTOR_SELF, Float(1.0))
    Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(FlyToGoal, ACTOR_SELF, 16, 0, EASING_LINEAR)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 10)
    Call(SetActorRotationOffset, ACTOR_SELF, 0, 40, 0)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, -40)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BLOOPER_SQUIRT)
    Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
    Add(LVar3, 1)
    Sub(LVar4, 27)
    Sub(LVar5, 3)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(SpitInk), LVar0, LVar1, LVar2, LVar3, LVar4, LVar5)
    Call(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Wait(10)
            IfEq(LVarF, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(30)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
            Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
            ExecWait(N(EVS_FloatToHome))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Wait(10)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetDamageSource, DMG_SRC_INK_BLAST)
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_NO_CONTACT, 0, 0, DMG_INK_BLAST, BS_FLAGS1_TRIGGER_EVENTS)
    Wait(30)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim00)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    ExecWait(N(EVS_FloatToHome))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};
