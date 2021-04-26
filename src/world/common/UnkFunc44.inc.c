#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc44)(ScriptInstance *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    script->functionTemp[0].s = get_variable(script, *args++);
    script->functionTemp[1].s = get_variable(script, *args++);
    script->functionTemp[2].s = get_variable(script, *args++);
    sfx_adjust_env_sound_pos(0x194, 0, script->functionTemp[0].s, script->functionTemp[1].s, script->functionTemp[2].s);
    return ApiStatus_DONE2;
}