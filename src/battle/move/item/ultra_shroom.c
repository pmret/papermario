#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_ultra_shroom

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(SpawnHeartRecoveryFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(0, a, b, c, d);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(HealPlayer10)) {
    PlayerData* playerData = &gPlayerData;

    playerData->curHP += 10;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }
    return ApiStatus_DONE2;
}

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    SetConst(LVarA, ITEM_SUPER_SHROOM)
    ExecWait(N(UseItemWithEffect))
    Call(AddBattleCamDist, 50)
    Call(MoveBattleCamOver, 20)
    ExecWait(N(EatItem))
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 0)
    Add(LVar1, 35)
    Call(N(SpawnHeartRecoveryFX), LVar0, LVar1, LVar2, 10)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 25)
    Add(LVar2, 5)
    Call(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, 10)
    Call(N(HealPlayer10))
    Wait(10)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_ThumbsUp)
    Wait(30)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar2, 5)
    Call(ShowRecoveryShimmer, LVar0, LVar1, LVar2, 10)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Wait(20)
    ExecWait(N(PlayerGoHome))
    Return
    End
};
