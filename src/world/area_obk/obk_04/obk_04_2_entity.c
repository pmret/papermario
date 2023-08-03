#include "obk_04.h"
#include "entity.h"

API_CALLABLE(N(SetItemAlpha)) {
    ItemEntity* item = get_item_entity(script->varTable[0]);

    set_item_entity_flags(script->varTable[0], ITEM_ENTITY_FLAG_TRANSPARENT);
    item->alpha = 255;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_OnSmash_Floor) = {
    EVT_SET(GF_OBK04_BoardedFloor, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnSmash_Unused) = {
    EVT_SET(GF_OBK04_UnusedBoardedFloor, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenGiantChest) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_SET(GF_OBK04_GiantChest, TRUE)
    EVT_EXEC(N(EVS_Scene_BoosUnleashed))
    EVT_CALL(DisablePlayerInput, FALSE)
EVT_END_IF
EVT_RETURN
EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_GiantChest), 180, 0, -175, -10, ITEM_NONE, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_OBK04_GiantChest)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenGiantChest)))
    EVT_CALL(MakeItemEntity, ITEM_MENU_BOOTS2, NPC_DISPOSE_LOCATION, ITEM_SPAWN_MODE_DECORATION, 0)
    EVT_CALL(N(SetItemAlpha))
    EVT_SET(MV_KeepAwayItem, LVar0)
    EVT_IF_EQ(GF_OBK04_BoardedFloor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_BoardedFloor), 0, 0, 0, 0, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_OnSmash_Floor)))
    EVT_END_IF
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), -60, 0, -190, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    EVT_CALL(AssignCrateFlag, GF_OBK04_Crate_MapleSyrup)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), -60, 30, -190, 0, -1, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_WoodenCrate), -20, 0, -190, 0, -1, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), -175, 0, -75, 0, MODEL_o318, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_OBK04_HiddenPanel)
    EVT_RETURN
    EVT_END
};
