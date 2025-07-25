#include "dgb_18.h"
#include "entity.h"

#include "world/common/entity/Chest.inc.c"

EvtScript N(EVS_OpenChest_MysticalKey) = {
    Set(GF_DGB18_Chest_MysticalKey, true)
    Call(AddKeyItem, ITEM_MYSTICAL_KEY)
    Call(SetNpcVar, NPC_Yakkey, 0, 1)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_Chest), 845, 0, 145, -35, 0, MAKE_ENTITY_END)
    Call(AssignChestFlag, GF_DGB18_Chest_MysticalKey)
    Call(AssignScript, Ref(N(EVS_OpenChest_MysticalKey)))
    Return
    End
};
