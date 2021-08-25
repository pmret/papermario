#include "common.h"
#include "map.h"

ApiStatus N(DeadGetItemName)(Evt* script, s32 isInitialCall) {
    Bytecode args = *script->ptrReadPos;
    s32 itemID = get_variable(script, args);

    set_variable(script, args, LOOKUP_ITEM(itemID).nameString);
    return ApiStatus_DONE2;
}
