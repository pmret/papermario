#include "common.h"

ApiStatus N(ActorJumpToPos)(Evt* script, s32 isInitialCall) {
    Actor* actor = get_actor(script->owner1.actorID);
    Vec3f* temp_f0 = &actor->state.currentPos;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }
    if (script->functionTemp[0] == 0) {
        actor->state.currentPos.x = actor->currentPos.x;
        actor->state.currentPos.y = actor->currentPos.y;
        actor->state.currentPos.z = actor->currentPos.z;
        script->functionTemp[0] = 1;
    }

    if (actor->state.velocity > 0.0f) {
        set_animation(ACTOR_SELF, 1, actor->state.animJumpRise);
    }
    if (actor->state.velocity < 0.0f) {
        set_animation(ACTOR_SELF, 1, actor->state.animJumpFall);
    }

    actor->state.currentPos.y += actor->state.velocity;
    actor->state.velocity = actor->state.velocity - actor->state.acceleration;
    add_xz_vec3f(temp_f0, actor->state.speed, actor->state.angle);
    actor->currentPos.x = actor->state.currentPos.x;
    actor->currentPos.y = actor->state.currentPos.y;
    actor->currentPos.z = actor->state.currentPos.z;

    if (actor->currentPos.y < 0.0f) {
        actor->currentPos.y = 0.0f;
        play_movement_dust_effects(2, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z, actor->yaw);
        sfx_play_sound(SOUND_SOFT_LAND);
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}
