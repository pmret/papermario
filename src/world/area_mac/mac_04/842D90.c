#include "mac_04.h"

// matches if func_8011B950 is declared to return s32, but that breaks other funcs
#ifdef NON_MATCHING
ApiStatus func_802401C0_842D90(Evt* script, s32 isInitialCall) {
    func_8011B950(0x9E, -1, 1, 1);
    set_background_color_blend(0, 0, 0, 255);
    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_mac/mac_04/842D90", func_802401C0_842D90);
#endif
