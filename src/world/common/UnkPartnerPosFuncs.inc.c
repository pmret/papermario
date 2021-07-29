#include "common.h"

ApiStatus N(UnkPartnerPosFunc)(ScriptInstance* script, s32 isInitialCall) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    playFX_11(2, partner->pos.x, partner->pos.y + 30.0f, partner->pos.z, 30.0f);
    return ApiStatus_DONE2;
}

ApiStatus N(UnkPartnerPosFunc2)(ScriptInstance* script, s32 isInitialCall) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    playFX_11(4, partner->pos.x, partner->pos.y + 30.0f, partner->pos.z, 30.0f);
    return ApiStatus_DONE2;
}
