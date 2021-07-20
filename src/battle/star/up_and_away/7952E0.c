#include "common.h"
#include "battle/battle.h"

#define NAMESPACE battle_star_up_and_away

#include "common/StarPower.inc.c"

ApiStatus func_802A1518_7957F8(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        mdl_set_all_fog_mode(1);
        *D_801512F0 = 1;
        set_background_color_blend(0, 0, 0, 0);
        script->functionTemp[0] = 200;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0]);
    script->functionTemp[0] += 2;

    if (script->functionTemp[0] >= 254) {
        set_background_color_blend(0, 0, 0, 254);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802A15B4_795894(ScriptInstance* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 254;
    }

    set_background_color_blend(0, 0, 0, script->functionTemp[0]);
    script->functionTemp[0] -= 5;

    if (script->functionTemp[0] <= 200) {
        set_background_color_blend(0, 0, 0, 200);

        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

#ifdef NON_MATCHING
ApiStatus func_802A1628_795908(ScriptInstance* script, s32 isInitialCall) {
    Actor* targetActor = get_actor(get_actor(script->owner1.actorID)->targetActorID);
    s32 flags = targetActor->flags;

    script->varTable[0] = 0;

    if ((flags & 0x4000) == NULL && (flags & 0x400000) == NULL && (flags & 0x2000) == NULL && targetActor->staticActorData->upAndAwayChance != 0 && targetActor->staticActorData->upAndAwayChance >= rand_int(100)) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}
#else
    INCLUDE_ASM(s32, "battle/star/up_and_away/7952E0", func_802A1628_795908);
#endif
