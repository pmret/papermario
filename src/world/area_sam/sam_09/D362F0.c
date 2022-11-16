#include "sam_09.h"

static char* N(exit_str_0) = "sam_08";
static char* N(exit_str_1) = "sam_10";

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

ApiStatus func_80240118_D36408(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = evt_get_variable(script, *args++);

    script->varTable[0] = get_item_entity(var1)->itemID;
    return ApiStatus_DONE2;
}

ApiStatus func_80240158_D36448(Evt* script, s32 isInitialCall) {
    s32 mapVar0;
    s32 mapVar2;
    s32 mapVar3;

    mapVar0 = evt_get_variable(script, MapVar(0));
    if (mapVar0 == -1) {
        mapVar0 = 0xFF;
    }
    evt_set_variable(script, GameByte(264), mapVar0 & 0xFF);
    evt_set_variable(script, GameByte(265), (mapVar0 >> 8) & 0xFF);

    mapVar2 = evt_get_variable(script, MapVar(1));
    if (mapVar2 == -1) {
        mapVar2 = 0xFF;
    }
    evt_set_variable(script, GameByte(266), mapVar2 & 0xFF);
    evt_set_variable(script, GameByte(267), (mapVar2 >> 8) & 0xFF);

    mapVar3 = evt_get_variable(script, MapVar(2));
    if (mapVar3 == -1) {
        mapVar3 = 0xFF;
    }
    evt_set_variable(script, GameByte(268), mapVar3 & 0xFF);
    evt_set_variable(script, GameByte(269), (mapVar3 >> 8) & 0xFF);
    return ApiStatus_DONE2;
}

ApiStatus func_80240264_D36554(Evt* script, s32 isInitialCall) {
    s32 temp_a2;
    s32 temp_s0;

    temp_s0 = evt_get_variable(script, GameByte(264)) & 0xFF;
    temp_a2 = evt_get_variable(script, GameByte(265)) & 0xFF;
    if (temp_s0 != 0xFF) {
        evt_set_variable(script, MapVar(0), (temp_a2 << 8) | temp_s0);
    } else {
        evt_set_variable(script, MapVar(0), -1);
    }

    temp_s0 = evt_get_variable(script, GameByte(266)) & 0xFF;
    temp_a2 = evt_get_variable(script, GameByte(267)) & 0xFF;
    if (temp_s0 != 0xFF) {
        evt_set_variable(script, MapVar(1), (temp_a2 << 8) | temp_s0);
    } else {
        evt_set_variable(script, MapVar(1), -1);
    }

    temp_s0 = evt_get_variable(script, GameByte(268)) & 0xFF;
    temp_a2 = evt_get_variable(script, GameByte(269)) & 0xFF;
    if (temp_s0 != 0xFF) {
        evt_set_variable(script, MapVar(2), (temp_a2 << 8) | temp_s0);
    } else {
        evt_set_variable(script, MapVar(2), -1);
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802403A0_D36690(Evt* script, s32 isInitialCall) {
    s32* array;
    s32 len = 92;
    s32 i;

    script->varTable[0] = array = heap_malloc(92 * sizeof(*array));
    for (i = 0; i < 91; i++) {
        array[i] = 128 + i;
    }
    array[i] = 0;
    return ApiStatus_DONE2;
}
