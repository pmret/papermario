#include "kzn_18.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 250, 250, -225, 0, MODEL_o380, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_KZN18_HiddenPanel)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_SavePoint), -420, 85, -80, 0, MAKE_ENTITY_END)
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HeartBlock), 350, 310, -250, 0, MAKE_ENTITY_END)
    EVT_RETURN
    EVT_END
};
