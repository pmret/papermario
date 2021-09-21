#include "common.h"

extern struct unkPartnerStruct* D_802BEAAC_31B01C;

#define NAMESPACE world_partner_parakarry
#define UNK_PARTNER_SYMBOL D_802BEAAC_31B01C
#define UNK_14_ADDITION 0.8
#define IS_PLAYER_DATA_USED 4
#define IS_WALKING_PARTNER 0

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BD100_319670);

ApiStatus func_802BD148_3196B8(Evt* script, s32 isInitialCall) {
    Npc* unk = script->owner2.npc; // todo what is this

    if (isInitialCall) {
        partner_init_get_out(unk);
    }
    return partner_get_out(unk) != 0;
}

#include "world/common/UnkPartnerFunc2.inc.c"

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BD514_319A84);

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BD558_319AC8);

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BD660_319BD0);

ApiStatus func_802BE8D4_31AE44(Evt* script, s32 isInitialCall) {
    s32 unk = script->owner2.npc; // todo what is this

    if (isInitialCall) {
        partner_init_put_away(unk);
    }
    return partner_put_away(unk) != 0;
}

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BE90C_31AE7C);

INCLUDE_ASM(s32, "world/partner/parakarry", func_802BE9D0_31AF40);
