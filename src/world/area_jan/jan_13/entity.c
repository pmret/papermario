#include "jan_13.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_PinkFlower), -169, 0, -115, 10, MAKE_ENTITY_END)
    Call(MakeEntity, Ref(Entity_HiddenYellowBlock), -185, 85, -35, 0, ITEM_VOLT_SHROOM, MAKE_ENTITY_END)
    Call(AssignBlockFlag, GF_JAN13_HiddenItem_VoltShroom)
    Call(UseDynamicShadow, true)
    Return
    End
};
