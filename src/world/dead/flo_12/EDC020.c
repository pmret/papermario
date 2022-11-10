#include "flo_12.h"

extern s32 N(D_802429E0)[];

#include "common/foliage.inc.c"

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

#ifdef NON_MATCHING // TODO(data)
ApiStatus func_802405C0_EDC5A0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        dead_flo_12_ItemChoice_HasSelectedItem = FALSE;
    }

    if (dead_flo_12_ItemChoice_HasSelectedItem) {
        dead_flo_12_ItemChoice_HasSelectedItem = FALSE;
        evt_set_variable(script, *args++, D_80241850_EDD834);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "EDC020", func_802405C0_EDC5A0);
#endif

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus func_8024064C_EDC62C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_802429E0)[i] = ptr[i];
        }
        N(D_802429E0)[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            N(D_802429E0)[i] = i + 16;
            N(D_802429E0)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
