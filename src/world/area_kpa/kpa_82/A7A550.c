#include "kpa_82.h"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_82/A7A550", func_8024027C_A7A77C);

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

BSS s32 D_80248F90[114];
BSS s32 D_80249158[92];

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
