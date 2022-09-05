#include "osr_01.h"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

extern s32 D_8024121C_AB120C;
extern s32 D_80241220_AB1210;

// Needs data migrated
#ifdef NON_MATCHING
ApiStatus func_802406A4_AB0694(Evt* script, s32 isInitialCall) { 
    s32* temp = script->ptrReadPos;
    
    if (isInitialCall != 0) {
        D_8024121C_AB120C = 0;
    }
    
    if (D_8024121C_AB120C != 0) {
        D_8024121C_AB120C = 0;
        evt_set_variable(script, *temp, D_80241220_AB1210);
        return ApiStatus_DONE2;
    }
    
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_osr/osr_01/AB0350", func_802406A4_AB0694);
#endif

// Needs data migrated
#ifdef NON_MATCHING
ApiStatus func_802406F8_AB06E8(Evt* script, s32 isInitialCall) {
    D_80241220_AB1210 = evt_get_variable(script, *script->ptrReadPos);
    D_8024121C_AB120C = 1;
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_osr/osr_01/AB0350", func_802406F8_AB06E8);
#endif

INCLUDE_ASM(s32, "world/area_osr/osr_01/AB0350", func_80240730_AB0720);

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/LetterDelivery.inc.c"
