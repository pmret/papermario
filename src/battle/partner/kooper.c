#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/npc/battle_kooper.h"
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
    STATUS_NORMAL,    NPC_ANIM_battle_kooper_Palette_00_Anim_5,
    STATUS_STONE,     NPC_ANIM_battle_kooper_Palette_00_Anim_0,
    STATUS_SLEEP,     NPC_ANIM_battle_kooper_Palette_00_Anim_1B,
    STATUS_POISON,    NPC_ANIM_battle_kooper_Palette_00_Anim_0,
    STATUS_STOP,      NPC_ANIM_battle_kooper_Palette_00_Anim_0,
    STATUS_DAZE,      NPC_ANIM_battle_kooper_Palette_00_Anim_1C,
    STATUS_TURN_DONE, NPC_ANIM_battle_kooper_Palette_00_Anim_0,
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
    EVT_CALL(BindTakeTurn, ACTOR_PARTNER, EVT_ADDR(N(takeTurn_80238974)))
    EVT_CALL(BindIdle, ACTOR_PARTNER, EVT_ADDR(N(idle_802385D0)))
    EVT_CALL(BindHandleEvent, ACTOR_PARTNER, EVT_ADDR(N(handleEvent_802385E0)))
    EVT_CALL(BindNextTurn, ACTOR_PARTNER, EVT_ADDR(N(nextTurn_80238B6C)))
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
    EVT_CALL(GetLastEvent, ACTOR_PARTNER, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_OR_EQ(EVENT_HIT_COMBO)
        EVT_CASE_OR_EQ(EVENT_HIT)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_EXEC_WAIT(D_802977BC)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_EXEC_WAIT(D_80296014)
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(EVENT_UNKNOWN_TRIGGER)
        EVT_CASE_OR_EQ(EVENT_IMMUNE)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_EXEC_WAIT(D_80297814)
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(EVENT_SPIKE_CONTACT)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_SET(LW(2), 16)
            EVT_EXEC_WAIT(D_80294FE4)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(EVENT_BURN_CONTACT)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_12)
            EVT_SET(LW(2), 16)
            EVT_SET_CONST(LW(3), NPC_ANIM_battle_kooper_Palette_00_Anim_13)
            EVT_EXEC_WAIT(D_80294C68)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(EVENT_BURN_HIT)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_12)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_kooper_Palette_00_Anim_13)
            EVT_EXEC_WAIT(D_8029621C)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(EVENT_SHOCK_HIT)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_SET(LW(2), 16)
            EVT_EXEC_WAIT(D_80295744)
        EVT_CASE_EQ(EVENT_33)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_11)
            EVT_EXEC_WAIT(D_80296014)
        EVT_CASE_EQ(EVENT_RECOVER_PARTNER)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_4)
            EVT_SET_CONST(LW(2), NPC_ANIM_battle_kooper_Palette_00_Anim_6)
            EVT_SET(LW(3), 0)
            EVT_EXEC_WAIT(D_80295EC4)
        EVT_CASE_OR_EQ(EVENT_18)
        EVT_CASE_OR_EQ(EVENT_BLOCK)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_208C)
            EVT_SET_CONST(LW(0), 1)
            EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_10)
            EVT_EXEC_WAIT(D_80297814)
            EVT_WAIT(10)
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_F)
        EVT_END_CASE_GROUP
        EVT_CASE_DEFAULT
    EVT_END_SWITCH
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(takeTurn_80238974) = {
    EVT_CALL(GetBattlePhase, LW(0))
    EVT_SWITCH(LW(0))
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
    EVT_SET_CONST(LW(0), 1)
    EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_16)
    EVT_SET_CONST(LW(2), NPC_ANIM_battle_kooper_Palette_00_Anim_5)
    EVT_SET_CONST(LW(3), NPC_ANIM_battle_kooper_Palette_00_Anim_4)
    EVT_EXEC_WAIT(D_80294720)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAway) = {
    EVT_SET_CONST(LW(0), 1)
    EVT_SET_CONST(LW(1), NPC_ANIM_battle_kooper_Palette_00_Anim_6)
    EVT_EXEC_WAIT(D_80294AFC)
    EVT_RETURN
    EVT_END
};

EvtScript N(runAwayFail) = {
    EVT_CALL(UseIdleAnimation, ACTOR_PARTNER, FALSE)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(6.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_6)
    EVT_CALL(SetActorYaw, ACTOR_PARTNER, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_4)
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
    EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(8)
            EVT_CALL(LoadStarPowerScript)
            EVT_EXEC_WAIT(LW(0))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
    EVT_SWITCH(LW(2))
        EVT_CASE_EQ(137)
            EVT_CALL(func_80269EAC, 6)
            EVT_SET(LW(15), 2)
            EVT_SET(LW(14), 1)
            EVT_EXEC_WAIT(N(80239384))
        EVT_CASE_EQ(138)
            EVT_CALL(func_80269EAC, 6)
            EVT_SET(LW(15), 3)
            EVT_SET(LW(14), 2)
            EVT_EXEC_WAIT(N(80239384))
        EVT_CASE_EQ(139)
            EVT_CALL(func_80269EAC, 6)
            EVT_SET(LW(15), 5)
            EVT_SET(LW(14), 3)
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
    EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
    EVT_SWITCH(LW(2))
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
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 60)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.4))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 20, FALSE, TRUE, FALSE)
    EVT_SUB(LW(0), 30)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, FALSE, TRUE)
    EVT_SUB(LW(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 6, FALSE, FALSE, TRUE)
    EVT_SUB(LW(0), 10)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, FALSE, TRUE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_F)
    EVT_WAIT(4)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(7.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_6)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_4)
    EVT_RETURN
    EVT_END
};

EvtScript N(80239084) = {
    EVT_CALL(ResetActorSounds, ACTOR_PARTNER, 0)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
    EVT_CALL(func_80280818)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 30)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.1))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_SUB(LW(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, FALSE, TRUE)
    EVT_SUB(LW(0), 10)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 6, FALSE, FALSE, TRUE)
    EVT_SUB(LW(0), 10)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, FALSE, TRUE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_F)
    EVT_WAIT(4)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(7.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_6)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_4)
    EVT_RETURN
    EVT_END
};

EvtScript N(802392A4) = {
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LW(11), LW(12), LW(13))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(12), LW(13), LW(0))
    EVT_IF_GT(LW(11), LW(12))
        EVT_SUB(LW(11), LW(12))
    EVT_ELSE
        EVT_SUB(LW(12), LW(11))
        EVT_SET(LW(11), LW(12))
    EVT_END_IF
    EVT_DIVF(LW(11), LW(10))
    EVT_IF_LT(LW(11), 0)
        EVT_SET(LW(11), 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(80239384) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_SMASH)
    EVT_CALL(action_command_hammer_CreateHudElements)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 30)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_6)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_4)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_E)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(CheckButtonDown, 0x00040000, LW(0))
        EVT_IF_NE(LW(0), FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(func_802A9258_422258, 0, 47, 3)
    EVT_CALL(SetActionResult, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x200C)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_59)
    EVT_SET(LW(9), 0)
    EVT_SET(LW(1), 0)
    EVT_LOOP(50)
        EVT_WAIT(1)
        EVT_SWITCH(LW(9))
            EVT_CASE_LT(20)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
            EVT_CASE_EQ(20)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(4), LW(5), LW(6))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(4), LW(5), LW(6), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(30)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_B)
            EVT_CASE_EQ(30)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(4), LW(5), LW(6))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(4), LW(5), LW(6), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(40)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_C)
            EVT_CASE_EQ(40)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(4), LW(5), LW(6))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(4), LW(5), LW(6), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(50)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_D)
            EVT_CASE_EQ(50)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(4), LW(5), LW(6))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(4), LW(5), LW(6), 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_END_SWITCH
        EVT_ADD(LW(9), 1)
        EVT_CALL(GetActionResult, LW(0))
        EVT_IF_NE(LW(0), 0)
            EVT_IF_NE(LW(1), TRUE)
                EVT_SET(LW(1), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, 0x00040000, LW(0))
        EVT_IF_EQ(LW(0), FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_SETF(LW(10), EVT_FLOAT(8.0))
    EVT_SWITCH(LW(9))
        EVT_CASE_LT(20)
            EVT_SETF(LW(10), EVT_FLOAT(10.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
        EVT_CASE_LT(30)
            EVT_SETF(LW(10), EVT_FLOAT(12.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_B)
        EVT_CASE_LT(40)
            EVT_SETF(LW(10), EVT_FLOAT(14.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_C)
        EVT_CASE_LT(50)
            EVT_SETF(LW(10), EVT_FLOAT(16.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_D)
    EVT_END_SWITCH
    EVT_ADD(LW(9), 1)
    EVT_CALL(GetActionSuccess, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x200A)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_EXEC_WAIT(N(802392A4))
    EVT_CALL(AddActorDecoration, ACTOR_SELF, 0, 0, 5)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, LW(10))
    EVT_CALL(SetActorSounds, ACTOR_PARTNER, 0, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(PartnerTestEnemy, LW(0), 0, 20, 0, 2, 16)
    EVT_IF_EQ(LW(0), 6)
        EVT_THREAD
            EVT_CALL(func_80238000_6F5E80)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 0)
        EVT_END_THREAD
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_9)
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 8, 0, 0)
        EVT_SET(LW(0), 0)
        EVT_LOOP(2)
            EVT_ADD(LW(0), -30)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LW(0))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(5)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(4), LW(5), LW(6))
        EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(4), LW(5), LW(6), 16, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_LOOP(5)
            EVT_ADD(LW(0), 12)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LW(0))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
        EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, 2)
        EVT_WAIT(2)
        EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, -2)
        EVT_WAIT(2)
        EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, 0)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_F)
        EVT_WAIT(10)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(7.0))
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_6)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 0)
    EVT_CALL(GetActionCommandResult, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_GT(0)
            EVT_CALL(PartnerDamageEnemy, LW(0), 0, 159, 0, LW(15), 112)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LW(0), 0, 159, 0, LW(14), 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_SWITCH(LW(0))
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
    EVT_CALL(GetActorLevel, 256, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_EQ(0)
            EVT_SET(LW(14), 1)
            EVT_SET(LW(15), 2)
        EVT_CASE_EQ(1)
            EVT_SET(LW(14), 1)
            EVT_SET(LW(15), 3)
        EVT_CASE_EQ(2)
            EVT_SET(LW(14), 1)
            EVT_SET(LW(15), 4)
    EVT_END_SWITCH
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 30)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_6)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_4)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_E)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
    EVT_LOOP(30)
        EVT_WAIT(1)
        EVT_CALL(CheckButtonDown, 0x00040000, LW(0))
        EVT_IF_NE(LW(0), FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_59)
    EVT_CALL(func_802A9258_422258, 0, 47, 3)
    EVT_CALL(SetActionResult, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x200C)
    EVT_SET(LW(9), 0)
    EVT_SET(LW(1), 0)
    EVT_LOOP(50)
        EVT_WAIT(1)
        EVT_SWITCH(LW(9))
            EVT_CASE_LT(20)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
            EVT_CASE_EQ(20)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(4), LW(5), LW(6))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(4), LW(5), LW(6), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(30)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_B)
            EVT_CASE_EQ(30)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(4), LW(5), LW(6))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(4), LW(5), LW(6), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(40)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_C)
            EVT_CASE_EQ(40)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(4), LW(5), LW(6))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(4), LW(5), LW(6), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_LT(50)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_D)
            EVT_CASE_EQ(50)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(4), LW(5), LW(6))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(4), LW(5), LW(6), 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_END_SWITCH
        EVT_ADD(LW(9), 1)
        EVT_CALL(GetActionResult, LW(0))
        EVT_IF_NE(LW(0), 0)
            EVT_IF_NE(LW(1), TRUE)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
                EVT_SET(LW(1), 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(CheckButtonDown, 0x00040000, LW(0))
        EVT_IF_EQ(LW(0), FALSE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(1)
    EVT_SET(LW(10), EVT_FLOAT(8.0))
    EVT_SWITCH(LW(9))
        EVT_CASE_LT(20)
            EVT_SET(LW(10), EVT_FLOAT(10.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
        EVT_CASE_LT(30)
            EVT_SET(LW(10), EVT_FLOAT(12.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_B)
        EVT_CASE_LT(40)
            EVT_SET(LW(10), EVT_FLOAT(14.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_C)
        EVT_CASE_LT(50)
            EVT_SET(LW(10), EVT_FLOAT(16.0))
            EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_D)
    EVT_END_SWITCH
    EVT_ADD(LW(9), 1)
    EVT_CALL(GetActionSuccess, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetActorVar, ACTOR_SELF, 0, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x200B)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_SET(LW(11), 260)
    EVT_DIVF(LW(11), LW(10))
    EVT_THREAD
        EVT_CALL(AddActorDecoration, ACTOR_SELF, 0, 1, 5)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 260)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, LW(10))
        EVT_CALL(SetActorSounds, ACTOR_PARTNER, 0, 0, 0)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_CALL(SetActorVar, ACTOR_SELF, 0, 1)
        EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 1)
    EVT_END_THREAD
    EVT_SET(LF(0), 0)
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(3), LW(4), LW(5))
    EVT_IF_GT(LW(0), LW(3))
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PartnerTestEnemy, LW(0), 0, 20, 0, 2, 16)
    EVT_IF_EQ(LW(0), 6)
        EVT_GOTO(12)
    EVT_END_IF
    EVT_IF_EQ(LF(0), 0)
        EVT_CALL(GetActionCommandResult, LW(0))
        EVT_SWITCH(LW(0))
            EVT_CASE_GT(0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_SET(LF(0), 1)
    EVT_CALL(GetActionCommandResult, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_GT(0)
            EVT_CALL(PartnerDamageEnemy, LW(0), 536870912, 159, 0, LW(15), 112)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LW(0), 536870912, 159, 0, LW(14), 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_LABEL(12)
    EVT_CALL(ChooseNextTarget, 0, LW(2))
    EVT_IF_NE(LW(2), -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(LF(0), 0)
        EVT_CALL(GetActionCommandResult, LW(0))
        EVT_SWITCH(LW(0))
            EVT_CASE_GT(0)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_LABEL(11)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_WAIT(1)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_CALL(GetActionCommandResult, LW(0))
    EVT_SWITCH(LW(0))
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
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 30)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_6)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_4)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_E)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_59)
    EVT_CALL(MoveBattleCamOver, 75)
    EVT_SET(LW(13), 75)
    EVT_SET(LW(10), LW(13))
    EVT_ADD(LW(10), -3)
    EVT_CALL(battle_partner_kooper_AverageTargetDizzyChance)
    EVT_CALL(action_command_dizzy_shell_MashActionCommandInit, 0, LW(10), 3, LW(0))
    EVT_CALL(SetActionResult, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x200C)
    EVT_SET(LW(9), 0)
    EVT_SET(LW(10), EVT_FLOAT(8.0))
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x2026)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, 0, 1, 7)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_SET(LW(9), 1)
    EVT_LOOP(LW(13))
        EVT_WAIT(1)
        EVT_CALL(GetActionResult, LW(0))
        EVT_SWITCH(LW(0))
            EVT_CASE_LT(20)
                EVT_SET(LW(10), EVT_FLOAT(10.0))
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
            EVT_CASE_LT(40)
                EVT_SET(LW(10), EVT_FLOAT(12.0))
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_B)
            EVT_CASE_LT(60)
                EVT_SET(LW(10), EVT_FLOAT(14.0))
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_C)
            EVT_CASE_DEFAULT
                EVT_SET(LW(10), EVT_FLOAT(16.0))
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_D)
        EVT_END_SWITCH
        EVT_SWITCH(LW(13))
            EVT_CASE_EQ(10)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(4), LW(5), LW(6))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(4), LW(5), LW(6), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_EQ(20)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(4), LW(5), LW(6))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(4), LW(5), LW(6), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_EQ(40)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(4), LW(5), LW(6))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(4), LW(5), LW(6), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_EQ(60)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(4), LW(5), LW(6))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(4), LW(5), LW(6), 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_END_SWITCH
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x290)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_SET(LW(11), 300)
    EVT_DIVF(LW(11), LW(10))
    EVT_THREAD
        EVT_CALL(AddActorDecoration, ACTOR_SELF, 0, 0, 5)
        EVT_CALL(EnableActorBlur, ACTOR_PARTNER, 1)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 350)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, LW(10))
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
    EVT_SET(LF(0), 0)
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(3), LW(4), LW(5))
    EVT_IF_GT(LW(0), LW(3))
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PartnerTestEnemy, LW(0), 0, 20, 0, 2, 16)
    EVT_IF_EQ(LW(0), 6)
        EVT_GOTO(12)
    EVT_END_IF
    EVT_IF_EQ(LF(0), 0)
        EVT_CALL(GetActionCommandResult, LW(0))
        EVT_SWITCH(LW(0))
            EVT_CASE_GT(99)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_SET(LF(0), 1)
    EVT_CALL(GetActionResult, LW(15))
    EVT_CALL(GetActionCommandResult, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_GT(0)
            EVT_IF_EQ(LW(9), 1)
                EVT_IF_EQ(LW(15), 100)
                    EVT_CALL(PartnerAfflictEnemy, LW(0), 1610612736, 159, -1073478912, 254, 0, 112)
                EVT_ELSE
                    EVT_CALL(PartnerAfflictEnemy, LW(0), 1610612736, 159, -1073478912, LW(15), 0, 112)
                EVT_END_IF
            EVT_ELSE
                EVT_CALL(PartnerAfflictEnemy, LW(0), 1610612736, 159, -1073478912, LW(15), 0, 112)
            EVT_END_IF
        EVT_CASE_DEFAULT
            EVT_IF_EQ(LW(9), 1)
                EVT_CALL(PartnerAfflictEnemy, LW(0), 1610612736, 159, -1073478912, 255, 0, 48)
            EVT_ELSE
                EVT_CALL(PartnerAfflictEnemy, LW(0), 1610612736, 159, -1073478912, 255, 0, 48)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_LABEL(12)
    EVT_CALL(ChooseNextTarget, 0, LW(2))
    EVT_IF_NE(LW(2), -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(LF(0), 0)
        EVT_CALL(GetActionCommandResult, LW(0))
        EVT_SWITCH(LW(0))
            EVT_CASE_GT(99)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_LABEL(11)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_WAIT(1)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(func_80280818)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_F)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_4)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(7.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_6)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_4)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023B660) = {
    EVT_CALL(LoadActionCommand, ACTION_COMMAND_FIRE_SHELL)
    EVT_CALL(func_802A9000_4269D0)
    EVT_CALL(SetupMashMeter, 5, 35, 60, 80, 99, 100)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 30)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(4.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_6)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0, FALSE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_4)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_E)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_59)
    EVT_CALL(MoveBattleCamOver, 75)
    EVT_SET(LW(13), 75)
    EVT_SET(LW(12), LW(13))
    EVT_ADD(LW(12), -3)
    EVT_CALL(action_command_fire_shell_MashActionCommandInit, 0, LW(12), 3)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 0)
    EVT_SET(LW(10), EVT_FLOAT(8.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x200C)
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x28E)
    EVT_CALL(AddActorDecoration, ACTOR_SELF, 0, 0, 4)
    EVT_WAIT(1)
    EVT_CALL(ModifyActorDecoration, 256, -1, 0, 10, 10, 255, 0)
    EVT_CALL(SetActorVar, ACTOR_SELF, 1, 1)
    EVT_CALL(func_8026EA7C, ACTOR_PARTNER, -1, 15)
    EVT_CALL(func_8026EBF8, ACTOR_PARTNER, -1, 0, 0, 1, 10, 1000, 10, 0, 0)
    EVT_CALL(func_8026ED20, ACTOR_PARTNER, 0, 1)
    EVT_SET(LW(6), 0)
    EVT_SET(LW(7), 0)
    EVT_SET(LW(8), 30)
    EVT_SET(LW(9), 30)
    EVT_LOOP(LW(13))
        EVT_WAIT(1)
        EVT_CALL(GetActionResult, LW(0))
        EVT_SWITCH(LW(0))
            EVT_CASE_GE(80)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_D)
                EVT_SET(LW(9), 80)
                EVT_SET(LW(7), 8)
                EVT_IF_NE(LW(6), LW(7))
                    EVT_CALL(func_8026EA7C, ACTOR_PARTNER, -1, 15)
                    EVT_CALL(func_8026EBF8, ACTOR_PARTNER, -1, LW(6), LW(7), 1, 10, 1000, 10, 0, 0)
                    EVT_SET(LW(6), LW(7))
                EVT_END_IF
            EVT_CASE_GE(60)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_C)
                EVT_SET(LW(9), 60)
                EVT_SET(LW(7), 7)
                EVT_IF_NE(LW(6), LW(7))
                    EVT_CALL(func_8026EA7C, ACTOR_PARTNER, -1, 15)
                    EVT_CALL(func_8026EBF8, ACTOR_PARTNER, -1, LW(6), LW(7), 1, 10, 1000, 10, 0, 0)
                    EVT_SET(LW(6), LW(7))
                EVT_END_IF
            EVT_CASE_GE(40)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_B)
                EVT_SET(LW(9), 40)
                EVT_SET(LW(7), 6)
                EVT_IF_NE(LW(6), LW(7))
                    EVT_CALL(func_8026EA7C, ACTOR_PARTNER, -1, 15)
                    EVT_CALL(func_8026EBF8, ACTOR_PARTNER, -1, LW(6), LW(7), 1, 10, 1000, 10, 0, 0)
                    EVT_SET(LW(6), LW(7))
                EVT_END_IF
            EVT_CASE_GE(20)
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
                EVT_SET(LW(9), 35)
                EVT_SET(LW(7), 5)
                EVT_IF_NE(LW(6), LW(7))
                    EVT_CALL(func_8026EA7C, ACTOR_PARTNER, -1, 15)
                    EVT_CALL(func_8026EBF8, ACTOR_PARTNER, -1, LW(6), LW(7), 1, 10, 1000, 10, 0, 0)
                    EVT_SET(LW(6), LW(7))
                EVT_END_IF
            EVT_CASE_DEFAULT
                EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
                EVT_SET(LW(9), 30)
                EVT_SET(LW(7), 0)
                EVT_IF_NE(LW(6), LW(7))
                    EVT_CALL(func_8026EA7C, ACTOR_PARTNER, -1, 15)
                    EVT_CALL(func_8026EBF8, ACTOR_PARTNER, -1, LW(6), LW(7), 1, 10, 1000, 10, 0, 0)
                    EVT_SET(LW(6), LW(7))
                EVT_END_IF
        EVT_END_SWITCH
        EVT_IF_LT(LW(8), LW(9))
            EVT_ADD(LW(8), 1)
        EVT_END_IF
        EVT_IF_GT(LW(8), LW(9))
            EVT_SUB(LW(8), 1)
        EVT_END_IF
        EVT_CALL(ModifyActorDecoration, 256, -1, 0, LW(8), LW(8), 255, 0)
        EVT_SWITCH(LW(13))
            EVT_CASE_EQ(10)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(3), LW(4), LW(5))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(3), LW(4), LW(5), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_EQ(20)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(3), LW(4), LW(5))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(3), LW(4), LW(5), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_EQ(40)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(3), LW(4), LW(5))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(3), LW(4), LW(5), 32, 4, 0, 10, 0, 0, 0, 0, 0)
            EVT_CASE_EQ(60)
                EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(3), LW(4), LW(5))
                EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(3), LW(4), LW(5), 32, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_END_SWITCH
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, 0x28F)
    EVT_CALL(func_802383C0_6F6240)
    EVT_SWITCH(LW(14))
        EVT_CASE_OR_EQ(0)
        EVT_CASE_OR_EQ(1)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
            EVT_CALL(MoveBattleCamOver, 50)
            EVT_SETF(LW(10), EVT_FLOAT(10.0))
        EVT_END_CASE_GROUP
        EVT_CASE_OR_EQ(2)
        EVT_CASE_OR_EQ(3)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
            EVT_CALL(MoveBattleCamOver, 30)
            EVT_SETF(LW(10), EVT_FLOAT(10.0))
        EVT_END_CASE_GROUP
        EVT_CASE_EQ(4)
            EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
            EVT_CALL(MoveBattleCamOver, 15)
            EVT_SETF(LW(10), EVT_FLOAT(16.0))
    EVT_END_SWITCH
    EVT_SET(LW(11), 350)
    EVT_DIVF(LW(11), LW(10))
    EVT_THREAD
        EVT_CALL(AddActorDecoration, ACTOR_PARTNER, -1, 1, 6)
        EVT_WAIT(1)
        EVT_SWITCH(LW(14))
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
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
        EVT_ADD(LW(0), 350)
        EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, LW(10))
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
    EVT_SET(LF(0), 0)
    EVT_LABEL(10)
    EVT_WAIT(1)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(3), LW(4), LW(5))
    EVT_IF_GT(LW(0), LW(3))
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(PartnerTestEnemy, LW(0), 0, 20, 0, 2, 16)
    EVT_IF_EQ(LW(0), 6)
        EVT_GOTO(12)
    EVT_END_IF
    EVT_IF_EQ(LF(0), 0)
        EVT_CALL(GetActionCommandResult, LW(0))
        EVT_SWITCH(LW(0))
            EVT_CASE_GT(99)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_SET(LF(0), 1)
    EVT_CALL(GetActionResult, LW(0))
    EVT_CALL(GetActionCommandResult, LW(0))
    EVT_SWITCH(LW(0))
        EVT_CASE_GT(99)
            EVT_CALL(PartnerDamageEnemy, LW(0), 536870914, 159, 0, LW(15), 112)
        EVT_CASE_DEFAULT
            EVT_CALL(PartnerDamageEnemy, LW(0), 536870914, 159, 0, LW(15), 48)
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_LABEL(12)
    EVT_CALL(ChooseNextTarget, 0, LW(0))
    EVT_IF_NE(LW(0), -1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_IF_EQ(LF(0), 0)
        EVT_CALL(GetActionCommandResult, LW(0))
        EVT_SWITCH(LW(0))
            EVT_CASE_GT(99)
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_E)
            EVT_CASE_DEFAULT
                EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_51)
        EVT_END_SWITCH
    EVT_END_IF
    EVT_LABEL(11)
    EVT_CALL(GetActorVar, ACTOR_SELF, 0, LW(0))
    EVT_IF_EQ(LW(0), 0)
        EVT_WAIT(1)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_CALL(func_80280818)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_F)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_4)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(7.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_6)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_4)
    EVT_RETURN
    EVT_END
};

EvtScript N(8023C754) = {
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_ADD(LW(0), 60)
    EVT_CALL(SetActorPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(InitTargetIterator)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_A)
    EVT_CALL(SetGoalToTarget, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(16.0))
    EVT_CALL(SetActorSounds, ACTOR_PARTNER, 0, 0, 0)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(PartnerTestEnemy, LW(0), 0, 20, 0, 2, 16)
    EVT_IF_EQ(LW(0), 6)
        EVT_THREAD
            EVT_CALL(func_80238000_6F5E80)
            EVT_CALL(RemoveActorDecoration, ACTOR_SELF, 0, 0)
        EVT_END_THREAD
        EVT_WAIT(4)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_9)
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 8, 0, 0)
        EVT_SET(LW(0), 0)
        EVT_LOOP(2)
            EVT_ADD(LW(0), -30)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LW(0))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_WAIT(5)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LW(4), LW(5), LW(6))
        EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 1, LW(4), LW(5), LW(6), 16, 4, 0, 10, 0, 0, 0, 0, 0)
        EVT_LOOP(5)
            EVT_ADD(LW(0), 12)
            EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, LW(0))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetActorRotationOffset, ACTOR_PARTNER, 0, 0, 0)
        EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, 2)
        EVT_WAIT(2)
        EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, -2)
        EVT_WAIT(2)
        EVT_CALL(SetActorRotation, ACTOR_PARTNER, 0, 0, 0)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_F)
        EVT_WAIT(10)
        EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
        EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(7.0))
        EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_6)
        EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LW(15), 1)
    EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
    EVT_SWITCH(LW(2))
        EVT_CASE_EQ(137)
            EVT_SET(LW(15), 1)
        EVT_CASE_EQ(138)
            EVT_SET(LW(15), 2)
        EVT_CASE_EQ(139)
            EVT_SET(LW(15), 3)
    EVT_END_SWITCH
    EVT_CALL(PartnerDamageEnemy, LW(0), 0, 159, 0, LW(15), 48)
    EVT_CALL(GetMenuSelection, LW(0), LW(1), LW(2))
    EVT_SWITCH(LW(2))
        EVT_CASE_EQ(137)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
        EVT_CASE_EQ(138)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
        EVT_CASE_EQ(139)
            EVT_CALL(PlaySoundAtActor, ACTOR_PARTNER, SOUND_0)
    EVT_END_SWITCH
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(GetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_SUB(LW(0), 40)
    EVT_SET(LW(1), 0)
    EVT_CALL(SetActorJumpGravity, ACTOR_PARTNER, EVT_FLOAT(1.1))
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 10, FALSE, TRUE, FALSE)
    EVT_SUB(LW(0), 30)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 8, FALSE, FALSE, TRUE)
    EVT_SUB(LW(0), 20)
    EVT_CALL(SetGoalPos, ACTOR_PARTNER, LW(0), LW(1), LW(2))
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 6, FALSE, FALSE, TRUE)
    EVT_SUB(LW(0), 10)
    EVT_CALL(JumpToGoal, ACTOR_PARTNER, 4, FALSE, FALSE, TRUE)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_F)
    EVT_WAIT(15)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_4)
    EVT_CALL(SetGoalToHome, ACTOR_PARTNER)
    EVT_CALL(SetActorSpeed, ACTOR_PARTNER, EVT_FLOAT(7.0))
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_6)
    EVT_CALL(RunToGoal, ACTOR_PARTNER, 0)
    EVT_CALL(SetAnimation, ACTOR_PARTNER, -1, NPC_ANIM_battle_kooper_Palette_00_Anim_4)
    EVT_CALL(EnableIdleScript, ACTOR_SELF, 1)
    EVT_CALL(UseIdleAnimation, ACTOR_SELF, TRUE)
    EVT_RETURN
    EVT_END
};
