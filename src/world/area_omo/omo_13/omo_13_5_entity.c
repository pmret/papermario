#include "omo_13.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_PowerPlus) = EVT_OPEN_CHEST_BADGE(ITEM_POWER_PLUS_B, GF_OMO13_Chest_PowerPlusB);

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), 110, 0, -60, 0, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_OMO13_Chest_PowerPlusB)
    Call(AssignScript, Ref(N(EVS_OpenChest_PowerPlus)))
    Call(MakeEntity, Ref(Entity_YellowBlock), -375, 60, -95, 0, ITEM_COIN, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO13_ItemBlock_Coin)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 470, 60, -60, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_OMO13_HiddenItem_MapleSyrup)
    Return
    End
};
