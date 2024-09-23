#include "../area.h"
#include "sprite/npc/PetitPiranha.h"
#include "effects.h"
#include "boss_common.h"

#define NAMESPACE A(petit_piranha)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Death);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorParams) {
    DMG_IMPACT      = 6,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_PetitPiranha_Anim01,
    STATUS_KEY_STONE,     ANIM_PetitPiranha_Anim01,
    STATUS_KEY_SLEEP,     ANIM_PetitPiranha_Anim01,
    STATUS_KEY_POISON,    ANIM_PetitPiranha_Anim01,
    STATUS_KEY_STOP,      ANIM_PetitPiranha_Anim00,
    STATUS_KEY_STATIC,    ANIM_PetitPiranha_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_PetitPiranha_Anim01,
    STATUS_KEY_PARALYZE,  ANIM_PetitPiranha_Anim01,
    STATUS_KEY_DIZZY,     ANIM_PetitPiranha_Anim01,
    STATUS_KEY_DIZZY,     ANIM_PetitPiranha_Anim01,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_WATER,   -2,
    ELEMENT_ICE,     -2,
    ELEMENT_FIRE,    99,
    ELEMENT_BLAST,    0,
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
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,          0,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          1,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,       0,
    STATUS_TURN_MOD_SHRINK,         0,
    STATUS_TURN_MOD_STOP,           0,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_IGNORE_BELOW_CHECK | ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 24 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_FIREY,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -2, -22 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_PETIT_PIRANHA,
    .level = ACTOR_LEVEL_PETIT_PIRANHA,
    .maxHP = 1,
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
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 30, 30 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(SetEnemyHP, ACTOR_SELF, 1)
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Label(0)
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
        CaseEq(EVENT_BEGIN_FIRST_STRIKE)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_PetitPiranha_Anim03)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_PetitPiranha_Anim03)
            SetConst(LVar2, -1)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_PetitPiranha_Anim03)
            SetConst(LVar2, -1)
            ExecWait(EVS_Enemy_BurnHit)
            Wait(10)
            ExecWait(N(EVS_Death))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_PetitPiranha_Anim03)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_PetitPiranha_Anim03)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_PetitPiranha_Anim03)
            ExecWait(EVS_Enemy_SpinSmashHit)
            ExecWait(N(EVS_Death))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_PetitPiranha_Anim03)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_PetitPiranha_Anim03)
            ExecWait(EVS_Enemy_ShockHit)
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_PetitPiranha_Anim03)
            ExecWait(EVS_Enemy_ShockHit)
            ExecWait(N(EVS_Death))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_PetitPiranha_Anim03)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_PetitPiranha_Anim01)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseOrEq(EVENT_SPIKE_TAUNT)
        CaseOrEq(EVENT_BURN_TAUNT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_PetitPiranha_Anim03)
            Wait(60)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_PetitPiranha_Anim03)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            ExecWait(N(EVS_Death))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_PetitPiranha_Anim03)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_END_FIRST_STRIKE)
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_PetitPiranha_Anim01)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_30)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_PetitPiranha_Anim03)
            ExecWait(EVS_Enemy_Hit)
            Wait(1000)
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

// unused
EvtScript N(EVS_AbsorbDamage) = {
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_SPARKLES, 0, LVar0, LVar1, LVar2, Float(1.0), 0)
    Add(LVar0, 20)
    Call(GetLastDamage, ACTOR_SELF, LVar3)
    PlayEffect(EFFECT_RECOVER, 0, LVar0, LVar1, LVar2, LVar3, 0)
    Call(GetActorHP, ACTOR_SELF, LVar0)
    Add(LVar0, LVar3)
    Call(GetEnemyMaxHP, ACTOR_SELF, LVar1)
    IfGt(LVar0, LVar1)
        Set(LVar0, LVar1)
    EndIf
    Call(SetEnemyHP, ACTOR_SELF, LVar0)
    Return
    End
};

API_CALLABLE(N(SetFlameScaleH)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    FlameFXData* flame = effect->data.flame;

    flame->scaleH = evt_get_float_variable(script, *args++);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetFlamePosX)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    FlameFXData* flame = effect->data.flame;

    flame->pos.x = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    IfGe(LVar1, 41)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_PetitPiranha_Anim04)
        Call(UseBattleCamPreset, BTL_CAM_ACTOR)
        Call(SetBattleCamDist, 380)
        Call(SetBattleCamOffsetY, -20)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 20)
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_PetitPiranha_Anim06)
        Call(SetActorSpeed, ACTOR_SELF, Float(2.0))
        Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar0, 15)
        Add(LVar1, 15)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(FlyToGoal, ACTOR_SELF, 20, -12, EASING_LINEAR)
    Else
        Call(UseBattleCamPreset, BTL_CAM_ACTOR)
        Call(SetBattleCamDist, 380)
        Call(SetBattleCamOffsetY, 0)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(MoveBattleCamOver, 20)
        Wait(20)
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_PetitPiranha_Anim03)
        Call(SetActorSpeed, ACTOR_SELF, Float(2.0))
        Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
        Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PETIT_PIRANHA_ASCEND)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 20)
        Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(FlyToGoal, ACTOR_SELF, 20, 0, EASING_LINEAR)
        Wait(10)
    EndIf
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_PETIT_PIRANHA_DIVE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 10)
    Call(SetGoalPos, ACTOR_SELF, LVar0, 5, LVar2)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_PetitPiranha_Anim05)
    Call(SetActorSpeed, ACTOR_SELF, Float(6.0))
    Call(SetActorJumpGravity, ACTOR_SELF, Float(8.0))
    Call(FlyToGoal, ACTOR_SELF, 0, -16, EASING_QUARTIC_IN)
    Call(SetPartFlagBits, ACTOR_SELF, PRT_MAIN, ACTOR_PART_FLAG_INVISIBLE, TRUE)
    Call(SetActorFlagBits, ACTOR_SELF, ACTOR_FLAG_NO_SHADOW, TRUE)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 10)
    Set(LVar1, 0)
    Add(LVar2, 2)
    PlayEffect(EFFECT_FLAME, FX_FLAME_RED, LVar0, LVar1, LVar2, Float(0.3), LVarA, 0)
    Thread
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(GetGoalPos, ACTOR_SELF, LVar3, LVar4, LVar5)
        Call(MakeLerp, 0, 30, 21, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Set(LVar4, LVar3)
            Sub(LVar4, LVar0)
            Call(N(SetFlamePosX), LVarA, LVar4)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(MakeLerp, 140, 160, 2, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        MulF(LVar0, Float(0.01))
        Call(N(SetFlameScaleH), LVarA, LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(EnemyTestTarget, ACTOR_SELF, LVar9, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar9)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Call(MakeLerp, 160, 10, 20, EASING_QUADRATIC_IN)
            Loop(0)
                Call(UpdateLerp)
                MulF(LVar0, Float(0.01))
                Call(N(SetFlameScaleH), LVarA, LVar0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Wait(1)
            Call(RemoveEffect, LVarA)
            IfEq(LVar9, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            ExecWait(N(EVS_Death))
            Call(RemoveActor, ACTOR_SELF)
            Return
        EndCaseGroup
    EndSwitch
    Wait(2)
    Set(LVar8, DMG_IMPACT)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar9, DAMAGE_TYPE_FIRE, SUPPRESS_EVENT_ALL, 0, LVar8, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVar9)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
        CaseOrEq(HIT_RESULT_10)
            Call(MakeLerp, 160, 10, 20, EASING_QUADRATIC_IN)
            Loop(0)
                Call(UpdateLerp)
                MulF(LVar0, Float(0.01))
                Call(N(SetFlameScaleH), LVarA, LVar0)
                Wait(1)
                IfEq(LVar1, 0)
                    BreakLoop
                EndIf
            EndLoop
            Wait(1)
            Call(RemoveEffect, LVarA)
            Wait(15)
            IfEq(LVar9, 10)
                Return
            EndIf
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EndCaseGroup
    EndSwitch
    ExecWait(N(EVS_Death))
    Call(RemoveActor, ACTOR_SELF)
    Return
    End
};

EvtScript N(EVS_Death) = {
    Call(ActorExists, ACTOR_BOSS, LVar0)
    IfFalse(LVar0)
        Return
    EndIf
    Call(GetActorHP, ACTOR_BOSS, LVar0)
    IfEq(LVar0, 0)
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_Petit_Parent, LVar0)
    Call(GetActorVar, LVar0, AVAR_Bud_PetitCount, LVar1)
    Sub(LVar1, 1)
    Call(SetActorVar, LVar0, AVAR_Bud_PetitCount, LVar1)
    Return
    End
};
