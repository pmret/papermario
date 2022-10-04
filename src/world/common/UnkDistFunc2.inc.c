#include "common.h"

ApiStatus N(UnkDistFunc2)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 distance = dist2D(
        playerStatus->position.x, playerStatus->position.z,
        script->array[2], script->array[4]);
    
    script->varTable[0] = 0;
    if (distance < 112.5f) {
        script->varTable[0] = 2;
    }
    if (distance < 37.5f) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}
