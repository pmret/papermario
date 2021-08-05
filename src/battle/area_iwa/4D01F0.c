#include "common.h"
#include "battle/battle.h"

#define NAMESPACE b_area_iwa

// allow_spin_smash
ApiStatus func_80218000_4D01F0(ScriptInstance* script, s32 isInitialCall) {
    s32 canSpinSmash = get_variable(script, *script->ptrReadPos);
    Actor *actor = get_actor(script->owner1.actorID);
    if (canSpinSmash == FALSE) {
        actor->staticActorData->spinSmashReq = 4;
    } else {
        actor->staticActorData->spinSmashReq = 0;
    }

    return ApiStatus_DONE2;
}

#include "common/StartRumbleWithParams.inc.c"
