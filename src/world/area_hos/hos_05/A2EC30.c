#include "hos_05.h"

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2EC30", func_802449F0_A2EC30);

#if 0 // NON_MATCHING
ApiStatus N(func_80244C60_A2EEA0)(Evt* script, s32 isInitialCall) {
    switch_to_partner(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_hos/hos_05/A2EC30", func_80244C60_A2EEA0);
#endif

INCLUDE_ASM(s32, "world/area_hos/hos_05/A2EC30", func_80244C8C_A2EECC);
