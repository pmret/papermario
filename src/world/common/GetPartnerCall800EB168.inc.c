#include "common.h"
#include "map.h"

ApiStatus N(GetPartnerCall800EB168)(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gPlayerData.currentPartner);
    switch_to_partner(0);
    return ApiStatus_DONE2;
}

ApiStatus N(Call800EB168)(ScriptInstance* script, s32 isInitialCall) {
    switch_to_partner((s8)get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
