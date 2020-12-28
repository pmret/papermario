#include "common.h"
#include "map.h"

ApiStatus N(SomeItemEntityFunc)(ScriptInstance* script, s32 isInitialCall) {
    ItemEntity* itemEntity = get_item_entity(script->varTable[0]);

    if (isInitialCall) {
        script->functionTemp[2].f = itemEntity->position.y;
        script->functionTemp[1].s = 0;
        script->functionTemp[3].s = 0;
    }

    switch (script->functionTemp[1].s) {
        case 0:
            itemEntity->position.y = script->functionTemp[2].f + ((1.0f - cos_rad((script->functionTemp[3].s *
                                     (PI / 2)) / 30.0f)) * 20.0f);
            if (script->functionTemp[3].s == 30) {
                script->functionTemp[1].s = 1;
                script->functionTemp[3].s = 0;
            } else {
                script->functionTemp[3].s++;
            }
            break;
        case 1:
            itemEntity->position.y = script->functionTemp[2].f + 17.0f + (cos_deg(script->functionTemp[3].s) * 3.0f);
            script->functionTemp[3].s = clamp_angle(script->functionTemp[3].s + 9);
            break;
    }

    return ApiStatus_BLOCK;
}

