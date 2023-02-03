#include "jan_02.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 25, 15, -60, 0, MODEL_o222, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_JAN02_HiddenPanel)
    EVT_RETURN
    EVT_END
};
