#include "food.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_73330C)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(func_802A12EC_7333BC)(Evt* script, s32 isInitialCall) {
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
        partner->disableEffect->data.disableX->unk_3C = partner->koDuration;
    } else {
        partner->koStatus = 0;
        dispatch_event_partner(EVENT_RECOVER_PARTNER);
        partner->disableEffect->data.disableX->unk_3C = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1378_733448)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(0, a, b, c, d);

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1438_733508)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(1, a, b, c, d);

    return ApiStatus_DONE2;
}

#include "common/AddHP.inc.c"

#include "common/AddFP.inc.c"

ApiStatus N(func_802A15A0_733670)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemIdx = evt_get_variable(script, *args++);
    ItemData* item = &gItemTable[itemIdx];
    s32 temp;

    script->varTable[11] = item->potencyA;
    script->varTable[12] = item->potencyB;
    script->varTable[13] = 0;

    if (item->typeFlags & 0x100) {
        script->varTable[13] = 1;
    }

    temp = 0;
    if ((script->varTable[11] < 0) || (script->varTable[11] <= 0 && script->varTable[12] < 0)) {
        temp = 1;
    }

    script->varTable[15] = temp;

    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

EvtScript N(script6) = {
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 180)
    EVT_WAIT(10)
    EVT_SET(LVar1, LVarF)
    EVT_EXEC_WAIT(N(UseItem))
    EVT_SET(LVarE, LVarA)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_THROW)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_END_THREAD
    EVT_CALL(CreateVirtualEntity, LVarA, 0x80283EE8)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 0)
    EVT_ADD(LVar1, 30)
    EVT_ADD(LVar2, 5)
    EVT_CALL(SetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
    EVT_CALL(SetVirtualEntityFlags, LVarA, 32)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar1, 45)
        EVT_CALL(MakeItemEntity, LVarE, LVar0, LVar1, LVar2, 1, 0)
        EVT_SET(LVarE, LVar0)
        EVT_LOOP(25)
            EVT_CALL(GetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
            EVT_CALL(N(func_802A123C_73330C), LVar0, LVar1, LVar2)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(RemoveItemEntity, LVarE)
    EVT_END_THREAD
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetBattleCamTarget, -125, 1, 0)
    EVT_CALL(SetBattleCamOffsetZ, 41)
    EVT_CALL(SetBattleCamZoom, 248)
    EVT_CALL(MoveBattleCamOver, 25)
    EVT_CALL(SetVirtualEntityJumpGravity, LVarA, EVT_FLOAT(0.4))
    EVT_ADD(LVar2, 5)
    EVT_CALL(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 25)
    EVT_CALL(AddBattleCamZoom, 100)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, LVarB)
    EVT_IF_GT(LVarB, 0)
        EVT_CALL(N(func_802A12EC_7333BC), LVarB)
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    EVT_CALL(ShowRecoveryShimmer, LVar0, LVar1, LVar2, LVarB)
    EVT_WAIT(20)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 150)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 120)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 90)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 60)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 30)
    EVT_WAIT(1)
    EVT_CALL(SetActorYaw, ACTOR_PLAYER, 0)
    EVT_WAIT(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(main) = {
    EVT_SET(LVarE, LVar1)
    EVT_CALL(GetMenuSelection, LVar0, LVar1, LVar2)
    EVT_SET(LVarA, LVar1)
    EVT_CALL(N(func_802A15A0_733670), LVarA)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetOwnerTarget, LVar0, LVar1)
    EVT_IF_EQ(LVar0, 256)
        EVT_EXEC_WAIT(N(script6))
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar1, LVarE)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_IF_EQ(LVarD, 0)
        EVT_EXEC_WAIT(N(EatItem))
    EVT_ELSE
        EVT_EXEC_WAIT(N(DrinkItem))
    EVT_END_IF
    EVT_IF_EQ(LVarF, 1)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_STICK_OUT_TONGUE)
    EVT_END_IF
    EVT_IF_GT(LVarB, 0)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 0)
        EVT_ADD(LVar1, 35)
        EVT_CALL(N(func_802A1378_733448), LVar0, LVar1, LVar2, LVarB)
    EVT_END_IF
    EVT_IF_LT(LVarB, 0)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 0)
        EVT_ADD(LVar1, 35)
        EVT_CALL(N(func_802A1378_733448), LVar0, LVar1, LVar2, LVarB)
    EVT_END_IF
    EVT_IF_GT(LVarC, 0)
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 20)
        EVT_ADD(LVar1, 25)
        EVT_CALL(N(func_802A1438_733508), LVar0, LVar1, LVar2, LVarC)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 25)
    EVT_CALL(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, LVarB)
    EVT_IF_NE(LVarB, 0)
        EVT_CALL(N(AddHP), LVarB)
    EVT_END_IF
    EVT_IF_NE(LVarC, 0)
        EVT_CALL(N(AddFP), LVarC)
    EVT_END_IF
    EVT_IF_EQ(LVarF, 0)
        EVT_WAIT(10)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_THUMBS_UP)
        EVT_WAIT(30)
    EVT_ELSE
        EVT_WAIT(30)
    EVT_END_IF
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    EVT_CALL(ShowRecoveryShimmer, LVar0, LVar1, LVar2, LVarB)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_WAIT(20)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
