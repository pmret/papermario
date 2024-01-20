#include "kpa_61.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), -225, -100, 175, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KPA61_ItemBlock_SuperShroomA)
    Call(MakeEntity, Ref(Entity_YellowBlock), 60, -100, 60, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KPA61_ItemBlock_MapleSyrup)
    Call(MakeEntity, Ref(Entity_YellowBlock), 575, -100, 60, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KPA61_ItemBlock_SuperShroomB)
    Call(MakeItemEntity, ITEM_JAMMIN_JELLY, 1070, -40, 320, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_KPA61_Item_JamminJelly)
    Return
    End
};
