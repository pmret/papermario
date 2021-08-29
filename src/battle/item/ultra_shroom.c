#include "ultra_shroom.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_7239BC)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);
    s32 d = get_variable(script, *args++);

    playFX_40(0, a, b, c, d);
    return ApiStatus_DONE2;
}

ApiStatus N(func_802A12FC_723A7C)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->curHP += 10;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

EvtSource N(main) = SCRIPT({
    EVT_VAR(10) = (const) ITEM_SUPER_SHROOM;
    await N(UseItemWithEffect);
    AddBattleCamZoom(50);
    MoveBattleCamOver(20);
    await N(EatItem);
    GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(0) += 0;
    EVT_VAR(1) += 35;
    N(func_802A123C_7239BC)(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10);
    GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(1) += 25;
    EVT_VAR(2) += 5;
    func_802D7520(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10);
    N(func_802A12FC_723A7C)();
    sleep 10;
    SetAnimation(ACTOR_PLAYER, 0, ANIM_THUMBS_UP);
    sleep 30;
    GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
    EVT_VAR(2) += 5;
    func_802D75D8(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    sleep 20;
    await N(PlayerGoHome);
});
