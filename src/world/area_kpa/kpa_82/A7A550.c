#include "kpa_82.h"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_82/A7A550", func_8024027C_A7A77C);

extern s32 D_80240C20_A7B120;
extern s32 D_80240C24_A7B124;

ApiStatus func_802402D0_A7A7D0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80240C24_A7B124 = evt_get_variable(script, *args++);
    D_80240C20_A7B120 = 1;
    return ApiStatus_DONE2;
}

extern s32 D_80248F90[];

ApiStatus func_80240308_A7A808(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80248F90[i] = ptr[i];
        }
        D_80248F90[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_80248F90[i] = i + 16;
            D_80248F90[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 D_80249158[];

ApiStatus func_802403A4_A7A8A4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80249158[i] = ptr[i];
        }
        D_80249158[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_80249158[i] = i + 128;
            D_80249158[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}
