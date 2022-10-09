#include "sam_04.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_sam/sam_04/D138E0", func_8024053C_D13B0C);

INCLUDE_ASM(s32, "world/area_sam/sam_04/D138E0", func_80240590_D13B60);

extern s32 sam_04_80245210[];

ApiStatus func_802405C8_D13B98(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            sam_04_80245210[i] = ptr[i];
        }
        sam_04_80245210[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            sam_04_80245210[i] = i + 16;
            sam_04_80245210[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 D_802453D8[];

ApiStatus func_80240664_D13C34(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802453D8[i] = ptr[i];
        }
        D_802453D8[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_802453D8[i] = i + 128;
            D_802453D8[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}
