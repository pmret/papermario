#include "common.h"
#include "map.h"

void M(SetPartnerFlags80000)(void) {
    Npc* partner = get_npc_safe(NpcId_PARTNER);

    if (partner != NULL) {
        partner->flags |= 0x80000;
    }
}
