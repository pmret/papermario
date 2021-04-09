#include "kpa_14.h"

INCLUDE_ASM(s32, "world/area_kpa/kpa_14/A57830", func_80240380_A57830);
/*
ApiStatus N(func_80240380_A57830)(ScriptInstance* script, s32 isInitialCall) {
    s32** ptr = &N(D_80241C68_BE09F8);
    s32 i;
    s32* test;

    if (*ptr == NULL) {
        i = heap_malloc(16 * sizeof(s32));
        *ptr = i;
        for (i = 0, test = *ptr; i < 16; i++) {
            *test++ = script->varTable[i];
        }
    } else {
        for (i = 0, test = *ptr; i < 16; i++) {
            script->varTable[i] = *test++;
        }
        ptr = &N(D_80241C68_BE09F8);
        heap_free(*ptr);
        *ptr = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#include "world/common/GetItemName.inc.c"

#include "world/common/SomeItemEntityFunc.inc.c"

#include "world/common/CheckItemFlags40.inc.c"

#include "world/common/SetEntityFlags100000.inc.c"

#include "world/common/GetEntityPosition.inc.c"

ApiStatus N(UnkFunc30)(ScriptInstance *script, s32 isInitialCall) {
    CollisionStatus* collisionStatus = &gCollisionStatus;

    set_variable(script, *script->ptrReadPos, collisionStatus->floorBelow);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_kpa/kpa_14/A57830", func_8024073C_A57BEC);

INCLUDE_ASM(s32, "world/area_kpa/kpa_14/A57830", func_80240840_A57CF0);
