#include "common.h"
#include "../partners.h"

extern s32 D_802BE0C0;
extern s32 D_802BE0C4;

void func_802BD100_323A50(Npc* partner) {
    partner->collisionHeight = 26;
    partner->collisionRadius = 24;
    partner->renderMode = RENDER_MODE_SURFACE_XLU_LAYER1;
    D_802BE0C4 = 0;
    D_802BE0C0 = 0;
}

ApiStatus func_802BD130_323A80(Evt* script, s32 isInitialCall) {
    Npc* owner = script->owner2.npc;
    if (isInitialCall) {
        partner_init_get_out(owner);
    }
    return partner_get_out(owner) != 0;
}

INCLUDE_ASM(s32, "world/partner/bow", func_802BD168_323AB8);

INCLUDE_ASM(s32, "world/partner/bow", func_802BD4FC_323E4C);

INCLUDE_ASM(s32, "world/partner/bow", func_802BD540_323E90);

INCLUDE_ASM(s32, "world/partner/bow", func_802BD694_323FE4);

INCLUDE_ASM(s32, "world/partner/bow", func_802BDDF0_324740);

INCLUDE_ASM(s32, "world/partner/bow", func_802BDF08_324858);

INCLUDE_ASM(s32, "world/partner/bow", func_802BDF64_3248B4);
