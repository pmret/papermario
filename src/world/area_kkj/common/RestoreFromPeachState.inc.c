#include "common.h"

API_CALLABLE(N(RestoreFromPeachState)) {
    gGameStatusPtr->peachFlags &= ~PEACH_STATUS_FLAG_IS_PEACH;
    gPlayerData.currentPartner = script->varTable[0];
    return ApiStatus_DONE2;
}
