#include "mac_04.h"

s32 set_background_color_blend(s32, s32, s32, s32);

ApiStatus func_802401C0_842D90(Evt* script, s32 isInitialCall) {
    func_8011B950(0x9E, -1, 1, 1);
    set_background_color_blend(0, 0, 0, 255);
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;
    return ApiStatus_DONE2;
}
