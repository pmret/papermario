#include "obk_01.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    EVT_CALL(MakeEntity, EVT_PTR(Entity_HiddenPanel), 675, -420, 415, 180, MODEL_o317, MAKE_ENTITY_END)
    EVT_CALL(AssignPanelFlag, GF_OBK01_HiddenPanel)
    EVT_RETURN
    EVT_END
};
