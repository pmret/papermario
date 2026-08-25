#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/AlbinoDino.h"

#define NAMESPACE A(albino_dino)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

API_CALLABLE(N(func_80218240_649050)) { // unused
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *args++);
    f32 var1 = evt_get_variable(script, *args++);
    f32 var2 = evt_get_variable(script, *args++);
    f32 var3 = evt_get_variable(script, *args++);

    // function is never called, so the effect type can't be inferred
    ((f32*)effect->data.any)[14] = var1;
    ((f32*)effect->data.any)[15] = var2;
    ((f32*)effect->data.any)[16] = var3;

    return ApiStatus_DONE2;
}

enum N(ActorPartIDs) {
    PRT_MAIN        = 1,
};

enum N(ActorParams) {
    DMG_TACKLE      = 4,
};

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_AlbinoDino_Idle,
    STATUS_KEY_STONE,     ANIM_AlbinoDino_Still,
    STATUS_KEY_SLEEP,     ANIM_AlbinoDino_Idle,
    STATUS_KEY_POISON,    ANIM_AlbinoDino_Idle,
    STATUS_KEY_STOP,      ANIM_AlbinoDino_Still,
    STATUS_KEY_STATIC,    ANIM_AlbinoDino_Idle,
    STATUS_KEY_PARALYZE,  ANIM_AlbinoDino_Still,
    STATUS_KEY_DIZZY,     ANIM_AlbinoDino_Still,
    STATUS_KEY_UNUSED,    ANIM_AlbinoDino_Still,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   4,
    ELEMENT_FIRE,    99,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,               0,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,               0,
    STATUS_KEY_UNUSED,              0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,            0,
    STATUS_KEY_SHRINK,             75,
    STATUS_KEY_STOP,                0,
    STATUS_TURN_MOD_DEFAULT,        0,
    STATUS_TURN_MOD_SLEEP,         -1,
    STATUS_TURN_MOD_POISON,         0,
    STATUS_TURN_MOD_FROZEN,         0,
    STATUS_TURN_MOD_DIZZY,         -1,
    STATUS_TURN_MOD_UNUSED,         0,
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
        .targetOffset = { -9, 46 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -6, -17 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_ALBINO_DINO,
    .level = ACTOR_LEVEL_ALBINO_DINO,
    .maxHP = 8,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 40,
    .airLiftChance = 15,
    .hurricaneChance = 10,
    .spookChance = 25,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 100,
    .coinReward = 1,
    .size = { 64, 56 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -22, 24 },
    .statusTextOffset = { 11, 40 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_AlbinoDino_Run)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_AlbinoDino_Idle)
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
            SetConst(LVar1, ANIM_AlbinoDino_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_BurntHurt)
            SetConst(LVar2, ANIM_AlbinoDino_BurntStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_BurntHurt)
            SetConst(LVar2, ANIM_AlbinoDino_BurntStill)
            ExecWait(EVS_Enemy_BurnHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_BurntStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_HurtStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_Hurt)
            ExecWait(EVS_Enemy_Knockback)
            ExecWait(N(EVS_ReturnHome))
        CaseEq(EVENT_SHOCK_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_Hurt)
            ExecWait(EVS_Enemy_ShockHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_HurtStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_Hurt)
            ExecWait(EVS_Enemy_Hit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_HurtStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_Run)
            SetConst(LVar2, ANIM_AlbinoDino_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_Run)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_AlbinoDino_Hurt)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};

EvtScript N(EVS_AddWalkQuakeFX) = {
    Set(LVarA, 0)
    Label(0)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Call(GetActorYaw, ACTOR_SELF, LVar3)
        IfEq(LVar3, 0)
            Add(LVar0, 20)
        Else
            Add(LVar0, -20)
        EndIf
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar0, LVar1, LVar2, 25, 8, 45, 20, 0)
        IfGt(LVarA, 3)
            Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.2))
            Set(LVarA, 0)
        EndIf
        Add(LVarA, 1)
        Wait(2)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, false)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, false)
    ExecGetTID(N(EVS_AddWalkQuakeFX), LVar9)
    Thread
        Loop(3)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ALBINO_DINO_STEP_A)
            Wait(4)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ALBINO_DINO_STEP_B)
            Wait(4)
        EndLoop
    EndThread
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_AlbinoDino_Run)
    Wait(20)
    Call(EnemyTestTarget, ACTOR_SELF, LVarF, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Thread
                Call(SetGoalToTarget, ACTOR_SELF)
                Call(AddGoalPos, ACTOR_SELF, -100, 0, 0)
                Call(SetActorSpeed, ACTOR_SELF, Float(12.0))
                Call(RunToGoal, ACTOR_SELF, 0, false)
                KillThread(LVar9)
            EndThread
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Wait(30)
            IfEq(LVarF, HIT_RESULT_LUCKY)
                Call(SetGoalToTarget, ACTOR_SELF)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(40)
            Call(YieldTurn)
            Call(AddActorDecoration, ACTOR_SELF, PRT_MAIN, 0, ACTOR_DECORATION_SWEAT)
            Call(SetActorYaw, ACTOR_SELF, 180)
            ExecWait(N(EVS_ReturnHome))
            Call(SetActorYaw, ACTOR_SELF, 0)
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_MAIN, 0)
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, true)
            Return
        EndCaseGroup
    EndSwitch
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        Call(AddGoalPos, ACTOR_SELF, 12, 0, 0)
    Else
        Call(AddGoalPos, ACTOR_SELF, 30, 0, 0)
    EndIf
    Call(SetActorSpeed, ACTOR_SELF, Float(12.0))
    Call(RunToGoal, ACTOR_SELF, 0, false)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 4, Float(1.5))
    EndThread
    KillThread(LVar9)
    Wait(2)
    Call(SetGoalToTarget, ACTOR_SELF)
    // invalid status field has 24% chance, but no status and doesn't have STATUS_FLAG_USE_DURATION set
    Call(EnemyDamageTarget, ACTOR_SELF, LVarF, 0, 0, 24, DMG_TACKLE, BS_FLAGS1_TRIGGER_EVENTS)
    Switch(LVarF)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Add(LVar0, 40)
            Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
            Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
            Call(JumpToGoal, ACTOR_SELF, 15, false, true, false)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_ALBINO_DINO_STEP_B)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_AlbinoDino_Idle)
            Call(ShakeCam, CAM_BATTLE, 0, 3, Float(1.0))
            Wait(10)
            Call(YieldTurn)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, true)
    Return
    End
};
