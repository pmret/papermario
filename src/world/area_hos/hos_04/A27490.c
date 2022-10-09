#include "hos_04.h"

ApiStatus func_802405C0_A27490(Evt* script, s32 isInitialCall) {
    script->varTable[0] = gGameStatusPtr->entryID;
    return ApiStatus_DONE2;
}
