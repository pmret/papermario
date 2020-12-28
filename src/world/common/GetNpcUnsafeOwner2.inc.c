#include "common.h"
#include "map.h"

ApiStatus M(GetNpcUnsafeOwner2)(ScriptInstance* script, s32 isInitialCall) {
    get_npc_unsafe(script->owner2.npc);
    return ApiStatus_BLOCK;
}
