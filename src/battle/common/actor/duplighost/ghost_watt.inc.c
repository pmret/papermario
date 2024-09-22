#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleWatt.h"
#include "effects.h"

#define NAMESPACE A(watt_clone)

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_HandleEvent);

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleWatt_Idle,
    STATUS_KEY_STONE,     ANIM_BattleWatt_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleWatt_Still,
    STATUS_KEY_POISON,    ANIM_BattleWatt_Idle,
    STATUS_KEY_STOP,      ANIM_BattleWatt_Still,
    STATUS_KEY_STATIC,    ANIM_BattleWatt_Idle,
    STATUS_KEY_PARALYZE,  ANIM_BattleWatt_Still,
    STATUS_KEY_DIZZY,     ANIM_BattleWatt_Injured,
    STATUS_KEY_FEAR,      ANIM_BattleWatt_Injured,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_SHOCK,   99,
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
        .flags = ACTOR_PART_FLAG_NO_TARGET,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { -1, 20 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ELECTRIFIED,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
    {
        .flags = ACTOR_PART_FLAG_INVISIBLE | ACTOR_PART_FLAG_PRIMARY_TARGET | ACTOR_PART_FLAG_SKIP_MOVEMENT_ALLOC,
        .index = PRT_TARGET,
        .posOffset = { 0, 50, 0 },
        .targetOffset = { -1, -30 },
        .opacity = 255,
        .idleAnimations = NULL,
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAG_ELECTRIFIED,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, -8 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_GHOST_WATT,
    .level = ACTOR_LEVEL_GHOST_WATT,
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
    .size = { 34, 28 },
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

API_CALLABLE(N(WattFXUpdate)) {
    Actor* actor = get_actor(script->owner1.enemyID);
    ActorState* state = &actor->state;
    WattEffectData* wattEffectData;
    f32 x, y, z;

    if (isInitialCall) {
        wattEffectData = heap_malloc(sizeof(*wattEffectData));
        actor->state.varTablePtr[2] = wattEffectData;
        wattEffectData->isBouncing = TRUE;
        wattEffectData->bouncePhase = 0;
        wattEffectData->isActive = TRUE;
        wattEffectData->currentEffectIndex = 0;
        wattEffectData->effect1 = fx_static_status(0, actor->curPos.x, actor->curPos.y, actor->curPos.z, (actor->debuff != STATUS_KEY_SHRINK) ? 1.0f : 0.4f, 5, 0);
        wattEffectData->effect2 = fx_static_status(1, actor->curPos.x, NPC_DISPOSE_POS_Y, actor->curPos.z, (actor->debuff != STATUS_KEY_SHRINK) ? 1.0f : 0.4f, 5, 0);
        wattEffectData->initialized = TRUE;
        wattEffectData->debuff = actor->debuff;
    }

    wattEffectData = state->varTablePtr[2];
    if (wattEffectData->initialized) {
        if (wattEffectData->isBouncing && actor->debuff != STATUS_KEY_STOP) {
            wattEffectData->bouncePhase += 15;
            wattEffectData->bouncePhase = clamp_angle(wattEffectData->bouncePhase);
        }
        actor->verticalRenderOffset = sin_rad(DEG_TO_RAD(wattEffectData->bouncePhase)) * 3.0f;

        x = actor->curPos.x + actor->headOffset.x;
        y = actor->curPos.y + actor->headOffset.y + actor->verticalRenderOffset + (actor->debuff != STATUS_KEY_SHRINK ? 12.0 : 4.800000000000001); // 4.8 doesn't match
        z = actor->curPos.z + actor->headOffset.z;
        if (wattEffectData->isActive) {
            switch (wattEffectData->currentEffectIndex) {
                case 0:
                    if (wattEffectData->effect1 == NULL) {
                        wattEffectData->effect1 = fx_static_status(0, x, y, z, (actor->debuff != STATUS_KEY_SHRINK) ? 1.0f : 0.4f, 5, 0);
                    }

                    if (wattEffectData->effect2 != NULL) {
                        wattEffectData->effect2->flags |= FX_INSTANCE_FLAG_DISMISS;
                        wattEffectData->effect2 = NULL;
                    }
                    wattEffectData->effect1->data.staticStatus->pos.x = x;
                    wattEffectData->effect1->data.staticStatus->pos.y = y;
                    wattEffectData->effect1->data.staticStatus->pos.z = z;
                    break;
                case 1:
                    if (wattEffectData->effect1 != NULL) {
                        wattEffectData->effect1->flags |= FX_INSTANCE_FLAG_DISMISS;
                        wattEffectData->effect1 = NULL;
                    }
                    if (wattEffectData->effect2 == NULL) {
                        wattEffectData->effect2 = fx_static_status(1, x, y, z, (actor->debuff != STATUS_KEY_SHRINK) ? 1.0f : 0.4f, 5, 0);

                    }
                    wattEffectData->effect2->data.staticStatus->pos.x = x;
                    wattEffectData->effect2->data.staticStatus->pos.y = y;
                    wattEffectData->effect2->data.staticStatus->pos.z = z;
                    break;
            }
        } else {
            if (wattEffectData->effect1 != NULL) {
                wattEffectData->effect1->flags |= FX_INSTANCE_FLAG_DISMISS;
                wattEffectData->effect1 = NULL;
            }
            if (wattEffectData->effect2 != NULL) {
                wattEffectData->effect2->flags |= FX_INSTANCE_FLAG_DISMISS;
                wattEffectData->effect2 = NULL;
            }
        }
        if (wattEffectData->debuff != actor->debuff && wattEffectData->isActive) {
            if (wattEffectData->effect1 != NULL) {
                wattEffectData->effect1->flags |= FX_INSTANCE_FLAG_DISMISS;
                wattEffectData->effect1 = NULL;
            }
            if (wattEffectData->effect2 != NULL) {
                wattEffectData->effect2->flags |= FX_INSTANCE_FLAG_DISMISS;
                wattEffectData->effect2 = NULL;
            }
        }
        wattEffectData->debuff = actor->debuff;
        return ApiStatus_BLOCK;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Idle) = {
    SetPriority(99)
    Call(N(WattFXUpdate))
    Return
    End
};

API_CALLABLE(N(WattFXRemove)) {
    WattEffectData* wattEffectData = get_actor(script->owner1.enemyID)->state.varTablePtr[2];

    wattEffectData->initialized = FALSE;

    if (wattEffectData->effect1 != NULL) {
        wattEffectData->effect1->flags |= FX_INSTANCE_FLAG_DISMISS;
    }

    if (wattEffectData->effect2 != NULL) {
        wattEffectData->effect2->flags |= FX_INSTANCE_FLAG_DISMISS;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(WattFXSetBouncing)) {
    Bytecode* args = script->ptrReadPos;
    WattEffectData* wattEffectData = get_actor(script->owner1.enemyID)->state.varTablePtr[2];

    wattEffectData->isBouncing = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(WattFXSetActive)) {
    Bytecode* args = script->ptrReadPos;
    WattEffectData* wattEffectData = get_actor(script->owner1.enemyID)->state.varTablePtr[2];

    wattEffectData->isActive = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(WattFXSetEffect)) {
    Bytecode* args = script->ptrReadPos;
    WattEffectData* wattEffectData = get_actor(script->owner1.enemyID)->state.varTablePtr[2];

    wattEffectData->currentEffectIndex = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(N(WattFXSetBouncing), 0)
    Call(N(WattFXSetActive), 1)
    Call(N(WattFXSetEffect), 0)
    Call(GetLastEvent, ACTOR_SELF, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleWatt_Hurt)
            ExecWait(EVS_Enemy_Hit)
        EndCaseGroup
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleWatt_BurnHurt)
            SetConst(LVar2, ANIM_BattleWatt_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
        CaseEq(EVENT_BURN_DEATH)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleWatt_BurnHurt)
            SetConst(LVar2, ANIM_BattleWatt_BurnStill)
            ExecWait(EVS_Enemy_BurnHit)
            Call(N(WattFXRemove))
            ExecWait(A(EVS_Duplighost_OnDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleWatt_BurnStill)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_SPIN_SMASH_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleWatt_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
        CaseEq(EVENT_SPIN_SMASH_DEATH)
            Call(N(WattFXRemove))
            ExecWait(A(EVS_Duplighost_OnDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleWatt_Hurt)
            ExecWait(EVS_Enemy_SpinSmashHit)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleWatt_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
        CaseOrEq(EVENT_AIR_LIFT_FAILED)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleWatt_Idle)
            ExecWait(EVS_Enemy_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_DEATH)
            Call(N(WattFXRemove))
            ExecWait(A(EVS_Duplighost_OnDeath))
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleWatt_Hurt)
            ExecWait(EVS_Enemy_Hit)
            Wait(10)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleWatt_Hurt)
            ExecWait(EVS_Enemy_Death)
            Return
        CaseEq(EVENT_RECOVER_STATUS)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleWatt_Idle)
            ExecWait(EVS_Enemy_Recover)
        CaseEq(EVENT_SCARE_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleWatt_Run)
            SetConst(LVar2, ANIM_BattleWatt_Hurt)
            ExecWait(EVS_Enemy_ScareAway)
            Return
        CaseEq(EVENT_BEGIN_AIR_LIFT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleWatt_Run)
            ExecWait(EVS_Enemy_AirLift)
        CaseEq(EVENT_BLOW_AWAY)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleWatt_Hurt)
            ExecWait(EVS_Enemy_BlowAway)
            Return
        CaseDefault
    EndSwitch
    Call(N(WattFXSetBouncing), 1)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

#include "common/UnkBackgroundFunc3.inc.c"

#include "common/SetBackgroundAlpha.inc.c"

EvtScript N(EVS_TakeTurn) = {
    Call(UseIdleAnimation, ACTOR_SELF, FALSE)
    Call(UseBattleCamPreset, BTL_CAM_REPOSITION)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(SetBattleCamTarget, LVar0, LVar1, LVar2)
    Call(SetBattleCamDist, 350)
    Call(SetBattleCamOffsetY, 40)
    Call(MoveBattleCamOver, 80)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_TARGET, BTL_CAM_XADJ_AVG, FALSE)
    Call(SetTargetActor, ACTOR_SELF, ACTOR_PLAYER)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Run)
    Call(N(WattFXSetEffect), 1)
    Call(AddGoalPos, ACTOR_SELF, 15, -10, 5)
    Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Idle)
    Call(N(WattFXSetEffect), 0)
    Wait(5)
    Call(N(WattFXSetBouncing), 0)
    Call(AddGoalPos, ACTOR_SELF, 25, 20, 0)
    Call(FlyToGoal, ACTOR_SELF, 15, -20, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Strain)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(FlyToGoal, ACTOR_SELF, 5, 0, EASING_COS_IN_OUT)
    Call(EnemyTestTarget, ACTOR_SELF, LVar0, 0, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_MISS)
        CaseOrEq(HIT_RESULT_LUCKY)
            Set(LVarA, LVar0)
            Thread
                Wait(5)
                Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Idle)
            EndThread
            Call(SetGoalToTarget, ACTOR_SELF)
            Call(AddGoalPos, ACTOR_SELF, -40, 10, 0)
            Call(FlyToGoal, ACTOR_SELF, 10, -20, EASING_QUADRATIC_OUT)
            IfEq(LVarA, HIT_RESULT_LUCKY)
                Call(EnemyTestTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_TRIGGER_LUCKY, 0, 0, 0)
            EndIf
            Call(N(WattFXSetActive), 1)
            Call(N(WattFXSetBouncing), 1)
            Wait(20)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(YieldTurn)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Run)
            Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Idle)
            Call(UseIdleAnimation, ACTOR_SELF, TRUE)
            Return
        EndCaseGroup
    EndSwitch
    Call(N(WattFXSetActive), 0)
    Set(LVarA, 40)
    Call(AddBattleCamDist, -75)
    Call(MoveBattleCamOver, LVarA)
    Call(SetBattleCamTargetingModes, BTL_CAM_YADJ_NONE, BTL_CAM_XADJ_NONE, TRUE)
    Call(PlaySoundAtActor, ACTOR_SELF, SOUND_WATT_CHARGE)
    Call(GetStatusFlags, ACTOR_SELF, LVar0)
    IfFlag(LVar0, STATUS_FLAG_SHRINK)
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 4)
        PlayEffect(EFFECT_RADIAL_SHIMMER, 8, LVar0, LVar1, LVar2, Float(0.52), LVarA, 0)
    Else
        Call(GetActorPos, ACTOR_SELF, LVar0, LVar1, LVar2)
        Add(LVar1, 12)
        PlayEffect(EFFECT_RADIAL_SHIMMER, 8, LVar0, LVar1, LVar2, Float(1.3), LVarA, 0)
    EndIf
    Call(N(UnkBackgroundFunc3))
    Set(LVar9, 0)
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_StrainBigger)
    Loop(LVarA)
        Add(LVar9, 3)
        IfGt(LVar9, 200)
            Set(LVar9, 200)
        EndIf
        Call(N(SetBackgroundAlpha), LVar9)
        Wait(1)
    EndLoop
    Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Idle)
    Call(SetActorPaletteEffect, ACTOR_SELF, PRT_MAIN, ACTOR_PAL_ADJUST_WATT_IDLE)
    Call(AddBattleCamDist, 75)
    Call(MoveBattleCamOver, 5)
    Thread
        Wait(2)
        Call(N(SetBackgroundAlpha), 0)
    EndThread
    Call(GetActorVar, ACTOR_SELF, AVAR_Copy_PartnerLevel, LVar9)
    Switch(LVar9)
        CaseEq(PARTNER_RANK_NORMAL)
            Wait(2)
#if VERSION_JP
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE, SUPPRESS_EVENT_ALL, 0, 2, BS_FLAGS1_TRIGGER_EVENTS)
#else
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE, SUPPRESS_EVENT_ALL, 0, 3, BS_FLAGS1_TRIGGER_EVENTS)
#endif
        CaseEq(PARTNER_RANK_SUPER)
            Wait(2)
#if VERSION_JP
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE, SUPPRESS_EVENT_ALL, 0, 3, BS_FLAGS1_TRIGGER_EVENTS)
#else
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE, SUPPRESS_EVENT_ALL, 0, 4, BS_FLAGS1_TRIGGER_EVENTS)
#endif
        CaseEq(PARTNER_RANK_ULTRA)
            Wait(2)
#if VERSION_JP
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE, SUPPRESS_EVENT_ALL, 0, 4, BS_FLAGS1_TRIGGER_EVENTS)
#else
            Call(EnemyDamageTarget, ACTOR_SELF, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE, SUPPRESS_EVENT_ALL, 0, 5, BS_FLAGS1_TRIGGER_EVENTS)
#endif
    EndSwitch
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
            Call(N(WattFXSetActive), 1)
            Call(N(WattFXSetBouncing), 1)
            Call(AddGoalPos, ACTOR_SELF, 25, 10, 0)
            Call(FlyToGoal, ACTOR_SELF, 15, -10, EASING_COS_IN_OUT)
            Wait(15)
            Call(YieldTurn)
            Call(SetGoalToHome, ACTOR_SELF)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Run)
            Call(FlyToGoal, ACTOR_SELF, 30, 0, EASING_COS_IN_OUT)
            Call(SetAnimation, ACTOR_SELF, PRT_MAIN, ANIM_BattleWatt_Idle)
        EndCaseGroup
    EndSwitch
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};

Formation A(WattCloneFormation) = {
    ACTOR_BY_POS(NAMESPACE, A(DuplighostSummonPos), 0),
};
