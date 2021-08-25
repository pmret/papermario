#include "common.h"
#include "map.h"

ApiStatus N(GetItemName)(Evt* script, s32 isInitialCall) {
    Bytecode a0 = *script->ptrReadPos;
    s32 itemID = get_variable(script, a0);

    set_variable(script, a0, LOOKUP_ITEM(itemID).nameString);
    return ApiStatus_DONE2;
}
