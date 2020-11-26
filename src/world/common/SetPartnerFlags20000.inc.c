#include "common.h"

static void SetPartnerFlags20000(void) {
    Npc* partner = get_npc_safe(NpcId_PARTNER);

    if (partner != NULL) {
        partner->flags |= 0x20000;
    }
}
