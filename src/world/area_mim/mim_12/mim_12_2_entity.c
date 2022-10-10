#include "mim_12.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 100, 0, -40, 0, MODEL_o8, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_MIM12_HiddenPanel)
    EVT_RETURN
    EVT_END
};
