#include "dead_03.h"

extern s32 func_80059AC8(s32, s32);
extern s32 dead_03_ItemChoice_HasSelectedItem;
extern s32 dead_03_ItemChoice_SelectedItemID;
extern s32 dead_03_D_802442D0[];
extern s32 D_800B8DEC;

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

// Needs data migrated
#ifdef NON_MATCHING
ApiStatus func_80240654_EB14B4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        dead_03_ItemChoice_HasSelectedItem = 0;
    }
    if (dead_03_ItemChoice_HasSelectedItem != 0) {
        dead_03_ItemChoice_HasSelectedItem = 0;
        dead_evt_set_variable(script, *args++, dead_03_ItemChoice_SelectedItemID);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "EB1170", func_80240654_EB14B4);
#endif

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus func_802406E0_EB1540(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            dead_03_D_802442D0[i] = ptr[i];
        }
        dead_03_D_802442D0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            dead_03_D_802442D0[i] = i + 16;
            dead_03_D_802442D0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"

ApiStatus func_80240A68_EB18C8(Evt* script, s32 isInitialCall) {
    func_80059AC8(0, 1);
    return ApiStatus_DONE2;
}

ApiStatus func_80240A8C_EB18EC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gCollisionStatus.currentFloor);
    return ApiStatus_DONE2;
}
