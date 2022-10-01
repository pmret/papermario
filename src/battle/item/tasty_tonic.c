#include "tasty_tonic.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_72223C)(Evt* script, s32 isInitialCall) {
    s32 actorId = evt_get_variable(script, *script->ptrReadPos);
    Actor* actor = get_actor(actorId);
    s32 id = actor->actorID & ACTOR_CLASS_MASK;

    if (actor->debuff != STATUS_END) {
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
        actor->disableEffect->data.disableX->unk_3C = 0;
    }

    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

EvtScript N(main) = {
    EVT_SET_CONST(LVarA, 0x89)
    EVT_EXEC_WAIT(battle_item_tasty_tonic_UseItemWithEffect)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_IF_EQ(LVar0, 0)
        EVT_EXEC_WAIT(battle_item_tasty_tonic_DrinkItem)
        EVT_CALL(GetActorPos, 0, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 25)
        EVT_ADD(LVar2, 5)
        EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, 10)
        EVT_CALL(GetActorPos, 0, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_CALL(SetAnimation, 0, 0, 65586)
        EVT_WAIT(30)
        EVT_CALL(SetAnimation, 0, 0, 65538)
        EVT_CALL(GetActorPos, 0, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 5)
        EVT_CALL(ShowRecoveryShimmer, LVar0, LVar1, LVar2, 10)
        EVT_CALL(battle_item_tasty_tonic_func_802A123C_72223C, 0)
        EVT_WAIT(20)
    EVT_ELSE
        EVT_CALL(GetActorPos, 256, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 25)
        EVT_ADD(LVar2, 5)
        EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, 5)
        EVT_CALL(GetActorPos, 256, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 20)
        EVT_WAIT(30)
        EVT_CALL(GetActorPos, 256, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 5)
        EVT_CALL(ShowRecoveryShimmer, LVar0, LVar1, LVar2, 5)
        EVT_CALL(battle_item_tasty_tonic_func_802A123C_72223C, 256)
        EVT_WAIT(20)
    EVT_END_IF
    EVT_EXEC_WAIT(battle_item_tasty_tonic_PlayerGoHome)
    EVT_RETURN
    EVT_END
};
