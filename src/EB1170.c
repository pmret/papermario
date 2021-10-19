#include "dead.h"
#include "common.h"

#define NAMESPACE EB1170

extern s32 func_80059AC8(s32, s32);
extern s16 D_80169B12;
extern s32 D_802417E4_EB2644;
extern s32 D_802417E8_EB2648;
extern s32 D_802442D0[];
extern u32 D_80244494;
extern s32 D_800B8DEC;

INCLUDE_ASM(s32, "EB1170", func_80240310_EB1170);

#include "world/common/DeadGetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

INCLUDE_ASM(s32, "EB1170", func_80240484_EB12E4);

// LW %LO issue.
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
#endif // NON_MATCHING

ApiStatus func_802406A8_EB1508(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_802417E8_EB2648 = evt_get_variable(script, *args++);
    D_802417E4_EB2644 = 1;
    return ApiStatus_DONE2;
}

ApiStatus func_802406E0_EB1540(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802442D0[i] = ptr[i];
        }
        D_802442D0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_802442D0[i] = i + 16;
            D_802442D0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

ApiStatus func_802409F8_EB1858(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->varTable[2]);

    D_80244494 = npc->currentAnim.w;
    npc->currentAnim.w = (u32)script->varTable[4];
    return ApiStatus_DONE2;
}


ApiStatus func_80240A3C_EB189C(Evt* script, s32 isInitialCall) {
    get_npc_unsafe(script->varTable[2])->currentAnim.w = D_80244494;
    return ApiStatus_DONE2;
}

ApiStatus func_80240A68_EB18C8(Evt* script, s32 isInitialCall) {
    func_80059AC8(0, 1);
    return ApiStatus_DONE2;
}

ApiStatus func_80240A8C_EB18EC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, D_80169B12);
    return ApiStatus_DONE2;
}
