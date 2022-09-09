#include "life_shroom.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_72E76C)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(func_802A12EC_72E81C)(Evt* script, s32 isInitialCall) {
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

ApiStatus N(func_802A1378_72E8A8)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(0, a, b, c, d);

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1438_72E968)(Evt* script, s32 isInitialCall) {
    ItemData* item = &gItemTable[ITEM_LIFE_SHROOM];
    PlayerData* playerData = &gPlayerData;

    playerData->curHP += item->potencyA;
    if (playerData->curHP > playerData->curMaxHP) {
        playerData->curHP = playerData->curMaxHP;
    }

    script->varTable[3] = item->potencyA;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1484_72E9B4)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 itemIdx = evt_get_variable(script, *args++);
    ItemData* itemTable = gItemTable;
    ItemData* item = &itemTable[itemIdx];

    script->varTable[11] = item->potencyA;
    script->varTable[12] = item->potencyB;

    itemIdx = script->varTable[11] < 0 || (script->varTable[11] <= 0 && script->varTable[12] < 0);
    script->varTable[15] = itemIdx;

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
    EVT_SET(LocalVar(1), LocalVar(15))
    EVT_EXEC_WAIT(N(UseItem))
    EVT_SET(LocalVar(14), LocalVar(10))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_THROW)
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_END_THREAD
    EVT_CALL(CreateVirtualEntity, LocalVar(10), 0x80283EE8)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 0)
    EVT_ADD(LocalVar(1), 30)
    EVT_ADD(LocalVar(2), 5)
    EVT_CALL(SetVirtualEntityPosition, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetVirtualEntityFlags, LocalVar(10), 32)
    EVT_THREAD
        EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
        EVT_ADD(LocalVar(1), 45)
        EVT_CALL(MakeItemEntity, LocalVar(14), LocalVar(0), LocalVar(1), LocalVar(2), 1, 0)
        EVT_SET(LocalVar(14), LocalVar(0))
        EVT_LOOP(25)
            EVT_CALL(GetVirtualEntityPosition, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_CALL(N(func_802A123C_72E76C), LocalVar(0), LocalVar(1), LocalVar(2))
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(RemoveItemEntity, LocalVar(14))
    EVT_END_THREAD
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, ACTOR_SELF)
    EVT_CALL(GetGoalPos, ACTOR_SELF, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(SetBattleCamTarget, -125, 1, 0)
    EVT_CALL(SetBattleCamOffsetZ, 41)
    EVT_CALL(SetBattleCamZoom, 248)
    EVT_CALL(MoveBattleCamOver, 25)
    EVT_CALL(SetVirtualEntityJumpGravity, LocalVar(10), EVT_FLOAT(0.4))
    EVT_ADD(LocalVar(2), 5)
    EVT_CALL(VirtualEntityJumpTo, LocalVar(10), LocalVar(0), LocalVar(1), LocalVar(2), 25)
    EVT_CALL(AddBattleCamZoom, 100)
    EVT_CALL(MoveBattleCamOver, 30)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(1), 25)
    EVT_CALL(ShowStartRecoveryShimmer, LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(11))
    EVT_IF_GT(LocalVar(11), 0)
        EVT_CALL(N(func_802A12EC_72E81C), LocalVar(11))
    EVT_END_IF
    EVT_WAIT(30)
    EVT_CALL(GetActorPos, ACTOR_PARTNER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(ShowRecoveryShimmer, LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(11))
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
    EVT_SET(LocalVar(15), LocalVar(1))
    EVT_CALL(GetMenuSelection, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_SET(LocalVar(10), LocalVar(1))
    EVT_CALL(N(func_802A1484_72E9B4), LocalVar(10))
    EVT_CALL(InitTargetIterator)
    EVT_CALL(GetOwnerTarget, LocalVar(0), LocalVar(1))
    EVT_IF_EQ(LocalVar(0), 256)
        EVT_EXEC_WAIT(N(script6))
        EVT_RETURN
    EVT_END_IF
    EVT_SET_CONST(LocalVar(10), 0x00000095)
    EVT_SET(LocalVar(1), LocalVar(15))
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_EXEC_WAIT(N(EatItem))
    EVT_CALL(N(func_802A1438_72E968))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(0), 0)
    EVT_ADD(LocalVar(1), 35)
    EVT_CALL(N(func_802A1378_72E8A8), LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(3))
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_ADD(LocalVar(1), 25)
    EVT_CALL(ShowStartRecoveryShimmer, LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(3))
    EVT_WAIT(10)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_THUMBS_UP)
    EVT_WAIT(30)
    EVT_CALL(GetActorPos, ACTOR_PLAYER, LocalVar(0), LocalVar(1), LocalVar(2))
    EVT_CALL(ShowRecoveryShimmer, LocalVar(0), LocalVar(1), LocalVar(2), LocalVar(3))
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_WAIT(20)
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
