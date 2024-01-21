#include "kpa_111.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), 205, 60, 110, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KPA111_ItemBlock_SuperShroom)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), 5, 60, 110, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KPA111_HiddenItem_MapleSyrup)
    Return
    End
};
