#include "common.h"
#include "battle/battle.h"

ApiStatus func_80238000_710EF0(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    script->varTable[0] = (s8) battleStatus->outtaSightActive;

    return ApiStatus_DONE2;
}

ApiStatus func_80238014_710F04(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* partnerTargetActor = get_actor(partnerActor->targetActorID);
    f32 partnerTargetActorSize = (partnerTargetActor->size.y + partnerTargetActor->size.x) >> 1;

    partnerTargetActorSize = (partnerTargetActorSize * 150.0f) / 100.0f;
    script->varTable[0] = partnerTargetActorSize;

    return ApiStatus_DONE2;
}

ApiStatus func_8023808C_710F7C(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->outtaSightActive = 1;
    if ((battleStatus->flags2 & 2) == 0) {
        battleStatus->outtaSightActive = -1;
    }

    battleStatus->hustleTurns = 0;
    battleStatus->flags1 &= ~0x04000000;

    return ApiStatus_DONE2;
}

ApiStatus func_802380E4_710FD4(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* playerActor = battleStatus->playerActor;
    f32 var0 = get_variable(script, *args++);
    f32 var1 = get_variable(script, *args++);
    f32 scalingFactor = playerActor->scalingFactor;

    script->varTable[0] += (var0 *= scalingFactor);
    script->varTable[1] += (var1 *= scalingFactor);

    return ApiStatus_DONE2;
}

ApiStatus func_80238198_711088(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    u8 var0 = playerActor->debuff - 3;
    s32 var1 = var0 < 6;

    if (playerActor->stoneStatus == 12) {
        var1 = 1;
    }
    script->varTable[0] = var1;

    return ApiStatus_DONE2;
}

ApiStatus func_802381C8_7110B8(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    ActorPart* playerActorPartTable = battleStatus->playerActor->partsTable;
    playerActorPartTable->idleAnimations = &bMarioIdleAnims;

    return ApiStatus_DONE2;
}

// Spook Attack Function
ApiStatus func_802381E8_7110D8(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor;
    ActorDesc* targetActorDesc;
    ActorPart* targetActorPart;
    s32 targetActorDescBaseStatusChance;
    s32 var0 = 0;
    s32 var1 = 0;
    s32 var2 = 0;

    for (var2; var2 < partnerActor->targetListLength; var2++) {
        targetActor = get_actor(partnerActor->targetData[var2].actorID);
        targetActorPart = get_actor_part(targetActor, partnerActor->targetData[var2].partID);
        targetActorDesc = targetActor->staticActorData;
        targetActorDescBaseStatusChance = targetActorDesc->baseStatusChance;

        if (targetActor->transStatus == 14) {
            targetActorDescBaseStatusChance = 0;
        }

        if (targetActorPart->eventFlags & 0x20) {
            targetActorDescBaseStatusChance = 0;
        }

        if (targetActorDescBaseStatusChance > 0) {
            var0 += targetActorDescBaseStatusChance;
            var1++;
        }
    }

    if (var1 > 0) {
        script->varTable[0] = (var0 / var1);
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}
