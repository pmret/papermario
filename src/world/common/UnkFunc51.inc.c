#include "common.h"
#include "npc.h"

ApiStatus N(UnkFunc51)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    script->functionTemp[0] = evt_get_variable(script, *args++);
    script->functionTemp[1] = evt_get_variable(script, *args++);
    script->functionTemp[2] = evt_get_variable(script, *args++);
    sfx_adjust_env_sound_pos(SOUND_UNKNOWN_52, 0, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);

    return ApiStatus_DONE2;
}
