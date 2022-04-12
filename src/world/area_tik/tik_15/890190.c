#include "tik_15.h"

#include "world/common/UnkPosFunc2.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

extern s32 D_802427BC_89235C[13][2];

ApiStatus func_80240A78_890618(Evt* script, s32 isInitialCall) {
    s32* array = D_802427BC_89235C[script->varTable[0]];

    script->varTable[0xA] = array[0];
    script->varTable[0xB] = array[1] ;
    return ApiStatus_DONE2;
}

ApiStatus func_80240AA4_890644(Evt* script) {
    script->varTable[0] = get_item_empty_count();
    return ApiStatus_DONE2;
}

ApiStatus func_80240AD0_890670(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, (gPlayerData.coins >= 64));
    return ApiStatus_DONE2;
}
