#include "common.h"
#include "battle/battle.h"

void dispatch_event_partner(s8 lastEventType) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    ScriptInstance* onHitScript = partnerActor->onHitScript;
    ScriptID onHitID = partnerActor->onHitID;
    ScriptInstance* script;

    partnerActor->lastEventType = lastEventType;
    script = start_script(partnerActor->onHitCode, 10, 0x20);
    partnerActor->onHitScript = script;
    partnerActor->onHitID = script->id;
    script->owner1.actorID = ActorID_PARTNER;

    if (partnerActor->takeTurnScript != NULL) {
        kill_script_by_ID(partnerActor->takeTurnID);
        partnerActor->takeTurnScript = NULL;
    }

    if (onHitScript != NULL) {
        kill_script_by_ID(onHitID);
    }
}

void dispatch_event_partner_continue_turn(s8 lastEventType) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    ScriptInstance* onHitScript = partnerActor->onHitScript;
    ScriptID onHitID = partnerActor->onHitID;
    ScriptInstance* script;

    partnerActor->lastEventType = lastEventType;
    script = start_script(partnerActor->onHitCode, 10, 0x20);
    partnerActor->onHitScript = script;
    partnerActor->onHitID = script->id;
    script->owner1.actorID = ActorID_PARTNER;

    if (onHitScript != NULL) {
        kill_script_by_ID(onHitID);
    }
}

INCLUDE_ASM(s32, "code_1AC760", calc_partner_test_enemy);

INCLUDE_ASM(s32, "code_1AC760", calc_partner_damage_enemy);

INCLUDE_ASM(s32, "code_1AC760", dispatch_damage_event_partner);

s32 dispatch_damage_event_partner_0(s32 damageAmount, s32 event, s32 stopMotion) {
    return dispatch_damage_event_partner(damageAmount, event, FALSE);
}

s32 dispatch_damage_event_partner_1(s32 damageAmount, s32 event, s32 stopMotion) {
    return dispatch_damage_event_partner(damageAmount, event, TRUE);
}

ApiStatus MakeOwnerTargetIndex(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    s32 numTargets = actor->targetListLength;
    s8* targetList = &actor->targetIndexList;
    s32 arg1 = get_variable(script, *args++);
    s32 arg2 = get_variable(script, *args++);
    s32 otherArg = *args++;
    SelectableTarget* selectableTarget;

    if (numTargets == 0) {
        arg2 = -1;
    } else {
        if (arg2 != 0) {
            if (arg2 >= numTargets) {
                arg2 = numTargets - 1;
            } else {
                arg2--;
            }
        }

        selectableTarget = &actor->targetData[targetList[arg2]];
        actor->targetActorID = selectableTarget->actorID;
        actor->targetPartIndex = selectableTarget->partID;
    }
    
    set_variable(script, otherArg, arg2);
    return ApiStatus_DONE2;
}

s32 calc_partner_damage_enemy(void);

ApiStatus func_8027FC90(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hitResult;
    Actor* actor;
    ActorID actorID = get_variable(script, *args++);
    s32 outVar;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.enemyID;
    }

    outVar = *args++;
    actor = get_actor(actorID);
    battleStatus->flags1 |= 0x20;

    hitResult = calc_partner_damage_enemy();
    show_damage_popup(actor->walk.goalPos.x, actor->walk.goalPos.y, actor->walk.goalPos.z, battleStatus->lastAttackDamage, 0);
    set_variable(script, outVar, hitResult);

    return ApiStatus_DONE2;
}

ApiStatus GetActorLevel(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Bytecode* outVar;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.enemyID;
    }

    outVar = *args++;
    set_variable(script, outVar, get_actor(actorID)->staticActorData->level);

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1AC760", PartnerDamageEnemy);

INCLUDE_ASM(s32, "code_1AC760", PartnerAfflictEnemy);

INCLUDE_ASM(s32, "code_1AC760", PartnerPowerBounceEnemy);

INCLUDE_ASM(s32, "code_1AC760", PartnerTestEnemy);

ApiStatus func_8028070C(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    s32 damageAmount = get_variable(script, *args++);
    s32 event = get_variable(script, *args++);

    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;

    if (dispatch_damage_event_partner_0(damageAmount, event, battleStatus) >= 0) {
        return does_script_exist_by_ref(script) ? ApiStatus_DONE2 : ApiStatus_BLOCK;
    }

    return ApiStatus_BLOCK;
}

ApiStatus DeletePartner(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    delete_actor(battleStatus->partnerActor);
    return ApiStatus_DONE2;
}

ApiStatus func_802807D0(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var = *script->ptrReadPos;
    s32 actionSuccess = battleStatus->actionSuccess;
    s32 outVal = 0;

    if (actionSuccess < outVal) {
        actionSuccess = outVal;
    }

    if (actionSuccess > outVal) {
        outVal = actionSuccess;
    }

    set_variable(script, var, outVal);
    return ApiStatus_DONE2;
}

/// Seems to be the same functionality as YieldTurn in code_1A5830.c
ApiStatus func_80280818(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= 0x200000;
    return ApiStatus_DONE2;
}
