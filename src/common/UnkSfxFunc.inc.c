#include "common.h"

API_CALLABLE(N(UnkSfxFunc)) {
    Actor* actor = get_actor(script->owner1.actorID);
    f32 distX;
    f32 distY;
    f32 distZ;

    if (isInitialCall) {
        distX = actor->state.goalPos.x - actor->curPos.x;
        distY = actor->state.goalPos.y - actor->curPos.y;
        distZ = actor->state.goalPos.z - actor->curPos.z;
        script->functionTemp[0] = ((sqrtf(SQ(distX) + SQ(distY) + SQ(distZ)) / actor->state.speed) * 0.5f) + 1.0f;
        sfx_play_sound_at_position(SOUND_359, SOUND_SPACE_MODE_0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
    }

    if (script->functionTemp[0]-- > 0) {
        return ApiStatus_BLOCK;
    }

    sfx_play_sound_at_position(SOUND_359 | SOUND_ID_TRIGGER_CHANGE_SOUND, SOUND_SPACE_MODE_0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
    return ApiStatus_DONE2;
}
