#include "omo_13.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_PowerPlus) = EVT_OPEN_CHEST_BADGE(ITEM_POWER_PLUS_B, GF_OMO13_Chest_PowerPlusB);

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 110, 0, -60, 0, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_OMO13_Chest_PowerPlusB)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_PowerPlus)))
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -375, 60, -95, 0, ITEM_COIN, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO13_ItemBlock_Coin)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 470, 60, -60, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO13_HiddenItem_MapleSyrup)
    EVT_RETURN
    EVT_END
};
