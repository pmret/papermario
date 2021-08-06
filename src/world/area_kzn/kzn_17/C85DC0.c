#include "kzn_17.h"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

#include "world/common/UnkNpcAIFunc26.inc.c"

#include "world/common/UnkFunc7.inc.c"

#include "world/common/UnkNpcAIFunc27.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80240BE0_C86690);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80240C4C_C866FC);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80240D48_C867F8);

#include "world/common/UnkNpcDurationFlagFunc3.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80241818_C872C8);

#include "world/common/UnkNpcDurationFlagFunc2.inc.c"

#include "world/common/UnkNpcAIFunc30.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80241A64_C87514);

#include "world/common/set_script_owner_npc_anim.inc.c"

#include "world/common/UnkDistFunc.inc.c"

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242048_C87AF8);

#include "world/common/AwaitPlayerNearNpc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_8024259C_C8804C);
/*
ApiStatus N(func_8024259C_C8804C)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80244074_C89B24) == NULL) {
        N(D_80244074_C89B24) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80244074_C89B24)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80244074_C89B24)[i];
        }
        heap_free(N(D_80244074_C89B24));
        N(D_80244074_C89B24) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_802428E0_C88390);
/*
ApiStatus N(func_802428E0_C88390)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_802440D8_C89B88) = FALSE;
    }

    if (N(D_802440D8_C89B88)) {
        N(D_802440D8_C89B88) = FALSE;
        set_variable(script, *args, N(D_802440DC_C89B8C));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242934_C883E4);
/*
ApiStatus N(func_80242934_C883E4)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_802440DC_C89B8C) = get_variable(script, *args);
    N(D_802440D8_C89B88) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_8024296C_C8841C);
/*
ApiStatus N(func_8024296C_C8841C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
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

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242C84_C88734);
/*
ApiStatus N(func_80242C84_C88734)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242CC8_C88778);
/*
ApiStatus N(func_80242CC8_C88778)(ScriptInstance *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/
