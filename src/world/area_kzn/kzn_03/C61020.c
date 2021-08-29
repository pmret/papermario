#include "kzn_03.h"

#include "world/common/set_script_owner_npc_anim.inc.c"

#include "world/common/UnkDistFunc.inc.c"

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_802406A4_C613B4);

#include "world/common/AwaitPlayerNearNpc.inc.c"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

#include "world/common/UnkNpcAIFunc26.inc.c"

#include "world/common/UnkFunc7.inc.c"

#include "world/common/UnkNpcAIFunc27.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_802414C8_C621D8);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80241534_C62244);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80241630_C62340);

#include "world/common/UnkNpcDurationFlagFunc3.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242100_C62E10);

#include "world/common/UnkNpcDurationFlagFunc2.inc.c"

#include "world/common/UnkNpcAIFunc30.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_8024234C_C6305C);

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_8024259C_C632AC);
/*
ApiStatus N(func_8024259C_C632AC)(Evt* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802441A0_C64EB0) == NULL) {
        N(D_802441A0_C64EB0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802441A0_C64EB0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802441A0_C64EB0)[i];
        }
        heap_free(N(D_802441A0_C64EB0));
        N(D_802441A0_C64EB0) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_802428E0_C635F0);
/*
ApiStatus N(func_802428E0_C635F0)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80244204_C64F14) = FALSE;
    }

    if (N(D_80244204_C64F14)) {
        N(D_80244204_C64F14) = FALSE;
        evt_set_variable(script, *args, N(D_80244208_C64F18));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242934_C63644);
/*
ApiStatus N(func_80242934_C63644)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80244208_C64F18) = evt_get_variable(script, *args);
    N(D_80244204_C64F14) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_8024296C_C6367C);
/*
ApiStatus N(func_8024296C_C6367C)(Evt* script, s32 isInitialCall) {
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
*/

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242C84_C63994);
/*
ApiStatus N(func_80242C84_C63994)(Evt *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_03/C61020", func_80242CC8_C639D8);
/*
ApiStatus N(func_80242CC8_C639D8)(Evt *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/
