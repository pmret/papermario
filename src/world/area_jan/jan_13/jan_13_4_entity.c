#include "jan_13.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_PinkFlower), -169, 0, -115, 10, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), -185, 85, -35, 0, ITEM_VOLT_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_JAN13_HiddenItem_VoltShroom)
    EVT_CALL(UseDynamicShadow, TRUE)
    EVT_RETURN
    EVT_END
};
