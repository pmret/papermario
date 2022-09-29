#include "kzn_19.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -170, 310, -340, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KZN19_ItemBlock_SuperShroom)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), -70, 310, -340, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KZN19_ItemBlock_MapleSyrup)
    EVT_RETURN
    EVT_END
};
