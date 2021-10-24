#include "dead.h"
#include "common.h"

#define NAMESPACE EA7320

#include "world/common/SetCamera0Flag1000.inc.c"

#include "world/common/UnsetCamera0Flag1000.inc.c"

ApiStatus func_80240388_EA7358(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, dead_gCollisionStatus.pushingAgainstWall);
    return ApiStatus_DONE2;
}
