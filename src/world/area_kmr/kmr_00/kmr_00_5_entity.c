#include "kmr_00.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 0, 0, 0, 0, MODEL_ji_3, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_KMR00_HiddenPanel)
    EVT_RETURN
    EVT_END
};
