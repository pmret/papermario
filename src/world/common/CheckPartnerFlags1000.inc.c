#include "common.h"
#include "npc.h"

ApiStatus N(CheckPartnerFlags1000)(Evt* script, s32 isInitialCall) {
    return ((get_npc_unsafe(NPC_PARTNER)->flags & 0x1000) != 0) * ApiStatus_DONE2;
}
