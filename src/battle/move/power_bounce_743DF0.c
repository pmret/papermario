#include "common.h"
#include "battle/battle.h"

#define NAMESPACE battle_move_power_bounce

extern s32* D_802A2730_745520;

#include "world/common/UnkMoveFunc1.inc.c"

#ifdef NON_MATCHING
ApiStatus func_802A10E4_743ED4(ScriptInstance* script, s32 isInitialCall) {
    Actor* actor = get_actor(script->owner1.actorID);
    Actor* targetActor = get_actor(actor->targetActorID);
    u8 powerBounceChance;

    script->varTable[0] = 99;
    powerBounceChance = targetActor->staticActorData->powerBounceChance;
    if (is_ability_active(Ability_DODGE_MASTER)) {
        powerBounceChance += 7;
    }

    if ((*D_802A2730_745520 * powerBounceChance) / 100 < rand_int(100)) {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "battle/move/power_bounce_743DF0", func_802A10E4_743ED4);
#endif


INCLUDE_ASM(s32, "battle/move/power_bounce_743DF0", func_802A1194_743F84);

INCLUDE_ASM(s32, "battle/move/power_bounce_743DF0", func_802A11A4_743F94);

INCLUDE_ASM(s32, "battle/move/power_bounce_743DF0", func_802A11C0_743FB0);
