#include "kpa_82.h"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kpa/kpa_82/A7A550", func_8024027C_A7A77C);

extern s32 D_80240C20_A7B120;
extern s32 D_80240C24_A7B124;

ApiStatus func_802402D0_A7A7D0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    D_80240C24_A7B124 = evt_get_variable(script, *args++);
    D_80240C20_A7B120 = 1;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kpa/kpa_82/A7A550", func_80240308_A7A808);

INCLUDE_ASM(s32, "world/area_kpa/kpa_82/A7A550", func_802403A4_A7A8A4);
