#include "common.h"
#include "npc.h"

API_CALLABLE(N(GetItemName)) {
    Bytecode* args = script->ptrReadPos;
    s32 inOutVar = *args++;
    s32 itemID = evt_get_variable(script, inOutVar);

    evt_set_variable(script, inOutVar, gItemTable[itemID & ~0xF0000].nameMsg);
    return ApiStatus_DONE2;
}
