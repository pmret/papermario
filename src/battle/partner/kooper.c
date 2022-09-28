#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/BattleKooper.h"
#include "battle/action_cmd/hammer.h"
#include "battle/action_cmd/fire_shell.h"
#include "battle/action_cmd/dizzy_shell.h"

#define NAMESPACE battle_partner_kooper

extern EvtScript N(init_80238570);
extern EvtScript N(takeTurn_80238974);
extern EvtScript N(idle_802385D0);
extern EvtScript N(handleEvent_802385E0);
extern EvtScript N(nextTurn_80238B6C);
extern EvtScript N(firstStrike);
extern EvtScript N(80238B7C);
extern EvtScript N(80238A20);
extern EvtScript N(runAway);
extern EvtScript N(runAwayFail);
extern EvtScript N(80239384);
extern EvtScript N(80239E7C);
extern EvtScript N(8023AA38);
extern EvtScript N(8023B660);
extern EvtScript N(8023C754);

ApiStatus func_80238000_6F5E80(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    ActorState* partnerActorMovement = &partnerActor->state;

    if (isInitialCall) {
        partnerActor->state.currentPos.x = partnerActor->currentPos.x;
        partnerActor->state.currentPos.y = partnerActor->currentPos.y;
        partnerActor->state.currentPos.z = partnerActor->currentPos.z;
    }

    add_xz_vec3f(&partnerActorMovement->currentPos, partnerActor->state.speed, partnerActor->state.angle);

    if (partnerActor->state.speed < 4.0f) {
        play_movement_dust_effects(0, partnerActor->state.currentPos.x, partnerActor->state.currentPos.y,
                                   partnerActor->state.currentPos.z, partnerActor->state.angle);
    } else {
        play_movement_dust_effects(1, partnerActor->state.currentPos.x, partnerActor->state.currentPos.y,
                                   partnerActor->state.currentPos.z, partnerActor->state.angle);
    }

    partnerActorMovement->speed = partnerActorMovement->speed / 1.5;

    partnerActor->currentPos.x = partnerActorMovement->currentPos.x;
    partnerActor->currentPos.y = partnerActorMovement->currentPos.y;
    partnerActor->currentPos.z = partnerActorMovement->currentPos.z;

    if (partnerActorMovement->speed < 1.0) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80238114_6F5F94(Evt* script, s32 isInitialCall) {
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
            x = actor->currentPos.x;
            target = &actor->targetData[actor->targetIndexList[i]];
            targetX = target->pos.x;
            targetActor = get_actor(target->actorID);

            if (targetActor != NULL) {
                targetActorPart = get_actor_part(targetActor, target->partID);

                if (targetActor->transparentStatus == 0) {
                    if (!(targetActorPart->eventFlags & 0x20)) {
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

ApiStatus N(AverageTargetDizzyChance)(Evt* script, s32 isInitialCall) {
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
        targetActorBlueprintBaseStatusChance = lookup_status_chance(targetActor->statusTable, STATUS_DIZZY);

        if (targetActor->transparentStatus == STATUS_TRANSPARENT) {
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

ApiStatus func_802383C0_6F6240(Evt* script, s32 isInitialCall) {
    s32 var0 = script->varTable[0];
    s32 var1;
    s32 var2;

    if (var0 < 36) {
        var1 = 1;
        var2 = 0;
    } else if (var0 < 61) {
        var1 = 3;
        var2 = 1;
    } else if (var0 < 81) {
        var1 = 4;
        var2 = 2;
    } else if (var0 < 100) {
        var1 = 5;
        var2 = 3;
    } else {
        var1 = 6;
        var2 = 4;
    }

    script->varTable[14] = var2;
    script->varTable[15] = var1;

    return ApiStatus_DONE2;
}

s32 N(idleAnimations_80238430)[] = {
    STATUS_NORMAL,    ANIM_BattleKooper_Walk,
    STATUS_STONE,     ANIM_BattleKooper_Still,
    STATUS_SLEEP,     ANIM_BattleKooper_Pray,
    STATUS_POISON,    ANIM_BattleKooper_Still,
    STATUS_STOP,      ANIM_BattleKooper_Still,
    STATUS_DAZE,      ANIM_BattleKooper_Injured,
    STATUS_TURN_DONE, ANIM_BattleKooper_Still,
    STATUS_END,
};

s32 N(defenseTable_8023846C)[] = {
    ELEMENT_NORMAL, 0,
    ELEMENT_END,
};

s32 N(statusTable_80238478)[] = {
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

ActorPartBlueprint N(partsTable_80238524)[] = {
    {
        .flags = 0,
        .index = 1,
        .posOffset = { 0, 0, 0 },
        .targetOffset = { 8, 27 },
        .opacity = 255,
        .idleAnimations = N(idleAnimations_80238430),
        .defenseTable = N(defenseTable_8023846C),
        .eventFlags = ACTOR_EVENT_FLAG_0,
        .elementImmunityFlags = 0,
        .unk_1C = 0,
    },
};

ActorBlueprint NAMESPACE = {
    .flags = 0,
    .type = ACTOR_TYPE_KOOPER,
    .level = 0,
    .maxHP = 99,
    .partCount = ARRAY_COUNT(N(partsTable_80238524)),
    .partsData = N(partsTable_80238524),
    .script = &N(init_80238570),
    .statusTable = N(statusTable_80238478),
    .escapeChance = 0,
    .airLiftChance = 0,
    .spookChance = 0,
    .baseStatusChance = 0,
    .upAndAwayChance = 0,
    .spinSmashReq = 4,
    .powerBounceChance = 80,
    .coinReward = 0,
    .size = { 32, 38 },
    .hpBarOffset = { 0, 0 },
    .statusIconOffset = { -10, 30 },
    .statusMessageOffset = { 10, 30 },
};

EvtScript N(init_80238570) = {
    EVT_CALL(BindTakeTurn, ACTOR_PARTNER, EVT_PTR(N(takeTurn_80238974)))
    EVT_CALL(BindIdle, ACTOR_PARTNER, EVT_PTR(N(idle_802385D0)))
    EVT_CALL(BindHandleEvent, ACTOR_PARTNER, EVT_PTR(N(handleEvent_802385E0)))
    EVT_CALL(BindNextTurn, ACTOR_PARTNER, EVT_PTR(N(nextTurn_80238B6C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(idle_802385D0) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(handleEvent_802385E0) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(CloseActionCommandInfo)
    EVT_CALL(GetLastEvent, ACTOR_PARTNER, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_SET_CONST(LVar2, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(D_802977BC)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(D_80296014)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(DoPartnerBlock)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_SET(LVar2, 16)
            EVT_EXEC_WAIT(D_80294FE4)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_BurnHurt)
            EVT_SET(LVar2, 16)
            EVT_SET_CONST(LVar3, ANIM_BattleKooper_BurnStill)
            EVT_EXEC_WAIT(D_80294C68)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_BurnHurt)
            EVT_SET_CONST(LVar2, ANIM_BattleKooper_BurnStill)
            EVT_EXEC_WAIT(D_8029621C)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_SET(LVar2, 16)
            EVT_EXEC_WAIT(D_80295744)
        EVT_CASE_EQ(EVENT_33)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Hurt)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(EVENT_RECOVER_PARTNER)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_Idle)
            EVT_SET_CONST(LVar2, ANIM_BattleKooper_Run)
            EVT_SET(LVar3, 0)
            EVT_EXEC_WAIT(DoPartnerRecover)
        EVT_CASE_OR_EQ(EVENT_18)
        EVT_CASE_OR_EQ(EVENT_BLOCK)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LVar0, 1)
            EVT_SET_CONST(LVar1, ANIM_BattleKooper_LowerShell)
            EVT_EXEC_WAIT(DoPartnerBlock)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ExitShell)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80238974) = {
    EVT_CALL(GetBattlePhase, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(PHASE_FIRST_STRIKE)
            EVT_EXEC_WAIT(N(firstStrike))
        EVT_CASE_EQ(PHASE_EXECUTE_ACTION)
            EVT_EXEC_WAIT(N(80238B7C))
        EVT_CASE_EQ(PHASE_5)
            EVT_EXEC_WAIT(N(80238A20))
        EVT_CASE_EQ(PHASE_RUN_AWAY_START)
            EVT_EXEC_WAIT(N(runAway))
        EVT_CASE_EQ(PHASE_RUN_AWAY_FAIL)
            EVT_EXEC_WAIT(N(runAwayFail))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80238A20) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_BattleKooper_Celebrate)
    EVT_SET_CONST(LVar2, ANIM_BattleKooper_Walk)
    EVT_SET_CONST(LVar3, ANIM_BattleKooper_Idle)
    EVT_EXEC_WAIT(D_80294720)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAway) = {
    EVT_SET_CONST(LVar0, 1)
    EVT_SET_CONST(LVar1, ANIM_BattleKooper_Run)
    EVT_EXEC_WAIT(D_80294AFC)
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

EvtScript N(nextTurn_80238B6C) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(80238B7C) = {
    EVT_CALL(func_802694A4, 1)
    EVT_CALL(SetBattleFlagBits, BS_FLAGS1_4000, 0)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(8)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(LVar0)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(137)
            EVT_CALL(func_80269EAC, 6)
            EVT_SET(LVarF, 2)
            EVT_SET(LVarE, 1)
            EVT_EXEC_WAIT(N(80239384))
        EVT_CASE_EQ(138)
            EVT_CALL(func_80269EAC, 6)
            EVT_SET(LVarF, 3)
            EVT_SET(LVarE, 2)
            EVT_EXEC_WAIT(N(80239384))
        EVT_CASE_EQ(139)
            EVT_CALL(func_80269EAC, 6)
            EVT_SET(LVarF, 5)
            EVT_SET(LVarE, 3)
            EVT_EXEC_WAIT(N(80239384))
        EVT_CASE_EQ(140)
            EVT_CALL(func_80269EAC, 7)
            EVT_EXEC_WAIT(N(80239E7C))
        EVT_CASE_EQ(141)
            EVT_CALL(func_80269EAC, 8)
            EVT_EXEC_WAIT(N(8023AA38))
        EVT_CASE_EQ(142)
            EVT_CALL(func_80269EAC, 9)
            EVT_EXEC_WAIT(N(8023B660))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(firstStrike) = {
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(137)
            EVT_CALL(func_80269EAC, 6)
            EVT_EXEC_WAIT(N(8023C754))
        EVT_CASE_EQ(138)
            EVT_CALL(func_80269EAC, 6)
            EVT_EXEC_WAIT(N(8023C754))
        EVT_CASE_EQ(139)
            EVT_CALL(func_80269EAC, 6)
            EVT_EXEC_WAIT(N(8023C754))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80238E38) = {
    EVT_CALL(ResetActorSounds, ACTOR_PARTNER, 0)
    EVT_THREAD
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
        EVT_WAIT(30)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
    EVT_END_THREAD
    EVT_CALL(func_80280818)
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

EvtScript N(80239084) = {
    EVT_CALL(ResetActorSounds, ACTOR_PARTNER, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_CALL(func_80280818)
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

EvtScript N(802392A4) = {
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

EvtScript N(80239384) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 30)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Run)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_Idle)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_EnterShell)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(CheckButtonDown, 0x00040000, LVar0)
        EVT_IF_NE(LVar0, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(func_802A9258_422258, 0, 47, 3)
    EVT_CALL(SetActionResult, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x200C)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_59)
    EVT_SET(LVar9, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(50)
        EVT_WAIT(1)
        EVT_SWITCH(LVar9)
            EVT_CASE_LT(20)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
            EVT_CASE_EQ(20)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(30)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
            EVT_CASE_EQ(30)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(40)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
            EVT_CASE_EQ(40)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(50)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
            EVT_CASE_EQ(50)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_END_SWITCH
        EVT_ADD(LVar9, 1)
        EVT_CALL(GetActionResult, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_IF_NE(LVar1, TRUE)
                EVT_SET(LVar1, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, 0x00040000, LVar0)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_SETF(LVarA, EVT_FLOAT(8.0))
    EVT_SWITCH(LVar9)
        EVT_CASE_LT(20)
            EVT_SETF(LVarA, EVT_FLOAT(10.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
        EVT_CASE_LT(30)
            EVT_SETF(LVarA, EVT_FLOAT(12.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
        EVT_CASE_LT(40)
            EVT_SETF(LVarA, EVT_FLOAT(14.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
        EVT_CASE_LT(50)
            EVT_SETF(LVarA, EVT_FLOAT(16.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
    EVT_END_SWITCH
    EVT_ADD(LVar9, 1)
    EVT_CALL(GetActionSuccess, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x200A)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_EXEC_WAIT(N(802392A4))
    EVT_CALL(AddActorDecoration, ACTOR_SELF, 0, 0, 5)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, LVarA)
    EVT_CALL(SetActorSounds, ACTOR_PARTNER, 0, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, 20, 0, 2, 16)
    EVT_IF_EQ(LVar0, 6)
        EVT_THREAD
            EVT_CALL(func_80238000_6F5E80)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 0)
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
        EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 16, 4, 0, 10, 0, 0, 0, 0, 0)
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
    EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 0)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, 159, 0, LVarF, 112)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LVar0, 0, 159, 0, LVarE, 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_SWITCH(LVar0)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(2)
            EVT_EXEC_WAIT(N(80239084))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(1)
        EVT_CASE_OR_EQ(3)
            EVT_EXEC_WAIT(N(80238E38))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(80239E7C) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_CALL(GetActorLevel, 256, LVar0)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(CheckButtonDown, 0x00040000, LVar0)
        EVT_IF_NE(LVar0, FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_59)
    EVT_CALL(func_802A9258_422258, 0, 47, 3)
    EVT_CALL(SetActionResult, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x200C)
    EVT_SET(LVar9, 0)
    EVT_SET(LVar1, 0)
    EVT_LOOP(50)
        EVT_WAIT(1)
        EVT_SWITCH(LVar9)
            EVT_CASE_LT(20)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
            EVT_CASE_EQ(20)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(30)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
            EVT_CASE_EQ(30)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(40)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
            EVT_CASE_EQ(40)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(50)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
            EVT_CASE_EQ(50)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_END_SWITCH
        EVT_ADD(LVar9, 1)
        EVT_CALL(GetActionResult, LVar0)
        EVT_IF_NE(LVar0, 0)
            EVT_IF_NE(LVar1, TRUE)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
                EVT_SET(LVar1, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, 0x00040000, LVar0)
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
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x200B)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_SET(LVarB, 260)
    EVT_DIVF(LVarB, LVarA)
    EVT_THREAD
        EVT_CALL(AddActorDecoration, ACTOR_SELF, 0, 1, 5)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 260)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, LVarA)
        EVT_CALL(SetActorSounds, ACTOR_PARTNER, 0, 0, 0)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 1)
    EVT_END_THREAD
    EVT_SET(LocalFlag(0), 0)
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
    EVT_IF_GT(LVar0, LVar3)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PartnerTestEnemy, LVar0, 0, 20, 0, 2, 16)
    EVT_IF_EQ(LVar0, 6)
        EVT_GOTO(12)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(GetActionCommandResult, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_GT(0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_SET(LocalFlag(0), 1)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_CALL(PartnerDamageEnemy, LVar0, 536870912, 159, 0, LVarF, 112)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LVar0, 536870912, 159, 0, LVarE, 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_LABEL(12)
    EVT_CALL(ChooseNextTarget, 0, LVar2)
    EVT_IF_NE(LVar2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(GetActionCommandResult, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_GT(0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_LABEL(11)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_EXEC_WAIT(N(80239084))
        EVT_CASE_DEFAULT
            EVT_EXEC_WAIT(N(80238E38))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(8023AA38) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_DIZZY_SHELL)
    EVT_CALL(func_802A9000_426170)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_59)
    EVT_CALL(MoveBattleCamOver, 75)
    EVT_SET(LVarD, 75)
    EVT_SET(LVarA, LVarD)
    EVT_ADD(LVarA, -3)
    EVT_CALL(battle_partner_kooper_AverageTargetDizzyChance)
    EVT_CALL(action_command_dizzy_shell_MashActionCommandInit, 0, LVarA, 3, LVar0)
    EVT_CALL(SetActionResult, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x200C)
    EVT_SET(LVar9, 0)
    EVT_SET(LVarA, EVT_FLOAT(8.0))
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x2026)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, 0, 1, 7)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_SET(LVar9, 1)
    EVT_LOOP(LVarD)
        EVT_WAIT(1)
        EVT_CALL(GetActionResult, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_LT(20)
                EVT_SET(LVarA, EVT_FLOAT(10.0))
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
            EVT_CASE_LT(40)
                EVT_SET(LVarA, EVT_FLOAT(12.0))
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
            EVT_CASE_LT(60)
                EVT_SET(LVarA, EVT_FLOAT(14.0))
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
            EVT_CASE_DEFAULT
                EVT_SET(LVarA, EVT_FLOAT(16.0))
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
        EVT_END_SWITCH
        EVT_SWITCH(LVarD)
            EVT_CASE_EQ(10)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_EQ(20)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_EQ(40)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_EQ(60)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar4, LVar5, LVar6)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_END_SWITCH
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x290)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_SET(LVarB, 300)
    EVT_DIVF(LVarB, LVarA)
    EVT_THREAD
        EVT_CALL(AddActorDecoration, ACTOR_SELF, 0, 0, 5)
        EVT_CALL(EnableActorBlur, ACTOR_PARTNER, 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 350)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, LVarA)
        EVT_CALL(SetActorSounds, ACTOR_PARTNER, 0, 0, 0)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 0)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 1)
        EVT_WAIT(20)
        EVT_CALL(SetActorPos, ACTOR_PARTNER, -200, 0, 0)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, 40, 0, 0)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(12.0))
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 0, 0, 6)
        EVT_CALL(EnableActorBlur, ACTOR_PARTNER, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(func_80238114_6F5F94)
    EVT_END_THREAD
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_SET(LocalFlag(0), 0)
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
    EVT_IF_GT(LVar0, LVar3)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PartnerTestEnemy, LVar0, 0, 20, 0, 2, 16)
    EVT_IF_EQ(LVar0, 6)
        EVT_GOTO(12)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(GetActionCommandResult, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_GT(99)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_SET(LocalFlag(0), 1)
    EVT_CALL(GetActionResult, LVarF)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(0)
            EVT_IF_EQ(LVar9, 1)
                EVT_IF_EQ(LVarF, 100)
                    EVT_CALL(PartnerAfflictEnemy, LVar0, 1610612736, 159, -1073478912, 254, 0, 112)
                EVT_ELSE
                    EVT_CALL(PartnerAfflictEnemy, LVar0, 1610612736, 159, -1073478912, LVarF, 0, 112)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(PartnerAfflictEnemy, LVar0, 1610612736, 159, -1073478912, LVarF, 0, 112)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(LVar9, 1)
                EVT_CALL(PartnerAfflictEnemy, LVar0, 1610612736, 159, -1073478912, 255, 0, 48)
            EVT_ELSE
                EVT_CALL(PartnerAfflictEnemy, LVar0, 1610612736, 159, -1073478912, 255, 0, 48)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_LABEL(12)
    EVT_CALL(ChooseNextTarget, 0, LVar2)
    EVT_IF_NE(LVar2, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(GetActionCommandResult, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_GT(99)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_LABEL(11)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(func_80280818)
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

EvtScript N(8023B660) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_FIRE_SHELL)
    EVT_CALL(func_802A9000_4269D0)
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
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_59)
    EVT_CALL(MoveBattleCamOver, 75)
    EVT_SET(LVarD, 75)
    EVT_SET(LVarC, LVarD)
    EVT_ADD(LVarC, -3)
    EVT_CALL(action_command_fire_shell_MashActionCommandInit, 0, LVarC, 3)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_SET(LVarA, EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x200C)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x28E)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, 0, 0, 4)
    EVT_WAIT(1)
    EVT_CALL(ModifyActorDecoration, 256, -1, 0, 10, 10, 255, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_CALL(func_8026EA7C, ACTOR_PARTNER, -1, 15)
    EVT_CALL(func_8026EBF8, ACTOR_PARTNER, -1, 0, 0, 1, 10, 1000, 10, 0, 0)
    EVT_CALL(func_8026ED20, ACTOR_PARTNER, 0, 1)
    EVT_SET(LVar6, 0)
    EVT_SET(LVar7, 0)
    EVT_SET(LVar8, 30)
    EVT_SET(LVar9, 30)
    EVT_LOOP(LVarD)
        EVT_WAIT(1)
        EVT_CALL(GetActionResult, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_GE(80)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFastest)
                EVT_SET(LVar9, 80)
                EVT_SET(LVar7, 8)
                EVT_IF_NE(LVar6, LVar7)
                    EVT_CALL(func_8026EA7C, ACTOR_PARTNER, -1, 15)
                    EVT_CALL(func_8026EBF8, ACTOR_PARTNER, -1, LVar6, LVar7, 1, 10, 1000, 10, 0, 0)
                    EVT_SET(LVar6, LVar7)
                EVT_END_IF
            EVT_CASE_GE(60)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinFaster)
                EVT_SET(LVar9, 60)
                EVT_SET(LVar7, 7)
                EVT_IF_NE(LVar6, LVar7)
                    EVT_CALL(func_8026EA7C, ACTOR_PARTNER, -1, 15)
                    EVT_CALL(func_8026EBF8, ACTOR_PARTNER, -1, LVar6, LVar7, 1, 10, 1000, 10, 0, 0)
                    EVT_SET(LVar6, LVar7)
                EVT_END_IF
            EVT_CASE_GE(40)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlower)
                EVT_SET(LVar9, 40)
                EVT_SET(LVar7, 6)
                EVT_IF_NE(LVar6, LVar7)
                    EVT_CALL(func_8026EA7C, ACTOR_PARTNER, -1, 15)
                    EVT_CALL(func_8026EBF8, ACTOR_PARTNER, -1, LVar6, LVar7, 1, 10, 1000, 10, 0, 0)
                    EVT_SET(LVar6, LVar7)
                EVT_END_IF
            EVT_CASE_GE(20)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
                EVT_SET(LVar9, 35)
                EVT_SET(LVar7, 5)
                EVT_IF_NE(LVar6, LVar7)
                    EVT_CALL(func_8026EA7C, ACTOR_PARTNER, -1, 15)
                    EVT_CALL(func_8026EBF8, ACTOR_PARTNER, -1, LVar6, LVar7, 1, 10, 1000, 10, 0, 0)
                    EVT_SET(LVar6, LVar7)
                EVT_END_IF
            EVT_CASE_DEFAULT
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
                EVT_SET(LVar9, 30)
                EVT_SET(LVar7, 0)
                EVT_IF_NE(LVar6, LVar7)
                    EVT_CALL(func_8026EA7C, ACTOR_PARTNER, -1, 15)
                    EVT_CALL(func_8026EBF8, ACTOR_PARTNER, -1, LVar6, LVar7, 1, 10, 1000, 10, 0, 0)
                    EVT_SET(LVar6, LVar7)
                EVT_END_IF
        EVT_END_SWITCH
        EVT_IF_LT(LVar8, LVar9)
            EVT_ADD(LVar8, 1)
        EVT_END_IF
        EVT_IF_GT(LVar8, LVar9)
            EVT_SUB(LVar8, 1)
        EVT_END_IF
        EVT_CALL(ModifyActorDecoration, 256, -1, 0, LVar8, LVar8, 255, 0)
        EVT_SWITCH(LVarD)
            EVT_CASE_EQ(10)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar3, LVar4, LVar5, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_EQ(20)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar3, LVar4, LVar5, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_EQ(40)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar3, LVar4, LVar5, 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_EQ(60)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar3, LVar4, LVar5, 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_END_SWITCH
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x28F)
    EVT_CALL(func_802383C0_6F6240)
    EVT_SWITCH(LVarE)
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(1)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
            EVT_CALL(MoveBattleCamOver, 50)
            EVT_SETF(LVarA, EVT_FLOAT(10.0))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(3)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_SETF(LVarA, EVT_FLOAT(10.0))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(4)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_SETF(LVarA, EVT_FLOAT(16.0))
    EVT_END_SWITCH
    EVT_SET(LVarB, 350)
    EVT_DIVF(LVarB, LVarA)
    EVT_THREAD
        EVT_CALL(AddActorDecoration, ACTOR_PARTNER, -1, 1, 6)
        EVT_WAIT(1)
        EVT_SWITCH(LVarE)
            EVT_CASE_OR_EQ(0)
            EVT_CASE_OR_EQ(1)
                EVT_CALL(ModifyActorDecoration, 256, -1, 1, 50, 0, 0, 0)
            EVT_END_CASE_GROUP
            EVT_CASE_OR_EQ(2)
            EVT_CASE_OR_EQ(3)
                EVT_CALL(ModifyActorDecoration, 256, -1, 1, 100, 0, 0, 0)
            EVT_END_CASE_GROUP
            EVT_CASE_EQ(4)
                EVT_CALL(ModifyActorDecoration, 256, -1, 1, 300, 0, 0, 0)
        EVT_END_SWITCH
        EVT_CALL(EnableActorBlur, ACTOR_PARTNER, 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 350)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, LVarA)
        EVT_CALL(SetActorSounds, ACTOR_PARTNER, 0, 0, 0)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 1)
        EVT_WAIT(20)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 0)
        EVT_CALL(func_8026ED20, ACTOR_PARTNER, 0, 0)
        EVT_CALL(SetActorPos, ACTOR_PARTNER, -200, 0, 0)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(AddGoalPos, ACTOR_PARTNER, 40, 0, 0)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(12.0))
        EVT_CALL(FlyToGoal, ACTOR_PARTNER, 0, 0, 6)
        EVT_CALL(EnableActorBlur, ACTOR_PARTNER, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
    EVT_END_THREAD
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_SET(LocalFlag(0), 0)
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar3, LVar4, LVar5)
    EVT_IF_GT(LVar0, LVar3)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PartnerTestEnemy, LVar0, 0, 20, 0, 2, 16)
    EVT_IF_EQ(LVar0, 6)
        EVT_GOTO(12)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(GetActionCommandResult, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_GT(99)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_SET(LocalFlag(0), 1)
    EVT_CALL(GetActionResult, LVar0)
    EVT_CALL(GetActionCommandResult, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_GT(99)
            EVT_CALL(PartnerDamageEnemy, LVar0, 536870914, 159, 0, LVarF, 112)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LVar0, 536870914, 159, 0, LVarF, 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_LABEL(12)
    EVT_CALL(ChooseNextTarget, 0, LVar0)
    EVT_IF_NE(LVar0, -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(LocalFlag(0), 0)
        EVT_CALL(GetActionCommandResult, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_GT(99)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_LABEL(11)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(func_80280818)
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

EvtScript N(8023C754) = {
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 60)
    EVT_CALL(SetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, ANIM_BattleKooper_ShellSpinSlowest)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(16.0))
    EVT_CALL(SetActorSounds, ACTOR_PARTNER, 0, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(PartnerTestEnemy, LVar0, 0, 20, 0, 2, 16)
    EVT_IF_EQ(LVar0, 6)
        EVT_THREAD
            EVT_CALL(func_80238000_6F5E80)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 0)
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
        EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LVar4, LVar5, LVar6, 16, 4, 0, 10, 0, 0, 0, 0, 0)
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
        EVT_CASE_EQ(137)
            EVT_SET(LVarF, 1)
        EVT_CASE_EQ(138)
            EVT_SET(LVarF, 2)
        EVT_CASE_EQ(139)
            EVT_SET(LVarF, 3)
    EVT_END_SWITCH
    EVT_CALL(PartnerDamageEnemy, LVar0, 0, 159, 0, LVarF, 48)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SWITCH(LVar2)
        EVT_CASE_EQ(137)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
        EVT_CASE_EQ(138)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
        EVT_CASE_EQ(139)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
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
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
