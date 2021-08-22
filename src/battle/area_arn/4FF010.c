#include "battle/battle.h"

#define NAMESPACE b_area_arn

#define NAMESPACE dup2_b_area_arn
#include "common/StartRumbleWithParams.inc.c"
#define NAMESPACE b_area_arn

ApiStatus func_80218618_4FF068(Evt* script, s32 isInitialCall) {
    s32 temp_s0 = get_variable(script, *script->ptrReadPos);
    Actor* actor = get_actor(script->owner1.actorID);

    if (temp_s0 == 0) {
        actor->staticActorData->spinSmashReq = 4;
    } else {
        actor->staticActorData->spinSmashReq = 0;
    }

    return ApiStatus_DONE2;
}
