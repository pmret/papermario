#include "hos_06.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), -50, 0, 350, -90, MODEL_o4, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_HOS06_HiddenPanel)
    EVT_RETURN
    EVT_END
};
