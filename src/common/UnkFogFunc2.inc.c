#include "common.h"

ApiStatus N(UnkFogFunc2)(Evt* script, s32 isInitialCall) {
    enable_world_fog();
    set_world_fog_dist(950, 1000);
    set_world_fog_color(16, 16, 16, 255);
    gCameras[CAM_BATTLE].bgColor[0] = 20;
    gCameras[CAM_BATTLE].bgColor[1] = 20;
    gCameras[CAM_BATTLE].bgColor[2] = 28;

    return ApiStatus_DONE2;
}
