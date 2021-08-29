#include "dried_shroom.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_71CF1C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    playFX_40(0, a, b, c, d);

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A12FC_71CFDC)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->curHP++;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

EvtSource N(main) = SCRIPT({
    EVT_VAR(10) = (const) ITEM_DRIED_SHROOM;
    await N(UseItemWithEffect);
    await N(EatItem);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_STICK_OUT_TONGUE);
    GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) += 0;
    EVT_VAR(1) += 35;
    N(func_802A123C_71CF1C)(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1);
    GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(1) += 25;
    EVT_VAR(2) += 5;
    func_802D7520(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1);
    N(func_802A12FC_71CFDC)();
    sleep 30;
    GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(2) += 5;
    func_802D75D8(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    sleep 20;
    await N(PlayerGoHome);
});
