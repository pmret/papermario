#include "common.h"
#include "goombaria.h"
#include "../partners.h"

void world_goombaria_init(Npc* partner) {
    partner->collisionHeight = 24;
    partner->collisionRadius = 20;
}

ApiStatus GoombariaTakeOut(ScriptInstance* script, s32 isInitialCall) {
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        func_800EECC4(owner);
    }
    return func_800EECE8(owner) != 0;
}

ApiStatus GoombariaUpdate(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        enable_partner_walking(owner, TRUE);
    }

    func_800EBA3C(owner);
    func_800EBB40(owner);
    playerData->unk_2F4[PARTNER_GOOMBARIA]++;

    return ApiStatus_BLOCK;
}

ApiStatus GoombariaUseAbility(ScriptInstance* script, s32 isInitialCall) {
    return ApiStatus_DONE2;
}

ApiStatus GoombariaPutAway(ScriptInstance* script, s32 isInitialCall) {
    Npc* owner = script->owner2.npc;

    if (isInitialCall) {
        func_800EE994(owner);
    }
    return func_800EE9B8(owner) != 0;
}

Script world_goombaria_take_out = SCRIPT({
    GoombariaTakeOut();
});

Script world_goombaria_update = SCRIPT({
    GoombariaUpdate();
});

Script world_goombaria_use_ability = SCRIPT({
    GoombariaUseAbility();
});

Script world_goombaria_put_away = SCRIPT({
    GoombariaPutAway();
});
