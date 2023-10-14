#include "common.h"

API_CALLABLE(N(ActorJumpToPos)) {
    Actor* actor = get_actor(script->owner1.actorID);
    Vec3f* temp_f0 = &actor->state.curPos;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }
    if (script->functionTemp[0] == 0) {
        actor->state.curPos.x = actor->curPos.x;
        actor->state.curPos.y = actor->curPos.y;
        actor->state.curPos.z = actor->curPos.z;
        script->functionTemp[0] = 1;
    }

    if (actor->state.vel > 0.0f) {
        set_actor_anim(ACTOR_SELF, 1, actor->state.animJumpRise);
    }
    if (actor->state.vel < 0.0f) {
        set_actor_anim(ACTOR_SELF, 1, actor->state.animJumpFall);
    }

    actor->state.curPos.y += actor->state.vel;
    actor->state.vel = actor->state.vel - actor->state.acceleration;
    add_xz_vec3f(temp_f0, actor->state.speed, actor->state.angle);
    actor->curPos.x = actor->state.curPos.x;
    actor->curPos.y = actor->state.curPos.y;
    actor->curPos.z = actor->state.curPos.z;

    if (actor->curPos.y < 0.0f) {
        actor->curPos.y = 0.0f;
        play_movement_dust_effects(2, actor->curPos.x, actor->curPos.y, actor->curPos.z, actor->yaw);
        sfx_play_sound(SOUND_LAND_SOFTLY);
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}
