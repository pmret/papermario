#include "kzn_19.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_YellowBlock), -170, 310, -340, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KZN19_ItemBlock_SuperShroom)
    Call(MakeEntity, Ref(Entity_YellowBlock), -70, 310, -340, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_KZN19_ItemBlock_MapleSyrup)
    Return
    End
};
