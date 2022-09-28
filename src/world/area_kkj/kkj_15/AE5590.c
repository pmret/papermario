#include "kkj_15.h"

static char* N(exit_str_0) = "kmr_10";
static char* N(exit_str_1) = "trd_00";
static char* N(exit_str_2) = "arn_07";
static char* N(exit_str_3) = "kkj_11";
static char* N(exit_str_4) = "kkj_11\0";
static char* N(exit_str_5) = "";

#include "world/common/atomic/TexturePan.inc.c"

ApiStatus func_8024030C_AE589C(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags &= ~PEACH_STATUS_FLAG_IS_PEACH;
    gPlayerData.currentPartner = script->varTable[0];

    return ApiStatus_DONE2;
}
