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
    EVT_SET_CONST(LVarA, ITEM_VOLT_SHROOM)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_EXEC_WAIT(N(EatItem))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, 20)
    EVT_CALL(MultiplyByActorScale, LVar3)
    EVT_ADD(LVar1, LVar3)
    EVT_SETF(LVar3, EVT_FLOAT(1.0))
    EVT_CALL(MultiplyByActorScale, LVar3)
    EVT_PLAY_EFFECT(EFFECT_SNAKING_STATIC, 0, LVar0, LVar1, LVar2, LVar3, 30, 0)
    EVT_CALL(PlaySound, SOUND_VOLT_SHROOM_APPLY)
    EVT_CALL(GetItemPower, ITEM_VOLT_SHROOM, LVar0, LVar1)
    EVT_CALL(N(func_802A123C_71AA2C))
    EVT_WAIT(20)
    EVT_CALL(ShowMessageBox, BTL_MSG_PLAYER_CHARGED, 60)
    EVT_CALL(WaitForMessageBoxDone)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
