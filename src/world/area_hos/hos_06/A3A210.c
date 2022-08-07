#include "hos_06.h"

ApiStatus func_80240D30_A3A210(Evt* script, s32 isInitialCall) {
    script->varTable[0] = gGameStatusPtr->entryID;
    return ApiStatus_DONE2;
}
