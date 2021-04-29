#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc40)(ScriptInstance *script, s32 isInitialCall) {
    script->varTable[0] = 0;
    if ((D_8010EBB0.unk_00 != 0) && (D_8010EBB0.unk_03 == 3)) {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}
