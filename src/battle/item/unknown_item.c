#include "unknown_item.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_72447C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);
    s32 d = get_variable(script, *args++);

    playFX_40(0, a, b, c, d);
    return ApiStatus_DONE2;
}

ApiStatus N(func_802A12FC_72453C)(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->curHP += 20;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

EvtSource N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_ULTRA_SHROOM;
    await N(UseItemWithEffect);
    await N(EatItem);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 0;
    SI_VAR(1) += 35;
    N(func_802A123C_72447C)(SI_VAR(0), SI_VAR(1), SI_VAR(2), 20);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 25;
    SI_VAR(2) += 5;
    func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), 20);
    N(func_802A12FC_72453C)();
    sleep 10;
    SetAnimation(ACTOR_PLAYER, 0, ANIM_THUMBS_UP);
    sleep 30;
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(2) += 5;
    func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), 20);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    sleep 20;
    await N(PlayerGoHome);
});
