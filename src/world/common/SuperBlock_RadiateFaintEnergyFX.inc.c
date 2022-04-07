#include "common.h"
#include "npc.h"

ApiStatus N(SuperBlock_RadiateFaintEnergyFX)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_safe(-4);

    fx_radial_shimmer(9, npc->pos.x, npc->pos.y + 12.5f, npc->pos.z, 1.0f, 0x1E);

    return ApiStatus_DONE2;
}
