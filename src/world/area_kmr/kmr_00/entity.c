#include "kmr_00.h"
#include "entity.h"

EvtScript N(EVS_MakeEntities) = {
    Call(MakeEntity, Ref(Entity_HiddenPanel), 0, 0, 0, 0, MODEL_ji_3, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_KMR00_HiddenPanel)
    Return
    End
};
