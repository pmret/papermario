#include "common.h"

API_CALLABLE(N(RestoreFromPeachState)) {
    gGameStatusPtr->peachFlags &= ~PEACH_FLAG_IS_PEACH;
    gPlayerData.curPartner = script->varTable[0];
    return ApiStatus_DONE2;
}
