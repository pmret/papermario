#include "jan_04.h"

//static f64 D_802462E0_B4AA50[4] = {990.0, 2.732579860045591e+204, 2.732579860045591e+204, 0.0}; /* const */

#include "world/common/SetEntityPositionF.inc.c"

#include "world/common/GetEntityPosition.inc.c"

// Can't get this to match because the const array above is in "discarded section .data"
#ifdef NON_MATCHING
ApiStatus func_80240BE8_B45358(Evt* script, s32 isInitialCall) {
    Entity* entity = get_entity_by_index(script->varTable[10]);

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 60;
    }

    entity->scale.x = (60 - script->functionTemp[1]) / 60.0f;
    entity->scale.y = (60 - script->functionTemp[1]) / 60.0f;
    entity->scale.z = (60 - script->functionTemp[1]) / 60.0f;
    entity->rotation.y = (1.0f - cos_rad(entity->scale.y * PI)) * D_802462E0_B4AA50[0] * 0.25f;
    script->functionTemp[1]--;

    if (script->functionTemp[1] == -1) {
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_jan/jan_04/B451F0", func_80240BE8_B45358);
#endif

INCLUDE_ASM(s32, "world/area_jan/jan_04/B451F0", func_80240D0C_B4547C);

#define NAMESPACE dup_jan_04
#include "world/common/foliage.inc.c"
#define NAMESPACE jan_04
