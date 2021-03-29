#include "common.h"

ApiStatus N(DeadUnkPartnerPosFunc)(ScriptInstance* script, s32 isInitialCall) {
    Npc* partner = func_8003E534(NPC_PARTNER);

    dead_func_8006FEF0(2, partner->pos.x, partner->pos.y + 30.0f, partner->pos.z, 30.0f);
    return ApiStatus_DONE2;
}

ApiStatus N(DeadUnkPartnerPosFunc2)(ScriptInstance* script, s32 isInitialCall) {
    Npc* partner = func_8003E534(NPC_PARTNER);

    dead_func_8006FEF0(4, partner->pos.x, partner->pos.y + 30.0f, partner->pos.z, 30.0f);
    return ApiStatus_DONE2;
}
