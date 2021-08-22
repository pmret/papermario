#include "common.h"
#include "battle/battle.h"

#define NAMESPACE battle_move_power_bounce

extern s32* D_802A2730_745520;
extern s32 D_802A4020;

#include "world/common/UnkMoveFunc1.inc.c"

#ifdef NON_MATCHING
ApiStatus func_802A10E4_743ED4(Evt* script, s32 isInitialCall) {
    Actor* targetActor = get_actor(get_actor(script->owner1.actorID)->targetActorID);
    s32 powerBounceChance;

    script->varTable[0] = 99;
    powerBounceChance = targetActor->staticActorData->powerBounceChance;
    if (is_ability_active(ABILITY_DODGE_MASTER)) {
        powerBounceChance += 7;
    }

    if ((*D_802A2730_745520 * powerBounceChance) / 100 < rand_int(100)) {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "battle/move/power_bounce/743DF0", func_802A10E4_743ED4);
#endif

ApiStatus func_802A1194_743F84(Evt* script, s32 isInitialCall) {
    D_802A4020 = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_802A11A4_743F94(Evt* script, s32 isInitialCall) {
    D_802A4020 += 1;
    return ApiStatus_DONE2;
}

ApiStatus func_802A11C0_743FB0(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    if (playerData->powerBounces < D_802A4020) {
        playerData->powerBounces = D_802A4020;
    }

    return ApiStatus_DONE2;
}
