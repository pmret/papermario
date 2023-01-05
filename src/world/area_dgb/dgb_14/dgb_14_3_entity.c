#include "dgb_14.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 500, 60, 75, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_DGB14_ItemBlock_MapleSyrup)
    EVT_RETURN
    EVT_END
};
