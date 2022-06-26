#include "nok_13.h"

INCLUDE_ASM(s32, "world/area_nok/nok_13/A01420", func_80240E20_A01420);

ApiStatus func_80241360_A01960(Evt* script) {
    Bytecode* args = script->ptrReadPos;
    s32 a0 = *args++;

    evt_set_variable(script, a0, atan2(-364.0f, -135.0f, gPlayerStatus.position.x, gPlayerStatus.position.z));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_nok/nok_13/A01420", func_802413CC_A019CC);
