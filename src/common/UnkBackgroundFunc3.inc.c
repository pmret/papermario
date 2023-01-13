#include "common.h"
#include "model.h"

ApiStatus N(UnkBackgroundFunc3)(Evt* script, s32 isInitialCall) {
    mdl_set_all_fog_mode(FOG_MODE_1);
    *gBackgroundFogModePtr = FOG_MODE_1;
    set_background_color_blend(0, 0, 0, 0);
    return ApiStatus_DONE2;
}
