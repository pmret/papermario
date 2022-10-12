#include "pra_02.h"

#include "world/common/atomic/Reflection.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_8024114C_D5113C);

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_802411A0_D51190);

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_802411D8_D511C8);

extern s32 D_80243E88_846A58[];

ApiStatus func_80241274_D51264(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_80243E88_846A58[i] = ptr[i];
        }
        D_80243E88_846A58[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            D_80243E88_846A58[i] = i + 128;
            D_80243E88_846A58[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/todo/SetEntityPositionF.inc.c"

#include "world/common/todo/GetEntityPosition.inc.c"

#include "world/common/todo/UnkFunc44.inc.c"

INCLUDE_ASM(s32, "world/area_pra/pra_02/D50010", func_802414A8_D51498);

#include "world/common/todo/RemovePadlock.inc.c"

#define NAMESPACE dup_pra_02
#include "world/common/todo/GetEntityPosition.inc.c"
#define NAMESPACE pra_02
