#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc39)(ScriptInstance* script, s32 isInitialCall) {
    Effect* effect = get_variable(script, *script->ptrReadPos);

    effect->flags |= 0x10;

    return ApiStatus_DONE2;
}
