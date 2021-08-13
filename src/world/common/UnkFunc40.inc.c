#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc40)(ScriptInstance* script, s32 isInitialCall) {
    script->varTable[0] = 0;
    if ((gPartnerActionStatus.actionState.b[0] != 0) && (gPartnerActionStatus.actionState.b[3]  == 3)) {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}
