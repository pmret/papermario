#include "common.h"

extern s32 D_802BE934;
extern f64 D_802BE900_319650;

extern struct unkPartnerStruct* D_802BE89C_3195EC;

#define NAMESPACE world_partner_bombette
#define UNK_PARTNER_SYMBOL D_802BE89C_3195EC
#define UNK_14_ADDITION D_802BE900_319650
#define IS_PLAYER_DATA_USED 3
#define IS_WALKING_PARTNER 1


INCLUDE_ASM(s32, "world/partner/bombette", func_802BD100_317E50);

INCLUDE_ASM(s32, "world/partner/bombette", func_802BD2D8_318028);

ApiStatus func_802BD300_318050(Evt* script, s32 isInitialCall) {
    Npc* unk = script->owner2.npc; // todo what is this

    if (isInitialCall) {
        partner_init_get_out(unk);
    }
    return partner_get_out(unk) != 0;
}

#include "world/common/UnkPartnerFunc2.inc.c"

INCLUDE_ASM(s32, "world/partner/bombette", func_802BD6DC_31842C);

s32 func_802BD720_318470(void) {
    if (gPartnerActionStatus.actionState.b[0] != 0) {
        D_802BE934 = 1;
        return FALSE;
    }
    return TRUE;
}

s32 func_802BD748(void) {
    return gPartnerActionStatus.actionState.b[0] == 0;
}

INCLUDE_ASM(s32, "world/partner/bombette", func_802BD758_3184A8);

ApiStatus func_802BE4E8_319238(Evt* script, s32 isInitialCall) {
    s32 unk = script->owner2.npc; // todo what is this

    if (isInitialCall) {
        partner_init_put_away(unk);
    }
    return partner_put_away(unk) != 0;
}

INCLUDE_ASM(s32, "world/partner/bombette", func_802BE520_319270);

INCLUDE_ASM(s32, "world/partner/bombette", func_802BE6E8_319438);
