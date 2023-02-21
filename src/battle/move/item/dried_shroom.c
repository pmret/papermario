#include "common.h"
#include "script_api/battle.h"
#include "effects.h"

#define NAMESPACE battle_item_dried_shroom

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(ShowHeartRecoveryFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(0, a, b, c, d);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802A12FC_71CFDC)) {
    PlayerData* playerData = &gPlayerData;

    playerData->curHP++;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    return ApiStatus_DONE2;
}

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    EVT_SET_CONST(LVarA, ITEM_DRIED_SHROOM)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_EXEC_WAIT(N(EatItem))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_StickOutTongue)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 0)
    EVT_ADD(LVar1, 35)
    EVT_CALL(N(ShowHeartRecoveryFX), LVar0, LVar1, LVar2, 1)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_ADD(LVar2, 5)
    EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, 1)
    EVT_CALL(N(func_802A12FC_71CFDC))
    EVT_WAIT(30)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar2, 5)
    EVT_CALL(ShowRecoveryShimmer, LVar0, LVar1, LVar2, 1)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_WAIT(20)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
