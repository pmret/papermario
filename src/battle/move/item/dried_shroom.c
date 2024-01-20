#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_dried_shroom

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(SpawnHeartRecoveryFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 x = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 z = evt_get_variable(script, *args++);
    s32 duration = evt_get_variable(script, *args++);

    fx_recover(0, x, y, z, duration);

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
    SetConst(LVarA, ITEM_DRIED_SHROOM)
    ExecWait(N(UseItemWithEffect))
    ExecWait(N(EatItem))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_StickOutTongue)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 0)
    Add(LVar1, 35)
    Call(N(SpawnHeartRecoveryFX), LVar0, LVar1, LVar2, 1)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 25)
    Add(LVar2, 5)
    Call(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, 1)
    Call(N(func_802A12FC_71CFDC))
    Wait(30)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar2, 5)
    Call(ShowRecoveryShimmer, LVar0, LVar1, LVar2, 1)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Wait(20)
    ExecWait(N(PlayerGoHome))
    Return
    End
};
