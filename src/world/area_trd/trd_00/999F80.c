#include "trd_00.h"

INCLUDE_ASM(s32, "world/area_trd/trd_00/999F80", func_80240310_999F80);

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

ApiStatus func_80240578_99A1E8(ScriptInstance* script, s32 isInitialCall) {
    s32 itemIndex = get_variable(script, *script->ptrReadPos);

    script->varTable[0] = 0;
    if (gItemTable[itemIndex].typeFlags & 0x40) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}
