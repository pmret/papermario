#include "common.h"

static ApiStatus GetGameStatus75(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, SI_VAR(0), GAME_STATUS->unk_75);
    return ApiStatus_DONE2;
}
