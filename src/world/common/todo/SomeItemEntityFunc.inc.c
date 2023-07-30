#include "common.h"
#include "npc.h"

API_CALLABLE(N(SomeItemEntityFunc)) {
    ItemEntity* itemEntity = get_item_entity(script->varTable[0]);

    if (isInitialCall) {
        script->functionTempF[2] = itemEntity->pos.y;
        script->functionTemp[1] = 0;
        script->functionTemp[3] = 0;
    }

    switch (script->functionTemp[1]) {
        case 0:
            itemEntity->pos.y = script->functionTempF[2] + ((1.0f - cos_rad((script->functionTemp[3] *
                                     (PI / 2)) / 30.0f)) * 20.0f);
            if (script->functionTemp[3] == 30) {
                script->functionTemp[1] = 1;
                script->functionTemp[3] = 0;
            } else {
                script->functionTemp[3]++;
            }
            break;
        case 1:
            itemEntity->pos.y = script->functionTempF[2] + 17.0f + (cos_deg(script->functionTemp[3]) * 3.0f);
            script->functionTemp[3] = clamp_angle(script->functionTemp[3] + 9);
            break;
    }

    return ApiStatus_BLOCK;
}

