#include "tasty_tonic.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_72223C)(Evt* script, s32 isInitialCall) {
    s32 actorId = evt_get_variable(script, *script->ptrReadPos);
    Actor* actor = get_actor(actorId);
    s32 id = actor->actorID & 0x700;

    if (actor->debuff != STATUS_END) {
        actor->debuffDuration = 0;
        actor->debuff = 0;
        remove_status_1(actor->unk_436);
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

EvtSource N(main) = SCRIPT({
    EVT_VAR(10) = (const) ITEM_TASTY_TONIC;
    await N(UseItemWithEffect);
    InitTargetIterator();
    GetOwnerTarget(EVT_VAR(0), EVT_VAR(1));
    if (EVT_VAR(0) == 0) {
        await N(DrinkItem);
        GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        EVT_VAR(1) += 25;
        EVT_VAR(2) += 5;
        func_802D7520(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10);
        GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        EVT_VAR(1) += 20;
        SetAnimation(ACTOR_PLAYER, 0, ANIM_THUMBS_UP);
        sleep 30;
        SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
        GetActorPos(ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        EVT_VAR(2) += 5;
        func_802D75D8(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 10);
        N(func_802A123C_72223C)(ACTOR_PLAYER);
        sleep 20;
    } else {
        GetActorPos(ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        EVT_VAR(1) += 25;
        EVT_VAR(2) += 5;
        func_802D7520(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 5);
        GetActorPos(ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        EVT_VAR(1) += 20;
        sleep 30;
        GetActorPos(ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2));
        EVT_VAR(2) += 5;
        func_802D75D8(EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 5);
        N(func_802A123C_72223C)(ACTOR_PARTNER);
        sleep 20;
    }
    await N(PlayerGoHome);
});
