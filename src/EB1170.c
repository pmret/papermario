#include "dead.h"
#include "common.h"

// Has some relation to flo_12 (CC0E70.c) but it's rearranged and some stuff is different, so hard to tell

#define NAMESPACE EB1170

extern s32 func_80059AC8(s32, s32);
extern s32 D_802417E4_EB2644;
extern s32 D_802417E8_EB2648;
extern s32 EB1170_D_802442D0[];
extern s32 EB1170_LetterDelivery_SavedNpcAnim;
extern s32 D_800B8DEC;

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

// Needs data migrated
#ifdef NON_MATCHING
ApiStatus func_80240654_EB14B4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        D_802417E4_EB2644 = 0;
    }
    if (D_802417E4_EB2644 != 0) {
        D_802417E4_EB2644 = 0;
        dead_evt_set_variable(script, *args++, D_802417E8_EB2648);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "EB1170", func_80240654_EB14B4);
#endif

ApiStatus func_802406A8_EB1508(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_802417E8_EB2648 = evt_get_variable(script, *args++);
    D_802417E4_EB2644 = 1;
    return ApiStatus_DONE2;
}

ApiStatus func_802406E0_EB1540(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            EB1170_D_802442D0[i] = ptr[i];
        }
        EB1170_D_802442D0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            EB1170_D_802442D0[i] = i + 16;
            EB1170_D_802442D0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"

ApiStatus func_80240A68_EB18C8(Evt* script, s32 isInitialCall) {
    func_80059AC8(0, 1);
    return ApiStatus_DONE2;
}

ApiStatus func_80240A8C_EB18EC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, gCollisionStatus.currentFloor);
    return ApiStatus_DONE2;
}
