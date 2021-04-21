#include "tst_11.h"

// TODO: match up functions from reflection.inc.c here

INCLUDE_ASM(s32, "world/area_tst/tst_11/B1CA50", func_80240000_B1CA50);

INCLUDE_ASM(s32, "world/area_tst/tst_11/B1CA50", func_8024003C_B1CA8C);

INCLUDE_ASM(s32, "world/area_tst/tst_11/B1CA50", func_80240100_B1CB50);

INCLUDE_ASM(s32, "world/area_tst/tst_11/B1CA50", func_802402B8_B1CD08);

INCLUDE_ASM(s32, "world/area_tst/tst_11/B1CA50", func_802402F4_B1CD44);

INCLUDE_ASM(s32, "world/area_tst/tst_11/B1CA50", func_802403B8_B1CE08);

INCLUDE_ASM(s32, "world/area_tst/tst_11/B1CA50", func_802406D4_B1D124);

void N(SetPartnerFlagsA0000)(void) {
    Npc* partner = get_npc_safe(NPC_PARTNER);

    if (partner != NULL) {
        partner->flags |= 0xA0000;
    }
}
