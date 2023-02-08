#include "dgb_18.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_MysticalKey) = {
    EVT_SET(GF_DGB18_Chest_MysticalKey, TRUE)
    EVT_CALL(AddKeyItem, ITEM_MYSTICAL_KEY)
    EVT_CALL(SetNpcVar, NPC_Yakkey, 0, 1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_Chest), 845, 0, 145, -35, 0, MAKE_ENTITY_END)
    EVT_CALL(AssignChestFlag, GF_DGB18_Chest_MysticalKey)
    EVT_CALL(AssignScript, EVT_PTR(N(EVS_OpenChest_MysticalKey)))
    EVT_RETURN
    EVT_END
};
