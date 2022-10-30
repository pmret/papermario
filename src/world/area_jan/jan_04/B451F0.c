#include "jan_04.h"

#include "world/common/todo/SetEntityPositionF.inc.c"

#include "world/common/todo/GetEntityPosition.inc.c"

ApiStatus func_80240BE8_B45358(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(script->varTable[10]);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 60;
    }

    entity->scale.x = (60 - script->functionTemp[1]) / 60.0f;
    entity->scale.y = (60 - script->functionTemp[1]) / 60.0f;
    entity->scale.z = (60 - script->functionTemp[1]) / 60.0f;
    entity->rotation.y = (1.0f - cos_rad(entity->scale.y * PI)) * 990.0 * 0.25f;
    script->functionTemp[1]--;

    if (script->functionTemp[1] == -1) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

const char* N(exit_str_0) = "jan_04\0"; // remove \0 when this is part of a script and not an isolated symbol
const char* N(exit_str_1) = "jan_04";

ApiStatus func_80240D0C_B4547C(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(script->varTable[10]);

    if (isInitialCall) {
        script->functionTemp[0] = -30;
    }
    entity->rotation.x = script->functionTemp[0];
    entity->rotation.z = script->functionTemp[0];
    script->functionTemp[0]++;

    if (script->functionTemp[0] == 1) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

#define NAMESPACE dup_jan_04
#include "common/foliage.inc.c"
#define NAMESPACE jan_04
