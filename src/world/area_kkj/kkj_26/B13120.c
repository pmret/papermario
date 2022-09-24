#include "kkj_26.h"

static char* N(exit_str_0) = "hos_00";
static char* N(exit_str_1) = "kkj_14";
static char* N(exit_str_2) = "kkj_14\0";
static char* N(exit_str_3) = "kkj_26";

ApiStatus func_80240000_B13120(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags &= ~PEACH_STATUS_FLAG_IS_PEACH;
    gPlayerData.currentPartner = script->varTable[0];

    return ApiStatus_DONE2;
}
