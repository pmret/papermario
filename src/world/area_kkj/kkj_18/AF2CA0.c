#include "kkj_18.h"

static char* N(exit_str_0) = "mac_04";
static char* N(exit_str_1) = "kkj_19";
static char* N(exit_str_2) = "kkj_11";
static char* N(exit_str_3) = "";

#include "world/common/atomic/TexturePan.inc.c"

ApiStatus func_8024030C_AF2FAC(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->peachFlags &= ~PEACH_STATUS_FLAG_IS_PEACH;
    gPlayerData.currentPartner = script->varTable[0];

    return ApiStatus_DONE2;
}
