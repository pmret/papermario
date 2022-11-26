#include "flo_03.h"
#include "entity.h"

EvtScript N(EVS_EmptyEntityHandler) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), -175, 0, 150, 0, MODEL_o56, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_FLO03_HiddenPanel)
    EVT_RETURN
    EVT_END
};
