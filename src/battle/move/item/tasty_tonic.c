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
    SetConst(LVarA, ITEM_TASTY_TONIC)
    ExecWait(battle_item_tasty_tonic_UseItemWithEffect)
    Call(InitTargetIterator)
    Call(GetOwnerTarget, LVar0, LVar1)
    IfEq(LVar0, 0)
        ExecWait(battle_item_tasty_tonic_DrinkItem)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 25)
        Add(LVar2, 5)
        Call(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, 10)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 20)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_ThumbsUp)
        Wait(30)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar2, 5)
        Call(ShowRecoveryShimmer, LVar0, LVar1, LVar2, 10)
        Call(battle_item_tasty_tonic_func_802A123C_72223C, 0)
        Wait(20)
    Else
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar1, 25)
        Add(LVar2, 5)
        Call(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, 5)
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar1, 20)
        Wait(30)
        Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
        Add(LVar2, 5)
        Call(ShowRecoveryShimmer, LVar0, LVar1, LVar2, 5)
        Call(battle_item_tasty_tonic_func_802A123C_72223C, 256)
        Wait(20)
    EndIf
    ExecWait(battle_item_tasty_tonic_PlayerGoHome)
    Return
    End
};
