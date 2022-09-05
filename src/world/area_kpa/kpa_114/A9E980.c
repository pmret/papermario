#include "kpa_114.h"

ApiStatus func_80240000_A9E980(Evt* script, s32 isInitialCall) {
    sprintf((s8* ) &wMapShapeName, "kpa_112_shape");
    sprintf((s8* ) &wMapHitName, "kpa_112_hit\0kpa_113\0kpa_115");
    return ApiStatus_BLOCK;
}
