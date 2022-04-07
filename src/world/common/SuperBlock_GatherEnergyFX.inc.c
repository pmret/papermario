#include "common.h"
#include "npc.h"

ApiStatus N(SuperBlock_GatherEnergyFX)(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(evt_get_variable(script, *script->ptrReadPos));

    fx_radial_shimmer(4, entity->position.x, entity->position.y + 12.5f, entity->position.z, 1.0f, 0x4B);

    return ApiStatus_DONE2;
}
