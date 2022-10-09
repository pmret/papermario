#include "machi.h"

extern s32 D_80241180_7E8520[];

ApiStatus func_802401B0_7E7550(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    if (rand_int(1000) < 500) {
        func_8005DECC(npc, -1, D_80241180_7E8520,
                      rand_int(4) + 1, rand_int(3) + 5, rand_int(50) + 50, rand_int(100) + 100);
    } else {
        func_8005DECC(npc, rand_int(3) + 10, D_80241180_7E8520,
                      rand_int(4) + 1, rand_int(3) + 5, rand_int(50) + 50, rand_int(100) + 10);
    }
    return ApiStatus_DONE2;
}

ApiStatus func_802402EC_7E768C(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    func_8005DFD4(npc);
    return ApiStatus_DONE2;
}

ApiStatus func_80240318_7E76B8(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    func_8005E12C(npc);
    return ApiStatus_DONE2;
}

ApiStatus func_80240344_7E76E4(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s32 i;

    playerData->curHP = 5;
    playerData->curMaxHP = 5;
    playerData->bootsLevel = 0;
    playerData->hammerLevel = -1;
    playerData->fortressKeyCount = 0;

    for (i = 0; i < ARRAY_COUNT(playerData->partners); i++) {
        playerData->partners[i].enabled = FALSE;
    }
    switch_to_partner(PARTNER_NONE);
    return ApiStatus_DONE2;
}

ApiStatus func_802403A0_7E7740(Evt* script, s32 isInitialCall) {
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);

    npc_set_palswap_mode_A(npc, 3);
    npc_set_palswap_1(npc, 0, 1, 30, 10);
    npc_set_palswap_2(npc, 60, 20, 0, 0);
    return ApiStatus_DONE2;
}

ApiStatus func_80240410_7E77B0(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s32 i;

    playerData->curHP = 8;
    playerData->curMaxHP = 8;
    playerData->bootsLevel = 0;
    playerData->hammerLevel = 0;
    playerData->fortressKeyCount = 0;
    playerData->partners[PARTNER_NONE].enabled = TRUE;

    for (i = 1; i < ARRAY_COUNT(playerData->partners); i++) {
        playerData->partners[i].enabled = FALSE;
    }
    return ApiStatus_DONE2;
}

ApiStatus func_8024045C_7E77FC(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    s32 i;

    playerData->curHP = 11;
    playerData->curMaxHP = 11;
    playerData->bootsLevel = 0;
    playerData->hammerLevel = 0;
    playerData->fortressKeyCount = 0;

    for (i = 0; i < ARRAY_COUNT(playerData->partners); i++) {
        playerData->partners[i].enabled = FALSE;
    }

    playerData->partners[PARTNER_NONE].enabled = TRUE;
    playerData->partners[PARTNER_GOOMBARIO].enabled = TRUE;
    playerData->partners[PARTNER_BOMBETTE].enabled = TRUE;
    return ApiStatus_DONE2;
}
