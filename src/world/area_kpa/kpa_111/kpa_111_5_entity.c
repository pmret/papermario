#include "kpa_111.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_YellowBlock), 205, 60, 110, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KPA111_ItemBlock_SuperShroom)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 5, 60, 110, 0, ITEM_MAPLE_SYRUP, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_KPA111_HiddenItem_MapleSyrup)
    EVT_RETURN
    EVT_END
};
