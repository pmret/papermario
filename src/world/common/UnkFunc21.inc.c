#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc21)(ScriptInstance* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(get_variable(script, *script->ptrReadPos));

    playFX_33(4, entity->position.x, entity->position.y + 12.5f, entity->position.z, 1.0f, 0x4B);

    return ApiStatus_DONE2;
}
