#include "kkj_16.h"

static char* N(exit_str_0) = "sbk_02";
static char* N(exit_str_1) = "kkj_11";

ApiStatus func_80240000_AED410(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags &= ~0x1;
    gPlayerData.currentPartner = script->varTable[0];
    return ApiStatus_DONE2;
}

ApiStatus func_80240028_AED438(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    gPlayerStatus.availableDisguiseType = evt_get_float_variable(script, *args++);
    return ApiStatus_DONE2;
}

#include "world/common/atomic/UnkPhysicsFuncs.inc.c"

#include "world/common/UnkGooberFunc50.inc.c"

const char* kkj_16_str = "kkj_14";
