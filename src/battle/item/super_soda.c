#include "super_soda.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_724F1C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    ItemEntity* item = get_item_entity(script->varTable[14]);

    item->position.x = a;
    item->position.y = b;
    item->position.z = c;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A12EC_724FCC)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    Bytecode* args = script->ptrReadPos;

    if (partner->koDuration == 0) {
        return ApiStatus_DONE2;
    }

    partner->koDuration -= evt_get_variable(script, *args++);
    if (partner->koDuration < 0) {
        partner->koDuration = 0;
    }
    if (partner->koDuration > 0) {
        partner->ptrDefuffIcon->ptrPropertyList[0xF] = partner->koDuration;
    } else {
        partner->koStatus = 0;
        dispatch_event_partner(0x34);
        partner->ptrDefuffIcon->ptrPropertyList[0xF] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1378_725058)(Evt* script, s32 isInitialCall) {
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

    btl_update_ko_status();

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1418_7250F8)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    playFX_40(1, a, b, c, d);
    return ApiStatus_DONE2;
}

#include "common/AddFP.inc.c"

#include "UseItem.inc.c"

EvtSource N(script6) = {
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 180)
    EVT_WAIT_FRAMES(10)
    EVT_SET(EVT_VAR(1), EVT_VAR(15))
    EVT_EXEC_WAIT(N(UseItem))
    EVT_SET(EVT_VAR(14), EVT_VAR(10))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_THROW)
    EVT_THREAD
        EVT_WAIT_FRAMES(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_END_THREAD
    EVT_CALL(CreateVirtualEntity, EVT_VAR(10), 0x80283EE8)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(0), 0)
    EVT_ADD(EVT_VAR(1), 30)
    EVT_ADD(EVT_VAR(2), 5)
    EVT_CALL(SetVirtualEntityPosition, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetVirtualEntityFlags, EVT_VAR(10), 32)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 45)
        EVT_CALL(MakeItemEntity, EVT_VAR(14), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 1, 0)
        EVT_SET(EVT_VAR(14), EVT_VAR(0))
        EVT_LOOP(25)
            EVT_CALL(GetVirtualEntityPosition, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_CALL(N(func_802A123C_724F1C), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
            EVT_WAIT_FRAMES(1)
        EVT_END_LOOP
        EVT_CALL(RemoveItemEntity, EVT_VAR(14))
    EVT_END_THREAD
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(SetBattleCamTarget, -125, 1, 0)
    EVT_CALL(SetBattleCamOffsetZ, 41)
    EVT_CALL(SetBattleCamZoom, 248)
    EVT_CALL(MoveBattleCamOver, 25)
    EVT_CALL(SetVirtualEntityJumpGravity, EVT_VAR(10), EVT_FIXED(0.4))
    EVT_ADD(EVT_VAR(2), 5)
    EVT_CALL(VirtualEntityJumpTo, EVT_VAR(10), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 25)
    EVT_CALL(AddBattleCamZoom, 100)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_ADD(EVT_VAR(1), 25)
    EVT_CALL(func_802D7520, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_VAR(11))
    EVT_IF_GT(EVT_VAR(11), 0)
        EVT_CALL(N(func_802A12EC_724FCC), EVT_VAR(11))
    EVT_END_IF
    EVT_WAIT_FRAMES(30)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
    EVT_CALL(func_802D75D8, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), EVT_VAR(11))
    EVT_WAIT_FRAMES(20)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT_FRAMES(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
    EVT_WAIT_FRAMES(10)
    EVT_RETURN
    EVT_END
};

EvtSource N(main) = {
    EVT_SET_CONST(EVT_VAR(10), 0x0000009B)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetOwnerTarget, EVT_VAR(0), EVT_VAR(1))
    EVT_IF_EQ(EVT_VAR(0), 0)
        EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_UNKNOWN_2095)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_DRINK)
        EVT_WAIT_FRAMES(45)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(0), 0)
        EVT_ADD(EVT_VAR(1), 35)
        EVT_CALL(N(func_802A1418_7250F8), EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 5)
        EVT_CALL(N(AddFP), 5)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 25)
        EVT_CALL(func_802D7520, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 5)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_ADD(EVT_VAR(1), 20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_THUMBS_UP)
        EVT_WAIT_FRAMES(30)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2))
        EVT_CALL(func_802D75D8, EVT_VAR(0), EVT_VAR(1), EVT_VAR(2), 5)
        EVT_CALL(InitTargetIterator)
        EVT_CALL(GetOwnerTarget, EVT_VAR(0), EVT_VAR(1))
        EVT_CALL(N(func_802A1378_725058), 0)
        EVT_WAIT_FRAMES(20)
    EVT_ELSE
        EVT_SET(EVT_VAR(11), 0)
        EVT_SET(EVT_VAR(12), 0)
        EVT_SET(EVT_VAR(15), 0)
        EVT_EXEC_WAIT(N(script6))
    EVT_END_IF
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
