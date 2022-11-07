#include "kzn_17.h"

const char ascii_EA6D70[] = "kzn_11";
const char ascii_EA6D78[] = "kzn_18";
extern s32 N(D_802466D0)[];

void func_8004D8E0(DeadEnemy*);

#include "world/common/enemy/ai/WanderMeleeAI.inc.c"
#include "world/common/enemy/wip/PiranhaPlantAI_00.inc.c"
#include "world/common/enemy/wip/PiranhaPlantAI_01.inc.c"
#include "world/common/enemy/wip/PiranhaPlantAI_10.inc.c"
#include "world/common/enemy/wip/PiranhaPlantAI_11.inc.c"
#include "world/common/enemy/wip/PiranhaPlantAI_12.inc.c"
#include "world/common/enemy/wip/PiranhaPlantAI_13.inc.c"
#include "world/common/enemy/wip/PiranhaPlantAI_14.inc.c"
#include "world/common/enemy/wip/Dead_PiranhaPlantAI_Main.inc.c"

#include "world/common/enemy/ai/TackleAI.inc.c"

#include "world/common/todo/AwaitPlayerNearNpc.inc.c"

#include "world/common/todo/StashVars.inc.c"

#include "world/common/todo/GetItemName.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

// Requires data migration
#ifdef NON_MATCHING
ApiStatus func_802429C0_EA32C0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        dead_kzn_17_ItemChoice_HasSelectedItem = FALSE;
    }

    if (dead_kzn_17_ItemChoice_HasSelectedItem) {
        dead_kzn_17_ItemChoice_HasSelectedItem = FALSE;
        evt_set_variable(script, *args++, dead_kzn_17_ItemChoice_SelectedItemID);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "EA0C10", func_802429C0_EA32C0);
#endif

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

ApiStatus func_80242A4C_EA334C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            N(D_802466D0)[i] = ptr[i];
        }
        N(D_802466D0)[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            N(D_802466D0)[i] = i + 16;
            N(D_802466D0)[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 N(LetterDelivery_SavedNpcAnim);
#include "world/common/todo/LetterDelivery.inc.c"
