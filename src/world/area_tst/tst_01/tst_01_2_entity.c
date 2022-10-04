#include "tst_01.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 136, 80, 63, 0, ITEM_FLOWER_POINT, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 190, 0, 63, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 201, 60, -20, 0, ITEM_HEART, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 230, 60, -20, 0, ITEM_HEART, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenRedBlock), 258, 60, -20, 0, ITEM_FLOWER_POINT, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_RedBlock), 315, 60, 63, 0, ITEM_FLOWER_POINT, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
