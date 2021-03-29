#include "common.h"
#include "map.h"

void N(SetPartnerFlags80000)(void) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    if (partner != NULL) {
        partner->flags |= 0x80000;
    }
}
