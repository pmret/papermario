#include "mac_01.h"

#define NAMESPACE dup_mac_01

#include "world/common/enemy/PatrolNoAttackAI.inc.c"

#define NAMESPACE mac_01

static char* N(exit_str_0) = "osr_00";

ApiStatus func_802463E0_806C60(Evt* script, s32 isInitialCall) {
    if (evt_get_variable(NULL, EVT_SAVE_FLAG(260)) == 0) {
        set_item_entity_flags(gGameStatusPtr->shopItemEntities[0].index, 0x40);
    }
    if (evt_get_variable(NULL, EVT_SAVE_FLAG(261)) == 0) {
        set_item_entity_flags(gGameStatusPtr->shopItemEntities[1].index, 0x40);
    }
    if (evt_get_variable(NULL, EVT_SAVE_FLAG(262)) == 0) {
        set_item_entity_flags(gGameStatusPtr->shopItemEntities[2].index, 0x40);
    }
    return ApiStatus_DONE2;
}
