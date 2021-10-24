#include "dead.h"
#include "common.h"

#define NAMESPACE EF2650

extern s16 D_80169B16;

ApiStatus func_80240040_EF2650(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, D_80169B16);
    return ApiStatus_DONE2;
}
