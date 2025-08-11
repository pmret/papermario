#include "obk_04.h"
#include "entity.h"

API_CALLABLE(N(SetItemAlpha)) {
    ItemEntity* item = get_item_entity(script->varTable[0]);

    set_item_entity_flags(script->varTable[0], ITEM_ENTITY_FLAG_TRANSPARENT);
    item->alpha = 255;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_OnSmash_Floor) = {
    Set(GF_OBK04_BoardedFloor, true)
    Return
    End
};

EvtScript N(EVS_OnSmash_Unused) = {
    Set(GF_OBK04_UnusedBoardedFloor, true)
    Return
    End
};

EvtScript N(EVS_OpenGiantChest) = {
    Call(DisablePlayerInput, true)
    Set(GF_OBK04_GiantChest, true)
    Exec(N(EVS_Scene_BoosUnleashed))
    Call(DisablePlayerInput, false)
EndIf
Return
End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_GiantChest), 180, 0, -175, -10, ITEM_NONE, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_OBK04_GiantChest)
    Call(AssignScript, Ref(N(EVS_OpenGiantChest)))
    Call(MakeItemEntity, ITEM_MENU_BOOTS2, NPC_DISPOSE_LOCATION, ITEM_SPAWN_MODE_DECORATION, 0)
    Call(N(SetItemAlpha))
    Set(MV_KeepAwayItem, LVar0)
    IfEq(GF_OBK04_BoardedFloor, false)
        Call(MakeEntity, Ref(Entity_BoardedFloor), 0, 0, 0, 0, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_OnSmash_Floor)))
    EndIf
    Call(MakeEntity, Ref(Entity_WoodenCrate), -60, 0, -190, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    Call(AssignCrateFlag, GF_OBK04_Crate_MapleSyrup)
    Call(MakeEntity, Ref(Entity_WoodenCrate), -60, 30, -190, 0, -1, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_WoodenCrate), -20, 0, -190, 0, -1, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenPanel), -175, 0, -75, 0, MODEL_o318, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_OBK04_HiddenPanel)
    Return
    End
};
