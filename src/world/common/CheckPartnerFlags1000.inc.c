#include "common.h"
#include "npc.h"

ApiStatus N(CheckPartnerFlags1000)(Evt* script, s32 isInitialCall) {
    if (get_npc_unsafe(NPC_PARTNER)->flags & NPC_FLAG_1000) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}
