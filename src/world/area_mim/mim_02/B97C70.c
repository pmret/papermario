#include "mim_02.h"

INCLUDE_ASM(s32, "world/area_mim/mim_02/B97C70", func_80240070_B97C70);

INCLUDE_ASM(s32, "world/area_mim/mim_02/B97C70", func_802402A0_B97EA0);

#include "world/common/UnkNpcAIFunc1.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_02/B97C70", func_80240698_B98298);

#include "world/common/UnkNpcAIFunc15.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_02/B97C70", func_8024091C_B9851C);

#include "world/common/UnkDurationCheck.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_02/B97C70", func_80240C60_B98860);

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_mim/mim_02/B97C70", func_802410B0_B98CB0);
/*
ApiStatus N(func_802410B0_B98CB0)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_802416AC_B992AC) = FALSE;
    }

    if (N(D_802416AC_B992AC)) {
        N(D_802416AC_B992AC) = FALSE;
        set_variable(script, *args, N(D_802416B0_B992B0));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_mim/mim_02/B97C70", func_80241104_B98D04);
/*
ApiStatus N(func_80241104_B98D04)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_802416B0_B992B0) = get_variable(script, *args);
    N(D_802416AC_B992AC) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_mim/mim_02/B97C70", func_8024113C_B98D3C);
/*
ApiStatus N(func_8024113C_B98D3C)(Evt* script, s32 isInitialCall) {
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
