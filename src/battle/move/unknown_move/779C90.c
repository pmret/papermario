#include "common.h"

#include "battle/battle.h"

#define NAMESPACE battle_move_unknown_move

#include "world/common/UnkMoveFunc1.inc.c"

extern s32 D_802A26D0_77B360;

ApiStatus func_802A10E4_779D74(Evt* script, s32 isInitialCall) {
    Actor *enemyTargetActor;
    u32 enemyTargetPowerBounceChance;

    enemyTargetActor = get_actor(get_actor(script->owner1.enemyID)->targetActorID);

    script->varTable[0] = 99;

    enemyTargetPowerBounceChance = enemyTargetActor->actorBlueprint->powerBounceChance;

    if (is_ability_active(ABILITY_DODGE_MASTER)) {
        enemyTargetPowerBounceChance += 7;
    }

    D_802A26D0_77B360 *= enemyTargetPowerBounceChance;
    D_802A26D0_77B360 /= 100;

    if (D_802A26D0_77B360 < rand_int(100)) {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

