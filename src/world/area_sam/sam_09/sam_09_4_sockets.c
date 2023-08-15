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
    EVT_CALL(PlaySoundAtCollider, LVar4, SOUND_SAM_RAISE_BARRIER, 0)
    EVT_CALL(MakeLerp, 0, 130, 30 * DT, EASING_LINEAR)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, LVar2, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, LVar4)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TakeItemFromSocket) = {
    EVT_CALL(PlaySoundAtCollider, LVar4, SOUND_SAM_LOWER_BARRIER, 0)
    EVT_CALL(MakeLerp, 130, 0, 30 * DT, EASING_CUBIC_IN)
    EVT_LABEL(0)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, LVar2, 0, LVar0, 0)
    EVT_CALL(UpdateColliderTransform, LVar4)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, LVar4, SOUND_SAM_BARRIER_THUD, 0)
    EVT_CALL(GetModelCenter, LVar2)
    EVT_SET(LVar3, LVar2)
    EVT_SET(LVar4, LVar2)
    EVT_ADD(LVar3, 30)
    EVT_SUB(LVar4, 30)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, LVar0, 0, LVar2, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, LVar0, 0, LVar3, 0)
    EVT_PLAY_EFFECT(EFFECT_LANDING_DUST, 3, LVar0, 0, LVar4, 0)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSocket1) = {
    EVT_IF_EQ(MV_Socket1_ItemID, -1)
        EVT_CALL(ShowConsumableChoicePopup)
        EVT_CALL(CloseChoicePopup)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_SAM09_PlaceItemTip, 160, 40)
            EVT_RETURN
        EVT_END_IF
        EVT_IF_EQ(LVar0, -1)
            EVT_RETURN
        EVT_END_IF
        EVT_SET(MV_Socket1_ItemID, LVar0)
        EVT_CALL(N(SerializeItemIDs))
        EVT_CALL(RemoveItem, LVar0, LVar2)
        EVT_CALL(MakeItemEntity, LVar0, -385, 30, -50, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(MV_Socket1_ItemEntityID, LVar0)
        EVT_SET(LVar2, MODEL_m1_kabe)
        EVT_SET(LVar4, COLLIDER_o55)
        EVT_EXEC_WAIT(N(EVS_PlaceItemInSocket))
        EVT_RETURN
    EVT_ELSE
        EVT_SET(LVar0, MV_Socket1_ItemEntityID)
        EVT_CALL(N(GetItemIDFromItemEntity), LVar0)
        EVT_CALL(N(GetItemName), LVar0)
        EVT_CALL(SetMessageText, LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_PickUpPrompt, 160, 40)
        EVT_CALL(ShowChoice, MSG_Choice_000D)
        EVT_CALL(CloseMessage)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(AddItem, MV_Socket1_ItemID, LVar0)
            EVT_IF_EQ(LVar0, -1)
                EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_CantCarryMore, 160, 40)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(N(GetItemIDFromItemEntity), MV_Socket1_ItemEntityID)
            EVT_CALL(RemoveItemEntity, MV_Socket1_ItemEntityID)
            EVT_SET(MV_Socket1_ItemID, -1)
            EVT_CALL(N(SerializeItemIDs))
            EVT_CALL(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_UNIQUE)
            EVT_SET(LVar2, MODEL_m1_kabe)
            EVT_SET(LVar4, COLLIDER_o55)
            EVT_EXEC_WAIT(N(EVS_TakeItemFromSocket))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSocket2) = {
    EVT_IF_EQ(MV_Socket2_ItemID, -1)
        EVT_CALL(ShowConsumableChoicePopup)
        EVT_CALL(CloseChoicePopup)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_SAM09_PlaceItemTip, 160, 40)
            EVT_RETURN
        EVT_END_IF
        EVT_IF_EQ(LVar0, -1)
            EVT_RETURN
        EVT_END_IF
        EVT_SET(MV_Socket2_ItemID, LVar0)
        EVT_CALL(N(SerializeItemIDs))
        EVT_CALL(RemoveItem, LVar0, LVar2)
        EVT_CALL(MakeItemEntity, LVar0, -35, 30, -50, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(MV_Socket2_ItemEntityID, LVar0)
        EVT_SET(LVar2, MODEL_m2_kabe)
        EVT_SET(LVar4, COLLIDER_o54)
        EVT_EXEC_WAIT(N(EVS_PlaceItemInSocket))
        EVT_RETURN
    EVT_ELSE
        EVT_SET(LVar0, MV_Socket2_ItemEntityID)
        EVT_CALL(N(GetItemIDFromItemEntity), LVar0)
        EVT_CALL(N(GetItemName), LVar0)
        EVT_CALL(SetMessageText, LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_PickUpPrompt, 160, 40)
        EVT_CALL(ShowChoice, MSG_Choice_000D)
        EVT_CALL(CloseMessage)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(AddItem, MV_Socket2_ItemID, LVar0)
            EVT_IF_EQ(LVar0, -1)
                EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_CantCarryMore, 160, 40)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(N(GetItemIDFromItemEntity), MV_Socket2_ItemEntityID)
            EVT_CALL(RemoveItemEntity, MV_Socket2_ItemEntityID)
            EVT_SET(MV_Socket2_ItemID, -1)
            EVT_CALL(N(SerializeItemIDs))
            EVT_CALL(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_UNIQUE)
            EVT_SET(LVar2, MODEL_m2_kabe)
            EVT_SET(LVar4, COLLIDER_o54)
            EVT_EXEC_WAIT(N(EVS_TakeItemFromSocket))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseSocket3) = {
    EVT_IF_EQ(MV_Socket3_ItemID, -1)
        EVT_CALL(ShowConsumableChoicePopup)
        EVT_CALL(CloseChoicePopup)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_SAM09_PlaceItemTip, 160, 40)
            EVT_RETURN
        EVT_END_IF
        EVT_IF_EQ(LVar0, -1)
            EVT_RETURN
        EVT_END_IF
        EVT_SET(MV_Socket3_ItemID, LVar0)
        EVT_CALL(N(SerializeItemIDs))
        EVT_CALL(RemoveItem, LVar0, LVar2)
        EVT_CALL(MakeItemEntity, LVar0, 265, 30, -50, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(MV_Socket3_ItemEntityID, LVar0)
        EVT_SET(LVar2, MODEL_m3_kabe)
        EVT_SET(LVar4, COLLIDER_o53)
        EVT_EXEC_WAIT(N(EVS_PlaceItemInSocket))
        EVT_RETURN
    EVT_ELSE
        EVT_SET(LVar0, MV_Socket3_ItemEntityID)
        EVT_CALL(N(GetItemIDFromItemEntity), LVar0)
        EVT_CALL(N(GetItemName), LVar0)
        EVT_CALL(SetMessageText, LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_PickUpPrompt, 160, 40)
        EVT_CALL(ShowChoice, MSG_Choice_000D)
        EVT_CALL(CloseMessage)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(AddItem, MV_Socket3_ItemID, LVar0)
            EVT_IF_EQ(LVar0, -1)
                EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_Inspect_CantCarryMore, 160, 40)
                EVT_RETURN
            EVT_END_IF
            EVT_CALL(N(GetItemIDFromItemEntity), MV_Socket3_ItemEntityID)
            EVT_CALL(RemoveItemEntity, MV_Socket3_ItemEntityID)
            EVT_SET(MV_Socket3_ItemID, -1)
            EVT_CALL(N(SerializeItemIDs))
            EVT_CALL(ShowGotItem, LVar0, FALSE, ITEM_PICKUP_FLAG_UNIQUE)
            EVT_SET(LVar2, MODEL_m3_kabe)
            EVT_SET(LVar4, COLLIDER_o53)
            EVT_EXEC_WAIT(N(EVS_TakeItemFromSocket))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Interact_ItemSockets) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_LABEL(0)
    EVT_CALL(GetPlayerActionState, LVar0)
    EVT_WAIT(1)
    EVT_IF_NE(LVar0, ACTION_STATE_IDLE)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
    EVT_IF_LT(LVar1, -150)
        EVT_EXEC_WAIT(N(EVS_UseSocket1))
    EVT_ELSE
        EVT_IF_LT(LVar1, 100)
            EVT_EXEC_WAIT(N(EVS_UseSocket2))
        EVT_ELSE
            EVT_EXEC_WAIT(N(EVS_UseSocket3))
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupSockets) = {
    EVT_CALL(ParentColliderToModel, COLLIDER_o55, MODEL_m1_kabe)
    EVT_CALL(ParentColliderToModel, COLLIDER_o54, MODEL_m2_kabe)
    EVT_CALL(ParentColliderToModel, COLLIDER_o53, MODEL_m3_kabe)
    EVT_IF_EQ(GF_SAM09_Visited, FALSE)
        EVT_SET(GF_SAM09_Visited, TRUE)
        EVT_SET(MV_Socket1_ItemID, ITEM_SHOOTING_STAR)
        EVT_SET(MV_Socket2_ItemID, ITEM_SNOWMAN_DOLL)
        EVT_SET(MV_Socket3_ItemID, ITEM_THUNDER_RAGE)
        EVT_CALL(N(SerializeItemIDs))
    EVT_END_IF
    EVT_CALL(N(DeserializeItemIDs))
    EVT_IF_NE(MV_Socket1_ItemID, -1)
        EVT_CALL(TranslateModel, MODEL_m1_kabe, 0, 130, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o55)
        EVT_CALL(MakeItemEntity, MV_Socket1_ItemID, -385, 30, -50, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(MV_Socket1_ItemEntityID, LVar0)
    EVT_END_IF
    EVT_IF_NE(MV_Socket2_ItemID, -1)
        EVT_CALL(TranslateModel, MODEL_m2_kabe, 0, 130, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o54)
        EVT_CALL(MakeItemEntity, MV_Socket2_ItemID, -35, 30, -50, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(MV_Socket2_ItemEntityID, LVar0)
    EVT_END_IF
    EVT_IF_NE(MV_Socket3_ItemID, -1)
        EVT_CALL(TranslateModel, MODEL_m3_kabe, 0, 130, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o53)
        EVT_CALL(MakeItemEntity, MV_Socket3_ItemID, 265, 30, -50, ITEM_SPAWN_MODE_DECORATION, 0)
        EVT_SET(MV_Socket3_ItemEntityID, LVar0)
    EVT_END_IF
    EVT_CALL(N(CreateConsumableItemList))
    EVT_BIND_PADLOCK(EVT_PTR(N(EVS_Interact_ItemSockets)), TRIGGER_WALL_PRESS_A, COLLIDER_hako, LVar0, 0, 1)
    EVT_RETURN
    EVT_END
};
