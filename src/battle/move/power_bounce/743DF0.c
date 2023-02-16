#include "common.h"
#include "battle/battle.h"

#define NAMESPACE battle_move_power_bounce

extern s32 D_802A2730_745520;

BSS s32 D_802A4020;

#include "world/common/todo/UnkMoveFunc1.inc.c"

API_CALLABLE(func_802A10E4_743ED4) {
    Actor* targetActor = get_actor(get_actor(script->owner1.actorID)->targetActorID);
    s32 powerBounceChance;

    script->varTable[0] = 99;
    powerBounceChance = targetActor->actorBlueprint->powerBounceChance;
    if (is_ability_active(ABILITY_DODGE_MASTER)) {
        powerBounceChance += 7;
    }
    D_802A2730_745520 = D_802A2730_745520 * powerBounceChance / 100;

    if (D_802A2730_745520 < rand_int(100)) {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(func_802A1194_743F84) {
    D_802A4020 = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802A11A4_743F94) {
    D_802A4020 += 1;
    return ApiStatus_DONE2;
}

API_CALLABLE(func_802A11C0_743FB0) {
    PlayerData* playerData = &gPlayerData;

    if (playerData->powerBounces < D_802A4020) {
        playerData->powerBounces = D_802A4020;
    }

    return ApiStatus_DONE2;
}
