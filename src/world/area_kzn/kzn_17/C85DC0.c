#include "kzn_17.h"

#include "world/common/enemy/PiranhaPlantAI.inc.c"

#include "world/common/enemy/LungeAI.inc.c"

#include "world/common/AwaitPlayerNearNpc.inc.c"

#include "world/common/StashVars.inc.c"

#include "world/common/GetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_802428E0_C88390);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_80242934_C883E4);

INCLUDE_ASM(s32, "world/area_kzn/kzn_17/C85DC0", func_8024296C_C8841C);

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

extern s32 N(LetterDelivery_SavedNpcAnim);

ApiStatus N(LetterDelivery_SaveNpcAnim)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->varTable[2]);
    N(LetterDelivery_SavedNpcAnim) = npc->currentAnim.w;
    npc->currentAnim.w = script->varTable[4];
    return ApiStatus_DONE2;
}

ApiStatus N(LetterDelivery_RestoreNpcAnim)(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->varTable[2]);
    npc->currentAnim.w = N(LetterDelivery_SavedNpcAnim);
    return ApiStatus_DONE2;
}
