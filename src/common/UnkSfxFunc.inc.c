#include "common.h"

ApiStatus N(UnkSfxFunc)(Evt* script, s32 isInitialCall) {
    Actor* actor = get_actor(script->owner1.actorID);
    f32 distX;
    f32 distY;
    f32 distZ;

    if (isInitialCall) {
        distX = actor->state.goalPos.x - actor->currentPos.x;
        distY = actor->state.goalPos.y - actor->currentPos.y;
        distZ = actor->state.goalPos.z - actor->currentPos.z;
        script->functionTemp[0] = ((sqrtf(SQ(distX) + SQ(distY) + SQ(distZ)) / actor->state.speed) * 0.5f) + 1.0f;
        sfx_play_sound_at_position(SOUND_UNKNOWN_359, 0.0f, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z);
    }

    if (script->functionTemp[0]-- > 0) {
        return ApiStatus_BLOCK;
    }

    sfx_play_sound_at_position(SOUND_UNKNOWN_759, 0, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z);
    return ApiStatus_DONE2;
}
