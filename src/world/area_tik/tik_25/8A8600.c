#include "tik_25.h"
#include "entity.h"

ApiStatus func_80240680_8A8600(Evt* script, s32 isInitialCall) {
    get_entity_by_index(script->varTable[0])->dataBuf.chest->gotItemDone = TRUE;
    return ApiStatus_DONE2;
}

#include "world/common/todo/SetEntityPosition.inc.c"

// linker sym needed
#ifdef NON_MATCHING
ApiStatus func_80240770_8A86F0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Entity* entity;

    entity = get_entity_by_index(evt_get_variable(script, *args++));
    if (entity == NULL) {
        return ApiStatus_BLOCK;
    }
    play_model_animation(entity->virtualModelIndex, 0x1E4);
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_tik/tik_25/8A8600", func_80240770_8A86F0);
#endif
