#include "common.h"

static ApiStatus SetPlayerStatusAnimFlags100000(ScriptInstance* script, s32 isInitialCall) {
    gPlayerStatusPtr->animFlags |= 0x100000;
    return ApiStatus_DONE2;
}
