#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleKooper.h"
#include "battle/action_cmd/hammer.h"
#include "battle/action_cmd/fire_shell.h"
#include "battle/action_cmd/dizzy_shell.h"

#define NAMESPACE battle_partner_kooper

extern EvtScript N(EVS_Init);
extern EvtScript N(EVS_TakeTurn);
extern EvtScript N(EVS_Idle);
extern EvtScript N(EVS_HandleEvent);
extern EvtScript N(EVS_HandlePhase);
extern EvtScript N(firstStrike);
extern EvtScript N(EVS_ExecuteAction);
extern EvtScript N(EVS_Celebrate);
extern EvtScript N(runAway);
extern EvtScript N(runAwayFail);
extern EvtScript N(shellToss);
extern EvtScript N(powerShell);
extern EvtScript N(dizzyShell);
extern EvtScript N(fireShell);
extern EvtScript N(shellTossOnFirstStrike);

enum N(ActorPartIDs) {
    PRT_MAIN            = 1,
    PRT_ZERO            = 0,
};

enum N(ActorVars) {
    AVAR_Unk_0      = 0,
    AVAR_Unk_1      = 1,
};

enum N(ActorParams) {
    DMG_UNK         = 0,
};

API_CALLABLE(N(SlowDown)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    ActorState* partnerActorMovement = &partnerActor->state;

    if (isInitialCall) {
        partnerActor->state.curPos.x = partnerActor->curPos.x;
        partnerActor->state.curPos.y = partnerActor->curPos.y;
        partnerActor->state.curPos.z = partnerActor->curPos.z;
    }

    add_xz_vec3f(&partnerActorMovement->curPos, partnerActor->state.speed, partnerActor->state.angle);

    if (partnerActor->state.speed < 4.0f) {
        play_movement_dust_effects(0, partnerActor->state.curPos.x, partnerActor->state.curPos.y,
                                   partnerActor->state.curPos.z, partnerActor->state.angle);
    } else {
        play_movement_dust_effects(1, partnerActor->state.curPos.x, partnerActor->state.curPos.y,
                                   partnerActor->state.curPos.z, partnerActor->state.angle);
    }

    partnerActorMovement->speed = partnerActorMovement->speed / 1.5;

    partnerActor->curPos.x = partnerActorMovement->curPos.x;
    partnerActor->curPos.y = partnerActorMovement->curPos.y;
    partnerActor->curPos.z = partnerActorMovement->curPos.z;

    if (partnerActorMovement->speed < 1.0) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

API_CALLABLE(N(SetTargetsYaw)) {
    SelectableTarget* target;
    Actor* actor = gBattleStatus.partnerActor;
    Actor* targetActor;
    ActorPart* targetActorPart;
    f32 x;
    f32 targetX;
    s32 i;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        actor->selectedTargetIndex = 0;
    }

    if (script->functionTemp[0] == 0) {
        for (i = 0; i < actor->targetListLength; i++) {
            x = actor->curPos.x;
            target = &actor->targetData[actor->targetIndexList[i]];
            targetX = target->truePos.x;
            targetActor = get_actor(target->actorID);

            if (targetActor != NULL) {
                targetActorPart = get_actor_part(targetActor, target->partID);

                if (targetActor->transparentStatus == 0) {
                    if (!(targetActorPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY)) {
                        if (x > targetX) {
                            targetActor->yaw += 33;
                        } else {
                            targetActor->yaw = 0;
                        }

                        targetActor->yaw = clamp_angle(targetActor->yaw);
                    }
                }
            }
        }

        if (actor->state.varTable[0] != 0) {
            for (i = 0; i < actor->targetListLength; i++) {
                target = &actor->targetData[actor->targetIndexList[i]];
                targetActor = get_actor(target->actorID);
                if (targetActor) {
                    targetActor->yaw = 0.0f;
                }
            }
            return ApiStatus_DONE2;
        }
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(AverageTargetDizzyChance)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor;
    ActorPart* targetActorPart;
    s32 targetActorBlueprintBaseStatusChance;
    s32 chanceTotal = 0;
    s32 nTargets = 0;
    s32 i;

    for (i = 0; i < partnerActor->targetListLength; i++) {
        targetActor = get_actor(partnerActor->targetData[i].actorID);
        targetActorPart = get_actor_part(targetActor, partnerActor->targetData[i].partID);
        targetActorBlueprintBaseStatusChance = lookup_status_chance(targetActor->statusTable, STATUS_KEY_DIZZY);

        if (targetActor->transparentStatus == STATUS_KEY_TRANSPARENT) {
            targetActorBlueprintBaseStatusChance = 0;
        }

        if (targetActorPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
            targetActorBlueprintBaseStatusChance = 0;
        }

        if (targetActorBlueprintBaseStatusChance > 0) {
            chanceTotal += targetActorBlueprintBaseStatusChance;
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

API_CALLABLE(N(GetFireShellSpeedAndDamage)) {
    s32 mashResult = script->varTable[0];
    s32 damage;
    s32 speedRating;

    if (mashResult <= 35) {
        damage = 1;
        speedRating = 0;
    } else if (mashResult <= 60) {
        damage = 3;
        speedRating = 1;
    } else if (mashResult <= 80) {
        damage = 4;
        speedRating = 2;
    } else if (mashResult < 100) {
        damage = 5;
        speedRating = 3;
    } else {
        damage = 6;
        speedRating = 4;
    }

    script->varTable[14] = speedRating;
    script->varTable[15] = damage;

    return ApiStatus_DONE2;
}

s32 N(DefaultAnims)[] = {
    STATUS_KEY_NORMAL,    ANIM_BattleKooper_Walk,
    STATUS_KEY_STONE,     ANIM_BattleKooper_Still,
    STATUS_KEY_SLEEP,     ANIM_BattleKooper_Pray,
    STATUS_KEY_POISON,    ANIM_BattleKooper_Still,
    STATUS_KEY_STOP,      ANIM_BattleKooper_Still,
    STATUS_KEY_DAZE,      ANIM_BattleKooper_Injured,
    STATUS_KEY_INACTIVE,  ANIM_BattleKooper_Still,
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
        .targetOffset = { 8, 27 },
        .opacity = 255,
        .idleAnimations = N(DefaultAnims),
        .defenseTable = N(DefenseTable),
        .eventFlags = ACTOR_EVENT_FLAGS_NONE,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_KOOPER,
    .level = ACTOR_LEVEL_KOOPER,
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
    .size = { 32, 38 },
    .healthBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 30 },
    .statusTextOffset = { 10, 30 },
};

EvtScript N(EVS_Init) = {
    Call(BindTakeTurn, ACTOR_PARTNER, Ref(N(EVS_TakeTurn)))
    Call(BindIdle, ACTOR_PARTNER, Ref(N(EVS_Idle)))
    Call(BindHandleEvent, ACTOR_PARTNER, Ref(N(EVS_HandleEvent)))
    Call(BindHandlePhase, ACTOR_PARTNER, Ref(N(EVS_HandlePhase)))
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
            SetConst(LVar1, ANIM_BattleKooper_Hurt)
            SetConst(LVar2, ANIM_BattleKooper_Hurt)
            ExecWait(EVS_Partner_Hit)
            SetConst(LVar1, ANIM_BattleKooper_Hurt)
            ExecWait(EVS_Partner_Drop)
        EndCaseGroup
        CaseOrEq(EVENT_ZERO_DAMAGE)
        CaseOrEq(EVENT_IMMUNE)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleKooper_Hurt)
            ExecWait(EVS_Partner_NoDamageHit)
        EndCaseGroup
        CaseEq(EVENT_SPIKE_CONTACT)
            SetConst(LVar1, ANIM_BattleKooper_Hurt)
            Set(LVar2, 16)
            ExecWait(EVS_Partner_SpikeContact)
            SetConst(LVar1, ANIM_BattleKooper_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_BURN_CONTACT)
            SetConst(LVar1, ANIM_BattleKooper_BurnHurt)
            Set(LVar2, 16)
            SetConst(LVar3, ANIM_BattleKooper_BurnStill)
            ExecWait(EVS_Partner_BurnContact)
            SetConst(LVar1, ANIM_BattleKooper_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_BURN_HIT)
            SetConst(LVar1, ANIM_BattleKooper_BurnHurt)
            SetConst(LVar2, ANIM_BattleKooper_BurnStill)
            ExecWait(EVS_Partner_BurnHit)
            SetConst(LVar1, ANIM_BattleKooper_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_SHOCK_HIT)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleKooper_Hurt)
            Set(LVar2, 16)
            ExecWait(EVS_Partner_ShockHit)
        CaseEq(EVENT_33)
            SetConst(LVar1, ANIM_BattleKooper_Hurt)
            ExecWait(EVS_Partner_Drop)
        CaseEq(EVENT_RECOVER_FROM_KO)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleKooper_Idle)
            SetConst(LVar2, ANIM_BattleKooper_Run)
            Set(LVar3, 0)
            ExecWait(EVS_Partner_Recover)
        CaseOrEq(EVENT_18)
        CaseOrEq(EVENT_BLOCK)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            SetConst(LVar0, PRT_MAIN)
            SetConst(LVar1, ANIM_BattleKooper_LowerShell)
            ExecWait(EVS_Partner_NoDamageHit)
            Wait(10)
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
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
        CaseEq(PHASE_FIRST_STRIKE)
            ExecWait(N(firstStrike))
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
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_BattleKooper_Celebrate)
    SetConst(LVar2, ANIM_BattleKooper_Walk)
    SetConst(LVar3, ANIM_BattleKooper_Idle)
    ExecWait(EVS_Partner_Celebrate)
    Return
    End
};

EvtScript N(runAway) = {
    SetConst(LVar0, PRT_MAIN)
    SetConst(LVar1, ANIM_BattleKooper_Run)
    ExecWait(EVS_Partner_RunAway)
    Return
    End
};

EvtScript N(runAwayFail) = {
    Call(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(6.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    Call(SetActorYaw, ACTOR_PARTNER, 0)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    Call(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    Return
    End
};

EvtScript N(EVS_HandlePhase) = {
    Return
    End
};

EvtScript N(EVS_ExecuteAction) = {
    Call(ShowActionHud, TRUE)
    Call(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar0)
        CaseEq(BTL_MENU_TYPE_STAR_POWERS)
            Call(LoadStarPowerScript)
            ExecWait(LVar0)
            Return
    EndSwitch
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_SHELL_TOSS1)
            Call(SetDamageSource, DMG_SRC_SHELL_TOSS)
            Set(LVarF, 2)
            Set(LVarE, 1)
            ExecWait(N(shellToss))
        CaseEq(MOVE_SHELL_TOSS2)
            Call(SetDamageSource, DMG_SRC_SHELL_TOSS)
            Set(LVarF, 3)
            Set(LVarE, 2)
            ExecWait(N(shellToss))
        CaseEq(MOVE_SHELL_TOSS3)
            Call(SetDamageSource, DMG_SRC_SHELL_TOSS)
            Set(LVarF, 5)
            Set(LVarE, 3)
            ExecWait(N(shellToss))
        CaseEq(MOVE_POWER_SHELL)
            Call(SetDamageSource, DMG_SRC_POWER_SHELL)
            ExecWait(N(powerShell))
        CaseEq(MOVE_DIZZY_SHELL)
            Call(SetDamageSource, DMG_SRC_DIZZY_SHELL)
            ExecWait(N(dizzyShell))
        CaseEq(MOVE_FIRE_SHELL)
            Call(SetDamageSource, DMG_SRC_FIRE_SHELL)
            ExecWait(N(fireShell))
    EndSwitch
    Return
    End
};

EvtScript N(firstStrike) = {
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_SHELL_TOSS1)
            Call(SetDamageSource, DMG_SRC_SHELL_TOSS)
            ExecWait(N(shellTossOnFirstStrike))
        CaseEq(MOVE_SHELL_TOSS2)
            Call(SetDamageSource, DMG_SRC_SHELL_TOSS)
            ExecWait(N(shellTossOnFirstStrike))
        CaseEq(MOVE_SHELL_TOSS3)
            Call(SetDamageSource, DMG_SRC_SHELL_TOSS)
            ExecWait(N(shellTossOnFirstStrike))
    EndSwitch
    Return
    End
};

EvtScript N(returnHomeOnMiss) = {
    Call(ResetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK)
    Thread
        Call(UseBattleCamPreset, BTL_CAM_RETURN_HOME)
        Wait(30)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EndThread
    Call(PartnerYieldTurn)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Sub(LVar0, 60)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.4))
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
    Sub(LVar0, 30)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 8, FALSE, FALSE, TRUE)
    Sub(LVar0, 20)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 6, FALSE, FALSE, TRUE)
    Sub(LVar0, 10)
    Call(JumpToGoal, ACTOR_PARTNER, 4, FALSE, FALSE, TRUE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
    Wait(4)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(7.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    Return
    End
};

EvtScript N(EVS_ReturnHome) = {
    Call(ResetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK)
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_MISTAKE)
    Call(PartnerYieldTurn)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Sub(LVar0, 30)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.1))
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    Sub(LVar0, 20)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 8, FALSE, FALSE, TRUE)
    Sub(LVar0, 10)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 6, FALSE, FALSE, TRUE)
    Sub(LVar0, 10)
    Call(JumpToGoal, ACTOR_PARTNER, 4, FALSE, FALSE, TRUE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
    Wait(4)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(7.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    Return
    End
};

EvtScript N(getShellTossMoveTime) = {
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(GetGoalPos, ACTOR_PARTNER, LVarB, LVarC, LVarD)
    Call(GetActorPos, ACTOR_PARTNER, LVarC, LVarD, LVar0)
    IfGt(LVarB, LVarC)
        Sub(LVarB, LVarC)
    Else
        Sub(LVarC, LVarB)
        Set(LVarB, LVarC)
    EndIf
    DivF(LVarB, LVarA)
    IfLt(LVarB, 0)
        Set(LVarB, 0)
    EndIf
    Return
    End
};

EvtScript N(shellToss) = {
    Call(LoadActionCommand, ACTION_COMMAND_SMASH)
    Call(action_command_hammer_init)
    Call(InitTargetIterator)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(4.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_EnterShell)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    Wait(15)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    Loop(30)
        Wait(1)
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfNe(LVar0, FALSE)
            BreakLoop
        EndIf
    EndLoop
    Call(action_command_hammer_start, 0, 50 * DT - 3, 3)
    Call(SetActionQuality, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_KOOPER_SHELL_SPINUP)
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_CLOSE_UP)
    Set(LVar9, 0)
    Set(LVar1, 0)
    Loop(50 * DT)
        Wait(1)
        Switch(LVar9)
            CaseLt(20 * DT)
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
            CaseEq(20 * DT)
                Call(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            CaseLt(30 * DT)
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
            CaseEq(30 * DT)
                Call(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            CaseLt(40 * DT)
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
            CaseEq(40 * DT)
                Call(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            CaseLt(50 * DT)
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
            CaseEq(50 * DT)
                Call(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
        EndSwitch
        Add(LVar9, 1)
        Call(GetActionQuality, LVar0)
        IfNe(LVar0, 0)
            IfNe(LVar1, TRUE)
                Set(LVar1, 1)
            EndIf
        EndIf
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfEq(LVar0, FALSE)
            BreakLoop
        EndIf
    EndLoop
    Label(0)
    Wait(1)
    SetF(LVarA, Float(8.0))
    Switch(LVar9)
        CaseLt(20 * DT)
            SetF(LVarA, Float(10.0))
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
        CaseLt(30 * DT)
            SetF(LVarA, Float(12.0))
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
        CaseLt(40 * DT)
            SetF(LVarA, Float(14.0))
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
        CaseLt(50 * DT)
            SetF(LVarA, Float(16.0))
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
    EndSwitch
    Add(LVar9, 1)
    Call(GetActionSuccess, LVar0)
    IfEq(LVar0, 0)
        Goto(0)
    EndIf
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_PARAKARRY_AIR_RAID_1)
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(MoveBattleCamOver, 15)
    ExecWait(N(getShellTossMoveTime))
    Call(AddActorDecoration, ACTOR_SELF, PRT_ZERO, 0, ACTOR_DECORATION_GREY_SMOKE_TRAIL)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, LVarA)
    Call(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENTS_KOOPER_TEST, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Thread
            Call(N(SlowDown))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 0)
        EndThread
        Wait(4)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellStill)
        Call(SetActorRotationOffset, ACTOR_PARTNER, 8, 0, 0)
        Set(LVar0, 0)
        Loop(2)
            Add(LVar0, -30)
            Call(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Wait(5)
        Call(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 16, 4, 0, 10, 0)
        Loop(5)
            Add(LVar0, 12)
            Call(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Call(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
        Call(SetActorRotation, ACTOR_PARTNER, 0, 0, 2)
        Wait(2)
        Call(SetActorRotation, ACTOR_PARTNER, 0, 0, -2)
        Wait(2)
        Call(SetActorRotation, ACTOR_PARTNER, 0, 0, 0)
        Wait(10)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
        Wait(10)
        Call(SetGoalToHome, ACTOR_PARTNER)
        Call(SetActorSpeed, ACTOR_PARTNER, Float(7.0))
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
        Call(RunToGoal, ACTOR_PARTNER, 0)
        Return
    EndIf
    Call(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 0)
    Call(GetPartnerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(0)
            Call(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENTS_KOOPER_DAMAGE, 0, LVarF, BS_FLAGS1_NICE_HIT | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
        CaseDefault
            Call(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENTS_KOOPER_DAMAGE, 0, LVarE, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
    EndSwitch
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    Switch(LVar0)
        CaseOrEq(HIT_RESULT_HIT)
        CaseOrEq(HIT_RESULT_NO_DAMAGE)
            ExecWait(N(EVS_ReturnHome))
        EndCaseGroup
        CaseOrEq(HIT_RESULT_NICE)
        CaseOrEq(HIT_RESULT_NICE_NO_DAMAGE)
            ExecWait(N(returnHomeOnMiss))
        EndCaseGroup
    EndSwitch
    Return
    End
};

EvtScript N(powerShell) = {
    Call(LoadActionCommand, ACTION_COMMAND_SMASH)
    Call(action_command_hammer_init)
    Call(GetActorLevel, ACTOR_PARTNER, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Set(LVarE, 1)
            Set(LVarF, 2)
        CaseEq(1)
            Set(LVarE, 1)
            Set(LVarF, 3)
        CaseEq(2)
            Set(LVarE, 1)
            Set(LVarF, 4)
    EndSwitch
    Call(InitTargetIterator)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(4.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_EnterShell)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    Wait(15)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    Loop(30)
        Wait(1)
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfNe(LVar0, FALSE)
            BreakLoop
        EndIf
    EndLoop
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_CLOSE_UP)
    Call(action_command_hammer_start, 0, 47, 3)
    Call(SetActionQuality, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_KOOPER_SHELL_SPINUP)
    Set(LVar9, 0)
    Set(LVar1, 0)
    Loop(50)
        Wait(1)
        Switch(LVar9)
            CaseLt(20)
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
            CaseEq(20)
                Call(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            CaseLt(30)
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
            CaseEq(30)
                Call(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            CaseLt(40)
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
            CaseEq(40)
                Call(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            CaseLt(50)
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
            CaseEq(50)
                Call(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
        EndSwitch
        Add(LVar9, 1)
        Call(GetActionQuality, LVar0)
        IfNe(LVar0, 0)
            IfNe(LVar1, TRUE)
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
                Set(LVar1, 1)
            EndIf
        EndIf
        Call(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        IfEq(LVar0, FALSE)
            BreakLoop
        EndIf
    EndLoop
    Label(0)
    Wait(1)
    Set(LVarA, Float(8.0))
    Switch(LVar9)
        CaseLt(20)
            Set(LVarA, Float(10.0))
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
        CaseLt(30)
            Set(LVarA, Float(12.0))
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
        CaseLt(40)
            Set(LVarA, Float(14.0))
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
        CaseLt(50)
            Set(LVarA, Float(16.0))
            Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
    EndSwitch
    Add(LVar9, 1)
    Call(GetActionSuccess, LVar0)
    IfEq(LVar0, 0)
        Goto(0)
    EndIf
    Call(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 0)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_PARAKARRY_AIR_RAID_2)
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(MoveBattleCamOver, 15)
    Set(LVarB, 260)
    DivF(LVarB, LVarA)
    Thread
        Call(AddActorDecoration, ACTOR_SELF, PRT_ZERO, 1, ACTOR_DECORATION_GREY_SMOKE_TRAIL)
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar0, 260)
        Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(SetActorSpeed, ACTOR_PARTNER, LVarA)
        Call(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
        Call(RunToGoal, ACTOR_PARTNER, 0)
        Call(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 1)
        Call(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 1)
    EndThread
    Set(LFlag0, FALSE)
        Label(10)
        Wait(1)
        Call(SetGoalToTarget, ACTOR_PARTNER)
        Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
        IfGt(LVar0, LVar3)
            Goto(10)
        EndIf
        Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENTS_KOOPER_TEST, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
        IfEq(LVar0, 6)
            Goto(12)
        EndIf
        IfEq(LFlag0, FALSE)
            Call(GetPartnerActionSuccess, LVar0)
            Switch(LVar0)
                CaseGt(0)
                    Call(UseBattleCamPreset, BTL_CAM_RETURN_HOME)
                CaseDefault
                    Call(UseBattleCamPreset, BTL_CAM_PARTNER_MISTAKE)
            EndSwitch
        EndIf
        Set(LFlag0, TRUE)
        Call(GetPartnerActionSuccess, LVar0)
        Switch(LVar0)
            CaseGt(0)
                Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_KOOPER_DAMAGE, 0, LVarF, BS_FLAGS1_NICE_HIT | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
            CaseDefault
                Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_KOOPER_DAMAGE, 0, LVarE, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
        EndSwitch
        Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
        Label(12)
        Call(ChooseNextTarget, ITER_NEXT, LVar2)
        IfNe(LVar2, ITER_NO_MORE)
            Goto(10)
        EndIf
    IfEq(LFlag0, FALSE)
        Call(GetPartnerActionSuccess, LVar0)
        Switch(LVar0)
            CaseGt(0)
                Call(UseBattleCamPreset, BTL_CAM_RETURN_HOME)
            CaseDefault
                Call(UseBattleCamPreset, BTL_CAM_PARTNER_MISTAKE)
        EndSwitch
    EndIf
    Label(11)
        Call(GetActorVar, ACTOR_SELF, AVAR_Unk_0, LVar0)
        IfEq(LVar0, 0)
            Wait(1)
            Goto(11)
        EndIf
    Call(GetPartnerActionSuccess, LVar0)
    Switch(LVar0)
        CaseGt(0)
            ExecWait(N(EVS_ReturnHome))
        CaseDefault
            ExecWait(N(returnHomeOnMiss))
    EndSwitch
    Return
    End
};

EvtScript N(dizzyShell) = {
    Call(LoadActionCommand, ACTION_COMMAND_DIZZY_SHELL)
    Call(action_command_dizzy_shell_init)
    Call(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    Call(InitTargetIterator)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(4.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_EnterShell)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    Wait(15)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_CLOSE_UP)
    Call(MoveBattleCamOver, 75 * DT)
    Set(LVarD, 75 * DT)
    Set(LVarA, LVarD)
    Add(LVarA, -3)
    Call(battle_partner_kooper_AverageTargetDizzyChance)
    Call(action_command_dizzy_shell_start, 0, LVarA, 3, LVar0)
    Call(SetActionQuality, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_KOOPER_SHELL_SPINUP)
    Set(LVar9, 0)
    Set(LVarA, Float(8.0))
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_DIZZY_SHELL)
    Call(AddActorDecoration, ACTOR_SELF, PRT_ZERO, 1, ACTOR_DECORATION_WHIRLWIND)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unk_1, 1)
    Set(LVar9, 1)
    Loop(LVarD)
        Wait(1)
        Call(GetActionQuality, LVar0)
        Switch(LVar0)
            CaseLt(20 * DT)
                Set(LVarA, Float(10.0))
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
            CaseLt(40 * DT)
                Set(LVarA, Float(12.0))
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
            CaseLt(60 * DT)
                Set(LVarA, Float(14.0))
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
            CaseDefault
                Set(LVarA, Float(16.0))
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
        EndSwitch
        Switch(LVarD)
            CaseEq(10 * DT)
                Call(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            CaseEq(20 * DT)
                Call(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            CaseEq(40 * DT)
                Call(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            CaseEq(60 * DT)
                Call(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
        EndSwitch
    EndLoop
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_DIZZY_SHELL_LAUNCH)
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(MoveBattleCamOver, 15)
    Set(LVarB, 300)
    DivF(LVarB, LVarA)
    Thread
        Call(AddActorDecoration, ACTOR_SELF, PRT_ZERO, 0, ACTOR_DECORATION_GREY_SMOKE_TRAIL)
        Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar0, 350)
        Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(SetActorSpeed, ACTOR_PARTNER, LVarA)
        Call(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
        Call(RunToGoal, ACTOR_PARTNER, 0)
        Call(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 0)
        Call(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 1)
        Wait(20)
        Call(SetActorPos, ACTOR_PARTNER, -200, 0, 0)
        Call(SetGoalToHome, ACTOR_PARTNER)
        Call(AddGoalPos, ACTOR_PARTNER, 40, 0, 0)
        Call(SetActorSpeed, ACTOR_PARTNER, Float(12.0))
        Call(FlyToGoal, ACTOR_PARTNER, 0, 0, EASING_QUARTIC_OUT)
        Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
        Call(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 1)
    EndThread
    Thread
        Call(N(SetTargetsYaw))
    EndThread
    Call(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 0)
    Set(LFlag0, FALSE)
    Label(10)
        Wait(1)
        Call(SetGoalToTarget, ACTOR_PARTNER)
        Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
        IfGt(LVar0, LVar3)
            Goto(10)
        EndIf
        Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENTS_KOOPER_TEST, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(12)
        EndIf
        IfEq(LFlag0, FALSE)
            Call(GetPartnerActionSuccess, LVar0)
            Switch(LVar0)
                CaseGt(99)
                    Call(UseBattleCamPreset, BTL_CAM_RETURN_HOME)
                CaseDefault
                    Call(UseBattleCamPreset, BTL_CAM_PARTNER_MISTAKE)
            EndSwitch
        EndIf
        Set(LFlag0, TRUE)
        Call(GetActionQuality, LVarF)
        Call(GetPartnerActionSuccess, LVar0)
        Switch(LVar0)
            CaseGt(0)
                IfEq(LVar9, 1)
                    IfEq(LVarF, 100)
                        Call(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS,
                        SUPPRESS_EVENTS_KOOPER_DAMAGE, DMG_STATUS_ALWAYS(STATUS_FLAG_DIZZY, 3), 254, 0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
                    Else
                        Call(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, SUPPRESS_EVENTS_KOOPER_DAMAGE, DMG_STATUS_ALWAYS(STATUS_FLAG_DIZZY, 3), LVarF, 0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
                    EndIf
                Else
                    Call(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, SUPPRESS_EVENTS_KOOPER_DAMAGE, DMG_STATUS_ALWAYS(STATUS_FLAG_DIZZY, 3), LVarF, 0, BS_FLAGS1_NICE_HIT | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
                EndIf
            CaseDefault
                IfEq(LVar9, 1)
                    Call(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, SUPPRESS_EVENTS_KOOPER_DAMAGE, DMG_STATUS_ALWAYS(STATUS_FLAG_DIZZY, 3), 255, 0, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
                Else
                    Call(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, SUPPRESS_EVENTS_KOOPER_DAMAGE, DMG_STATUS_ALWAYS(STATUS_FLAG_DIZZY, 3), 255, 0, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
                EndIf
        EndSwitch
        Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
        Label(12)
        Call(ChooseNextTarget, ITER_NEXT, LVar2)
        IfNe(LVar2, ITER_NO_MORE)
            Goto(10)
        EndIf
    IfEq(LFlag0, FALSE)
        Call(GetPartnerActionSuccess, LVar0)
        Switch(LVar0)
            CaseGt(99)
                Call(UseBattleCamPreset, BTL_CAM_RETURN_HOME)
            CaseDefault
                Call(UseBattleCamPreset, BTL_CAM_PARTNER_MISTAKE)
        EndSwitch
    EndIf
    Label(11)
        Call(GetActorVar, ACTOR_SELF, AVAR_Unk_0, LVar0)
        IfEq(LVar0, 0)
            Wait(1)
            Goto(11)
        EndIf
    Wait(15)
    Call(PartnerYieldTurn)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
    Wait(15)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(7.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    Return
    End
};

EvtScript N(fireShell) = {
    Call(LoadActionCommand, ACTION_COMMAND_FIRE_SHELL)
    Call(action_command_fire_shell_init)
    Call(SetupMashMeter, 5, 35, 60, 80, 99, 100)
    Call(InitTargetIterator)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 30)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(4.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_EnterShell)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    Wait(15)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    Call(UseBattleCamPreset, BTL_CAM_PARTNER_CLOSE_UP)
    Call(MoveBattleCamOver, 75 * DT)
    Set(LVarD, 75 * DT)
    Set(LVarC, LVarD)
    Add(LVarC, -3)
    Call(action_command_fire_shell_start, 0, LVarC, 3)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unk_1, 0)
    Set(LVarA, Float(8.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_KOOPER_SHELL_SPINUP)
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_ROARING_FIRE)
    Call(AddActorDecoration, ACTOR_SELF, PRT_ZERO, 0, ACTOR_DECORATION_RED_FLAMES)
    Wait(1)
    Call(ModifyActorDecoration, ACTOR_PARTNER, -1, 0, 10, 10, 255, 0)
    Call(SetActorVar, ACTOR_SELF, AVAR_Unk_1, 1)
    Call(SetActorPaletteEffect, ACTOR_PARTNER, -1, ACTOR_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
    Call(SetActorPaletteSwapParams, ACTOR_PARTNER, -1, SPR_PAL_BattleKooper, SPR_PAL_BattleKooper, 1, 10, 1000, 10, 0, 0)
    Call(EnableActorPaletteEffects, ACTOR_PARTNER, 0, TRUE)
    Set(LVar6, SPR_PAL_BattleKooper)
    Set(LVar7, SPR_PAL_BattleKooper)
    Set(LVar8, 30)
    Set(LVar9, 30)
    Loop(LVarD)
        Wait(1)
        Call(GetActionQuality, LVar0)
        Switch(LVar0)
            CaseGe(80 * DT)
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
                Set(LVar9, 80 * DT)
                Set(LVar7, SPR_PAL_BattleKooper_Red4)
                IfNe(LVar6, LVar7)
                    Call(SetActorPaletteEffect, ACTOR_PARTNER, -1, ACTOR_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
                    Call(SetActorPaletteSwapParams, ACTOR_PARTNER, -1, LVar6, LVar7, 1, 10, 1000, 10, 0, 0)
                    Set(LVar6, LVar7)
                EndIf
            CaseGe(60 * DT)
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
                Set(LVar9, 60 * DT)
                Set(LVar7, SPR_PAL_BattleKooper_Red3)
                IfNe(LVar6, LVar7)
                    Call(SetActorPaletteEffect, ACTOR_PARTNER, -1, ACTOR_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
                    Call(SetActorPaletteSwapParams, ACTOR_PARTNER, -1, LVar6, LVar7, 1, 10, 1000, 10, 0, 0)
                    Set(LVar6, LVar7)
                EndIf
            CaseGe(40 * DT)
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
                Set(LVar9, 40 * DT)
                Set(LVar7, SPR_PAL_BattleKooper_Red2)
                IfNe(LVar6, LVar7)
                    Call(SetActorPaletteEffect, ACTOR_PARTNER, -1, ACTOR_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
                    Call(SetActorPaletteSwapParams, ACTOR_PARTNER, -1, LVar6, LVar7, 1, 10, 1000, 10, 0, 0)
                    Set(LVar6, LVar7)
                EndIf
            CaseGe(20 * DT)
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
                Set(LVar9, 35 * DT)
                Set(LVar7, SPR_PAL_BattleKooper_Red1)
                IfNe(LVar6, LVar7)
                    Call(SetActorPaletteEffect, ACTOR_PARTNER, -1, ACTOR_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
                    Call(SetActorPaletteSwapParams, ACTOR_PARTNER, -1, LVar6, LVar7, 1, 10, 1000, 10, 0, 0)
                    Set(LVar6, LVar7)
                EndIf
            CaseDefault
                Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
                Set(LVar9, 30 * DT)
                Set(LVar7, SPR_PAL_BattleKooper)
                IfNe(LVar6, LVar7)
                    Call(SetActorPaletteEffect, ACTOR_PARTNER, -1, ACTOR_PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
                    Call(SetActorPaletteSwapParams, ACTOR_PARTNER, -1, LVar6, LVar7, 1, 10, 1000, 10, 0, 0)
                    Set(LVar6, LVar7)
                EndIf
        EndSwitch
        IfLt(LVar8, LVar9)
            Add(LVar8, 1)
        EndIf
        IfGt(LVar8, LVar9)
            Sub(LVar8, 1)
        EndIf
        Call(ModifyActorDecoration, ACTOR_PARTNER, -1, 0, LVar8, LVar8, 255, 0)
        Switch(LVarD)
            CaseEq(10 * DT)
                Call(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar3, LVar4, LVar5, 32, 4, 0, 10, 0)
            CaseEq(20 * DT)
                Call(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar3, LVar4, LVar5, 32, 4, 0, 10, 0)
            CaseEq(40 * DT)
                Call(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar3, LVar4, LVar5, 32, 4, 0, 10, 0)
            CaseEq(60 * DT)
                Call(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
                PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar3, LVar4, LVar5, 32, 4, 0, 10, 0)
        EndSwitch
    EndLoop
    Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_FIRE_SHELL_LAUNCH)
    Call(N(GetFireShellSpeedAndDamage))
    Switch(LVarE)
        CaseOrEq(0)
        CaseOrEq(1)
            Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
            Call(MoveBattleCamOver, 50)
            SetF(LVarA, Float(10.0))
        EndCaseGroup
        CaseOrEq(2)
        CaseOrEq(3)
            Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
            Call(MoveBattleCamOver, 30)
            SetF(LVarA, Float(10.0))
        EndCaseGroup
        CaseEq(4)
            Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
            Call(MoveBattleCamOver, 15)
            SetF(LVarA, Float(16.0))
    EndSwitch
    Set(LVarB, 350)
    DivF(LVarB, LVarA)
    Thread
        Call(AddActorDecoration, ACTOR_PARTNER, -1, 1, ACTOR_DECORATION_FIRE_SMOKE_TRAIL)
        Wait(1)
        Switch(LVarE)
            CaseOrEq(0)
            CaseOrEq(1)
                Call(ModifyActorDecoration, ACTOR_PARTNER, -1, 1, 50, 0, 0, 0)
            EndCaseGroup
            CaseOrEq(2)
            CaseOrEq(3)
                Call(ModifyActorDecoration, ACTOR_PARTNER, -1, 1, 100, 0, 0, 0)
            EndCaseGroup
            CaseEq(4)
                Call(ModifyActorDecoration, ACTOR_PARTNER, -1, 1, 300, 0, 0, 0)
        EndSwitch
        Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar0, 350)
        Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(SetActorSpeed, ACTOR_PARTNER, LVarA)
        Call(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
        Call(RunToGoal, ACTOR_PARTNER, 0)
        Call(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 1)
        Wait(20)
        Call(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 0)
        Call(EnableActorPaletteEffects, ACTOR_PARTNER, 0, FALSE)
        Call(SetActorPos, ACTOR_PARTNER, -200, 0, 0)
        Call(SetGoalToHome, ACTOR_PARTNER)
        Call(AddGoalPos, ACTOR_PARTNER, 40, 0, 0)
        Call(SetActorSpeed, ACTOR_PARTNER, Float(12.0))
        Call(FlyToGoal, ACTOR_PARTNER, 0, 0, EASING_QUARTIC_OUT)
        Call(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
        Call(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 1)
    EndThread
    Call(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 0)
    Set(LFlag0, FALSE)
    Label(10)
        Wait(1)
        Call(SetGoalToTarget, ACTOR_PARTNER)
        Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Call(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
        IfGt(LVar0, LVar3)
            Goto(10)
        EndIf
        Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENTS_KOOPER_TEST, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
        IfEq(LVar0, 6)
            Goto(12)
        EndIf
        IfEq(LFlag0, FALSE)
            Call(GetPartnerActionSuccess, LVar0)
            Switch(LVar0)
                CaseGt(99)
                    Call(UseBattleCamPreset, BTL_CAM_RETURN_HOME)
                CaseDefault
                    Call(UseBattleCamPreset, BTL_CAM_PARTNER_MISTAKE)
            EndSwitch
        EndIf
        Set(LFlag0, TRUE)
        Call(GetActionQuality, LVar0)
        Call(GetPartnerActionSuccess, LVar0)
        Switch(LVar0)
            CaseGt(99)
                Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_FIRE | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_KOOPER_DAMAGE, 0, LVarF, BS_FLAGS1_NICE_HIT | BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
            CaseDefault
                Call(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_FIRE | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENTS_KOOPER_DAMAGE, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
        EndSwitch
        Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
        Label(12)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(10)
        EndIf
    IfEq(LFlag0, FALSE)
        Call(GetPartnerActionSuccess, LVar0)
        Switch(LVar0)
            CaseGt(99)
                Call(UseBattleCamPreset, BTL_CAM_RETURN_HOME)
            CaseDefault
                Call(UseBattleCamPreset, BTL_CAM_PARTNER_MISTAKE)
        EndSwitch
    EndIf
    Label(11)
        Call(GetActorVar, ACTOR_SELF, AVAR_Unk_0, LVar0)
        IfEq(LVar0, 0)
            Wait(1)
            Goto(11)
        EndIf
    Wait(15)
    Call(PartnerYieldTurn)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
    Wait(15)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(7.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    Return
    End
};

EvtScript N(shellTossOnFirstStrike) = {
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar0, 60)
    Call(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(InitTargetIterator)
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(MoveBattleCamOver, 15)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    Call(SetGoalToTarget, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(16.0))
    Call(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENTS_KOOPER_TEST, 0, 2, BS_FLAGS1_INCLUDE_POWER_UPS)
    IfEq(LVar0, HIT_RESULT_MISS)
        Thread
            Call(N(SlowDown))
            Call(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 0)
        EndThread
        Wait(4)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellStill)
        Call(SetActorRotationOffset, ACTOR_PARTNER, 8, 0, 0)
        Set(LVar0, 0)
        Loop(2)
            Add(LVar0, -30)
            Call(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Wait(5)
        Call(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
        PlayEffect(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 16, 4, 0, 10, 0)
        Loop(5)
            Add(LVar0, 12)
            Call(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            Wait(1)
        EndLoop
        Call(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
        Call(SetActorRotation, ACTOR_PARTNER, 0, 0, 2)
        Wait(2)
        Call(SetActorRotation, ACTOR_PARTNER, 0, 0, -2)
        Wait(2)
        Call(SetActorRotation, ACTOR_PARTNER, 0, 0, 0)
        Wait(10)
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
        Wait(10)
        Call(SetGoalToHome, ACTOR_PARTNER)
        Call(SetActorSpeed, ACTOR_PARTNER, Float(7.0))
        Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
        Call(RunToGoal, ACTOR_PARTNER, 0)
        Return
    EndIf
    Set(LVarF, 1)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_SHELL_TOSS1)
            Set(LVarF, 1)
        CaseEq(MOVE_SHELL_TOSS2)
            Set(LVarF, 2)
        CaseEq(MOVE_SHELL_TOSS3)
            Set(LVarF, 3)
    EndSwitch
    Call(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENTS_KOOPER_DAMAGE, 0, LVarF, BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Switch(LVar2)
        CaseEq(MOVE_SHELL_TOSS1)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
        CaseEq(MOVE_SHELL_TOSS2)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
        CaseEq(MOVE_SHELL_TOSS3)
            Call(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EndSwitch
    Call(UseBattleCamPreset, BTL_CAM_VIEW_ENEMIES)
    Call(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Sub(LVar0, 40)
    Set(LVar1, 0)
    Call(SetActorJumpGravity, ACTOR_PARTNER, Float(1.1))
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    Sub(LVar0, 30)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 8, FALSE, FALSE, TRUE)
    Sub(LVar0, 20)
    Call(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(JumpToGoal, ACTOR_PARTNER, 6, FALSE, FALSE, TRUE)
    Sub(LVar0, 10)
    Call(JumpToGoal, ACTOR_PARTNER, 4, FALSE, FALSE, TRUE)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
    Wait(15)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    Call(SetGoalToHome, ACTOR_PARTNER)
    Call(SetActorSpeed, ACTOR_PARTNER, Float(7.0))
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    Call(RunToGoal, ACTOR_PARTNER, 0)
    Call(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    Call(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    Call(UseIdleAnimation, ACTOR_SELF, TRUE)
    Return
    End
};
