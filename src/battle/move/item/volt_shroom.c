#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_volt_shroom

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(func_802A123C_71AA2C)) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;

    inflict_status(player, STATUS_KEY_STATIC, script->varTable[0]);
    player->statusAfflicted = 0;
    return ApiStatus_DONE2;
}

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    SetConst(LVarA, ITEM_VOLT_SHROOM)
    ExecWait(N(UseItemWithEffect))
    ExecWait(N(EatItem))
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Set(LVar3, 20)
    Call(MultiplyByActorScale, LVar3)
    Add(LVar1, LVar3)
    SetF(LVar3, Float(1.0))
    Call(MultiplyByActorScale, LVar3)
    PlayEffect(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, LVar3, 30, 0)
    Call(PlaySound, SOUND_VOLT_SHROOM_APPLY)
    Call(GetItemPower, ITEM_VOLT_SHROOM, LVar0, LVar1)
    Call(N(func_802A123C_71AA2C))
    Wait(20)
    Call(ShowMessageBox, BTL_MSG_PLAYER_CHARGED, 60)
    Call(WaitForMessageBoxDone)
    ExecWait(N(PlayerGoHome))
    Return
    End
};
