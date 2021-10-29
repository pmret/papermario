#include "common.h"
#include "npc.h"

ApiStatus N(CheckItemFlags40)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemIndex = evt_get_variable(script, *args++);

    script->varTable[0] = FALSE;
    if (gItemTable[itemIndex].typeFlags & 0x40) {
        script->varTable[0] = TRUE;
    }

    return ApiStatus_DONE2;
}
