#include "common.h"
#include "npc.h"

ApiStatus N(GetItemName)(Evt* script, s32 isInitialCall) {
    Bytecode args = *script->ptrReadPos;
    s32 itemID = evt_get_variable(script, args);

    evt_set_variable(script, args, LOOKUP_ITEM(itemID).nameMsg);
    return ApiStatus_DONE2;
}
