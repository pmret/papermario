#include "flo_08.h"
#include "effects.h"

extern s32 N(ItemChoiceList)[];
extern s32 N(FlowerGuard_ItemChoiceList)[91];
extern s32 dead_flo_08_ItemChoice_HasSelectedItem;
extern s32 dead_flo_08_ItemChoice_SelectedItemID;

void dead_flo_08_UnkFloAI_Chase(Evt* script, MobileAISettings* aiSettings, EnemyDetectVolume* territory);

#include "world/common/enemy/ai/UnkFloAI.inc.c"

// following four functions can be folded into this combined include when the last two are done
// #include "world/common/atomic/ItemChoice_PartA.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

// Needs data migrated
#ifdef NON_MATCHING
ApiStatus dead_flo_08_ItemChoice_WaitForSelection(Evt *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    
    if (isInitialCall) {
        dead_flo_08_ItemChoice_HasSelectedItem = FALSE;
    }
    if (dead_flo_08_ItemChoice_HasSelectedItem) {
        dead_flo_08_ItemChoice_HasSelectedItem = FALSE;
        dead_evt_set_variable(script, *args++, dead_flo_08_ItemChoice_SelectedItemID);
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "ECAA80", func_8024199C_ECB69C);
#endif

// dead_flo_08_ItemChoice_SaveSelected (needs data?)

ApiStatus dead_flo_08_ItemChoice_SaveSelected(Evt *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    dead_flo_08_ItemChoice_SelectedItemID = dead_evt_get_variable(script, *args++);
    dead_flo_08_ItemChoice_HasSelectedItem = TRUE;
    return ApiStatus_DONE2;
}


#include "world/common/atomic/MakeConsumableChoice.inc.c"

#include "world/common/atomic/ItemChoice_FlowerGuard.inc.c"
