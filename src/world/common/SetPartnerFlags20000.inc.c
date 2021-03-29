#include "common.h"

void N(SetPartnerFlags20000)(void) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    if (partner != NULL) {
        partner->flags |= 0x20000;
    }
}
