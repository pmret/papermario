#include "dead.h"
#include "common.h"

// Copy of flo_12 (CC0E70.c)

#define NAMESPACE EDC020

extern s32 D_802429E0[];
//extern s32** D_802417EC_EDD7CC = NULL;

/*
extern s32 D_80241850_EDD830 = {
    0x00000000,
};

extern s32 D_80241850_EDD834 = {
    0x00000000,
};
*/

#include "world/common/foliage.inc.c"

#ifdef NON_MATCHING // TODO(data)
ApiStatus func_8024027C_EDC25C(Evt* script, s32 isInitialCall) {
    s32 i;

    if (D_802417EC_EDD7CC == NULL) {
        D_802417EC_EDD7CC = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            D_802417EC_EDD7CC[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = D_802417EC_EDD7CC[i];
        }
        heap_free(D_802417EC_EDD7CC);
        D_802417EC_EDD7CC = NULL;
    }
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "EDC020", func_8024027C_EDC25C);
#endif

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

#ifdef NON_MATCHING // TODO(data)
ApiStatus func_802405C0_EDC5A0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        D_80241850_EDD830 = FALSE;
    }

    if (D_80241850_EDD830) {
        D_80241850_EDD830 = FALSE;
        evt_set_variable(script, *args, D_80241850_EDD834);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "EDC020", func_802405C0_EDC5A0);
#endif

#ifdef NON_MATCHING // TODO(data)
ApiStatus func_80240614_EDC5F4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80241850_EDD834 = evt_get_variable(script, *args);
    D_80241850_EDD830 = TRUE;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "EDC020", func_80240614_EDC5F4);
#endif

ApiStatus func_8024064C_EDC62C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802429E0[i] = ptr[i];
        }
        D_802429E0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_802429E0[i] = i + 16;
            D_802429E0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
