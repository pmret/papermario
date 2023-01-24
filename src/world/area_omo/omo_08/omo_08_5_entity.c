#include "omo_08.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -350, 60, 50, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenYellowBlock), 350, 60, 60, 0, ITEM_FIRE_FLOWER, MAKE_ENTITY_END)
    EVT_CALL(AssignBlockFlag, GF_OMO08_HiddenItem_FireFlower)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), -200, 0, 200, 0, MODEL_soto, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_OMO08_HiddenPanel)
    EVT_RETURN
    EVT_END
};
