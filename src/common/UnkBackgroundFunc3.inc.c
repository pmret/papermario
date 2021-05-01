#include "common.h"

ApiStatus N(UnkBackgroundFunc3)(ScriptInstance* script, s32 isInitialCall) {
    func_8011D82C(1);
    *D_801512F0 = 1;
    set_background_color_blend(0, 0, 0, 0);
    return ApiStatus_DONE2;
}
