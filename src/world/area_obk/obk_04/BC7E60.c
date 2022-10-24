#include "obk_04.h"

ApiStatus func_80240000_BC7E60(Evt* script, s32 isInitialCall) {
    ItemEntity* item = get_item_entity(script->varTable[0]);

    set_item_entity_flags(script->varTable[0], ITEM_ENTITY_FLAGS_TRANSPARENT);
    item->alpha = 255;
    return ApiStatus_DONE2;
}
