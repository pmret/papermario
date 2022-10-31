#include "flo_25.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), -390, 0, 0, 0, MODEL_o3, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_FLO25_HiddenPanel)
    EVT_RETURN
    EVT_END
};
