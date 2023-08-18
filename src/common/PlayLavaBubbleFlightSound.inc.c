#include "common.h"

API_CALLABLE(N(PlayLavaBubbleFlightSound)) {
    Actor* actor = get_actor(script->owner1.actorID);
    f32 distX;
    f32 distY;
    f32 distZ;
    f32 dist;

    if (isInitialCall) {
        distX = actor->state.goalPos.x - actor->curPos.x;
        distY = actor->state.goalPos.y - actor->curPos.y;
        distZ = actor->state.goalPos.z - actor->curPos.z;
        dist = sqrtf(SQ(distX) + SQ(distY) + SQ(distZ));
        script->functionTemp[0] = ((dist / actor->state.speed) * 0.5f) + 1.0f;
        sfx_play_sound_at_position(SOUND_EMBER_FLY, SOUND_SPACE_DEFAULT, actor->curPos.x, actor->curPos.y, actor->curPos.z);
    }

    if (script->functionTemp[0]-- > 0) {
        return ApiStatus_BLOCK;
    }

    sfx_play_sound_at_position(SOUND_EMBER_FLY | SOUND_ID_TRIGGER_CHANGE_SOUND, SOUND_SPACE_DEFAULT, actor->curPos.x, actor->curPos.y, actor->curPos.z);
    return ApiStatus_DONE2;
}
