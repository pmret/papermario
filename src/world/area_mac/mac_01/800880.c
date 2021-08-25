#include "mac_01.h"

static char* N(exit_str_0) = "mac_00";
static char* N(exit_str_1) = "nok_11";
static char* N(exit_str_2) = "kmr_22";
static char* N(exit_str_3) = "osr_00";
static char* N(exit_str_4) = "osr_01";
static char* N(exit_str_5) = "mac_02";

ApiStatus func_80240000_800880(Evt* script, s32 isInitialCall) {
    s32 itemIndex = get_variable(script, *script->ptrReadPos);

    set_item_entity_flags(gGameStatusPtr->shopItemEntities[itemIndex].index, 0x40);
    return ApiStatus_DONE2;
}

ApiStatus func_80240044_8008C4(Evt* script, s32 isInitialCall) {
    s32 itemIndex = get_variable(script, *script->ptrReadPos);
    s32* var1 = get_variable(NULL, SI_MAP_VAR(2));

    set_item_entity_flags(gGameStatusPtr->shopItemEntities[itemIndex].index, 0x40);
    set_variable(NULL, var1[itemIndex], 1);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_01/800880", func_802400C8_800948);
