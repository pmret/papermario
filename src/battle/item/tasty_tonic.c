#include "tasty_tonic.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_72223C)(Evt* script, s32 isInitialCall) {
    s32 actorId = evt_get_variable(script, *script->ptrReadPos);
    Actor* actor = get_actor(actorId);
    s32 id = actor->actorID & 0x700;

    if (actor->debuff != STATUS_END) {
        actor->debuffDuration = 0;
        actor->debuff = 0;
        remove_status_debuff(actor->hudElementDataIndex);
    }

    if (actor->koStatus != 0) {
        actor->koDuration = 0;
        actor->koStatus = 0;
        if (id != 0) {
            if (id == 0x100) {
                dispatch_event_partner(0x31);
            }
        }
        actor->ptrDefuffIcon->ptrPropertyList[15] = 0;
    }

    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

EvtSource N(main) = {
    EVT_SET_CONST(EVT_VAR(10), 0x89)
    EVT_EXEC_WAIT(battle_item_tasty_tonic_UseItemWithEffect)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetOwnerTarget, EVT_VAR(0), EVT_VAR(1))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_EXEC_WAIT(battle_item_tasty_tonic_DrinkItem)
        EVT_CALL(GetActorPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 25)
        EVT_ADD(EVT_VAR(2), 5)
        EVT_CALL(func_802D7520, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
        EVT_CALL(GetActorPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 20)
        EVT_CALL(SetAnimation, 0, 0, 65586)
        EVT_WAIT_FRAMES(30)
        EVT_CALL(SetAnimation, 0, 0, 65538)
        EVT_CALL(GetActorPos, 0, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(2), 5)
        EVT_CALL(func_802D75D8, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10)
        EVT_CALL(battle_item_tasty_tonic_func_802A123C_72223C, 0)
        EVT_WAIT_FRAMES(20)
    EVT_ELSE
        EVT_CALL(GetActorPos, 256, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 25)
        EVT_ADD(EVT_VAR(2), 5)
        EVT_CALL(func_802D7520, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 5)
        EVT_CALL(GetActorPos, 256, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 20)
        EVT_WAIT_FRAMES(30)
        EVT_CALL(GetActorPos, 256, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(2), 5)
        EVT_CALL(func_802D75D8, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 5)
        EVT_CALL(battle_item_tasty_tonic_func_802A123C_72223C, 256)
        EVT_WAIT_FRAMES(20)
    EVT_END_IF
    EVT_EXEC_WAIT(battle_item_tasty_tonic_PlayerGoHome)
    EVT_RETURN
    EVT_END
};
