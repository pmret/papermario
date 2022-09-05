#include "kpa_81.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_81/A78510", func_8024027C_A7873C);

INCLUDE_ASM(s32, "world/area_kpa/kpa_81/A78510", func_802402D0_A78790);

INCLUDE_ASM(s32, "world/area_kpa/kpa_81/A78510", func_80240308_A787C8);

extern s32 D_80242208[];

ApiStatus func_802403A4_A78864(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80242208[i] = ptr[i];
        }
        D_80242208[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_80242208[i] = i + 128;
            D_80242208[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}
