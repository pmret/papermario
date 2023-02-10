#include "jan_15.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_PinkFlower), 385, 0, -75, 10, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 0, 0, 0, 0, MODEL_o87, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_JAN15_HiddenPanel)
    EVT_RETURN
    EVT_END
};
