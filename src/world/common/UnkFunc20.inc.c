#include "common.h"
#include "map.h"

ApiStatus N(UnkFunc20)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 entityIdx = get_variable(script, *args++);
    Entity* entity = get_entity_by_index(entityIdx);
    s32 si_var = *args++;
    EffectInstance* effectInst = func_80071750(0, entity->position.x, entity->position.y + 12.5f, entity->position.z, 0.7f,
                                 0);

    set_variable(script, si_var, (s32) effectInst);

    return ApiStatus_DONE2;
}
