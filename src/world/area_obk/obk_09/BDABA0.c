#include "obk_09.h"

ApiStatus func_802403F0_BDABA0(Evt* script, s32 isInitialCall) {
    get_item_entity(script->varTable[0])->scale = 0.6f;
    return ApiStatus_DONE2;
}
