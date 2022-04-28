#include "common.h"

// incomplete dedupe -- only the last two functions for now

/*
#include "world/common/LetterDelivery.inc.c"
*/

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

