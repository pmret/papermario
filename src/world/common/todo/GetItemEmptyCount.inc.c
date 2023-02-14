#include "common.h"

API_CALLABLE(N(GetItemEmptyCount)) {
    script->varTable[1] = get_item_empty_count();

    return ApiStatus_DONE2;
}
