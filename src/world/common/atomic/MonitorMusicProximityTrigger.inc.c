#include "common.h"
#include "npc.h"

/*
    The current BGM can be modified based on the player's proximity to a specified point.
    When closer than the inner distance, the modified tracks(?) play at half volume. If the
    player moves beyond the outer distance, the modified tracks are muted.
    Setting an event flags overries the normal music with the modified music until the outer
    distance is exceeded.
*/
API_CALLABLE(N(MonitorMusicProximityTrigger)) {
    Bytecode* args = script->ptrReadPos;
    MusicProximityTrigger* trigger;
    s32 cond = false;
    f32 dist;

    if (isInitialCall) {
        script->functionTemp[0] = evt_get_variable(script, *args);
        script->functionTemp[1] = MUSIC_PROXIMITY_FAR;
        script->functionTemp[2] = ((MusicProximityTrigger*)(script->functionTemp[0]))->manualActivationFlag;
    }

    trigger = script->functionTempPtr[0];

    if (evt_get_variable(script, script->functionTemp[2])) {
        if (script->functionTemp[1] != MUSIC_PROXIMITY_FULL) {
            script->functionTemp[1] = MUSIC_PROXIMITY_FULL;
            cond = true;
        }
    } else {
        dist = dist2D(gPlayerStatusPtr->pos.x, gPlayerStatusPtr->pos.z, trigger->pos.x, trigger->pos.z);

        switch (script->functionTemp[1]) {
            case MUSIC_PROXIMITY_FAR:
                if (dist < trigger->innerDist) {
                    script->functionTemp[1] = MUSIC_PROXIMITY_NEAR;
                    cond = true;
                }
                break;
            case MUSIC_PROXIMITY_NEAR:
                if (dist > trigger->outerDist) {
                    script->functionTemp[1] = MUSIC_PROXIMITY_FAR;
                    cond = true;
                }
                break;
            case MUSIC_PROXIMITY_FULL:
                script->functionTemp[1] = MUSIC_PROXIMITY_NEAR;
                cond = true;
                break;
        }
    }

    if (cond) {
        bgm_adjust_proximity(0, trigger->mix, script->functionTemp[1]);
    }

    return ApiStatus_BLOCK;
}
