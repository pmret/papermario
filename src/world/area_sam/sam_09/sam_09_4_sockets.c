#include "sam_09.h"
#include "effects.h"

#include "world/common/complete/GiveReward.inc.c"

API_CALLABLE(N(GetItemIDFromItemEntity)) {
    Bytecode* args = script->ptrReadPos;
    s32 itemEntityIdx = evt_get_variable(script, *args++);

    script->varTable[0] = get_item_entity(itemEntityIdx)->itemID;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SerializeItemIDs)) {
    s32 itemID;

    itemID = evt_get_variable(script, MV_Socket1_ItemID);
    if (itemID == -1) {
        itemID = 0xFF;
    }
    evt_set_variable(script, GB_SAM09_ItemSocket1_LowerByte, itemID & 0xFF);
    evt_set_variable(script, GB_SAM09_ItemSocket1_UpperByte, (itemID >> 8) & 0xFF);

    itemID = evt_get_variable(script, MV_Socket2_ItemID);
    if (itemID == -1) {
        itemID = 0xFF;
    }
    evt_set_variable(script, GB_SAM09_ItemSocket2_LowerByte, itemID & 0xFF);
    evt_set_variable(script, GB_SAM09_ItemSocket2_UpperByte, (itemID >> 8) & 0xFF);

    itemID = evt_get_variable(script, MV_Socket3_ItemID);
    if (itemID == -1) {
        itemID = 0xFF;
    }
    evt_set_variable(script, GB_SAM09_ItemSocket3_LowerByte, itemID & 0xFF);
    evt_set_variable(script, GB_SAM09_ItemSocket3_UpperByte, (itemID >> 8) & 0xFF);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(DeserializeItemIDs)) {
    s32 upper;
    s32 lower;

    lower = evt_get_variable(script, GB_SAM09_ItemSocket1_LowerByte) & 0xFF;
    upper = evt_get_variable(script, GB_SAM09_ItemSocket1_UpperByte) & 0xFF;
    if (lower != 0xFF) {
        evt_set_variable(script, MV_Socket1_ItemID, (upper << 8) | lower);
    } else {
        evt_set_variable(script, MV_Socket1_ItemID, -1);
    }

    lower = evt_get_variable(script, GB_SAM09_ItemSocket2_LowerByte) & 0xFF;
    upper = evt_get_variable(script, GB_SAM09_ItemSocket2_UpperByte) & 0xFF;
    if (lower != 0xFF) {
        evt_set_variable(script, MV_Socket2_ItemID, (upper << 8) | lower);
    } else {
        evt_set_variable(script, MV_Socket2_ItemID, -1);
    }

    lower = evt_get_variable(script, GB_SAM09_ItemSocket3_LowerByte) & 0xFF;
    upper = evt_get_variable(script, GB_SAM09_ItemSocket3_UpperByte) & 0xFF;
    if (lower != 0xFF) {
        evt_set_variable(script, MV_Socket3_ItemID, (upper << 8) | lower);
    } else {
        evt_set_variable(script, MV_Socket3_ItemID, -1);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(N(CreateConsumableItemList)) {
    s32* array;
    s32 len = ITEM_NUM_CONSUMABLES;
    s32 i;

    script->varTablePtr[0] = array = heap_malloc((ITEM_NUM_CONSUMABLES + 1) * sizeof(*array));
    for (i = 0; i < ITEM_NUM_CONSUMABLES; i++) {
        array[i] = ITEM_FIRST_CONSUMABLE + i;
    }
    array[i] = ITEM_NONE;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_PlaceItemInSocket) = {
    Call(PlaySoundAtCollider, LVar4, SOUND_SAM_RAISE_BARRIER, 0)
    Call(MakeLerp, 0, 130, 30 * DT, EASING_LINEAR)
    Label(0)
        Call(UpdateLerp)
        Call(TranslateModel, LVar2, 0, LVar0, 0)
        Call(UpdateColliderTransform, LVar4)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Return
    End
};

EvtScript N(EVS_TakeItemFromSocket) = {
    Call(PlaySoundAtCollider, LVar4, SOUND_SAM_LOWER_BARRIER, 0)
    Call(MakeLerp, 130, 0, 30 * DT, EASING_CUBIC_IN)
    Label(0)
    Call(UpdateLerp)
    Call(TranslateModel, LVar2, 0, LVar0, 0)
    Call(UpdateColliderTransform, LVar4)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(0)
    EndIf
    Call(PlaySoundAtCollider, LVar4, SOUND_SAM_BARRIER_THUD, 0)
    Call(GetModelCenter, LVar2)
    Set(LVar3, LVar2)
    Set(LVar4, LVar2)
    Add(LVar3, 30)
    Sub(LVar4, 30)
    PlayEffect(EFFECT_LANDING_DUST, 3, LVar0, 0, LVar2, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, LVar0, 0, LVar3, 0)
    PlayEffect(EFFECT_LANDING_DUST, 3, LVar0, 0, LVar4, 0)
    Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(1.0))
    Return
    End
};

EvtScript N(EVS_UseSocket1) = {
    IfEq(MV_Socket1_ItemID, -1)
        Call(ShowConsumableChoicePopup)
        Call(CloseChoicePopup)
        IfEq(LVar0, 0)
            Call(ShowMessageAtScreenPos, MSG_Menus_SAM09_PlaceItemTip, 160, 40)
            Return
        EndIf
        IfEq(LVar0, -1)
            Return
        EndIf
        Set(MV_Socket1_ItemID, LVar0)
        Call(N(SerializeItemIDs))
        Call(RemoveItem, LVar0, LVar2)
        Call(MakeItemEntity, LVar0, -385, 30, -50, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(MV_Socket1_ItemEntityID, LVar0)
        Set(LVar2, MODEL_m1_kabe)
        Set(LVar4, COLLIDER_o55)
        ExecWait(N(EVS_PlaceItemInSocket))
        Return
    Else
        Set(LVar0, MV_Socket1_ItemEntityID)
        Call(N(GetItemIDFromItemEntity), LVar0)
        Call(N(GetItemName), LVar0)
        Call(SetMessageText, LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_PickUpPrompt, 160, 40)
        Call(ShowChoice, MSG_Choice_000D)
        Call(CloseMessage)
        IfEq(LVar0, 0)
            Call(AddItem, MV_Socket1_ItemID, LVar0)
            IfEq(LVar0, -1)
                Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_CantCarryMore, 160, 40)
                Return
            EndIf
            Call(N(GetItemIDFromItemEntity), MV_Socket1_ItemEntityID)
            Call(RemoveItemEntity, MV_Socket1_ItemEntityID)
            Set(MV_Socket1_ItemID, -1)
            Call(N(SerializeItemIDs))
            Call(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_UNIQUE)
            Set(LVar2, MODEL_m1_kabe)
            Set(LVar4, COLLIDER_o55)
            ExecWait(N(EVS_TakeItemFromSocket))
            Return
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_UseSocket2) = {
    IfEq(MV_Socket2_ItemID, -1)
        Call(ShowConsumableChoicePopup)
        Call(CloseChoicePopup)
        IfEq(LVar0, 0)
            Call(ShowMessageAtScreenPos, MSG_Menus_SAM09_PlaceItemTip, 160, 40)
            Return
        EndIf
        IfEq(LVar0, -1)
            Return
        EndIf
        Set(MV_Socket2_ItemID, LVar0)
        Call(N(SerializeItemIDs))
        Call(RemoveItem, LVar0, LVar2)
        Call(MakeItemEntity, LVar0, -35, 30, -50, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(MV_Socket2_ItemEntityID, LVar0)
        Set(LVar2, MODEL_m2_kabe)
        Set(LVar4, COLLIDER_o54)
        ExecWait(N(EVS_PlaceItemInSocket))
        Return
    Else
        Set(LVar0, MV_Socket2_ItemEntityID)
        Call(N(GetItemIDFromItemEntity), LVar0)
        Call(N(GetItemName), LVar0)
        Call(SetMessageText, LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_PickUpPrompt, 160, 40)
        Call(ShowChoice, MSG_Choice_000D)
        Call(CloseMessage)
        IfEq(LVar0, 0)
            Call(AddItem, MV_Socket2_ItemID, LVar0)
            IfEq(LVar0, -1)
                Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_CantCarryMore, 160, 40)
                Return
            EndIf
            Call(N(GetItemIDFromItemEntity), MV_Socket2_ItemEntityID)
            Call(RemoveItemEntity, MV_Socket2_ItemEntityID)
            Set(MV_Socket2_ItemID, -1)
            Call(N(SerializeItemIDs))
            Call(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_UNIQUE)
            Set(LVar2, MODEL_m2_kabe)
            Set(LVar4, COLLIDER_o54)
            ExecWait(N(EVS_TakeItemFromSocket))
            Return
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_UseSocket3) = {
    IfEq(MV_Socket3_ItemID, -1)
        Call(ShowConsumableChoicePopup)
        Call(CloseChoicePopup)
        IfEq(LVar0, 0)
            Call(ShowMessageAtScreenPos, MSG_Menus_SAM09_PlaceItemTip, 160, 40)
            Return
        EndIf
        IfEq(LVar0, -1)
            Return
        EndIf
        Set(MV_Socket3_ItemID, LVar0)
        Call(N(SerializeItemIDs))
        Call(RemoveItem, LVar0, LVar2)
        Call(MakeItemEntity, LVar0, 265, 30, -50, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(MV_Socket3_ItemEntityID, LVar0)
        Set(LVar2, MODEL_m3_kabe)
        Set(LVar4, COLLIDER_o53)
        ExecWait(N(EVS_PlaceItemInSocket))
        Return
    Else
        Set(LVar0, MV_Socket3_ItemEntityID)
        Call(N(GetItemIDFromItemEntity), LVar0)
        Call(N(GetItemName), LVar0)
        Call(SetMessageText, LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_PickUpPrompt, 160, 40)
        Call(ShowChoice, MSG_Choice_000D)
        Call(CloseMessage)
        IfEq(LVar0, 0)
            Call(AddItem, MV_Socket3_ItemID, LVar0)
            IfEq(LVar0, -1)
                Call(ShowMessageAtScreenPos, MSG_Menus_Inspect_CantCarryMore, 160, 40)
                Return
            EndIf
            Call(N(GetItemIDFromItemEntity), MV_Socket3_ItemEntityID)
            Call(RemoveItemEntity, MV_Socket3_ItemEntityID)
            Set(MV_Socket3_ItemID, -1)
            Call(N(SerializeItemIDs))
            Call(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_UNIQUE)
            Set(LVar2, MODEL_m3_kabe)
            Set(LVar4, COLLIDER_o53)
            ExecWait(N(EVS_TakeItemFromSocket))
            Return
        EndIf
    EndIf
    Return
    End
};

EvtScript N(EVS_Interact_ItemSockets) = {
    Call(DisablePlayerInput, TRUE)
    Label(0)
    Call(GetPlayerActionState, LVar0)
    Wait(1)
    IfNe(LVar0, ACTION_STATE_IDLE)
        Goto(0)
    EndIf
    Call(GetPlayerPos, LVar1, LVar2, LVar3)
    IfLt(LVar1, -150)
        ExecWait(N(EVS_UseSocket1))
    Else
        IfLt(LVar1, 100)
            ExecWait(N(EVS_UseSocket2))
        Else
            ExecWait(N(EVS_UseSocket3))
        EndIf
    EndIf
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_SetupSockets) = {
    Call(ParentColliderToModel, COLLIDER_o55, MODEL_m1_kabe)
    Call(ParentColliderToModel, COLLIDER_o54, MODEL_m2_kabe)
    Call(ParentColliderToModel, COLLIDER_o53, MODEL_m3_kabe)
    IfEq(GF_SAM09_Visited, FALSE)
        Set(GF_SAM09_Visited, TRUE)
        Set(MV_Socket1_ItemID, ITEM_SHOOTING_STAR)
        Set(MV_Socket2_ItemID, ITEM_SNOWMAN_DOLL)
        Set(MV_Socket3_ItemID, ITEM_THUNDER_RAGE)
        Call(N(SerializeItemIDs))
    EndIf
    Call(N(DeserializeItemIDs))
    IfNe(MV_Socket1_ItemID, -1)
        Call(TranslateModel, MODEL_m1_kabe, 0, 130, 0)
        Call(UpdateColliderTransform, COLLIDER_o55)
        Call(MakeItemEntity, MV_Socket1_ItemID, -385, 30, -50, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(MV_Socket1_ItemEntityID, LVar0)
    EndIf
    IfNe(MV_Socket2_ItemID, -1)
        Call(TranslateModel, MODEL_m2_kabe, 0, 130, 0)
        Call(UpdateColliderTransform, COLLIDER_o54)
        Call(MakeItemEntity, MV_Socket2_ItemID, -35, 30, -50, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(MV_Socket2_ItemEntityID, LVar0)
    EndIf
    IfNe(MV_Socket3_ItemID, -1)
        Call(TranslateModel, MODEL_m3_kabe, 0, 130, 0)
        Call(UpdateColliderTransform, COLLIDER_o53)
        Call(MakeItemEntity, MV_Socket3_ItemID, 265, 30, -50, ITEM_SPAWN_MODE_DECORATION, 0)
        Set(MV_Socket3_ItemEntityID, LVar0)
    EndIf
    Call(N(CreateConsumableItemList))
    BindPadlock(Ref(N(EVS_Interact_ItemSockets)), TRIGGER_WALL_PRESS_A, COLLIDER_hako, LVar0, 0, 1)
    Return
    End
};
