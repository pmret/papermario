#include "common.h"
#include "map.h"

ApiStatus M(GetGameStatus75)(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, SI_VAR(0), GAME_STATUS->unk_75);
    return ApiStatus_DONE2;
}
