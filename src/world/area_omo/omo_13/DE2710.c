#include "omo_13.h"

#include "world/common/enemy/ShyGuyWanderAI.inc.c"

#include "world/common/enemy/GrooveGuyAI.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

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

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_80240F8C_DE341C);

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_80241028_DE34B8);
