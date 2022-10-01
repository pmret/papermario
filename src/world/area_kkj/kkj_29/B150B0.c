#include "kkj_29.h"

static char* N(exit_str_0) = "jan_22";
static char* N(exit_str_1) = "kkj_10";

ApiStatus func_80240000_B150B0(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags &= ~PEACH_STATUS_FLAG_IS_PEACH;
    gPlayerData.currentPartner = script->varTable[0];

    return ApiStatus_DONE2;
}
