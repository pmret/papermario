#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "entity.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_food

extern EntityModelScript EMS_StarIcon;

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(func_802A123C_73330C)) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    ItemEntity* item = get_item_entity(script->varTable[14]);

    item->pos.x = a;
    item->pos.y = b;
    item->pos.z = c;

    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_802A12EC_7333BC)) {
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
        partner->disableEffect->data.disableX->koDuration = partner->koDuration;
    } else {
        partner->koStatus = 0;
        dispatch_event_partner(EVENT_RECOVER_FROM_KO);
        partner->disableEffect->data.disableX->koDuration = 0;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpawnHeartRecoveryFX)) {
    Bytecode* args = script->ptrReadPos;
    s32 a = evt_get_variable(script, *args++);
    s32 b = evt_get_variable(script, *args++);
    s32 c = evt_get_variable(script, *args++);
    s32 d = evt_get_variable(script, *args++);

    fx_recover(0, a, b, c, d);

    return ApiStatus_DONE2;
}

API_CALLABLE(N(SpawnFlowerRecoveryFX)) {
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

API_CALLABLE(N(GetFoodParameters)) {
    Bytecode* args = script->ptrReadPos;
    s32 itemIdx = evt_get_variable(script, *args++);
    ItemData* item = &gItemTable[itemIdx];
    b32 isHarmful;

    script->varTable[11] = item->potencyA;
    script->varTable[12] = item->potencyB;
    script->varTable[13] = FALSE;

    if (item->typeFlags & ITEM_TYPE_FLAG_USE_DRINK_ANIMATION) {
        script->varTable[13] = TRUE;
    }

    isHarmful = FALSE;
    if ((script->varTable[11] < 0) || (script->varTable[11] <= 0 && script->varTable[12] < 0)) {
        isHarmful = TRUE;
    }

    script->varTable[15] = isHarmful;

    return ApiStatus_DONE2;
}

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseOnPartner) = {
    Call(SetActorYaw, ACTOR_PLAYER, 30)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 60)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 90)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 120)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 150)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 180)
    Wait(10)
    Set(LVar1, LVarF)
    ExecWait(N(UseItem))
    Set(LVarE, LVarA)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Throw)
    Thread
        Wait(20)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EndThread
    Call(CreateVirtualEntity, LVarA, Ref(EMS_StarIcon))
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar0, 0)
    Add(LVar1, 30)
    Add(LVar2, 5)
    Call(SetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
    Call(SetVirtualEntityFlags, LVarA, 32)
    Thread
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar1, 45)
        Call(MakeItemEntity, LVarE, LVar0, LVar1, LVar2, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(LVarE, LVar0)
        Loop(25)
            Call(GetVirtualEntityPosition, LVarA, LVar0, LVar1, LVar2)
            Call(N(func_802A123C_73330C), LVar0, LVar1, LVar2)
            Wait(1)
        EndLoop
        Call(RemoveItemEntity, LVarE)
    EndThread
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(GetGoalPos, ACTOR_SELF, LVar0, LVar1, LVar2)
    Call(SetBattleCamTarget, -125, 1, 0)
    Call(SetBattleCamOffsetZ, 41)
    Call(SetBattleCamZoom, 248)
    Call(MoveBattleCamOver, 25)
    Call(SetVirtualEntityJumpGravity, LVarA, Float(0.4))
    Add(LVar2, 5)
    Call(VirtualEntityJumpTo, LVarA, LVar0, LVar1, LVar2, 25)
    Call(AddBattleCamZoom, 100)
    Call(MoveBattleCamOver, 30)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Add(LVar1, 25)
    Call(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, LVarB)
    IfGt(LVarB, 0)
        Call(N(func_802A12EC_7333BC), LVarB)
    EndIf
    Wait(30)
    Call(GetActorPos, ACTOR_PARTNER, LVar0, LVar1, LVar2)
    Call(ShowRecoveryShimmer, LVar0, LVar1, LVar2, LVarB)
    Wait(20)
    Call(SetActorYaw, ACTOR_PLAYER, 150)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 120)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 90)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 60)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 30)
    Wait(1)
    Call(SetActorYaw, ACTOR_PLAYER, 0)
    Wait(10)
    Return
    End
};

EvtScript N(EVS_UseItem) = {
    #define LV_ItemID LVarA
    #define LV_HPAmt LVarB
    #define LV_FPAmt LVarC
    #define LV_IsDrink LVarD
    #define LV_NoRefund LVarE
    #define LV_IsHarmful LVarF
    
    Set(LV_NoRefund, LVar1)
    Call(GetMenuSelection, LVar0, LVar1, LVar2)
    Set(LV_ItemID, LVar1)
    Call(N(GetFoodParameters), LV_ItemID)
    Call(InitTargetIterator)
    Call(GetOwnerTarget, LVar0, LVar1)
    IfEq(LVar0, ACTOR_PARTNER)
        ExecWait(N(EVS_UseOnPartner))
        Return
    EndIf
    Set(LVar1, LV_NoRefund)
    ExecWait(N(UseItemWithEffect))
    IfEq(LV_IsDrink, FALSE)
        ExecWait(N(EatItem))
    Else
        ExecWait(N(DrinkItem))
    EndIf
    IfEq(LV_IsHarmful, TRUE)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_StickOutTongue)
    EndIf
    IfGt(LV_HPAmt, 0)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 0)
        Add(LVar1, 35)
        Call(N(SpawnHeartRecoveryFX), LVar0, LVar1, LVar2, LV_HPAmt)
    EndIf
    IfLt(LV_HPAmt, 0)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 0)
        Add(LVar1, 35)
        Call(N(SpawnHeartRecoveryFX), LVar0, LVar1, LVar2, LV_HPAmt)
    EndIf
    IfGt(LV_FPAmt, 0)
        Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
        Add(LVar0, 20)
        Add(LVar1, 25)
        Call(N(SpawnFlowerRecoveryFX), LVar0, LVar1, LVar2, LV_FPAmt)
    EndIf
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Add(LVar1, 25)
    Call(ShowStartRecoveryShimmer, LVar0, LVar1, LVar2, LV_HPAmt)
    IfNe(LV_HPAmt, 0)
        Call(N(AddHP), LV_HPAmt)
    EndIf
    IfNe(LV_FPAmt, 0)
        Call(N(AddFP), LV_FPAmt)
    EndIf
    IfEq(LV_IsHarmful, FALSE)
        Wait(10)
        Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_ThumbsUp)
        Wait(30)
    Else
        Wait(30)
    EndIf
    Call(GetActorPos, ACTOR_PLAYER, LVar0, LVar1, LVar2)
    Call(ShowRecoveryShimmer, LVar0, LVar1, LVar2, LV_HPAmt)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Wait(20)
    ExecWait(N(PlayerGoHome))
    Return
    End
};
