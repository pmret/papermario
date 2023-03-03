#include "common.h"
#include "npc.h"

API_CALLABLE(N(CheckPartnerFlags1000)) {
    if (get_npc_unsafe(NPC_PARTNER)->flags & NPC_FLAG_GROUNDED) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}
