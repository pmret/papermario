#include "osr_01.h"

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

// Needs data migrated
#ifdef NON_MATCHING
ApiStatus func_802406A4_AB0694(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        osr_01_ItemChoice_HasSelectedItem = 0;
    }

    if (osr_01_ItemChoice_HasSelectedItem != 0) {
        osr_01_ItemChoice_HasSelectedItem = 0;
        evt_set_variable(script, *args++, osr_01_ItemChoice_SelectedItemID);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_osr/osr_01/AB0350", func_802406A4_AB0694);
#endif

// Needs data migrated
#ifdef NON_MATCHING
ApiStatus func_802406F8_AB06E8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    osr_01_ItemChoice_SelectedItemID = evt_get_variable(script, *args++);
    osr_01_ItemChoice_HasSelectedItem = 1;
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

BSS s32 osr_01_D_80242180[114];

ApiStatus func_80240730_AB0720(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            osr_01_D_80242180[i] = ptr[i];
        }
        osr_01_D_80242180[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            osr_01_D_80242180[i] = i + 16;
            osr_01_D_80242180[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"
