#include "common.h"
#include "npc.h"

ApiStatus N(SuperBlock_WaitForPlayerToLand)(Evt* script, s32 isInitialCall) {
    script->varTable[0] = 0;
    if ((gPartnerActionStatus.actionState.b[0] != 0) && (gPartnerActionStatus.actionState.b[3]  == 3)) {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}
