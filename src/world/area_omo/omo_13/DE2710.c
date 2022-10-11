#include "omo_13.h"

#include "world/common/enemy/ShyGuyWanderAI.inc.c"

#include "world/common/enemy/GrooveGuyAI.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

// matches, needs data migration
#ifdef NON_MATCHING
ApiStatus func_80240F00_DE3390(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    if (isInitialCall) {
        D_80241C04_DE4094 = FALSE;
    }
    
    if (D_80241C04_DE4094) {
        D_80241C04_DE4094 = FALSE;
        evt_set_variable(script, *args++, D_80241C08_DE4098);
        return ApiStatus_DONE2;
    }
    
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_80240F00_DE3390);
#endif

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_80240F54_DE33E4);

extern s32 flo_10_npcSettings_80243220[];

ApiStatus func_80240F8C_DE341C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            flo_10_npcSettings_80243220[i] = ptr[i];
        }
        flo_10_npcSettings_80243220[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            flo_10_npcSettings_80243220[i] = i + 128;
            flo_10_npcSettings_80243220[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_80241028_DE34B8);
