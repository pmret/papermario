#include "common.h"
#include "battle/battle.h"

ApiStatus func_80238000_6F5E80(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    ActorMovement* partnerActorMovement = &partnerActor->walk;

    if (isInitialCall) {
        partnerActor->walk.currentPos.x = partnerActor->currentPos.x;
        partnerActor->walk.currentPos.y = partnerActor->currentPos.y;
        partnerActor->walk.currentPos.z = partnerActor->currentPos.z;
    }

    add_xz_vec3f(&partnerActorMovement->currentPos, partnerActor->walk.speed, partnerActor->walk.angle);

    if (partnerActor->walk.speed < 4.0f) {
        play_movement_dust_effects(0, partnerActor->walk.currentPos.x, partnerActor->walk.currentPos.y, partnerActor->walk.currentPos.z, partnerActor->walk.angle);
    } else {
        play_movement_dust_effects(1, partnerActor->walk.currentPos.x, partnerActor->walk.currentPos.y, partnerActor->walk.currentPos.z, partnerActor->walk.angle);
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

INCLUDE_ASM(s32, "battle/partner/kooper_6F5E80", func_80238114_6F5F94);

ApiStatus func_80238298_6F6118(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Actor* targetActor;
    ActorPart* targetActorPart;
    s32 targetActorDescBaseStatusChance;
    s32 var0 = 0;
    s32 var1 = 0;
    s32 var2 = 0;

    for (var2; var2 < partnerActor->targetListLength; var2++) {
        targetActor = get_actor(partnerActor->targetData[var2].actorID);
        targetActorPart = get_actor_part(targetActor, partnerActor->targetData[var2].partID);
        targetActorDescBaseStatusChance = lookup_status_chance(targetActor->statusTable, 4);

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

ApiStatus func_802383C0_6F6240(ScriptInstance* script, s32 isInitialCall) {
    s32 var0 = script->varTable[0];
    s32 var1;
    s32 var2;

    if (var0 < 0x24) {
        var1 = 1;
        var2 = 0;
    } else if (var0 < 0x3D) {
        var1 = 3;
        var2 = 1;
    } else if (var0 < 0x51) {
        var1 = 4;
        var2 = 2;
    } else if (var0 < 0x64) {
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
