#include "nok_02.h"

static char* N(exit_str_0) = "nok_01";
static char* N(exit_str_1) = "nok_03";
static char* N(exit_str_2) = "tik_01";
static char* N(exit_str_3) = "";

#include "world/common/SetPlayerStatusAnimFlags100000.inc.c"

#include "world/common/GetCurrentFloor.inc.c"

#include "world/common/UnkFunc25.inc.c"

#include "world/common/GetEntryPos.inc.c"

#include "world/common/GetCurrentCameraYawClamped180.inc.c"

#include "world/common/SomeXYZFunc2.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7020", func_802402E0_9D7300);
/*
ApiStatus N(func_802402E0_9D7300)(ScriptInstance* script, s32 isInitialCall) {
    s32 i;

    if (N(D_802453D0_9DC3F0) == NULL) {
        N(D_802453D0_9DC3F0) = heap_malloc(16 * sizeof(s32));
        for (i = 0; i < 16; i++) {
            N(D_802453D0_9DC3F0)[i] = script->varTable[i];
        }
    } else {
        for (i = 0; i < 16; i++) {
            script->varTable[i] = N(D_802453D0_9DC3F0)[i];
        }
        heap_free(N(D_802453D0_9DC3F0));
        N(D_802453D0_9DC3F0) = NULL;
    }
    return ApiStatus_DONE2;
}
*/

#define NAMESPACE dup_nok_02
#include "world/common/GetItemName.inc.c"
#define NAMESPACE nok_02

#define NAMESPACE dup_nok_02
#include "world/common/GetNpcCollisionHeight.inc.c"
#define NAMESPACE nok_02

#define NAMESPACE dup_nok_02
#include "world/common/AddPlayerHandsOffset.inc.c"
#define NAMESPACE nok_02

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7020", func_80240624_9D7644);
/*
ApiStatus N(func_80240624_9D7644)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        N(D_80245434_9DC454) = FALSE;
    }

    if (N(D_80245434_9DC454)) {
        N(D_80245434_9DC454) = FALSE;
        set_variable(script, *args, N(D_80245438_9DC458));
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7020", func_80240678_9D7698);
/*
ApiStatus N(func_80240678_9D7698)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(D_80245438_9DC458) = get_variable(script, *args);
    N(D_80245434_9DC454) = TRUE;
    return ApiStatus_DONE2;
}
*/

INCLUDE_ASM(s32, "world/area_nok/nok_02/9D7020", func_802406B0_9D76D0);
/*
ApiStatus N(func_802406B0_9D76D0)(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_80244A20)[i] = ptr[i];
        }
        N(D_80244A20)[i] = 0;
    } else {
        for (i = 0; i < 0x70; i++) {
            N(D_80244A20)[i] = i + 16;
            N(D_80244A20)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}
*/
