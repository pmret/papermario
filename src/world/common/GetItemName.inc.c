#include "common.h"
#include "map.h"

ApiStatus N(GetItemName)(Evt* script, s32 isInitialCall) {
    Bytecode a0 = *script->ptrReadPos;
    s32 itemID = evt_get_variable(script, a0);

    evt_set_variable(script, a0, LOOKUP_ITEM(itemID).nameString);
    return ApiStatus_DONE2;
}
