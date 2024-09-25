#include "flo_25.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HiddenPanel), -390, 0, 0, 0, MODEL_o3, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_FLO25_HiddenPanel)
    Return
    End
};
