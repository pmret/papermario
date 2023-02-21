#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "battle/action_cmd/smack.h"
#include "battle/action_cmd/spook.h"
#include "sprite/npc/BattleBow.h"

#define NAMESPACE battle_partner_bow

extern EvtScript N(handleEvent);
extern EvtScript N(idle);
extern EvtScript N(nextTurn);
extern EvtScript N(takeTurn);
extern EvtScript N(init);
extern EvtScript N(executeAction);
extern EvtScript N(celebrate);
extern EvtScript N(runAway);
extern EvtScript N(runAwayFail);
extern EvtScript N(smack);
extern EvtScript N(outtaSight);
extern EvtScript N(spook);
extern EvtScript N(fanSmack);
extern EvtScript N(hidePlayer);

extern s32 bMarioHideAnims[];

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
    if (!(gBattleStatus.flags2 & BS_FLAGS2_2)) {
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
    s32 isImmobile = playerActor->debuff == STATUS_FEAR
                     || playerActor->debuff == STATUS_DIZZY
                     || playerActor->debuff == STATUS_PARALYZE
                     || playerActor->debuff == STATUS_SLEEP
                     || playerActor->debuff == STATUS_FROZEN
                     || playerActor->debuff == STATUS_STOP;

    if (playerActor->stoneStatus == STATUS_STONE) {
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

        if (targetActor->transparentStatus == STATUS_TRANSPARENT) {
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

s32 N(idleAnimations)[] = {
    STATUS_NORMAL, ANIM_BattleBow_Walk,
    STATUS_STONE, ANIM_BattleBow_Still,
    STATUS_SLEEP, ANIM_BattleBow_Pray,
    STATUS_POISON, ANIM_BattleBow_Still,
    STATUS_STOP, ANIM_BattleBow_Still,
    STATUS_DAZE, ANIM_BattleBow_Injured,
    STATUS_TURN_DONE, ANIM_BattleBow_Still,
    STATUS_END,
};

s32 N(defenseTable)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable)[] = {
    STATUS_NORMAL, 100,
    STATUS_DEFAULT, 100,
    STATUS_SLEEP, 100,
    STATUS_POISON, 100,
    STATUS_FROZEN, 100,
    STATUS_DIZZY, 100,
    STATUS_FEAR, 100,
    STATUS_STATIC, 100,
    STATUS_PARALYZE, 100,
    STATUS_SHRINK, 100,
    STATUS_STOP, 100,
    STATUS_DEFAULT_TURN_MOD, 0,
    STATUS_SLEEP_TURN_MOD, 0,
    STATUS_POISON_TURN_MOD, 0,
    STATUS_FROZEN_TURN_MOD, 0,
    STATUS_DIZZY_TURN_MOD, 0,
    STATUS_FEAR_TURN_MOD, 0,
    STATUS_STATIC_TURN_MOD, 0,
    STATUS_PARALYZE_TURN_MOD, 0,
    STATUS_SHRINK_TURN_MOD, 0,
    STATUS_STOP_TURN_MOD, 0,
    STATUS_END,
};

ActorPartBlueprint N(parts)[] = {
    {
        .flags = 0,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 9, 19 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations),
        .defenseTable = N(defenseTable),
        .eventFlags = 0,
        .elementImmunityFlags = 0,
        .projectileTargetOffset = { 0, 0 },
    },
};

ActorBlueprint NAMESPACE = {
    .flags = ACTOR_FLAG_FLYING,
    .type = ACTOR_TYPE_BOW,
    .level = 0,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(parts)),
    .partsData = N(parts),
    .initScript = &N(init),
    .statusTable = N(statusTable),
    .escapeChance = 0,
    .airLiftChance = 0,
    .hurricaneChance = 0,
    .spookChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 36, 29 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 22 },
    .statusMessageOffset = { 10, 22 },
};

EvtScript N(init) = {
    EVT_CALL(BindTakeTurn, ACTOR_SELF, EVT_PTR(N(takeTurn)))
    EVT_CALL(BindIdle, ACTOR_SELF, EVT_PTR(N(idle)))
    EVT_CALL(BindHandleEvent, ACTOR_SELF, EVT_PTR(N(handleEvent)))
    EVT_CALL(BindNextTurn, ACTOR_SELF, EVT_PTR(N(nextTurn)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(GetLastEvent, ACTOR_PARTNER, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_SET_CONST(LVar2, ANIM_BattleBow_Hurt)
            EVT_EXEC_WAIT(D_802977BC)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_EXEC_WAIT(DoPartnerBlock)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_SET(LVar2, 14)
            EVT_EXEC_WAIT(DoPartnerSpikeContact)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_BurnHurt)
            EVT_SET(LVar2, 14)
            EVT_SET_CONST(LVar3, ANIM_BattleBow_BurnStill)
            EVT_EXEC_WAIT(DoPartnerBurnContact)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_BattleBow_BurnStill)
            EVT_EXEC_WAIT(DoPartnerBurn)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_SET(LVar2, 14)
            EVT_EXEC_WAIT(D_80295744)
        EVT_CASE_EQ(EVENT_33)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Hurt)
            EVT_EXEC_WAIT(DoPartnerHit)
        EVT_CASE_EQ(EVENT_RECOVER_FROM_KO)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Idle)
            EVT_SET_CONST(LVar2, ANIM_BattleBow_Run)
            EVT_SET(LVar3, 20)
            EVT_EXEC_WAIT(DoPartnerRecover)
        EVT_CASE_OR_EQ(EVENT_18)
        EVT_CASE_OR_EQ(EVENT_BLOCK)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleBow_Block)
            EVT_EXEC_WAIT(DoPartnerBlock)
            EVT_WAIT(10)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_EXECUTE_ACTION)
            EVT_EXEC_WAIT(N(executeAction))
        EVT_CASE_EQ(PHASE_CELEBRATE)
            EVT_EXEC_WAIT(N(celebrate))
        EVT_CASE_EQ(PHASE_RUN_AWAY_START)
            EVT_EXEC_WAIT(N(runAway))
        EVT_CASE_EQ(PHASE_RUN_AWAY_FAIL)
            EVT_EXEC_WAIT(N(runAwayFail))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(celebrate) = {
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Celebrate)
    EVT_WAIT(36)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAway) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_BattleBow_Run)
    EVT_EXEC_WAIT(DoPartnerRunAway)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAwayFail) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Run)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(nextTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_ENEMY_BEGIN)
            EVT_CALL(N(IsOuttaSightActive))
            EVT_IF_NE(LVar0, 0)
                EVT_EXEC_WAIT(N(hidePlayer))
            EVT_END_IF
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(executeAction) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(8)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(LVar0)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_SMACK1)
            EVT_EXEC_WAIT(N(smack))
        EVT_CASE_EQ(MOVE_SMACK2)
            EVT_EXEC_WAIT(N(smack))
        EVT_CASE_EQ(MOVE_SMACK3)
            EVT_EXEC_WAIT(N(smack))
        EVT_CASE_EQ(MOVE_OUTTA_SIGHT)
            EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
            EVT_EXEC_WAIT(N(outtaSight))
        EVT_CASE_EQ(MOVE_SPOOK)
            EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
            EVT_EXEC_WAIT(N(spook))
        EVT_CASE_EQ(MOVE_FAN_SMACK)
            EVT_EXEC_WAIT(N(fanSmack))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome2) = {
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOO_VANISH)
    EVT_THREAD
        EVT_SET(LVar0, 200)
        EVT_LOOP(20)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Run)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOO_APPEAR)
    EVT_SET(LVar0, 55)
    EVT_LOOP(20)
        EVT_ADD(LVar0, 10)
        EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, 255)
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHome) = {
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOO_VANISH)
    EVT_THREAD
        EVT_SET(LVar0, 200)
        EVT_LOOP(20)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Run)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 30, 0, EASING_COS_IN_OUT)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOO_APPEAR)
    EVT_SET(LVar0, 55)
    EVT_LOOP(20)
        EVT_ADD(LVar0, 10)
        EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, 255)
    EVT_RETURN
    EVT_END
};

EvtScript N(80238EE0) = {
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Run)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 15, 0, EASING_COS_IN_OUT)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(smack) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMACK)
    EVT_CALL(action_command_smack_init)
    EVT_CALL(SetActionHudPrepareTime, 0)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_SMACK1)
            EVT_CALL(SetupMashMeter, 4, 40, 70, 99, 100, 0)
            EVT_SET(LVarB, 60)
            EVT_SET(LVarC, 1)
        EVT_CASE_EQ(MOVE_SMACK2)
            EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
            EVT_SET(LVarB, 60)
            EVT_SET(LVarC, 1)
        EVT_CASE_EQ(MOVE_SMACK3)
            EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
            EVT_SET(LVarB, 60)
            EVT_SET(LVarC, 1)
    EVT_END_SWITCH
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_SET(LVar0, LVarB)
        EVT_ADD(LVar0, -3)
        EVT_CALL(action_command_smack_start, 0, LVar0, 3, 0)
        EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOO_VANISH)
    EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, 55)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Run)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, -15, -10, 0)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 15, 0, EASING_COS_IN_OUT)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    EVT_END_THREAD
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetBattleCamOffsetZ, 9)
    EVT_CALL(func_8024EDA4)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOO_APPEAR)
    EVT_SET(LVar0, 55)
    EVT_LOOP(5)
        EVT_ADD(LVar0, 40)
        EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, 255)
    EVT_CALL(UseBattleCamPresetImmediately, 19)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_PreSlap)
    EVT_WAIT(20)
    EVT_SET(LVarF, 0)
    EVT_SET(LVarE, 0)
    EVT_SET(LVarD, 0)
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_LOOP(15)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(0.5), 0, 0)
        EVT_WAIT(1)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(-0.5), 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActionCommandResult, LVarB)
    EVT_CALL(func_80269600, LVarD)
    EVT_LABEL(0)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_SlapOnce)
        EVT_CALL(CloseActionCommandInfo)
        EVT_SET(LVar0, 0)
        EVT_LOOP(20)
            EVT_ADD(LVar0, -45)
            EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Injured)
        EVT_CALL(AddActorDecoration, ACTOR_SELF, 0, 0, ACTOR_DECORATION_SEEING_STARS)
        EVT_WAIT(30)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
        EVT_WAIT(10)
        EVT_EXEC_WAIT(N(returnHome))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LVarE, 1)
    EVT_IF_GT(LVarE, LVarD)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.4), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_SlapOnce)
        EVT_SET(LocalFlag(0), 1)
        EVT_CALL(func_80269EAC, 10)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_SlapBack)
        EVT_SET(LocalFlag(0), 0)
        EVT_CALL(func_80269EAC, 11)
    EVT_END_IF
    EVT_WAIT(2)
    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_IF_EQ(LVarE, 1)
        EVT_CALL(N(GetBowSize))
        EVT_CALL(AddBattleCamZoom, LVar0)
        EVT_CALL(MoveBattleCamOver, 5)
    EVT_ELSE
        EVT_CALL(AddBattleCamZoom, 25)
        EVT_CALL(MoveBattleCamOver, 5)
    EVT_END_IF
    EVT_CALL(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_HURT, SOUND_2019, 0)
    EVT_IF_EQ(LVarE, 1)
        EVT_IF_GT(LVarB, 99)
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarC, BS_FLAGS1_40 | BS_FLAGS1_10)
        EVT_ELSE
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarC, BS_FLAGS1_10)
        EVT_END_IF
        EVT_GOTO(1)
    EVT_ELSE
        EVT_IF_GT(LVarB, 99)
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarC, BS_FLAGS1_40)
        EVT_ELSE
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarC, 0)
        EVT_END_IF
        EVT_GOTO(1)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_WAIT(8)
    EVT_ADD(LVarF, 10)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    EVT_GOTO(0)
    EVT_LABEL(2)
    EVT_IF_EQ(LVarE, 1)
        EVT_CALL(N(GetBowSize))
        EVT_CALL(AddBattleCamZoom, LVar0)
        EVT_CALL(MoveBattleCamOver, 5)
    EVT_ELSE
        EVT_CALL(AddBattleCamZoom, 25)
        EVT_CALL(MoveBattleCamOver, 5)
    EVT_END_IF
    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.4), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_SlapOnce)
        EVT_SET(LocalFlag(0), 1)
        EVT_CALL(func_80269EAC, 12)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_SlapBack)
        EVT_SET(LocalFlag(0), 0)
        EVT_CALL(func_80269EAC, 13)
    EVT_END_IF
    EVT_WAIT(2)
    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_HURT, SOUND_2019, 0)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(99)
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarC, BS_FLAGS1_40 | BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT, 0, LVarC, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_WAIT(8)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
            EVT_EXEC_WAIT(N(returnHome2))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(outtaSight) = {
    EVT_CALL(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_20000000, TRUE)
    EVT_CALL(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_4000000, FALSE)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_19)
    EVT_CALL(SetBattleCamTarget, -129, 28, 0)
    EVT_CALL(SetBattleCamOffsetZ, 15)
    EVT_CALL(SetBattleCamZoom, 260)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 5)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 10, 0, EASING_COS_IN_OUT)
    EVT_END_THREAD
    EVT_SET(LVar0, 0)
    EVT_LOOP(10)
        EVT_ADD(LVar0, 18)
        EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(10)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -30)
    EVT_ADD(LVar1, 30)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 20, 30, EASING_COS_IN_OUT)
    EVT_THREAD
        EVT_SET(LVar0, 180)
        EVT_LOOP(10)
            EVT_SUB(LVar0, 18)
            EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 255)
        EVT_LOOP(30)
            EVT_SUB(LVar0, 5)
            EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(N(ModifyBowPos), -10, 20)
    EVT_ADD(LVar2, 5)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 20, 0, EASING_LINEAR)
    EVT_CALL(N(IsPartnerImmobile))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Crouch)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOW_VANISH)
    EVT_SET(LVar0, 255)
    EVT_LOOP(15)
        EVT_SUB(LVar0, 10)
        EVT_CALL(SetPartAlpha, ACTOR_PLAYER, 1, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(N(ApplyOuttaSight))
    EVT_CALL(SetActorFlagBits, ACTOR_PLAYER, ACTOR_FLAG_20000000, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(hidePlayer) = {
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_WAIT(20)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOW_APPEAR)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_SET(LVar0, 105)
        EVT_LOOP(30)
            EVT_ADD(LVar0, 5)
            EVT_CALL(SetPartAlpha, ACTOR_PLAYER, 1, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 105)
        EVT_LOOP(30)
            EVT_ADD(LVar0, 5)
            EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_CALL(MoveBattleCamOver, 40)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 20, 0, EASING_COS_IN_OUT)
    EVT_CALL(N(RestorePlayerIdleAnimations))
    EVT_WAIT(20)
    EVT_RETURN
    EVT_END
};

EvtScript N(spook) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SPOOK)
    EVT_CALL(action_command_spook_init)
    EVT_CALL(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    EVT_CALL(SetActionHudPrepareTime, 20)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_15)
        EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
        EVT_CALL(SetBattleCamOffsetZ, 4)
        EVT_CALL(AddBattleCamZoom, -150)
        EVT_CALL(MoveBattleCamOver, 20)
        EVT_CALL(func_8024EDA4)
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 40)
    EVT_ADD(LVar1, 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(FlyToGoal, ACTOR_PARTNER, 20, 0, EASING_COS_IN_OUT)
    EVT_WAIT(15)
    EVT_CALL(UseBattleCamPresetImmediately, 19)
    EVT_THREAD
        EVT_WAIT(74)
        EVT_LOOP(8)
            EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 1, 0, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, -1, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(7)
            EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 2, 0, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, -2, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(8)
            EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 3, 0, 0)
            EVT_WAIT(1)
            EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, -3, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_END_THREAD
    EVT_CALL(N(AverageSpookChance))
    EVT_CALL(action_command_spook_start, 0, 87, 3, LVar0)
    EVT_CALL(GetActionResult, LVar1)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Conceal)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_LOOP(90)
        EVT_SWITCH(LVar1)
            EVT_CASE_GT(80)
                EVT_IF_EQ(LVar2, 7)
                    EVT_CALL(AddBattleCamZoom, -20)
                    EVT_CALL(MoveBattleCamOver, 20)
                    EVT_CALL(func_8024ECF8, 0, 0, 1)
                    EVT_SET(LVar2, 8)
                EVT_END_IF
            EVT_CASE_GT(70)
                EVT_IF_EQ(LVar2, 6)
                    EVT_CALL(AddBattleCamZoom, -20)
                    EVT_CALL(MoveBattleCamOver, 20)
                    EVT_CALL(func_8024ECF8, 0, 0, 1)
                    EVT_SET(LVar2, 7)
                EVT_END_IF
            EVT_CASE_GT(60)
                EVT_IF_EQ(LVar2, 5)
                    EVT_CALL(AddBattleCamZoom, -20)
                    EVT_CALL(MoveBattleCamOver, 20)
                    EVT_CALL(func_8024ECF8, 0, 0, 1)
                    EVT_SET(LVar2, 6)
                EVT_END_IF
            EVT_CASE_GT(50)
                EVT_IF_EQ(LVar2, 4)
                    EVT_CALL(AddBattleCamZoom, -20)
                    EVT_CALL(MoveBattleCamOver, 20)
                    EVT_CALL(func_8024ECF8, 0, 0, 1)
                    EVT_SET(LVar2, 5)
                EVT_END_IF
            EVT_CASE_GT(40)
                EVT_IF_EQ(LVar2, 3)
                    EVT_CALL(AddBattleCamZoom, -20)
                    EVT_CALL(MoveBattleCamOver, 20)
                    EVT_CALL(func_8024ECF8, 0, 0, 1)
                    EVT_SET(LVar2, 4)
                EVT_END_IF
            EVT_CASE_GT(30)
                EVT_IF_EQ(LVar2, 2)
                    EVT_CALL(AddBattleCamZoom, -20)
                    EVT_CALL(MoveBattleCamOver, 20)
                    EVT_CALL(func_8024ECF8, 0, 0, 1)
                    EVT_SET(LVar2, 3)
                EVT_END_IF
            EVT_CASE_GT(20)
                EVT_IF_EQ(LVar2, 1)
                    EVT_CALL(AddBattleCamZoom, -20)
                    EVT_CALL(MoveBattleCamOver, 20)
                    EVT_CALL(func_8024ECF8, 0, 0, 1)
                    EVT_SET(LVar2, 2)
                EVT_END_IF
            EVT_CASE_GT(10)
                EVT_IF_EQ(LVar2, 0)
                    EVT_CALL(AddBattleCamZoom, -20)
                    EVT_CALL(MoveBattleCamOver, 20)
                    EVT_CALL(func_8024ECF8, 0, 0, 1)
                    EVT_SET(LVar2, 1)
                EVT_END_IF
        EVT_END_SWITCH
        EVT_ADD(LVar1, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, 0, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_SpookLoop)
    EVT_CALL(SetActorRotationOffset, ACTOR_SELF, 0, 12, 0)
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 5)
        EVT_WAIT(5)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_B)
        EVT_LOOP(5)
            EVT_CALL(SetBattleCamParam, 3, 110)
            EVT_WAIT(2)
            EVT_CALL(SetBattleCamParam, 3, 100)
            EVT_WAIT(2)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LVar0, 255)
        EVT_LOOP(15)
            EVT_SUB(LVar0, 10)
            EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOW_SPOOK)
    EVT_SETF(LVar0, EVT_FLOAT(1.0))
    EVT_CALL(GetActionResult, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_LE(20)
            EVT_SETF(LVar1, EVT_FLOAT(0.3))
        EVT_CASE_LE(40)
            EVT_SETF(LVar1, EVT_FLOAT(0.4))
        EVT_CASE_LE(60)
            EVT_SETF(LVar1, EVT_FLOAT(0.5))
        EVT_CASE_LE(80)
            EVT_SETF(LVar1, EVT_FLOAT(0.6))
        EVT_CASE_DEFAULT
            EVT_SETF(LVar1, EVT_FLOAT(0.7))
    EVT_END_SWITCH
    EVT_LOOP(5)
        EVT_ADDF(LVar0, LVar1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, LVar0, LVar0, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SETF(LVarE, LVar0)
    EVT_THREAD
        EVT_LOOP(5)
            EVT_LOOP(3)
                EVT_SUBF(LVar0, EVT_FLOAT(0.23))
                EVT_CALL(SetActorScale, ACTOR_PARTNER, LVar0, LVar0, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_LOOP(3)
                EVT_ADDF(LVar0, EVT_FLOAT(0.23))
                EVT_CALL(SetActorScale, ACTOR_PARTNER, LVar0, LVar0, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 32)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, EVT_FLOAT(1.8), 45, 0)
    EVT_PLAY_EFFECT(EFFECT_ENERGY_IN_OUT, 6, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 45, 0)
    EVT_WAIT(15)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetActionResult, LVarF)
    EVT_LOOP(0)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 2, BS_FLAGS1_10)
        EVT_IF_EQ(LVar0, 6)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(func_80269EAC, 18)
        EVT_SWITCH(LVarF)
            EVT_CASE_GT(99)
                EVT_CALL(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, STATUS_FLAG_400000, LVarF, 0, BS_FLAGS1_40 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
            EVT_CASE_DEFAULT
                EVT_CALL(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, 0, STATUS_FLAG_400000, LVarF, 0, BS_FLAGS1_80 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
        EVT_END_SWITCH
        EVT_LABEL(10)
        EVT_WAIT(5)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_EQ(LVar0, -1)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(99)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
        EVT_CASE_DEFAULT
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_END_SWITCH
    EVT_WAIT(30)
    EVT_THREAD
        EVT_SET(LVar0, 105)
        EVT_LOOP(15)
            EVT_ADD(LVar0, 10)
            EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(GetActionResult, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_LE(20)
            EVT_SETF(LVar1, EVT_FLOAT(0.3))
        EVT_CASE_LE(40)
            EVT_SETF(LVar1, EVT_FLOAT(0.4))
        EVT_CASE_LE(60)
            EVT_SETF(LVar1, EVT_FLOAT(0.5))
        EVT_CASE_LE(80)
            EVT_SETF(LVar1, EVT_FLOAT(0.6))
        EVT_CASE_DEFAULT
            EVT_SETF(LVar1, EVT_FLOAT(0.7))
    EVT_END_SWITCH
    EVT_SETF(LVar0, LVarE)
    EVT_LOOP(5)
        EVT_SUBF(LVar0, LVar1)
        EVT_CALL(SetActorScale, ACTOR_PARTNER, LVar0, LVar0, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    EVT_EXEC_WAIT(N(80238EE0))
    EVT_RETURN
    EVT_END
};

EvtScript N(fanSmack) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMACK)
    EVT_CALL(action_command_smack_init)
    EVT_CALL(SetActionHudPrepareTime, 0)
    EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
    EVT_SET(LVarB, 90)
    EVT_SET(LVarC, 2)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_SET(LVar0, LVarB)
        EVT_ADD(LVar0, -3)
        EVT_CALL(action_command_smack_start, 0, LVar0, 3, 1)
        EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOO_VANISH)
    EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, 55)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_THREAD
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Run)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, -25, -10, 0)
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 15, 0, EASING_COS_IN_OUT)
    EVT_END_THREAD
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_13)
    EVT_CALL(BattleCamTargetActor, ACTOR_SELF)
    EVT_CALL(SetBattleCamZoom, 180)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(SetBattleCamOffsetZ, 9)
    EVT_CALL(func_8024EDA4)
    EVT_WAIT(15)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_BOO_APPEAR)
    EVT_SET(LVar0, 55)
    EVT_LOOP(5)
        EVT_ADD(LVar0, 40)
        EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, LVar0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetPartAlpha, ACTOR_PARTNER, -1, 255)
    EVT_CALL(UseBattleCamPresetImmediately, 19)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Celebrate)
    EVT_WAIT(20)
    EVT_SET(LVarF, 0)
    EVT_SET(LVarE, 0)
    EVT_SET(LVarD, 0)
    EVT_SET(LocalFlag(0), 0)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_CelebrateFast)
    EVT_LOOP(30)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(0.5), 0, 0)
        EVT_WAIT(1)
        EVT_CALL(SetActorDispOffset, ACTOR_PARTNER, EVT_FLOAT(-0.5), 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(GetActionCommandResult, LVarB)
    EVT_CALL(func_80269600, LVarD)
    EVT_LABEL(0)
    EVT_CALL(PartnerTestEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, 1, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_FanSmackOnce)
        EVT_CALL(CloseActionCommandInfo)
        EVT_SET(LVar0, 0)
        EVT_LOOP(15)
            EVT_ADD(LVar0, -45)
            EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_LOOP(15)
            EVT_ADD(LVar0, -90)
            EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Injured)
        EVT_CALL(AddActorDecoration, ACTOR_SELF, 0, 0, ACTOR_DECORATION_SEEING_STARS)
        EVT_WAIT(40)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
        EVT_WAIT(10)
        EVT_EXEC_WAIT(N(returnHome))
        EVT_RETURN
    EVT_END_IF
    EVT_ADD(LVarE, 1)
    EVT_IF_GT(LVarE, LVarD)
        EVT_GOTO(2)
    EVT_END_IF
    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.4), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_FanSmackOnce)
        EVT_SET(LocalFlag(0), 1)
        EVT_CALL(func_80269EAC, 14)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_FanSmackBack)
        EVT_SET(LocalFlag(0), 0)
        EVT_CALL(func_80269EAC, 15)
    EVT_END_IF
    EVT_WAIT(2)
    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_IF_EQ(LVarE, 1)
        EVT_CALL(N(GetBowSize))
        EVT_CALL(AddBattleCamZoom, LVar0)
        EVT_CALL(MoveBattleCamOver, 5)
    EVT_ELSE
        EVT_CALL(AddBattleCamZoom, 25)
        EVT_CALL(MoveBattleCamOver, 5)
    EVT_END_IF
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_PLAY_EFFECT(EFFECT_CONFETTI, 5, LVar0, LVar1, LVar2, EVT_FLOAT(1.0), 20, 0)
    EVT_CALL(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_HURT, SOUND_201A, 0)
    EVT_IF_EQ(LVarE, 1)
        EVT_IF_GT(LVarB, 99)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarC, BS_FLAGS1_40 | BS_FLAGS1_10)
        EVT_ELSE
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarC, BS_FLAGS1_10)
        EVT_END_IF
        EVT_GOTO(1)
    EVT_ELSE
        EVT_IF_GT(LVarB, 99)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarC, BS_FLAGS1_40)
        EVT_ELSE
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarC, 0)
        EVT_END_IF
        EVT_GOTO(1)
    EVT_END_IF
    EVT_LABEL(1)
    EVT_IF_EQ(LVarE, 1)
        EVT_SET(LVar0, 0)
        EVT_LOOP(8)
            EVT_ADD(LVar0, 144)
            EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_ELSE
        EVT_SET(LVar0, 0)
        EVT_LOOP(8)
            EVT_SUB(LVar0, 144)
            EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_ADD(LVarF, 10)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
    EVT_GOTO(0)
    EVT_LABEL(2)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 2, EVT_FLOAT(1.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_BATTLE, 0, 1, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_IF_EQ(LVarE, 1)
        EVT_CALL(N(GetBowSize))
        EVT_CALL(AddBattleCamZoom, LVar0)
        EVT_CALL(MoveBattleCamOver, 5)
    EVT_ELSE
        EVT_CALL(AddBattleCamZoom, 25)
        EVT_CALL(MoveBattleCamOver, 5)
    EVT_END_IF
    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.4), EVT_FLOAT(1.4), EVT_FLOAT(1.0))
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_FanSmackOnce)
        EVT_SET(LocalFlag(0), 1)
        EVT_CALL(func_80269EAC, 16)
    EVT_ELSE
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_FanSmackBack)
        EVT_SET(LocalFlag(0), 0)
        EVT_CALL(func_80269EAC, 17)
    EVT_END_IF
    EVT_WAIT(2)
    EVT_CALL(SetActorScale, ACTOR_PARTNER, EVT_FLOAT(1.0), EVT_FLOAT(1.0), EVT_FLOAT(1.0))
    EVT_CALL(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_HURT, SOUND_201A, 0)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(99)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarC, BS_FLAGS1_40 | BS_FLAGS1_SP_EVT_ACTIVE)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarC, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_END_SWITCH
    EVT_THREAD
        EVT_IF_EQ(LVarE, 1)
            EVT_SET(LVar0, 0)
            EVT_LOOP(8)
                EVT_ADD(LVar0, 144)
                EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_ELSE
            EVT_SET(LVar0, 0)
            EVT_LOOP(8)
                EVT_SUB(LVar0, 144)
                EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_IF
        EVT_IF_EQ(LVarE, 1)
            EVT_SET(LVar0, 0)
            EVT_LOOP(8)
                EVT_ADD(LVar0, 72)
                EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_ELSE
            EVT_SET(LVar0, 0)
            EVT_LOOP(8)
                EVT_SUB(LVar0, 72)
                EVT_CALL(SetActorYaw, ACTOR_PARTNER, LVar0)
                EVT_WAIT(1)
            EVT_END_LOOP
        EVT_END_IF
        EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_END_THREAD
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
            EVT_EXEC_WAIT(N(returnHome))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleBow_Idle)
            EVT_EXEC_WAIT(N(returnHome2))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

