#include "common.h"

ApiStatus N(UnkFogFunc)(Evt* script, s32 isInitialCall) {
    set_world_fog_dist(980, 1000);
    set_world_fog_color(15, 5, 55, 255);
    enable_world_fog();
    return ApiStatus_DONE2;
}
