#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_tasty_tonic

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(func_802A123C_72223C)) {
    s32 actorId = evt_get_variable(script, *script->ptrReadPos);
    Actor* actor = get_actor(actorId);
    s32 id = actor->actorID & ACTOR_CLASS_MASK;

    if (actor->debuff != 0) {
        actor->debuffDuration = 0;
        actor->debuff = 0;
        remove_status_debuff(actor->hudElementDataIndex);
    }

    if (actor->koStatus != 0) {
        actor->koDuration = 0;
        actor->koStatus = 0;

        switch (id) {
            case ACTOR_CLASS_PLAYER:
                break;
            case ACTOR_CLASS_PARTNER:
                dispatch_event_partner(EVENT_RECOVER_STATUS);
        }
        actor->disableEffect->data.disableX->koDuration = 0;
    }

    return ApiStatus_DONE2;
}

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    EVT_SET_CONST(LVarA, ITEM_TASTY_TONIC)
    EVT_EXEC_WAIT(battle_item_tasty_tonic_UseItemWithEffect)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_IF_EQ(LVar0, 0)
        EVT_EXEC_WAIT(battle_item_tasty_tonic_DrinkItem)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 25)
        EVT_ADD(LVar2, 5)
        EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, 10)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_ThumbsUp)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 5)
        EVT_CALL(ShowRecoveryShimmer, LVar0, LVar1, LVar2, 10)
        EVT_CALL(battle_item_tasty_tonic_func_802A123C_72223C, 0)
        EVT_WAIT(20)
    EVT_ELSE
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 25)
        EVT_ADD(LVar2, 5)
        EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, 5)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_WAIT(30)
        EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 5)
        EVT_CALL(ShowRecoveryShimmer, LVar0, LVar1, LVar2, 5)
        EVT_CALL(battle_item_tasty_tonic_func_802A123C_72223C, 256)
        EVT_WAIT(20)
    EVT_END_IF
    EVT_EXEC_WAIT(battle_item_tasty_tonic_PlayerGoHome)
    EVT_RETURN
    EVT_END
};
