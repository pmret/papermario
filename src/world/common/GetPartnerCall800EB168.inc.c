#include "common.h"
#include "map.h"

ApiStatus N(GetPartnerCall800EB168)(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gPlayerData.currentPartner);
    func_800EB168(0);
    return ApiStatus_DONE2;
}

ApiStatus N(Call800EB168)(ScriptInstance* script, s32 isInitialCall) {
    func_800EB168((s8)get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
