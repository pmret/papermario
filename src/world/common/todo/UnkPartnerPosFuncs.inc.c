#include "common.h"

API_CALLABLE(N(SuperBlock_PartnerSparkles2)) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    fx_sparkles(FX_SPARKLES_2, partner->pos.x, partner->pos.y + 30.0f, partner->pos.z, 30.0f);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SuperBlock_PartnerSparkles4)) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    fx_sparkles(FX_SPARKLES_4, partner->pos.x, partner->pos.y + 30.0f, partner->pos.z, 30.0f);
    return ApiStatus_DONE2;
}
