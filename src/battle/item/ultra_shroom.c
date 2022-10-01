#include "ultra_shroom.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_7239BC)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(0, a, b, c, d);
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

EvtScript N(main) = {
    EVT_SET_CONST(LVarA, 0x0000008C)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(AddBattleCamZoom, 50)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_EXEC_WAIT(N(EatItem))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 0)
    EVT_ADD(LVar1, 35)
    EVT_CALL(N(func_802A123C_7239BC), LVar0, LVar1, LVar2, 10)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_ADD(LVar2, 5)
    EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, 10)
    EVT_CALL(N(func_802A12FC_723A7C))
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_ThumbsUp)
    EVT_WAIT(30)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 5)
    EVT_CALL(ShowRecoveryShimmer, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_WAIT(20)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
