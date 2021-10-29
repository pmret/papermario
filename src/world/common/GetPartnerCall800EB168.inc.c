#include "common.h"
#include "npc.h"

ApiStatus N(GetPartnerCall800EB168)(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gPlayerData.currentPartner);
    switch_to_partner(0);
    return ApiStatus_DONE2;
}

ApiStatus N(Call800EB168)(Evt* script, s32 isInitialCall) {
    switch_to_partner((s8)evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
