#include "pra_02.h"

#include "world/common/reflection.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_8024114C_D5113C);
/*
ApiStatus N(func_8024114C_D5113C)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80242ACC_D52ABC) = FALSE;
    }

    if (N(D_80242ACC_D52ABC)) {
        N(D_80242ACC_D52ABC) = FALSE;
        set_variable(script, *args, N(D_80242AD0_D52AC0));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_802411A0_D51190);
/*
ApiStatus N(func_802411A0_D51190)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80242AD0_D52AC0) = get_variable(script, *args);
    N(D_80242ACC_D52ABC) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_802411D8_D511C8);
/*
ApiStatus N(func_802411D8_D511C8)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_80241274_D51264);
/*
ApiStatus N(func_80241274_D51264)(ScriptInstance* script, s32 isInitialCall) {
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

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_80241310_D51300);

#include "world/common/GetEntityPosition.inc.c"

#include "world/common/UnkFunc44.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_802414A8_D51498);

#include "world/common/SetEntityFlags100000.inc.c"

#define NAMESPACE dup_pra_02
#include "world/common/GetEntityPosition.inc.c"
#define NAMESPACE pra_02
