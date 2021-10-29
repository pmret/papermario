#include "common.h"
#include "npc.h"

ApiStatus N(AwaitScriptComplete)(Evt* script, s32 isInitialCall) {
    return (!does_script_exist(evt_get_variable(script, *script->ptrReadPos))) * ApiStatus_DONE2;
}
