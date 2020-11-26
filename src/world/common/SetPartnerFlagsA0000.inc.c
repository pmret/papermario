#include "common.h"

static void SetPartnerFlagsA0000(void) {
    Npc* partner = get_npc_safe(NpcId_PARTNER);

    if (partner != NULL) {
        partner->flags |= 0xA0000;
    }
}
