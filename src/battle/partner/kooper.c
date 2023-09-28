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
extern EvtScript N(executeAction);
extern EvtScript N(celebrate);
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
            targetX = target->posA.x;
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
    EVT_CALL(BindTakeTurn, ACTOR_PARTNER, EVT_PTR(N(EVS_TakeTurn)))
    EVT_CALL(BindIdle, ACTOR_PARTNER, EVT_PTR(N(EVS_Idle)))
    EVT_CALL(BindHandleEvent, ACTOR_PARTNER, EVT_PTR(N(EVS_HandleEvent)))
    EVT_CALL(BindHandlePhase, ACTOR_PARTNER, EVT_PTR(N(EVS_HandlePhase)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Idle) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandleEvent) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(GetLastEvent, ACTOR_PARTNER, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_SET_CONST(LVar2, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(EVS_Partner_Hit)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_ZERO_DAMAGE)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(EVS_Partner_NoDamageHit)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_SET(LVar2, 16)
            EVT_EXEC_WAIT(EVS_Partner_SpikeContact)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_BurnHurt)
            EVT_SET(LVar2, 16)
            EVT_SET_CONST(LVar3, ANIM_BattleKooper_BurnStill)
            EVT_EXEC_WAIT(EVS_Partner_BurnContact)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_BattleKooper_BurnStill)
            EVT_EXEC_WAIT(EVS_Partner_BurnHit)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_SET(LVar2, 16)
            EVT_EXEC_WAIT(EVS_Partner_ShockHit)
        EVT_CASE_EQ(EVENT_33)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(EVS_Partner_Drop)
        EVT_CASE_EQ(EVENT_RECOVER_FROM_KO)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Idle)
            EVT_SET_CONST(LVar2, ANIM_BattleKooper_Run)
            EVT_SET(LVar3, 0)
            EVT_EXEC_WAIT(EVS_Partner_Recover)
        EVT_CASE_OR_EQ(EVENT_18)
        EVT_CASE_OR_EQ(EVENT_BLOCK)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NO_DAMGE)
            EVT_SET_CONST(LVar0, PRT_MAIN)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_LowerShell)
            EVT_EXEC_WAIT(EVS_Partner_NoDamageHit)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeTurn) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(firstStrike))
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
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_BattleKooper_Celebrate)
    EVT_SET_CONST(LVar2, ANIM_BattleKooper_Walk)
    EVT_SET_CONST(LVar3, ANIM_BattleKooper_Idle)
    EVT_EXEC_WAIT(EVS_Partner_Celebrate)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAway) = {
    EVT_SET_CONST(LVar0, PRT_MAIN)
    EVT_SET_CONST(LVar1, ANIM_BattleKooper_Run)
    EVT_EXEC_WAIT(EVS_Partner_RunAway)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAwayFail) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HandlePhase) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(executeAction) = {
    EVT_CALL(ShowActionHud, TRUE)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, FALSE)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(BTL_MENU_TYPE_STAR_POWERS)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(LVar0)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_SHELL_TOSS1)
            EVT_CALL(SetDamageSource, DMG_SRC_SHELL_TOSS)
            EVT_SET(LVarF, 2)
            EVT_SET(LVarE, 1)
            EVT_EXEC_WAIT(N(shellToss))
        EVT_CASE_EQ(MOVE_SHELL_TOSS2)
            EVT_CALL(SetDamageSource, DMG_SRC_SHELL_TOSS)
            EVT_SET(LVarF, 3)
            EVT_SET(LVarE, 2)
            EVT_EXEC_WAIT(N(shellToss))
        EVT_CASE_EQ(MOVE_SHELL_TOSS3)
            EVT_CALL(SetDamageSource, DMG_SRC_SHELL_TOSS)
            EVT_SET(LVarF, 5)
            EVT_SET(LVarE, 3)
            EVT_EXEC_WAIT(N(shellToss))
        EVT_CASE_EQ(MOVE_POWER_SHELL)
            EVT_CALL(SetDamageSource, DMG_SRC_POWER_SHELL)
            EVT_EXEC_WAIT(N(powerShell))
        EVT_CASE_EQ(MOVE_DIZZY_SHELL)
            EVT_CALL(SetDamageSource, DMG_SRC_DIZZY_SHELL)
            EVT_EXEC_WAIT(N(dizzyShell))
        EVT_CASE_EQ(MOVE_FIRE_SHELL)
            EVT_CALL(SetDamageSource, DMG_SRC_FIRE_SHELL)
            EVT_EXEC_WAIT(N(fireShell))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(firstStrike) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_SHELL_TOSS1)
            EVT_CALL(SetDamageSource, DMG_SRC_SHELL_TOSS)
            EVT_EXEC_WAIT(N(shellTossOnFirstStrike))
        EVT_CASE_EQ(MOVE_SHELL_TOSS2)
            EVT_CALL(SetDamageSource, DMG_SRC_SHELL_TOSS)
            EVT_EXEC_WAIT(N(shellTossOnFirstStrike))
        EVT_CASE_EQ(MOVE_SHELL_TOSS3)
            EVT_CALL(SetDamageSource, DMG_SRC_SHELL_TOSS)
            EVT_EXEC_WAIT(N(shellTossOnFirstStrike))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(returnHomeOnMiss) = {
    EVT_CALL(ResetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK)
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_04)
        EVT_WAIT(30)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
    EVT_END_THREAD
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 60)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
    EVT_SUB(LVar0, 30)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, FALSE, TRUE)
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 6, FALSE, FALSE, TRUE)
    EVT_SUB(LVar0, 10)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, FALSE, TRUE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
    EVT_WAIT(4)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(7.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReturnHome) = {
    EVT_CALL(ResetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 30)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.1))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, FALSE, TRUE)
    EVT_SUB(LVar0, 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 6, FALSE, FALSE, TRUE)
    EVT_SUB(LVar0, 10)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, FALSE, TRUE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
    EVT_WAIT(4)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(7.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(getShellTossMoveTime) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVarB, LVarC, LVarD)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVarC, LVarD, LVar0)
    EVT_IF_GT(LVarB, LVarC)
        EVT_SUB(LVarB, LVarC)
    EVT_ELSE
        EVT_SUB(LVarC, LVarB)
        EVT_SET(LVarB, LVarC)
    EVT_END_IF
    EVT_DIVF(LVarB, LVarA)
    EVT_IF_LT(LVarB, 0)
        EVT_SET(LVarB, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(shellToss) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_EnterShell)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_NE(LVar0, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(action_command_hammer_start, 0, 50 * DT - 3, 3)
    EVT_CALL(SetActionQuality, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_200C)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_59)
    EVT_SET(LVar9, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(50 * DT)
        EVT_WAIT(1)
        EVT_SWITCH(LVar9)
            EVT_CASE_LT(20 * DT)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
            EVT_CASE_EQ(20 * DT)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            EVT_CASE_LT(30 * DT)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
            EVT_CASE_EQ(30 * DT)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            EVT_CASE_LT(40 * DT)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
            EVT_CASE_EQ(40 * DT)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            EVT_CASE_LT(50 * DT)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
            EVT_CASE_EQ(50 * DT)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
        EVT_END_SWITCH
        EVT_ADD(LVar9, 1)
        EVT_CALL(GetActionQuality, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_IF_NE(LVar1, TRUE)
                EVT_SET(LVar1, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_SETF(LVarA, EVT_FLOAT(8.0))
    EVT_SWITCH(LVar9)
        EVT_CASE_LT(20 * DT)
            EVT_SETF(LVarA, EVT_FLOAT(10.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
        EVT_CASE_LT(30 * DT)
            EVT_SETF(LVarA, EVT_FLOAT(12.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
        EVT_CASE_LT(40 * DT)
            EVT_SETF(LVarA, EVT_FLOAT(14.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
        EVT_CASE_LT(50 * DT)
            EVT_SETF(LVarA, EVT_FLOAT(16.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
    EVT_END_SWITCH
    EVT_ADD(LVar9, 1)
    EVT_CALL(GetActionSuccess, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_200A)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_EXEC_WAIT(N(getShellTossMoveTime))
    EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_ZERO, 0, ACTOR_DECORATION_GREY_SMOKE_TRAIL)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, LVarA)
    EVT_CALL(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 2, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_THREAD
            EVT_CALL(N(SlowDown))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 0)
        EVT_END_THREAD
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellStill)
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 8, 0, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(2)
            EVT_ADD(LVar0, -30)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(5)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 16, 4, 0, 10, 0)
        EVT_LOOP(5)
            EVT_ADD(LVar0, 12)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
        EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, 2)
        EVT_WAIT(2)
        EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, -2)
        EVT_WAIT(2)
        EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, 0)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
        EVT_WAIT(10)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(7.0))
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 0)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarF, BS_FLAGS1_40 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarE, BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(HIT_RESULT_HIT)
        EVT_CASE_OR_EQ(HIT_RESULT_NO_DAMAGE)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(HIT_RESULT_1)
        EVT_CASE_OR_EQ(HIT_RESULT_3)
            EVT_EXEC_WAIT(N(returnHomeOnMiss))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(powerShell) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_init)
    EVT_CALL(GetActorLevel, ACTOR_PARTNER, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 2)
        EVT_CASE_EQ(1)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 3)
        EVT_CASE_EQ(2)
            EVT_SET(LVarE, 1)
            EVT_SET(LVarF, 4)
    EVT_END_SWITCH
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_EnterShell)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_NE(LVar0, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_59)
    EVT_CALL(action_command_hammer_start, 0, 47, 3)
    EVT_CALL(SetActionQuality, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_200C)
    EVT_SET(LVar9, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(50)
        EVT_WAIT(1)
        EVT_SWITCH(LVar9)
            EVT_CASE_LT(20)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
            EVT_CASE_EQ(20)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            EVT_CASE_LT(30)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
            EVT_CASE_EQ(30)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            EVT_CASE_LT(40)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
            EVT_CASE_EQ(40)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            EVT_CASE_LT(50)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
            EVT_CASE_EQ(50)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
        EVT_END_SWITCH
        EVT_ADD(LVar9, 1)
        EVT_CALL(GetActionQuality, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_IF_NE(LVar1, TRUE)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
                EVT_SET(LVar1, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, BUTTON_STICK_LEFT, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_SET(LVarA, EVT_FLOAT(8.0))
    EVT_SWITCH(LVar9)
        EVT_CASE_LT(20)
            EVT_SET(LVarA, EVT_FLOAT(10.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
        EVT_CASE_LT(30)
            EVT_SET(LVarA, EVT_FLOAT(12.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
        EVT_CASE_LT(40)
            EVT_SET(LVarA, EVT_FLOAT(14.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
        EVT_CASE_LT(50)
            EVT_SET(LVarA, EVT_FLOAT(16.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
    EVT_END_SWITCH
    EVT_ADD(LVar9, 1)
    EVT_CALL(GetActionSuccess, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_200B)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_SET(LVarB, 260)
    EVT_DIVF(LVarB, LVarA)
    EVT_THREAD
        EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_ZERO, 1, ACTOR_DECORATION_GREY_SMOKE_TRAIL)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 260)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, LVarA)
        EVT_CALL(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 1)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 1)
    EVT_END_THREAD
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
    EVT_IF_GT(LVar0, LVar3)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 2, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, 6)
        EVT_GOTO(12)
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(GetActionCommandResult, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_GT(0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_04)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_SET(LFlag0, TRUE)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarF, BS_FLAGS1_40 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarE, BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_LABEL(12)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar2)
    EVT_IF_NE(LVar2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(GetActionCommandResult, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_GT(0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_04)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_LABEL(11)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_EXEC_WAIT(N(EVS_ReturnHome))
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(returnHomeOnMiss))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(dizzyShell) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_DIZZY_SHELL)
    EVT_CALL(action_command_dizzy_shell_init)
    EVT_CALL(SetupMashMeter, 1, 100, 0, 0, 0, 0)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_EnterShell)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_59)
    EVT_CALL(MoveBattleCamOver, 75 * DT)
    EVT_SET(LVarD, 75 * DT)
    EVT_SET(LVarA, LVarD)
    EVT_ADD(LVarA, -3)
    EVT_CALL(battle_partner_kooper_AverageTargetDizzyChance)
    EVT_CALL(action_command_dizzy_shell_start, 0, LVarA, 3, LVar0)
    EVT_CALL(SetActionQuality, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_200C)
    EVT_SET(LVar9, 0)
    EVT_SET(LVarA, EVT_FLOAT(8.0))
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_DIZZY_SHELL)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_ZERO, 1, ACTOR_DECORATION_WHIRLWIND)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_1, 1)
    EVT_SET(LVar9, 1)
    EVT_LOOP(LVarD)
        EVT_WAIT(1)
        EVT_CALL(GetActionQuality, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_LT(20 * DT)
                EVT_SET(LVarA, EVT_FLOAT(10.0))
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
            EVT_CASE_LT(40 * DT)
                EVT_SET(LVarA, EVT_FLOAT(12.0))
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
            EVT_CASE_LT(60 * DT)
                EVT_SET(LVarA, EVT_FLOAT(14.0))
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
            EVT_CASE_DEFAULT
                EVT_SET(LVarA, EVT_FLOAT(16.0))
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
        EVT_END_SWITCH
        EVT_SWITCH(LVarD)
            EVT_CASE_EQ(10 * DT)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            EVT_CASE_EQ(20 * DT)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            EVT_CASE_EQ(40 * DT)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
            EVT_CASE_EQ(60 * DT)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0)
        EVT_END_SWITCH
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0290)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_SET(LVarB, 300)
    EVT_DIVF(LVarB, LVarA)
    EVT_THREAD
        EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_ZERO, 0, ACTOR_DECORATION_GREY_SMOKE_TRAIL)
        EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 350)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, LVarA)
        EVT_CALL(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 0)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 1)
        EVT_WAIT(20)
        EVT_CALL(SetActorPos, ACTOR_PARTNER, -200, 0, 0)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, 40, 0, 0)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(12.0))
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 0, 0, EASING_QUARTIC_OUT)
        EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(N(SetTargetsYaw))
    EVT_END_THREAD
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 0)
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
    EVT_IF_GT(LVar0, LVar3)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 2, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_GOTO(12)
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(GetActionCommandResult, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_GT(99)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_04)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_SET(LFlag0, TRUE)
    EVT_CALL(GetActionQuality, LVarF)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_IF_EQ(LVar9, 1)
                EVT_IF_EQ(LVarF, 100)
                    EVT_CALL(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS,
                    SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, DMG_STATUS_ALWAYS(STATUS_FLAG_DIZZY, 3), 254, 0, BS_FLAGS1_40 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
                EVT_ELSE
                    EVT_CALL(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, DMG_STATUS_ALWAYS(STATUS_FLAG_DIZZY, 3), LVarF, 0, BS_FLAGS1_40 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, DMG_STATUS_ALWAYS(STATUS_FLAG_DIZZY, 3), LVarF, 0, BS_FLAGS1_40 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(LVar9, 1)
                EVT_CALL(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, DMG_STATUS_ALWAYS(STATUS_FLAG_DIZZY, 3), 255, 0, BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
            EVT_ELSE
                EVT_CALL(PartnerAfflictEnemy, LVar0, DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_STATUS_ALWAYS_HITS, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, DMG_STATUS_ALWAYS(STATUS_FLAG_DIZZY, 3), 255, 0, BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_LABEL(12)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar2)
    EVT_IF_NE(LVar2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(GetActionCommandResult, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_GT(99)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_04)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_LABEL(11)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(7.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(fireShell) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_FIRE_SHELL)
    EVT_CALL(action_command_fire_shell_init)
    EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_EnterShell)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_59)
    EVT_CALL(MoveBattleCamOver, 75 * DT)
    EVT_SET(LVarD, 75 * DT)
    EVT_SET(LVarC, LVarD)
    EVT_ADD(LVarC, -3)
    EVT_CALL(action_command_fire_shell_start, 0, LVarC, 3)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_1, 0)
    EVT_SET(LVarA, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_200C)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_028E)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, PRT_ZERO, 0, ACTOR_DECORATION_RED_FLAMES)
    EVT_WAIT(1)
    EVT_CALL(ModifyActorDecoration, ACTOR_PARTNER, -1, 0, 10, 10, 255, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_1, 1)
    EVT_CALL(SetActorPaletteEffect, ACTOR_PARTNER, -1, PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
    EVT_CALL(SetActorPaletteSwapParams, ACTOR_PARTNER, -1, SPR_PAL_BattleKooper, SPR_PAL_BattleKooper, 1, 10, 1000, 10, 0, 0)
    EVT_CALL(EnableActorPaletteEffects, ACTOR_PARTNER, 0, TRUE)
    EVT_SET(LVar6, SPR_PAL_BattleKooper)
    EVT_SET(LVar7, SPR_PAL_BattleKooper)
    EVT_SET(LVar8, 30)
    EVT_SET(LVar9, 30)
    EVT_LOOP(LVarD)
        EVT_WAIT(1)
        EVT_CALL(GetActionQuality, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_GE(80 * DT)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
                EVT_SET(LVar9, 80 * DT)
                EVT_SET(LVar7, SPR_PAL_BattleKooper_Red4)
                EVT_IF_NE(LVar6, LVar7)
                    EVT_CALL(SetActorPaletteEffect, ACTOR_PARTNER, -1, PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
                    EVT_CALL(SetActorPaletteSwapParams, ACTOR_PARTNER, -1, LVar6, LVar7, 1, 10, 1000, 10, 0, 0)
                    EVT_SET(LVar6, LVar7)
                EVT_END_IF
            EVT_CASE_GE(60 * DT)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
                EVT_SET(LVar9, 60 * DT)
                EVT_SET(LVar7, SPR_PAL_BattleKooper_Red3)
                EVT_IF_NE(LVar6, LVar7)
                    EVT_CALL(SetActorPaletteEffect, ACTOR_PARTNER, -1, PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
                    EVT_CALL(SetActorPaletteSwapParams, ACTOR_PARTNER, -1, LVar6, LVar7, 1, 10, 1000, 10, 0, 0)
                    EVT_SET(LVar6, LVar7)
                EVT_END_IF
            EVT_CASE_GE(40 * DT)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
                EVT_SET(LVar9, 40 * DT)
                EVT_SET(LVar7, SPR_PAL_BattleKooper_Red2)
                EVT_IF_NE(LVar6, LVar7)
                    EVT_CALL(SetActorPaletteEffect, ACTOR_PARTNER, -1, PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
                    EVT_CALL(SetActorPaletteSwapParams, ACTOR_PARTNER, -1, LVar6, LVar7, 1, 10, 1000, 10, 0, 0)
                    EVT_SET(LVar6, LVar7)
                EVT_END_IF
            EVT_CASE_GE(20 * DT)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
                EVT_SET(LVar9, 35 * DT)
                EVT_SET(LVar7, SPR_PAL_BattleKooper_Red1)
                EVT_IF_NE(LVar6, LVar7)
                    EVT_CALL(SetActorPaletteEffect, ACTOR_PARTNER, -1, PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
                    EVT_CALL(SetActorPaletteSwapParams, ACTOR_PARTNER, -1, LVar6, LVar7, 1, 10, 1000, 10, 0, 0)
                    EVT_SET(LVar6, LVar7)
                EVT_END_IF
            EVT_CASE_DEFAULT
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
                EVT_SET(LVar9, 30 * DT)
                EVT_SET(LVar7, SPR_PAL_BattleKooper)
                EVT_IF_NE(LVar6, LVar7)
                    EVT_CALL(SetActorPaletteEffect, ACTOR_PARTNER, -1, PAL_ADJUST_BLEND_PALETTES_VARYING_INTERVALS)
                    EVT_CALL(SetActorPaletteSwapParams, ACTOR_PARTNER, -1, LVar6, LVar7, 1, 10, 1000, 10, 0, 0)
                    EVT_SET(LVar6, LVar7)
                EVT_END_IF
        EVT_END_SWITCH
        EVT_IF_LT(LVar8, LVar9)
            EVT_ADD(LVar8, 1)
        EVT_END_IF
        EVT_IF_GT(LVar8, LVar9)
            EVT_SUB(LVar8, 1)
        EVT_END_IF
        EVT_CALL(ModifyActorDecoration, ACTOR_PARTNER, -1, 0, LVar8, LVar8, 255, 0)
        EVT_SWITCH(LVarD)
            EVT_CASE_EQ(10 * DT)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar3, LVar4, LVar5, 32, 4, 0, 10, 0)
            EVT_CASE_EQ(20 * DT)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar3, LVar4, LVar5, 32, 4, 0, 10, 0)
            EVT_CASE_EQ(40 * DT)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar3, LVar4, LVar5, 32, 4, 0, 10, 0)
            EVT_CASE_EQ(60 * DT)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
                EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar3, LVar4, LVar5, 32, 4, 0, 10, 0)
        EVT_END_SWITCH
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_028F)
    EVT_CALL(N(GetFireShellSpeedAndDamage))
    EVT_SWITCH(LVarE)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(1)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
            EVT_CALL(MoveBattleCamOver, 50)
            EVT_SETF(LVarA, EVT_FLOAT(10.0))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(3)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_SETF(LVarA, EVT_FLOAT(10.0))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(4)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_SETF(LVarA, EVT_FLOAT(16.0))
    EVT_END_SWITCH
    EVT_SET(LVarB, 350)
    EVT_DIVF(LVarB, LVarA)
    EVT_THREAD
        EVT_CALL(AddActorDecoration, ACTOR_PARTNER, -1, 1, ACTOR_DECORATION_FIRE_SMOKE_TRAIL)
        EVT_WAIT(1)
        EVT_SWITCH(LVarE)
            EVT_CASE_OR_EQ(0)
            EVT_CASE_OR_EQ(1)
                EVT_CALL(ModifyActorDecoration, ACTOR_PARTNER, -1, 1, 50, 0, 0, 0)
            EVT_END_CASE_GROUP
            EVT_CASE_OR_EQ(2)
            EVT_CASE_OR_EQ(3)
                EVT_CALL(ModifyActorDecoration, ACTOR_PARTNER, -1, 1, 100, 0, 0, 0)
            EVT_END_CASE_GROUP
            EVT_CASE_EQ(4)
                EVT_CALL(ModifyActorDecoration, ACTOR_PARTNER, -1, 1, 300, 0, 0, 0)
        EVT_END_SWITCH
        EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_ENABLE)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 350)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, LVarA)
        EVT_CALL(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 1)
        EVT_WAIT(20)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 0)
        EVT_CALL(EnableActorPaletteEffects, ACTOR_PARTNER, 0, FALSE)
        EVT_CALL(SetActorPos, ACTOR_PARTNER, -200, 0, 0)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, 40, 0, 0)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(12.0))
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 0, 0, EASING_QUARTIC_OUT)
        EVT_CALL(EnableActorBlur, ACTOR_PARTNER, ACTOR_BLUR_DISABLE)
        EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 1)
    EVT_END_THREAD
    EVT_CALL(SetActorVar, ACTOR_SELF, AVAR_Unk_0, 0)
    EVT_SET(LFlag0, FALSE)
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
    EVT_IF_GT(LVar0, LVar3)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 2, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, 6)
        EVT_GOTO(12)
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(GetActionCommandResult, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_GT(99)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_04)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_SET(LFlag0, TRUE)
    EVT_CALL(GetActionQuality, LVar0)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(99)
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_FIRE | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarF, BS_FLAGS1_40 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LVar0, DAMAGE_TYPE_FIRE | DAMAGE_TYPE_MULTIPLE_POPUPS, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarF, BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_LABEL(12)
    EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(LFlag0, FALSE)
        EVT_CALL(GetActionCommandResult, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_GT(99)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_04)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_LABEL(11)
    EVT_CALL(GetActorVar, ACTOR_SELF, AVAR_Unk_0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(PartnerYieldTurn)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(7.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    EVT_RETURN
    EVT_END
};

EvtScript N(shellTossOnFirstStrike) = {
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 60)
    EVT_CALL(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(16.0))
    EVT_CALL(SetActorSounds, ACTOR_PARTNER, ACTOR_SOUND_WALK, SOUND_NONE, SOUND_NONE)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_BURN_CONTACT, 0, 2, BS_FLAGS1_10)
    EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
        EVT_THREAD
            EVT_CALL(N(SlowDown))
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, PRT_ZERO, 0)
        EVT_END_THREAD
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellStill)
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 8, 0, 0)
        EVT_SET(LVar0, 0)
        EVT_LOOP(2)
            EVT_ADD(LVar0, -30)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(5)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 16, 4, 0, 10, 0)
        EVT_LOOP(5)
            EVT_ADD(LVar0, 12)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
        EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, 2)
        EVT_WAIT(2)
        EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, -2)
        EVT_WAIT(2)
        EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, 0)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
        EVT_WAIT(10)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(7.0))
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVarF, 1)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_SHELL_TOSS1)
            EVT_SET(LVarF, 1)
        EVT_CASE_EQ(MOVE_SHELL_TOSS2)
            EVT_SET(LVarF, 2)
        EVT_CASE_EQ(MOVE_SHELL_TOSS3)
            EVT_SET(LVarF, 3)
    EVT_END_SWITCH
    EVT_CALL(PartnerDamageEnemy, LVar0, 0, SUPPRESS_EVENT_SPIKY_TOP | SUPPRESS_EVENT_EXPLODE_CONTACT | SUPPRESS_EVENT_SPIKY_FRONT | SUPPRESS_EVENT_SHOCK_CONTACT | SUPPRESS_EVENT_BURN_CONTACT | SUPPRESS_EVENT_FLAG_80, 0, LVarF, BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(MOVE_SHELL_TOSS1)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
        EVT_CASE_EQ(MOVE_SHELL_TOSS2)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
        EVT_CASE_EQ(MOVE_SHELL_TOSS3)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_NONE)
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_SUB(LVar0, 40)
    EVT_SET(LVar1, 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.1))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_SUB(LVar0, 30)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, FALSE, TRUE)
    EVT_SUB(LVar0, 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 6, FALSE, FALSE, TRUE)
    EVT_SUB(LVar0, 10)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, FALSE, TRUE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(7.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, IDLE_SCRIPT_ENABLE)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
