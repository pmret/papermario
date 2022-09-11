#include "jan_06.h"

ApiStatus func_80240310_B52B40(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    script->functionTemp[0] = evt_get_variable(script, *args++);
    script->functionTemp[1] = evt_get_variable(script, *args++);
    script->functionTemp[2] = evt_get_variable(script, *args++);
    sfx_adjust_env_sound_pos(SOUND_9E, 0, script->functionTemp[0], script->functionTemp[1], script->functionTemp[2]);
   
    return ApiStatus_DONE2;
}
