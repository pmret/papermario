#include "nok_02.h"

#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"

#include "world/common/GetCurrentFloor.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7020", func_80240034_9D7054);

#include "world/common/GetEntryPos.inc.c"

#include "world/common/GetCurrentCameraYawClamped180.inc.c"

#include "world/common/SomeXYZFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7020", func_802402E0_9D7300);
/*
ApiStatus N(func_802402E0_9D7300)(ScriptInstance* script, s32 isInitialCall) {
    s32** ptr = &D_80241C68_BE09F8;
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
        ptr = &D_80241C68_BE09F8;
        heap_free(*ptr);
        *ptr = NULL;
    }
    return 2;
}
*/

#define NAMESPACE dup_nok_02
#include "world/common/GetItemName.inc.c"
#define NAMESPACE nok_02

#define NAMESPACE dup_nok_02
#include "world/common/GetNpcCollisionHeight.inc.c"
#define NAMESPACE nok_02

#define NAMESPACE dup_nok_02
#include "world/common/SomeXYZFuncTodoRename.inc.c"
#define NAMESPACE nok_02

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7020", func_80240624_9D7644);
/*
ApiStatus N(func_80240624_9D7644)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr;

    if (isInitialCall) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
    }

    ptr = &D_80241CCC_BE0A5C;
    if (*ptr != NULL) {
        ptr = &D_80241CCC_BE0A5C;
        *ptr = 0;
        set_variable(script, *args, D_80241CD0_BE0A60);
        return 2;
    }

    return 0;
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7020", func_80240678_9D7698);
/*
ApiStatus N(func_80240678_9D7698)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    D_80241CD0_BE0A60 = get_variable(script, *args);
    D_80241CCC_BE0A5C = 1;
    return 2;
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7020", func_802406B0_9D76D0);
