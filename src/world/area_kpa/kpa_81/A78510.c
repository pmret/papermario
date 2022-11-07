#include "kpa_81.h"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

// Needs data migrated
#ifdef NON_MATCHING
ApiStatus func_8024027C_A7873C(Evt* script, s32 isInitialCall) { 
    Bytecode* args = script->ptrReadPos;
    
    if (isInitialCall) {
        kpa_81_ItemChoice_HasSelectedItem = 0;
    }
    if (kpa_81_ItemChoice_HasSelectedItem != 0) {
        kpa_81_ItemChoice_HasSelectedItem = 0;
        evt_set_variable(script, *args++, kpa_81_ItemChoice_SelectedItemID);
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
    
    kpa_81_ItemChoice_SelectedItemID = evt_get_variable(script, *args++);
    kpa_81_ItemChoice_HasSelectedItem = 1;
    return ApiStatus_DONE2;
}
#else

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}
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
