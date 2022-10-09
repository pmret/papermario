#include "kpa_81.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

extern s32 D_80240D98_A79258;
extern s32 D_80240D9C_A7925C;

// Needs data migrated
#ifdef NON_MATCHING
ApiStatus func_8024027C_A7873C(Evt* script, s32 isInitialCall) { 
    Bytecode* args = script->ptrReadPos;
    
    if (isInitialCall) {
        D_80240D98_A79258 = 0;
    }
    if (D_80240D98_A79258 != 0) {
        D_80240D98_A79258 = 0;
        evt_set_variable(script, *args++, D_80240D9C_A7925C);
        return ApiStatus_DONE2;
    }
    
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_kpa/kpa_81/A78510", func_8024027C_A7873C);
#endif

// Needs data migrated
#ifdef NON_MATCHING
ApiStatus func_802402D0_A78790(Evt* script, s32 isInitialCall) { 
    Bytecode* args = script->ptrReadPos;
    
    D_80240D9C_A7925C = evt_get_variable(script, *args++);
    D_80240D98_A79258 = 1;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_kpa/kpa_81/A78510", func_802402D0_A78790);
#endif

INCLUDE_ASM(s32, "world/area_kpa/kpa_81/A78510", func_80240308_A787C8);

extern s32 D_80242208[];

ApiStatus func_802403A4_A78864(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80242208[i] = ptr[i];
        }
        D_80242208[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_80242208[i] = i + 128;
            D_80242208[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}
