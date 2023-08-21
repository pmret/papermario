#include "common.h"
#include "npc.h"

API_CALLABLE(N(UnkFunc51)) {
    Bytecode* args = script->ptrReadPos;

    script->functionTemp[0] = evt_get_variable(script, *args++);
    script->functionTemp[1] = evt_get_variable(script, *args++);
    script->functionTemp[2] = evt_get_variable(script, *args++);
    sfx_adjust_env_sound_pos(SOUND_LRAW_TROMP_ROLL, SOUND_SPACE_DEFAULT, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);

    return ApiStatus_DONE2;
}
