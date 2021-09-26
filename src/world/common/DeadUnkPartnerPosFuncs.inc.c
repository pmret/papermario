#include "common.h"
#include "effects.h"

ApiStatus N(DeadUnkPartnerPosFunc)(Evt* script, s32 isInitialCall) {
    Npc* partner = dead_get_npc_safe(NPC_PARTNER);

    playFX_11(2, partner->pos.x, partner->pos.y + 30.0f, partner->pos.z, 30.0f);
    return ApiStatus_DONE2;
}

ApiStatus N(DeadUnkPartnerPosFunc2)(Evt* script, s32 isInitialCall) {
    Npc* partner = dead_get_npc_safe(NPC_PARTNER);

    playFX_11(4, partner->pos.x, partner->pos.y + 30.0f, partner->pos.z, 30.0f);
    return ApiStatus_DONE2;
}
