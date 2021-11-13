#include "jan_00.h"
#include "effects.h"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_8024030C_B2084C);

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240340_B20880);

#if 0 // NON_MATCHING
ApiStatus N(func_802403F4_B20934)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802423C8_B22908) == NULL) {
        N(D_802423C8_B22908) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802423C8_B22908)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802423C8_B22908)[i];
        }
        heap_free(N(D_802423C8_B22908));
        N(D_802423C8_B22908) = NULL;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_802403F4_B20934);
#endif

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

#if 0 // NON_MATCHING
ApiStatus N(func_80240738_B20C78)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_8024242C_B2296C) = FALSE;
    }

    if (N(D_8024242C_B2296C)) {
        N(D_8024242C_B2296C) = FALSE;
        evt_set_variable(script, *args, N(D_80242430_B22970));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240738_B20C78);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_8024078C_B20CCC)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80242430_B22970) = evt_get_variable(script, *args);
    N(D_8024242C_B2296C) = TRUE;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_8024078C_B20CCC);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_802407C4_B20D04)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_80244A20)[i] = i + 16;
            N(D_80244A20)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_802407C4_B20D04);
#endif

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

#if 0 // NON_MATCHING
ApiStatus N(func_80240ADC_B2101C)(Evt *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240ADC_B2101C);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_80240B20_B21060)(Evt *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240B20_B21060);
#endif

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240B4C_B2108C);

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240CF8_B21238);

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80240F14_B21454);

INCLUDE_ASM(s32, "world/area_jan/jan_00/B20540", func_80241134_B21674);
