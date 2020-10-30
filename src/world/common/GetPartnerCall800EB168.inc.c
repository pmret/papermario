#include "common.h"

static ApiStatus GetPartnerCall800EB168(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, PLAYER_DATA->currentPartner);
    func_800EB168(0);
    return ApiStatus_DONE2;
}

static ApiStatus Call800EB168(ScriptInstance* script, s32 isInitialCall) {
    func_800EB168(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
