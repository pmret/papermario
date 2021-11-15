#include "battle/battle.h"

ApiStatus N(UnkActorPosFunc)(Evt* script, s32 isInitialCall) {
    Actor* actor = get_actor(script->owner1.actorID);
    ActorState* actorState = &actor->state;

    if (isInitialCall) {
        actor->state.currentPos.x = actor->currentPos.x;
        actor->state.currentPos.y = actor->currentPos.y;
        actor->state.currentPos.z = actor->currentPos.z;
    }

    add_xz_vec3f(&actorState->currentPos, actor->state.speed, actor->state.angle);
    if (actor->state.speed < 4.0f) {
        play_movement_dust_effects(0, actor->state.currentPos.x, actor->state.currentPos.y, actor->state.currentPos.z, actor->state.angle);
    } else {
        play_movement_dust_effects(1, actor->state.currentPos.x, actor->state.currentPos.y, actor->state.currentPos.z, actor->state.angle);
    }
    
    actorState->speed /= 1.5;
    actor->currentPos.x = actorState->currentPos.x;
    actor->currentPos.y = actorState->currentPos.y;
    actor->currentPos.z = actorState->currentPos.z;

    if (actorState->speed < 1.0) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
