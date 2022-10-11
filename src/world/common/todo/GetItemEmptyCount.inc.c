#include "common.h"

ApiStatus N(GetItemEmptyCount)(Evt* script, s32 isInitialCall) {
    script->varTable[1] = get_item_empty_count();

    return ApiStatus_DONE2;
}
