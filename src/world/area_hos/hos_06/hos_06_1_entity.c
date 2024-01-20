#include "hos_06.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HiddenPanel), -50, 0, 350, -90, MODEL_o4, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_HOS06_HiddenPanel)
    Return
    End
};
