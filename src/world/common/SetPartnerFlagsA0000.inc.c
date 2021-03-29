#include "common.h"
#include "map.h"

void N(SetPartnerFlagsA0000)(void) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    if (partner != NULL) {
        partner->flags |= 0xA0000;
    }
}
