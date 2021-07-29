#include "common.h"
#include "goompa.h"

static s32 goompa_802BD600;

void world_goompa_init(Npc* partner) {
    partner->collisionHeight = 24;
    partner->collisionRadius = 20;
}

ApiStatus GoompaTakeOut(ScriptInstance* script, s32 isInitialCall) {
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        partner_init_get_out(owner);
    }
    return partner_get_out(owner) != 0;
}

INCLUDE_ASM(s32, "world/partner/goompa", func_802BD14C_324A5C);

INCLUDE_ASM(s32, "world/partner/goompa", func_802BD4E0_324DF0);

ApiStatus GoompaUseAbility(ScriptInstance* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus GoompaPutAway(ScriptInstance* script, s32 isInitialCall) {
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        partner_init_put_away(owner);
    }
    return partner_put_away(owner) != 0;
}

Script world_goompa_take_out = SCRIPT({
    GoompaTakeOut();
});

s32 D_802BD58C_324E9C = &goompa_802BD600;

Script world_goompa_update = SCRIPT({
    func_802BD14C_324A5C();
});

Script world_goompa_use_ability = SCRIPT({
    GoompaUseAbility();
});

Script world_goompa_put_away = SCRIPT({
    GoompaPutAway();
});
