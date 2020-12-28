#include "common.h"
#include "map.h"

ApiStatus M(SetPlayerStatusAnimFlags100000)(ScriptInstance* script, s32 isInitialCall) {
    gPlayerStatusPtr->animFlags |= 0x100000;
    return ApiStatus_DONE2;
}
