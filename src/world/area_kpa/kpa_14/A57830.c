#include "kpa_14.h"

INCLUDE_ASM(s32, "world/area_kpa/kpa_14/A57830", func_80240380_A57830);

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

#include "world/common/SetEntityFlags100000.inc.c"

#include "world/common/GetEntityPosition.inc.c"

ApiStatus N(func_80240710_A57BC0)(Evt* script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;

    evt_set_variable(script, *script->ptrReadPos, collisionStatus->floorBelow);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kpa/kpa_14/A57830", func_8024073C_A57BEC);

INCLUDE_ASM(s32, "world/area_kpa/kpa_14/A57830", func_80240840_A57CF0);
