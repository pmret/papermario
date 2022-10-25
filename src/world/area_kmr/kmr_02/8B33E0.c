#include "kmr_02.h"

ApiStatus func_80243370_8B33E0(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s32 cond = FALSE;
    s32 i;

    for (i = 0; i < ARRAY_COUNT(playerData->equippedBadges); i++) {
        if (playerData->equippedBadges[i] != 0) {
            cond = TRUE;
            break;
        }
    }

    script->varTable[0] = cond;
    return ApiStatus_DONE2;
}

#include "world/common/todo/SetEntityPositionF.inc.c"

#include "world/common/todo/GetEntityPosition.inc.c"

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
