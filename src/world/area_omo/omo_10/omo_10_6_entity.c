#include "omo_10.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), -350, 60, 60, 0, ITEM_SUPER_SHROOM, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO10_HiddenItem_SuperShroom)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), 250, 60, 55, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), 150, 60, 55, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 0, 0, 200, 0, MODEL_soto, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_OMO10_HiddenPanel)
    EVT_RETURN
    EVT_END
};
