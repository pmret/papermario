#include "common.h"
#include "map.h"

void M(SetPartnerFlagsA0000)(void) {
    Npc* partner = get_npc_safe(NpcId_PARTNER);

    if (partner != NULL) {
        partner->flags |= 0xA0000;
    }
}
