#include "pra_31.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_8024024C_D7EFAC);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_802402A0_D7F000);

extern s32 D_80247CA0[];

ApiStatus func_802402D8_D7F038(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80247CA0[i] = ptr[i];
        }
        D_80247CA0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_80247CA0[i] = i + 16;
            D_80247CA0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 D_80247E68[];

ApiStatus func_80240374_D7F0D4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80247E68[i] = ptr[i];
        }
        D_80247E68[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_80247E68[i] = i + 128;
            D_80247E68[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_80240410_D7F170);

INCLUDE_ASM(s32, "world/area_pra/pra_31/D7ED80", func_80240468_D7F1C8);
