#include "hos_04.h"

INCLUDE_ASM(s32, "world/area_hos/hos_04/A27AA0", func_80240BD0_A27AA0);

#if 0 // NON_MATCHING
ApiStatus N(func_80240E40_A27D10)(Evt* script, s32 isInitialCall) {
    switch_to_partner(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_hos/hos_04/A27AA0", func_80240E40_A27D10);
#endif

INCLUDE_ASM(s32, "world/area_hos/hos_04/A27AA0", func_80240E6C_A27D3C);
