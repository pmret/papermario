#include "common.h"

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

INCLUDE_ASM(s32, "battle/partner/kooper_6F5E80", func_80238298_6F6118);

INCLUDE_ASM(s32, "battle/partner/kooper_6F5E80", func_802383C0_6F6240);
