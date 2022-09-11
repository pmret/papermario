#include "kmr_20.h"

#define NAMESPACE dup_kmr_20
#include "world/common/atomic/Pipe.inc.c"
#define NAMESPACE kmr_20

#define NAMESPACE dup3_kmr_20
#include "common/foliage.inc.c"
#define NAMESPACE kmr_20

ApiStatus func_80241C9C_8EDABC(Evt* script, s32 isInitialCall) {
    func_8011B950(269, -1, 1, 1);
    set_background_color_blend(0, 0, 0, 255);

    gCameras[CAM_DEFAULT].bgColor[0] = 0;
    gCameras[CAM_DEFAULT].bgColor[1] = 0;
    gCameras[CAM_DEFAULT].bgColor[2] = 0;

    return ApiStatus_DONE2;
}

ApiStatus func_80241CF0_8EDB10(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    gCameras[CAM_DEFAULT].moveSpeed = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_80241D1C_8EDB3C(Evt* script, s32 isInitialCall) {
    au_ambience_set_volume(0, 1000, 0x3F);
    return ApiStatus_DONE2;
}
