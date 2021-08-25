#include "mushroom.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_715A8C)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);
    ItemEntity* item = get_item_entity(script->varTable[14]);

    item->position.x = a;
    item->position.y = b;
    item->position.z = c;

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A12EC_715B3C)(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    Bytecode* args = script->ptrReadPos;

    if (partner->koDuration == 0) {
        return ApiStatus_DONE2;
    }

    partner->koDuration -= get_variable(script, *args++);
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

ApiStatus N(func_802A1378_715BC8)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);
    s32 d = get_variable(script, *args++);

    playFX_40(0, a, b, c, d);

    return ApiStatus_DONE2;
}

ApiStatus N(func_802A1438_715C88)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a = get_variable(script, *args++);
    s32 b = get_variable(script, *args++);
    s32 c = get_variable(script, *args++);
    s32 d = get_variable(script, *args++);

    playFX_40(1, a, b, c, d);

    return ApiStatus_DONE2;
}

#include "common/AddHP.inc.c"

#include "common/AddFP.inc.c"

ApiStatus N(func_802A15A0_715DF0)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    StaticItem* itemTable = gItemTable;
    StaticItem* item = &itemTable[get_variable(script, *args++)];

    script->varTable[11] = item->potencyA;
    script->varTable[12] = item->potencyB;
    script->varTable[15] = item->potencyA == 1;

    return ApiStatus_DONE2;
}

#include "UseItem.inc.c"

EvtSource N(script6) = SCRIPT({
    SetActorYaw(ACTOR_PLAYER, 30);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 60);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 90);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 120);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 150);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 180);
    sleep 10;
    SI_VAR(1) = SI_VAR(15);
    await N(UseItem);
    SI_VAR(14) = SI_VAR(10);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_THROW);
    spawn {
        sleep 20;
        SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    }
    CreateVirtualEntity(SI_VAR(10), 0x80283EE8);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 0;
    SI_VAR(1) += 30;
    SI_VAR(2) += 5;
    SetVirtualEntityPosition(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetVirtualEntityFlags(SI_VAR(10), 32);
    spawn {
        GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 45;
        MakeItemEntity(SI_VAR(14), SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 0);
        SI_VAR(14) = SI_VAR(0);
        loop 25 {
            GetVirtualEntityPosition(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2));
            N(func_802A123C_715A8C)(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 1;
        }
        RemoveItemEntity(SI_VAR(14));
    }
    InitTargetIterator();
    SetGoalToTarget(ACTOR_SELF);
    GetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetBattleCamTarget(0xFFFFFF83, 1, 0);
    SetBattleCamOffsetZ(41);
    SetBattleCamZoom(248);
    MoveBattleCamOver(25);
    SetVirtualEntityJumpGravity(SI_VAR(10), 0.400390625);
    SI_VAR(2) += 5;
    VirtualEntityJumpTo(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 25);
    AddBattleCamZoom(100);
    MoveBattleCamOver(30);
    GetActorPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 25;
    func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(11));
    if (SI_VAR(11) > 0) {
        N(func_802A12EC_715B3C)(SI_VAR(11));
    }
    sleep 30;
    GetActorPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(11));
    sleep 20;
    SetActorYaw(ACTOR_PLAYER, 150);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 120);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 90);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 60);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 30);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 0);
    sleep 10;
});

EvtSource N(main) = SCRIPT({
    SI_VAR(14) = SI_VAR(1);
    GetMenuSelection(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(10) = SI_VAR(1);
    N(func_802A15A0_715DF0)(SI_VAR(10));
    InitTargetIterator();
    GetOwnerTarget(SI_VAR(0), SI_VAR(1));
    if (SI_VAR(0) == ACTOR_PARTNER) {
        await N(script6);
        return;
    }
    SI_VAR(1) = SI_VAR(14);
    await N(UseItemWithEffect);
    await N(EatItem);
    if (SI_VAR(15) == 1) {
        SetAnimation(ACTOR_PLAYER, 0, ANIM_STICK_OUT_TONGUE);
    }
    if (SI_VAR(11) > 0) {
        GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += 0;
        SI_VAR(1) += 35;
        N(func_802A1378_715BC8)(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(11));
    }
    if (SI_VAR(12) > 0) {
        GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += 20;
        SI_VAR(1) += 25;
        N(func_802A1438_715C88)(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(12));
    }
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 25;
    func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(11));
    if (SI_VAR(11) != 0) {
        N(AddHP)(SI_VAR(11));
    }
    if (SI_VAR(12) != 0) {
        N(AddFP)(SI_VAR(12));
    }
    if (SI_VAR(15) == 0) {
        sleep 10;
        SetAnimation(ACTOR_PLAYER, 0, ANIM_THUMBS_UP);
        sleep 30;
    } else {
        sleep 30;
    }
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(11));
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    sleep 20;
    await N(PlayerGoHome);
});
