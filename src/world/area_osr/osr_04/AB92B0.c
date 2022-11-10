#include "osr_04.h"

ApiStatus func_80240000_AB92B0(Evt *script, s32 isInitialCall) {
    gGameStatusPtr->playerSpriteSet = 2;
    sprintf(wMapShapeName, "osr_03_shape");
    sprintf(wMapHitName, "osr_03_hit");
    return ApiStatus_BLOCK;
}

const char* N(exit_str_0) = "kkj_03";

ApiStatus func_80240050_AB9300(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    evt_set_variable(script, *args++, (sin_deg(evt_get_variable(script, *args)) * 20.0f));
    return ApiStatus_DONE2;
}
