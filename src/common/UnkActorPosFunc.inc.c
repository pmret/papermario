#include "battle/battle.h"

API_CALLABLE(N(UnkActorPosFunc)) {
    Actor* actor = get_actor(script->owner1.actorID);
    ActorState* actorState = &actor->state;

    if (isInitialCall) {
        actor->state.curPos.x = actor->curPos.x;
        actor->state.curPos.y = actor->curPos.y;
        actor->state.curPos.z = actor->curPos.z;
    }

    add_xz_vec3f(&actorState->curPos, actor->state.speed, actor->state.angle);
    if (actor->state.speed < 4.0f) {
        play_movement_dust_effects(0, actor->state.curPos.x, actor->state.curPos.y, actor->state.curPos.z, actor->state.angle);
    } else {
        play_movement_dust_effects(1, actor->state.curPos.x, actor->state.curPos.y, actor->state.curPos.z, actor->state.angle);
    }

    actorState->speed /= 1.5;
    actor->curPos.x = actorState->curPos.x;
    actor->curPos.y = actorState->curPos.y;
    actor->curPos.z = actorState->curPos.z;

    if (actorState->speed < 1.0) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
