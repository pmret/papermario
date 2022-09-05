#include "iwa_10.h"

#include "world/common/UnkFunc41.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_iwa/iwa_10/91F5A0", func_802413E0_91F950);

INCLUDE_ASM(s32, "world/area_iwa/iwa_10/91F5A0", func_80241434_91F9A4);

extern s32 D_80248480[];

ApiStatus func_8024146C_91F9DC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80248480[i] = ptr[i];
        }
        D_80248480[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_80248480[i] = i + 16;
            D_80248480[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
