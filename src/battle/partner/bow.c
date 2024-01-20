#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "battle/action_cmd/smack.h"
#include "battle/action_cmd/spook.h"
#include "sprite/npc/BattleBow.h"
#include "sprite/player.h"

#define NAMESPACE battle_partner_bow

extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_ExecuteAction);
extern EvtScript N(EVS_Celebrate);
extern EvtScript N(runAway);
extern EvtScript N(runAwayFail);
extern EvtScript N(smack);
extern EvtScript N(outtaSight);
extern EvtScript N(spook);
extern EvtScript N(fanSmack);
extern EvtScript N(hidePlayer);

extern s32 bMarioHideAnims[];

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_ZERO            = 0,
};

API_CALLABLE(N(IsOuttaSightActive)) {
    BattleStatus* battleStatus = &gBattleStatus;
    script->varTable[0] = battleStatus->outtaSightActive;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(GetBowSize)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* partnerTargetActor = get_actor(partnerActor->targetActorID);
    f32 partnerTargetActorSize = (partnerTargetActor->size.y + partnerTargetActor->size.x) / 2;

    partnerTargetActorSize = (partnerTargetActorSize * 150.0f) / 100.0f;
    script->varTable[0] = partnerTargetActorSize;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(ApplyOuttaSight)) {
    ActorPart* playerActorPartTable = gBattleStatus.playerActor->partsTable;

    gBattleStatus.outtaSightActive = 1;
    if (!(gBattleStatus.flags2 & BS_FLAGS2_PLAYER_TURN_USED)) {
        gBattleStatus.outtaSightActive = -1;
    }

    playerActorPartTable->idleAnimations = bMarioHideAnims;
    gBattleStatus.hustleTurns = 0;
    gBattleStatus.flags1 &= ~BS_FLAGS1_HUSTLED;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(ModifyBowPos)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* playerActor = battleStatus->playerActor;
    f32 deltaX = evt_get_variable(script, *args++);
    f32 deltaY = evt_get_variable(script, *args++);
    f32 scalingFactor = playerActor->scalingFactor;

    deltaX *= scalingFactor;
    script->varTable[0] += deltaX;

    deltaY *= scalingFactor;
    script->varTable[1] += deltaY;

    return ApiStatus_DONE2;
}

/// Duplicate of IsPartnerImmobile
API_CALLABLE(N(IsPartnerImmobile)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    s32 isImmobile = playerActor->debuff == STATUS_KEY_FEAR
                     || playerActor->debuff == STATUS_KEY_DIZZY
                     || playerActor->debuff == STATUS_KEY_PARALYZE
                     || playerActor->debuff == STATUS_KEY_SLEEP
                     || playerActor->debuff == STATUS_KEY_FROZEN
                     || playerActor->debuff == STATUS_KEY_STOP;

    if (playerActor->stoneStatus == STATUS_KEY_STONE) {
        isImmobile = TRUE;
    }

    script->varTable[0] = isImmobile;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(RestorePlayerIdleAnimations)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    ActorPart* playerActorPartTable = battleStatus->playerActor->partsTable;
    playerActorPartTable->idleAnimations = bMarioIdleAnims;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(AverageSpookChance)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor;
    ActorBlueprint* targetActorBlueprint;
    ActorPart* targetActorPart;
    s32 spookChance;
    s32 chanceTotal = 0;
    s32 nTargets = 0;
    s32 i;

    for (i = 0; i < partnerActor->targetListLength; i++) {
        targetActor = get_actor(partnerActor->targetData[i].actorID);
        targetActorPart = get_actor_part(targetActor, partnerActor->targetData[i].partID);
        targetActorBlueprint = targetActor->actorBlueprint;
        spookChance = targetActorBlueprint->spookChance;

        if (targetActor->transparentStatus == STATUS_KEY_TRANSPARENT) {
            spookChance = 0;
        }

        if (targetActorPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
            spookChance = 0;
        }

        if (spookChance > 0) {
            chanceTotal += spookChance;
            nTargets++;
        }
    }

    if (nTargets > 0) {
        script->varTable[0] = chanceTotal / nTargets;
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleBow_Walk,
    STATUS_KEY_STONE,     ANIM_BattleBow_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleBow_Pray,
    STATUS_KEY_POISON,    ANIM_BattleBow_Still,
    STATUS_KEY_STOP,      ANIM_BattleBow_Still,
    STATUS_KEY_DAZE,      ANIM_BattleBow_Injured,
    STATUS_KEY_INACTIVE,  ANIM_BattleBow_Still,
    STATUS_END,
};

s32 N(DefenseTable)[] = {
    ELEMENT_NORMAL,   0,
    ELEMENT_END,
};

s32 N(StatusTable)[] = {
    STATUS_KEY_NORMAL,            100,
    STATUS_KEY_DEFAULT,           100,
    STATUS_KEY_SLEEP,             100,
    STATUS_KEY_POISON,            100,
    STATUS_KEY_FROZEN,            100,
    STATUS_KEY_DIZZY,             100,
    STATUS_KEY_FEAR,              100,
    STATUS_KEY_STATIC,            100,
    STATUS_KEY_PARALYZE,          100,
    STATUS_KEY_SHRINK,            100,
    STATUS_KEY_STOP,              100,
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
        .flags = 0,
        .index = PRT_MAIN,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 9, 19 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_BOW,
    .level = ACTOR_LEVEL_BOW,
    .maxHP = 99,
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
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 36, 29 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 22 },
    .statusTextOffset = { 10, 22 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_SELF, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_SELF, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_SELF, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_SELF, Ref(N(EVS_HandlePhase)))
    Return
    End
};

EvtScript N(EVS_Idle) = {
    Return
    End
};

EvtScript N(EVS_HandleEvent) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(CloseActionCommandInfo)
    Call(GetLastEvent, ACTOR_PARTNER, LVar0)
    Switch(LVar0)
        CaseOrEq(EVENT_HIT_COMBO)
        CaseOrEq(EVENT_HIT)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            SetConst(LVar2, ANIM_BattleBow_Hurt)
            ExecWait(EVS_Partner_Hit)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            ExecWait(EVS_Partner_Drop)
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            ExecWait(EVS_Partner_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SPIKE_CONTACT)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            Set(LVar2, 14)
            ExecWait(EVS_Partner_SpikeContact)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_BURN_CONTACT)
            SetConst(LVar1, ANIM_BattleBow_BurnHurt)
            Set(LVar2, 14)
            SetConst(LVar3, ANIM_BattleBow_BurnStill)
            ExecWait(EVS_Partner_BurnContact)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar1, ANIM_BattleBow_BurnHurt)
            SetConst(LVar2, ANIM_BattleBow_BurnStill)
            ExecWait(EVS_Partner_BurnHit)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            Set(LVar2, 14)
            ExecWait(EVS_Partner_ShockHit)
        CaseEq(EVENT_33)
            SetConst(LVar1, ANIM_BattleBow_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_RECOVER_FROM_KO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Idle)
            SetConst(LVar2, ANIM_BattleBow_Run)
            Set(LVar3, 20)
            ExecWait(EVS_Partner_Recover)
        CaseOrEq(EVENT_18)
        CaseOrEq(EVENT_BLOCK)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleBow_Block)
            ExecWait(EVS_Partner_NoDamageHit)
            Wait(10)
        EndCaseGroup
        CaseDefault
    EndSwitch
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};

EvtScript N(EVS_TakeTurn) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_EXECUTE_ACTION)
            ExecWait(N(EVS_ExecuteAction))
        CaseEq(PHASE_CELEBRATE)
            ExecWait(N(EVS_Celebrate))
        CaseEq(PHASE_RUN_AWAY_START)
            ExecWait(N(runAway))
        CaseEq(PHASE_RUN_AWAY_FAIL)
            ExecWait(N(runAwayFail))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Celebrate) = {
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Celebrate)
    Wait(36)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    Return
    End
};

EvtScript N(runAway) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_BattleBow_Run)
    ExecWait(EVS_Partner_RunAway)
    Return
    End
};

EvtScript N(runAwayFail) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Run)
    Call(SetActorYaw, ACTOR_PARTNER, 0)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Call(GetBattlePhase, LVar0)
    Switch(LVar0)
        CaseEq(PHASE_ENEMY_BEGIN)
            Call(N(IsOuttaSightActive))
            IfNe(LVar0, 0)
                ExecWait(N(hidePlayer))
            EndIf
    EndSwitch
    Return
    End
};

EvtScript N(EVS_ExecuteAction) = {
    Call(ShowActionHud, TRUE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar0)
        CaseEq(BTL_MENU_TYPE_STAR_POWERS)
            Call(LoadStarPowerScript)
            ExecWait(LVar0)
            Return
    EndSwitch
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_SMACK1)
            ExecWait(N(smack))
        CaseEq(MOVE_SMACK2)
            ExecWait(N(smack))
        CaseEq(MOVE_SMACK3)
            ExecWait(N(smack))
        CaseEq(MOVE_OUTTA_SIGHT)
            Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
            ExecWait(N(outtaSight))
        CaseEq(MOVE_SPOOK)
            Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
            ExecWait(N(spook))
        CaseEq(MOVE_FAN_SMACK)
            ExecWait(N(fanSmack))
    EndSwitch
    Return
    End
};

EvtScript N(returnHome2) = {
    Call(PartnerYieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_04)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOO_VANISH_A)
    Thread
        Set(LVar0, 200)
        Loop(20)
            Sub(LVar0, 10)
            Call(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Wait(10)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Run)
    Call(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOO_APPEAR_A)
    Set(LVar0, 55)
    Loop(20)
        Add(LVar0, 10)
        Call(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
        Wait(1)
    EndLoop
    Call(SetPartAlpha, ACTOR_PARTNER, -1, 255)
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(PartnerYieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOO_VANISH_A)
    Thread
        Set(LVar0, 200)
        Loop(20)
            Sub(LVar0, 10)
            Call(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Wait(10)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Run)
    Call(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOO_APPEAR_A)
    Set(LVar0, 55)
    Loop(20)
        Add(LVar0, 10)
        Call(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
        Wait(1)
    EndLoop
    Call(SetPartAlpha, ACTOR_PARTNER, -1, 255)
    Return
    End
};

EvtScript N(80238EE0) = {
    Call(PartnerYieldTurn)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Run)
    Call(FlyToGoal, ACTOR_PARTNER, 15, 0, EASING_COS_IN_OUT)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    Return
    End
};

EvtScript N(smack) = {
    Call(LoadActionCommand, ACTION_COMMAND_SMACK)
    Call(action_command_smack_init)
    Call(SetActionHudPrepareTime, 0)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_SMACK1)
            Call(SetupMashMeter, 4, 40, 70, 99, 100, 0)
            Set(LVarB, 60 * DT)
            Set(LVarC, 1)
        CaseEq(MOVE_SMACK2)
            Call(SetupMashMeter, 5, 35, 60, 80, 99, 100)
            Set(LVarB, 60 * DT)
            Set(LVarC, 1)
        CaseEq(MOVE_SMACK3)
            Call(SetupMashMeter, 5, 35, 60, 80, 99, 100)
            Set(LVarB, 60 * DT)
            Set(LVarC, 1)
    EndSwitch
    Wait(10)
    Thread
        Wait(10)
        Set(LVar0, LVarB)
        Add(LVar0, -3)
        Call(action_command_smack_start, 0, LVar0, 3, 0)
        Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    EndThread
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOO_VANISH_A)
    Call(SetPartAlpha, ACTOR_PARTNER, -1, 55)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Thread
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Run)
        Call(AddGoalPos, ACTOR_PARTNER, -15, -10, 0)
        Call(FlyToGoal, ACTOR_PARTNER, 15, 0, EASING_COS_IN_OUT)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    EndThread
    Call(UseBattleCamPreset, BTL_CAM_PRESET_13)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamZoom, 180)
    Call(MoveBattleCamOver, 30)
    Call(SetBattleCamOffsetZ, 9)
    Call(func_8024EDA4)
    Wait(15)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOO_APPEAR_A)
    Set(LVar0, 55)
    Loop(5)
        Add(LVar0, 40)
        Call(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
        Wait(1)
    EndLoop
    Call(SetPartAlpha, ACTOR_PARTNER, -1, 255)
    Call(UseBattleCamPresetImmediately, 19)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_PreSlap)
    Wait(20)
    Set(LVarF, 0)
    Set(LVarE, 0)
    Set(LVarD, 0)
    Set(LFlag0, FALSE)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_SELF)
    Loop(15)
        Call(SetActorDispOffset, ACTOR_PARTNER, Float(0.5), 0, 0)
        Wait(1)
        Call(SetActorDispOffset, ACTOR_PARTNER, Float(-0.5), 0, 0)
        Wait(1)
    EndLoop
    Call(GetPartnerActionSuccess, LVarB)
    Call(func_80269600, LVarD)
    Label(0)
    Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_SlapOnce)
        Call(CloseActionCommandInfo)
        Set(LVar0, 0)
        Loop(20)
            Add(LVar0, -45)
            Call(SetActorYaw, ACTOR_PARTNER, LVar0)
            Wait(1)
        EndLoop
        Call(SetActorYaw, ACTOR_PARTNER, 0)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Injured)
        Call(AddActorDecoration, ACTOR_SELF, PRT_ZERO, 0, ACTOR_DECORATION_SEEING_STARS)
        Wait(30)
        Call(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 0)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
        Wait(10)
        ExecWait(N(EVS_ReturnHome))
        Return
    EndIf
    Add(LVarE, 1)
    IfGt(LVarE, LVarD)
        Goto(2)
    EndIf
    Call(SetActorScale, ACTOR_PARTNER, Float(1.4), Float(1.4), Float(1.0))
    IfEq(LFlag0, FALSE)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_SlapOnce)
        Set(LFlag0, TRUE)
        Call(SetDamageSource, DMG_SRC_NEXT_SLAP_LEFT)
    Else
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_SlapBack)
        Set(LFlag0, FALSE)
        Call(SetDamageSource, DMG_SRC_NEXT_SLAP_RIGHT)
    EndIf
    Wait(2)
    Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.5))
        Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
        Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.2))
    EndThread
    IfEq(LVarE, 1)
        Call(N(GetBowSize))
        Call(AddBattleCamZoom, LVar0)
        Call(MoveBattleCamOver, 5)
    Else
        Call(AddBattleCamZoom, 25)
        Call(MoveBattleCamOver, 5)
    EndIf
    Call(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_HURT, SOUND_BOW_SMACK, 0)
    IfEq(LVarE, 1)
        IfGt(LVarB, 99)
            Call(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarC, BS_FLAGS1_NICE_HIT | BS_FLAGS1_INCLUDE_POWER_UPS)
        Else
            Call(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarC, BS_FLAGS1_INCLUDE_POWER_UPS)
        EndIf
        Goto(1)
    Else
        IfGt(LVarB, 99)
            Call(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarC, BS_FLAGS1_NICE_HIT)
        Else
            Call(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarC, 0)
        EndIf
        Goto(1)
    EndIf
    Label(1)
    Wait(8)
    Add(LVarF, 10)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    Goto(0)
    Label(2)
    IfEq(LVarE, 1)
        Call(N(GetBowSize))
        Call(AddBattleCamZoom, LVar0)
        Call(MoveBattleCamOver, 5)
    Else
        Call(AddBattleCamZoom, 25)
        Call(MoveBattleCamOver, 5)
    EndIf
    Call(SetActorScale, ACTOR_PARTNER, Float(1.4), Float(1.4), Float(1.0))
    IfEq(LFlag0, FALSE)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_SlapOnce)
        Set(LFlag0, TRUE)
        Call(SetDamageSource, DMG_SRC_LAST_SLAP_LEFT)
    Else
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_SlapBack)
        Set(LFlag0, FALSE)
        Call(SetDamageSource, DMG_SRC_LAST_SLAP_RIGHT)
    EndIf
    Wait(2)
    Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
    Call(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_HURT, SOUND_BOW_SMACK, 0)
    Call(GetPartnerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(99)
            Call(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarC, BS_FLAGS1_NICE_HIT | BS_FLAGS1_TRIGGER_EVENTS)
        CaseDefault
            Call(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarC, BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Wait(8)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
            ExecWait(N(returnHome2))
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(outtaSight) = {
    Call(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_NO_INACTIVE_ANIM, TRUE)
    Call(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_USING_IDLE_ANIM, FALSE)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_19)
    Call(SetBattleCamTarget, -129, 28, 0)
    Call(SetBattleCamOffsetZ, 15)
    Call(SetBattleCamZoom, 260)
    Call(MoveBattleCamOver, 40)
    Thread
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar1, 5)
        Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(FlyToGoal, ACTOR_PARTNER, 10, 0, EASING_COS_IN_OUT)
    EndThread
    Set(LVar0, 0)
    Loop(10)
        Add(LVar0, 18)
        Call(SetActorYaw, ACTOR_PARTNER, LVar0)
        Wait(1)
    EndLoop
    Wait(10)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, -30)
    Add(LVar1, 30)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_PARTNER, 20, 30, EASING_COS_IN_OUT)
    Thread
        Set(LVar0, 180)
        Loop(10)
            Sub(LVar0, 18)
            Call(SetActorYaw, ACTOR_PARTNER, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Set(LVar0, 255)
        Loop(30)
            Sub(LVar0, 5)
            Call(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(N(ModifyBowPos), -10, 20)
    Add(LVar2, 5)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_PARTNER, 20, 0, EASING_LINEAR)
    Call(N(IsPartnerImmobile))
    IfEq(LVar0, 0)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Crouch)
    EndIf
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOW_VANISH)
    Set(LVar0, 255)
    Loop(15)
        Sub(LVar0, 10)
        Call(SetPartAlpha, ACTOR_PLAYER, 1, LVar0)
        Wait(1)
    EndLoop
    Wait(15)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 30)
    Call(N(ApplyOuttaSight))
    Call(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_NO_INACTIVE_ANIM, FALSE)
    Return
    End
};

EvtScript N(hidePlayer) = {
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Wait(20)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOW_APPEAR)
    Thread
        Wait(10)
        Set(LVar0, 105)
        Loop(30)
            Add(LVar0, 5)
            Call(SetPartAlpha, ACTOR_PLAYER, 1, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Thread
        Set(LVar0, 105)
        Loop(30)
            Add(LVar0, 5)
            Call(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Call(PartnerYieldTurn)
    Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    Call(MoveBattleCamOver, 40)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(FlyToGoal, ACTOR_PARTNER, 20, 0, EASING_COS_IN_OUT)
    Call(N(RestorePlayerIdleAnimations))
    Wait(20)
    Return
    End
};

EvtScript N(spook) = {
    Call(LoadActionCommand, ACTION_COMMAND_SPOOK)
    Call(action_command_spook_init)
    Call(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    Call(SetActionHudPrepareTime, 20)
    Wait(10)
    Thread
        Call(UseBattleCamPreset, BTL_CAM_PRESET_15)
        Call(BattleCamTargetActor, ACTOR_SELF)
        Call(SetBattleCamOffsetZ, 4)
        Call(AddBattleCamZoom, -150)
        Call(MoveBattleCamOver, 20)
        Call(func_8024EDA4)
    EndThread
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 40)
    Add(LVar1, 10)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(FlyToGoal, ACTOR_PARTNER, 20, 0, EASING_COS_IN_OUT)
    Wait(15)
    Call(UseBattleCamPresetImmediately, 19)
    Thread
        Wait(74)
        Loop(8)
            Call(SetActorDispOffset, ACTOR_PARTNER, 1, 0, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_PARTNER, -1, 0, 0)
            Wait(1)
        EndLoop
        Loop(7)
            Call(SetActorDispOffset, ACTOR_PARTNER, 2, 0, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_PARTNER, -2, 0, 0)
            Wait(1)
        EndLoop
        Loop(8)
            Call(SetActorDispOffset, ACTOR_PARTNER, 3, 0, 0)
            Wait(1)
            Call(SetActorDispOffset, ACTOR_PARTNER, -3, 0, 0)
            Wait(1)
        EndLoop
        Call(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    EndThread
    Call(N(AverageSpookChance))
    Call(action_command_spook_start, 0, 87 * DT, 3, LVar0)
    Call(GetActionQuality, LVar1)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Conceal)
    Set(LVar1, 0)
    Set(LVar2, 0)
    Loop(90 * DT)
        Switch(LVar1)
            CaseGt(80)
                IfEq(LVar2, 7)
                    Call(AddBattleCamZoom, -20)
                    Call(MoveBattleCamOver, 20)
                    Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, TRUE)
                    Set(LVar2, 8)
                EndIf
            CaseGt(70)
                IfEq(LVar2, 6)
                    Call(AddBattleCamZoom, -20)
                    Call(MoveBattleCamOver, 20)
                    Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, TRUE)
                    Set(LVar2, 7)
                EndIf
            CaseGt(60)
                IfEq(LVar2, 5)
                    Call(AddBattleCamZoom, -20)
                    Call(MoveBattleCamOver, 20)
                    Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, TRUE)
                    Set(LVar2, 6)
                EndIf
            CaseGt(50)
                IfEq(LVar2, 4)
                    Call(AddBattleCamZoom, -20)
                    Call(MoveBattleCamOver, 20)
                    Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, TRUE)
                    Set(LVar2, 5)
                EndIf
            CaseGt(40)
                IfEq(LVar2, 3)
                    Call(AddBattleCamZoom, -20)
                    Call(MoveBattleCamOver, 20)
                    Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, TRUE)
                    Set(LVar2, 4)
                EndIf
            CaseGt(30)
                IfEq(LVar2, 2)
                    Call(AddBattleCamZoom, -20)
                    Call(MoveBattleCamOver, 20)
                    Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, TRUE)
                    Set(LVar2, 3)
                EndIf
            CaseGt(20)
                IfEq(LVar2, 1)
                    Call(AddBattleCamZoom, -20)
                    Call(MoveBattleCamOver, 20)
                    Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, TRUE)
                    Set(LVar2, 2)
                EndIf
            CaseGt(10)
                IfEq(LVar2, 0)
                    Call(AddBattleCamZoom, -20)
                    Call(MoveBattleCamOver, 20)
                    Call(func_8024ECF8, BTL_CAM_MODEY_0, BTL_CAM_MODEX_0, TRUE)
                    Set(LVar2, 1)
                EndIf
        EndSwitch
        Add(LVar1, 1)
        Wait(1)
    EndLoop
    Call(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_SpookLoop)
    Call(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
    Thread
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 5)
        Wait(5)
        Call(UseBattleCamPreset, BTL_CAM_PRESET_01)
        Loop(5)
            Call(SetBattleCamParam, 3, 110)
            Wait(2)
            Call(SetBattleCamParam, 3, 100)
            Wait(2)
        EndLoop
    EndThread
    Thread
        Set(LVar0, 255)
        Loop(15)
            Sub(LVar0, 10)
            Call(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOW_SPOOK)
    SetF(LVar0, Float(1.0))
    Call(GetActionQuality, LVar2)
    Switch(LVar2)
        CaseLe(20)
            SetF(LVar1, Float(0.3))
        CaseLe(40)
            SetF(LVar1, Float(0.4))
        CaseLe(60)
            SetF(LVar1, Float(0.5))
        CaseLe(80)
            SetF(LVar1, Float(0.6))
        CaseDefault
            SetF(LVar1, Float(0.7))
    EndSwitch
    Loop(5)
        AddF(LVar0, LVar1)
        Call(SetActorScale, ACTOR_PARTNER, LVar0, LVar0, LVar0)
        Wait(1)
    EndLoop
    SetF(LVarE, LVar0)
    Thread
        Loop(5)
            Loop(3)
                SubF(LVar0, Float(0.23))
                Call(SetActorScale, ACTOR_PARTNER, LVar0, LVar0, LVar0)
                Wait(1)
            EndLoop
            Loop(3)
                AddF(LVar0, Float(0.23))
                Call(SetActorScale, ACTOR_PARTNER, LVar0, LVar0, LVar0)
                Wait(1)
            EndLoop
        EndLoop
    EndThread
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar1, 32)
    PlayEffect(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, Float(1.8), 45, 0)
    PlayEffect(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, Float(1.0), 45, 0)
    Wait(15)
    Call(InitTargetIterator)
    Call(GetActionQuality, LVarF)
    Loop(0)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
        IfEq(LVar0, 6)
            Goto(10)
        EndIf
        Call(SetDamageSource, DMG_SRC_SPOOK)
        Switch(LVarF)
            CaseGt(99)
                Call(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, STATUS_FLAG_400000, LVarF, 0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
            CaseDefault
                Call(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, STATUS_FLAG_400000, LVarF, 0, BS_FLAGS1_NO_RATING | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
        EndSwitch
        Label(10)
        Wait(5)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfEq(LVar0, ITER_NO_MORE)
            BreakLoop
        EndIf
    EndLoop
    Call(GetPartnerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(99)
            Call(UseBattleCamPreset, BTL_CAM_PRESET_04)
        CaseDefault
            Call(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EndSwitch
    Wait(30)
    Thread
        Set(LVar0, 105)
        Loop(15)
            Add(LVar0, 10)
            Call(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
            Wait(1)
        EndLoop
    EndThread
    Call(GetActionQuality, LVar2)
    Switch(LVar2)
        CaseLe(20)
            SetF(LVar1, Float(0.3))
        CaseLe(40)
            SetF(LVar1, Float(0.4))
        CaseLe(60)
            SetF(LVar1, Float(0.5))
        CaseLe(80)
            SetF(LVar1, Float(0.6))
        CaseDefault
            SetF(LVar1, Float(0.7))
    EndSwitch
    SetF(LVar0, LVarE)
    Loop(5)
        SubF(LVar0, LVar1)
        Call(SetActorScale, ACTOR_PARTNER, LVar0, LVar0, LVar0)
        Wait(1)
    EndLoop
    Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    ExecWait(N(80238EE0))
    Return
    End
};

EvtScript N(fanSmack) = {
    Call(LoadActionCommand, ACTION_COMMAND_SMACK)
    Call(action_command_smack_init)
    Call(SetActionHudPrepareTime, 0)
    Call(SetupMashMeter, 5, 35, 60, 80, 99, 100)
    Set(LVarB, 90 * DT)
    Set(LVarC, 2)
    Wait(10)
    Thread
        Wait(10)
        Set(LVar0, LVarB)
        Add(LVar0, -3)
        Call(action_command_smack_start, 0, LVar0, 3, 1)
        Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    EndThread
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOO_VANISH_A)
    Call(SetPartAlpha, ACTOR_PARTNER, -1, 55)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Thread
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Run)
        Call(AddGoalPos, ACTOR_PARTNER, -25, -10, 0)
        Call(FlyToGoal, ACTOR_PARTNER, 15, 0, EASING_COS_IN_OUT)
    EndThread
    Call(UseBattleCamPreset, BTL_CAM_PRESET_13)
    Call(BattleCamTargetActor, ACTOR_SELF)
    Call(SetBattleCamZoom, 180)
    Call(MoveBattleCamOver, 30)
    Call(SetBattleCamOffsetZ, 9)
    Call(func_8024EDA4)
    Wait(15)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOO_APPEAR_A)
    Set(LVar0, 55)
    Loop(5)
        Add(LVar0, 40)
        Call(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
        Wait(1)
    EndLoop
    Call(SetPartAlpha, ACTOR_PARTNER, -1, 255)
    Call(UseBattleCamPresetImmediately, 19)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Celebrate)
    Wait(20)
    Set(LVarF, 0)
    Set(LVarE, 0)
    Set(LVarD, 0)
    Set(LFlag0, FALSE)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_CelebrateFast)
    Loop(30)
        Call(SetActorDispOffset, ACTOR_PARTNER, Float(0.5), 0, 0)
        Wait(1)
        Call(SetActorDispOffset, ACTOR_PARTNER, Float(-0.5), 0, 0)
        Wait(1)
    EndLoop
    Call(GetPartnerActionSuccess, LVarB)
    Call(func_80269600, LVarD)
    Label(0)
    Call(PartnerTestEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_ALT_SPIKY, 0, 1, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_FanSmackOnce)
        Call(CloseActionCommandInfo)
        Set(LVar0, 0)
        Loop(15)
            Add(LVar0, -45)
            Call(SetActorYaw, ACTOR_PARTNER, LVar0)
            Wait(1)
        EndLoop
        Loop(15)
            Add(LVar0, -90)
            Call(SetActorYaw, ACTOR_PARTNER, LVar0)
            Wait(1)
        EndLoop
        Call(SetActorYaw, ACTOR_PARTNER, 0)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Injured)
        Call(AddActorDecoration, ACTOR_SELF, PRT_ZERO, 0, ACTOR_DECORATION_SEEING_STARS)
        Wait(40)
        Call(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 0)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
        Wait(10)
        ExecWait(N(EVS_ReturnHome))
        Return
    EndIf
    Add(LVarE, 1)
    IfGt(LVarE, LVarD)
        Goto(2)
    EndIf
    Call(SetActorScale, ACTOR_PARTNER, Float(1.4), Float(1.4), Float(1.0))
    IfEq(LFlag0, FALSE)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_FanSmackOnce)
        Set(LFlag0, TRUE)
        Call(SetDamageSource, DMG_SRC_NEXT_FAN_SMACK_LEFT)
    Else
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_FanSmackBack)
        Set(LFlag0, FALSE)
        Call(SetDamageSource, DMG_SRC_NEXT_FAN_SMACK_RIGHT)
    EndIf
    Wait(2)
    Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.5))
        Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
        Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.2))
    EndThread
    IfEq(LVarE, 1)
        Call(N(GetBowSize))
        Call(AddBattleCamZoom, LVar0)
        Call(MoveBattleCamOver, 5)
    Else
        Call(AddBattleCamZoom, 25)
        Call(MoveBattleCamOver, 5)
    EndIf
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    PlayEffect(EFFECT_CONFETTI, 5, LVar0, LVar1, LVar2, Float(1.0), 20, 0)
    Call(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_HURT, SOUND_BOW_FAN_SMACK, 0)
    IfEq(LVarE, 1)
        IfGt(LVarB, 99)
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_ALT_SPIKY, 0, LVarC, BS_FLAGS1_NICE_HIT | BS_FLAGS1_INCLUDE_POWER_UPS)
        Else
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_ALT_SPIKY, 0, LVarC, BS_FLAGS1_INCLUDE_POWER_UPS)
        EndIf
        Goto(1)
    Else
        IfGt(LVarB, 99)
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_ALT_SPIKY, 0, LVarC, BS_FLAGS1_NICE_HIT)
        Else
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_ALT_SPIKY, 0, LVarC, 0)
        EndIf
        Goto(1)
    EndIf
    Label(1)
    IfEq(LVarE, 1)
        Set(LVar0, 0)
        Loop(8)
            Add(LVar0, 144)
            Call(SetActorYaw, ACTOR_PARTNER, LVar0)
            Wait(1)
        EndLoop
    Else
        Set(LVar0, 0)
        Loop(8)
            Sub(LVar0, 144)
            Call(SetActorYaw, ACTOR_PARTNER, LVar0)
            Wait(1)
        EndLoop
    EndIf
    Call(SetActorYaw, ACTOR_PARTNER, 0)
    Add(LVarF, 10)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    Goto(0)
    Label(2)
    Thread
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(0.5))
        Call(ShakeCam, CAM_BATTLE, 0, 2, Float(1.5))
        Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.5))
        Call(ShakeCam, CAM_BATTLE, 0, 1, Float(0.2))
    EndThread
    IfEq(LVarE, 1)
        Call(N(GetBowSize))
        Call(AddBattleCamZoom, LVar0)
        Call(MoveBattleCamOver, 5)
    Else
        Call(AddBattleCamZoom, 25)
        Call(MoveBattleCamOver, 5)
    EndIf
    Call(SetActorScale, ACTOR_PARTNER, Float(1.4), Float(1.4), Float(1.0))
    IfEq(LFlag0, FALSE)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_FanSmackOnce)
        Set(LFlag0, TRUE)
        Call(SetDamageSource, DMG_SRC_LAST_FAN_SMACK_LEFT)
    Else
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_FanSmackBack)
        Set(LFlag0, FALSE)
        Call(SetDamageSource, DMG_SRC_LAST_FAN_SMACK_RIGHT)
    EndIf
    Wait(2)
    Call(SetActorScale, ACTOR_PARTNER, Float(1.0), Float(1.0), Float(1.0))
    Call(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_HURT, SOUND_BOW_FAN_SMACK, 0)
    Call(GetPartnerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(99)
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_ALT_SPIKY, 0, LVarC, BS_FLAGS1_NICE_HIT | BS_FLAGS1_TRIGGER_EVENTS)
        CaseDefault
            Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_ALT_SPIKY, 0, LVarC, BS_FLAGS1_TRIGGER_EVENTS)
    EndSwitch
    Thread
        IfEq(LVarE, 1)
            Set(LVar0, 0)
            Loop(8)
                Add(LVar0, 144)
                Call(SetActorYaw, ACTOR_PARTNER, LVar0)
                Wait(1)
            EndLoop
        Else
            Set(LVar0, 0)
            Loop(8)
                Sub(LVar0, 144)
                Call(SetActorYaw, ACTOR_PARTNER, LVar0)
                Wait(1)
            EndLoop
        EndIf
        IfEq(LVarE, 1)
            Set(LVar0, 0)
            Loop(8)
                Add(LVar0, 72)
                Call(SetActorYaw, ACTOR_PARTNER, LVar0)
                Wait(1)
            EndLoop
        Else
            Set(LVar0, 0)
            Loop(8)
                Sub(LVar0, 72)
                Call(SetActorYaw, ACTOR_PARTNER, LVar0)
                Wait(1)
            EndLoop
        EndIf
        Call(SetActorYaw, ACTOR_PARTNER, 0)
    EndThread
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            Wait(10)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
        CaseOrEq(1)
        CaseOrEq(3)
            Wait(10)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
            ExecWait(N(returnHome2))
        EndCaseGroup
    EndSwitch
    Return
    End
};

