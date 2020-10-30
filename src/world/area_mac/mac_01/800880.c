#include "mac_01.h"

ApiStatus func_80240000_800880(ScriptInstance* script, s32 isInitialCall) {
    s32 itemIndex = get_variable(script, *script->ptrReadPos);

    set_item_entity_flags(GAME_STATUS->shopItemData[itemIndex * 4], 0x40);
    return ApiStatus_DONE2;
}

ApiStatus func_80240044_8008C4(ScriptInstance* script, s32 isInitialCall) {
    s32 itemIndex = get_variable(script, *script->ptrReadPos);
    s32* var1 = get_variable(NULL, SI_MAP_VAR(2));

    set_item_entity_flags(GAME_STATUS->shopItemData[itemIndex * 4], 0x40);
    set_variable(NULL, var1[itemIndex], 1);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_mac/mac_01/800880", func_802400C8_800948);
