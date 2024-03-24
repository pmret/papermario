#include "flo_03.h"
#include "entity.h"

EvtScript N(EVS_EmptyEntityHandler) = {
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HiddenPanel), -175, 0, 150, 0, MODEL_o56, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_FLO03_HiddenPanel)
    Return
    End
};
