#include "common.h"
#include "map.h"

ApiStatus N(DeadGetItemName)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode args = *script->ptrReadPos;
    s32 itemID = dead_get_variable(script, args);

    dead_set_variable(script, args, DEAD_LOOKUP_ITEM(itemID).nameString);
    return ApiStatus_DONE2;
}
