#include "../area.h"
#include "sprite/npc/Blooper.h"

#define NAMESPACE A(electro_blooper)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_UpdateStaticFX);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Move_ChargeUp);
extern EvtScript N(EVS_Attack_ChargedDrop);
extern EvtScript N(EVS_Attack_SpinDrop);
extern EvtScript N(EVS_Attack_InkBlast);
extern EvtScript N(EVS_Charge);
extern EvtScript N(EVS_Discharge);
extern EvtScript N(EVS_Death);

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
    PRT_TARGET      = 2,
};

enum N(ActorVars) {
    AVAR_Charged        = 0,
    AVAR_StaticEffect   = 1,
    AVAR_ShouldCharge   = 2,
};

enum N(ActorParams) {
    DMG_CHARGED_DROP    = 6,
    DMG_SPIN_DROP       = 4,
    DMG_INK_BLAST       = 4,
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
    STATUS_KEY_SLEEP,              50,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              60,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           50,
    STATUS_KEY_SHRINK,             80,
    STATUS_KEY_STOP,               80,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

s32 N(ChargedStatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              25,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              30,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,             70,
    STATUS_KEY_STOP,                0,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,          0,
    STATUS_TURN_MOD_FEAR,           0,
    STATUS_TURN_MOD_STATIC,         0,
    STATUS_TURN_MOD_PARALYZE,      -1,
    STATUS_TURN_MOD_SHRINK,        -1,
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 80 },
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
        .targetOffset = { 0, 60 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -37 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_ELECTRO_BLOOPER1,
    .level = ACTOR_LEVEL_ELECTRO_BLOOPER1,
    .maxHP = 50,
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
    .powerBounceChance = 85,
    .coinReward = 0,
    .size = { 95, 105 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { 0, 40 },
    .statusTextOffset = { 25, 85 },
};

#include "common/StartRumbleWithParams.inc.c"

API_CALLABLE(N(unused_func)) {
    Bytecode* args = script->ptrReadPos;
    Bytecode arg0 = *args++;
    f32 var0, var1;

    var1 = evt_get_float_variable(script, *args++);
    do {} while (0); //TODO required to match
    var0 = evt_get_float_variable(script, arg0);

    evt_set_float_variable(script, arg0, var1 * sin_rad(DEG_TO_RAD(var0)));

    return ApiStatus_DONE2;
}

#include "common/FadeBackgroundDarken.inc.c"
#include "common/FadeBackgroundLighten.inc.c"

API_CALLABLE(N(UpdateStaticEffect)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    f32 x = evt_get_variable(script, *args++);
    f32 y = evt_get_variable(script, *args++);
    f32 z = evt_get_variable(script, *args++);
    f32 scale = evt_get_float_variable(script, *args++);

    effect->data.snakingStatic->pos.x = x;
    effect->data.snakingStatic->pos.y = y;
    effect->data.snakingStatic->pos.z = z;
    effect->data.snakingStatic->scale = scale;
    return ApiStatus_DONE2;
}

#include "common/SpitInk.inc.c"

EvtScript N(EVS_Init) = {
    Call(ForceHomePos, ACTOR_SELF, 90, 45, -10)
    Call(HPBarToHome, ACTOR_SELF)
    Call(SetActorScale, ACTOR_SELF, Float(1.25), Float(1.25), Float(1.0))
    Call(SetActorVar, ACTOR_SELF, AVAR_Charged, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_StaticEffect, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_ShouldCharge, FALSE)
    Exec(N(EVS_UpdateStaticFX))
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Return
    End
};

EvtScript N(EVS_UpdateStaticFX) = {
    Label(0)
        Call(ActorExists, ACTOR_SELF, LVar0)
        IfEq(LVar0, 0)
            Return
        EndIf
        Call(GetActorVar, ACTOR_SELF, AVAR_Charged, LVar0)
        IfNe(LVar0, 1)
            Goto(99)
        EndIf
        Call(GetActorVar, ACTOR_SELF, AVAR_StaticEffect, LVar0)
        IfEq(LVar0, 0)
            Goto(99)
        EndIf
        Call(GetActorPos, ACTOR_SELF, LVar1, LVar2, LVar3)
        Call(GetStatusFlags, ACTOR_SELF, LVar4)
        IfNotFlag(LVar4, STATUS_FLAG_SHRINK)
            Add(LVar2, 45)
            SetF(LVar4, Float(1.6))
        Else
            Add(LVar2, 18)
            SetF(LVar4, Float(0.64))
        EndIf
        Call(N(UpdateStaticEffect), LVar0, LVar1, LVar2, LVar3, LVar4)
        Label(99)
        Wait(1)
        Goto(0)
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
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_Discharge))
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(EVS_Enemy_Hit)
            ExecWait(N(EVS_Discharge))
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_BURN_HIT)
            Set(LVar0, PRT_MAIN)
            Set(LVar1, ANIM_Blooper_Anim05)
            Set(LVar2, ANIM_Blooper_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_Discharge))
        CaseEq(EVENT_BURN_DEATH)
            Set(LVar0, PRT_MAIN)
            Set(LVar1, ANIM_Blooper_Anim05)
            Set(LVar2, ANIM_Blooper_Anim06)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(N(EVS_Discharge))
            SetConst(LVar1, ANIM_Blooper_Anim06)
            ExecWait(N(EVS_Death))
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
            ExecWait(N(EVS_Discharge))
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(EVS_Enemy_SpinSmashHit)
            ExecWait(N(EVS_Discharge))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(N(EVS_Death))
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
        CaseOrEq(EVENT_INVUNERABLE_TAUNT)
        CaseOrEq(EVENT_1E)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim00)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseOrEq(EVENT_STAR_BEAM)
        CaseOrEq(EVENT_PEACH_BEAM)
            ExecWait(N(EVS_Discharge))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_Blooper_Anim04)
            ExecWait(EVS_Enemy_Hit)
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
    Call(GetActorVar, ACTOR_SELF, AVAR_Charged, LVar0)
    IfEq(LVar0, 1)
        Call(SetActorVar, ACTOR_SELF, AVAR_ShouldCharge, FALSE)
        ExecWait(N(EVS_Attack_ChargedDrop))
        Return
    EndIf
    Call(GetActorVar, ACTOR_SELF, AVAR_ShouldCharge, LVar0)
    IfEq(LVar0, 1)
        ExecWait(N(EVS_Move_ChargeUp))
        Return
    Else
        Call(GetStatusFlags, ACTOR_SELF, LVar0)
        IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
            Call(SetActorVar, ACTOR_SELF, AVAR_ShouldCharge, TRUE)
            Call(RandInt, 100, LVar0)
            IfLt(LVar0, 50)
                ExecWait(N(EVS_Attack_SpinDrop))
            Else
                ExecWait(N(EVS_Attack_InkBlast))
            EndIf
        Else
            ExecWait(N(EVS_Attack_SpinDrop))
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_Move_ChargeUp) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 65)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamZoom, 320)
    Call(MoveBattleCamOver, 50)
    Wait(20)
    Call(N(FadeBackgroundDarken))
    Call(N(StartRumbleWithParams), 70, 80)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 40, Float(0.3))
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim09)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0A)
    Wait(10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_Blooper_Anim0B)
    Wait(10)
    ExecWait(N(EVS_Charge))
    Wait(20)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Call(N(FadeBackgroundLighten))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    Return
    End
};

EvtScript N(EVS_Attack_SpinDrop) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 112)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(SetBattleCamZoom, 500)
        Call(MoveBattleCamOver, 130)
    Else
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 82)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(SetBattleCamZoom, 385)
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
            Call(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
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
    Call(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
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
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    ExecWait(N(EVS_FloatToHome))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_ChargedDrop) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfNotFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 112)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(SetBattleCamZoom, 500)
        Call(MoveBattleCamOver, 130)
    Else
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 82)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(SetBattleCamZoom, 385)
        Call(MoveBattleCamOver, 130)
    EndIf
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Set(LVar1, 100)
    Set(LVar3, 15)
    ExecWait(N(EVS_FloatToPos))
    Call(EnemyTestTarget, ACTOR_SELF, LVarF, DAMAGE_TYPE_SHOCK, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
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
            Call(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(MoveBattleCamOver, 20)
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
    Call(JumpToGoal, ACTOR_SELF, 16, FALSE, TRUE, FALSE)
    Wait(2)
    Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_SHOCK, SUPPRESS_EVENT_SHOCK_CONTACT, 0, DMG_CHARGED_DROP, BS_FLAGS1_TRIGGER_EVENTS)
    IfNe(LVarF, HIT_RESULT_HIT_STATIC)
        ExecWait(N(EVS_Discharge))
    EndIf
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
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    ExecWait(N(EVS_FloatToHome))
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_RESTART)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Attack_InkBlast) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
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
        Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
        Sub(LVar0, 30)
        Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
        Call(SetBattleCamZoom, 350)
        Call(MoveBattleCamOver, 80)
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
    Sub(LVar4, 28)
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
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
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
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_Charge) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_Charged, LVar0)
    IfNe(LVar0, 0)
        Return
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_Charged, TRUE)
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(GetStatusFlags, ACTOR_SELF, LVar3)
    IfNotFlag(LVar3, STATUS_FLAG_SHRINK)
        Add(LVar1, 45)
        SetF(LVar3, Float(1.6))
    Else
        Add(LVar1, 18)
        SetF(LVar3, Float(0.64))
    EndIf
    PlayEffect(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, LVar3, -1, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_StaticEffect, LVarF)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_CHARGE_LIGHTNING)
    Call(SetPartEventFlags, ACTOR_SELF, PRT_TARGET, ACTOR_EVENT_FLAG_ATTACK_CHARGED | ACTOR_EVENT_FLAG_ELECTRIFIED)
    Call(EnableActorPaletteEffects, ACTOR_SELF, PRT_MAIN, TRUE)
    Call(SetActorPaletteEffect, ACTOR_SELF, PRT_MAIN, ACTOR_PAL_ADJUST_STATIC)
    Call(SetStatusTable, ACTOR_SELF, Ref(N(ChargedStatusTable)))
    Return
    End
};

EvtScript N(EVS_Discharge) = {
    Call(GetActorVar, ACTOR_SELF, AVAR_Charged, LVar0)
    IfNe(LVar0, 1)
        Return
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_ShouldCharge, FALSE)
    Call(SetActorVar, ACTOR_SELF, AVAR_Charged, FALSE)
    Call(GetActorVar, ACTOR_SELF, AVAR_StaticEffect, LVar0)
    IfNe(LVar0, 0)
        Call(RemoveEffect, LVar0)
        Call(SetActorVar, ACTOR_SELF, AVAR_StaticEffect, 0)
    EndIf
    Call(SetPartEventFlags, ACTOR_SELF, PRT_TARGET, 0)
    Call(EnableActorPaletteEffects, ACTOR_SELF, PRT_MAIN, FALSE)
    Call(SetStatusTable, ACTOR_SELF, Ref(N(StatusTable)))
    Return
    End
};
