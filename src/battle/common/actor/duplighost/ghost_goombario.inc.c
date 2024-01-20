#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleGoombario.h"

#define NAMESPACE A(goombario_clone)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleGoombario_Idle,
    STATUS_KEY_STONE,     ANIM_BattleGoombario_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleGoombario_Still,
    STATUS_KEY_POISON,    ANIM_BattleGoombario_Idle,
    STATUS_KEY_STOP,      ANIM_BattleGoombario_Still,
    STATUS_KEY_STATIC,    ANIM_BattleGoombario_Idle,
    STATUS_KEY_PARALYZE,  ANIM_BattleGoombario_Still,
    STATUS_KEY_DIZZY,     ANIM_BattleGoombario_Injured,
    STATUS_KEY_FEAR,      ANIM_BattleGoombario_Injured,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,              0,
    STATUS_KEY_DEFAULT,             0,
    STATUS_KEY_SLEEP,              60,
    STATUS_KEY_POISON,              0,
    STATUS_KEY_FROZEN,              0,
    STATUS_KEY_DIZZY,              75,
    STATUS_KEY_FEAR,                0,
    STATUS_KEY_STATIC,              0,
    STATUS_KEY_PARALYZE,           75,
    STATUS_KEY_SHRINK,             75,
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
    STATUS_TURN_MOD_STOP,          -1,
    STATUS_END,
};

ActorPartBlueprint N(ActorParts)[] = {
    {
        .flags = ACTOR_PART_FLAG_PRIMARY_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 0, 20 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { -1, -9 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_GHOST_GOOMBARIO,
    .level = ACTOR_LEVEL_GHOST_GOOMBARIO,
    .maxHP = 15,
    .partCount = ARRAY_COUNT(N(ActorParts)),
    .partsData = N(ActorParts),
    .initScript = &N(EVS_Init),
    .statusTable = N(StatusTable),
    .escapeChance = 50,
    .airLiftChance = 80,
    .hurricaneChance = 70,
    .spookChance = 50,
    .upAndAwayChance = 95,
    .spinSmashReq = 0,
    .powerBounceChance = 90,
    .coinReward = 2,
    .size = { 29, 26 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 20 },
    .statusTextOffset = { 10, 20 },
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

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            Call(GetLastElement, LVar1)
            IfFlag(LVar1, DAMAGE_TYPE_SHOCK)
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
                ExecWait(A(EVS_Duplighost_OnHitElectric))
                Return
            Else
                SetConst(LVar0, PRT_MAIN)
                SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
                ExecWait(EVS_Enemy_Hit)
            EndIf
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_BurnHurt1)
            SetConst(LVar2, ANIM_BattleGoombario_BurnHurt2)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_BurnHurt1)
            SetConst(LVar2, ANIM_BattleGoombario_BurnHurt2)
            ExecWait(EVS_Enemy_BurnHit)
            ExecWait(A(EVS_Duplighost_OnDeath))
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_BurnHurt2)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            ExecWait(A(EVS_Duplighost_OnDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            ExecWait(A(EVS_Duplighost_OnShockHit))
            Return
        CaseEq(EVENT_SHOCK_DEATH)
            ExecWait(A(EVS_Duplighost_OnDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            Set(LVar2, 12)
            ExecWait(A(EVS_Duplighost_OnShockDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            ExecWait(A(EVS_Duplighost_OnDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_Run)
            SetConst(LVar2, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_Run)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleGoombario_HurtStill)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

#include "world/common/todo/UnkFunc62.inc.c"
#include "common/ActorJumpToPos.inc.c"

EvtScript N(EVS_HeadbonkFollowthrough) = {
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
    Thread
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
        Set(LVar0, 180)
        Loop(15)
            Sub(LVar0, 60)
            Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Fall)
        Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
        Call(SetActorRotationOffset, ACTOR_SELF, 0, 0, 0)
    EndThread
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Add(LVar0, 60)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.0))
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 15, FALSE, TRUE, FALSE)
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        SetF(LVar5, Float(7.2))
    Else
        Set(LVar5, 18)
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    Call(SetActorDispOffset, ACTOR_SELF, 0, LVar5, 0)
    Wait(1)
    Call(SetActorRotation, ACTOR_SELF, 0, 0, 0)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
    Add(LVar0, 20)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 6, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    Call(SetActorDispOffset, ACTOR_SELF, 0, LVar5, 0)
    Wait(1)
    Add(LVar0, 10)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 4, FALSE, TRUE, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    Call(SetActorDispOffset, ACTOR_SELF, 0, LVar5, 0)
    Wait(1)
    Call(SetActorDispOffset, ACTOR_SELF, 0, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
    Wait(2)
    Call(SetGoalToHome, ACTOR_SELF)
    Call(SetActorSpeed, ACTOR_SELF, Float(8.0))
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Run)
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
    Return
    End
};

EvtScript N(EVS_ApproachPlayer) = {
    Call(UseBattleCamPreset, BTL_CAM_ENEMY_APPROACH)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(func_8024ECF8, BTL_CAM_MODEY_MINUS_1, BTL_CAM_MODEX_1, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 70, 0, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Run)
    Call(SetActorSpeed, ACTOR_SELF, Float(5.0))
    Call(RunToGoal, ACTOR_SELF, 0, FALSE)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Idle)
    Return
    End
};

// copied from goombario.c and used, but result is discarded
EvtScript N(EVS_CalculateJumpTime) = {
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVarB, LVarC, LVarD)
    Call(GetActorPos, ACTOR_SELF, LVarC, LVarD, LVarE)
    IfGt(LVarB, LVarC)
        Sub(LVarB, LVarC)
    Else
        Sub(LVarC, LVarB)
        Set(LVarB, LVarC)
    EndIf
    Sub(LVarB, 20)
    DivF(LVarB, Float(10.588))
    AddF(LVarB, 15)
    Set(LVarA, LVarB)
    Return
    End
};

EvtScript N(EVS_Attack_Headbonk) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    ExecWait(N(EVS_ApproachPlayer))
    ExecWait(N(EVS_CalculateJumpTime))
    Call(GetStatusFlags, ACTOR_SELF, LVarA)
    IfFlag(LVarA, STATUS_FLAG_SHRINK)
        SetF(LVar0, Float(7.2))
        SetF(LVar1, Float(7.6))
        SetF(LVar1, Float(3.6))
    Else
        Set(LVar0, 18)
        Set(LVar1, 19)
        Set(LVar2, 9)
    EndIf
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_PreHeadbonk)
    Call(SetActorDispOffset, ACTOR_SELF, 0, LVar0, 0)
    Wait(5)
    Call(SetActorDispOffset, ACTOR_SELF, 0, LVar1, 0)
    Wait(1)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
    Call(SetActorDispOffset, ACTOR_SELF, 0, LVar2, 0)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(AddGoalPos, ACTOR_SELF, 0, 0, 5)
    Call(SetJumpAnimations, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
    Call(SetActorSounds, ACTOR_SELF, ACTOR_SOUND_JUMP, SOUND_NONE, 0)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GOOMBARIO_JUMP)
    Call(N(UnkFunc62), LVarA, 0)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Call(SetJumpAnimations, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
            Call(N(ActorJumpToPos))
            Thread
                Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
            EndThread
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Wait(20)
            Call(YieldTurn)
            ExecWait(N(EVS_HeadbonkFollowthrough))
            Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    ChildThread
        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.1), Float(0.8), Float(1.0))
        Wait(1)
        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.3), Float(0.5), Float(1.0))
        Wait(1)
        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.0), Float(1.0), Float(1.0))
    EndChildThread
    Wait(1)
    Wait(2)
    Call(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar9)
    Switch(LVar9)
        CaseEq(PARTNER_RANK_NORMAL)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
        CaseEq(PARTNER_RANK_SUPER)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
        CaseEq(PARTNER_RANK_ULTRA)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 3, BS_FLAGS1_INCLUDE_POWER_UPS)
    EndSwitch
    Call(GetActorHP, ACTOR_PLAYER, LVar0)
    IfEq(LVar0, 0)
        Goto(100)
    EndIf
    Set(LVarA, 24)
    Call(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar9)
    Switch(LVar9)
        CaseEq(PARTNER_RANK_NORMAL)
            Thread
                Wait(4)
                Set(LVar0, 0)
                Loop(6)
                    Add(LVar0, 30)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(SetJumpAnimations, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GOOMBARIO_HEADBONK)
            Call(N(UnkFunc62), LVarA, 3)
        CaseEq(PARTNER_RANK_SUPER)
            Thread
                Wait(4)
                Set(LVar0, 0)
                Loop(6)
                    Add(LVar0, 30)
                    Call(SetActorRotation, ACTOR_SELF, 0, 0, LVar0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
            Call(SetJumpAnimations, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GOOMBARIO_HEADBONK)
            Call(N(UnkFunc62), LVarA, 3)
            Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
        CaseEq(PARTNER_RANK_ULTRA)
            Thread
                Wait(4)
                Set(LVar0, 0)
                Loop(6)
                    Add(LVar0, 30)
                    Call(SetActorRotation, ACTOR_SELF, 0, EVT_IGNORE_ARG, LVar0)
                    Wait(1)
                EndLoop
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk)
            EndThread
            Thread
                Set(LVar0, 0)
                Loop(LVarA)
                    Add(LVar0, 133)
                    Call(SetActorRotation, ACTOR_SELF, EVT_IGNORE_ARG, LVar0, EVT_IGNORE_ARG)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_ENABLE)
            Call(SetJumpAnimations, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk, ANIM_BattleGoombario_Headbonk)
            Call(PlaySoundAtActor, ACTOR_SELF, SOUND_GOOMBARIO_HEADBONK)
            Call(N(UnkFunc62), LVarA, 3)
            Call(EnableActorBlur, ACTOR_SELF, ACTOR_BLUR_DISABLE)
    EndSwitch
    ChildThread
        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.1), Float(0.8), Float(1.0))
        Wait(1)
        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.3), Float(0.5), Float(1.0))
        Wait(1)
        Call(SetPartScale, ACTOR_SELF, PRT_MAIN, Float(1.0), Float(1.0), Float(1.0))
    EndChildThread
    Wait(1)
    Wait(2)
    Call(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar9)
    Switch(LVar9)
        CaseEq(PARTNER_RANK_NORMAL)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 1, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(PARTNER_RANK_SUPER)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
        CaseEq(PARTNER_RANK_ULTRA)
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, 0, 0, 0, 3, BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Label(100)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(YieldTurn)
            ExecWait(N(EVS_HeadbonkFollowthrough))
        EndCaseGroup
    EndSwitch
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

API_CALLABLE(N(CalculateTattleCamBoomLength)) {
    Actor* actor = get_actor(script->owner1.actorID);
    Actor* targetActor = get_actor(actor->targetActorID);
    s16 targetActorSizeX;
    u8 targetActorSizeY;
    u8 targetActorLargerDimension;

    if (!(targetActor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
        script->varTable[1] += targetActor->size.y / 2;
        script->varTable[1] += targetActor->size.y / 4;
    } else {
        script->varTable[1] -= targetActor->size.y / 2;
        script->varTable[1] -= targetActor->size.y / 4;
    }

    targetActorSizeY = targetActor->size.y;
    targetActorSizeX = targetActor->size.x;
    targetActorLargerDimension = targetActorSizeY;
    if (targetActorSizeY < targetActorSizeX) {
        targetActorLargerDimension = targetActorSizeX;
    }

    script->varTable[3] = targetActorLargerDimension + 126;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(OpenTattleWindow)) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, (s32) fx_tattle_window(0, 106.0f, 144.0f, 0, 1.0f, 0));
    return ApiStatus_DONE2;
}

API_CALLABLE(N(HideTattleWindow)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *args++);

    effect->data.tattleWindow->pos.y = NPC_DISPOSE_POS_Y;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CloseTattleWindow)) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, *args++);

    effect->data.tattleWindow->pos.y = 144.0f;
    effect->flags |= FX_INSTANCE_FLAG_DISMISS;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Move_Tattle) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_DISABLE)
    Call(SetActorJumpGravity, ACTOR_SELF, Float(1.8))
    Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_SELF, 10, FALSE, TRUE, FALSE)
    Wait(10)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetBattleFlagBits, BS_FLAGS1_TATTLE_OPEN, TRUE)
    Call(N(OpenTattleWindow), LVar5)
    Wait(12)
    Call(EnableBattleStatusBar, FALSE)
    Call(SetCamEnabled, CAM_TATTLE, TRUE)
    Call(SetCamNoDraw, CAM_TATTLE, FALSE)
    Call(SetCamPerspective, CAM_TATTLE, CAM_UPDATE_MODE_6, 25, 16, 1024)
    Call(SetCamViewport, CAM_TATTLE, 37, 95, 138, 99)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Sub(LVar0, 8)
    Set(LVar1, 0)
    Call(N(CalculateTattleCamBoomLength))
    Wait(1)
    Call(func_802CAE50, CAM_TATTLE, LVar0, LVar1, LVar2)
    Call(func_802CABE8, CAM_TATTLE, 0, LVar3, 100, 4)
    Wait(2)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_TATTLE_WINDOW_OPEN)
    Call(SetCamNoDraw, CAM_TATTLE, TRUE)
    Wait(10)
    Call(ActorSpeak, MSG_EnemyTattle_Mario, ACTOR_SELF, PRT_MAIN, ANIM_BattleGoombario_Talk, ANIM_BattleGoombario_Idle)
    Call(N(CloseTattleWindow), LVar5)
    Wait(12)
    Call(SetCamEnabled, CAM_TATTLE, FALSE)
    Wait(32)
    Call(EnableBattleStatusBar, TRUE)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(SetBattleFlagBits, BS_FLAGS1_TATTLE_OPEN, FALSE)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(RandInt, 100, LVar0)
    IfLt(LVar0, 10)
        ExecWait(N(EVS_Move_Tattle))
    Else
        ExecWait(N(EVS_Attack_Headbonk))
    EndIf
    Return
    End
};

Formation A(GoombarioCloneFormation) = {
    ACTOR_BY_POS(NAMESPACE, A(DuplighostSummonPos), 0),
};
