#include "common.h"

ApiStatus N(SuperBlock_PartnerSparkles2)(Evt* script, s32 isInitialCall) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    fx_sparkles(2, partner->pos.x, partner->pos.y + 30.0f, partner->pos.z, 30.0f);
    return ApiStatus_DONE2;
}

ApiStatus N(SuperBlock_PartnerSparkles4)(Evt* script, s32 isInitialCall) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    fx_sparkles(4, partner->pos.x, partner->pos.y + 30.0f, partner->pos.z, 30.0f);
    return ApiStatus_DONE2;
}
