#include "common.h"
#include "evt.h"

ApiStatus N(UnkMachiFunc)(Evt* script, s32 isInitialCall) {
    if (evt_get_variable(NULL, EVT_SAVE_FLAG(260)) == 0) {
        set_item_entity_flags(gGameStatusPtr->shopItemEntities[0].index, ITEM_ENTITY_FLAGS_40);
    }
    if (evt_get_variable(NULL, EVT_SAVE_FLAG(261)) == 0) {
        set_item_entity_flags(gGameStatusPtr->shopItemEntities[1].index, ITEM_ENTITY_FLAGS_40);
    }
    if (evt_get_variable(NULL, EVT_SAVE_FLAG(262)) == 0) {
        set_item_entity_flags(gGameStatusPtr->shopItemEntities[2].index, ITEM_ENTITY_FLAGS_40);
    }
    return ApiStatus_DONE2;
}
