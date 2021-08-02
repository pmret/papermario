#include "kzn_09.h"

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

#include "world/common/UnkNpcAIFunc26.inc.c"

#include "world/common/UnkFunc7.inc.c"

#include "world/common/UnkNpcAIFunc27.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_802418F0_C785D0);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_8024195C_C7863C);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80241A58_C78738);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80242498_C79178);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80242528_C79208);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80242628_C79308);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80242688_C79368);

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80242774_C79454);

#include "world/common/set_script_owner_npc_anim.inc.c"

#include "world/common/UnkDistFunc.inc.c"

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80242D58_C79A38);

#include "world/common/AwaitPlayerNearNpc.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_802432AC_C79F8C);
/*
ApiStatus N(func_802432AC_C79F8C)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_80245250_C7BF30) == NULL) {
        N(D_80245250_C7BF30) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_80245250_C7BF30)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_80245250_C7BF30)[i];
        }
        heap_free(N(D_80245250_C7BF30));
        N(D_80245250_C7BF30) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_802435F0_C7A2D0);
/*
ApiStatus N(func_802435F0_C7A2D0)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_802452B4_C7BF94) = FALSE;
    }

    if (N(D_802452B4_C7BF94)) {
        N(D_802452B4_C7BF94) = FALSE;
        set_variable(script, *args, N(D_802452B8_C7BF98));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80243644_C7A324);
/*
ApiStatus N(func_80243644_C7A324)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_802452B8_C7BF98) = get_variable(script, *args);
    N(D_802452B4_C7BF94) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_8024367C_C7A35C);
/*
ApiStatus N(func_8024367C_C7A35C)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_80243994_C7A674);
/*
ApiStatus N(func_80243994_C7A674)(ScriptInstance *script, s32 isInitialCall) {
    Npc *npc = get_npc_unsafe(script->varTable[2]);

    D_8024E1B4 = npc->currentAnim;
    npc->currentAnim = script->varTable[4];
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_kzn/kzn_09/C77D00", func_802439D8_C7A6B8);
/*
ApiStatus N(func_802439D8_C7A6B8)(ScriptInstance *script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim = D_8024E1B4;
    return ApiStatus_DONE2;
}
*/
