#define NAMESPACE battle_partner_bow

#include "common.h"
#include "battle/battle.h"

extern s32 bMarioIdleAnims[];
extern s32 bMarioHideAnims[];

ApiStatus func_80238000_710EF0(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    script->varTable[0] = battleStatus->outtaSightActive;

    return ApiStatus_DONE2;
}

ApiStatus func_80238014_710F04(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* partnerTargetActor = get_actor(partnerActor->targetActorID);
    f32 partnerTargetActorSize = (partnerTargetActor->size.y + partnerTargetActor->size.x) / 2;

    partnerTargetActorSize = (partnerTargetActorSize * 150.0f) / 100.0f;
    script->varTable[0] = partnerTargetActorSize;

    return ApiStatus_DONE2;
}

ApiStatus func_8023808C_710F7C(ScriptInstance* script, s32 isInitialCall) {
    ActorPart* playerActorPartTable = gBattleStatus.playerActor->partsTable;

    gBattleStatus.outtaSightActive = 1;
    if (!(gBattleStatus.flags2 & 2)) {
        gBattleStatus.outtaSightActive = -1;
    } 

    playerActorPartTable->idleAnimations = &bMarioHideAnims;
    gBattleStatus.hustleTurns = 0;
    gBattleStatus.flags1 &= ~0x04000000;

    return ApiStatus_DONE2;
}

ApiStatus func_802380E4_710FD4(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* playerActor = battleStatus->playerActor;
    f32 var0 = get_variable(script, *args++);
    f32 var1 = get_variable(script, *args++);
    f32 scalingFactor = playerActor->scalingFactor;

    var0 *= scalingFactor;
    script->varTable[0] += var0;

    var1 *= scalingFactor;
    script->varTable[1] += var1;

    return ApiStatus_DONE2;
}

/// Duplicate of IsPartnerImmobile
ApiStatus N(IsPartnerImmobile)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    s32 isImmobile = playerActor->debuff == STATUS_FEAR
                     || playerActor->debuff == STATUS_DIZZY
                     || playerActor->debuff == STATUS_PARALYZE
                     || playerActor->debuff == STATUS_SLEEP
                     || playerActor->debuff == STATUS_FROZEN
                     || playerActor->debuff == STATUS_STOP;

    if (playerActor->stoneStatus == 12) {
        isImmobile = TRUE;
    }

    script->varTable[0] = isImmobile;
    return ApiStatus_DONE2;
}

ApiStatus func_802381C8_7110B8(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    ActorPart* playerActorPartTable = battleStatus->playerActor->partsTable;
    playerActorPartTable->idleAnimations = &bMarioIdleAnims;

    return ApiStatus_DONE2;
}

/// Averages the baseStatusChance of the hittable actors this partner is targeting.
ApiStatus N(AverageTargetStatusChance)(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor;
    ActorDesc* targetActorDesc;
    ActorPart* targetActorPart;
    s32 targetActorDescBaseStatusChance;
    s32 chanceTotal = 0;
    s32 nTargets = 0;
    s32 i;

    for (i = 0; i < partnerActor->targetListLength; i++) {
        targetActor = get_actor(partnerActor->targetData[i].actorID);
        targetActorPart = get_actor_part(targetActor, partnerActor->targetData[i].partID);
        targetActorDesc = targetActor->staticActorData;
        targetActorDescBaseStatusChance = targetActorDesc->baseStatusChance;

        if (targetActor->transStatus == 14) {
            targetActorDescBaseStatusChance = 0;
        }

        if (targetActorPart->eventFlags & 0x20) {
            targetActorDescBaseStatusChance = 0;
        }

        if (targetActorDescBaseStatusChance > 0) {
            chanceTotal += targetActorDescBaseStatusChance;
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
