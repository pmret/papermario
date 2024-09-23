#include "../area.h"
#include "sprite/npc/BabyBlooper.h"
#include "battle/action_cmd/stop_leech.h"
#include "sprite/player.h"

#define NAMESPACE A(blooper_baby)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Death);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
};

enum N(ActorVars) {
    AVAR_HomePosX   = 0,
    AVAR_HomePosY   = 1,
    AVAR_HomePosZ   = 2,
};

enum N(ActorParams) {
    DMG_LEECH       = 2,
};

EvtScript N(EVS_FloatToPos) = {
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim00)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim01)
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
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BABY_BLOOPER_MOVE)
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
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim00)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim01)
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Sub(LVarB, 20)
    Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.3))
    Call(FallToGoal, ACTOR_SELF, 8)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BABY_BLOOPER_MOVE)
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
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim00)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim01)
    Call(GetActorPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Sub(LVarB, 20)
    Call(SetGoalPos, ACTOR_SELF, LVarA, LVarB, LVarC)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.3))
    Call(FallToGoal, ACTOR_SELF, 8)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BABY_BLOOPER_MOVE)
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
    STATUS_KEY_NORMAL,    ANIM_BabyBlooper_Anim00,
    STATUS_KEY_STOP,      ANIM_BabyBlooper_Anim00,
    STATUS_KEY_SLEEP,     ANIM_BabyBlooper_Anim06,
    STATUS_KEY_PARALYZE,  ANIM_BabyBlooper_Anim07,
    STATUS_KEY_PARALYZE,  ANIM_BabyBlooper_Anim00,
    STATUS_KEY_DIZZY,     ANIM_BabyBlooper_Anim07,
    STATUS_KEY_SHRINK,    ANIM_BabyBlooper_Anim00,
    STATUS_END,
};

s32 N(AscendAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BabyBlooper_Anim01,
    STATUS_KEY_STOP,      ANIM_BabyBlooper_Anim00,
    STATUS_KEY_SLEEP,     ANIM_BabyBlooper_Anim06,
    STATUS_KEY_PARALYZE,  ANIM_BabyBlooper_Anim07,
    STATUS_KEY_PARALYZE,  ANIM_BabyBlooper_Anim00,
    STATUS_KEY_DIZZY,     ANIM_BabyBlooper_Anim07,
    STATUS_KEY_SHRINK,    ANIM_BabyBlooper_Anim01,
    STATUS_END,
};

s32 N(DescendAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BabyBlooper_Anim00,
    STATUS_KEY_STOP,      ANIM_BabyBlooper_Anim00,
    STATUS_KEY_SLEEP,     ANIM_BabyBlooper_Anim06,
    STATUS_KEY_PARALYZE,  ANIM_BabyBlooper_Anim07,
    STATUS_KEY_PARALYZE,  ANIM_BabyBlooper_Anim00,
    STATUS_KEY_DIZZY,     ANIM_BabyBlooper_Anim07,
    STATUS_KEY_SHRINK,    ANIM_BabyBlooper_Anim00,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,              0,
    STATUS_KEY_STOP,              100,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -2,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 85 },
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
        .posOffset = { 0, 27, 0 },
        .targetOffset = { 0, 0 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 1, -13 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_BLOOPER_BABY,
    .level = ACTOR_LEVEL_BLOOPER_BABY,
    .maxHP = 6,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 0,
    .powerBounceChance = 95,
    .coinReward = 0,
    .size = { 28, 25 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -12, 20 },
    .statusTextOffset = { 10, 25 },
};

#include "common/StartRumbleWithParams.inc.c"
#include "common/SpawnEnemyDrainFX.inc.c"

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BABY_BLOOPER_MOVE)
    Call(N(StartRumbleWithParams), 80, 20)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim00)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim01)
    Call(GetActorPos, ACTOR_ENEMY0, LVar0, LVar1, LVar2)
    Add(LVar1, 10)
    Sub(LVar2, 10)
    Call(SetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 20)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.3))
    Call(SetActorSpeed, ACTOR_SELF, Float(0.3))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_SELF, 8, 0, EASING_LINEAR)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_BABY_BLOOPER_MOVE)
    Call(N(StartRumbleWithParams), 80, 20)
    Call(GetActorVar, ACTOR_SELF, AVAR_HomePosX, LVar0)
    Call(GetActorVar, ACTOR_SELF, AVAR_HomePosY, LVar1)
    Call(GetActorVar, ACTOR_SELF, AVAR_HomePosZ, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetActorSpeed, ACTOR_SELF, Float(3.0))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_SELF, 12, -2, EASING_CUBIC_OUT)
    Call(ForceHomePos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(HPBarToHome, ACTOR_SELF)
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
        Call(SetGoalToHome, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 0)
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        IfGe(LVar4, LVar1)
            Goto(11)
        EndIf
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(AscendAnims)))
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim00)
        Wait(9)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim01)
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
        Call(SetGoalToHome, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 5)
        Call(GetActorPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        IfGe(LVar4, LVar1)
            Goto(12)
        EndIf
        Call(SetIdleAnimations, ACTOR_SELF, PRT_MAIN, Ref(N(AscendAnims)))
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim00)
        Wait(9)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim01)
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
        Call(SetGoalToHome, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, -5)
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
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BabyBlooper_Anim02)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BabyBlooper_Anim02)
            ExecWait(EVS_Enemy_Hit)
            SetConst(LVar1, ANIM_BabyBlooper_Anim03)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_BURN_HIT)
            Set(LVar0, 1)
            Set(LVar1, ANIM_BabyBlooper_Anim04)
            Set(LVar2, ANIM_BabyBlooper_Anim05)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            Set(LVar0, 1)
            Set(LVar1, ANIM_BabyBlooper_Anim04)
            Set(LVar2, ANIM_BabyBlooper_Anim05)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar1, ANIM_BabyBlooper_Anim05)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BabyBlooper_Anim02)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BabyBlooper_Anim02)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BabyBlooper_Anim03)
            ExecWait(N(EVS_Death))
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BabyBlooper_Anim00)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SHOCK_HIT)
            Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BabyBlooper_Anim02)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BabyBlooper_Anim02)
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_FloatToHome))
        CaseOrEq(EVENT_SHOCK_DEATH)
            Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BabyBlooper_Anim02)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BabyBlooper_Anim02)
            ExecWait(EVS_Enemy_Knockback)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BabyBlooper_Anim03)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_END_FIRST_STRIKE)
            ExecWait(N(EVS_FloatToHome))
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BabyBlooper_Anim00)
            ExecWait(EVS_Enemy_Recover)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
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
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 100)
    Set(LVar3, 12)
    ExecWait(N(EVS_FloatToPos))
    Thread
        Wait(2)
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_FALL_QUICK)
    EndThread
    Call(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim02)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Set(LVar1, 0)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            IfEq(LVarF, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 12, FALSE, TRUE, FALSE)
            Add(LVar0, 20)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 8, FALSE, TRUE, FALSE)
            ExecWait(N(EVS_FloatToHome))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
        CaseOrEq(HIT_RESULT_HIT_STATIC)
        CaseOrEq(HIT_RESULT_IMMUNE)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim02)
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.5))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            IfEq(LVarF, 7)
                Call(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 0, 0, BS_FLAGS1_NICE_HIT)
            EndIf
            Add(LVar0, 30)
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
            ExecWait(N(EVS_FloatToHome))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 50)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamDist, 325)
    Call(MoveBattleCamOver, 30)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim02)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(0.8))
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar1, 10)
    Sub(LVar2, 5)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim08)
    Call(ShowMessageBox, BTL_MSG_ACTION_TIP_MASH_BUTTON, 32767)
    Call(ShowActionHud, TRUE)
    Call(LoadActionCommand, ACTION_COMMAND_STOP_LEECH)
    Call(action_command_stop_leech_init)
    Call(SetupMashMeter, 1, 15, 0, 0, 0, 0)
    Wait(10)
    Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    Call(action_command_stop_leech_start, 0, 32767, 3)
    Loop(5)
        Call(UseIdleAnimation, ACTOR_PLAYER, FALSE)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioB1_Leeching)
        Set(LFlag0, FALSE)
        Loop(10)
            Call(GetActionSuccessCopy, LVar1)
            IfEq(LVar1, 1)
                Set(LFlag0, TRUE)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        IfEq(LFlag0, TRUE)
            Call(DispatchEventPlayer, EVENT_66)
            Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            BreakLoop
        EndIf
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_LEECH)
        Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
        Set(LFlag0, FALSE)
        Loop(2)
            Call(GetActionSuccessCopy, LVar1)
            IfEq(LVar1, 1)
                Set(LFlag0, TRUE)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        IfEq(LFlag0, TRUE)
            Call(DispatchEventPlayer, EVENT_66)
            Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            BreakLoop
        EndIf
        Call(SetActorScale, ACTOR_SELF, Float(0.9), Float(1.1), Float(1.0))
        Set(LFlag0, FALSE)
        Loop(2)
            Call(GetActionSuccessCopy, LVar1)
            IfEq(LVar1, 1)
                Set(LFlag0, TRUE)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        IfEq(LFlag0, TRUE)
            Call(DispatchEventPlayer, EVENT_66)
            Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            BreakLoop
        EndIf
        Call(SetActorScale, ACTOR_SELF, Float(0.8), Float(1.2), Float(1.0))
        Set(LFlag0, FALSE)
        Loop(3)
            Call(GetActionSuccessCopy, LVar1)
            IfEq(LVar1, 1)
                Set(LFlag0, TRUE)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        IfEq(LFlag0, TRUE)
            Call(DispatchEventPlayer, EVENT_66)
            Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            BreakLoop
        EndIf
        Call(SetActorScale, ACTOR_SELF, Float(0.7), Float(1.4), Float(1.0))
        Set(LFlag0, FALSE)
        Loop(2)
            Call(GetActionSuccessCopy, LVar1)
            IfEq(LVar1, 1)
                Set(LFlag0, TRUE)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        IfEq(LFlag0, TRUE)
            Call(DispatchEventPlayer, EVENT_66)
            Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            BreakLoop
        EndIf
        Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
        Call(SetDamageSource, DMG_SRC_LEECH)
        Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_IGNORE_DEFENSE, 0, 0, DMG_LEECH, BS_FLAGS1_NICE_HIT)
        Call(StartRumble, BTL_RUMBLE_HIT_MIN)
        Call(GetLastDamage, ACTOR_PLAYER, LVar3)
        IfNe(LVar3, 0)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_RECOVER_HEART)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_HEART_BOUNCE)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar1, 10)
            Call(N(SpawnDrainHealthStartFX), LVar0, LVar1, LVar2, LVar3)
            Thread
                Wait(15)
                Call(PlaySoundAtActor, ACTOR_SELF, SOUND_STAR_BOUNCE_A)
                Call(N(SpawnDrainHealthContinueFX), LVar0, LVar1, LVar2, LVar3)
            EndThread
            Add(LVar0, 20)
            Add(LVar1, 20)
            PlayEffect(EFFECT_RECOVER, 0, LVar0, LVar1, LVar2, LVar3, 0)
            Call(GetEnemyMaxHP, ACTOR_SELF, LVar1)
            Call(GetActorHP, ACTOR_SELF, LVar0)
            Add(LVar0, LVar3)
            IfGt(LVar0, LVar1)
                Set(LVar0, LVar1)
            EndIf
            Call(SetEnemyHP, ACTOR_SELF, LVar0)
        Else
            Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
            Call(DispatchEventPlayer, EVENT_66)
            Call(func_80269470)
            BreakLoop
        EndIf
        Call(SetActorScale, ACTOR_SELF, Float(0.7), Float(1.4), Float(1.0))
        Set(LFlag0, FALSE)
        Loop(3)
            Call(GetActionSuccessCopy, LVar1)
            IfEq(LVar1, 1)
                Set(LFlag0, TRUE)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        IfEq(LFlag0, TRUE)
            Call(DispatchEventPlayer, EVENT_66)
            Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            BreakLoop
        EndIf
        Call(SetActorScale, ACTOR_SELF, Float(0.8), Float(1.2), Float(1.0))
        Set(LFlag0, FALSE)
        Loop(2)
            Call(GetActionSuccessCopy, LVar1)
            IfEq(LVar1, 1)
                Set(LFlag0, TRUE)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        IfEq(LFlag0, TRUE)
            Call(DispatchEventPlayer, EVENT_66)
            Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            BreakLoop
        EndIf
        Call(SetActorScale, ACTOR_SELF, Float(0.9), Float(1.1), Float(1.0))
        Set(LFlag0, FALSE)
        Loop(2)
            Call(GetActionSuccessCopy, LVar1)
            IfEq(LVar1, 1)
                Set(LFlag0, TRUE)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        IfEq(LFlag0, TRUE)
            Call(DispatchEventPlayer, EVENT_66)
            Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
            BreakLoop
        EndIf
        Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
        Call(GetPlayerHP, LVar1)
        IfEq(LVar1, 0)
            Call(DispatchEventPlayer, EVENT_66)
            Call(func_80269470)
            BreakLoop
        EndIf
        Set(LFlag0, FALSE)
        Loop(12)
            Call(GetActionSuccessCopy, LVar1)
            IfEq(LVar1, 1)
                Set(LFlag0, TRUE)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        IfEq(LFlag0, TRUE)
            Call(DispatchEventPlayer, EVENT_66)
            BreakLoop
        EndIf
    EndLoop
    Call(DispatchEventPlayer, EVENT_66)
    Call(func_80269470)
    Call(UseIdleAnimation, ACTOR_PLAYER, TRUE)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 20)
    Call(GetStatusFlags, ACTOR_PLAYER, LVar0)
    IfFlag(LVar0, STATUS_FLAG_STONE)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim02)
    Else
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BabyBlooper_Anim00)
    EndIf
    Call(SetActorScale, ACTOR_SELF, Float(1.0), Float(1.0), Float(1.0))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Sub(LVar1, 15)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.2))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    ExecWait(N(EVS_FloatToHome))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
