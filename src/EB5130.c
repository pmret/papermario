#include "dead.h"
#include "common.h"

#define NAMESPACE EB5130

#include "world/common/UnkTexturePanFunc.inc.c"

#include "world/common/UnkTexturePanFunc2.inc.c"

ApiStatus func_8024030C_EB543C(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, dead_gCollisionStatus.pushingAgainstWall);
    return ApiStatus_DONE2;
}
