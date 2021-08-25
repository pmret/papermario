#include "iwa_10.h"

#include "world/common/UnkFunc41.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_iwa/iwa_10/91F5A0", func_802413E0_91F950);
/*
ApiStatus N(func_802413E0_91F950)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_8024626C_9247DC) = FALSE;
    }

    if (N(D_8024626C_9247DC)) {
        N(D_8024626C_9247DC) = FALSE;
        set_variable(script, *args, N(D_80246270_9247E0));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_iwa/iwa_10/91F5A0", func_80241434_91F9A4);
/*
ApiStatus N(func_80241434_91F9A4)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80246270_9247E0) = get_variable(script, *args);
    N(D_8024626C_9247DC) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_iwa/iwa_10/91F5A0", func_8024146C_91F9DC);
/*
ApiStatus N(func_8024146C_91F9DC)(Evt* script, s32 isInitialCall) {
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
