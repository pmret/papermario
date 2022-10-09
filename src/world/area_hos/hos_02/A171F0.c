#include "hos_02.h"

ApiStatus func_80240FD0_A171F0(Evt* script, s32 isInitialCall) {
    script->varTable[0] = gGameStatusPtr->entryID;
    return ApiStatus_DONE2;
}
