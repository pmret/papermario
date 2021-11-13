#include "kzn_19.h"

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

#include "world/common/StarSpiritEffectFunc.inc.c"

static char* N(exit_str_0) = "kmr_23";
static char* N(exit_str_1) = "kzn_18";
static char* N(exit_str_2) = "kzn_20";

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240B00_C8E6B0);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240BD4_C8E784);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240CD8_C8E888);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240DA4_C8E954);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80240E2C_C8E9DC);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_802413C0_C8EF70);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_802413FC_C8EFAC);

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_8024140C_C8EFBC);

#if 0 // NON_MATCHING
ApiStatus N(func_80241468_C8F018)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80243D74_C91924) == NULL) {
        N(D_80243D74_C91924) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80243D74_C91924)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80243D74_C91924)[i];
        }
        heap_free(N(D_80243D74_C91924));
        N(D_80243D74_C91924) = NULL;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241468_C8F018);
#endif

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

#if 0 // NON_MATCHING
ApiStatus N(func_802417AC_C8F35C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80243DD8_C91988) = FALSE;
    }

    if (N(D_80243DD8_C91988)) {
        N(D_80243DD8_C91988) = FALSE;
        evt_set_variable(script, *args, N(D_80243DDC_C9198C));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_802417AC_C8F35C);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_80241800_C8F3B0)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80243DDC_C9198C) = evt_get_variable(script, *args);
    N(D_80243DD8_C91988) = TRUE;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241800_C8F3B0);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_80241838_C8F3E8)(Evt* script, s32 isInitialCall) {
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
INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241838_C8F3E8);
#endif

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

#if 0 // NON_MATCHING
ApiStatus N(func_80241B50_C8F700)(Evt *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241B50_C8F700);
#endif

#if 0 // NON_MATCHING
ApiStatus N(func_80241B94_C8F744)(Evt *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241B94_C8F744);
#endif

INCLUDE_ASM(s32, "world/area_kzn/kzn_19/C8DBB0", func_80241BC0_C8F770);
