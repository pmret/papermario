#include "kmr_02.h"

INCLUDE_ASM(s32, "world/area_kmr/kmr_02/8B33E0", func_80243370_8B33E0);

#include "world/common/SetEntityPositionF.inc.c"

#include "world/common/GetEntityPosition.inc.c"

static char* N(exit_str_6) = "tik_01";

ApiStatus func_80243514_8B3584(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(script->varTable[10]);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 60;
    }

    entity->scale.x = (60 - script->functionTemp[1]) / 60.0f;
    entity->scale.y = (60 - script->functionTemp[1]) / 60.0f;
    entity->scale.z = (60 - script->functionTemp[1]) / 60.0f;
    entity->rotation.y = (1.0f - cos_rad(entity->scale.y * PI)) * 990.0 * 0.5f;
    script->functionTemp[1]--;

    if (script->functionTemp[1] == -1) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
