#include "dead.h"
#include "common.h"

#define NAMESPACE EB1170

extern s32 D_802442D0[];

INCLUDE_ASM(s32, "EB1170", func_80240310_EB1170);

#include "world/common/DeadGetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

INCLUDE_ASM(s32, "EB1170", func_80240484_EB12E4);

INCLUDE_ASM(s32, "EB1170", func_80240654_EB14B4);

INCLUDE_ASM(s32, "EB1170", func_802406A8_EB1508);

ApiStatus func_802406E0_EB1540(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
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

INCLUDE_ASM(s32, "EB1170", func_8024077C_EB15DC);

//INCLUDE_ASM(s32, "EB1170", func_8024086C_EB16CC);
#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "EB1170", func_802409F8_EB1858);

INCLUDE_ASM(s32, "EB1170", func_80240A3C_EB189C);

INCLUDE_ASM(s32, "EB1170", func_80240A68_EB18C8);

INCLUDE_ASM(s32, "EB1170", func_80240A8C_EB18EC);
