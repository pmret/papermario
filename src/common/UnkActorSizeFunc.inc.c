#include "battle/battle.h"

ApiStatus N(UnkActorSizeFunc)(Evt* script, s32 isInitialCall) {
    Actor* actor = get_actor(script->owner1.actorID);
    Actor* targetActor = get_actor(actor->targetActorID);
    s16 targetActorSizeX;
    u8 targetActorSizeY;
    u8 targetActorLargerDimension;

    if (!(targetActor->flags & ACTOR_FLAG_HP_OFFSET_BELOW)) {
        script->varTable[1] += targetActor->size.y / 2;
        script->varTable[1] += targetActor->size.y / 4;
    } else {
        script->varTable[1] -= targetActor->size.y / 2;
        script->varTable[1] -= targetActor->size.y / 4;
    }

    targetActorSizeY = targetActor->size.y;
    targetActorSizeX = targetActor->size.x;
    targetActorLargerDimension = targetActorSizeY;
    if (targetActorSizeY < targetActorSizeX) {
        targetActorLargerDimension = targetActorSizeX;
    }
    
    script->varTable[3] = targetActorLargerDimension + 126;
    return ApiStatus_DONE2;
}
