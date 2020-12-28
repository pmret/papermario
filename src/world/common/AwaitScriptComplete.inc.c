#include "common.h"
#include "map.h"

ApiStatus N(AwaitScriptComplete)(ScriptInstance* script, s32 isInitialCall) {
    return (!does_script_exist(get_variable(script, *script->ptrReadPos))) * ApiStatus_DONE2;
}
